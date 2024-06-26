/* 
 * Pipes-Battle, é um jogo de batalha por turnos, onde dois sub-processos se atacam por meio de 
 * pipes. O jogo é composto por dois processos, o Client (Jogador 1) e Server(Jogador 2). 
 * Um processo ataca o outro mandando uma mensagem identificadora pelo pipe para o outro 
 * processo, onde é recebido. E então, a função attack é chamada, para retorna o dano causado 
 * pelo ataque, com a chance de erro e acerto de cada ataque.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//#include <semaphore.h>
#include "strings.h"
#include "attack.h"

#define MAXBUFF 1024

pthread_mutex_t lock; 
int control_lock = 1; 

void client (int readfd, int writefd);
void server(int readfd, int writefd);
int attack(char ident[40]);

void *count_time(void *arg); // Thread para contagem de tempo

int main(int argc, char **argv){


int descript, // usado para criar o processo filho pelo fork
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
    if ( (descript = fork()) <0)
    {
        printf("Erro na chamada FORK");
        exit(0);
    }
    else if (descript >0) // Processo pai
    { 

        close(pipe1[0]); // fecha leitura no pipe1 
        close(pipe2[1]); // fecha escrita no pipe2
        client(pipe2[0], pipe1[1]); // Chama Client no pai
        close(pipe1[1]); // fecha pipe1
        close(pipe2[0]); // fecha pipe2
        return 0;
    } // Fim do processo pai

    else // Processo filho
    { 
        close(pipe1[1]); // fecha escrita no pipe1
        close(pipe2[0]); // fecha leitura no pipe2
        server(pipe1[0], pipe2[1]); // Chama Server no filho
        close(pipe1[0]); // fecha leitura no pipe1
        close(pipe2[1]); // fecha escrita no pipe2
        return 0;
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
            return;
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

        write(writefd, buff.identify, 40); // Envia o ataque no pipe
	    write(writefd, vida_inimigo_conv, 40); // Envia sua vida, para o inimigo printar

        read(readfd, buff.identify, 40); // Recebe o ataque do inimigo
	    read(readfd, vida_inimigo_conv, 40); // Recebe a vida do inimigo
       
        buff.vida_inimigo = atoi(vida_inimigo_conv); // Volta a vida do inimigo para inteiro

        clear_screen();
        
        int dano = attack(buff.identify);
        vida = vida - dano;

        if(vida <= 0){
            game_over();
            return;
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
  	char vida_inimigo_conv[40];
    buff.vida_inimigo = 100;

    //pthread_t thread2;

    while(1)
    {
        pthread_mutex_lock(&lock);
        control_lock = 1;
        pthread_mutex_unlock(&lock);
        
        read(readfd, buff.identify, 40); // Recebe o ataque do inimigo
	    read(readfd, vida_inimigo_conv, 40); // Recebe a vida do inimigo

        
        buff.vida_inimigo = atoi(vida_inimigo_conv);    
        
      	clear_screen();
        
        int dano = attack(buff.identify);
        vida = vida - dano;
        
        if(vida <= 0){
            game_over();
            return;
        }
       
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
            return;
            break;
        default:
                printf("Escolha um número valido: ");
            goto control;
        }

        buff.vida_inimigo = vida; 
        sprintf(vida_inimigo_conv,"%d",buff.vida_inimigo); //Converte a vida do inimigo para string
        write(writefd, buff.identify, 40); // Envia o ataque no pipe
        write(writefd, vida_inimigo_conv, 40); // Envia sua vida, para o inimigo printar

        pthread_mutex_lock(&lock);
        control_lock = 0;               // Controle do relogio de turnos
        pthread_mutex_unlock(&lock);
    }
} // Fim da Funcao Server

void *count_time(void *arg) { // Thread para contar o tempos dos ataques e notificar o atacante
    thread:
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
    printf("\nFAÇA SEU ATAQUE...\n");
    goto thread; //GOTO para voltar para o começo da thread, recursão não funciona direito
    //pthread_exit(NULL);
}
