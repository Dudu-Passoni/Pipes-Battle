# Pipes-Battle

Batalha entre dois sub-processos usando pipes para se comunicar.

## Funcionamento do jogo

Dois jogadores (Client e Server), batalharão com ataques enviados através de pipes, atacando um em cada turno. O primeiro que zerar a vida do oponente vence.

## Tela de Inicio

![Screenshot from 2024-05-30 21-30-56](https://github.com/Dudu-Passoni/Pipes-Battle/assets/115907714/ab69bc36-8b93-4564-baa4-aab89f8ab787)

Assim que qualquer tecla for pressionada o jogo se inicia, e espera o jogador 1 (Client) escolher um ataque.


![Screenshot from 2024-05-30 21-31-16](https://github.com/Dudu-Passoni/Pipes-Battle/assets/115907714/6ca57793-5527-4930-a5e7-3df049604985)

Assim que um ataque for escolhido, o oponente receberá um dano do ataque, diminuindo sua vida.


![Screenshot from 2024-05-30 21-31-44](https://github.com/Dudu-Passoni/Pipes-Battle/assets/115907714/1cf36eee-a823-4797-b45e-122e79bf77e8)

Para cada ataque lançado, uma função é chamada e calcula a chance do ataque ser bem sucedido ou não.

Um ataque falho será indicado pelo identificador * miss * no começo da frase, junto com a frase de resposta do oponente.

![Screenshot from 2024-05-30 21-32-00](https://github.com/Dudu-Passoni/Pipes-Battle/assets/115907714/02bce7a9-8899-4ab5-a4c6-460ea0b5252a)
#
Quando um jogador fica muito tempo para realizar um ataque, uma thread que conta o tempo é chamada para alertar o jogador de fazer seu ataque.

![Screenshot from 2024-05-30 21-32-41](https://github.com/Dudu-Passoni/Pipes-Battle/assets/115907714/14ebb828-94ad-4c96-88ab-abb114f961f8)

#
Quando algum jogador chega a 0 de vida, uma tela de game over aparece e o jogo termina.

![Screenshot from 2024-05-30 21-37-43](https://github.com/Dudu-Passoni/Pipes-Battle/assets/115907714/3583fb7a-75a3-4e8a-9f28-eaf6a509384c)


