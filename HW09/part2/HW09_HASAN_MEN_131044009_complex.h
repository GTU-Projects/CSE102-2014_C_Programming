/* HW09_HASAN_MEN_131044009_complex.h  */
/* part2 */

typedef struct{
    double real,imag;
}complex_t;

int
scan_complex(complex_t *c); /* output - address of complex
variable to fill */

/*
* Complex output function displays value as a + bi or a - bi.
* Displays only a if imaginary part is 0.
* Displays only bi if real part is 0.
*/
void
print_complex(complex_t c); /* input - complex number to
display */

/*
* Returns sum of complex values c1 and c2
*/
complex_t
add_complex(complex_t c1, complex_t c2); /* input */

/*
* Returns difference c1 - c2
*/
complex_t
subtract_complex(complex_t c1, complex_t c2); /* input */

/*
* Returns product of complex values c1 and c2
*/
complex_t
multiply_complex(complex_t c1, complex_t c2); /* input */

/*
* Returns quotient of complex values (c1 / c2)
*/
complex_t
divide_complex(complex_t c1, complex_t c2); /* input */

/*
* Returns absolute value of complex number c
*/
complex_t
abs_complex(complex_t c); /* input */
