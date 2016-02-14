/* ilk cikti guncellendi */
/*##############################################################*/
/*HW05_HASAN_MEN_131044009_part2.c								*/
/*________________________________								*/
/* Olusturan : HASAN MEN  24-Mart-2015							*/
/*																*/
/*Tanim															*/
/*___________													*/
/*onceden tanimli array uzerinde max degeri bulmak,sayi aramak	*/
/*gibi turlu turlu islemeleri yapan programcik					*/
/*Girdiler:														*/
/*	tum degeler onceden define edildi							*/
/*Ciktilar:														*/
/*  fonksiyon sonuclari											*/
/*##############################################################*/


#include <stdio.h>

#define ARRAYSPACE 10	/* maximum array boyutum */

/* arrayde arama yapmak icin yeni turler	*/
/* 0'dan 9'a kadar yerleri kelimelerle berlirtmemizi saglar	*/
typedef enum {FALSE=0,TRUE=1} bool;

/* fonskiyon prototipleri	*/
int max_array(int array[], int n);
int second_max_array(int array[], int n);
int sum_all_array (int array[], int n);
int count_array(int array[], int n, int value);
bool search_array (int array[], int n, int value);


int
main()
{
	/* ana fonksiyon baslangici	*/
	int array[]={5,12,18,5,6,12,32,1,2,12};	/* 10elemanli array	*/
	int j,i,zero;		/* sayaclarimiz	*/
	int num1=1,num2=2,num3=7;	/* arrayda aranacak numaralar	*/
	/* degiskenlerin sonu */
	
	
	
	printf("++++++++++++++++++++\n");
	printf("My array is => ");

	/* arrayin ekrana basilmasi	*/
	for(j=0;j<ARRAYSPACE;j++)
	{
		printf("%d ",array[j]);
	}
	
	/* fonksiyonlardan gelen bilgilere gore ekrana degerlerin basilmasi	*/
	printf("\n++++++++++++++++++++\n");
	printf("Maximum array is %d\n" ,max_array(array,ARRAYSPACE));
	printf("++++++++++++++++++++\n");
	printf("Maximum second array is %d\n",second_max_array(array,ARRAYSPACE));
	printf("++++++++++++++++++++\n");
	printf("Sum of all array is %d\n",sum_all_array(array,ARRAYSPACE));
	printf("++++++++++++++++++++\n");
	printf("Count of value %2d is %2d\n",num1,count_array(array,ARRAYSPACE,num1));
	printf("Count of value %2d is %2d\n",num2,count_array(array,ARRAYSPACE,num2));
	printf("Count of value %2d is %2d\n",num3,count_array(array,ARRAYSPACE,num3));
	printf("++++++++++++++++++++\n");
	
	zero=0;	/* eger sayi bulunmaz ise sayac ile hata dondurecez*/
	for(i=0;i<ARRAYSPACE;i++)
	{
		if(search_array(array,i,num1))
		{
			printf("%d is at [%d]\n",num1,i);
			i=ARRAYSPACE;	/* eger bulunursa donguden kacis saglar */
		}
		/* fonksiyon false return ederse sayac artacak */
		else if(!search_array(array,i,num1))
		{
			zero++;
			/*dongu sonunda bulunmadiysa hata verir*/
			if(zero==ARRAYSPACE)
				printf("Couldn't find %d in array\n",num1);
		}
	}
	
	zero=0;/* eger sayi bulunmaz ise sayac ile hata dondurecez*/
	for(i=0;i<ARRAYSPACE;i++)
	{
		
		if(search_array(array,i,num2))
		{
			printf("%d is at [%d]\n",num2,i);
			i=ARRAYSPACE;	/* eger bulunursa donguden kacis saglar */
		}
		/* fonksiyon false return ederse sayac artacak */
		else if(!search_array(array,i,num2))
		{
			zero++;
			/*dongu sonunda bulunmadiysa hata verir*/
			if(zero==ARRAYSPACE)
				printf("Couldn't find %d in array\n",num2);
		}
	}
	
	zero=0;	/* eger sayi bulunmaz ise sayac ile hata dondurecez*/
	for(i=0;i<ARRAYSPACE;i++)
	{
		if(search_array(array,i,num3))
		{
			printf("%d is at [%d]\n",num3,i);
			i=ARRAYSPACE;	/* eger bulunursa donguden kacis saglar */
		}
		/* fonksiyon false return ederse sayac artacak */
		else if(!search_array(array,i,num3))
		{
			zero++;
			/*dongu sonunda bulunmadiysa hata verir*/
			if(zero==ARRAYSPACE)
				printf("Couldn't find %d in array\n",num3);
		}
	}
	return 0;
	/* ana fonksiyonun sonu	*/
}

/* arraydeki tum degerleri tarayarak en buyuk olanini return eder*/
int max_array(int array[], int n)
{
	int i,max=0;	
	for(i=0;i<n;i++)
	{
		if(array[i]>=max)
			max=array[i];
	}
	return max;
}

/* tum degerleri arayarak 2.en buyuk degeri bulur ve return eder*/
int second_max_array(int array[], int n)
{
	int i,second_max=0;	
	
	for(i=0;i<n;i++)
	{
		if(array[i]>=second_max && array[i]<max_array(array,n))
			second_max=array[i];
	}
	return second_max;
}

int sum_all_array (int array[], int n)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
			sum+=array[i];
	}
	return sum;
}

/* aranan degerin arrayde kac defa bulundugunu return eder */
int count_array(int array[], int n, int value)
{
	int i,counter=0;
	for(i=0;i<n;i++)
	{
		if(value==array[i])
			counter++;
	}
	return counter;
}

/* arrayde elemanlari arar*/
bool search_array (int array[], int n, int value)
{
	
	int i;
	
	for(i=0;i<=n;i++)
	{
		if(array[i]==value)
			return TRUE;
	}
	return FALSE;
}

/*	HW05_HASAN_MEN_131044009_part2.c	sonu	*/
