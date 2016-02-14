#include <stdio.h>
#include <string.h>




int combination(int n,int k);
int ways(int n);
int ways_rec(int n,int k);



int main()
{

	int a=4,b=2;
	printf("C(%d,%d) = %d\n",a,b,combination(a,b));
	printf("Ways %d",ways(a));

	return 0;
}


int combination(int n,int k)
{
	int res=0;
	if( n==k || k==0 )
		res=1;
	else
	{
		res=combination((n-1),k);		/* stacte hangisinin daha once geldigini anlarız */
		res+=combination((n-1),(k-1));
	}
		
	return res;
}



int ways(int n)
{
	int k=2;

	return ways_rec(n,k);	
	
}

int ways_rec(int n,int k)
{
	int sum=0;
	if(k<=2 && k>=0)
	{
	return sum += ways_rec(n,k-1);
	}
}

