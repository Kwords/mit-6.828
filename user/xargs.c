#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

int main(int argc, char *argv[])
{
  if(argc<3) {
    printf("invalid input!\n");
    exit(0);
  }
  char* args[128];
  for(int i=1;i<argc;i++) args[i-1]=argv[i];
  char buf[512];
  while(1) {
    gets(buf,512);
    if(buf[0]=='\0') {
      break;
    }
    buf[strlen(buf)-1] = '\0';
    args[argc-1] = buf;
    args[argc]=0;
    int pid = fork();
    if(pid==0) {
      exec(argv[1],args);
      exit(0);
    } else{
      wait(0);
    }
  }
  exit(0);
}
