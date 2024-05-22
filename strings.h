/* Descrição: Arquivo de cabeçalho com as strings longas utilizadas no jogo!! */ 

#include <stdio.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


char info_client[270] = "Ataque: \n 1 - Gerar deadlock - 10 de dano - 60 de chance de acerto\n 2 - Dividir por zero - 15 de dano - 50 de chance de acerto\n 3 - Jogar um tijolo na CPU - 20 de dano - 40 de chance de acerto \n 4 - Recarregar\n 5 - Sair \n\n";
char info_server[269] = "Ataque: \n 1 - Rodar um programa .exe - 25 de dano - 40 de chance de acerto\n 2 - Abrir Google Chrome no Processo inimigo - 10 de dano - 50 de chance de acerto\n 3 - Abrir Android Studio - 15 de dano - 50 de chance de acerto\n 4 - Recarregar\n 5 - Sair \n\n";

// Ataques do cliente 
char info_attack_1[50] = "Gerando deadlock no processo inimigo";
char info_attack_2[52] = "Dividindo por zero no processo inimigo";
char info_attack_3[60] = "Jogando um tijolo na CPU do processo inimigo";

// Ataques do Server
char info_attack_1_server[44] = "Rodando exe no processo inimigo";
char info_attack_2_server[39] = "Abrindo o Google Chrome...";
char info_attack_3_server[55] = "Abrindo Android Studio no processo inimigo";

char info_reload[15] = "recarregando\n";

// Respostas Client
char info_deadlock[49] = " Tomei um Deadlock na boca\n";
char miss_deadlock[54] = " *Miss* Errou o ataque, trouxa!\n";

char info_div_zero[56] = " Deu pau em tudo, meu BCP sumiu!!\n";
char miss_div_zero[52] = " *Miss* Não vou dividir nada!\n";

char info_tijolo[43] = " Tomei uma tijolada na CPU, ai\n";
char miss_tijolo[38] = " *Miss* Esquivo, esquivo!\n";

// Respostas Server
char info_exe[18] = " Credo, Windows!\n";
char miss_exe[55] = " *Miss* Deus me livre, executar programa de Windows!\n";

char info_chrome[26] = " Nããããão, minha RAM!\n";
char miss_chrome[38] = " *Miss* NÃO. Minha RAM é só minha!\n";

char info_android[33] = " Estou sem recursos, meu Deus!\n";
char miss_android[24] = " *Miss* Errou, bobão!\n";




void color_client(){
	printf(ANSI_COLOR_YELLOW "\n Client -> " ANSI_COLOR_RESET);
}

void color_server(){
	printf(ANSI_COLOR_RED "\n Server -> " ANSI_COLOR_RESET);
}
