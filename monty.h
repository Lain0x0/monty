#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

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

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
stack_t *head = NULL;


void o_file(char *file_name);
int p_line(char *buffer, int line_number, int format);
void r_file(FILE *);
int l_chars(FILE *);
void find_fun(char *, char *, int, int);


stack_t *create_node(int n);
void fr_nodes(void);
void print_stack(stack_t **, unsigned int);
void add_stack(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);

void call_fun(op_func, char *, char *, int, int);

void print_top(stack_t **, unsigned int);
void pop_top(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void swap_nodes(stack_t **, unsigned int);


void addi_nodes(stack_t **, unsigned int);
void subs_nodes(stack_t **, unsigned int);
void divi_nodes(stack_t **, unsigned int);
void multi_nodes(stack_t **, unsigned int);
void modul_nodes(stack_t **, unsigned int);

void print_char(stack_t **, unsigned int);
void print_string(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);

void error(int error_c, ...);
void more_errors(int error_c, ...);
void str_err(int error_c, ...);
void rotr(stack_t **, unsigned int);

#endif
