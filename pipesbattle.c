#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "strings.h"
#include <semaphore.h>

#define MAXBUFF 1024

int lock = 1;
sem_t mutex; 

void client (int readfd, int writefd);
void server(int readfd, int writefd);
int attack(char ident[40]);

void *count_time(void *arg);

int main(int argc, char **argv){

sem_init(&mutex, 0, 1);

int descritor, // usado para criar o processo filho pelo fork
    pipe1[2], // comunicacao pai -> filho
    pipe2[2]; // comunicacao filho -> pai
    
    system("clear");
    printf("\n *___Pipes-Battle___*\n");    

    if (pipe(pipe1)<0 || pipe(pipe2) <0)
    { 
        printf("Erro na chamada PIPE");
        exit(0);
    }
    // Fork para criar o processo filho
    if ( (descritor = fork()) <0)
    {
        printf("Erro na chamada FORK");
        exit(0);
    }
    else if (descritor >0) // Processo pai
    { 
        close(pipe1[0]); // fecha leitura no pipe1
        close(pipe2[1]); // fecha escrita no pipe2
        client(pipe2[0], pipe1[1]); // Chama Client no pai
        close(pipe1[1]); // fecha pipe1
        close(pipe2[0]); // fecha pipe2
            exit(0);
    } // Fim do processo pai

    else // Processo filho
    { 
        close(pipe1[1]); // fecha escrita no pipe1
        close(pipe2[0]); // fecha leitura no pipe2
        server(pipe1[0], pipe2[1]); // Chama Server no filho
        close(pipe1[0]); // fecha leitura no pipe1
        close(pipe2[1]); // fecha escrita no pipe2
            exit(0);
    } // Fim do processo filho
    sem_destroy(&mutex);
} // Fim do main

void client (readfd, writefd)
    int readfd, // leitura do pipe2[0]
        writefd;// escrita no pipe1[1]
{
    struct str{
        int vida_inimigo;
        char identify[MAXBUFF];
    };
    struct str buff;
    int aux = 0;
    int vida = 100;
    int mana = 100;
    char vida_inimigo_conv[40];
    buff.vida_inimigo = 100;

    pthread_t thread1;
    //pthread_create(&thread1, NULL, count_time, NULL);


    while(1)
    {
        sem_wait(&mutex);
        lock = 0;
        sem_post(&mutex);
        pthread_create(&thread1, NULL, count_time, NULL);

	    printf("\n Client-> Vida do Server: %d\n", buff.vida_inimigo);

        printf("\n Client-> Vida: %d", vida);
        //printf("\n Client-> Mana: %d", mana);
        

        printf("\n\n %s", info_client); 

        scanf("%d", &aux);
        printf(" \n Client->");

        switch (aux)
        {
        case 1:
            printf(" %s", info_attack_1);
                mana = mana - 25;
                strcpy(buff.identify, "Deadlock");
            break;
        case 2:
            printf(" %s", info_attack_2);
                mana = mana - 25;
                strcpy(buff.identify, "Divisao por zero");
            break;
        case 3:
            printf(" %s", info_attack_3);
                mana = mana - 25;
                strcpy(buff.identify, "Tijolada na CPU");
            break;
        case 4:
            printf(" %s", info_reload);
                mana = mana + 25;
            break;
        case 5:
            printf(" Saindo do programa\n");
            exit(0);
            break;    
        default:
            exit(0);
            break;
        }
        sem_wait(&mutex);
        lock = 1;
        sem_post(&mutex);

        buff.vida_inimigo = vida;
        sprintf(vida_inimigo_conv,"%d",buff.vida_inimigo);

        write(writefd, buff.identify, 40);
	      write(writefd, vida_inimigo_conv, 40);

        read(readfd, buff.identify, 40);
	      read(readfd, vida_inimigo_conv, 40);
        
        buff.vida_inimigo = atoi(vida_inimigo_conv); 

	    system("clear");

        int dano = attack(buff.identify);
        vida = vida - dano;

        if(vida <= 0){
            printf("Client perdeu \n");
            exit(0);
        }
    }
} // Fim da Funcao CLIENT

void server(readfd, writefd)
    int readfd, // leitura do pipe1[0]
        writefd; // escrita no pipe2[1]
{
    struct str{
        int vida_inimigo;
        char identify[MAXBUFF];
    };
    struct str buff;
    int aux1 = 0;
    int vida = 100;
    int mana = 100;
	char vida_inimigo_conv[40];
    buff.vida_inimigo = 100;

    pthread_t thread2;

    while(1)
    {
        sem_wait(&mutex);
        lock = 2;
        sem_post(&mutex);
        
        read(readfd, buff.identify, 40);
	    read(readfd, vida_inimigo_conv, 40);

        
        buff.vida_inimigo = atoi(vida_inimigo_conv);    
        
      	system("clear");
        
        int dano = attack(buff.identify);
        vida = vida - dano;
        
        if(vida <= 0){
            printf("Server perdeu \n");
            exit(0);
        }
        printf("\n Vida do Client: %d\n", buff.vida_inimigo);    

        printf("\n Server-> Vida: %d", vida);
        //printf("\n Server-> Mana: %d", mana);

        buff.vida_inimigo = vida;

        printf("\n\n %s", info_server);

        scanf("%d", &aux1);
        printf(" \n Server->");

        switch (aux1)
        {
        case 1:
            printf(" %s", info_attack_1_server);
                mana = mana - 25;
                strcpy(buff.identify, "Rodar exe");
            break;
        case 2:
            printf(" %s", info_attack_2_server);
                mana = mana - 25;
                strcpy(buff.identify, "Abrir Google Chrome");
            break;
        case 3:
            printf(" %s", info_attack_3_server);
                mana = mana - 25;
                strcpy(buff.identify, "Abrir Android Studio");
            break;
        case 4:
            printf(" %s", info_reload);
                mana = mana + 25;
            break;
        case 5:
            printf(" Saindo do programa\n");
            exit(0);
            break;
        default:
            exit(0);
            break;
        }

        buff.vida_inimigo = vida;
        sprintf(vida_inimigo_conv,"%d",buff.vida_inimigo);
        write(writefd, buff.identify, 40);
        write(writefd, vida_inimigo_conv, 40);

        sem_wait(&mutex);
        printf("ENTROU AQUI\n");
        lock = 1;
        printf("LOCK: %d\n", lock);
        sem_post(&mutex);
    }
} // Fim da Funcao Server

// Controle dos ataques
// Ataques do Client
int attack(char ident[40]){

    if (strcmp(ident, "Deadlock") == 0){
        printf("\n Server ->");
        if(rand() % 100 > 40){
            printf("%s", info_deadlock);
                return 10;
        }
        else{
            printf("%s", miss_deadlock);
                return 0;
        }
    }
    else if (strcmp(ident, "Divisao por zero") == 0){
        printf("\n Server ->");
        if (rand() % 100 > 50){
            printf("%s", info_div_zero);
                return 15;
        }
        else{
            printf("%s", miss_div_zero);
                return 0;
        }
    }
    else if (strcmp(ident, "Tijolada na CPU") == 0){
        printf("\n Server ->");
        if (rand() % 100 > 60){
            printf("%s", info_tijolo);
                return 20;
        }
        else{
            printf("%s", miss_tijolo);
                return 0;
        }
    }
    //Ataque do Server

    else if(strcmp(ident, "Rodar exe") == 0){
        printf("\n Client ->");
        if(rand() % 100 > 60){
            printf("%s", info_exe);
                return 25;
        }
        else{
            printf("%s", miss_exe);
                return 0;
        }
    }
    else if(strcmp(ident, "Abrir Google Chrome") == 0){
        printf("\n Client ->");

        if(rand() % 100 > 50){
            printf("%s", info_chrome);
                return 10;
        }
        else{
            printf("%s", miss_chrome);
                return 0;
        }
    }
    else if(strcmp(ident, "Abrir Android Studio") == 0){
        printf("\n Client ->");

        if(rand() % 100 > 50){
            printf("%s", info_android);
                return 15;
        }
        else{
            printf("%s", miss_android);
                return 0;
        }
    }
    else if(strcmp(ident, "Recarregar") == 0){
        printf("Recarregando\n");
            return 0;
    }
    else{
        printf("Ataque invalido\n");
            return 0;
    }
}
// Fim da função de controle dos ataques

void *count_time(void *arg){
    for(int i = 1; i <= 20; i++){
        sem_wait(&mutex);
        if(lock == 0){
            //printf("Tempo1: %d\n", i);
            sleep(1);
            sem_post(&mutex);
        }       
        else
            pthread_exit(NULL);
            sem_post(&mutex);
    }
    printf("Tempo esgotado, babaca\n");
    pthread_exit(NULL);
}
