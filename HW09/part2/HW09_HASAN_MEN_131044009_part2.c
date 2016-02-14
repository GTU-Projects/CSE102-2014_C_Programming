/*######################################################################*/
/* HW09_HASAN_MEN_131044009_part2.c										*/
/* HAZIRLAYAN : HASAN MEN - 131044009									*/
/* TARIH: 27.4.15														*/
/*																		*/
/* TANIM:	kullanicidan 2tane karmasik sayi alip bu sayilar ile 
/* islemler yapip, sonuclari ekrana basan program */
/*######################################################################*/
#include <stdio.h>
#include <string.h>
#include "HW09_HASAN_MEN_131044009_complex.h"

int main()
{
    complex_t com1,com2;

    /*Gets two complex numbers*/
    printf("Enter the real and imaginary parts of a complex number\n");
    printf("separated by a space> ");
    scan_complex(&com1);
    printf("Enter a second complex number> ");
    scan_complex(&com2);

    /*Forms and displays the sum */
    printf("\n");
    print_complex(com1);
    printf(" + ");
    print_complex(com2);
    printf(" = ");
    print_complex(add_complex(com1,com2));

    /* Forms and displays the difference */
    printf("\n\n");
    print_complex(com1);
    printf(" - ");
    print_complex(com2);
    printf(" = ");
    print_complex(subtract_complex(com1,com2));

    /* Forms and displays the absolute value of the first number */
    printf("\n\n|");
    print_complex(com1);
    printf("| = ");
    print_complex(abs_complex(com1));


    /* Forms and displays the multiply */
    printf("\n\n");
    print_complex(com1);
    printf(" * ");
    print_complex(com2);
    printf(" = ");
    print_complex(multiply_complex(com1,com2));

    /* Forms and displays the divide_complex */
    printf("\n\n");
    print_complex(com1);
    printf(" / ");
    print_complex(com2);
    printf(" = ");
    print_complex(divide_complex(com1,com2));
    printf("\n\n");

    return 0;
}
/* HW09_HASAN_MEN_131044009_part2.c */
