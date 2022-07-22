%{
    #include<stdio.h>
    int sl=0,ml=0;
%}
%%
"/*"[a-zA-Z0-9' '\t\n]+"*/" ml++;
"//".* sl++;
%%

main()
{
    yyin=fopen("f1.c","r");
    yyout=fopen("f2.c","w");
    yylex();
    fclose(yyin);
    fclose(yyout);
    printf("\nnumber of single line comments are: %d\n",sl);
    printf("number of multiline comments sre: %d\n",ml);
}