#include <stdlib.h>
#include <stdio.h>

typedef struct{
  unsigned size_type;
  unsigned capacity;
  unsigned size;
  void *data;
} Stack_t;

typedef int bool_t;

Stack_t *init_stack(int size_t) {
  Stack_t *tmp = malloc(sizeof(Stack_t));
  tmp->size_type = size_t;
}

void ctor(Stack_t *s) {
  s->size = 0;
  s->capacity = 10;
  s->data = malloc(sizeof(char) * s->size_type * s->capacity);
}

bool_t is_full(const Stack_t *s) { return s->size >= s->capacity; }
bool_t is_empty(const Stack_t *s) { return s->size == 0; }

void push_stack(Stack_t *s, void *val){
  if(is_full(s)){
    s->capacity *= 2;
    void *tmp = s->data;
    s->data=malloc(sizeof(char) * s->size_type * s->capacity);
  }
  s->size++;
  int l_stack = s->size * s->size_type;
  for (int i = 0; i < s->size_type; ++i) {
    *(char *)(s->data + l_stack + i) = *(char *)(val + i);
  }
}
void pop_stack(Stack_t *s, void *val){
  if(is_empty(s)){
    printf("stack is empty");
  }
  int l_stack = s->size * s->size_type;
  for (int i = 0; i < s->size_type; ++i) {
    *(char *)(val + i)=*(char *)(s->data + l_stack + i);
  }
  s->size--;
}
unsigned get_size(Stack_t *s){}
void destroy_stack(Stack_t *s){}

