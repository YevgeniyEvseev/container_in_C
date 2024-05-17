#ifndef DECIMAL_H
#define DECIMAL_H

/*1000 0000
0001 | 000 0000
0010 | 00 0000
0100 | 0 0000
1000 | 0000
+0011
1011 | 0000
0001 0110 | 000
+0011
0001 1001
0011 0010 | 00
0110 0100 | 0
1001 0100 |0
*/

typedef struct{
  int bits[4];
}Decimal;

typedef struct{
  int bits[4];
} BCD_t;

void ofset_bcd_left(BCD_t *val);
void print_int_bit(int n);
void decimal_to_bcd(const Decimal *dst, BCD_t *src);
void clear_bcd(BCD_t *n);
void clear_decimal(Decimal *n);
void chech_and_correct_decimal(BCD_t *n);

#endif