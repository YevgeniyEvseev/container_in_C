#include <stdio.h>
#include "decimal.h"
#include "stack.h"

int main() {
  Decimal s;
  clear_decimal(&s);
  s.bits[0] = 1234567890;
  BCD_t n;
  clear_bcd(&n);
  decimal_to_bcd(&s, &n);
  printf("%x", n.bits[1]);  
  printf("%x", n.bits[0]);

  printf("stack\n");
  struct Stack_t *s_int = init_stack(sizeof(int));
  int a = 444;
  push_stack(s_int, &a);
  
  int a2 = 43433;
  push_stack(s_int, &a2);
  int b;
  pop_stack(s_int, (int*)&b);
  printf("%d", b);
}