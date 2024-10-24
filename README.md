# Pipes-Battle

Batalha entre dois sub-processos usando pipes para se comunicar.

Battle between two sub-processes using pipes to comunicate.
##
![Screenshot from 2024-05-30 21-30-56](https://github.com/Dudu-Passoni/Pipes-Battle/assets/115907714/ab69bc36-8b93-4564-baa4-aab89f8ab787)
##
Rodar no linux: 

To run on linux:
&nbsp;
```
gcc -o PipesBattle pipesbattle.c -pthread
./PipesBattle
```
Or
```
chmod u+x makefile.sh
./makefile.sh
```
#
Rodar no windows

To run on windows
```
it doesn't :)
Não roda :(
```
#
Pipes-Battle, é um jogo de batalha por turnos, onde dois sub-processos se atacam por meio de 
pipes. O jogo é composto por dois processos, o Client (Jogador 1) e Server(Jogador 2). 
Um processo ataca o outro mandando uma mensagem identificadora pelo pipe para o outro 
processo, onde é recebido. E então, a função attack é chamada, para retorna o dano causado 
pelo ataque, com a chance de erro e acerto de cada ataque. [Explicação Detalhada](#Explicação-Detalhada)
#
Pipes-Battle, is a turn-based battle game, where two sub-processes attack each other by means of pipes (inner process comunication). The game consists of two processes, the Client (Player 1) and Server (Player 2). One process attacks the other by sending an identifying message through the pipe to the other process, where it is received. And then, the attack function is called, to return the damage dealt by attack, with the chance of error and success of each attack.
# Explicação Detalhada

## Funcionamento do jogo

Dois jogadores (Client e Server), batalharão com ataques enviados através de pipes, atacando um em cada turno. O primeiro que zerar a vida do oponente vence.

Two players (Client and server), will battle with attacks sent by pipes, each one by round. The first to get the opponents health to zero is the winner.

## Tela de Inicio

![Screenshot from 2024-05-30 21-30-56](https://github.com/Dudu-Passoni/Pipes-Battle/assets/115907714/ab69bc36-8b93-4564-baa4-aab89f8ab787)

Assim que qualquer tecla for pressionada o jogo se inicia, e espera o jogador 1 (Client) escolher um ataque.

When any keys are pressed the game starts and wait for player number 1 (Client) to choose an attack.


![Screenshot from 2024-05-30 21-31-16](https://github.com/Dudu-Passoni/Pipes-Battle/assets/115907714/6ca57793-5527-4930-a5e7-3df049604985)

Assim que um ataque for escolhido, o oponente receberá um dano do ataque, diminuindo sua vida.

When the attack is choosed, the opponent will receive damage from the attack


![Screenshot from 2024-05-30 21-31-44](https://github.com/Dudu-Passoni/Pipes-Battle/assets/115907714/1cf36eee-a823-4797-b45e-122e79bf77e8)

Para cada ataque lançado, uma função é chamada e calcula a chance do ataque ser bem sucedido ou não.

Um ataque falho será indicado pelo identificador * miss * no começo da frase, junto com a frase de resposta do oponente.


For each attack launched, a function is called and calculates the chance of the attack being successful or not.

A failed attack will be indicated by the *miss* identifier at the beginning of the phrase, along with the opponent's response phrase.

![Screenshot from 2024-05-30 21-32-00](https://github.com/Dudu-Passoni/Pipes-Battle/assets/115907714/02bce7a9-8899-4ab5-a4c6-460ea0b5252a)
#
Quando um jogador fica muito tempo para realizar um ataque, uma thread que conta o tempo é chamada para alertar o jogador de fazer seu ataque.

When a player stays too long to perform an attack, a thread that counts down the time is called to alert the player to make their attack.

![Screenshot from 2024-05-30 21-32-41](https://github.com/Dudu-Passoni/Pipes-Battle/assets/115907714/14ebb828-94ad-4c96-88ab-abb114f961f8)

#
Quando algum jogador chega a 0 de vida, uma tela de game over aparece e o jogo termina.

When a player reaches 0 health, a game over screen appears and the game ends.

![Screenshot from 2024-05-30 21-37-43](https://github.com/Dudu-Passoni/Pipes-Battle/assets/115907714/3583fb7a-75a3-4e8a-9f28-eaf6a509384c)

#
