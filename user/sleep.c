#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc <=1) {
    printf("no input!\n");
    exit(0);
  }
  int cnt = 0;
  cnt = atoi(argv[1]);
  if(cnt>0) {
    sleep(cnt);
  } else {
    printf("input invalid!\n");
  }
  exit(0);
}
