/*##################################################################*/
/*																	*/
/*	HW10_HASAN_MEN_131044009_Test1.c  (PART1)						*/
/*	Tarih : 19.05.15												*/
/*																	*/
/* 	Tanim:Binary fileden randevu bilgilerini alip dinamic arraya	*/
/*  tam dolu bir sekilde yazan ve kullanilan dosya bilgilerini 		*/
/* 	output olarak verek program parcacigi							*/
/*##################################################################*/

#include <stdio.h>
#include "HW10_HASAN_MEN_131044009_Part1.h"


int main(int argc,char *argv[])
{
    int app_size;	/* appointment size */
    Files_t files;	/* files bilgileri */
    Working_hours_t w_hours;	/* mesai saatleri */
    Appointment_t *readed;	/* dinamik arrayimiz */

	/* main argumanlari varsa islendi */
    get_main_arguments(argc,argv,&w_hours,&files);

	/* dinamic olarak appointler okundu */
    readed = getRequests(&files,&app_size);

	/* appointler gerekli formatta yazildi */
    write_appointments(readed, app_size,&files);

	/* dosya isimleri ve saatler parametre dosyasina yazildi */
    print_parameters(&files,&w_hours);

	/* program basarili bir sekilde sona erdi */
    return 0;
}

/* HW10_HASAN_MEN_131044009_Tes1.c Sonu */
