/*############################################################################*/
/*                     Hw01 Ahmet Orhan Ocak 121044035 Part 1                 */
/*                           Olusturulma tarihi 22.02.15                      */
/*____________________________________________________________________________*/
/*                                   Tanimlama:                               */
/*   f(x) ve g(x) fonksiyonlarini kullanarak fog(x) ve gof(x)'i hesaplar.     */
/*                                   yazdirir.                                */
/*____________________________________________________________________________*/
/*                                    Inputs:                                 */
/*            Input olarak x degerini Variables.txt dosyasindan alir.         */
/*____________________________________________________________________________*/
/*                                    Outputs:                                */
/*                     Alinan x degeri icin fog(x) ve gof(x)'in               */
/*                  sonuclarinir ekrana ve Result1.txt'ye basilir.            */
/*############################################################################*/


/*Stdio.h library'si printf scanf fonksiyonlarini kullanabilmek icin cagilir*/
/*Math.h library'si pow, sin ve log fonksiyonlarini kullanabilmek icin cagrilir*/

#include<stdio.h>
#include<math.h>
#define Y 8.0           /*Y degeri constant macro olarak atanir */

double fx ( double x ); /*fonksiyonlarin protoripleri yazilir   */
double gx ( double x ); /* x double olarak atanir               */
                        /* ancak kullanicidan int olarak alinir */   

int main (void)         /*  ana fonksiyonumuz */
{

  double resultofFog;   /* Gof ve fog double olarak atanir      */
  double resultofGof;

    FILE *iptr,*optr;   /*input ve output pointer tanimlanir.   */

    int x;              /* x degeri intager olarak tanimlanir   */

	/*input'lari okumak icin Variables.txt acilir*/
    iptr=fopen("Variables.txt","r"); 
    /* output'lari yazmak icin Results1.txt acilir */
	optr=fopen("Results1.txt","w");  

    fscanf(iptr, "%d", &x);  /*x degeri okunur*/
    
	/*ustte prototiplerini en altta ise kendisini tanimladigimiz fonksiyonlar cagrilir*/
	/*ve fogx ve gofx'i bulmak icin fx ve gx olarak tanimladigimiz fonksiyonlarin icine */
	/*sirayla parametre olarak gx ve fx'i yazariz boylece fog ve gof x hesaplanmis olur */
    resultofFog= fx (gx((double) x)); 
    resultofGof= gx (fx((double) x));
  
	/* output'lar ekrana ve file'a yazilir */    
	fprintf(optr,"%f\n%f"  , resultofFog, resultofGof );
    printf("The result of fog(x)=%f\nThe result of gof(x)=%f\n", resultofFog, resultofGof);

	/* input ve output dosyalari kapanir */
    fclose(iptr);
    fclose(optr);

return 0; /* ana fonksiyon basarili sekilde sonlandirilir */
}



/* f(x) fonksiyonu tanimlanir */
double fx ( double x ) 
{
    double result;
    
    result = sin( pow(((x+Y)/x)+( pow(log(( pow(3, x))/(2*x+1)), 0.5)), 2.5));

    return result;
}

/* g(x) fonksiyonu tanimlanir */
double gx ( double x )
{
    double result;
    
    result = x+(1/(x+(Y/(2*x))));

    return result;
}


/*############################################################################*/
/*       Odev Hw01'in sonu  HW01_AhmetOrhan_Ocak_121044035_part1.c            */
/*############################################################################*/

