/*
*   Função para controlar os ataques do cliente e servidor
*   @param char ident[40] - Identificador do ataque
*   @return int - Dano causado pelo ataque
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int attack(char ident[40]){

    if (strcmp(ident, "Deadlock") == 0){
        printf(ANSI_COLOR_RED "\n Server -> " ANSI_COLOR_RESET);
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
        printf(ANSI_COLOR_RED "\n Server -> " ANSI_COLOR_RESET);
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
        printf(ANSI_COLOR_RED "\n Server -> " ANSI_COLOR_RESET);
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
        printf(ANSI_COLOR_YELLOW "\n Client -> " ANSI_COLOR_RESET);
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
        printf(ANSI_COLOR_YELLOW "\n Client -> " ANSI_COLOR_RESET);
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
        printf(ANSI_COLOR_YELLOW "\n Client -> " ANSI_COLOR_RESET);
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