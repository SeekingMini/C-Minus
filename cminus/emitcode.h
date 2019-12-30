#ifndef EMITCODE_H
#define EMITCODE_H

int ArgList[3];
int ArgNum;
int NumOfParams;
int LabelSeed;  // 标号计数器
FILE *fp;

/*
 * 算数表达式运算
 */
enum
{
    ADD,
    SUB,
    MULT,
    DIV
} ALU_OPS;
void emitAluOp(int op, int reg1, int reg2);

/*
 * 关系表达式运算
 */
enum
{
    EQU,
    NEQU,
    LESS,
    GTR,
    LTEQU,
    GTEQU
} RELATION_OPS;
void emitRelOp(int op, int reg1, int reg2);

/* 
 * 数组运算
 */
enum
{
    LOAD,
    STORE
} MEMORY_OPS;
void emitMemOp(int op, char *id, int reg);

/*
 * 变量赋值运算
 */
void emitLoadConst(int reg, int value);

/*
 * 函数或(全局)变量声明
 */
enum
{
    VAR,
    FUNC
} DECLARATION_TYPE;
void emitDeclaration(int type, char *id);

/*
 * 过程
 */
void emitCall(char *id, int argList[]);

/*
 * 
 */
void emitEpilogue();

/*
 * 打印返回值
 */
void emitPrintReturn();

/*
 * 返回某个寄存器
 */
enum
{
    EAX,
    EBX,
    ECX,
    EDX,
    ESI,
    EDI
} REGISTER_NAME;
char *regToString(int reg);

/*
 *
 */
int nextFreeRegister();
/*
 * 释放一个寄存器
 */
void releaseOneRegister();
/*
 * 释放所有寄存器
 */
void releaseAllRegister();

#endif