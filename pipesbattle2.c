#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "ataques.c"

void *count_time(void *arg);

// Função do cliente
void client(int readfd, int writefd, struct Ataque *ataques) {

    printf("\nCLIENTE\n");

    int aux;

    while (1) {
        printf("\nEscolha um ataque (0, 1 ou 2): ");
        scanf("%d", &aux);

        if (aux < 0 || aux > 2) {
            printf("Ataque inválido.\n");
            continue;
        }

        write(writefd, &ataques[aux], sizeof(struct Ataque));

        // Aqui você pode implementar a leitura da resposta do servidor
        char resposta[40];

        read(readfd, &resposta, sizeof(resposta));

        printf("Resposta do servidor: %s\n", resposta);
    }
}

// Função do servidor
void server(int readfd, int writefd, struct Ataque *ataques) {

    printf("\nSERVIDOR\n");

    while (1) {
        // Recebe o ataque do cliente
        struct Ataque curAtaque;
        read(readfd, &curAtaque, sizeof(struct Ataque));

        printf("Ataque recebido: %s\n", curAtaque.nome);

        // Aqui você pode implementar a lógica de processamento do ataque e preparar uma resposta para o cliente
        char resposta[100] = "Ataque recebido com sucesso!";
        write(writefd, &resposta, sizeof(resposta));
    }
}

int main(int argc, char **argv) {
    int pipe1[2], pipe2[2];
    struct Ataque *ataques = instanciarAtaques();

    pthread_t thread;
    pthread_create(&thread, NULL, count_time, NULL);

    // Criando pipes
    if (pipe(pipe1) < 0 || pipe(pipe2) < 0) {
        perror("Erro na chamada PIPE");
        exit(EXIT_FAILURE);
    }

    // Fork para criar o processo filho
    pid_t pid = fork();
    if (pid < 0) {
        perror("Erro na chamada FORK");
        exit(EXIT_FAILURE);
    } else if (pid > 0) { // PROCESSO PAI
        close(pipe1[0]); // fecha leitura no pipe1
        close(pipe2[1]); // fecha escrita no pipe2

        client(pipe2[0], pipe1[1], ataques); // Chama CLIENTE no PAI

        close(pipe1[1]); // fecha pipe1
        close(pipe2[0]); // fecha pipe2
        
        exit(0);
    } else { // PROCESSO FILHO
        close(pipe1[1]); // fecha escrita no pipe1
        close(pipe2[0]); // fecha leitura no pipe2

        server(pipe1[0], pipe2[1], ataques); // Chama SERVIDOR no FILHO

        close(pipe1[0]); // fecha leitura no pipe1
        close(pipe2[1]); // fecha escrita no pipe2

        exit(0);
    }

    return 0;
}

void *count_time(void *arg){
    unsigned long int i;
    for(i = 0; i < 10000; i++){
        //system("clear");
        //printf("Tempo: %ld\n", i);
        //sleep(1);
    }

    pthread_exit(NULL);
}
