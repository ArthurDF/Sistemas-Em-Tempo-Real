/*
 *  thread3.cpp
 *  teste
 *
 *  Created by Luiz Affonso on 04/09/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// programa thread3.cpp
// Programa que executar duas threads simultaneamente: main () e thread_function() 
// Para compilá-lo utilise: g++ -o thread3 thread3.cpp -lpthread

//#include "thread3.h"


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 4

// Fun��o auxiliar da thread
void* funcaoHelper(void* idThread) {
  sleep(3);
  printf("Finalizar a thread: %d\n", idThread);
  while(true){};
  pthread_exit((void *) idThread);
}  

int main(int argc, char *argv[]){

  //Vetor de threads
  pthread_t vetorThreads[NUM_THREADS];

  //Status de cria��o
  int statusRetorno;

  //Status de finaliza��o da thread
  void * statusFinalizacao;

  //Loop para criar as threads
  for(int i=0; i < NUM_THREADS; i++){
      printf("Main - criando a thread: %d\n", i);
      //Criar a thread i
      statusRetorno = pthread_create(&vetorThreads[i], NULL, funcaoHelper, (void *)i);
      //Verificando a exist�ncia de erros na cria��o
      if (statusRetorno){
         printf("Erro ao criar a thread: %d\n", statusRetorno);
         exit(-1);
      }
   }
  //Realizando um join com todas as threads
  for (int i=0; i < NUM_THREADS; i++){
      //Main fica bloqueado at� vetorThreads[i] finalizar
      statusRetorno = pthread_join(vetorThreads[i], &statusFinalizacao);
       if (statusRetorno){
         printf("Erro ao executar thread_join: %d\n", statusRetorno);
         exit(-1);
      }
      printf("Join finalizado para a thread: %d com o codigo: %d\n", i, statusFinalizacao);
   }
   printf("Finalizando o metodo main\n");
   pthread_exit(NULL);
}
