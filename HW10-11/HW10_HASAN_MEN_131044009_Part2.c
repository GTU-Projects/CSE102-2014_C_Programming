/*##################################################################*/
/*																	*/
/*	HW10_HASAN_MEN_131044009_Part2.c 	*/
/*  HW10_HASAN_MEN_131044009_Test2.c icin gerekli fonksiyonlarin 	*/
/* 	iceriklerini neler yapacagini icerir.							*/
/*	Tam calismasi icin test2ve part2.h dosyasi ile combine edilmeli	*/
/*##################################################################*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "HW10_HASAN_MEN_131044009_Part1.h"
#include "HW10_HASAN_MEN_131044009_Part2.h"





/* Fonksiyona gelen degerin listedeki varligini return eder*/
int is_duble(int hourr,node_t *list)
{
    int res;
    if(list==NULL)
        res=0;
    else if(list->hour==hourr)
            res=1;
    else    res = is_duble(hourr,list->next);

    return res;
}

node_t* build_ll(Appointment_t appointmens[],
									int size, const Working_hours_t *hours)
{
/* ayni olanlarin silinmesi kaldi*/
    int fill=0,i=0,j;

    /* baslangicta listemiz null */
    node_t * head=NULL;
    node_t * temp;

	head=NULL;
    for(j=0;j<size;j++)
	{
	    /* saatler uygunsa ve daha onceden listemize eklenmemisse ekle */
		if(appointmens[j].hour >= hours->start &&
			appointmens[j].hour <= hours->end &&
			 !is_duble(appointmens[j].hour,head))
       {
            temp=(node_t *)malloc(sizeof(node_t));
            temp->app_id=appointmens[j].app_id;
            temp->patient_id=appointmens[j].patient_id;
            temp->hour=appointmens[j].hour;
            temp->name[0]='\0';
			temp->history='\0';
#ifdef DEBUG
    printf("List-patient-id= %d ",temp->patient_id);
	printf("List-patient-hs= %s\n",temp->history);
#endif
			temp->next=head;
            head=temp;
        }
	}
   	return head;
}

/* Link listin tum elemenlarini basar */
void print_node(node_t *node)
{
    if(node!=NULL)
    {
        printf("\n\n%d - ",node->app_id);
        printf("%d -",node->patient_id);
        printf("%s -",node->name);
       	/*printf("%s\n",node->history);*/
		/* history yer gosterdigi icin yazilmiyor */
		/* seg fault cikartiyor*/
        print_node(node->next);
    }
}

void write_accepted_app(node_t* head, const Files_t* files)
{
    int i=0;
    FILE *accep_csv_file;
    accep_csv_file=fopen(files->accepted_appo_file_n,"w");
    if(accep_csv_file==NULL)    /* dosya acilmama durumunda hata */
    {
        FILE_ERROR(files->accepted_appo_file_n);
        exit(1);
    }

    /* belirtilen formatta liste elemanlari yazilir */
    fprintf(accep_csv_file,"no;id;patient_id;name;history;hour\n");
    while(head!=NULL)
    {
        fprintf(accep_csv_file,"%d;%d;%d;%s;%s;%d\n",i,head->app_id,
											head->patient_id,head->name,
                                            head->history,head->hour);
        i++;
        head=head->next;
    }
}

void add_personal_data(node_t* head, const Files_t* files)
{
    char temp[20];
    FILE *pt_xml_file;
    pt_xml_file=fopen(files->patient_file_n,"r");

    if(pt_xml_file==NULL)
    {
        FILE_ERROR(files->patient_file_n);
        exit(1);
    }
    /* dosya basindaki records ignore edildi */
    fscanf(pt_xml_file,"%s",temp);
    /* geri kalani okumak icin fonksiyon cagirildi */
    read_p_data(head,pt_xml_file);

    fclose(pt_xml_file);
}

void read_p_data(node_t* head,FILE *pdata)
{
    node_t *find_node;
    char temp[MAX_HISTORY],ch,id[MAX_ID_LEN],
		name[MAX_NAME_LEN],historyx[MAX_HISTORY];
    int a_id;
    int i=0;
    int last=0;

    /* ignore </patiens> and </records> */
    fscanf(pdata,"%s",temp);

    /* dosya sonuna gelindi */
    if(strcmp(temp,"</Records>")==0)
        last=1;
    else{

            /*p1 -> sýrayla  < ve > arasindaki karakterler kaydedildi*/
            while(fscanf(pdata,"%c",&ch)!=EOF && ch!='>'){}
            while(fscanf(pdata,"%c",&ch)!=EOF && ch!='<')
            {
                sprintf(&id[i],"%c",ch);
                i++;
            }
            sscanf(&id[0],"%d",&a_id);
            /* stringten okuma yapilarak id kaydedildi */

            /* tab bitisine kadar hersey ignore edildi */
            while(fscanf(pdata,"%c",&ch)!=EOF  && ch!='>'){}

            /* p2 -> sýrayla  < ve > arasindaki karakterler kaydedildi*/
            i=0;
            while(fscanf(pdata,"%c",&ch)!=EOF  && ch!='>'){}
            while(fscanf(pdata,"%c",&ch)!=EOF  && ch!='<')
            {
                sprintf(&name[i],"%c",ch);
                i++;
            }
            name[i]='\0';
            /* taglar arasindaki name kaydedildi ve gerisi ignore edildi*/
            while(fscanf(pdata,"%c",&ch)!=EOF  && ch!='>'){}

            /*p3 taglar arasindaki name kaydedildi ve gerisi ignore edildi*/
            i=0;
            while(fscanf(pdata,"%c",&ch)!=EOF  && ch!='>'){}
            while(fscanf(pdata,"%c",&ch)!=EOF  && ch!='<')
            {
                sprintf(&historyx[i],"%c",ch);
                i++;
            }
            while(fscanf(pdata,"%c",&ch)!=EOF  && ch!='>'){}

            /* ignore </patient>  */
            fscanf(pdata,"%s",temp);
        #ifdef DEBUG_READ_PER
            printf("ID = %d\n",a_id);
            printf("Name = %s\n",name);
            printf("Hist = %s\n",historyx);
        #endif

    /* okunanalar listelere yaziliyor */
            find_node=head;
            find_node->history=(char *)malloc(sizeof(char)*strlen(historyx));
            find_node->history=NULL;
            while(find_node!=NULL)
            {
                /* id ye sahip kisi var ise bilgileri listeye eklenir */
                if(find_node->patient_id==a_id)
                {
                    strcpy(find_node->name,name);
                    find_node->history=historyx;
                }
                find_node=find_node->next;
            }
        }
    /* eger dosya sonundaki tag a gelinmediyse tekrar okuma yap */
    if(!last)
        read_p_data(head,pdata);
}

int delete_appointments(node_t** head, const Files_t* files)
{
    int del_app;
	int count=0;
    FILE *del_file;
    node_t* del;
    node_t* clear; /* bir onceki nodun yerini tutmak icin */

    del_file=fopen(files->delete_file_n,"r");


    if(del_file==NULL){
        FILE_ERROR(files->delete_file_n);
        exit(1);
    }

/* http://geeksquiz.com/linked-list-set-3-deleting-node/ */
/* KAYNAK OLARAK CALISILDI */
    while(fscanf(del_file,"%d",&del_app)!=EOF)
    {
		printf("%d-",del_app);
        del=(*head);

		/*ilk elemanda ise direk sil ve listeyi guncelle */
		if(del!=NULL && del->app_id==del_app)
		{
			*head=del->next;
			free(del);
			count++; /* silince sayaci arttir */
		}
		else
		{
			/* sayiyi bulana kadar git*/
		    while(del!=NULL && del->app_id!=del_app)
		    {
		        clear=del;
		        del=del->next;
		    }
			/* sayi bulundu ise silinecek */
		    if(del!=NULL)

		        {
		            clear->next=del->next;
		            free(del);
					count++;
		        }
		}
}
    return count;
}


void free_list(node_t* head)
{
    node_t *temp;
    while(head!=NULL) /* liste sonuna gelene kadar hersey free edildi */
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
