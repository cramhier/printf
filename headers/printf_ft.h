#ifndef PRINTF_H
# define PRINTF_H

#include "../lib_ft/libft.h"
#include <stdarg.h>  

//Format Manager
int	formatManager(char format, va_list *arguments);
//Output Functions
int outputChar(char c);
int	outputString(char *string);
int	outputPointer(void *pointer);
int	transformToHexadecimal(unsigned long long number);

#endif