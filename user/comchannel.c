#include "kernel/types.h"
#include "user/user.h"
int main()
{
int fds[2];
char buf[100];
int pid;

pipe (fds);
pid =fork();

if (pid == 0){
//child

close(fds[1]);
int n =read(fds[0],buf,sizeof(buf));
write(1,buf,n);
close(fds[0];
}else{
//parent
close(fds[0]);
write(fds[1], "Hello from parent\n",18);
close(fds[1];
wait(0);
}
exit(0);
}
