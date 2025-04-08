#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  int p[2];
  char buf='c';
  pipe(p);
  int pid = fork();
  if(pid > 0) {
    write(p[1],&buf,1);
    close(p[1]);
    wait(0);
    read(p[0],&buf,1);
    close(p[0]);
    printf("%d: received pong\n",getpid());
  } else if(pid == 0){
    read(p[0],&buf,1);
    close(p[0]);
    printf("%d: received ping\n",getpid());
    buf = 's';
    write(p[1],&buf,1);
    close(p[1]);
  }
  exit(0);
}
