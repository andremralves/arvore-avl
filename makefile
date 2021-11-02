main: main.c
	gcc -Wextra -g -o main main.c abp.c files.c -I. -lm