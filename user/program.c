#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(){
int pid;

pid= fork();
if(pid==0){
    char *argsv[]={"ls",0};
     exec("ls",argsv);
     printf("exec failed\n");
}else{

   wait(0);
  printf("child finished execution\n");
}
 exit(0);
}
