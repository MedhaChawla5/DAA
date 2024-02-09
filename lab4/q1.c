#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int cost[4][4]={{10,3,8,9},{7,5,4,8},{6,9,2,9},{8,7,10,5}};
    int persons[4]={0,0,0,0};
    int jobs = 4;
    int final[4]={0,1,2,3};
    int small = cost[0][0]+cost[1][1]+cost[2][2]+cost[3][3];
    int opcount=0;
    int mainopcount=0;
    for(int i =0; i<jobs ; i++ ){
        persons[0]=i;
        for(int j =0; j<jobs ; j++ ){
            if(j==i){
                opcount++;
                continue;
            }
            persons[1]=j;
            for(int k =0; k<jobs ; k++ ){
                if(k==i || k==j ){
                opcount= opcount+2;
                continue;
                }
                persons[2]=k;
                for(int l =0; l<jobs ; l++ ){
                    if(l==i || l==j || l==k ){
                    opcount= opcount+3;
                    continue;
                    }
                    mainopcount++;
                    persons[3]=l;
                    int tempcost = cost[0][persons[0]]+cost[1][persons[1]]+cost[2][persons[2]]+cost[3][persons[3]];
                    if(tempcost<small){
                        small = tempcost;
                        final[0]= persons[0];
                        final[1]= persons[1];
                        final[2]= persons[2];
                        final[3]= persons[3];
                    }

                }
            }
        }
    }
    for(int i = 0; i<4;i++){
        printf("%d person is assigned with job %d \n",i+1 , final[i]+1);
    }
    printf("comparision opcount is %d \n",opcount);
    printf("main opcount is %d \n",mainopcount);
    printf("total opcount is %d \n",opcount+mainopcount);

}
