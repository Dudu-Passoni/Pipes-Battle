/* 
 Descrição: Arquivo de cabeçalho com as strings longas utilizadas no jogo!!
*/

char info_client[250] = "\033[1;31mClient-> Ataque: \n 1 - Gerar deadlock - 10 de dano - 60 de chance de acerto\n 2 - Dividir por zero - 15 de dano - 50 de chance de acerto\n 3 - Jogar um tijolo na CPU - 20 de dano - 40 de chance de acerto \n 4 - Recarregar\n 5 - Sair \033[0m\n\n";
char info_server[269] = "Server-> Ataque: \n 1 - Rodar um programa .exe - 25 de dano - 40 de chance de acerto\n 2 - Abrir Google Chrome no Processo inimigo - 10 de dano - 50 de chance de acerto\n 3 - Abrir Android Studio - 15 de dano - 50 de chance de acerto\n 4 - Recarregar\n 5 - Sair \n";

// Ataques do cliente       
char info_attack_1[50] = "\033[1;31mGerando deadlock no processo inimigo \033[0m\n";
char info_attack_2[52] = "\033[1;31mDividindo por zero no processo inimigo \033[0m\n";
char info_attack_3[60] = "\033[1;31mJogando um tijolo na CPU do processo inimigo \033[0m\n";

// Ataques do Server
char info_attack_1_server[44] = "Rodando exe no processo inimigo\033[0m\n";
char info_attack_2_server[39] = "Abrindo o Google Chrome...\033[0m\n";
char info_attack_3_server[55] = "Abrindo Android Studio no processo inimigo\033[0m\n";

char info_reload[15] = "recarregando\n";

// Respostas Client
char info_deadlock[49] = " \033[1;31mTomei um Deadlock na boca\n";
char miss_deadlock[54] = " \033[1;31m*Miss* Errou o ataque, trouxa!\n";

char info_div_zero[56] = " \033[1;31mDeu pau em tudo, meu BCP sumiu!!\n";
char miss_div_zero[52] = " \033[1;31m*Miss* Não vou dividir nada!\n";

char info_tijolo[43] = " \033[1;31mTomei uma tijolada na CPU, ai\n";
char miss_tijolo[38] = " \033[1;31m*Miss* Esquivo, esquivo!\n";

// Respostas Server
char info_exe[18] = " Credo, Windows!\n";
char miss_exe[55] = " *Miss* Deus me livre, executar programa de Windows!\n";

char info_chrome[26] = " Nããããão, minha RAM!\n";
char miss_chrome[38] = " *Miss* NÃO. Minha RAM é só minha!\n";

char info_android[33] = " Estou sem recursos, meu Deus!\n";
char miss_android[24] = " *Miss* Errou, bobão!\n";
