/*##################################################################*/
/*																	*/
/*	HW10_HASAN_MEN_131044009_ProduceRecordFile.c  (PART1)			*/
/*	Tarih : 19.05.15												*/
/*																	*/
/* 	Tanim:	Belli sayida randevu bilgisini daha sonra kullanilmak 	*/
/* icin binary dosyasina yazar */
/*##################################################################*/

#include <stdio.h>

/* randevu icerikleri */

typedef struct{

    int app_id;
    int patient_id;
    int hour;
}Appointment_t;


int main()
{

	
    Appointment_t app[6];
    FILE *binp;
    binp = fopen("Records.bin","wb");


	/* degerlerimiz */

    app[0].app_id=8;
    app[0].hour=11;
    app[0].patient_id=1;

	/* iptal*/
    app[1].app_id=3;
    app[1].hour=21;
    app[1].patient_id=5;

	/* iptal*/
    app[2].app_id=26;
    app[2].hour=11;
    app[2].patient_id=20;

	/* iptal*/
    app[3].app_id=11;
    app[3].hour=4;
    app[3].patient_id=2;
	
    app[4].app_id=18;
    app[4].hour=14;
    app[4].patient_id=2;

    app[5].app_id=13;
    app[5].hour=14;
    app[5].patient_id=5;

    app[6].app_id=12;
    app[6].hour=15;
    app[6].patient_id=20;



    fwrite(&app[0],sizeof(Appointment_t),7,binp);
    fclose(binp);

    return 0;
}
/* HW10_HASAN_MEN_131044009_ProduceRecordFile.c sonu*/
