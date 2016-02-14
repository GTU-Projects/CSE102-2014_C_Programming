/*##############################################################*/
/* HW10_HASAN_MEN_131044009_Test2.c								*/
/*																*/
/* Ne ise yarar?												*/
/* Binary den aldigi appointmentleri link liste ekleme, liste 	*/
/* dosyadan aldigi bilgiler ile listelere veri ekleme, listeden */
/* eleman silme ve listenin tamamiyle free edilmesini test etmek*/
/* amaciyla olusturulmustur.									*/
/*##############################################################*/
#include <stdio.h>
#include <stdlib.h>
#include "HW10_HASAN_MEN_131044009_Part1.h"
#include "HW10_HASAN_MEN_131044009_Part2.h"



int main(int argc,char *argv[])
{
    int app_size;
    Files_t files;
    Working_hours_t w_hours;
    Appointment_t *readed;
    node_t *node;
	int del_num;

	/* liste olusturuldu */
    get_main_arguments(argc,argv,&w_hours,&files);
    readed = getRequests(&files,&app_size);
    node = build_ll(readed,app_size,&w_hours);

	/* kontrol icin ekrana bas */
	print_node(node);

	/* dosyadan ek bilgiler okunup eklendi*/
    add_personal_data(node,&files);
    write_accepted_app(node,&files);

    printf("\n---------------------\n");
    printf("Personal information adden in list\n");
   	print_node(node);

    printf("\n---------------------\n");

	/* istenilen veriler silindi */
    del_num=delete_appointments(&node,&files);
    printf("\n---------------------\n");
    printf("* %d * Appoinments deleted from list\nNew List->\n",del_num);
    print_node(node);
	printf("\n---------------------\n");

	/* program sonu ve listenin free edilmesi */
    free_list(node);
    printf("\n---------------------\n");
    printf("List removed\n");

    return 0;
}
