#include <stdio.h> 
#include <stdlib.h> 
#include <semaphore.h> 
#include <unistd.h>  
#include <pthread.h> 

sem_t mutex;

void *thread(void *input)
{
    sem_wait(&mutex);
    sleep(1);
    printf("%s\n",(char *)input);
    sem_post(&mutex);
}

int main()
{
    pthread_t A, B;
    sem_init(&mutex, 0, 1);
    pthread_create(&B,NULL,thread,"Inside thread B");
    pthread_create(&A,NULL,thread,"Inside thread A"); // B goes to sleep so A waits for B to complete
    pthread_join(A,NULL);//A terminates
    pthread_join(B,NULL);//B terminates
    printf("%s","Exiting main code\n"); // only after both A and B terminates
    sem_destroy(&mutex);
    return 0;
}