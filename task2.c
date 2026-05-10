#include <omp.h>
#include <stdio.h>

int main(){
int N =100;
int sum =0;
int partial_sum[4]={0};

int num_threads =4;
omp_set_num_threads(num_threads);
#pragma omp parallel
   {
    int tid=  omp_get_thread_num();
    printf("I'm in thread: %d\n", tid);

#pragma omp for 
  for (int i=1; i<=N;i++){
partial_sum[tid]+=i;
}
} 
for(int i=0;i<num_threads;i++){
sum+=partial_sum[i];
}
printf("final sum from 1  to %d is :%d\n",N,sum);
return 0;
}
