#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTD_VAGAS 5
#define TAM_PLACA 10
#define INICIALIZACAO_PILHA -1

typedef struct {
    char placa[TAM_PLACA];
    int qtdManobras;
} Carros[QTD_VAGAS];

typedef struct {
    int topo;
    Carros carros;
} Estacionamento;

typedef struct {
    int topo;
    Carros carros;
} PilhaDeManobras;

void entrada(char *movimentacoes, Estacionamento *alameda) {
    if (alameda->topo == QTD_VAGAS - 1) {
        printf("\nNão há vagas na alameda. O carro de placa %s saiu sem entrar no estacionamento.\n", movimentacoes);
        
    } else if (alameda->topo < QTD_VAGAS - 1) {
        alameda->topo++;
        strncpy(alameda->carros[alameda->topo].placa, movimentacoes, sizeof(alameda->carros[alameda->topo].placa) - 1);
        alameda->carros[alameda->topo].placa[sizeof(alameda->carros[alameda->topo].placa) - 1] = '\0';
        printf("\n%s entrou no estacionamento.\n", alameda->carros[alameda->topo].placa);
        alameda->carros[alameda->topo].qtdManobras = 0;
        
    }
}

void saida(char *movimentacoes, Estacionamento *alameda, PilhaDeManobras *manobrando) {
    if (alameda->topo == -1) {
        printf("\nEste carro não está aqui. O estacionamento está vazio.\n");
        
    } else {
        
        while (alameda->topo >= 0) {
            if (strcmp(alameda->carros[alameda->topo].placa, movimentacoes) == 0) {
                if(alameda->carros[alameda->topo].qtdManobras == 1) {
                    printf("\nO carro de placa %s saiu da alameda depois de realizar 1 manobra.\n", movimentacoes);
                    alameda->topo--;
                    break;
                }
                
                printf("\nO carro de placa %s saiu da alameda depois de realizar %d manobras.\n", movimentacoes, alameda->carros[alameda->topo].qtdManobras);
                alameda->topo--;
                break;
                
            } else {
                manobrando->topo++;
                strcpy(manobrando->carros[manobrando->topo].placa, alameda->carros[alameda->topo].placa);
                alameda->carros[alameda->topo].qtdManobras++;
                manobrando->carros[manobrando->topo].qtdManobras = alameda->carros[alameda->topo].qtdManobras;
                alameda->topo--;
                
            }
        }
        
        while (manobrando->topo >= 0) {
            alameda->topo++;
            strcpy(alameda->carros[alameda->topo].placa, manobrando->carros[manobrando->topo].placa);
            alameda->carros[alameda->topo].qtdManobras = manobrando->carros[manobrando->topo].qtdManobras;
            manobrando->topo--;
            
        }
    }
}

void cortarString(char *movimentacoes) {
    memmove(movimentacoes, movimentacoes + 2, strlen(movimentacoes + 2) + 1);
}

int main() {
    
    Estacionamento alameda;
    alameda.topo = INICIALIZACAO_PILHA;

    PilhaDeManobras manobrando;
    manobrando.topo = INICIALIZACAO_PILHA;

    char movimentacoes[][TAM_PLACA] = {"E ABC1234", "E DEF1234", "E GHI1234", "E JKL1234", "E MNO1234", "E PQR1234", "S ABC1234", "S DEF1234", "S GHI1234", "S JKL1234", "S MNO1234", "S MNO1234"};

    for (int i = 0; i < 12; i++) {
        
        if (movimentacoes[i][0] == 'E') {
            cortarString(movimentacoes[i]);
            entrada(movimentacoes[i], &alameda);
            
        } else if (movimentacoes[i][0] == 'S') {
            cortarString(movimentacoes[i]);
            saida(movimentacoes[i], &alameda, &manobrando);
            
        }
    }

    return 0;
}
