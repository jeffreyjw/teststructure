#include "file_to_string.h"

#include <stdlib.h>
#include <stdio.h>


PUBLIC char* file_to_string(char* path)
{
    char* file_contents;
    long input_file_size;
    
    FILE* input_file = fopen(path, "rb");
    
    if (input_file == NULL)
    {
        return NULL;
    }
    
    fseek(input_file, 0, SEEK_END);
    
    input_file_size = ftell(input_file);
    rewind(input_file);
    file_contents = malloc(sizeof(char) * input_file_size);
    fread(file_contents, sizeof(char), input_file_size, input_file);
    
    fclose(input_file);
    
    return file_contents;
}