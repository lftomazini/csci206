#ifndef _bits_H_
#define _bits_H_

#include <stdint.h>

/* get_byte - Extract byte n from word x
 * example: get_byte(0x12345678, 1) = 0x56
 * legal ops: ~ ! & ^ | + << >>
 */
int get_byte(int x, int n);

/* negate - returns the negation of a two's complement 
 * integer by manipulating the data at the bit-level.
 * example: negate(1) = -1
 * legal ops: ~ & ^ | + << >>
 */
int negate(int x);

/* is_positive - returns 1 if the number is > 0
 * example: is_positive(-1) = 0.
 * legal ops: ! ~ & ^ | + << >>
 */
int is_positive(int x);

/* tmax - return the maximum (largest) two's complement integer
 * using up to n bits
 * legal ops: ~ ! & ^ | + - >> << 
 */
int tmax(int n);

/* tmin - return the minimum (smallest) two's complement integer
 * using up to n bits
 * legal ops: ~ ! & ^ | + - >> << 
 */
int tmin(int n);

/*
 * test script for tmax and tmin
 */
void test_tmax_tmin(void);

#endif /* _bits_H_ */