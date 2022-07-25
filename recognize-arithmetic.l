%{
    #include<stdio.h>
    int opcount=0;
    int idcount=0;
    int brac=0;
%}
%%
[0-9]+ {idcount++;printf("\nidentifier ");ECHO;}
[\+\*] {opcount++;printf("\noperator ");ECHO;}
"(" {brac++;}
")" {brac--;}
\n {return 0;}
%%
int main(){
    printf("\nenter the expression: ");
    yylex();
    if(opcount=idcount-1 && brac==0){
        printf("\nvalid expression\noperators: %d\nidentifiers: %d",opcount,idcount);
    }
    else{
        printf("\ninvalid expression");
    }
}
int yywrap(){
    return 1;
}
