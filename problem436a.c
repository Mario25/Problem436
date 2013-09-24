#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int player2,iterations,count;
  double sum,latest1,latest2;
  srand(time(NULL));
  player2=0;
  scanf("%d",&iterations);
  for (count=0;count<iterations;count++){
    sum=0;
    while (sum<1){
      latest1=(double)rand()/(double)RAND_MAX;
      sum=sum+latest1;
    }
    while (sum<2){
      latest2=(double)rand()/(double)RAND_MAX;
      sum=sum+latest2;
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







