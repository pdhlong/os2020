#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

pthread_mutex_t lock;
sem_t mutex;

void *printPrimeNumbers(void *n)
{
 sem_wait(&mutex);
 pthread_mutex_lock(&lock);
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
 pthread_mutex_unlock(&lock);
 sem_post(&mutex);
}

void *printFiboSequence(void *n)
{
 sem_wait(&mutex);
 pthread_mutex_lock(&lock);
 int i, t1 = 2, t2 = 3, nextTerm;
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
 pthread_mutex_unlock(&lock);
 sem_post(&mutex);
}

int main()
{
 sem_init(&mutex, 0, 1);
 if(pthread_mutex_init(&lock, NULL) != 0)
 {
  printf("\n mutex init failed\n");
  return 1;
 }
 pthread_t t1, t2;
 pthread_create(&t1, NULL, printPrimeNumbers, NULL);
 pthread_create(&t2, NULL, printFiboSequence, NULL);
 pthread_join(t1, NULL);
 pthread_join(t2, NULL);
 pthread_mutex_destroy(&lock);
 sem_destroy(&mutex);
 return 0;
}

   
