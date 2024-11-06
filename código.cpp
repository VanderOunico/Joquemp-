#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

// Função para exibir o resultado de uma rodada

const char* resultado_rodada(int jogador, int computador) {
    if (jogador == computador) {
        return "Empate";
    } else if ((jogador == 1 && computador == 3) || 
               (jogador == 2 && computador == 1) || 
               (jogador == 3 && computador == 2)) {
        return "Vitória";
    } else {
        return "Derrota";
    }
}

// Função para jogar o Joquempô
void jogar_joquempo() {
    int rodadas, escolha, computador, total_vitorias = 0;
    int total_rodadas_ganhas = 0;
    int vitorias_consecutivas = 0, maior_sequencia_vitorias = 0;
 	int exibir; // Variável para controlar se o computador deve exibir a escolha
 
    printf("Bem-vindo ao jogo de Joquempô!\n");
    printf("Quantas rodadas você quer jogar? ");
    scanf("%d", &rodadas);
	printf("\nDeseja exibir o que o computador escolheu?\nSim = 1\nNão = 2\nEscolha: ");
    scanf("%d", &exibir);
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    for (int i = 1; i <= rodadas; i++) {
        printf("\nRodada %d:\n", i);

        int vitorias_rodada = 0; // Contador de vitórias para a rodada
        int derrotas_rodada = 0;  // Contador de derrotas para a rodada

        // Loop para a mesma rodada
       while (1) {
            printf("Opções:\n 1. Pedra\n2. Papel\n3. Tesoura\n0 para sair\n\nEscolha: ");
            scanf("%d", &escolha);

            if (escolha == 0) { // Opção para sair do jogo
                printf("\nTotal de vitórias no torneio: %d\n", total_vitorias);
                return; // Sai do jogo
            }

            if (escolha < 1 || escolha > 3) {
                printf("\nEscolha inválida! Tente novamente.\n");
                continue;
            }

		   computador = rand() % 3 + 1; // Gera escolha aleatória do computador (1 a 3)
            if (exibir == 1) {
                printf("\nComputador escolheu: %s\n", computador == 1 ? "Pedra" : computador == 2 ? "Papel" : "Tesoura");
}
            const char* resultado = resultado_rodada(escolha, computador);
            printf("\nResultado: %s\n", resultado);

            if (resultado[0] == 'V') { // Vitória
                vitorias_rodada++;
                total_vitorias++;
                vitorias_consecutivas++;
                if (vitorias_consecutivas > maior_sequencia_vitorias) {
                    maior_sequencia_vitorias = vitorias_consecutivas;
                }
            } else if (resultado[0] == 'D') { // Derrota
                derrotas_rodada++;
                vitorias_consecutivas = 0;
            }

            printf("\nVitórias nesta rodada: %d\n", vitorias_rodada);
            printf("\nDerrotas nesta rodada: %d\n", derrotas_rodada);
            printf("\nMaior sequência de vitórias: %d\n", maior_sequencia_vitorias);
            
			char continuar;
            printf("\nDeseja continuar jogando nesta rodada? (s para continuar, n para passar para a próxima rodada): ");
            scanf(" %c", &continuar);
            if (continuar == 'n' || continuar == 'N') {
                break; // Sai para a próxima rodada
            }
        }
        // Verifica se a rodada foi ganha
        if (vitorias_rodada > derrotas_rodada) {
            total_rodadas_ganhas++;
            printf("\nVocê ganhou esta rodada!\n");
        } else {
            printf("\nVocê perdeu esta rodada.\n");
        }
    }

    printf("\nTotal de vitórias no torneio: %d\n", total_vitorias);
    printf("\nTotal de rodadas ganhas: %d\n", total_rodadas_ganhas);
}


int main() {
		setlocale(LC_ALL, "Portuguese");
    jogar_joquempo();
    return 0;
}
