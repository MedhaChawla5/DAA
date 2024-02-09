#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int isprime(int n ,int* opcount){
	int i;
	int count = 0;
	for(i=2;i< sqrt(n);i++){
		*opcount++;
		if(n%i == 0){
			return 0;
		}
		return 1;
	}
}
int main(){
	int gcd=1;
	int n1,n2;
	int opcount = 0;
	int i = 2;
	int x,y;
	printf("Enter first integer");
	scanf("%d",&n1);
	printf("Enter second integer");
	scanf("%d",&n2);
	x = n1<n2 ? n1 : n2;
	y = n1>n2 ? n1 : n2;
	do{
		opcount++;
		if(x%i==0 && y%i ==0){
			if(isprime(i,&opcount)){
				x = x/i;
				y=y/i;
				gcd = gcd*i;
				i--;
			}
		}
		i++;
	}while(i<=x);
	printf("GCD of %d and %d is %d \nopcount is %d",n1,n2,gcd,opcount);
	return 0;
}