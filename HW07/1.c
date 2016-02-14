#include <stdio.h>
#include <string.h>
#define STR_SIZE 50
#define MAX_STR 20
int find_size(const char *string);
int char_number(const char *string,const char *wish_to_find);



int main()
{

	char str[STR_SIZE];
	char str2[MAX_STR][STR_SIZE];
	int n,i;
	char ch;
	int sayac=0;
	
	
	
	printf("Enter a string (Max=50 length)=>");
	fgets(str,STR_SIZE,stdin);
	if(str[find_size(str)-1]=='\n')
		str[find_size(str)-1]='\0';
		

	printf("String size = %d\n",find_size(str));
	
	printf("Enter the number of strings(Max=20)=>");
	scanf("%d",&n);
	
	/* sayi girildikten sonraki \n iptal edilir */
	do
	{
		scanf("%c",&ch);
	}while(ch!='\n');
	
	
	for(i=0;i<n;i++)
	{
		fgets(str2[i],STR_SIZE,stdin);
		if(str2[i][find_size(str2[i])-1]=='\n')
			str2[i][find_size(str2[i])-1]='\0';
		printf("Size2 = %d\n",find_size(str2[i]));
		sayac += char_number(str,str2[i]);
	}	
		
	
	printf("%s occ is %d ",str,sayac);
	
}

int find_size(const char *string)
{
	int sonuc=0,i=0;

	if(string[i]=='\0')
		sonuc = i;
	else sonuc = ++i + find_size(&string[i]);
	/* 1 + f_Size(1)de olur */
	
	return sonuc;
}

int char_number(const char *string,const char *wish_to_find)
{
	int res,num=0;
	res = strcmp(string , wish_to_find);
	
	if(res==0)
		num++;
		
	return num;

}
