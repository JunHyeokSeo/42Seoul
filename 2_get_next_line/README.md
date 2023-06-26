# get_next_line

### :bulb: Evaluation Log

1. 23/04/26 : OK
   - **125 score** (mandatory 100 + bonus 25)

---

### :bulb: Objective

- Process와 File Descriptor에 대해 이해하여, 주어진 파일을 한 줄씩 읽어서 출력하는 프로그램을 작성하는 과제입니다.
---

### :bulb: Codes

1. Mandatory Part: [**_gnl.c_**](./gnl_bonus_loop/get_next_line.c), [**_gnl_utils.c_**](./gnl_bonus_loop/get_next_line_utils.c), [**_gnl.h_**](./gnl_bonus_loop/get_next_line.h)

   - **_function description_** : returns a line read from a file descriptor, without the newline
   - **_compile option_** : gcc -Wall -Wextra -Werror `-D BUFFER_SIZE=32` get_next_line.c get_next_line_utils.c
   - since libft is not allowed, up to 5 functions can be added in gnl_utils.c

2. Bonus Part: [**_gnl_bonus.c_**](./gnl_bonus_loop/get_next_line_bonus.c), [**_gnl_utils_bonus.c_**](./gnl_bonus_loop/get_next_line_utils_bonus.c), [**_gnl_bonus.h_**](./gnl_bonus_loop/get_next_line_bonus.h)
   - **_requirement 1_**: to succeed get_next_line with a single static variable.
   - **_requirement 2_**: to be able to manage multiple file descriptors with get_next_line without losing the reading thread on each of the descriptors.

---