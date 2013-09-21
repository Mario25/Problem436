#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int player2,iterations,count;
	double sum1,sum2,latest1,latest2;
	srand(time(NULL));
	player2=0;
    scanf("%d",&iterations);
    for (count=0;count<iterations;count++){
           	sum1=0;
           	sum2=0;
			while (sum1<1){
            	latest1=(double)rand()/(double)RAND_MAX;
            	sum1=sum1+latest1;
			}
			while (sum2<2){
             	latest2=(double)rand()/(double)RAND_MAX;
          		sum2=sum2+latest2;
        	}
			if (latest1<latest2){
               	player2++;
			}
			printf("%20.18f \n",player2/(double)count);
	}
	printf("\n\n %20.18f \n\n",player2/(double)iterations);
	system("pause");
	return 0;
}







