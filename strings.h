/* Descrição: Arquivo de cabeçalho com as strings longas utilizadas no jogo!! */ 

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
