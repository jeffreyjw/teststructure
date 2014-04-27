#include "parser.h"

#include <stdlib.h>


PUBLIC Parser* parser_create(void)
{
    Parser* parser = malloc(sizeof(Parser));
    parser_init(parser);
    return parser;
}


PRIVATE void parser_init(Parser* parser)
{
    parser->type_string = mpc_new("type_string");
    parser->suite = mpc_new("suite");
    parser->language = mpc_new("mocha");
    parser->function = mpc_new("function");
    parser->comment = mpc_new("comment");
    
    mpca_lang(MPCA_LANG_DEFAULT, 
            "                                             \
              type_string : '\"' /[a-zA-Z0-9_\\s\\.\\,]*/ '\"' ;   \
              function    : \"function\" '(' ')' '{' (<suite>+|/[^\\}]*/) '}' ;  \
              comment     : \"/**\" /[^(\\*\\/)]*/ \"*/\" ; \
              suite       : <comment>? \"it\" '(' <type_string> ',' <function> ')' /\\;?/ ;  \
              mocha       : <suite>       ;               \
            "
            , parser->type_string,
            parser->function,
            parser->comment,
            parser->suite,
            parser->language);
}


PUBLIC void parser_parse(Parser* parser, const char* input)
{
    printf("%s\n\n", input);
    mpc_result_t r;
    if (mpc_parse("<stdin>", input, parser->language, &r)) {
      /* On Success Print the AST */
      mpc_ast_print(r.output);
      mpc_ast_delete(r.output);
    } else {
      /* Otherwise Print the Error */
      mpc_err_print(r.error);
      mpc_err_delete(r.error);
    }
}


PUBLIC void parser_free(Parser* parser)
{
    mpc_cleanup(5, 
            parser->type_string,
            parser->suite,
            parser->function,
            parser->comment,
            parser->language);
    
    free(parser);
}