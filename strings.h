/* 
 Descrição: Arquivo de cabeçalho com as strings longas utilizadas no jogo!!
*/

char info_client[240] = "Client-> Ataque: \n 1 - Gerar deadlock - 10 de dano - 60 de chance de acerto\n 2 - Dividir por zero - 15 de dano - 50 de chance de acerto\n 3 - Jogar um tijolo na CPU - 20 de dano - 40 de chance de acerto \n 4 - Recarregar\n 5 - Sair \n\n";
char info_server[269] = "Server-> Ataque: \n 1 - Rodar um programa .exe - 25 de dano - 40 de chance de acerto\n 2 - Abrir Google Chrome no Processo inimigo - 10 de dano - 50 de chance de acerto\n 3 - Abrir Android Studio - 15 de dano - 50 de chance de acerto\n 4 - Recarregar\n 5 - Sair \n\n";

// Ataques do cliente       
char info_attack_1[40] = "Gerando deadlock no processo inimigo\n";
char info_attack_2[42] = "Dividindo por zero no processo inimigo\n";
char info_attack_3[47] = "Jogando um tijolo na CPU do processo inimigo\n";

// Ataques do Server
char info_attack_1_server[34] = "Rodando exe no processo inimigo\n";
char info_attack_2_server[29] = "Abrindo o Google Chrome...\n";
char info_attack_3_server[45] = "Abrindo Android Studio no processo inimigo\n";

char info_reload[15] = "recarregando\n";

// Respostas Client
char info_deadlock[29] = " Tomei um Deadlock na boca\n";
char miss_deadlock[34] = " *Miss* Errou o ataque, trouxa!\n";

char info_div_zero[36] = " Deu pau em tudo, meu BCP sumiu!!\n";
char miss_div_zero[32] = " *Miss* Não vou dividir nada!\n";

char info_tijolo[33] = " Tomei uma tijolada na CPU, ai\n";
char miss_tijolo[28] = " *Miss* Esquivo, esquivo!\n";

// Respostas Server
char info_exe[18] = " Credo, Windows!\n";
char miss_exe[55] = " *Miss* Deus me livre, executar programa de Windows!\n";

char info_chrome[26] = " Nããããão, minha RAM!\n";
char miss_chrome[38] = " *Miss* NÃO. Minha RAM é só minha!\n";

char info_android[33] = " Estou sem recursos, meu Deus!\n";
char miss_android[24] = " *Miss* Errou, bobão!\n";
