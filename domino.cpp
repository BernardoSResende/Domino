#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "FilaInt.h"
#include "pilha.h"
 	
	 
	 
	 struct peca{
 		int numeros[2];	
	 };
	
	struct mesa{
		struct peca **pecas;
		struct peca *primeiro, *ultimo;
    	int total;	
	};
	
	struct peca *pecas = NULL;
	int ordem[28];
	
	  
	struct peca *criar_peca (int lado1, int lado2) {
	struct peca *nova = (peca*) calloc(sizeof(struct peca),1);
	nova-> numeros[0] = lado1;
	nova-> numeros[1] = lado2;
	return nova;
}	
	void aleatoriza() {
		int Cont1=0;
		int aux;
		int vetor[28];
		memset(&vetor,0,sizeof(int)*28);
		srand(time(NULL));
		while (Cont1<28){
			aux = rand() % 28;
			if(vetor[aux]==0){
				ordem[Cont1]= aux;
				Cont1++;
				vetor[aux]=1;
			}
		}
	} 	 
int main(){
	
	struct peca *temporario ;
	int Cont1 = 0, Cont2 = 0, Cont3 = 0;
	while (Cont1 <= 6){
		Cont2 = 0;
		while (Cont2 <= Cont1){
			pecas = (peca*) realloc(pecas, (Cont3+1)*sizeof(struct peca));
			temporario = criar_peca(Cont1, Cont2);
			memcpy(&pecas[Cont3],temporario,sizeof(struct peca));
			free(temporario);
			Cont3++;
			Cont2++;
		}
	 Cont1++;
	}
	printf("Pecas desordenadas\n");
	aleatoriza();
	Cont1 = 0 ;
	while (Cont1 < 28){
		printf("Peca [%i | %i]\n", pecas[ordem[Cont1]].numeros[0], pecas[ordem[Cont1]].numeros[1]);
	    Cont1++;
	}
	return 0;
}

	
	
	
	
//	printf("Bem vindo ao domino, insira o nome do primeiro jogador\n");
//	scanf(" %s", jogador1.Nome);
//	system("cls");
//	printf("Bem vindo(a), %s! Agora insira o nome do segundo jogador\n",jogador1.Nome);
//	scanf(" %s", jogador2.Nome);
//	system("cls");
//	printf("Bem vindo(a), %s! Agora insira o nome do terceiro jogador\n",jogador2.Nome);
//	scanf(" %s", jogador3.Nome);
//	system("cls");
//	printf("Bem vindo(a), %s! Agora insira o nome do quarto jogador\n",jogador3.Nome);
//	scanf(" %s", jogador4.Nome);
//	system("cls");
//	printf("Bem vindo(a), %s",jogador4.Nome);	
	
// return 0;
//}
