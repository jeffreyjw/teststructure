#include "parameters.h"

#include <stdlib.h>
#include <string.h>
#include <argp.h>

Parameters* PUBLIC parameters_create(int argc, char ** argv)
{
    Parameters* parameters = malloc(sizeof(Parameters));
    parameters->file = fill_str( argc > 1 ? argv[1] : "input.js" );
    parameters->language = fill_str("js");
    parameters->output_file = fill_str("report.json");
    return parameters;
}


PRIVATE char* fill_str(char* from)
{
    char* ptr = malloc(sizeof(char)*10);
    strcpy(ptr, from);
}


void PUBLIC parameters_free(Parameters* parameters)
{
    free(parameters->file);
    free(parameters->language);
    free(parameters->output_file);
    free(parameters);
}