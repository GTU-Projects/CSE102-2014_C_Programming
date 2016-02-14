/*######################################################################*/
/*HW03_HASAN_MEN_131044009_part2.c          							*/
/*________________________________										*/
/*oluSturan Hasan MEN  Mart 9, 2015										*/
/*													  	   				*/
/*TANIM																	*/
/*_____																	*/
/*		Bu program 10<x<40 arasinda bir sayi uretip o yukseklikten 		*/
/* birakilan br topun random olan ratio ile ratio*x  kadar her 			*/
/* seferinde yeni yuksekliğe cikan  ve yukseklik 1feet olana kadar devam*/
/* eden  ve toplam yukseklik ve kac adımda bitise geldigini hesaplar 	*/
/* ve bu degerleri dosya ve ekrana basar								*/
/*GIRISLER																*/
/*________																*/
/*	- Girilen deger yok , random uretilir								*/	
/*CIKISLAR																*/
/*________																*/
/*	-count = 1feetin altina kac adımda duser							*/
/*	-height = yeni yukseklik(her ziplamada degisir)						*/
/*	-distance = toplam alinan dikey yol									*/
/*	-ratio = yüksekligin degisim miktari (random dur)					*/
/*######################################################################*/

#include <stdio.h>
#include <stdlib.h>

/* defines */
#define LIMITREBOUNCE 1	/* topun min. yüksekliği */
#define UPDOWN 2		/* inis ve cikisi belirtir */

#define OUT_FILE "Result_Table.txt"	/* output dosyamız */


/* fonksiyon prototipleri */
double calculate_the_new_height(double first_height,double ratio);
double calculate_the_vertical_distance(double height);
int count_the_number(int counter);
void report(int count,double height,double distance,FILE *out);

int main()
{
	/* Main başlangıcı */
	int first_height;
	double ratio;
	double height;
	double distance;
	int count=1;

	/* outF dosyasinin acilmasi */
	FILE *outF = fopen(OUT_FILE,"w");

	/* her seferinde farkli random sayilar uretmeye yardımcı olur */
	srand(time(NULL));

	first_height = 10+rand()%31;	/* 10<= first_height<= 40 */
	ratio = (40+rand()%50)/100.0;	/* 0,4<=ratio<=0,8 */
	
	/*ilk degerlerin kontrol icin ekrana basilmasi */
	printf("First - Height = %d \t Ratio =  %.2f\n",first_height,ratio);
	
	/* degiskenlerin karismamasi icin yuksekligi heighte attım */
	height = (double)first_height;
	distance = height;
	printf("No\tThe Rebounching Height\t\tThe Total vertical Distance\n");

	/* yukseklik>1 sarti saglanana kadar dongu ile yeni degerler hesaplanır*/
	while(LIMITREBOUNCE<height)
	{
	report(count,height,distance,outF);
	height=calculate_the_new_height(height,ratio);
	count = (count_the_number(count));
	distance += calculate_the_vertical_distance(height);
	}	

	return 0;
}
/* ratio oranında yeni yuksekligi hesaplayıp degeri return eden fonksiyon */
double calculate_the_new_height(double first_height,double ratio)
{
	return first_height*ratio;
}


/* toplam dikey mesafeyi hesaplamamızı sağlar */
double calculate_the_vertical_distance(double height)
{
	return UPDOWN*height;
}

/* kac adım sonra limite ulastigimiz bilgisini return eder */
int count_the_number(int counter)
{
	counter++;
	return counter;
}

/* sonuclarin ekrana ve dosyaya basılması */

void report(int count,double height,double distance, FILE *out)
{
		printf("%d\t%.3f\t\t\t\t%.3f\n",count,height,distance);	

		fprintf(out,"%d\t%.3f\t\t%.3f\n",count,height,distance);
}

/*##################################################################*/
/*				HW03_HASAN_MEN_131044009_part2.c  sonu		       	*/
/*##################################################################*/
