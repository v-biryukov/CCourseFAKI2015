#include <stdio.h>

float sinx( float degree ) {
    float result, two_right_angles = 180.0f ;
    /* Convert angle from degrees to radians and then calculate sin value */
    __asm__ __volatile__ ( "fld %1;"
                            "fld %2;"
                            "fldpi;"
                            "fmul;"
                            "fdiv;"
                            "fsin;"
                            "fstp %0;" : "=g" (result) : 
        "g"(two_right_angles), "g" (degree)
    ) ;
    return result ;
}

float cosx( float degree ) {
    float result, two_right_angles = 180.0f, radians ;
    /* Convert angle from degrees to radians and then calculate cos value */
    __asm__ __volatile__ ( "fld %1;"
                            "fld %2;"
                            "fldpi;"
                            "fmul;"
                            "fdiv;"
                            "fstp %0;" : "=g" (radians) : 
        "g"(two_right_angles), "g" (degree)
    ) ;
    __asm__ __volatile__ ( "fld %1;"
                            "fcos;"
                            "fstp %0;" : "=g" (result) : "g" (radians)
    ) ;
    return result ;
}

float square_root( float val ) {
    float result ;
    __asm__ __volatile__ ( "fld %1;"
                            "fsqrt;"
                            "fstp %0;" : "=g" (result) : "g" (val)
    ) ;
    return result ;
}

int main() {
    float theta ;
    printf( "Enter theta in degrees : " ) ;
    scanf( "%f", &theta ) ;

    printf( "sinx(%f) = %f\n", theta, sinx( theta ) );
    printf( "cosx(%f) = %f\n", theta, cosx( theta ) );
    printf( "square_root(%f) = %f\n", theta, square_root( theta ) ) ;

    return 0 ;
}