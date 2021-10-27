#include "String.h"
#include <stdlib.h>
#include <string.h>

const char* StringAppend(const char* _string, const char* _toAppend)
{
    char* new_str;
    if ((new_str = malloc(strlen(_string) + strlen(_toAppend) + 1)) != NULL) 
    {
        new_str[0] = '\0';
        strcat_s(new_str, strlen(_string) + strlen(_toAppend) + 1, _string);
        strcat_s(new_str, strlen(_string) + strlen(_toAppend) + 1, _toAppend);
        return new_str;
    }
    return NULL;
}
