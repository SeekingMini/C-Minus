%{ 
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "emitcode.h"
  #include "symtab.h"

  extern int yylineno;
  int yylex();
  void yyerror(const char *s);

  extern struct symbolAttributes parsedSymbolAttributes;

  extern struct symbolTable globalSymTab;
  extern struct symbolTable *CurrentScope;

  extern int LabelSeed;  // 标签计数器
  extern int NumOfParams;  // (函数)参数的个数
  extern int ArgList[3];  // 参数列表
  extern int ArgNum;  // 

  extern FILE *fp;
  int TextSection = 0; 
%}

%union {
   	int n;
  	char s[15];
}
/* 保留字 */
%token ELSE
%token IF
%token INT
%token RETURN
%token VOID
%token WHILE
/* 标识符与数字 */
%token ID
%token NUM
/* 关系运算符 */
%token LTE
%token GTE
%token EQUAL
%token NOTEQUAL
/* */
%type<n>    NUM call factor term expression type_specifier simple_expression additive_expression addop mulop relop iteration_stmt selection_stmt ifsubroutine whilesubroutine
%type<s>    ID var var_declaration
%nonassoc   IFX
%nonassoc   ELSE
%%

program : InitDataSection declaration_list {finalizeScope();};
                                                                  
InitDataSection : /*empty*/   {fprintf(fp, "SECTION .data\n                                                \n");
						                   fprintf(fp, "ReturnMsg: db \"Return Value:%%i\", 10, 0\n");
                              }  // 初始化数据部分

declaration_list : declaration_list declaration  // 声明一个或多个变量或函数 
                 | declaration;

declaration  : var_declaration   // 变量声明
	           | fun_declaration;  // 函数声明

// 变量声明
var_declaration : type_specifier ID ';'	{insertSymbol($2, parsedSymbolAttributes, VAR);  // 将符号插入符号表
                                         strcpy($$, $2);  // 复制名称
                                         resetparsedSymbolAttributes();  // 重置符号属性
                                        }
                | type_specifier ID '[' NUM ']' ';' {parsedSymbolAttributes.array = 1;  // 类型为数组
                                                     parsedSymbolAttributes.arrSize = $4;  // 数组元素个数
                                                     insertSymbol($2, parsedSymbolAttributes, VAR);  // 将符号插入符号表
                                                     strcpy($$, $2);  // 复制名称
                                                     resetparsedSymbolAttributes();  // 重置符号属性
                                                    }
                ;

type_specifier : INT	  {$$ = 0; parsedSymbolAttributes.type = 0;}
               | VOID   {$$ = 1; parsedSymbolAttributes.type = 1;}
	             ;

fun_declaration : type_specifier ID '('     {if(!TextSection++) fprintf(fp, "\nSECTION .text\nextern printf\n");  // 代码块
                                             emitDeclaration(FUNC, $2);  // 函数声明
                                             initScope();  // 初始化一个域
                                            }
                  params ')'                {parsedSymbolAttributes.type = $1;  // 函数类型赋值到符号属性
                                             parsedSymbolAttributes.parameters = NumOfParams;  // 函数形参个数
                                             insertGlobalSymbol($2, parsedSymbolAttributes, FUNC);  // 插入全局符号

											                       resetparsedSymbolAttributes();  // 重置符号属性
                                             NumOfParams=0;  // 形参个数重置为0
											                      }
				  compound_stmt  			              {finalizeScope();  // 函数体解析结束打印符号表
                                             if($1 == 1)  // 函数类型为VOID                                       
                                                emitEpilogue();  // 弹栈                                  	     
                                             releaseAllRegister();  // 释放所有寄存器
                                            }
                ;

params : param_list | VOID ;  // 有形参或者没有形参

param_list : param_list ',' param {NumOfParams++; }  // 形参表定义：一个或多个形参
           | param 		            {NumOfParams++; }
	         ;

param : type_specifier ID           {parsedSymbolAttributes.parameters = NumOfParams + 1;  // 形参的顺序
                                     parsedSymbolAttributes.initialized = 1;  // 表示已被初始化
                                     insertSymbol($2, parsedSymbolAttributes, VAR);  // 插入变量符号到符号表
                                     resetparsedSymbolAttributes();  // 重置符号属性
                                    }
      | type_specifier ID '[' ']'   {parsedSymbolAttributes.parameters = NumOfParams + 1;
                                     parsedSymbolAttributes.array = 1;
                                     parsedSymbolAttributes.initialized = 1;
                                     insertSymbol($2, parsedSymbolAttributes, VAR);
                                     resetparsedSymbolAttributes();
                                    }
      ;

compound_stmt : '{'                                     {if(!inFunctionBody())  // 如果不在函数体中，重新生成一个域
                                                            initScope();
                                                        }
                 local_declarations statement_list 
                 '}'  {if(!inFunctionBody())
                          finalizeScope();}
              ;

local_declarations : local_declarations var_declaration {emitDeclaration(VAR, $2);}  // 声明局部变量
                   | /* empty */ ;

statement_list : statement_list statement  // 声明语句列表
               | /* empty */ ;

statement : expression_stmt  // 表达式语句
          | compound_stmt  // 代码块语句
          | selection_stmt  // 选择语句
          | iteration_stmt  // 循环语句
          | return_stmt ;  // 返回语句

expression_stmt : expression ';'
                | ';' 
				;

selection_stmt : ifsubroutine  statement        {fprintf(fp, "EndIf%i:\n", $1);}
               | ifsubroutine  statement ELSE	  {fprintf(fp, "jmp EndIfElse%i\n", $1);
                              					         fprintf(fp, "EndIf%i:\n", $1);
                      							            }
				         statement					 	          {fprintf(fp, "EndIfElse%i:\n", $1);}
               ;

ifsubroutine : IF  '(' expression ')'  {$$ = LabelSeed; LabelSeed++;  // 语句标号
                     					          fprintf(fp, "cmp %s, 1\n", regToString($3));
                                        fprintf(fp, "jne EndIf%i\n", $$);
                                        releaseOneRegister();  // 释放一个寄存器
                                       }
		   ;

iteration_stmt : whilesubroutine

                '(' expression ')' {fprintf(fp, "cmp %s, 1\n", regToString($<n>3));
                                     fprintf(fp, "jne EndWhile%i\n", $1);
                                     releaseOneRegister();
                                    }
                 statement          {fprintf(fp, "jmp While%i\n", $1);
                                     fprintf(fp, "EndWhile%i:\n", $1);
                                    }
                ;
whilesubroutine : WHILE    {$$ = LabelSeed; LabelSeed++; 
                            fprintf(fp, "While%i:\n", $$);
                           }

return_stmt : RETURN ';'              {emitEpilogue();}  // 弹栈

            | RETURN expression ';'   {if($2 == EAX){
										                    emitPrintReturn();
                                        emitEpilogue();
									                     }
                                       else{
                                        fprintf(fp, "mov eax, %s\n", regToString($2));
										                    emitPrintReturn();
                                        emitEpilogue();
                                       }
                                       releaseOneRegister();
                                      }

            ;

expression : var '=' expression     {$$=9;
                                     emitMemOp(STORE,$1,$3);  // 表达式的值赋给变量
                                     releaseOneRegister();  // 释放一个寄存器
                                    }
           | simple_expression      {$$ = $1;}
           ;

var : ID                    {lookup($1)->attr.references++;
                             strcpy($$, $1);}

    | ID '[' expression ']' {struct symbolEntry *tmp = lookup($1);
                             if(!tmp->attr.array)  // 判断符号是否为数组
                             printf("[Error]  %s is not an array", tmp->id);
                             tmp->attr.references++;
                             tmp->attr.regContainingArrIndex = $3;
                             strcpy($$, $1);
                            }
    ;

simple_expression : additive_expression relop additive_expression  {$$=$1;
                                                                    emitRelOp($2,$1,$3);  // 算数表达式
                                                                    releaseOneRegister();
                                                                   }
                  | additive_expression                            {$$ = $1;
                                                                   }
                  ;

relop : LTE {$$=LTEQU;}| '<'{$$=LESS;} | '>' {$$=GTR;}| GTE{$$=GTEQU;} | EQUAL{$$=EQU;} | NOTEQUAL {$$=NEQU;};

additive_expression : additive_expression addop term    {$$ = $1;
                                                         emitAluOp($2,$1,$3);
                                                         releaseOneRegister();
                                                        }
                    | term                              {$$ = $1;}
                    ;

addop : '+' {$$ = ADD;}
      | '-' {$$ = SUB;}
      ;

term : term mulop factor    {$$ = $1;
                             emitAluOp($2,$1,$3);
                             releaseOneRegister();
                            }
     | factor               {$$ = $1;}
     ;

mulop : '*' {$$ = MULT;}
      | '/' {$$ = DIV;}
      ;

factor : '(' expression ')' {$$ = $2;}
       | var                {
                             $$ = nextFreeRegister();
                             emitMemOp(LOAD,$1,$$);
                            }

       | call               {$$ = $1;}
       | NUM                {$$=nextFreeRegister();
                             emitLoadConst($$, $1);
                            }
       ;

call : ID '(' args ')'  {
                         emitCall($1, ArgList);  // 使用函数过程
                         $$=nextFreeRegister();
                         NumOfParams=0;  // 形参重新置为0
                        }
     ;

args : arg_list | /* empty */ ;

arg_list : arg_list ',' expression {ArgList[NumOfParams++] = $3;}
         | expression              {ArgList[NumOfParams++] = $1;}
         ;

%%

int main() 
{	
	fp = fopen ("out/output.asm", "w");

	if(!yyparse())
  {
    printf("\nParsing complete!\n");
  }	
	else
  {
    printf("\nParsing failed!\n");
  }
	fclose(fp);

  return 0;
}

void yyerror (char const *s)
{
  fprintf(stderr, "%s, line: %i\n", s, yylineno);
}


