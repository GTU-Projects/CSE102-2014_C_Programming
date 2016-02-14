#include<stdio.h>
#include<string.h>


/* farkli kisimlari debug etmek icin const macrolar */
#define DEBUG
#define ERROR_LINE_ARG
#define DEBUG_READ_BIN
#define DEBUG_APPOINT_BIN


#define FILE_ERROR(x) printf("\n***********\n%s couldn't opened \
					to r/w/a.\n***********\n",x);
#define PRINT_TEMP(x) printf("\n*** App_id = %d\tPat_id = %d\tHour = %d***\n" \
				,x.app_id,x.patient_id,x.hour);
#define DBG_MESSAGE printf("\n######It's a debug message######\n");
#define CONTROL printf("\nControl\n");

#define MAX_STR 999
#define MAX_NAME_LEN 50
#define START_WORK 9
#define END_WORK 17
#define MAX_APPOINTMENT 999 /* randevu arrayi icin */


/* randevu bilgilerinin yapisi */
typedef struct{
    int app_id;
    int patient_id;
    int hour;
}Appointment_t;

/* mesai saaleri */
typedef struct{

    int start;
    int end;

}Working_hours_t;

/* Dosya isimleri */
typedef struct{

    const char *records_file_n;
    const char *patient_file_n;
    const char *delete_file_n;
    const char *readable_records_file_n;
    const char *accepted_appo_file_n;
    const char *parameters_file_n;
}Files_t;

/* link listimizin yapisi */
typedef struct node_t{

    int app_id;
    int patient_id;
    char name[MAX_NAME_LEN];
    char *history;
    int hour;
    struct node_t *next;
}node_t;


/*######################################################################*/
/*																		*/
/*	Girilen arguman ve saatlere gore files structini doldurur.			*/
/*																		*/
/*int argc -> girilen arguman sayisi (input parametre)					*/
/*argv	-> input-output olarak girilen arguman stringleri 				*/
/*hours -> input-output olarak calisma saatleri							*/
/*files -> input-output olarak verilerin islenecegi dosya stringleri	*/
/*######################################################################*/
void get_main_arguments(int argc, char *argv[], Working_hours_t* hours,
									 Files_t* files);


/*######################################################################*/
/* Binary filedan appoint bilgilerini okuyarak dinamik arraya yazar 	*/
/* ve kac randevu oldugunu output olarak yazar, arrayi ise return eder	*/
/*																		*/
/*const files -> input olarak verilerin okunacagi dosya pointerleri		*/
/*size -> output parametre olarak appointment sayisi					*/
/*######################################################################*/
Appointment_t* getRequests(const Files_t* files, int* size);

/*######################################################################*/
/*Olusturulan appoinment arrayini istenilen bicimde output dosyasina	*/
/* yazar 																*/
/*																		*/
/*Appointments -> input-output arguman 									*/
/*size ->input arguman													*/
/* files -> const input arguman											*/
/*######################################################################*/
void write_appointments(Appointment_t appointments[], int size,
						const Files_t* files);

/*######################################################################*/
/*Parametre olarak gonderilen bilgilerin iceriklerini outputa yazar		*/
/*																		*/
/*files -> input parametre	// hours-> input parametre					*/
/*######################################################################*/
void print_parameters(const Files_t* files, const Working_hours_t* hours);

/* HW10_HASAN_MEN_131044009_Part1.h sonu */
