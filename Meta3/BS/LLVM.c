#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "semantics.h"
#include "math.h"
#include "symbol_table.h"





void imprime_inicio(no node){
    printf("@.strlit = private unnamed_addr constant [4 xi8] c\"%%s\\0A\\00\",align 1\n");
    printf("@.newline = private unnamed_addr constant [2 xi8] c\"\\0A\\00\",align 1\n");
    printf("@.intlit = private unnamed_addr constant [4 xi8] c\"%%d\\0A\\00\",align 1\n");
    printf("@.reallit = private unnamed_addr constant [7 xi8] c\"%%.08f\\0A\\00\",align 1\n");
    printf("@.boollit = private unnamed_addr constant [4 xi8] c\"%%d\\0A\\00\",align 1\n");          
 
    printf("declare i32 @atoi(...)\n");
    printf("declare i32 @printf(i8*,...)\n\n");

    printf("@.strture = private unnamed_addr constant [6 xi8] c\"true\\0A\\00\",align 1\n");          
    printf("@.strfalse = private unnamed_addr constant [7 xi8] c\"false\\0A\\00\",align 1\n");


    printf("define dso_local void @print_bool(i1) #0 {\n");
    printf("\t%%2 = alloca i1\n");

    printf("\tstore i1 %%0, i1* %%2\n");
    printf("\t%%3 = load i1, i1* %%2\n");
    printf("\t%%4 = icmp ne i1 %%3, 0\n");
    printf("\tbr i1 %%4, label %%true, label %%false\n");
    printf("true:\n");
    printf("\t%%5 = call i32( i8*,...) @printf(i8* getelementptr inbounds ([6 x i8],[6 x i8]* @.strtrue, i32 0, i32 0))\n");
    printf("\tbr label %%end\n\n");
    printf("false:\n");
    printf("\t%%6 = call i32( i8*,...) @printf(i8* getelementptr inbounds ([7 x i8],[7 x i8]* @.strfalse, i32 0, i32 0))\n");
    printf("\tbr label %%end\n\n");
    printf("end:\n");
    printf("\tret void\n");
    printf("}\n");


}

char *tipoVarLLVM(no node){
    char * returnT;
    if(node == NULL){
        returnT = strdup("void");
    }else if(strcmp(node->s_type,"Int")==0){
        returnT = strdup("i32");
    }else if(strcmp(node->s_type,"Double")==0){
        returnT = strdup("i64");
    }
    return returnT;
}


void imprime_func(no node){

    if(strcmp(node->filho->filho->irmao->valor, "main")==0){
        printf("define i32 @main(i32 %%argc, i8** argv) {}");
        return;
    }else{
        char *type = tipoVarLLVM(node->filho->filho);
        printf("define %s @%s(",type,node->filho->filho->irmao->valor);
    
    no nodeaux = node->filho->filho->irmao->irmao;
    no aux = NULL;
    
    for(aux = nodeaux->filho; aux!=NULL; aux = aux->irmao){
        char *type =  tipoVarLLVM(aux->filho);
        printf("%s %%%s",type,aux->filho->irmao->valor);
        if(aux->irmao!=NULL){
            printf(", ");
        }
      

    }
    }
    printf(") {}\n");


    
}
char * if_Ope(char * c){
    if(strcmp(c,"Eq")==0){
        return "eq";
    }
}


void imprime_if(no node){
    char *t = if_Ope(node->filho->s_type);
    char * type = tipoVarLLVM(node);
    char *k = "comp";
    printf("\t%%comp= icmp %s %s %%%s, 0 \n",t,type,node->filho->filho->valor);
    printf("\tbr i1 %%comp, label %%b2, label %%b3");
    printf("b2:\n");

}



void CodeF(no node){
    if(node){
       
    if(strcmp(node->s_type,"Program")==0){
        imprime_inicio(node);
    }
     if(strcmp(node->s_type,"MethodDecl")==0){
        imprime_func(node);
    }
    /* if(strcmp(node->s_type,"If")==0){
        imprime_if(node);
     }*/
    
    }
}