#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
int fd[2];
char msg[]="Hello from child process";
char buf[100];

pipe (fd);
if (fork()==0){
   close(fd[0]);
   write(fd[1],msg,sizeof(msg));
   close(fd[1]);
}else{
close (fd[1]);
read (fd[0],buf,sizeof(msg));
printf("%s\n",buf);
close(fd[0]);
wait(NULL);
}
return 0 ;
}
