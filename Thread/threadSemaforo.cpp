#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

void L(int trem, int trilho);
void *trem1(void *arg);
void *trem2(void *arg);
void *trem3(void *arg);
