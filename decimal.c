#include "decimal.h"
#include <stdio.h>

void decimal_to_bcd(const Decimal *dst, BCD_t *src) {
  for (int i = 95; i >= 0; i--){
    int index_arr = i / 32;
    int index_bit = i % 32;
    chech_and_correct_decimal(src);
    int val_bit = (dst->bits[index_arr] >> index_bit) & 0x1;
    ofset_bcd_left(src);
    src->bits[0] += val_bit;
    print_int_bit(src->bits[0]);
  }
}

void ofset_bcd_left(BCD_t *val) { 
  for (int i = 3; i > 0; i--){
    val->bits[i] = val->bits[i] << 1;
    if (val->bits[i - 1] & 0x80000000) val->bits[i] += 1;
  }
  val->bits[0] = val->bits[0] << 1;
}

void print_int_bit(int n) { for (int i = 31; i >= 0; i--){
    printf("%d", (n >> i) & 0x1);
  }
  printf("\n");
}

void clear_bcd(BCD_t *n) {
    for (int i = 0; i < 4; ++i){
    n->bits[i] = 0;
  }
}

void clear_decimal(Decimal *n) {
    for (int i = 0; i < 4; ++i){
    n->bits[i] = 0;
  }
}


void chech_and_correct_decimal(BCD_t *n) { 
  for (int i = 31; i >= 0; i--){
    int index_arr = i / 8;
    int index_bit = i % 8;
    int tmp = (n->bits[index_arr] >> (index_bit * 4)) & 0xf;
    if(tmp>4) {
      tmp += 3;
      // clear 1/2 bite
      n->bits[index_arr] = (~(0xf << (index_bit * 4))) & n->bits[index_arr];
      //set val tmp
      n->bits[index_arr] = (tmp << (index_bit * 4)) | n->bits[index_arr];
    }
  }
 }