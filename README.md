
*This project has been created as part of the 42 curriculum by <halakhal>*
# ft_printf

## Description

ft_printf is a reimplementation of the C standard function printf. It parses a format string, reads variadic arguments, and prints formatted output to stdout without using the real printf.

Supported conversions (mandatory part):

- %c : character  
- %s : string  
- %p : pointer address in hexadecimal  
- %d / %i : signed decimal integer  
- %u : unsigned decimal integer  
- %x : unsigned hexadecimal (lowercase)  
- %X : unsigned hexadecimal (uppercase)  
- %% : literal %  

The goal is to understand variadic functions, formatting logic, and low-level output with write().

## Instructions

### Compile

make

This creates the static library:

libftprintf.a

Useful Make targets:

- `make clean` - removes the .o files
- `make fclean` - removes .o files and the library
- `make re` - rebuilds everything from scratch

Use in another program

Include the header:

#include "ft_printf.h"

Compile and link:

cc main.c libftprintf.a -I. -o test_printf

Then run:

./test_printf

Resources

I used the following references while working on this project:
	•	man  printf
	•	man  write
	•	Documentation for stdarg.h (variadic functions)
	•	The official 42 ft_printf subject PDF
	•	General C tutorials for:
	•	integer to string conversion
	•	hexadecimal formatting
	•	pointer printing

Use of AI: I used AI tools (such as ChatGPT and gemini) only to clarify concepts and help with the wording of this README.
All project code was written, understood, and tested by me.

Algorithm and Data Structures

ft_printf(const char *format, ...) works like this:
	1.	Iterate over the format string character by character.
	2.	If the character is not %, write it directly with write(1, &c, 1) and increment the printed length.
	3.	If the character is %, read the next character as the conversion specifier (c, s, p, d, i, u, x, X, %).
	4.	Use stdarg.h (va_start, va_arg, va_end) to fetch the matching argument.
	5.	Call a small set of helper functions, for example:
	•	ft_print_char
	•	ft_print_str
	•	ft_print_ptr
	•	ft_print_int / ft_print_uint
	•	ft_print_hex

Each helper converts the value to characters using repeated division by the base (10 for decimal, 16 for hex) and prints using write().
No complex data structures are needed: the main “structure” is the format string and the va_list. This keeps the implementation simple, norm-friendly, and easy to extend.

#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "World");
    ft_printf("Character: %c\n", 'A');
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    
    return (0);
}