/*
 * Constantes, Strings longas e funções de cunho visual utilizadas no programa
 */ 

#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


char *info_client = "Ataque: Escolha um número para realizar um ataque...\n\n 1 - Gerar deadlock - 10 de dano - 60 de chance de acerto\n 2 - Dividir por zero - 15 de dano - 50 de chance de acerto\n 3 - Jogar um tijolo na CPU - 20 de dano - 40 de chance de acerto \n 4 - Sair \n\n\0";
char *info_server = "Ataque: Escolha um número para realizar um ataque...\n\n 1 - Rodar um programa .exe - 25 de dano - 40 de chance de acerto\n 2 - Abrir Google Chrome no Processo inimigo - 10 de dano - 50 de chance de acerto\n 3 - Abrir Android Studio - 15 de dano - 50 de chance de acerto\n 4 - Sair \n\n\0";

// Ataques do cliente 
char *info_attack_1 = "Gerando deadlock no processo inimigo\0";
char *info_attack_2 = "Dividindo por zero no processo inimigo\0";
char *info_attack_3 = "Jogando um tijolo na CPU do processo inimigo\0";

// Ataques do Server
char *info_attack_1_server = "Rodando exe no processo inimigo\0";
char *info_attack_2_server = "Abrindo o Google Chrome...\0";
char *info_attack_3_server = "Abrindo Android Studio no processo inimigo\0";

char *info_reload = "recarregando\n\0";

// Respostas Client
char *info_deadlock = " Tomei um Deadlock na boca\n\0";
char *miss_deadlock = " *Miss* Errou o ataque, trouxa!\n\0";

char *info_div_zero = " Deu pau em tudo, meu BCP sumiu!!\n\0";
char *miss_div_zero = " *Miss* Não vou dividir nada!\n\0";

char *info_tijolo = " Tomei uma tijolada na CPU, ai\n\0";
char *miss_tijolo = " *Miss* Esquivo, esquivo!\n\0";

// Respostas Server
char *info_exe = " Credo, Windows!\n\0";
char *miss_exe = " *Miss* Deus me livre, executar programa de Windows!\n\0";

char *info_chrome = " Nããããão, minha RAM!\n\0";
char *miss_chrome = " *Miss* NÃO. Minha RAM é só minha!\n\0";

char *info_android = " Estou sem recursos, meu Deus!\n\0";
char *miss_android = " *Miss* Errou, bobão!\n\0";

//Functions

void color_client(){
	printf(ANSI_COLOR_YELLOW "\n Client -> " ANSI_COLOR_RESET);
}

void color_server(){
	printf(ANSI_COLOR_RED "\n Server -> " ANSI_COLOR_RESET);
}

void clear_screen(){
  printf("\e[1;1H\e[2J");
}

void welcome_screen(){
	  printf("__        __   _                            _             \n");
    printf("\\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___       \n");
    printf(" \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\      \n");
    printf("  \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) |     \n");
    printf(" __\\_/\\_/ \\___|_|\\___\\___/|_| |_|_|_|\\___|_|\\__\\___/      \n");
    printf("|  _ \\(_)_ __   ___  ___      | __ )  __ _| |_| |_| | ___ \n");
    printf("| |_) | | '_ \\ / _ \\/ __|_____|  _ \\ / _` | __| __| |/ _ \\\n");
    printf("|  __/| | |_) |  __/\\__ \\_____| |_) | (_| | |_| |_| |  __/\n");
    printf("|_|   |_| .__/ \\___||___/     |____/ \\__,_|\\__|\\__|_|\\___|\n");
    printf("        |_|                                              \n");
	  printf("\n");
	  printf("Pressione qualquer tecla para continuar\n");
    getchar();
	  //clear_screen();
    system("clear");
}

void client_screen(){
    printf(ANSI_COLOR_YELLOW);
	  printf("  ____ _ _            _   \n");
    printf(" / ___| (_) ___ _ __ | |_ \n");
    printf("| |   | | |/ _ \\ '_ \\| __|\n");
    printf("| |___| | |  __/ | | | |_ \n");
    printf(" \\____|_|_|\\___|_| |_|\\__|\n");
    printf(ANSI_COLOR_RESET);
}

void server_screen(){
    printf(ANSI_COLOR_RED);
	  printf(" ____                           \n");
    printf("/ ___|  ___ _ ____   _____ _ __ \n");
    printf("\\___ \\ / _ \\ '__\\ \\ / / _ \\ '__|\n");
    printf(" ___) |  __/ |   \\ V /  __/ |   \n");
    printf("|____/ \\___|_|    \\_/ \\___|_|   \n");
    printf(ANSI_COLOR_RESET);
}

void game_over(){ // A coisa mais dificil da história é sair desse programa de um jeito correto!
	//system("clear");
    clear_screen();
	  printf("  ____                         ___                 \n");
    printf(" / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __ \n");
    printf("| |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n");
    printf("| |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |   \n");
    printf(" \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|   \n");
	  printf("Pressione CTRL + C para sair \n");
	  return;
}


void client_presentation(int vida, int vida_inimigo){
        client_screen();
        color_client();
	      printf("Vida do "ANSI_COLOR_RED"Server: %d\n"ANSI_COLOR_RESET, vida_inimigo);
	
	      color_client();
        printf("Vida: %d", vida);
	
	      color_client();
        printf("%s", info_client); 

        color_client();

}

void server_presentation(int vida, int vida_inimigo){
  server_screen();

        color_server();
        printf(" Vida do "ANSI_COLOR_YELLOW"Client: %d\n"ANSI_COLOR_RESET, vida_inimigo);    
        vida_inimigo = vida;   // Recebe a vida do inimigo

        color_server();
        printf(" Vida: %d", vida);

        color_server();
        printf("%s", info_server);
        
        //sem_wait(&semaphore);

        color_server();
 
}
