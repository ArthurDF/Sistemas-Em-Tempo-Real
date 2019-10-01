#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

// Para compilá-lo utilise: g++ -o threadtrem threadtrem.cpp -lpthread

void *thread_function(void *arg);
pthread_mutex_t m1; /* proteção para: work_area e time_to_exit */
void L(int trem, int trilho);
void *trem1(void *arg);
void *trem2(void *arg);

#define WORK_SIZE 1024
char work_area[WORK_SIZE];
int time_to_exit = 0;

int main()
{
    pthread_t thread1, thread2;
    int res;
    void *thread_result;

    // Criação do Mutex M1
    res = pthread_mutex_init(&m1, NULL);
    if (res != 0)
    {
        perror("Iniciação do Mutex Falhou");
        exit(EXIT_FAILURE);
    }

    // Criação Da Thread 1

    res = pthread_create(&thread1, NULL, trem1, NULL);
    if (res != 0)
    {
        perror("Iniciação da Thread1 Falhou");
        exit(EXIT_FAILURE);
    }

    // Criação Da Thread 2

    res = pthread_create(&thread2, NULL, trem2, NULL);
    if (res != 0)
    {
        perror("Iniciação da Thread2 Falhou");
        exit(EXIT_FAILURE);
    }

    //espera os terminos das Threads 1 e 2
    res = pthread_join(thread1, &thread_result);
    if (res != 0)
    {
        perror("Join Thread1 falhou");
        exit(EXIT_FAILURE);
    }
    res = pthread_join(thread2, &thread_result);
    if (res != 0)
    {
        perror("Join Thread2 falhou");
        exit(EXIT_FAILURE);
    }

    pthread_mutex_destroy(&m1);
    exit(EXIT_SUCCESS);
}

void *trem1(void *arg) {
    while(1){
        L(1,1);
        sleep(1);
        L(1,2);
        sleep(1);
        //lock(m1)
        pthread_mutex_lock(&m1);
        L(1,3);
        sleep(1);
        //unlock(m1)
        pthread_mutex_unlock(&m1);
        L(1,4);
        sleep(1);
    }
    pthread_exit(NULL);
}
void *trem2(void *arg) {
    while(1){
        L(2,5);
        sleep(1);
        L(2,6);
        sleep(1);
        //lock(m1)
        pthread_mutex_lock(&m1);
        L(2,7);
        sleep(1);
        //unlock(m1)
        pthread_mutex_unlock(&m1);
        L(2,8);
        sleep(10);
    }
    pthread_exit(NULL);
}

void L(int trem, int trilho){
    printf("Trem: %d ---- no Trilho: %d\n",trem,trilho);
}

void *thread_function(void *arg)
{
}