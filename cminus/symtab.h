#ifndef SYMTAB_H
#define SYMTAB_H

#define MAX_NAME_LENGTH 20		 // 标识符名称长度最大值
#define MAX_SYMBOLS_PER_TABLE 10 // 每一个符号表包含符号的最大值

/*
 * 符号的各种属性
 */
struct symbolAttributes
{
	int type;		 // 符号种类
	int initialized; // 是否被初始化
	int references;  // 是否被引用
	int scope;		 // 符号所属域

	int array;		 // 符号是否为数组
	int arrSize;	 // 数组长度

	int parameters;			 // 参数中的顺序
	int localVarStackOffset; // 局部变量栈偏移
	int regContainingArrIndex;
};
/*
 * 符号
 */
struct symbolEntry
{
	char id[MAX_NAME_LENGTH];	 // 名称
	int type;					  // 种类: 变量or函数
	struct symbolAttributes attr; // 属性
};
/*
 * 符号表(通过链表连接)
 */
struct symbolTable
{
	struct symbolEntry symTab[MAX_SYMBOLS_PER_TABLE]; // 一个符号表包含的符号数组
	struct symbolTable *outerScope;					  // 指向外层符号表的指针
	int symbolNum;									  // 包含符号的个数
	int localVarNum;								  // 局部变量的个数
};

struct symbolAttributes parsedSymbolAttributes; // 已经被解析好的符号表(用作临时变量)

struct symbolTable globalSymTab;  // 全局符号表
struct symbolTable *CurrentScope; // 指向当前符号表(scope)的指针

/*
 * 在符号表中查找符号
 */
struct symbolEntry *lookup(char *id);
/*
 * 插入(局部)符号
 */
void insertSymbol(char *id, struct symbolAttributes attr, int type);
/*
 * 插入全局符号
 */
void insertGlobalSymbol(char *id, struct symbolAttributes attr, int type);

/*
 * 初始化一个域(scope)
 */
void initScope();
/*
 * 定案一个域(scope)
 */
void finalizeScope();

/*
 * 打印符号
 */
void printSymbol(struct symbolEntry sym);

/*
 * 置(临时)符号表于初始状态
 */
void resetparsedSymbolAttributes();

/*
 * 是否在函数体中
 */
int inFunctionBody();

#endif
