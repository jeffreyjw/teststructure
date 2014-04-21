#include "parser.h"

#include <stdlib.h>


PUBLIC Parser* parser_create(void)
{
    Parser* parser = malloc(sizeof(Parser));
    return parser;
}


PUBLIC void parser_free(Parser* parser)
{
    free(parser);
}