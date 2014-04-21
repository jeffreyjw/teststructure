#include <stdio.h>

#include "parameters.h"


int main(int argc, char ** argv)
{
    Parameters* parameters = parameters_create(argc, argv);
    
    printf("%s\n", parameters->file);
    
    parameters_free(parameters);
    return 0;
}