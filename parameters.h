/* 
 * File:   parameters.h
 * Author: jeffrey
 *
 * Created on 21 kwiecień 2014, 16:31
 */

#ifndef PARAMETERS_H
#define	PARAMETERS_H

#include "class.h"


typedef struct {
    char* file;
    char* language;
    char* output_file;
} Parameters;


PUBLIC Parameters*  parameters_create(int argc, char ** argv);
PUBLIC void parameters_free(Parameters* parameters);
PRIVATE char* fill_str(char* from);

#endif	/* PARAMETERS_H */

