/*##############################################################*/
/*HW05_HASAN_MEN_131044009_part1.c								*/
/*________________________________								*/
/* Olusturan : HASAN MEN  23-Mart-2015							*/
/*																*/
/*Tanım															*/
/*___________													*/
/*Ilk konumlari ve hizlarina gore  araclarin anlık hareket		*/
/*durumunu bulan bir program									*/
/*Girdiler:														*/
/*	-name1,name2: arac isimleri									*/
/*  -speed1,speed2 : baslangic hizlari							*/
/*	-weight1,weight2 : arac agirliklari							*/
/*Ciktilar:														*/
/*  -Carpisma baslangıcından sonuna hareketler					*/
/*##############################################################*/


#include <stdio.h>

#define ROADLENGTH 50	/* max genisligi */
#define MINROAD	0		/* minimum yol araligi  0<= yol<= 50 */

/* carpma durumlari icin yeni turler */
typedef enum
	{PLAY,CRASH,END}
	object_state;

/* foksiyon prototipleri */
void make_move(	char *object1,double *position1,double *speed1,int weight1,
				char *object2,double *position2,double *speed2, int weight2,
				object_state *game_state);

double car_crash_time(	double position1, double position2,
						double speed1,double speed2);

void print_game_state(	char object1,double position1,
						char object2,double position2, object_state game_state);

int main()
{
	/* ana fonksiyon baslangici */
	char name1,name2;	/* arac isimleri*/
	double speed1,speed2;	/* baslangic hizlari */
	int weight1,weight2;	/* arac agirliklari */
	double position1=1;		/* ilk pozisyonlar-1.arac en basta	*/
	double position2=50;	/* 	en sonda*/
	/* degiskenlerin sonu */
	

	/* simulasyon aktiflesti */
	object_state state=PLAY;

	/* kullanıcıdan degerleri alinmasi */
	printf("Enter First Car Name / Speed / Weight (left to right) ");
	scanf("%c%lf%d",&name1,&speed1,&weight1);
	printf("Enter Second Car Name / Speed / Weight (left to right) ");
	scanf(" %c%lf%d",&name2,&speed2,&weight2);

	printf("%c %.2f %d\n",name1,speed1,weight1);
	printf("%c %.2f %d\n",name2,speed2,weight2);
	

	/* haraket fonksiyonunun cagirilmasi */
	make_move(	&name1,&position1,&speed1,weight1,
				&name2,&position2,&speed2,weight2,&state);

	return 0;
	/* ana fonksiyon sonu */
}

/*##################################################################*/
/*	Araclarin ilk bilgilerini aralarak kac adimda carpisacaklarini	*/
/*	zamana bagli hareketlerini ve carpma sonrasi ortak kutlenin 	*/
/*	hareketini cizen fonksiyonumuz									*/
/*																	*/
/*	Girdi:															*/
/*	------	*object(x)	: arac isimleri	- pointer olarak			*/
/*	------	*position(x) : araclarin pozistonlari - pointer olarak	*/
/*	------	*speed(x)	: baslangic hizlari - pointer				*/
/*	------	weight	: ortak kutlenin hizini bulmak icin agirliklar	*/
/*																	*/
/*	Cikti:															*/
/*	------araclarin carpisma oncesi ve sonrasi adim adim hareketleri*/
/*##################################################################*/

void make_move(	char *object1,double *position1,double *speed1,int weight1,
				char *object2,double *position2,double *speed2, int weight2, 
				object_state *game_state)
{
	/* make_move fonksiyonu baslangici */
	
	int i,time; /* i: sayac  , time : ne zaman carpisacaklari */
	double newspeed;	/* ortak kutlenin yeni hizi */
	/* degiskenlerin sonu */
	
	time=car_crash_time(*position1,*position2,*speed1,*speed2);

	/* simulasyon crash olana kadar araclarin birbirlerin yaklasmalari */
	for(i=0;i<=time;i++)
	{
		/* pritn_game_State fonk ile adim adim yazdirma */
		print_game_state(*object1,*position1,*object2,*position2,*game_state);

		/* aradaki mesafe 1 olana kadar hızlar degisir.1olunca carpisma	*/
		/* durumuna gecilir.											*/ 		
		if(*position2-*position1!=1)	
		{
		*position1 += *speed1;	/* pozisyonlar hizlara gore degisir */
		*position2 += *speed2;
		}

	}

	/* yeni hizin bulunmasi - temel fizik kuralina gore  	*/
	/* Kural = (m1v1 + m2v2)/(m1+m2)						*/
	newspeed = ((*speed1)*weight1+(*speed2)*weight2)/(double)(weight1+weight2);


	/* yol sinirlarina yaklasana kadar ortak hareeket */
    do{
		*game_state=CRASH;		/* carpisma durumu	*/
		*object1='X';	/* yeni cismimiz (ortak kutle */
		
		/* chash durumuna gore print_game_cagirilmasi*/
		print_game_state(*object1,*position1,*object2,*position2,*game_state);
		*position1 += newspeed;
    }while(*position1>=MINROAD && *position1<ROADLENGTH);


	/* eger sinirlar asilirsa 0 ve 50ye geri donulup bitis aninin belirtilmesi*/
	if(*position1<=MINROAD)
		*position1=MINROAD;
	else if(*position1>=ROADLENGTH)
		*position1=ROADLENGTH;

		/* oyun durumu 'end' ve son adim icin print_game_state cagirilir */
        *game_state=END;
        *object1='X';
		print_game_state(*object1,*position1,*object2,*position2,*game_state);
		
		/* make_move fonksitonu bitisi */
}


/*##########################################################################*/
/* araclarin pozisyon ve hizlarina gore kacinci adimda carpisacaklarini		*/
/* bulup make_move fonksiyonuna return eder 								*/
/*	Girdi:																	*/
/*	----- position1,position2 : araclarin ilk yerleri						*/
/*	----- speed1,speed2 : araclarin ilk hizlari								*/			
/*	Cıktı																	*/
/*	----- carpisma sureleri (return edildi)									*/
/*##########################################################################*/
double car_crash_time(	double position1, double position2,
						double speed1,double speed2)
{
		return (position2-position1)/(speed1-speed2);
}


/*##########################################################################*/
/* make move den gelen bilgilere gore adim adim hareketlerin ekrana 		*/
/*basilmasi	, oyun durumu en buyuk etkenimizdir 							*/
/*	Girdi:																	*/
/*	----- object1,object2: arac isimleri 									*/
/*	----- NOT: end ve crash icin object1 'X' i kullanir.Object2 iptaldir.	*/
/*	----- position1, position2 : araclarin yerleri							*/
/*	----- NOT: ortak kutle yeri position1 de yer alir						*/
/*	----- game_State : simulasyon durmumu									*/			
/*	Cıktı																	*/
/*	----- adim adim hareketler												*/
/*##########################################################################*/

void print_game_state(	char object1,double position1,
						char object2,double position2, object_state game_state)
{
	/* print_game_state fonksiyonu baslangici */
	int outl,outr,in;	/* oultleft,outright : sol,sag  bosluklar*/
	int inspace=position2-position1-1;	/* aradaki bosluklar */
	/* degiskenlerin sonu */
	
	/* simulasyon aktif ise pozisyonlara gore bosluk ve isimleri basilmasi */
	if(game_state==PLAY)
	{
		for(outl=1;outl<position1;outl++)
			printf("_");
		printf("%c",object1);

		for(in=1;in<=inspace;in++)
			printf("_");
		printf("%c",object2);

		for(outr=position2;outr<ROADLENGTH;outr++)
			printf("_");

		printf("\n12345678901234567890123456789012345678901234567890\n");
	}

	/* carpisma durumunun basilmasi */
	else if(game_state==CRASH)
	{

	for(outl=1;outl<=position1;outl++)
		printf("_");
	printf("%c",object1);

	for(outr=1;outr<ROADLENGTH-position1;outr++)
		printf("_");

	printf("\n12345678901234567890123456789012345678901234567890\n");

	}

	/* bitis aninin basilmasi */
	else if(game_state==END)
	{

	for(outl=1;outl<position1;outl++)
		printf("_");
	printf("%c",object1);

	for(outr=1;outr<ROADLENGTH-position1;outr++)
		printf("_");

    printf("\n12345678901234567890123456789012345678901234567890\n");
	}
	/* print_game_state fonksiyonunun sonu */
}

/* 				HW05_HASAN_MEN_131044009_part1.c	sonu			*/
