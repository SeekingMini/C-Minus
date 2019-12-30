#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/*
 * 初始化全局符号表
 */
struct symbolTable globalSymTab = {
    .outerScope = NULL, // 全局符号表没有外层scope指针
    .symbolNum = 0,
    .localVarNum = 0};
struct symbolTable *CurrentScope = &globalSymTab;

int ScopeLevel = 0; // 符号表层级

/*
 * 初始化属性
 */
struct symbolAttributes parsedSymbolAttributes = {
    .type = 0,
    .initialized = 0,
    .references = 0,
    .scope = 0,
    .array = 0,
    .arrSize = 0,
    .parameters = 0,
    .localVarStackOffset = 0};

struct symbolEntry *lookup(char *id)
{
  struct symbolTable *iter = CurrentScope;
  while (iter)
  {
    for (int i = 0; i < iter->symbolNum; i++)
    {
      if (!strcmp(iter->symTab[i].id, id))
      {
        return &iter->symTab[i]; // 如果找到则返回这个符号的指针
      }
    }
    iter = iter->outerScope; // 如果在当前符号表中没有找到则跳到外层符号表继续寻找
  }

  printf("[Error] id: %s is never declared!\n", id);
  exit(0); // 该符号在所有符号表中都没有找到则发生错误并退出
}

void insertSymbol(char *id, struct symbolAttributes attr, int type)
{
  // 生成一个新符号
  struct symbolEntry symbol = {.type = type,
                               .attr = attr};
  strcpy(symbol.id, id);

  // 如果是主函数main
  if (!strcmp(id, "main"))
  {
    symbol.attr.references = 1; // 表示被引用
  }

  // 检查符号是否已经声明过
  struct symbolTable *iter = CurrentScope;
  while (iter)
  {
    for (int i = 0; i < iter->symbolNum; i++)
    {
      if (strcmp(iter->symTab[i].id, id) == 0)
      {
        printf("[Error] id: %s was previously declared!\n", id);
        exit(0); // 发生重复声明错误并退出
      }
    }
    iter = iter->outerScope;
  }
  CurrentScope->symTab[CurrentScope->symbolNum] = symbol;
  CurrentScope->symbolNum++;

  // 打印符号
  printf("【Adding a symbol to table】\n");
  printSymbol(symbol);
  printf("\n\n");
}

void insertGlobalSymbol(char *id, struct symbolAttributes attr, int type)
{
  struct symbolEntry symbol = {.type = type,
                               .attr = attr};
  strcpy(symbol.id, id);
  if (!strcmp(id, "main"))
  {
    symbol.attr.references = 1;
  }

  struct symbolTable *iter = &globalSymTab;
  for (int i = 0; i < iter->symbolNum; i++)
  {
    if (strcmp(iter->symTab[i].id, id) == 0)
    {
      printf("[Error] id: %s was previously declared!\n", id);
      exit(0);
    }
  }
  iter->symTab[iter->symbolNum] = symbol;
  iter->symbolNum++;

  // 打印符号
  printf("【Adding a symbol to table】\n");
  printSymbol(symbol);
  printf("\n\n");
}

void initScope()
{
  ScopeLevel++;
  printf("【Initializing new scope. Scope depth: %i】\n", ScopeLevel);

  struct symbolTable *tab = (struct symbolTable *)malloc(sizeof(struct symbolTable));
  tab->outerScope = CurrentScope;
  tab->symbolNum = 0;
  CurrentScope = tab;
}

void finalizeScope()
{
  printf("【Exiting scope level: %i】\n【Printing Table】\n", ScopeLevel);
  printf("Name\t\tType\t\tAttributes\n");

  for (int i = 0; i < CurrentScope->symbolNum; i++)
  {
    printSymbol(CurrentScope->symTab[i]);
    printf("\n");

    if (!CurrentScope->symTab[i].attr.references) // 符号未被引用会引起警告
    {
      printf("[Warning] id \"%s\" was not referenced!\n\n",
             CurrentScope->symTab[i].id);
    }
  }
  printf("\n");

  if (ScopeLevel)
  {
    struct symbolTable *temp = CurrentScope;
    CurrentScope = CurrentScope->outerScope;
    free(temp);
    temp = NULL;
    ScopeLevel--;
  }
}

enum
{
  VAR = 0,
  FUNC = 1
};
void printSymbol(struct symbolEntry sym)
{
  printf("%s\t", sym.id);
  if (strlen(sym.id) < 9)
  {
    printf("\t");
  }
  if (sym.type == VAR)
  {
    printf("VAR\t");
  }
  else
  {
    printf("FUNC\tParameters:%i\t", sym.attr.parameters);
  }

  if (sym.attr.type == 0)
  {
    printf("INT\t");
  }
  else
  {
    printf("VOID\t");
  }

  if (sym.attr.array == 1)
  {
    printf("ARRAY, size:%i", sym.attr.arrSize);
  }
}
void resetparsedSymbolAttributes()
{
  parsedSymbolAttributes.type = 0;
  parsedSymbolAttributes.initialized = 0;
  parsedSymbolAttributes.references = 0;
  parsedSymbolAttributes.scope = 0;
  parsedSymbolAttributes.array = 0;
  parsedSymbolAttributes.arrSize = 0;
  parsedSymbolAttributes.parameters = 0;
  parsedSymbolAttributes.localVarStackOffset = 0;
}

int inFunctionBody()
{
  if (ScopeLevel == 1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}