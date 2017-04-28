#include <stdio.h>

int main() {

    float arg1, arg2, add, sub, mul, div ;

    printf( "Enter two numbers : " );
    scanf( "%f%f", &arg1, &arg2 );

    /* Perform floating point Addition, Subtraction, Multiplication & Division */
    __asm__ ( "fld %1;"
              "fld %2;"
              "fadd;"
              "fstp %0;" : "=g" (add) : "g" (arg1), "g" (arg2) ) ;

    __asm__ ( "fld %2;"
              "fld %1;"
              "fsub;"
              "fstp %0;" : "=g" (sub) : "g" (arg1), "g" (arg2) ) ;

    __asm__ ( "fld %1;"
              "fld %2;"
              "fmul;"
              "fstp %0;" : "=g" (mul) : "g" (arg1), "g" (arg2) ) ;

    __asm__ ( "fld %2;"
              "fld %1;"
              "fdiv;"
              "fstp %0;" : "=g" (div) : "g" (arg1), "g" (arg2) ) ;

    printf( "%f + %f = %f\n", arg1, arg2, add );
    printf( "%f - %f = %f\n", arg1, arg2, sub );
    printf( "%f * %f = %f\n", arg1, arg2, mul );
    printf( "%f / %f = %f\n", arg1, arg2, div );

    return 0 ;
}