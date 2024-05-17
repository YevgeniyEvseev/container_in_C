#ifndef STACK_H
#define STACK_H

struct Stack_t;

struct Stack_t *init_stack(int);
void ctor(struct Stack_t *s);
void push_stack(struct Stack_t *s, void *val);
void pop_stack(struct Stack_t *s, void *val);
unsigned get_size(struct Stack_t *s);
void destroy_stack(struct Stack_t *s);

#endif