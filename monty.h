#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>

/* The data structures functions goes here */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* The functions goes here */

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);

/*file operations*/
void o_file(char *f_name);
int p_line(char *buffer, int l_number, int format);
void r_file(FILE *);
int l_chars(FILE *);
void f_fun(char *, char *, int, int);

/*Stack operations*/
stack_t *c_node(int n);
void fr_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_stack(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);

void call_func(op_func, char *, char *, int, int);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void Swap_nodes(stack_t **, unsigned int);

/*Math operations with nodes*/
void addi_nodes(stack_t **, unsigned int);
void subs_nodes(stack_t **, unsigned int);
void divi_nodes(stack_t **, unsigned int);
void multi_nodes(stack_t **, unsigned int);
void modul_nodes(stack_t **, unsigned int);

/*String operations*/
void print_char(stack_t **, unsigned int);
void print_string(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

/*Error hanlding*/
void error(int error_c, ...);
void more_errores(int error_c, ...);
void string_error(int error_c, ...);
void rotr(stack_t **, unsigned int);

#endif
