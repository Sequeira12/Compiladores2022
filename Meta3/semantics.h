#include "symbol_table.h"

void verifica(no raiz);
void verifica_method_decl(no node);
char * verifica_method_params(no node);
char ** verifica_array_method_params(no node);
void verifica_method_body(char * tab, no node);
void check_ast(no raiz);