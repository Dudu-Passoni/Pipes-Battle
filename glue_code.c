#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXBUFF 1024 // numero de caract. do buffer



int main(){

int descritor, // usado para criar o processo filho pelo fork
    pipe1[2], // comunicacao pai -> filho
    pipe2[2]; // comunicacao filho -> pai

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
    else if (descritor >0) // PROCESSO PAI
    { 
        close(pipe1[0]); // fecha leitura no pipe1
        close(pipe2[1]); // fecha escrita no pipe2
        client(pipe2[0], pipe1[1]); // Chama CLIENTE no PAI
        close(pipe1[1]); // fecha pipe1
        close(pipe2[0]); // fecha pipe2
            exit(0);
    } // FIM DO PROCESSO PAI

    else // PROCESSO FILHO
    { 
        close(pipe1[1]); // fecha escrita no pipe1
        close(pipe2[0]); // fecha leitura no pipe2
        server(pipe1[0], pipe2[1]); // Chama SERVIDOR no FILHO
        close(pipe1[0]); // fecha leitura no pipe1
        close(pipe2[1]); // fecha escrita no pipe2
        exit(0);
    } // FIM DO PROCESSO FILHO
} // FIM DO MAIN
/*
-----------------------------------------------------------------------------------
------------------------
Funcao Client: Executa no processo PAI
Envia o nome do arquivo para o FILHO
Recebe os dados do FILHO e imprime na tela
-----------------------------------------------------------------------------------
------------------------ */
void client (readfd, writefd)
    int readfd, // leitura do pipe2[0]
        writefd;// escrita no pipe1[1]
{
    struct str{
        char escritas[MAXBUFF];
        int vida;
        int mana;

    };
    struct str buff;
    int aux = 0;
    while(1)
    {
        printf("\n Client->\n Ataque: \n 1 - Gerar deadlock \n 2 - Dividir por zero \n 3 - Jogar um tijolo na CPU \n 4 - Sair \n\n"); 
            scanf("%d", &aux);
        printf(" \n Client->");
        switch (aux)
        {
        case 1:
            printf(" Gerando deadlock no processo inimigo\n");
                strcpy(buff.escritas, "Tomei um Deadlock na boca\n");
            break;
        case 2:
            printf(" Dividindo por zero no processo inimigo\n");
                strcpy(buff.escritas, "Dividi por zero e deu pau em tudo\n");
            break;
        case 3:
            printf(" Jogando um tijolo na CPU do processo inimigo\n");
                strcpy(buff.escritas, "Tomei uma tijolada na CPU, ai\n");
            break;
        case 4:
            printf(" Saindo do programa\n");
            exit(0);
            break;
        default:
            break;
        }
        //gets(buff);
            write(writefd, buff.escritas, 40);
            read(readfd,buff.escritas,40);
        printf(" \n Client <- %s",buff.escritas);
    }
} // Fim da Funcao CLIENT

/*
-----------------------------------------------------------------------------------
------------------------
Funcao Server: Executa no processo FILHO
Abre o arquivo solicitado e envia seu conteudo
para o PAI
-----------------------------------------------------------------------------------
------------------------ */
void server(readfd, writefd)
    int readfd, // leitura do pipe1[0]
        writefd; // escrita no pipe2[1]
{
    struct str{
        char escritas[MAXBUFF];
        int vida;
        int mana;
    };
    struct str buff;
    int n, fd;
    int aux1 =0;
    while(1)
    {
            read(readfd,buff.escritas,40);
        printf(" \n Server<- %s",buff);
        printf("\n Server->\n Ataque: \n 1 - Rodar um programa .exe \n 2 - Abrir Google Chrome no Processo inimigo \n 3 - Abrir Android Studio \n 4 - Sair \n\n");
            scanf("%d", &aux1);
        switch (aux1)
        {
        case 1:
            printf(" Rodando exe no processo inimigo\n");
                strcpy(buff.escritas, "Credo, Windows!\n");
            break;
        case 2:
            printf(" Abrindo o Google Chrome...\n");
                strcpy(buff.escritas, "Nããããão, minha RAM!\n");
            break;
        case 3:
            printf(" Abrindo Android Studio no processo inimigo\n");
                strcpy(buff.escritas, "Estou sem recursos, meu Deus!\n");
            break;
        case 4:
            printf(" Saindo do programa\n");
            exit(0);
            break;
        default:
            break;
        }
        printf(" \n Server->");
        //gets(buff);
            write(writefd, buff.escritas, 40);
    }
} // Fim da Funcao Server
