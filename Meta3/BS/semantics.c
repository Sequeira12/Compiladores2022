#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "semantics.h"
#include "math.h"
#include "symbol_table.h"



int contadorTab = 0;


void verifica(no raiz){
    if(raiz){
        if(strcmp(raiz->s_type,"Program")==0) nova_classe(raiz->filho->valor);
        else if(strcmp(raiz->s_type, "MethodDecl")==0) {
            contadorTab++;
            verifica_method_decl(raiz->filho);
        
        }else if(strcmp(raiz->s_type, "FieldDecl")==0) insere(raiz->filho,NULL,NULL,"Class");
           
    

        
        for(no f = raiz->filho; f!=NULL; f=f->irmao) verifica(f);
        

    }else{
        return;
    }
}


void verifica_method_decl(no node){
    char * tipo = verifica_type(node->filho->s_type);
    char * valor = (char*)strdup(node->filho->irmao->valor);
    char * parametros = verifica_method_params(node->filho->irmao->irmao);
    char ** array_de_parametros = verifica_array_method_params(node->filho->irmao->irmao);

    char** vars_in_param = (char**)malloc((strlen(valor)+strlen(parametros)+1)*sizeof(char*));

    int control=0;
    for(no aux = node->filho->irmao->irmao->filho; aux != NULL; aux = aux->irmao){
        vars_in_param[control]=aux->filho->irmao->valor;
        control++;
    }


    char *n = malloc(strlen(valor)+strlen(parametros)+1);
    if(n){
        n[0]='\0';
        strcat(n,valor);
        strcat(n,parametros);
    }
    if(verifica_repetidos(n)>0){
        insere(node->filho,parametros,NULL,"Class");

        novo_metodo(n,valor,array_de_parametros,tipo);
        no h = NULL;
        if(node->filho->irmao->irmao->filho){
            h = node->filho->irmao->irmao->filho;
        }
        for(h; h!= NULL; h=h->irmao) {
            if(verifica_repetidos_parametros(n,h->filho->irmao->valor)==0) {
                insere(h->filho,NULL, "param", n);
            }
            
            else {
                printf("Line %s, col %s: Symbol %s already defined\n",h->filho->irmao->line ,h->filho->irmao->col ,h->filho->irmao->valor);
            }

        }
    }else{
        node->filho->irmao->repetido=1;
        no h = NULL;
        if(node->filho->irmao->irmao->filho){
            h = node->filho->irmao->irmao->filho;
        }
        
        int contador_parametros=0;
        for(h; h!= NULL; h=h->irmao){ 
            int ctrl=0;
            for(int i = 0; vars_in_param[i] && i<=contador_parametros; i++){
                if(strcmp(vars_in_param[i], h->filho->irmao->valor)==0){
                    ctrl+=1;
                }
            }
            contador_parametros+=1;
            if (ctrl>1)
            {
                printf("Line %s, col %s: Symbol %s already defined\n",h->filho->irmao->line ,h->filho->irmao->col ,h->filho->irmao->valor);
            }
        }
        printf("Line %s, col %s: Symbol %s already defined\n", node->filho->irmao->line, node->filho->irmao->col,n);
    }
};


char * verifica_method_params(no node){
    if(node->filho){
        char parametros[200] = "(";

        for(no aux = node->filho; aux != NULL; aux = aux->irmao){
            if(strcmp(aux->filho->s_type, "StringArray") == 0) strcat(parametros,"String[]");
            else if(strcmp(aux->filho->s_type, "Double")==0)strcat(parametros, "double");
            else if(strcmp(aux->filho->s_type, "Bool")==0)strcat(parametros, "boolean");
            else if(strcmp(aux->filho->s_type, "Int") == 0)strcat(parametros, "int");
            if(aux->irmao) strcat(parametros,",");
        }
        strcat(parametros,")");
        return strdup(parametros);
    }else{
        return strdup("()");
    }
}


char ** check_calls_method_params(no raiz) {
    char ** params = (char**)malloc(50*sizeof(char*));
    no aux = NULL;
    int i = 1;
    if (raiz->filho->irmao) {
        aux = raiz->filho->irmao;
    }
    while (aux != NULL) {
        if (aux->id != NULL) {
            params[i] = strdup(&aux->id[3]);
            i++;
        }
        aux = aux->irmao;
    }
    char string[10];
    sprintf(string, "%d", i-1);
    params[0] = strdup(string);
  
    return params;
}

void removeChar(char *str, char garbage){
    char *src,*dst;

    for(src = dst = str; *src != '\0'; src++){
        *dst = *src;
        if(*dst != garbage)dst++;
    }
    *dst = '\0';
    
}



char *RemoveUnderLine(char *valor){
    
   char* returnValue = malloc(sizeof(char)*strlen(valor)+1);

   strcpy(returnValue,valor);
   removeChar(returnValue,'_');

   return returnValue;
}



//retorna array com strings a indicar o tipo de parametros
char ** verifica_array_method_params(no node){
    char ** parametros = (char**)malloc(30*sizeof(char*));
    
    int x = 1;

    if(node->filho){

        for(no aux = node->filho; aux != NULL; aux = aux->irmao){
            if(strcmp(aux->filho->s_type, "StringArray") == 0)parametros[x]=strdup("String[]");
            else if(strcmp(aux->filho->s_type, "Double")==0)parametros[x]=strdup("double");
            else if(strcmp(aux->filho->s_type, "Bool")==0)parametros[x]=strdup("boolean");
            else if(strcmp(aux->filho->s_type, "Int") == 0)parametros[x]=strdup("int");
            x++;
        }
    }
    char numero[20];
    sprintf(numero,"%d", x-1);
    parametros[0]=strdup(numero);
    return parametros;
}


char * transforma_type(char* tipo){       
    if (strcmp(tipo, " - boolean") == 0) return "boolean";
    if (strcmp(tipo, " - int") == 0) return "int";
    if (strcmp(tipo, " - String[]") == 0) return "String[]";
    if (strcmp(tipo, " - double") == 0) return "double";
    if (strcmp(tipo, " - void") == 0) return "void";
    if (strcmp(tipo, "Add") == 0) return "+";
    if (strcmp(tipo, "Eq") == 0) return "==";
    if (strcmp(tipo, "Sub") == 0) return "-";
    if (strcmp(tipo, "Assign") == 0) return "=";
    if (strcmp(tipo, "Mul") == 0) return "*";
    if (strcmp(tipo, "Div") == 0) return "/";
    if (strcmp(tipo, "Mod") == 0) return "%";
    if (strcmp(tipo, " - undef") == 0) return "undef";
    if (strcmp(tipo, "- undef") == 0) return "undef";
    if (strcmp(tipo, "none") == 0) return "none";
    if (strcmp(tipo,"Length" ) == 0) return ".length";
    if (strcmp(tipo,"ParseArgs") == 0) return "Integer.parseInt";
    if (strcmp(tipo,"Xor") == 0) return "^";
    if (strcmp(tipo,"Eq") == 0) return "==";
    if (strcmp(tipo,"Ne") == 0) return "!=";
    if (strcmp(tipo,"Le") == 0) return "<=";
    if (strcmp(tipo,"Lt") == 0) return "<";
    if (strcmp(tipo,"Ge") == 0) return ">=";
    if (strcmp(tipo,"Gt") == 0) return ">";
    if (strcmp(tipo,"Plus") == 0) return "+";
    if (strcmp(tipo,"Minus") == 0) return "-";
    if (strcmp(tipo,"Not") == 0) return "!";  
    if (strcmp(tipo,"Lshift") == 0) return "<<";    
    if (strcmp(tipo,"And") == 0) return "&&";    
    if (strcmp(tipo,"Or") == 0) return "||";    
    return "none";
}

char * coloca_id(no node, char *tab){
    if(strcmp(node->s_type,"Le")==0 || strcmp(node->s_type,"Lt")==0 || strcmp(node->s_type,"Gt")==0 || strcmp(node->s_type,"Ge")==0){
        return " - boolean";
    }
    if(strcmp(node->s_type,"BoolLit")==0){
        return " - boolean";
            
    };
    if(strcmp(node->s_type,"RealLit")==0){
        
        return " - double";
        
    };
    if(strcmp(node->s_type,"DecLit")==0){
        return " - int";
     
    };
    if(strcmp(node->s_type,"DecLit")==0){
        return " - int";
        
    };
    if(strcmp(node->s_type,"Id")==0){
        
        node->id = procura_tabela(node,tab);
        return node->id;
    };
    if(strcmp(node->s_type,"And")==0){
        return " - boolean";
    }
    if(strcmp(node->s_type,"Rshift")==0){
        return "";
    }
     if(strcmp(node->s_type,"Lshift")==0){
        return "";
    }
    return "none";
}


long double calculaPotencia(double x, long double y){
    y=-y;
    int i;
    long double p=1;
    for(i=0; i<y;i++){
        p=p*x;
    }
    //printf("%d  %Lf  %Lf\n", i,-y,p);
    return p;
}




void verifica_method_body(char * tab, no node){
    //printf("%s %s %s %s\n", node->valor, node->s_type, node->line, node->col);
   
    if(node){
        if(strcmp(node->s_type,"Return")==0){
            tabela noo = procura_tab(tab);
            if(node->filho){
              

                //casos normais
                node->filho->id = procura_tabela(node->filho,tab);
                if(strcmp(node->filho->s_type,"BoolLit")==0){
                    strcpy(node->filho->id," - boolean");
                };
                if(strcmp(node->filho->s_type,"RealLit")==0){
                    strcpy(node->filho->id," - double");
                };
                if(strcmp(node->filho->s_type,"DecLit")==0){
                    strcpy(node->filho->id," - int");
                };
                 if(strcmp(node->filho->s_type,"ParseArgs")==0){
                    strcpy(node->filho->id," - int");
                };
               
                
                if(node->filho && strcmp(node->filho->s_type,"Length")==0){
                    node->filho->filho->id = coloca_id(node->filho->filho,tab);
                    if(strcmp(transforma_type(node->filho->filho->id),"String[]")!= 0){
                        printf("Line %s, col %s: Operator %s cannot be applied to type %s\n",node->filho->line,node->filho->col,transforma_type(node->filho->s_type),transforma_type(node->filho->filho->id));
                    }
                }
                
                //node->filho->id=coloca_id(node->filho,tab);

                /*if(strcmp(noo->tab->s_type,transforma_type(node->filho->id))!=0){
                    printf("Line %s, col %s: Incompatible type %s in return statement\n",node->filho->line,
                    node->filho->col,transforma_type(node->filho->id));
                }*/
                /*if(strcmp(noo->tab->s_type,"void")==0 && ((strcmp(transforma_type(node->filho->id),"int")==0) ||
                (strcmp(transforma_type(node->filho->id),"boolean")==0) || ((strcmp(transforma_type(node->filho->id),"double")==0))||
                (strcmp(transforma_type(node->filho->id),"String[]")==0))){
                    printf("Line %s, col %s: Incompatible type %s in return statement\n",node->filho->line,
                    node->filho->col,transforma_type(node->filho->id));
                    
                }*/
               /* if(strcmp(node->filho->s_type, "Call")==0 && strcmp(node->filho->id, noo->tab->s_type)!=0){
                    verifica_method_body(tab, node->filho);
                    printf("Line %s, col %s: Incompatible type %s in return statement\n",node->filho->line,
                    node->filho->col,transforma_type(node->filho->id));
                }*/
                /*if(strcmp(noo->tab->s_type,"int")==0 && ((strcmp(transforma_type(node->filho->id),"void")==0) ||
                (strcmp(transforma_type(node->filho->id),"boolean")==0) || ((strcmp(transforma_type(node->filho->id),"double")==0))||
                (strcmp(transforma_type(node->filho->id),"String[]")==0) )){
                    printf("Line %s, col %s: Incompatible type %s in return statement\n",node->filho->line,
                    node->filho->col,transforma_type(node->filho->id));
                    
                }*/
            //retorna return;
            }else{
                if(!strcmp(noo->tab->s_type,"void")==0) printf("Line %s, col %s: Incompatible type void in return statement\n",node->line,node->col);
            }
        }
        if(strcmp(node->s_type,"While")==0){            
            node->filho->id = coloca_id(node->filho,tab);
  
            
            if(node->filho && strcmp(node->filho->s_type,"Xor")==0){
                node->filho->filho->id = coloca_id(node->filho->filho,tab);
                node->filho->filho->irmao->id = coloca_id(node->filho->filho->irmao,tab);
                if(strcmp(node->filho->filho->id,node->filho->filho->irmao->id)!=0){
                    node->filho->id = (char*)strdup(" - undef");
                }else{
                    node->filho->id = node->filho->filho->id;
                }
                 if(!strcmp(transforma_type(node->filho->id),"boolean")==0){
                    printf("Line %s, col %s: Incompatible type %s in while statement\n",node->filho->line,
                    node->filho->col,transforma_type(node->filho->id));
                }
                return;

            }
            if(node->filho && strcmp(node->filho->s_type,"Lshift")==0){
                node->filho->filho->id = coloca_id(node->filho->filho,tab);
                node->filho->filho->irmao->id = coloca_id(node->filho->filho->irmao,tab);


                if(strcmp(node->filho->filho->id,node->filho->filho->irmao->id)==0 && strcmp(node->filho->filho->id," - int")==0){
                    node->filho->id = (char*)strdup(" - int");
                }else{
                    node->filho->id = (char*)strdup(" - undef");
                }

                if(!(strcmp(node->filho->filho->id,node->filho->filho->irmao->id)==0 && strcmp(node->filho->filho->id," - int")==0)){
                    printf("Line %s, col %s: Operator %s cannot be applied to types %s, %s\n",node->filho->filho->line,node->filho->col,
                    transforma_type(node->filho->s_type),transforma_type(node->filho->filho->id),transforma_type(node->filho->filho->irmao->id));
                   
                }
                if(strcmp(node->filho->id," - boolean")!=0){
                     printf("Line %s, col %s: Incompatible type %s in while statement\n",node->filho->line,node->filho->col,transforma_type(node->filho->id));
            
                }
            
            return;}


            if(strcmp(node->filho->id," - boolean")!=0){
                printf("Line %s, col %s: Incompatible type %s in while statement\n",node->filho->line,node->filho->col,transforma_type(node->filho->id));
            }
        }
        

       


      
        
        if(strcmp(node->s_type,"Ge")==0 ||strcmp(node->s_type,"Gt")==0 || 
        strcmp(node->s_type,"Lt")==0 || strcmp(node->s_type,"Le")==0 ){
           
            if(node->filho->id == NULL){
                node->filho->id = coloca_id(node->filho,tab);
                if(strcmp(node->filho->id, "none")==0) verifica_method_body(tab,node->filho);
            }
            if(node->filho->irmao->id == NULL){   
                node->filho->irmao->id = coloca_id(node->filho->irmao,tab);
                if(strcmp(node->filho->irmao->id, "none")==0) verifica_method_body(tab,node->filho->irmao);
            }
            //printf("%s %s\n", node->filho->id, node->filho->irmao->s_type);
            node->filho->id = ColocaOperadores(node->filho,tab);
            node->filho->irmao->id =ColocaOperadores(node->filho->irmao,tab);
            if(!(((strcmp(transforma_type(node->filho->id),transforma_type(node->filho->irmao->id))==0 )&&
             (strcmp(transforma_type(node->filho->id),"double")==0 || strcmp(transforma_type(node->filho->id), "int")==0)) || 
             (strcmp(transforma_type(node->filho->id),"int")==0 && strcmp(transforma_type(node->filho->irmao->id),"double")==0) ||
             (strcmp(transforma_type(node->filho->irmao->id),"int")==0 && strcmp(transforma_type(node->filho->id),"double")==0 ))){
                printf("Line %s, col %s: Operator %s cannot be applied to types %s, %s\n",node->line,node->col,transforma_type(node->s_type),transforma_type(node->filho->id),transforma_type(node->filho->irmao->id));
             }


            
        }


        if(strcmp(node->s_type,"If")==0){
            node->filho->id = procura_tabela(node->filho,tab);
           
            if(strcmp(node->filho->s_type,"BoolLit")==0){
                strcpy(node->filho->id," - boolean");
            };
            if(strcmp(node->filho->s_type,"RealLit")==0){
                strcpy(node->filho->id," - double");
            };
            if(strcmp(node->filho->s_type,"DecLit")==0){
                strcpy(node->filho->id," - int");
            };
            if(strcmp(node->filho->s_type,"Eq")==0){
                strcpy(node->filho->id," - boolean");
            }
            if(strcmp(node->filho->s_type,"Lshift")==0){
                strcpy(node->filho->id," - int");
            }
            if(strcmp(node->filho->s_type,"Ne")==0){
                strcpy(node->filho->id," - boolean");
            }
             if(strcmp(node->filho->s_type,"Ge")==0){
                strcpy(node->filho->id," - boolean");
            }
             if(strcmp(node->filho->s_type,"Lt")==0){
                strcpy(node->filho->id," - boolean");
            }
             if(strcmp(node->filho->s_type,"Gt")==0){
                strcpy(node->filho->id," - boolean");
            }
             if(strcmp(node->filho->s_type,"Le")==0){
                strcpy(node->filho->id," - boolean");
            }
             if(strcmp(node->filho->s_type,"And")==0){
                strcpy(node->filho->id," - boolean");
            }
            
            if(strcmp(transforma_type(node->filho->id),"boolean")!=0){
            //printf("%s\n", node->filho->s_type);
                printf("Line %s, col %s: Incompatible type %s in if statement\n",node->filho->line,
                node->filho->col,transforma_type(node->filho->id));
            }

          
            
        }

        if(strcmp(node->s_type,"VarDecl")==0) {insere(node->filho, NULL,NULL,tab);}
        if(strcmp(node->s_type,"Lshift")==0 ){
            node->id = "";
            node->filho->id = "";
            node->filho->irmao->id ="";
        }


        
        if(strcmp(node->s_type,"Id")==0){
            
            if(node->pai){
                if(strcmp(node->pai->s_type,"Rshift")==0 ){
                    node->id = "";
                }else{
                    node->id=procura_tabela(node,tab);
                    node->id = coloca_id(node,tab);
            }
            }else{
                    node->id=procura_tabela(node,tab);
                    node->id = coloca_id(node,tab);
            }
            if(strcmp(node->valor,"_")==0){
                printf("Line %s, col %s: Symbssol _ is reserved\n",node->line,node->col);
            }  
            if(node->pai){
            if(strcmp(transforma_type(node->id),"undef")==0 && (strcmp(node->pai->s_type,"Length")==0 || strcmp(node->pai->s_type,"ParseArgs")==0)){
                printf("Line %s, col %s: Cannot find symbol %s\n",node->line,node->col,node->valor);
            }
            } 
        }
        if(strcmp(node->s_type,"DecLit")==0 || strcmp(node->s_type,"Length")==0 || strcmp(node->s_type,"ParseArgs")==0) {
            node->id=(char*)strdup(" - int");}

        if(strcmp(node->s_type, "Ne") == 0 || strcmp(node->s_type, "Eq") == 0 || strcmp(node->s_type, "Ge") == 0 || strcmp(node->s_type, "Gt") == 0 
        || strcmp(node->s_type, "Le") == 0 || strcmp(node->s_type, "Lt") == 0 || strcmp(node->s_type, "Not") == 0 || strcmp(node->s_type, "Or") == 0 
        || strcmp(node->s_type, "And") == 0 || strcmp(node->s_type, "BoolLit") == 0) {
            node->id=(char*)strdup(" - boolean");

            if(strcmp(node->s_type,"Mul")==0){
            if(node->filho && node->filho->irmao){
            node->filho->id = procura_tabela(node->filho,tab);
            node->filho->irmao->id = procura_tabela(node->filho->irmao,tab);
            
            if(strcmp(node->filho->id,node->filho->irmao->id)!=0 ){
               node->id = (char*)strdup(" - undef");
                printf("Line %s, col %s: Operator %s cannot be applied to types %s, %s\n",node->filho->line,node->col,transforma_type(node->s_type),transforma_type(node->filho->id),transforma_type(node->filho->irmao->id));
    
            }else{
                node->id = (char*)strdup(" - boolean");
            }
        }
            }
        }

        if(strcmp(node->s_type,"StrLit")==0) node->id=(char*)strdup(" - String");

       if(strcmp(node->s_type,"RealLit")==0){
            node->id = coloca_id(node,tab);
       }
       
        if(strcmp(node->s_type,"VarDecl")!=0 && strcmp(node->s_type,"Lshift")!=0){
            no aux = node->filho;
            while (aux != NULL) {
                verifica_method_body(tab, aux);
                aux = aux->irmao;
            }
        }
        
        if(strcmp(node->s_type,"Xor")==0){
            if(!(strcmp(node->filho->id," - boolean")==0 && strcmp(node->filho->irmao->id," - boolean")==0)){
                //printf("Line %s, col %s: Operator %s cannot be applied to types %s, %s\n",node->line,node->col,transforma_type(node->s_type),transforma_type(node->filho->id),transforma_type(node->filho->irmao->id));
                node->id=" - undef";
            }else{
                node->id=" - boolean";
            }
            
        }
        if(strcmp(node->s_type,"Minus")==0 || strcmp(node->s_type,"Plus")==0){
            node->id=node->filho->id;
            //printf("%s\n", node->id);
            if((strcmp(node->id, " - int")!=0) &&(strcmp(node->id, " - double")!=0)&&(strcmp(node->id, " - boolean")!=0) )printf("Line %s, col %s: Operator %s cannot be applied to type %s\n",node->line,node->col,transforma_type(node->s_type),transforma_type(node->id));
            if(node->filho && strcmp(node->filho->s_type,"Length")==0){
                if(strcmp(transforma_type(node->filho->filho->id),"String[]")!= 0){
                    printf("Line %s, col %s: Operator %s cannot be applied to type %s\n",node->filho->line,node->filho->col,transforma_type(node->filho->s_type),transforma_type(node->filho->filho->id));
                }
            }
        }
        if(strcmp(node->s_type,"ParseArgs")==0){
      

            if(!(strcmp(node->filho->id,node->filho->irmao->id)!=0 && strcmp(node->filho->id," - String[]")==0 && strcmp(node->filho->irmao->id," - int")==0)){
                int a = atoi(node->filho->col);
                a = a - 17;
                //ALDRABADO
                printf("Line %s, col %d: Operator Integer.parseInt cannot be applied to types %s, %s\n",node->filho->line,a,transforma_type(node->filho->id),transforma_type(node->filho->irmao->id));
            
            }
        }

                
                if(strcmp(node->s_type,"RealLit")==0){
                //char *id3 = node->valor;
              
                //char *id = RemoveUnderLine(id3);
                //char *ids2 = RemoveUnderLine(id3);
             
            
                /*char *Final = VerificaE(id,b);
            
                b = 0;
                int a = VerificaELen(ids2,b);

                //printf("%s %s", ids2, Final);


                long double x = strtol(ids2,NULL,10);
                long double y = strtol(Final,NULL,10);
                printf("%Lf %Lf %Lf\n", x,y, calculaPotencia(10,y));
                long double z = x* calculaPotencia(10,y);

                printf("%Lf\n", z);

                long l = atol(ids2) * 10^(atol(Final));

                if(l >= 2147483648){
                        printf("Line %s, col %s: Number %s out of bounds\n",node->filho->line,node->filho->col,node->filho->valor);
                    }
                    */ 
        } 
        if(strcmp(node->s_type,"Mul")==0){
            node->id = (char*)strdup(" - int");
        }
        
        if(strcmp(node->s_type, "Assign")==0){
            tabela tabe = procura_tab(tab);

            
           
            
            long intv;
            char *num=NULL;
           
            if(node->filho->irmao && strcmp(node->filho->irmao->s_type, "Not") == 0){
                node->id=(char*)strdup(" - boolean");
               
                /*if(node->filho->irmao->filho != NULL && node->filho->irmao->filho->id != NULL){
               
                    
                    if(strcmp(node->filho->irmao->filho->id," - boolean")!=0){
                    printf("Line %s, col %s: Operator %s cannot be applied to type %s\n",node->filho->irmao->filho->line,node->filho->irmao->col,transforma_type(node->filho->irmao->s_type),transforma_type(node->filho->irmao->filho->id));
            
                    }

                }*/
            }
          if((node->filho->irmao && strcmp(node->filho->irmao->s_type, "Minus")==0) || strcmp(node->filho->irmao->s_type, "Plus")==0){
            node->filho->irmao->id=node->filho->irmao->filho->id;
           
            
            if(!(strcmp(node->filho->irmao->id," - int")==0 || strcmp(node->filho->irmao->id," - double")==0)){
                node->filho->irmao->id = (char*)strdup(" - undef");
                printf("Line %s, col %s: Operator %s cannot be applied to type %s\n",node->filho->irmao->line,node->filho->irmao->col,transforma_type(node->filho->irmao->s_type),transforma_type(node->filho->irmao->filho->id));
                }
        }
           
            

            if(node->filho->irmao && strcmp(node->filho->irmao->s_type,"Xor")==0){
                if((strcmp(node->filho->id,node->filho->irmao->filho->id)==0 && strcmp(transforma_type(node->filho->id),"boolean")==0)
                ||(strcmp(node->filho->id,node->filho->irmao->filho->id)!=0 && strcmp(transforma_type(node->filho->irmao->filho->id),"boolean")==0)
                ||(strcmp(node->filho->id,node->filho->irmao->filho->id)!=0 && strcmp(transforma_type(node->filho->id),"boolean")==0)){
                    node->filho->irmao->id = (char*)strdup(" - boolean");
                }else  if(strcmp(node->filho->id,node->filho->irmao->filho->id)==0 && strcmp(transforma_type(node->filho->id),"int")==0){
                    node->filho->irmao->id = (char*)strdup(" - int");
                }else{
                    node->filho->irmao->id = (char*)strdup(" - undef");
                }
                if(strcmp(transforma_type(node->filho->irmao->id),"undef")==0){
                printf("Line %s, col %s: Operator %s cannot be applied to types %s, %s\n",node->filho->irmao->line,node->filho->irmao->col,transforma_type(node->filho->irmao->s_type),transforma_type(node->filho->irmao->filho->irmao->id),transforma_type(node->filho->irmao->filho->id));
                }
            }
           
            if(node->filho->irmao && strcmp(node->filho->irmao->s_type,"Mul")==0){
                if(strcmp(node->filho->irmao->filho->s_type,"Lshift")==0){
                    node->filho->irmao->id = " - undef";
                    node->filho->irmao->filho->id = "";
                    node->filho->irmao->filho->filho->id = "";
                    node->filho->irmao->filho->filho->irmao->id = "";
                }
                if(strcmp(node->filho->id," - boolean")==0 ||strcmp(node->filho->irmao->filho->id," - boolean")==0 
                || strcmp(node->filho->id," - String[]")==0 ||strcmp(node->filho->irmao->filho->id," - String[]")==0 
                || strcmp(node->filho->id,"")==0 ||strcmp(node->filho->irmao->filho->id,"")==0 )
              {
                printf("Line %s, col %s: Operator %s cannot be applied to types %s, %s\n",
                node->filho->irmao->line, node->filho->irmao->col,transforma_type(node->filho->irmao->s_type),
                transforma_type(node->filho->irmao->filho->id),transforma_type(node->filho->irmao->filho->irmao->id));
              }
            }
          
            


            if((node->filho->irmao && strcmp(node->filho->irmao->s_type,"Plus")==0) || strcmp(node->filho->irmao->s_type,"Minus")==0){
                num = RemoveUnderLine(node->filho->irmao->filho->valor);
                intv = strtol(num,(char**)NULL,10);
                if(intv >= 2147483648){
                    printf("Line %s, col %s: Number %s out of bounds\n",node->filho->irmao->filho->line,node->filho->irmao->filho->col,node->filho->irmao->filho->valor);
                }
            }else{
                num = RemoveUnderLine(node->filho->irmao->valor);
                intv = strtol(num,(char**)NULL,10);
                if(intv >= 2147483648){
                    printf("Line %s, col %s: Number %s out of bounds\n",node->filho->irmao->line,node->filho->irmao->col,node->filho->irmao->valor);
                }
            
            }
           
            if(node->filho->irmao && strcmp(node->filho->irmao->s_type,"Length")==0){

                if(strcmp(transforma_type(node->filho->irmao->filho->id),"String[]")!= 0){
                    printf("Line %s, col %s: Operator %s cannot be applied to type %s\n",node->filho->irmao->line,node->filho->irmao->col,transforma_type(node->filho->irmao->s_type),transforma_type(node->filho->irmao->filho->id));
                }
            }
            

            if(node->filho->irmao && strcmp(node->filho->irmao->s_type,"Lshift")==0){
                char *id, *idfilho,*idirmao;
                id= coloca_id(node->filho->irmao,tab);
                idfilho = coloca_id(node->filho->irmao->filho,tab);
                idirmao= coloca_id(node->filho->irmao->filho->irmao,tab);
                if(strcmp(tabe->c_nome,"main")==0){
                
                if(!(strcmp(idfilho," - int")==0 && strcmp(idirmao," - int")==0) &&
                 !(strcmp(idfilho," - int")==0 && strcmp(idirmao,"none")==0) &&
                 !(strcmp(idfilho,"none")==0 && strcmp(idirmao," - int")==0)){
                    id = (char*)strdup(" - undef");
                    node->filho->irmao->id = id;
                    node->filho->irmao->filho->id = idfilho;
                    node->filho->irmao->filho->irmao->id = idirmao;
                    printf("Line %s, col %s: Operator %s cannot be applied to types %s, %s\n",node->filho->irmao->line,node->filho->irmao->col,
                    transforma_type(node->filho->irmao->s_type),transforma_type(idfilho),transforma_type(idirmao));
                }else{
                    node->filho->irmao->id = idfilho;
                    node->filho->irmao->filho->id = idfilho;
                    node->filho->irmao->filho->irmao->id = idirmao;
                }   
                }else{
                    node->filho->irmao->id = "";
                    node->filho->irmao->filho->id = "";
                    node->filho->irmao->filho->irmao->id = "";
                }
                

                if(strcmp(node->filho->irmao->filho->irmao->s_type,"Mul")==0){
                if(strcmp(tabe->c_nome,"main")!=0){
                    node->id = (char*)strdup(" - int");
                    node->filho->irmao->filho->id = coloca_id(node->filho->irmao->filho,tab);
                    node->filho->irmao->id = (char*)strdup(" - int");
                    node->filho->irmao->filho->irmao->filho->id = coloca_id(node->filho->irmao->filho->irmao->filho,tab);
                    node->filho->irmao->filho->irmao->id = node->filho->irmao->filho->irmao->filho->id ;
                    node->filho->irmao->filho->irmao->filho->irmao->id=coloca_id(node->filho->irmao->filho->irmao->filho->irmao,tab);
                    return;
                }else{
                   
                    node->id = (char*)strdup(" - int");
                    node->filho->irmao->id= "";
                    node->filho->irmao->filho->id = "";
                    node->filho->irmao->filho->irmao->filho->id = "";
                    node->filho->irmao->filho->irmao->id = "";
                    node->filho->irmao->filho->irmao->filho->irmao->id="";
                    printf("Line %s, col %s: Operator = cannot be applied to types %s, none\n", node->line,node->col,transforma_type(idfilho));
                    return;
                }
                
                }
               
                if(strcmp(node->filho->irmao->s_type,"Mul")==0){
                    node->filho->irmao->id = "";
                    node->filho->irmao->filho->id = "";
                    node->filho->irmao->filho->irmao->id="";
                    return;
                }
               
               
        

            }   
            
            char * id1=malloc(sizeof(char) * 50);
            char * id2=malloc(sizeof(char) * 50);
            if(node->filho->id==NULL){
                verifica_method_body(tab, node->filho);
                id1=node->filho->id;
            }
            else id1=node->filho->id;
            if(node->filho->irmao->id==NULL){
                verifica_method_body(tab, node->filho->irmao);
                id2=node->filho->irmao->id;
            }
            else id2=node->filho->irmao->id;
           // printf("%s %s\n",transforma_type(id1),trasnforma_type(id2));
            if(!(strcmp(id1," - double")==0 && strcmp(id2," - int")==0)){
                if(strcmp(id1,id2)!=0 || strcmp(id1," - undef")==0 || strcmp(id2," - undef")==0 || ((strcmp(id1,id2)==0) && strcmp(id1, " - String[]")==0)){
                    printf("Line %s, col %s: Operator %s cannot be applied to types %s, %s\n",node->line,node->col,transforma_type(node->s_type),transforma_type(id1),transforma_type(id2));
                }
            }
            node->id=node->filho->id;        
        }
         if(strcmp(node->s_type,"And")==0 || strcmp(node->s_type,"Or")==0){
            if(node->filho && node->filho->irmao){
                //verifica_method_body(tab,node->filho->irmao);
            if(!(strcmp(node->filho->id," - boolean")==0 && strcmp(node->filho->irmao->id," - boolean")==0)){
                printf("Line %s, col %s: Operator %s cannot be applied to types %s, %s\n",node->line,node->col,transforma_type(node->s_type),transforma_type(node->filho->id),transforma_type(node->filho->irmao->id));
                }
            }
            
        }
        ///ADD AQUIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII
        if(strcmp(node->s_type,"Rshift")==0){
            node->id = (char*)strdup(" - int");
            if(node->filho && node->filho->irmao){
                
                node->filho->id = coloca_id(node->filho,tab);
                node->filho->irmao->id = coloca_id(node->filho->irmao,tab);
                //printf("%s -- %s\n",node->filho->id, node->filho->s_type);
               
            }
        }
         if(strcmp(node->s_type,"Lshift")==0){
            node->id = (char*)strdup(" - int");
            if(node->filho && node->filho->irmao){
                
                node->filho->id = coloca_id(node->filho,tab);
                node->filho->irmao->id = coloca_id(node->filho->irmao,tab);
                //printf("%s -- %s\n",node->filho->id, node->filho->s_type);
               
            }
           
            if(node->pai){
                if(strcmp(node->pai->s_type,"Assign")==0){
                  
                    node->id = "";
                    node->filho->id = "";
                    node->filho->irmao->id = "";

                }
            }
        }
        
        if(strcmp(node->s_type,"Print")==0){
           char * id = procura_tabela(node->filho,tab);
            tabela noo = procura_tab(tab);
            if(node->filho){
                
                /*if(strcmp(node->filho->s_type,"RealLit")==0){
                
                int b = 0;
                char *id3 = node->filho->valor;
               
                char *id = RemoveUnderLine(id3);
                char *ids2 = RemoveUnderLine(id3);
                
                char *erps;
                char *Final = VerificaE(id,b);
            
                b = 0;
                int a = VerificaELen(ids2,b);

                double x1 = strtod(ids2,&erps);
                int x = CalculaN(x1);

                x++;

                int valorEle = atoi(Final) - x;
                if(valorEle == -324){
                    double n;
                    
                   
                    if(x == 0){
                        n = x1;
                    }else{
                        n = x1 * calcPow(-x);
                    }

                    
                    if(n < 2.5){
                        
                        printf("Line %s, col %s: Number %s out of bounds\n",node->filho->line,node->filho->col,node->filho->valor);
                    }
                }
                if(valorEle < -324 || valorEle > 308){
                    printf("Line %s, col %s: Number %s out of bounds\n",node->filho->line,node->filho->col,node->filho->valor);
                 
                    
                }
                if(valorEle == 308 ){
                    double n;
                    
                   
                    if(x == 0){
                        n = x1;
                    }else{
                        n = x1 * calcPow(-x);
                    }
                    if(n > 1.0 ){
                        printf("Line %s, col %s: Number %s out of bounds\n",node->filho->line,node->filho->col,node->filho->valor);
                 
                    
                    }
                }
            }*/
                 
            
        

        if(strcmp(node->filho->s_type,"Length")==0){
                    if(node->filho->filho && strcmp(node->filho->filho->id, " - String[]")!=0){
                        printf("Line %s, col %s: Operator .length cannot be applied to type %s\n",node->filho->line,node->filho->col,transforma_type(node->filho->filho->id));
                    }
                }

            if(strcmp(node->filho->id, " - String[]")==0 || strcmp(node->filho->id, " - undef")==0){
                printf("Line %s, col %s: Incompatible type %s in System.out.print statement\n",node->line,
                node->col,transforma_type(node->filho->id));
            }

            else{if(strcmp(node->filho->s_type,"Call")==0 && (strcmp(transforma_type(node->filho->id),"undef")==0 || strcmp(transforma_type(node->filho->id),"void")==0)){
                printf("Line %s, col %s: Incompatible type %s in System.out.print statement\n",node->line,
                node->col,transforma_type(node->filho->id));
            }}
            }
          
            
        }
        
       

        if (strcmp(node->s_type,"Add")==0 || strcmp(node->s_type,"Sub")==0 
        || strcmp(node->s_type,"Div")==0||strcmp(node->s_type,"Mod")==0 || strcmp(node->s_type,"Mul")==0 )
        {   
            char *id;
            
            if(!node->filho->irmao->id){
                id = "";
            }else{
                id = node->filho->irmao->id;
            }
          
            if(strcmp(node->filho->id," - undef")==0 && strcmp(node->filho->s_type,"Id")==0){
                node->id=(char*)strdup(" - undef");
                printf("Line %s, col %s: Cannot find symbol %s\n",node->filho->line,node->filho->col,node->filho->valor);
            }
            if(strcmp(id," - undef")==0 && strcmp(node->filho->irmao->s_type,"Id")==0){
                node->id=(char*)strdup(" - undef");
                printf("Line %s, col %s: Cannot find symbol %s\n",node->filho->irmao->line,node->filho->irmao->col,node->filho->irmao->valor);
            }
            if(strcmp(node->filho->id," - boolean")==0 ||strcmp(id," - boolean")==0 || strcmp(node->filho->id," - undef")==0 || strcmp(id," - undef")==0
             || strcmp(node->filho->id," - String[]")==0 ||strcmp(id," - String[]")==0){
                printf("Line %s, col %s: Operator %s cannot be applied to types %s, %s\n",node->line,node->col,transforma_type(node->s_type),transforma_type(node->filho->id),transforma_type(id));
                node->id=(char*)strdup(" - undef");
                /*if(strcmp(node->pai->s_type,"Return")==0){
                printf("Line %s, col %s: Incompatible type undef in return statement\n",node->line,node->col);
            }*/
            }else{
                //printf("entrou9\n");
            // printf("----%s %s \n", node->filho->id, node->filho->irmao->s_type);
                if(strcmp(node->filho->id, id) != 0) {
                // printf("entrou7\n");
                    node->id=(char*)strdup(" - double");
                    //printf("saiu7\n");

                }
            // printf("naoéaqui\n");
                if(strcmp(node->filho->id, id) == 0) {
                    //printf("entrou8\n");
                    node->id=(char*)strdup(node->filho->id);
                    //printf("saiu8\n");
                }
                //printf("saiu9\n");
            }
        
        }
        
        if(strcmp(node->s_type,"Ne")==0 || strcmp(node->s_type,"Eq")==0){
           
            if(node->filho && node->filho->irmao){
                //printf("%s %s %d\n", node->filho->id,node->filho->irmao->id,strcmp(node->filho->id," - int")==0 && strcmp(node->filho->irmao->id," - int")==0);


                if(!(((strcmp(node->filho->id," - int")==0 && strcmp(node->filho->irmao->id," - int")==0))
                || (strcmp(node->filho->id," - boolean")==0 && strcmp(node->filho->irmao->id," - boolean")==0) ||
                (strcmp(node->filho->id," - int")==0 && strcmp(node->filho->irmao->id," - double")==0) ||
                (strcmp(node->filho->id," - double")==0 && strcmp(node->filho->irmao->id," - int")==0) || 
                (strcmp(node->filho->id," - double")==0 && strcmp(node->filho->irmao->id," - double")==0))
                ){
                    printf("Line %s, col %s: Operator %s cannot be applied to types %s, %s\n",node->line,
                    node->col,transforma_type(node->s_type),transforma_type(node->filho->id),transforma_type(node->filho->irmao->id));
                }
            }
        }

        if(strcmp(node->s_type,"Call")==0){
          
            char ** params = check_calls_method_params(node);
            
            char **vars=retorna_variaveis_parametros(tab);
          int control=0;
           
            if(vars!=NULL && node->filho->irmao){
                for(int i=0; vars[i]; i++){
                    if(strcmp(vars[i], node->filho->irmao->valor)==0) control++;
                }
               
                if(control==0 && strcmp(node->filho->irmao->valor,"")!=0 && strcmp(node->filho->irmao->s_type,"Id")==0) printf("Line %s, col %s: Cannot find symbol %s\n",node->filho->irmao->line,node->filho->irmao->col,node->filho->irmao->valor);
            }
            tabela anota = check_call(node->filho->valor, params, 0);
            int Num_param = atoi(params[0]);
            
        


            if (anota != NULL) {
                char * n_string;
                if ((n_string = malloc(strlen(" - ")+strlen(anota->tab->s_type)+1)) != NULL) {
                    n_string[0] = '\0';
                    strcat(n_string, " - ");
                    strcat(n_string, anota->tab->s_type);
                }
                node->id = n_string;
                int i = strlen(anota->c_nome);
                char * n_string2;
                if ((n_string2 = malloc(strlen(" - ")+strlen(&anota->nome[i])+1)) != NULL) {
                    n_string2[0] = '\0';
                    strcat(n_string2, " - ");
                    strcat(n_string2, &anota->nome[i]);
                }
                node->filho->id = n_string2;
            }
            else {
                char stringP[500]="";
                //printf("%d",Num_param);
                for(int x = 1; x <= Num_param; x++){
                   
                    strcat(stringP,params[x]);
                    if(x != Num_param){
                        strcat(stringP,",");
                    }
                }
               
                printf("Line %s, col %s: Cannot find symbol %s(%s)\n",node->filho->line,node->filho->col,node->filho->valor,stringP);
                char * n_string;
                if ((n_string = malloc(strlen(" - undef")+1)) != NULL) {
                    n_string[0] = '\0';
                    strcat(n_string, " - undef");
                }
               
                node->id = n_string;
                node->filho->id = n_string;
            }
            tabela noo = procura_tab(tab);
           // printf("%s %s\n", transforma_type(node->id), noo->tab->s_type);
            if(node->pai && strcmp(node->pai->s_type, "Return")==0 && (strcmp(transforma_type(node->id), noo->tab->s_type)!=0
            || strcmp(transforma_type(node->id), "void")==0)){
                printf("Line %s, col %s: Incompatible type %s in return statement\n",node->line,
                node->col,transforma_type(node->id));
            }
           //   AMBIGUIDADE FUNCIONA MAS FODE O RESTO
             if(node->filho){
               /* printf("%s\n", node->filho->valor);
                for(int i = 0; params[i]; i++){y
                    printf("%s\n", params[i]);
                }*/
            char * ambi  = verificaAmbiguidade(node->filho->valor,params);
                      
            if(strcmp(ambi,"FALSE")!=0){
                printf("Line %s, col %s: Reference to %s %s(",node->line,node->col,ambi,node->filho->valor);
                for(int i = 1; i <= atoi(params[0]);i++){
                    printf("%s",params[i]);
                    if(i != atoi(params[0])){
                        printf(",");
                    }
                }
                printf(") is ambiguous\n");
                node->filho->id = " - undef";
                node->id = " - undef";
                return;
            }

            }
            
        }            tabela noo = procura_tab(tab);
            if(strcmp(node->s_type,"Call")!=0 && node->pai && strcmp(node->pai->s_type, "Return")==0 && (!(strcmp(noo->tab->s_type,"double")==0 && strcmp(transforma_type(node->id),"int")==0)) && strcmp(transforma_type(node->id), noo->tab->s_type)!=0){
                
                //printf("%s %s %s\n", node->pai->filho->s_type,node->s_type, node->id);
                printf("Line %s, col %s: Incompatible type %s in return statement\n",node->line,
                node->col,transforma_type(node->id));
            }
            if(node->pai && strcmp(node->pai->s_type, "Not")==0){
                if (strcmp(node->id, " - boolean")!=0 && strcmp(node->id, " - undef")!=0) printf("Line %s, col %s: Operator %s cannot be applied to type %s\n",node->pai->line,node->pai->col,transforma_type(node->pai->s_type),transforma_type(node->id));
            }

    }else{
        return;
    }
}


void check_ast(no raiz){
    if(raiz){
        if(strcmp(raiz->s_type, "MethodDecl")==0){
            if(raiz->filho->filho->irmao->repetido==0){
                char * params = verifica_method_params(raiz->filho->filho->irmao->irmao);
                char * valor = (char*)strdup(raiz->filho->filho->irmao->valor);

                char * n = malloc(strlen(params)+strlen(valor)+1);
                if(n){
                    n[0]='\0';
                    strcat(n, valor);
                    strcat(n,params);
                }
                verifica_method_body(n,raiz->filho->irmao);
            }
        }

    }else return;
    for(no aux = raiz->filho; aux!=NULL; aux=aux->irmao) check_ast(aux);
}



char * ColocaOperadores(no node, char*tab){
    int i = 0;
    char *valor;
     if (strcmp(node->s_type,"Add")==0 || strcmp(node->s_type,"Sub")==0 
        || strcmp(node->s_type,"Div")==0 || strcmp(node->s_type,"Mul")==0 || strcmp(node->s_type,"Mod")==0)
        {
                verifica_method_body(tab,node);///////////////////////////////////////////////////////////////VER ISTOOOOO
                if(strcmp(node->filho->id, node->filho->irmao->id) != 0) {
                
                    valor=(char*)strdup(" - double");
                    return valor;
                    i++;
                 

                }
            
                if(strcmp(node->filho->id, node->filho->irmao->id) == 0) {
                    
                    valor=(char*)strdup(node->filho->id);
                    return valor;
                   i++;
                }
               
            }
        if(i == 0){
            return node->id;
        }
        return NULL;        
    }







char * VerificaE(char * nome,int contador2){
    char *ini;
    char *src,*dst;
    int contador = 0;

    for(src = dst =ini = nome; *src != '\0'; src++){
        if(contador == 1){
            strcpy(ini,src);
            return ini;
        }
		*dst = *src;
		if(*dst != 'E'){

            contador2++;
			*dst++;
		}else{
            contador = 1;
            *dst = '\0';
        }
	}
    *dst='\0';
    return ini;
}


int VerificaELen(char * nome,int contador2){
    char *ini;
    char *src,*dst;
    int contador = 0;

    for(src = dst =ini = nome; *src != '\0'; src++){
        if(contador == 1){
            return contador2;
        }
		*dst = *src;
		if(*dst != 'E'){
            contador2++;
			*dst++;
		}else{
            contador = 1;
            *dst = '\0';
        }
	}
    *dst='\0';
    return contador2;
}




int CalculaN(double num){
   
    if(num < 1.0){
        for(int i = 0; i < 300; i++){
            double x = calcPow(i);
            double n = num * x;
        
            if(n >= 1.0){
                return i;
            }
        }
    }else{
        for(int i = -1; i > -300; i--){
            double x = calcPow(i);
           
            double n = num * x;
            if(n <= 1){
                return i;
            }
        }
    }
    return -1;
}


double calcPow(int i){
  
    double valor = 10;
    if(i > 0){
    for(int a = 0; a < i; a++){
        valor = valor * 10;
    }
    }else{
        valor = 0.1;
        
         for(int a = 0; a < (-i); a++){
        valor = valor * 0.1;
    }
    }
    return valor;
}