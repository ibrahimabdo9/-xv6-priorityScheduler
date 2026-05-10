#include <stdio.h>
#include <pthread.h>

void *worker(void *arg){
int id= *(int *)arg;
printf("thread says:%d\n",id);
return NULL;
}
int main(){
pthread_t threads[5];
int ids[5];

for(int i=0; i<5; i++){
ids[i]=i;
pthread_create(&threads[i],NULL,worker,&ids[i]);
}
for(int i=0;i<5; i++){
pthread_join(threads[i] ,NULL);
}
printf("main thread finished.\n");
return 0;
}
