#include <stdio.h>
#include <stdlib.h>

#include "parameters.h"
#include "file_to_string.h"
#include "parser.h"


Parameters* parameters = NULL;
char* file_contents = NULL;
Parser* parser = NULL;


void clean(void)
{
    if (file_contents)
        free(file_contents);
    
    if (parameters)
        parameters_free(parameters);
    
    if (parser)
        parser_free(parser);
}


int main(int argc, char ** argv)
{
    parameters = parameters_create(argc, argv);
    file_contents = file_to_string(parameters->file);
    
    if (file_contents == NULL)
    {
        printf("Error: could not read %s\n", parameters->file);
        return EXIT_FAILURE;
    }
    
    parser = parser_create();
    
    parser_parse(parser, file_contents);
    
    clean();
    
    return EXIT_SUCCESS;
}
