# get_next_line

**get_next_line** is a project from the 42 school curriculum where the goal is to create a function that reads a line from a file descriptor (such as `stdin` or a file) until a newline or the end of the file is reached.

## Project Overview

The objective is to implement the `get_next_line()` function which reads a line from a file descriptor, one line at a time. The function should manage memory efficiently and handle edge cases such as multiple calls and very large files.

## Functionality

The function `get_next_line` reads from the given file descriptor and returns the next line in the file (or `NULL` if the end of the file is reached).

### Function prototype:
```c
char get_next_line(int fd);
```

## How to Use

1. Clone the repository:
```
git clone https://github.com/your_username/get_next_line.git
```

2. Navigate to the project folder:
   ```bash
   cd get_next_line
   ```
3. Compile the project:
      ```bash
      make
      ```
4. Example of usage:
```
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int fd = open("your_file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```
5. Link the library to your project:
      ```bash
      gcc -L. -lft your_file.c -o your_program
      ```
6. Clean the object files:
      ```bash
      make clean
      ```
7. Clean everything (including the library files):
      ```bash
      make fclean
      ```
8. Rebuild the library:
      ```bash
      make re
