/* 
 * File:   parser.h
 * Author: jeffrey
 *
 * Created on 21 kwiecień 2014, 17:50
 */

#ifndef PARSER_H
#define	PARSER_H

#include "class.h"

typedef struct {
    char* result;
} Parser;


PUBLIC Parser* parser_create(void);
PUBLIC void parser_free(Parser* parser);

#endif	/* PARSER_H */

