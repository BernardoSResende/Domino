#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include<stdbool.h>
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

	struct mesa *M = NULL;
	struct mesa *jogador1 = NULL;
	struct mesa *jogador2 = NULL;
	struct mesa *jogador3 = NULL;
	struct mesa *jogador4 = NULL;


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

struct mesa *nova_mao(){
	struct mesa *temp = NULL;
	temp = (mesa*) calloc(1, sizeof(struct mesa));
	return temp;
};

void distribuir_peca(struct mesa *m, struct peca *p){
	if(m){ 
		if(p){
			m->pecas = (peca**) realloc(m->pecas, (m->total+1)*sizeof(struct peca*) );
			m->pecas[m->total] = p;
			m->total++;
			m->primeiro = m->pecas[0];
			m->ultimo = m->pecas[m->total-1];
		}
		else{
			printf("erro na peca :( \n");
		}
	}
	else{
		printf("erro no recipiente :( \n");
	}
};

struct peca *retirar_indice(struct mesa *m, int indice){
	int i = indice;
	struct peca *temporario = NULL;

	temporario = m->pecas[indice];
	while(i<m->total - 1){
		m->pecas[i] = m->pecas[i+1];
		i++;
	}
	m->pecas[i] = NULL;

	m->pecas = (peca**)realloc(m->pecas, sizeof(struct peca*));
	m->total--;
	if(m->total > 0){
		m->primeiro = m->pecas[0];
		m->ultimo = m->pecas[m->total-1];
	}
	return temporario;
};	 

void imprimir_peca(struct peca *p){
	printf("Peca: [%i|%i]\n", p->numeros[0],p->numeros[1]);

};

int buscar_valor(struct mesa *m, int valor){
	int v = -1;
	struct peca *atual = NULL;
	bool encontrado = false;
	int cont=0;

	while(!encontrado && cont < m->total){
		atual =m->pecas[cont];
		if(atual->numeros[0] == valor||atual->numeros[1] == valor){
			v = cont;
			encontrado = true;
		}
		cont++;
	}
	return v; 
};

int main(){
	bool encontrado;
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

	jogador1 = nova_mao();
	jogador2 = nova_mao();
	jogador3 = nova_mao();
	jogador4 = nova_mao();

	Cont1=0;
	printf("As pecas do Jogador 1 \n");
	while(Cont1<7){
		distribuir_peca(jogador1, &pecas[ordem[Cont1]]);
		imprimir_peca(&pecas[ordem[Cont1]]);
		Cont1++;
	}
	printf("As pecas do Jogador 2 \n");
	while(Cont1<14){
		distribuir_peca(jogador2, &pecas[ordem[Cont1]]);
		imprimir_peca(&pecas[ordem[Cont1]]);
		Cont1++;
	}
	printf("As pecas do Jogador 3 \n");
	while(Cont1<21){
		distribuir_peca(jogador3, &pecas[ordem[Cont1]]);
		imprimir_peca(&pecas[ordem[Cont1]]);
		Cont1++;
	}
	printf("As pecas do Jogador 4 \n");
	while(Cont1<28){
		distribuir_peca(jogador4, &pecas[ordem[Cont1]]);
		imprimir_peca(&pecas[ordem[Cont1]]);
		Cont1++;
	}

	encontrado = buscar_valor(jogador1,1);
	if(encontrado != -1){
		printf("O jogador 1 tem o valor na posicao %i \n", encontrado);
	}
	else{
		printf("O jogador 1 nao tem o valor na posicao %i \n", encontrado);
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
