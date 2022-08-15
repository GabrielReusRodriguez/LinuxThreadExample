#include <stdio.h>
#include <pthread.h>

void * funcionThread(void *arg){

    int idThread = *((unsigned int *) arg);
    printf("Inicio del thread ID: %d\n",  idThread);
    for(int i = 0;i<0xFFFF;i++){
        //sleep(1)
    }
    printf("Saliendo del thread ID %d\n",idThread);
    return NULL;
}




int main(int  argc, char** argv ){


    pthread_t threadId_1,threadId_2;
    int err;

    err = pthread_create(&threadId_1, NULL, &funcionThread, &threadId_1);
    if ( err ){
        perror("Error al crear el thread.\n");
        return(err);
    } else{
        printf("Se ha creado el thread con ID : %d \n", (unsigned int)threadId_1);
    }

    err = pthread_create(&threadId_2, NULL, &funcionThread, &threadId_2);
    if ( err ){
        perror("Error al crear el thread.\n");
        return(err);
    } else{
        printf("Se ha creado el thread con ID : %d\n",(unsigned int)threadId_2);
    }
    

    //Hago el join de los threads para que el programa main acabe cuando se acaban los threads.
    err = pthread_join(threadId_1,NULL);
    if(err){
        printf("Error al hacer el join del thread %d\n ",(unsigned int)threadId_1);
        return err;
    }

    err = pthread_join(threadId_2,NULL);
    if(err){
        printf("Error al hacer el join del thread %d\n ",(unsigned int)threadId_2);
        return err;
    }

    printf("Se finalizan los dos treads\n");
    return 0;
}

