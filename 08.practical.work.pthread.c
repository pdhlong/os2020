#include <stdio.h>
#include <pthread.h>

void *printPrimeNumbers(void *n)
{
 int i, j, check;
 for(i = 2; i <= 1000000; i++)
 {
  check = 1;
  for(j = 2; j <= i/2; j++)
  {
   if(i%j == 0)
   {
    check = 0;
    break;
   }
  }
  if(check == 1)
  {
   printf("%d  ", i);
  }
}

void *printFiboSequence(void *n)
{
 int i, t1 = 2, t2 = 3; nextTerm;
 printf("%d  ", t1);
 printf("%d  ", t2);
 nextTerm = t1 + t2;
 while(nextTerm <= 1000000)
 {
  printf("%d  ", nextTerm);
  t1 = t2;
  t2 = nextTerm;
  nextTerm = t1 + t2;
 }
}

int main()
{
 pthread_t t1, t2;
 pthread_create(&t1, NULL, printPrimeNumbers, NULL);
 pthread_create(&t2, NULL, printFiboSequence, NULL);
 pthread_join(t1, NULL);
 pthread_join(t2, NULL);
 return 0;
}

   
