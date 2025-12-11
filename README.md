*This project has been created as part of the 42 curriculum by halakhal.*

# ft_printf

## Description

This is my implementation of printf. Basically I had to recreate the printf function from scratch without using the actual printf.

The goal is to learn how variadic functions work (functions that take different numbers of arguments), how to parse a format string, and how to print different types of data using only the write() function.

### What it does

My ft_printf reads a string with special format specifiers (like %d, %s, etc.) and replaces them with the actual values you pass to it, just like the real printf does.

I had to implement these conversions:

- `%c` - prints a character
- `%s` - prints a string
- `%p` - prints a pointer address in hex (with 0x in front)
- `%d` and `%i` - prints signed integers
- `%u` - prints unsigned integers
- `%x` - prints numbers in lowercase hexadecimal
- `%X` - prints numbers in uppercase hexadecimal
- `%%` - prints a percent sign

## Instructions

### How to compile

Just run this in the terminal:

```bash
make
```

This creates a library file called `libftprintf.a`

Other make commands:
- `make clean` - removes the .o files
- `make fclean` - removes .o files and the library
- `make re` - rebuilds everything from scratch

The code compiles with `-Wall -Werror -Wextra` flags.

### How to use it in your code

Include the header in your file:
```c
#include "ft_printf.h"
```

Compile your program:
```bash
cc main.c libftprintf.a -o my_program
```

Run it:
```bash
./my_program
```

### Example

```c
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
```

You can test it with the printfTester folder or make your own tests.

## Resources

These are the resources I used while working on this project:

- `man printf` - to understand how printf works
- `man write` - for the write system call
- `man stdarg` - to learn about variadic functions (va_start, va_arg, va_end)
- The 42 ft_printf subject PDF
- Some tutorials I found online about:
  - How to convert integers to strings
  - How hexadecimal works
  - How to print pointers
- Stack Overflow when I got stuck on specific problems
- Looked at other students' repos on GitHub to see different approaches (didn't copy code, just to understand the logic)

### AI Usage

I used ChatGPT and Gemini to help me with:
- Understanding how va_list and variadic functions work (it was confusing at first)
- Figuring out the best way to convert numbers to hex
- Writing this README file
- When I had bugs and couldn't figure them out, I asked for hints

Important: I wrote all the code myself and made sure I understood everything. I didn't just copy-paste AI generated code. I used AI more like a tutor to explain concepts when I was stuck.

## Algorithm and Data Structure Explanation

### How my ft_printf works

The main function basically does this:

1. It goes through the format string character by character
2. If it's a normal character, it just prints it with write()
3. If it finds a '%', it checks the next character to see what type it is (%d, %s, etc.)
4. Then it uses va_arg to get the right argument and calls the correct helper function
5. It keeps count of how many characters it printed and returns that number

### File Organization

I split my code into different files to keep things organized:

- `ft_words.c` - handles characters (%c) and strings (%s)
- `ft_digits.c` - handles regular numbers (%d, %i, %u)
- `ft_hexadecimal.c` - handles hex numbers (%x, %X)
- `ft_pointer.c` - handles printing pointer addresses (%p)
- `ft_printf.c` - the main function that ties everything together

I did it this way because:
- It's easier to debug when each type has its own file
- The functions stay small and follow the Norm
- If I need to add new conversions later, I can just add a new file

### How I convert numbers

**For regular numbers (decimal):**
I use recursion to get each digit. Basically:
- I divide the number by 10 to get the next digit
- Use modulo (%) to get the current digit
- Convert the digit to a character by adding '0'
- Print it with write()
- Handle negative numbers by printing a '-' first

**For hexadecimal:**
Same idea but divide by 16 instead of 10:
- Get each digit with modulo 16
- If the digit is 0-9, print that number
- If it's 10-15, print a-f (or A-F for uppercase)
- Keep dividing by 16 until we're done

**For pointers:**
- Print "0x" first
- Then convert the pointer address to hex (same as above)
- I had to cast it to unsigned long long to handle 64-bit addresses

### Why I chose this approach

I thought about using a buffer to store everything first and then print it all at once, but that seemed more complicated and I'd have to manage memory. 

Instead I just print each character as I go with write(). It's simpler and there's no risk of buffer overflow or memory leaks.

I use recursion because it's pretty clean and easy to understand. Yeah it uses a bit of stack space but for normal numbers it's fine. I tried to keep everything simple so I could actually understand what my code is doing.

The main data structure I use is just va_list from stdarg.h which handles the variadic arguments for me. I didn't need anything fancy like arrays or structs for this project.
