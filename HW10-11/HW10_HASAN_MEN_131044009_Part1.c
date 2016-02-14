#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HW10_HASAN_MEN_131044009_Part1.h"	/* header dosyasi */

/* global degiskelnlerimiz */
const char *rec_bin_file="Records.bin";
const char *patient_file="Patients.xml";
const char *delete_file="Delete.txt";
const char *readable_rec_file="Records.xml";
const char *accept_app_csv_file="Appointments.csv";
const char *parameter_file="Parameter.txt";



void get_main_arguments(int argc, char *argv[], Working_hours_t* hours, 
															Files_t* files)
{
    int i;

	/* once dosyalar global olarak belirlendi 	*/
    files->accepted_appo_file_n=accept_app_csv_file;
    files->delete_file_n=delete_file;
    files->parameters_file_n=parameter_file;
    files->patient_file_n=patient_file;
    files->readable_records_file_n=readable_rec_file;
    files->records_file_n=rec_bin_file;
	/* baslangic bitis saatleri */
    hours->start = START_WORK;
    hours->end = END_WORK;

	/* arguman kontrollerinin yapilmasi */
	/* 1.argumandan itibaren bakilir */
    for(i=1;i<argc;i+=2)
    {
        switch(argv[i][1])
        {
            case 'r':
                files->records_file_n=argv[i+1]; break;
            case 'p':
                files->patient_file_n=argv[i+1]; break;
            case 'd':
                files->delete_file_n=argv[i+1]; break;
            case 'x':
                files->readable_records_file_n=argv[i+1]; break;
            case 'c':
                files->accepted_appo_file_n=argv[i+1]; break;
            case 't':
                files->parameters_file_n=argv[i+1]; break;
            case 's':
                sscanf(argv[i+1],"%d",&hours->start); break;
            case 'e':
                sscanf(argv[i+1],"%d",&hours->end);   break;
        default :
	/* hatali arguman bildirimi yap ve bitir */
            {
 #ifdef ERROR_LINE_ARG
            printf("Command line arguman failed!!!");
 #endif
            exit(1);	/* hatali cikis */
            }
        }
    }
}

Appointment_t* getRequests(const Files_t* files, int* size)
{

    int i=0;
    FILE *rec_binp;

    /* dinamik array- hipte olusturuldu */
    Appointment_t *appoints;

    /* ilk size bulmak icin temporary array */
    Appointment_t temp[MAX_APPOINTMENT];

    rec_binp = fopen(files->records_file_n,"rb");
    if(rec_binp==NULL)
    {
        FILE_ERROR(files->records_file_n);	/* hatali dosya */
        exit(1);
    }

#ifdef DEBUG_READ_BIN
    printf("Binary file readed and appoinments saved...\n");
#endif

    /* binaryden okuma yapilip size bulunur */
    while(fread(&temp[i],sizeof(Appointment_t),1,rec_binp))
    {
#ifdef DEBUG
        PRINT_TEMP(temp[i]);	/* okumalar dogrumu diye kontrol */
#endif

        i++;
    }
    *size=i;	/* size bulundur */
#ifdef DEBUG 
	printf("Appointments size = %d\n",*size);
#endif
    fclose(rec_binp);


    /* Kapa ac yapilarak seek basa getirildi. */
	/* asil dinamic arraya doldurulacak - alan ihali olmayacak */
    rec_binp = fopen(files->records_file_n,"rb");

    if(rec_binp==NULL)
    {
        FILE_ERROR(files->records_file_n);	/* dosya acilmaz ise cikis */
        exit(1);
    }
    /* dinamic olarak yazildi - gereksiz alan kullanilmadi */

    appoints=(Appointment_t *)calloc(*size,sizeof(Appointment_t));   
	/* dynamic array yapildi */

	
    fread(appoints,sizeof(Appointment_t),*size,rec_binp);	/* array doldu */

#ifdef DEBUG_APPOINT_BIN
    DBG_MESSAGE;
    PRINT_TEMP(appoints[3]);	/* kontrol icin arrayin bi elemani basildi*/
#endif 

    fclose(rec_binp);	/* dosya kapandi */
    return appoints;/* array return edildi.'Heapte olusturuldu'*/
}

void write_appointments(Appointment_t appointments[], int size, 
														const Files_t* files)
{
    int i;
    FILE *read_file_p;
    read_file_p = fopen(files->readable_records_file_n,"w");
    if(read_file_p==NULL)
    {
        FILE_ERROR(files->readable_records_file_n);
        exit(1);
    }
	/* appoint icerigi dosyaya yazildi */
    fprintf(read_file_p,"<Size>%d</Size>\n",size);
    fprintf(read_file_p,"<Records>\n");
    for(i=0;i<size;i++)
    {
        fprintf(read_file_p,"\t<Appointment>\n");
        fprintf(read_file_p,"\t\t<app_id>%d</app_id>\n",appointments[i].app_id);
        fprintf(read_file_p,"\t\t<patient_id>%d</patient_id>\n",
													appointments[i].patient_id);
        fprintf(read_file_p,"\t\t<hour>%d</hour>\n",appointments[i].hour);
        fprintf(read_file_p,"\t</Appointment>\n");
    }
    fprintf(read_file_p,"</Records>\n");

    fclose(read_file_p); /* dosya kapandi */
}

void print_parameters(const Files_t* files, const Working_hours_t* hours)
{
    FILE *param_textp;

    param_textp = fopen(files->parameters_file_n,"w");
    if(param_textp==NULL)
    {
        FILE_ERROR(files->parameters_file_n);
        exit(1);
    }
	/* files ve hour icerigi parameter dosyasina yazildi. */
    fprintf(param_textp,"Accepted Appointed File = %s\n",
												files->accepted_appo_file_n);
    fprintf(param_textp,"Delete File = %s\n",files->delete_file_n);
    fprintf(param_textp,"Parameter File = %s\n",files->parameters_file_n);
    fprintf(param_textp,"Patient  File = %s\n",files->patient_file_n);
    fprintf(param_textp,"Readable Records File = %s\n",
											files->readable_records_file_n);
    fprintf(param_textp,"Records File = %s\n",files->records_file_n);
    fprintf(param_textp,"Start WORK  = %d\n",hours->start);
    fprintf(param_textp,"End  WORK  = %d\n",hours->end);

    fclose(param_textp); /* dosya kapandi */
}

/*  HW10_HASAN_MEN_131044009_Part1.c SONU */
