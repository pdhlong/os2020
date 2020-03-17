#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
 printf("Main before fork() \n");
 int pid1 = fork();
 if (pid1 == 0)
 {
  int pid2 = fork();
  if (pid2 == 0)
  {
   printf("I am child after fork(), lauching ps -ef \n");
   char *args[] = {"/bin/ps", "-ef", NULL);
   execvp("/bin/ps", args);
  }
  else
  {
   printf("I am parent after fork(), child is %d \n", pid2);
  }
  printf("I am child after fork(), lauching free -h \n);
  char *args[] = {"free", "-h", NULL);
  execvp("free", args);
 }
 else
 {
  printf("I am parent after fork(), child is %d \n", pid1);  
 }
 return 0;
}