#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
void func(int fd) {
  int num;
  int cur=-1;
  int p[2];
  int pid=-1;
  while(read(fd,&num,4)==4) {
    if(cur==-1) {
      cur=num;
      printf("prime %d\n",cur);
    }
    if(num%cur) {
      if(pid == -1) {
        pipe(p);
        write(p[1],&num,4);
        pid = fork();
        if(!pid) {
          close(p[1]);
          close(fd);
          func(p[0]);
        } else {
          close(p[0]);
        }
      } else {
        write(p[1],&num,4);
      }
    }
  }
  close(fd);
  if(pid!=-1) {
    close(p[1]);
    wait(0);
  }
}
int main()
{
  int p[2];
  pipe(p);
  for(int i=2;i<=35;i++) {
    write(p[1],&i,4);
  }
  close(p[1]);
  func(p[0]);
  exit(0);
}
