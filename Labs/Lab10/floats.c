/*
 * CSCI 206 Computer Organization & Programming
 * Author: Alan Marchiori
 * Date: 2014-03-01
 * Copyright (c) 2014 Bucknell University
 *
 * Permission is hereby granted, free of charge, to any individual or
 * institution obtaining a copy of this software and associated
 * on files (the "Software"), to use, copy, modify, and
 * distribute without restriction, provided that this copyright and
 * permission notice is maintained, intact, in all copies and supporting
 * documentation.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL BUCKNELL UNIVERSITY BE LIABLE FOR ANY CLAIM, DAMAGES
 * OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/* Luis Felipe Tomazini
 * T 1pm
 * floats.c
 * compile with: make
 */

#include <stdio.h>

/* Forward declaration for our assembly functions
 * so gcc knows the return type (the return type defaults
 * to int so, it would look in the $v0 register w/o this).
 * Knowning the return type is a float/double gcc will
 * look in the $f0 (float) or $f0-$f1 (double) registers.
 */
float one_half_single(void);
double one_half_double(void);
float u2f(unsigned int);
unsigned int f2u(float);
double u2d(unsigned long long);
unsigned long long d2u(double);

void inspect_float(float x){
    unsigned int sign;
    unsigned int exponent;
    unsigned int mantissa;

    unsigned int value = f2u(x);

    sign = value >> 31;
    exponent = value & 0x7f800000;
    exponent >>= 23;
    mantissa = value & 0x007fffff;


    printf("sign = %d\n", sign);
    printf("exponent = 0x%x\n", exponent);
    printf("mantissa = 0x%x\n", mantissa);
}

void inspect_double(double x){
    unsigned long long sign;
    unsigned long long exponent;
    unsigned long long mantissa;

    unsigned long long value = d2u(x);

    sign = value >> 63;
    exponent = value & 0x7ff0000000000000;
    exponent >>= 52;
    mantissa = value & 0x000fffffffffffff;

    printf("sign = %lld\n", sign);
    printf("exponent = 0x%llx\n", exponent);
    printf("mantissa = 0x%llx\n", mantissa);
}

void precision() {
/*
 * The next number after 1.0 is 1.0000001192092895507812500000
 * By analyzing the outputs it is noticeable that the difference between
 * consecutive values is the same.  It makes possible to store much smaller
 * values and larger values, without creating extra bits of precision. This
 * is possible by denormalizing and normalizing numbers.
 */
    float value = 1.0f;
    inspect_float(value);

    inspect_float(u2f(f2u(value)+1));

    printf("1.0 + 1 : %1.28f\n", u2f(f2u(value)+1));
    printf("1.0 + 2 : %1.28f\n", u2f(f2u(value)+2));
    printf("1.0 + 3 : %1.28f\n", u2f(f2u(value)+3));
    printf("1.0 + 10 : %1.28f\n", u2f(f2u(value)+10));
}

int is_near(double value, double expected, double epsilon) {
    float difference = ((value - expected) < 0) ? (expected - value) : (value - expected);

    return ((difference < epsilon) ? 1 : 0);
}

void sum() {
/*
 * The precision of the datatype does not allow to perform exact calculations.
 * By incrementing the variabe 1000 times the imprecision propagates.
 * Thus the result is not precise.
 */
    float a = 0.1;
    float sum = 0;
    int i;
    for (i = 0; i < 1000; i++) {
        sum += a;
    }
 
    float epsilon = 0.005;

    printf ("a = %1.28f, sum = %1.28f, sum == 100 ==> %s\n", a, sum, sum == 100 ? "TRUE":"FALSE");
    printf ("a = %1.28f, sum = %1.28f, epsilon = %1.3f, sum is near 100 ==> %s\n", a, sum, epsilon, is_near(sum, 100,epsilon) ? "TRUE":"FALSE");
 
    inspect_float(a);
    inspect_float(sum);
    inspect_float(100-sum);
}

int main() {
    printf("\n---one half test---\n");
    printf ("0.5 (single) = %f\n", one_half_single());
    printf ("0.5 (double) = %lf\n", one_half_double());

    printf("\n---inspect float test---\n");
    inspect_float(one_half_single());

    printf("\n---inspect double test---\n");
    inspect_double(one_half_double());

    printf("\n---precision test---\n");
    precision();

    printf("\n---sum test---\n");
    sum();

    return 0;
}
