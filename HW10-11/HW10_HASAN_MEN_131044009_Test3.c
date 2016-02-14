/*##############################################################*/
/* HW10_HASAN_MEN_131044009_Test3.c								*/
/*																*/
/* Ne ise yarar?												*/
/* Olusturulan bir listenin bagimsiz kopyasini uretir ve        */
/* kopyanin bagimsizligini kanitlamak icin bazý degiskenlerle   */
/* oynama yapacak test dosyamiz                                 */
/*##############################################################*/

#include <stdio.h>

#include "HW10_HASAN_MEN_131044009_Part1.h"
#include "HW10_HASAN_MEN_131044009_Part2.h"
#include "HW10_HASAN_MEN_131044009_Part3.h"


int main(int argc,char *argv[])
{
    int app_size;
    Files_t files;
    Working_hours_t w_hours;
    Appointment_t *readed;
    node_t *node;
    node_t *copy_node;

    /* once listemiz olusturuldu */
    get_main_arguments(argc,argv,&w_hours,&files);
    readed = getRequests(&files,&app_size);
    node = build_ll(readed,app_size,&w_hours);
    add_personal_data(node,&files);

    /* listemiz kopyalandi */
    copy_node = make_independent_copy_ll(node);

    /* kontrollerimiz ekrana basildi */
    printf("\n#####After Independent Copy#####\n");
    printf("#####Original Node#####\n");
    print_node(node);
    printf("\n#####New node(copy)#####");
    print_node(copy_node);

    printf("\n#####After change#####\n");

    printf("#####Node after changing#####\n");
    change_node(node);
    print_node(node);
    printf("\n#####Independent Copy#####\n");
    print_node(copy_node);

    return 0;
}
