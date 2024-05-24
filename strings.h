/*
 * Constantes e Strings lonags utilizadas no programa
 */ 

#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


char *info_client = "Ataque: \n 1 - Gerar deadlock - 10 de dano - 60 de chance de acerto\n 2 - Dividir por zero - 15 de dano - 50 de chance de acerto\n 3 - Jogar um tijolo na CPU - 20 de dano - 40 de chance de acerto \n 4 - Recarregar\n 5 - Sair \n\n";
char *info_server = "Ataque: \n 1 - Rodar um programa .exe - 25 de dano - 40 de chance de acerto\n 2 - Abrir Google Chrome no Processo inimigo - 10 de dano - 50 de chance de acerto\n 3 - Abrir Android Studio - 15 de dano - 50 de chance de acerto\n 4 - Recarregar\n 5 - Sair \n\n";

// Ataques do cliente 
char *info_attack_1 = "Gerando deadlock no processo inimigo";
char *info_attack_2 = "Dividindo por zero no processo inimigo";
char *info_attack_3 = "Jogando um tijolo na CPU do processo inimigo";

// Ataques do Server
char *info_attack_1_server = "Rodando exe no processo inimigo";
char *info_attack_2_server = "Abrindo o Google Chrome...";
char *info_attack_3_server = "Abrindo Android Studio no processo inimigo";

char info_reload[15] = "recarregando\n";

// Respostas Client
char *info_deadlock = " Tomei um Deadlock na boca\n";
char *miss_deadlock = " *Miss* Errou o ataque, trouxa!\n";

char *info_div_zero = " Deu pau em tudo, meu BCP sumiu!!\n";
char *miss_div_zero = " *Miss* Não vou dividir nada!\n";

char *info_tijolo = " Tomei uma tijolada na CPU, ai\n";
char *miss_tijolo = " *Miss* Esquivo, esquivo!\n";

// Respostas Server
char *info_exe = " Credo, Windows!\n";
char *miss_exe = " *Miss* Deus me livre, executar programa de Windows!\n";

char *info_chrome = " Nããããão, minha RAM!\n";
char *miss_chrome = " *Miss* NÃO. Minha RAM é só minha!\n";

char *info_android = " Estou sem recursos, meu Deus!\n";
char *miss_android = " *Miss* Errou, bobão!\n";

//Functions

void color_client(){
	printf(ANSI_COLOR_YELLOW "\n Client -> " ANSI_COLOR_RESET);
}

void color_server(){
	printf(ANSI_COLOR_RED "\n Server -> " ANSI_COLOR_RESET);
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
	system("clear");
}

void client_screen(){
	printf("  ____ _ _            _   \n");
    printf(" / ___| (_) ___ _ __ | |_ \n");
    printf("| |   | | |/ _ \\ '_ \\| __|\n");
    printf("| |___| | |  __/ | | | |_ \n");
    printf(" \\____|_|_|\\___|_| |_|\\__|\n");
}

void server_screen(){
	printf(" ____                           \n");
    printf("/ ___|  ___ _ ____   _____ _ __ \n");
    printf("\\___ \\ / _ \\ '__\\ \\ / / _ \\ '__|\n");
    printf(" ___) |  __/ |   \\ V /  __/ |   \n");
    printf("|____/ \\___|_|    \\_/ \\___|_|   \n");
}

void game_over(){ // A coisa mais dificil da história é sair desse programa de um jeito correto!
	//system("clear");
	printf("  ____                         ___                 \n");
    printf(" / ___| __ _ _ __ ___   ___   / _ \\__   _____ _ __ \n");
    printf("| |  _ / _` | '_ ` _ \\ / _ \\ | | | \\ \\ / / _ \\ '__|\n");
    printf("| |_| | (_| | | | | | |  __/ | |_| |\\ V /  __/ |   \n");
    printf(" \\____|\\__,_|_| |_| |_|\\___|  \\___/  \\_/ \\___|_|   \n");
	printf("Pressione CTRL + C para sair \nimplementar handler para saída automática!");
	getchar();
	exit(0);
}

void clear_screen(){
  printf("\e[1;1H\e[2J");
}
