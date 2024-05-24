#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "strings.h"
#include "attack.h"

#define MAXBUFF 1024

sem_t semaphore;
pthread_mutex_t lock; 
int control_lock = 1; 

void client (int readfd, int writefd);
void server(int readfd, int writefd);
int attack(char ident[40]);
int handle_alarm(int signal);

void *count_time(void *arg);

int main(int argc, char **argv){


int descritor, // usado para criar o processo filho pelo fork
    pipe1[2], // comunicacao pai -> filho
    pipe2[2]; // comunicacao filho -> pai

//sem_init(&semaphore, 0, 0);
    
    clear_screen();
    welcome_screen();
 
    pthread_t thread1;
    pthread_create(&thread1, NULL, count_time, NULL);
    pthread_mutex_init(&lock, NULL);


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
        close(pipe1[0]); // fecha leitura no pipe1 close(pipe2[1]); // fecha escrita no pipe2
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
    pthread_mutex_destroy(&lock);
    return 0;
} 

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
    char vida_inimigo_conv[40];
    buff.vida_inimigo = 100;

    while(1)
    {
        pthread_mutex_lock(&lock);
        control_lock = 0;               // Controle do relogio de turnos
        pthread_mutex_unlock(&lock);
        	
        client_presentation(vida, buff.vida_inimigo);  // Tela de apresentação do Client
        control:
        scanf("%d", &aux);
        
        switch (aux)  // Switch case para controle dos ataques
        {
        case 1:
                strcpy(buff.identify, "Deadlock");
            break;
        case 2:
                strcpy(buff.identify, "Divisao por zero");
            break;
        case 3:
                strcpy(buff.identify, "Tijolada na CPU");
            break;
        case 4:
            game_over();
            break;
        default:
            printf("Escolha um número valido: ");
            goto control;
            break;
        }

        pthread_mutex_lock(&lock);
        control_lock = 1;
        pthread_mutex_unlock(&lock);

        buff.vida_inimigo = vida; // Recebe a vida do inimigo
        sprintf(vida_inimigo_conv,"%d",buff.vida_inimigo); //Converte a vida do inimigo para string

        write(writefd, buff.identify, 40);
	      write(writefd, vida_inimigo_conv, 40);

        read(readfd, buff.identify, 40);
	      read(readfd, vida_inimigo_conv, 40);
        
        buff.vida_inimigo = atoi(vida_inimigo_conv); // Volta a vida do inimigo para inteiro

        clear_screen();
        
        int dano = attack(buff.identify);
        vida = vida - dano;

        if(vida <= 0)
            game_over(); 
        
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
  	char vida_inimigo_conv[40];
    buff.vida_inimigo = 100;

    //pthread_t thread2;

    while(1)
    {
        pthread_mutex_lock(&lock);
        control_lock = 1;
        pthread_mutex_unlock(&lock);
        
        read(readfd, buff.identify, 40);
	      read(readfd, vida_inimigo_conv, 40);

        
        buff.vida_inimigo = atoi(vida_inimigo_conv);    
        
      	clear_screen();
        
        int dano = attack(buff.identify);
        vida = vida - dano;
        
        if(vida <= 0)
        game_over();
       
        server_presentation(vida, buff.vida_inimigo);
        control:
        scanf("%d", &aux1);
       // color_server();

        switch (aux1) // Switch case para controle dos ataques
        {
        case 1:
                strcpy(buff.identify, "Rodar exe");
            break;
        case 2:
                strcpy(buff.identify, "Abrir Google Chrome");
            break;
        case 3:
                strcpy(buff.identify, "Abrir Android Studio");
            break;
        case 4:
            game_over();
            break;
        default:
                printf("Escolha um número valido: ");
            goto control;
        }

        buff.vida_inimigo = vida;
        sprintf(vida_inimigo_conv,"%d",buff.vida_inimigo);
        write(writefd, buff.identify, 40);
        write(writefd, vida_inimigo_conv, 40);

        pthread_mutex_lock(&lock);
        control_lock = 0;
        pthread_mutex_unlock(&lock);
    }
} // Fim da Funcao Server

void *count_time(void *arg) {
    //thread:
    int count = 0;
    int previous_lock = control_lock;
    while (1) {
        if (control_lock != previous_lock) {
            count = 0;
            previous_lock = control_lock;
        }
        if (count <= 20) {
            sleep(1);
            //printf("Count: %d e lock: %d\n", count, control_lock);
            count++;
        } else {
            break;
        }
    }
    printf("\nFAÇA SEU ATAQUE!!!\n");
    
    //printf("AQUI TEM QUE IMPLEMENTAR, MANDAR UM SINAL PARA OS SUBPROCESSOS PARA PULAR O TURNO DELES!!!\n");
    void *count_time(void *arg); //Recursão para reiniciar a contagem (RIP GOTO)
    //goto thread;
    //pthread_exit(NULL);
}

    
    
