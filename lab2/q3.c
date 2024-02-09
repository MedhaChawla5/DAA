#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b,int*opcount){
	int t;
	if(a<b)
		t = a;
	else
		t=b;
	for(t=b;t>0;t--){
		(*opcount)++;
		if(a%t==0 && b%t==0)
			return t;
	}
}
int main(){
	int opcount=0;
	printf("Enter first integer");
	int x;
	scanf("%d",&x);
	printf("Enter second integer");
	int y;
	scanf("%d",&y);
	int g= gcd(x,y,&opcount);
	printf("The gcd of numbers is %d \nopcount is %d",g,opcount);
}