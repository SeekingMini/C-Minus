cd cminus
yacc -d cminus.y
lex cminus.l
cc -o cminus.out lex.yy.c y.tab.c emitcode.c symtab.c
rm y.tab.c 
rm y.tab.h
rm lex.yy.c 
mv cminus.out ../