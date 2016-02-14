#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "HW10_HASAN_MEN_131044009_Part1.h"
#include "HW10_HASAN_MEN_131044009_Part2.h"
#include "HW10_HASAN_MEN_131044009_Part3.h"


/* head-> gelen listenin basini tutarak listede ilerler*/
/* basit bir sekilde dosya terminalden okuma yapar gibi*/
/* listeden listeye okuma yaparak yeni bir liste olusturu*/
node_t * make_independent_copy_ll(node_t* head)
{

    node_t *newp; /* baglanacak nodlar */
    node_t *tofill;/* nodlarý takip etmek icin*/
    node_t *ansp;/* yeni nodumuz */

    ansp=(node_t *)malloc(sizeof(node_t));
    tofill=ansp;

    /* ilk eleman kopyalandi */
    ansp->app_id=head->app_id;
    ansp->patient_id = head->patient_id;
    strcpy(ansp->name,head->name);
    ansp->hour=head->hour;
    ansp->history=(char *)malloc(sizeof(head->history));
    ansp->history=head->history;

    head=head->next;
    /* head guncellendi, 2.elemana gecildi */


    /* listeye elemanlar eklenir */
    while(head!=NULL)
    {
        newp=(node_t *)malloc(sizeof(node_t));
        newp->app_id=head->app_id;
        newp->patient_id = head->patient_id;
        strcpy(newp->name,head->name);
        newp->hour=head->hour;
        newp->history=(char *)malloc(sizeof(head->history));
        newp->history=head->history;

        tofill->next=newp;
        tofill=newp;

        head=head->next;
    }
    /* listenin sonuna null gelir */
    tofill->next=NULL;

    return ansp;
}

/* alinan listenin bikac degiskenini degistirir. */
/* kontrol amaclidir. */
void change_node(node_t *node)
{

    node->app_id= 13;
    node->patient_id=69;
    strcpy(node->name,"Evren");
    strcpy(node->next->name,"Tutor Aliiii");

    node->history="History degistii";
}

