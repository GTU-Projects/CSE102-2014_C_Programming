/* HW09_HASAN_MEN_131044009_complex.c */
/* part2 */
#include<math.h>
#include<stdio.h>
#include "HW09_HASAN_MEN_131044009_complex.h"	/* fonksiyon prototipleri*/

/* output argunamina bi karmasik sayi doldurur */
int scan_complex(complex_t *c)
{

    int status;

    status=scanf("%lf%lf",&c->real,&c->imag);
    if(status==2)
        status=1;
    else if(status!=EOF)
        status=0;
    return status;
}

/* a+bi yada a-bi olarak karmasik sayiyi yazdirir.	*/
/*	a<0.005 ise bi , b<0.005 ise a olarak yazar */
void
print_complex(complex_t c) /* input - complex number to display */
{
    double a, b;
    char sign;

    a = c.real;
    b = c.imag;

    printf("(");

    if (fabs(a) < 0.005 && fabs(b) < 0.005) {
    printf("%.2f", 0.0);
    } else if (fabs(b) < .005) {
    printf("%.2f", a);
    } else if (fabs(a) < .005) {
    printf("%.2fi", b);
    } else {
    if (b < 0)
    sign = '-';
    else
    sign = '+';
    printf("%.2f %c %.2fi", a, sign, fabs(b));
    }

    printf(")");
}

/* iki karmasik saiyiy toplar ve complex_t turunde return eder */
complex_t add_complex(complex_t c1,complex_t c2)
{
    complex_t sum;
    sum.real=c1.real+c2.real;
    sum.imag=c1.imag+c2.imag;
    return sum;
}

/* karmasik sayilarin farkini alir ve complex_t olarak return eder */
complex_t subtract_complex(complex_t c1,complex_t c2)
{
    complex_t sub;
    sub.real=c1.real-c2.real;
    sub.imag=c1.imag-c2.imag;
    return sub;
}

/* gonderilen  karmasik sayinin mutlagini alir ve complex_t olarak return eder*/
complex_t abs_complex(complex_t c)
{
    complex_t abs;
    abs.real=sqrt(c.real*c.real+c.imag*c.imag);
    abs.imag=0;
    return abs;
}

/* gonderilen iki karmasik sayiyi carpar ve sonucu return eder */
complex_t multiply_complex(complex_t c1,complex_t c2)
{

    complex_t cmulti;

    cmulti.real= c1.real*c2.real-c1.imag*c2.imag;
    cmulti.imag= c1.real*c2.imag+c1.imag*c2.real;

    return cmulti;
}

/* karmasik sayilari boler ve sonucu return eder */
complex_t divide_complex(complex_t c1,complex_t c2)
{
    complex_t cdivide;

    double fractional = ((c2.imag)*(c2.imag)+(c2.real)*(c2.real));
	
    cdivide.real = ((c1.real)*(c2.real)+(c1.imag)*((c2.imag))) / fractional;
    cdivide.imag =((((-1)*(c1.real)*(c2.imag))+(c1.imag)*(c2.real))/fractional);

    return cdivide;
}
