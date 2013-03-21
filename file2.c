#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main(int argc,char *argv[],char *envp[]){
  extern char **environ;

  int pid=fork();
  if(pid<0)  printf("error");
  else if(pid==0){
    FILE *f;
    f=fopen("text.txt","wr");
    fprintf(f,"%d  %d   ",pid,getpid());

    execl("/usr/bin/env","/usr/bin/env",0,envp);

    fclose(f);
  }
  else  printf("%d  %d   ",pid,getpid());
} 
