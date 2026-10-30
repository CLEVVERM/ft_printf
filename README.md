*This project has been created as part of the 42 curriculum by msotnych.*

# ft_printf

## Description

ft_printf is my own version of the `printf()` function from the C standard
library, written for the 42 curriculum. The goal is to learn how a function can
take a **variable number of arguments** (a variadic function), and to build a
flexible output function that can be reused in future 42 projects.

The project is compiled into a static library, `libftprintf.a`, using the `ar`
command. It follows the 42 Norm, uses no global variables, and every file is
built with `-Wall -Wextra -Werror`. Like the subject asks, it does not copy the
buffer management of the original `printf()`: every character is written
directly with `write`.

The function has the same prototype as the original:

```c
int	ft_printf(const char *format, ...);
```

It prints the format string and returns the number of characters printed.

## Instructions

### Compilation

Run these commands at the root of the repository:

```sh
make          # builds libftprintf.a
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # fclean + all
```

### Usage

Include the header in your code and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, you are %d years old\n", "Max", 42);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o my_program
```

## Supported conversions

A few basics used in the descriptions below:

- A **conversion** is a `%` followed by a letter in the format string, for example `%d`. It tells ft_printf to take the next argument and print it in a certain way.
- **Hexadecimal** (base 16) uses the digits `0-9` and then `a-f` (or `A-F`) for the values 10 to 15. For example 255 is `ff`.
- An **unsigned** number cannot be negative. If you give `-1` to an unsigned conversion, the same bits are read as the biggest possible unsigned number.

| Conversion | Argument type | What it prints | Function |
|---|---|---|---|
| `%c` | `int` | one character | `ft_putchar` |
| `%s` | `char *` | a string, or `(null)` if the pointer is `NULL` | `ft_putstr` |
| `%p` | `void *` | the address in hexadecimal with `0x` in front, or `(nil)` if it is `NULL` | `ft_putpointer` |
| `%d` | `int` | a signed decimal number | `ft_putnbr` |
| `%i` | `int` | the same as `%d` | `ft_putnbr` |
| `%u` | `unsigned int` | an unsigned decimal number | `ft_putnbr_unsigned` |
| `%x` | `unsigned int` | an unsigned number in lowercase hexadecimal | `ft_putnbr_hex` |
| `%X` | `unsigned int` | an unsigned number in uppercase hexadecimal | `ft_putnbr_cap_hex` |
| `%%` | none | a percent sign | `ft_putchar` |

## Algorithm

### Variadic functions

A variadic function is a function with `...` in its prototype. It can be called
with any number of arguments, but the arguments after `...` have no names. To
read them, C gives the tools from `<stdarg.h>`:

- **`va_list`**: a variable that works like a cursor on the next unread argument.
- **`va_start`**: puts the cursor right after the last named parameter (`format`).
- **`va_arg`**: returns the next argument as the given type and moves the cursor forward.
- **`va_end`**: closes the cursor when the work is done.

The function cannot know by itself how many arguments there are or what type
they have. Only the format string tells it. This is why `%d` reads an `int`,
`%s` reads a `char *`, and so on.

### How ft_printf works

The work is split into three levels:

1. **The main loop (`ft_printf`)** goes through the format string one character at a time.
   - A normal character is printed with `write`, and the counter goes up by one.
   - A `%` means the next character is a conversion letter. That letter is sent to `manager`, and the number it returns is added to the counter.
   - At the end, `va_end` is called and the counter is returned.
2. **The dispatcher (`manager`)** receives the conversion letter and a pointer to the `va_list`. It checks the letter, reads the argument with the correct type using `va_arg`, and calls the matching print function.
3. **The print functions** (`ft_putchar`, `ft_putstr`, `ft_putnbr`, ...) print one value and return how many characters they printed.

Example with `ft_printf("a%%b|%c|", 'Z')`:

| Step | Character | What happens | Counter |
|---|---|---|---|
| 1 | `a` | printed directly | 1 |
| 2 | `%` + `%` | `manager` prints `%` | 2 |
| 3 | `b`, `\|` | printed directly | 4 |
| 4 | `%` + `c` | `manager` reads `'Z'` and prints it | 5 |
| 5 | `\|` | printed directly | 6 |

The result on the screen is `a%b|Z|` and the function returns 6, exactly like the original `printf`.

### Why this structure

- **Easy to extend.** Each conversion is one short branch in `manager` and one print function. Adding a new conversion means adding one branch, without touching the main loop.
- **Short functions.** The Norm allows 25 lines per function. Because the main loop only reads the format and `manager` only chooses a function, each part stays small and easy to read.
- **Simple counting.** Every print function returns how many characters it printed, so the total is just the sum of all return values.



## Logic and techniques used

### Recursion

The number functions print digits with recursion. The last digit of a number
is easy to get (`n % base`), but digits must be printed from the first one. So
the function first calls itself with `n / base` (the number without its last
digit), which prints the front digits, and then prints the last digit. The
simple case is a number smaller than the base, which is printed directly.

It is used in:

- **`ft_putnbr`** (base 10, for `%d` and `%i`),
- **`ft_putnbr_unsigned`** (base 10, for `%u`),
- **`ft_putnbr_hex`** and **`ft_putnbr_cap_hex`** (base 16, for `%x`, `%X` and `%p`).

For base 16, the digit is taken from a string of symbols: `"0123456789abcdef"`
(or uppercase). The remainder of the division is the index in this string, so
a remainder of 15 gives `f`.

### Working with the integer limits (`long`)

The smallest `int` is `-2147483648`, but the largest is only `2147483647`, so
`-n` does not fit in an `int` for that value. In **`ft_putnbr`** the number is
first copied into a `long`, which is big enough to make it positive safely.
The minus sign is printed first, and then the positive number is printed.

### Pointers and `unsigned long`

A pointer stores a memory address. On a 64-bit system an address uses 8 bytes,
but an `unsigned int` only has 4, so part of the address would be lost. In
**`ft_putpointer`** the pointer is converted to `unsigned long` (8 bytes)
before it is printed in hexadecimal by `ft_putnbr_hex`.

### Why `%c` reads an `int`

When a `char` is passed through `...`, C automatically turns it into an `int`
(this is called *default argument promotion*). So `manager` reads `%c` with
`va_arg(*args, int)`, not with `char`.

### Special cases

- **`%s` with `NULL`** prints `(null)`, like the original on Linux.
- **`%p` with `NULL`** prints `(nil)`, like the original on Linux.
- **A `%` at the very end** of the format string has no conversion letter after it. This is undefined behavior, so ft_printf simply stops there instead of reading past the end of the string.
- **An unknown conversion** (for example `%k`) is also undefined behavior. ft_printf prints nothing for it and continues.
- **A `NULL` format string** returns `-1` without printing anything.

### Reusing my own functions

- `ft_putpointer` uses `ft_putnbr_hex` to print the address.
- `ft_putnbr` uses `ft_putchar` for the minus sign.

### Files

- `ft_printf.h`: the header with all prototypes.
- `ft_printf.c`: the main loop (`ft_printf`) and the dispatcher (`manager`).
- `ft_printf_char.c`: characters and strings (`ft_putchar`, `ft_putstr`).
- `ft_printf_numb.c`: numbers and pointers (`ft_putnbr`, `ft_putnbr_unsigned`, `ft_putnbr_hex`, `ft_putnbr_cap_hex`, `ft_putpointer`).

## Resources

- [Linux man pages: `man 3 printf` and `man 3 stdarg`](https://linux.die.net/man/)
- [The ft_printf subject](https://projects.intra.42.fr/)
- [Google](https://www.google.com/) search engine such sites as: [Stack Overflow](https://stackoverflow.com/questions), [GeeksforGeeks](https://www.geeksforgeeks.org/), [cppreference.com](https://cppreference.com/), [GitHub](https://github.com)
- [Peer discussions with other 42 students](https://www.42network.org/)

### Use of AI

AI ([Claude](https://claude.com/)) was used:

- **Explanations:** to explain variadic functions.
- **README:** a draft of this file was generated with AI and edited by me.