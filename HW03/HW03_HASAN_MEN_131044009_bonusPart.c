/*######################################################################*/
/*HW03_HASAN_MEN_131044009_bonusPart.c         							*/
/*________________________________										*/
/*Olusturan HASAN MEN - 9 MART 2015										*/
/*													  	   				*/
/*TANIM:																*/
/*_____																	*/
/*	- Alinan pramaterelere gore hava atılan topun zaman gore hareklerini*/
/*	dikey olarak grafiksellestiren program								*/
/*GIRIS:																*/
/*______																*/	
/* NOT:::Programın suanki halinde asagidaki degerler elle girilmistir 	*/
/*	- first_height: topun atildigi yukseklik							*/
/*	- feet_height: her dusmede alacagı adım sayiyisi					*/
/* 	- the_peak_point: en tepede iken basilacak olan karakter			*/
/*	- the_road_point: alinan yollari isaretlemek icin karakter			*/
/*CIKIS:																*/
/*______																*/
/*	- dikey olarak topun hareket grafigi								*/
/*	- toplam basılan karakter sayisi(return edildi)						*/
/*######################################################################*/

#include <stdio.h>

/* fonksiyon prototipi */
int draw_hor_diag_of_bb(int first_height,int feet_height,
									char the_peak_point,char the_road_point);
int main()
{
	/* ana fonksiyonun baslangıcı */
	int first_height=4;
	int feet_height=3;
	char the_peak_point='H';
	char the_road_point='|';
	/* degiskenlerin sonu */
	
	
	printf("\nCounter %d\n",draw_hor_diag_of_bb(first_height,feet_height,
											the_peak_point,the_road_point));
	return 0;
	/* ana fonksiyonun sonu */
}
/*##################################################################*/
/*  diket atis grafigini cizer										*/
/*GIRIS:															*/
/*-----																*/
/* -first_height : topun ilk yuksekligi								*/
/* -feet_height : topun kademe basina adim sayisi					*/
/* -the_peak_point: zirvedeki karakter								*/
/* -the_road_point : alinan yollardaki karakter*					*/
/*CIKIS:															*/
/*-----																*/
/*	-Toplam basılan karakter sayısı									*/
/*	-hareket grafigi 												*/
/* NOT : GRAFIGI ADIM ADIM DUSUNEREK CIZDIRDIM HER FEET HEIGHTI BIR */
/* GRUP VE O GRUPLARIDA AYRI GRUPLAR HALINDA YAZDIRDIM				*/
/*##################################################################*/
int draw_hor_diag_of_bb(int first_height,int feet_height,
									char the_peak_point,char the_road_point)
{
	int step;	/* adım sayimiz */
	int space_out_left;	/* stepler icin sol bolsuklarimiz */
	int space_out_right;	/* stepler icin sag bosluklarimiz */
	int space_in;	/* inis cikislar arasindaki bosluklar */
	int k,t;
	int line;	
	int counter=0;
	int fspace_peak;	/* zirvedeki karakterden önceki bosluklar */
	
	/* Step step yani her feet height ler birer step olacak */
	for(step=1;step<=first_height;step++)
	{		
		/* zirvedeki karakterler her azalma grafiginde ekrana */
		/*	bosluklar basıldıktan sonra basılır				*/
		for(fspace_peak=0;fspace_peak<=first_height-step;fspace_peak++)
		{
			printf(" ");
		}
		printf("%c",the_peak_point);
		counter++;	/* basilan gecerli karakterler icin sayacimiz artar */
		
		for(line=1;line<=feet_height;line++)
		{
			printf("\n");
			
			/* sol ve sagdaki boslukları bastiktan sonra bosluk sayisi bir
			/* den az olunca diger sekili cizmez ve alt sekillere gider*/
			
			/* t ic bosluk eger 1den kucukse satirdaki grafik sonuna gelir*/
			t=((first_height-(first_height-step))*2-1);
			
			/* basilan bosluklarin kontrolu ve azalarak basılması */
			for(k=(first_height-(first_height-step))*2-1;k>=1;k--)
			{
				if(t>=1)	
				{
					for(space_out_left=1;
						space_out_left<=first_height-step;
						space_out_left++)
					{
						printf(" ");
								
					}

					printf("%c",the_road_point);
					counter++;	/* gecerli karakterler icin sayacimiz artar */
				}
					
				/* ic boslukların basilmasi */
				for(space_in=1;space_in<=t;space_in++)
				{
					printf(" ");
				}
		
		/* eger ic satir 1den kucukse o stepteki grafiklerin sonuna gelir*/
				if(t>=1)	
				{
					printf("%c",the_road_point);
					counter++;	/* ecerli karakterler icin sayacimiz artar */
				
					for(space_out_right=1;
						space_out_right<=first_height-step;
						space_out_right++)
					{
						printf(" ");			
					}
				}
				t-=2;	
			}
		}
	}
	return counter;
}
/*##################################################################*/
/*				HW03_HASAN_MEN_131044009_bonusPart.c sonu	        */
/*##################################################################*/
