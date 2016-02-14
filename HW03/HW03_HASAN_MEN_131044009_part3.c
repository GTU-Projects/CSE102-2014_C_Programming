/*######################################################################*/
/*HW03_HASAN_MEN_131044009_part3.c          							*/
/*________________________________										*/
/*Olusturan HASAN MEN - 9 MART 2015										*/
/*													  	   				*/
/*TANIM:																*/
/*_____																	*/
/*	- Alinan pramaterelere gore hava atılan topun zaman gore hareklerini*/
/*	grafiksellestiren program											*/
/*GIRIS:																*/
/*______																*/	
/* NOT:::Programın suanki halinde asagidaki degerler elle girilmistir 	*/
/*	- first_height: topun atildigi yukseklik							*/
/*	- feet_height: her dusmede alacagı adım sayiyisi					*/
/* 	- the_peak_point: en tepede iken basilacak olan karakter			*/
/*	- the_road_point: alinan yollari isaretlemek icin karakter			*/
/*CIKIS:																*/
/*______																*/
/*	- 3farklı topun adim adim dusus grafikleri							*/
/*	- toplam basılan karakter sayisi(return edildi)						*/
/*######################################################################*/

#include <stdio.h>


/*fonksiyon prototipleri */
int draw_ver_diag_of_bb(int first_height, int feet_height, 
						char the_peak_point, char the_road_point);

int draw_diag_step(int height, int feet_height,
				   char the_peak_point, char the_road_point);

int finish_diag(int lenght);

int main()
{
	/* Ana fonksiyonun baslangici */
	draw_ver_diag_of_bb(4,2,'M','/');
	
	draw_ver_diag_of_bb(3,3,'H','*');
	
	draw_ver_diag_of_bb(5,6,'K','=');
	 
	return 0;
	/* Ana fonksiyonun sonu */	
}
/*##########################################################################*/
/*  asıl fonksiyonumuz bunun sayesinde tum grafigi adımlara parcalayıp		*/
/* tum seklimizi elde ederiz ve toplam basılan karakterlerimizide burada 	*/
/* hesaplarız 																*/	
/*##########################################################################*/		
int draw_ver_diag_of_bb(int first_height, int feet_height,
						char the_peak_point, char the_road_point)
{
	int height2,counter=0;
	
	printf("^\n");
	
	/* grafigin adimlarinin azaltilarak tekrardan cagirilmasi */
	/* gelen return degerlerini toplayarak toplam karakter sayimizi buluruz*/
	for(height2=first_height;height2>=1;height2--)
	{
		counter = counter + draw_diag_step(height2,feet_height,
											the_peak_point,the_road_point);
	}
	/* grafigin x eksenini basarız */
	finish_diag(first_height*feet_height);
	return counter;
}


/* asıl fonksiyondan gelen bilgilere göre parca parca grafikleri cizer*/

int draw_diag_step(int height, int feet_height,
					char the_peak_point, char the_road_point)
{

	int line,space,point,peak_space;
	int counter=0;
	
	/* 1.kısım */
	/* first_height kadar satırdan olusur*/
	for(line=1;line<=height;line++)
	{	
		printf("|");
		
		/* grafik baslangicindaki bosluklari basar */
		for(space=1;space<=feet_height*(line-1);space++)
		{
			printf(" ");			
		}
		
		/* feet_height kadar the_road_point basar */
		for(point=1;point<=feet_height;point++)
		{
			printf("%c",the_road_point);
			counter++;		/* basılan her karakter icin sayac artar */
		}
		printf("\n");
	}

	/* the_peak_pointin ekrana basılması */
	printf("|");
	for(peak_space=1;peak_space<=feet_height*height;peak_space++)
	{
		printf(" ");	
	}
	printf("%c\n",the_peak_point);
	counter++;	/* basılan her karakter icin sayac artar */
	
	/* 2.kısım */
	/* alt kisim icin satırları ayarlar*/
	for(line=height;line>=1;line--)
	{
		printf("|");
		/* grafik baslangicindaki bosluklari basar */
		for(space=0;space<(line-1)*feet_height;space++)
		{
			printf(" ");		
		}
		/* feet_height kadar the_road_point basar */
		for(point=1;point<=feet_height;point++)
		{
			printf("%c",the_road_point);	
			counter++;		/* basılan her karakter icin sayac artar */
		}
		printf("\n");
	}
	return counter;
}

/* grafigin alt tarafi icin x eksenini basar */
int finish_diag(int length)
{
	int step;
	printf("L");
	
	/* adım ve karakter sayisinin bir fazlası olacak sekilde '-' basar */
	for(step=1;step<=length+1;step++)
	{
		printf("-");	
	}
	printf(">\n");
	return 1;	/* alt satır basıldığına dair return degeri */
}
/*##################################################################*/
/*				HW03_HASAN_MEN_131044009_part3.c sonu	        	*/
/*##################################################################*/
