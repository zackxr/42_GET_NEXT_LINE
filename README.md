<h1 align="center">
	📖 get_next_line
</h1>

<p align="center">
	<b><i>Reading a line from a file descriptor made simple</i></b><br>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/score-112%20%2F%20100-brightgreen?style=for-the-badge" />
  <img src="https://img.shields.io/github/repo-size/zackxr/42_GET_NEXT_LINE?style=for-the-badge&logo=github" />
  <img src="https://img.shields.io/github/languages/count/zackxr/42_GET_NEXT_LINE?style=for-the-badge" />
  <img src="https://img.shields.io/github/languages/top/zackxr/42_GET_NEXT_LINE?style=for-the-badge" />
  <img src="https://img.shields.io/github/last-commit/zackxr/42_GET_NEXT_LINE?style=for-the-badge" />
</p>

<h3 align="center">
	<a href="#-about-the-project">About</a>
	<span> · </span>
	<a href="#-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 💡 About the Project

> _The goal of this project is to create a function that reads a line from a file descriptor._

This project will help you understand how files are opened, read, and closed in an operating system, and how they are interpreted by a programming language for further analysis. This is a fundamental skill for any programmer, as file manipulation is a common task in software development.

The function you will write, `get_next_line`, reads one line at a time from a text file, making it useful for processing large files without loading the entire file into memory.

For more detailed information, refer to the [**project subject**](https://github.com/zackxr/get_next_line/blob/main/subject.pdf).

---

## 🛠️ Usage

### Requirements

The function is written in C and requires the **`gcc` compiler** and standard **C libraries** to compile and run.

### Instructions 📕
**1. Including the function in your code**

To use the get_next_line function in your project, include its header file:

```C
#include "get_next_line.h"
```
**2. Compiling your code**

When compiling your code, include the source files and specify the buffer size using the -D flag. For example:

```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c your_main_file.c -o your_program_name
```
Replace 42 with your desired buffer size.

Replace your_main_file.c with the name of your main file.

Replace your_program_name with the desired output name for your executable.

**3. Example of a main file**

Here’s an example of how you might use get_next_line in your main file:

```C
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error opening file\n");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
### 📋 Testing
To test the get_next_line function, follow these steps:

Edit the get_next_line.c file:

Uncomment the main function and the necessary headers inside the file.

Modify the test.txt file to include the text you want to test.

Compile and run:
Use the following command to compile and run the program (replace xx with your desired buffer size):

```shell
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c -o gnl_test && ./gnl_test
```
### Third-party tester:
For more comprehensive testing, you can use the following third-party tester:

Tripouille/gnlTester

### 🚀 Key Features
Reads one line at a time from a file descriptor.

Supports multiple file descriptors.

Efficient memory management.

Configurable buffer size.

### 📜 Notes
Ensure that the BUFFER_SIZE is defined during compilation. If not, the function will use a default value.

The function returns the line read from the file descriptor, or NULL if there is nothing else to read or if an error occurs.

Feel free to contribute or report issues! Happy coding! 🎉

This version integrates the Usage section directly into the code blocks, making it easier to follow and implement. Let me know if you need further adjustments!
