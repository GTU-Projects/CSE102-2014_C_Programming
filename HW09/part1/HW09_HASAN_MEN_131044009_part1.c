/*######################################################################*/
/* HW09_HASAN_MEN_131044009_part1.c										*/
/* HAZIRLAYAN : HASAN MEN - 131044009									*/
/* TARIH: 27.4.15														*/
/*																		*/
/* TANIM:	Dosyadan alinan kisilerin yeni ucretlerini hesaplayip yeni	*/
/* ucretler ile birlikte binary file a yazan program					*/
/*######################################################################*/

#include <stdio.h>
#include <string.h>
#define MAX_STR 20	/* maximum string karakter sayisi */
#define MAX_LINE 100	/* fgets ile okunacak satir elemani sayisi */
#define TEXT_FILE "input1.txt"
#define BIN_FILE "input1.bin"

/* Instructer bilgieri icin structimiz */
typedef struct{

	char name[MAX_STR];	/* isim*/
	char surname[MAX_STR];	/*soyisim*/
	char department[MAX_STR];	/*bolum*/
	double salary;	/* maas */
	char class1[MAX_STR];	/* verdigi 1.ders */
	char class2[MAX_STR];	/* verdigi 2.ders */
}type_I;

/* Employee bilgileri icin structimiz */
typedef struct{

	char name[MAX_STR]; /* isim */
	char surname[MAX_STR];	/* soyisim */
	double salary;	/* maas */
	char degree; /* rutbe*/
/* a->rektor , b-> bolum sekreteri , c->genel servisler */

}type_E;

/* bi kisi sadece 1 rutbeye sahip olabilir.Bunu belirtmek icin struct */
typedef union{

	type_E empl;
	type_I inst;
}person_u;

/* asil structimiz , tum bilgilerimiz buradan dallanir. */
typedef struct{

	char character;
	person_u human;

}combine_type;

/* Text filedan bilgileri alip, combine_type turunde bir takim islemler yaparak
   yeni ucretler ile binary file'a yazan fonksiyon */
int read_inf(FILE *text_file,FILE *bin_file);

/* Onceden verilen bilgilere gore yeni ucretleri hesaplayip return eder */
combine_type salary_rise(combine_type person_info);


int main()
{

	int total;	/* okunan toplam deger sayisi */
	
	FILE *textp=fopen(TEXT_FILE,"r");	/* text dosyasi read modunda */
    FILE *binp=fopen(BIN_FILE,"wb");	/* write-binary olarak dosyasini ac*/
   
    if(textp==NULL || binp==NULL ) 	/* dosyalar acilmaz ise uyari ver ve cik */
    	printf("File couldn'T opened...\n");
	else {
	total = read_inf(textp,binp);
	/* isleme sokulan kisi sayisini terminale yazdirip bitir */
	printf("==========================================================\n");
	printf("%d Records readed and new salaries updated ...\n",total);
	printf("==========================================================\n");
	}
	return 0;
}

/* input = person_info -> kisinn type'i ve maasi okunacak					*/
/* output= bilgilere gore yeni maas bilgisi ayni tur oluğ return edilecek	*/
combine_type salary_rise(combine_type person_info)
{
	double new_slr; /* yeni maas icin degisken */
	combine_type temp=person_info; /* degisiklerin yapilacagi yer */
	if(temp.character=='I')	/* egitimci ise hesaplayip dondur */
	{
		new_slr = temp.human.inst.salary;
		new_slr += ((new_slr/2.0)*5)/100.0 + ((new_slr/2.0)*5.3)/100;
		temp.human.inst.salary=new_slr;
	}
	else if(temp.character=='E') /* isci ise hesaplayip dondur */
	{
		switch(temp.human.empl.degree)
		{
			case 'a':
				{
					new_slr = temp.human.empl.salary;
					new_slr += (new_slr*17.5)/100.0;
					temp.human.empl.salary=new_slr;
				}	break;
			case 'b':
				{
					new_slr = temp.human.empl.salary;
					new_slr += (new_slr*12.0)/100.0;
					temp.human.empl.salary=new_slr;
				}	break;
			case 'c':
				{
					new_slr = temp.human.empl.salary;
					new_slr += (new_slr*9.0)/100.0;
					temp.human.empl.salary=new_slr;
				}	break;
			default : printf("Wrong degree!!!\n");	/* yanlis rutbe */
		}
	}
	else printf("Wrong combine_type !!!\n");	/* yanlis personal */
	return temp;
}

int read_inf(FILE *text_file,FILE *bin_file)
{

    /* strtok fonksiyonu http://www.cplusplus.com/reference/cstring/strtok/
    'dan yardim aldim */
    char counter=0;		/* okunan kisi/satir sayisi */
    char line[MAX_LINE];	/* fgets'in okudugunu atacagi yer */
    char *pch; /* string parcalarini tutmak icin kullandim */
    combine_type readed_person; /* parcalarin atilacagi yer */

	printf("==========================================================\n");

   while(fgets(line,MAX_LINE,text_file)!=NULL) /* null olana kadar okuma yapar */
   {
		counter++;
        if(line[strlen(line)-1]=='\n')	/* satir sonundaki newline i sil */
            line[strlen(line)-1]='\0';


          pch = strtok (line," ,"); /* virgul ve spaceleri kullanarak parcala */
      if(strcmp(pch,"Instructor")==0)
        while (pch != NULL) /* parcalama bitene kadar devam */
        {
            readed_person.character='I';
            pch = strtok (NULL," ,");
            strcpy(readed_person.human.inst.name,pch);
         
            pch = strtok (NULL," ,");
            strcpy(readed_person.human.inst.surname,pch);
            
            pch = strtok (NULL,","); /* sadece virgul varsa parcala */
            strcpy(readed_person.human.inst.department,pch);

            pch = strtok (NULL," ,");
            strcpy(readed_person.human.inst.class1,pch);
            
            pch = strtok (NULL," ,");
            strcpy(readed_person.human.inst.class2,pch);
            
            /* maasi float olarak kaydet */
            pch = strtok(NULL," ,");
            sscanf(pch," %lf",&(readed_person.human.inst.salary));
            
            pch = strtok(NULL," ,");
     
     		/*	Kontorl amacli kisileri ekrana yaz */       
            printf("%s ",readed_person.human.inst.name);
            printf("%s ",readed_person.human.inst.surname);
            printf("%s ",readed_person.human.inst.department);
            printf("%s ",readed_person.human.inst.class1);
            printf("%s ",readed_person.human.inst.class2);
            printf("O_Salary=%.1f ",readed_person.human.inst.salary);

			/*yeni ucreti hesaplayip eskininin uzerine yazmak */	
            (readed_person)=salary_rise(readed_person);
            printf("N_salary=%.2f\n",readed_person.human.inst.salary);
        }else if(strcmp(pch,"Employee")==0) /* icsi ise devam et */
            while (pch != NULL)
            {
                readed_person.character='E';
                pch = strtok (NULL," ,");
                strcpy(readed_person.human.empl.name,pch);
                
                pch = strtok (NULL," ,");
                strcpy(readed_person.human.empl.surname,pch);
                
				/* maasi float olarak kaydet */
                pch = strtok(NULL," ,");
                sscanf(pch," %lf",&(readed_person.human.empl.salary));
                
				
                pch = strtok(NULL," ,");
                readed_person.human.empl.degree=pch[0];
                

                pch = strtok(NULL," ,"); /* parcalama biter */
             
             	/* kontrol amacli ekrana bilgiler basilir */   
				printf("%s ",readed_person.human.empl.name);
				printf("%s ",readed_person.human.empl.surname);
				printf("%c ",readed_person.human.empl.degree);
				printf("Salary=%.1f ",readed_person.human.empl.salary);

				/* yeni ucret hesaplanip atamasi yapilir */
                readed_person=salary_rise(readed_person);
                printf("New salary =  %.2f\n",readed_person.human.empl.salary);
            }
            /* yeni ucretler ile kisiler binary olarak yazilir */
        fwrite(&(readed_person),sizeof(combine_type),1,bin_file);
    }
	printf("==========================================================\n");
 	return counter;  
 }
 /* HW09_HASAN_MEN_131044009_part1.c SONU */

