#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXBUFF 1024 // numero de caract. do buffer

void client (int readfd, int writefd);
void server(int readfd, int writefd);
int atack(char ident[40]);


int main(int argc, char **argv){

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
        char identify[MAXBUFF];
    };
    struct str buff;
    int aux = 0;
    int vida = 100;
    int mana = 100;

    while(1)
    {
        printf(" \n Client-> Mana: %d\n", mana);
        printf("\n Client->\n Ataque: \n 1 - Gerar deadlock - 10 de dano - 60 de cahnce de acerto\n 2 - Dividir por zero - 5 de dano - 70 de chance de acerto\n 3 - Jogar um tijolo na CPU - 20 de dano - 40 de chance de acerto \n 4 - Recarregar\n 5 - Sair \n\n"); 

        scanf("%d", &aux);
        printf(" \n Client->");

        switch (aux)
        {
        case 1:
            printf(" Gerando deadlock no processo inimigo\n");
                mana = mana - 25;
                strcpy(buff.identify, "Deadlock");
            break;
        case 2:
            printf(" Dividindo por zero no processo inimigo\n");
                mana = mana - 25;
                strcpy(buff.identify, "Divisao por zero");
            break;
        case 3:
            printf(" Jogando um tijolo na CPU do processo inimigo\n");
                mana = mana - 25;
                strcpy(buff.identify, "Tijolada na CPU");
            break;
        case 4:
            printf(" Recarregando\n");
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
        write(writefd, buff.identify, 40);
        read(readfd,buff.identify,40);
        
        int dano = atack(buff.identify);
        vida = vida - dano;

        printf("\n Client->");
        printf(" Vida: %d", vida);

        if(vida <= 0){
            printf("Client perdeu :(\n");
            exit(0);
        }

        printf("\n Client->");
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
        char identify[MAXBUFF];
        int mana;
    };
    struct str buff;
    int aux1 =0;
    int vida = 100;
    int mana = 100;

    while(1)
    {
        read(readfd,buff.identify,40);

        int dano = atack(buff.identify);
        vida = vida - dano;
        
        if(vida <= 0){
            printf("Client perdeu :(\n");
            exit(0);
        }
        else 
        {
        printf("\n Server->");
        printf(" Vida: %d", vida);
        }

        printf("\n Server->");
        printf(" Mana: %d\n", mana);


        printf("\n Server->\n Ataque: \n 1 - Rodar um programa .exe - 25 de dano - 40 de chance de acerto\n 2 - Abrir Google Chrome no Processo inimigo - 10 de dano - 70 de chance de acerto\n 3 - Abrir Android Studio - 15 de dano - 50 de chance de acerto\n 4 - Recarregar\n 5 - Sair \n\n");

        scanf("%d", &aux1);
        printf(" \n Server->");

        switch (aux1)
        {
        case 1:
            printf(" Rodando exe no processo inimigo\n");
                mana = mana - 25;
                strcpy(buff.identify, "Rodar exe");
            break;
        case 2:
            printf(" Abrindo o Google Chrome...\n");
                mana = mana - 25;
                strcpy(buff.identify, "Abrir Google Chrome");
            break;
        case 3:
            printf(" Abrindo Android Studio no processo inimigo\n");
                mana = mana - 25;
                strcpy(buff.identify, "Abrir Android Studio");
            break;
        case 4:
            printf(" Recarregando\n");
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

        write(writefd, buff.identify, 40);
    }
} // Fim da Funcao Server
/*
____________________________________________________________________________________________________________________
____________________________________________________________________________________________________________________
*/

int atack(char ident[40]){

    if (strcmp(ident, "Deadlock") == 0){
        printf("\n Server ->");
        if(rand() % 100 > 40){
            printf(" Tomei um Deadlock na boca\n");
                return 10;
        }
        else{
            printf(" *Miss* Errou o ataque, trouxa!\n");
                return 0;
        }
    }
    else if (strcmp(ident, "Divisao por zero") == 0){
        printf("\n Server ->");
        if (rand() % 100 > 30){
            printf(" Deu pau em tudo, meu BCP sumiu!!\n");
                return 5;
        }
        else{
            printf(" *Miss* Não vou dividir nada!\n");
                return 0;
        }
    }
    else if (strcmp(ident, "Tijolada na CPU") == 0){
        printf("\n Server ->");
        if (rand() % 100 > 60){
            printf(" Tomei uma tijolada na CPU, ai\n");
                return 20;
        }
        else{
            printf(" *Miss* Esquivo, esquivo!\n");
                return 0;
        }
    }
    //_______________________________________________________________
    //Ataque do proximo sub-processo

    else if(strcmp(ident, "Rodar exe") == 0){
        printf("\n Client ->");
        if(rand() % 100 > 60){
            printf(" Credo, Windows!\n");
                return 25;
        }
        else{
            printf(" *Miss* Deus me livre, executar programa de Windows!\n");
                return 0;
        }
    }
    else if(strcmp(ident, "Abrir Google Chrome") == 0){
        printf("\n Client ->");

        if(rand() % 100 > 30){
            printf(" Nããããão, minha RAM!\n");
                return 10;
        }
        else{
            printf(" *Miss* NÃO. Minha RAM é só minha!\n");
                return 0;
        }
    }
    else if(strcmp(ident, "Abrir Android Studio") == 0){
        printf("\n Client ->");

        if(rand() % 100 > 50){
            printf(" Estou sem recursos, meu Deus!\n");
                return 15;
        }
        else{
            printf(" *Miss* Errou, bobão!\n");
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


//_______________________________________________________________________
