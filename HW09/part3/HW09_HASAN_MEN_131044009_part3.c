/*######################################################################*/
/* HW09_HASAN_MEN_131044009_part3.c										*/
/* HAZIRLAYAN : HASAN MEN - 131044009									*/
/* TARIH: 27.4.15														*/
/*																		*/
/* TANIM: text dosyasindan bilgileri alip binary dsyasina yazan,		*/
/* daha sonra binary dosyasindan okuma yaparak tablolara dolduran ve 	*/
/* istenildigi takdirde tablolardaki elemanlardan arama yapip sonucu 	*/
/* ekrana basan program 												*/
/*######################################################################*/
#include <stdio.h>

#define TEXT_FILE "input3.txt" 
#define BIN_FILE "output1.bin"

#define MAX_SIZE 100	/* mpn_table icin maximum boyut*/


typedef struct /* kombinasyonlarin tutulacagi structlar */
{
    int first,second,third;
}triplet_t;

typedef struct /* tum bilgilerin atilmasi icin bolumler */
{
    int mpn,lower,upper;
    triplet_t combination;
}Row;

/* input parametre olarak aldigi text ve bin dosyaslari icinden texten okuma
	yapip binarye e yazar . yazma islemi 10'lu olarak yapilmistir */
void Into_Binary(FILE *text_input,FILE *binary_input);

/* binary filedan okuma yaparak 10lu olarak struct tablomuzu doldurur ve kac 
	deger doldurulduysa return edeilir */
int Load_Mpn_table(FILE *binary_input_file,Row mpn_table[],int maxsize);

/* kullanicidan aldigi combinasyon degerlerine gore tabloda arama yapip
	sonuclari terminale basar */
void search (Row mpn_table[],int actual_size, const triplet_t triplet_to_search);

int main()
{
    Row table_mpn[MAX_SIZE];	/* binaryden okunacaklarla doldurulacak */
    triplet_t search_comb;	/* kullanicidan alinacak arama degerleri */
    int new_table_size;	/* dosyadan okunan bilgi adedi */
    
    FILE *text,*bin;	/* text ve binary dosyalarimiz acildi */
    text=fopen(TEXT_FILE,"r");
    bin=fopen(BIN_FILE,"wb"); /*write modunda */
	
	/* binaryye bilgiler yazildi ve read modu kapatilip read binary acildi */
    Into_Binary(text,bin);
    fclose(text);
    fclose(bin);
    bin=fopen(BIN_FILE,"rb");
    
    /* binaryden bilgiler tabloya dolduruldu */
    new_table_size = Load_Mpn_table(bin,table_mpn,MAX_SIZE);
    /*printf("Upper2 = %d // size = %d\n",table_mpn[1].upper,new_table_size);*/

	/* kullanici ilk degeri -1 girene kadar combinasyonlar icinde arama yapar*/
	do
	{
    printf("\nEnter a combination-of-positives triptlet\n");
    printf("Enter -1 x x to exit!!!(x some ingeter)\n");
    scanf("%d%d%d",	&(search_comb.first),
    				&(search_comb.second),
    				&(search_comb.third));
    
    
    search(table_mpn,new_table_size,search_comb);
	}while((search_comb.first)!=-1);
	
	/* binary dosyasi kapatildi ve program sonlandi */
	fclose(bin);  
    return 0;
}

/* text dosyasindan bilgileri binarye gecirir */
void Into_Binary(FILE *text_input,FILE *binary_input)
{
    int i=0;
    Row temp[20];
    Row bin_temp[20];
    char ctemp;

	/* EOF gorene kadar bilgileri okur ve kac tane okundugunu tutar.*/
        while(fscanf(text_input,"%d %c%d %c%d %d %d %d",	
        								&(temp[i].combination.first),
                                        &ctemp,
                                        &(temp[i].combination.second),
                                        &ctemp,
                                        &(temp[i].combination.third),
                                        &(temp[i].mpn),
                                        &(temp[i].lower),
                                        &(temp[i].upper))!=EOF)
        {
            i++;
        }

    printf("%d - Record saved to binary file\n",i);
    /* okunan bilgiler binary dosyasina yazildi */
    fwrite(&temp,sizeof(Row),i,binary_input);

	/* kontrol icin binary den okuma yapildi */
	/*
    fclose(binary_input);
    binary_input=fopen(BIN_FILE,"rb");

    fread(&bin_temp,sizeof(Row),i,binary_input);
    printf("Bin_upper2 = %d\n",bin_temp[1].upper);*/

}

/* binary_input'tan okuma yapilir ve kac tane bilgi okunduysa dondurulur */
/* mpn_table output digerleri input parametre olarak alinmistir */
int Load_Mpn_table(FILE *binary_input_file,Row mpn_table[],int maxsize)
{
    int read=0,check;
    /* kac bilgi okundugunu tutar */
    check = fread(&mpn_table[0],sizeof(Row),10,binary_input_file);
    
    /* tutulan bilgi varsa devam */
    /* 10lu sekilde okuma yapar */
    while(check!=0)
    {
        read+=check; /* toplam okunan bilgileri topla */
        /* bilgi okumasi bitene yani eof olana kadar devamm eder */
        check = fread(&mpn_table[read],sizeof(Row),10,binary_input_file);
    }
    printf("%d - Record readed from binary file\n",read);
    return read; /* toplam okunan bilgi return edildi */
}

/* tum degiskenler input parametre olarak kullanildi */
/* triplet_t turunde kullanicidan alinan degerleri mpn_Table icinde ariyip */
/* sonucu ekrana basar */
void search (Row mpn_table[],int actual_size, const triplet_t triplet_to_search)
{
    int i=0,found=0;

	/* kac eleman icinde aranacak */
    while(i<actual_size)
    {
        if(mpn_table[i].combination.first==triplet_to_search.first &&
           mpn_table[i].combination.second==triplet_to_search.second &&
           mpn_table[i].combination.third==triplet_to_search.third)
	   	{
	   	/* bulunursa bilgilendir ve bulundugunu isaret et */
	   printf("MPN = %d;%d%% of samples contaion between %d and %d bacteria/ml \
	   \n###################################################################\n",
                mpn_table[i].mpn,95,mpn_table[i].lower,mpn_table[i].upper);
        	found=1;
        }
        /* sonraki elemanda arama yap */
        i++;
    }
    /* bulunmaz ise bilgi ver */
    if(!found)
    	printf("Combination couln't found.Try again \
   	 \n###################################################################\n");
 }
 
 /* HW09_HASAN_MEN_131044009_part3.c  sonu 	*/
