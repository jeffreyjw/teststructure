/* 
 * File:   parser.h
 * Author: jeffrey
 *
 * Created on 21 kwiecień 2014, 17:50
 */

#ifndef PARSER_H
#define	PARSER_H

#include "class.h"
#include "mpc.h"

typedef struct {
    char* result;
    mpc_parser_t* language;
    mpc_parser_t* suite;
    mpc_parser_t* type_string;
    mpc_parser_t* function;
    mpc_parser_t* comment;
} Parser;


PUBLIC Parser* parser_create(void);
PUBLIC void parser_free(Parser* parser);
PRIVATE void parser_init(Parser* parser);
PUBLIC void parser_parse(Parser* parser, const char* input);

#endif	/* PARSER_H */

