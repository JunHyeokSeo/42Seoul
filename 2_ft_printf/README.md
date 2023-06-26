# ft_printf

### :bulb: Evaluation Log
2. 23/04/13
    - **100 score** _(mandatory 100 + bonus 0)_
***

### :bulb: Objective
- to recode __printf__ fuction in C in the well-structured and extensible way

- to learn how to use `variadic arguments`
***

### :bulb: Codes
0. Preview to understand printf's behavior
    - [***%c***](./examples/%25c), [***%s***](./examples/%25s), [***%p***](./examples/%25p), [***%d***](./examples/%25d), [***%u***](./examples/%25u), [***%x***](./examples/%25x), [***%%***](./examples/%25%25)
1. Mandatory Part
    - ***conversion***: c, s, p, d, i u, x, X, %
    - ***flag***: -, 0, ., *
    - [***Makefile***](./ft_printf/Makefile), [***ft_printf.c***](./ft_printf/ft_printf.c), [***ft_printf.h***](./ft_printf/ft_printf.h)
    - [***parse_all***](./ft_printf/parse_all.c), [***manage_box.c***](./ft_printf/manage_box.c), [***manage_int_sign.c***](./ft_printf/manage_int_sign.c)
    - [***print%c***](./ft_printf/print_1_char.c), [***print%s***](./ft_printf/print_2_string.c), [***print%d%i***](./ft_printf/print_3_int.c), [***print%u***](./ft_printf/print_4_unsigned_int.c), [***print%x%X***](./ft_printf/print_5_hexa.c), [***print%p***](./ft_printf/print_6_pointer.c), [***print%%***](./ft_printf/print_7_percent.c)
---
