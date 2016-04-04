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
void inspect_float(float x){
    unsigned int sign;
    long int exponent;
    long long int mantissa;

    unsigned int value = f2u(x);

    sign = value >> 31;
    exponent = value & 0x7f800000;
    exponent >>= 23;
    mantissa = value & 0x007fffff;


    printf("sign = %d\n", sign);
    printf("exponent = %ld\n", exponent);
    printf("mantissa = %llx\n", mantissa);
}

void precision() {
    // value = 
    float value = 1.0f;

    inspect_float(u2f(f2u(1.0)+1));
}

int main()
{ 
    printf ("0.5 (single) = %f\n", one_half_single());
    printf ("0.5 (double) = %lf\n", one_half_double());

    inspect_float(one_half_single());

    //precision();

    return 0;
}
