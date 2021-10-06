#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "FilaInt.h"
#include "pilha.h"

int main(){
	struct jogador{
		char Nome[30];
		int NumPecas;
		int peca1[2];
		int peca2[2];
		int peca3[2];
		int peca4[2];
		int peca5[2];
		int peca6[2];
		int peca7[2];
		
		
	};
	struct jogador jogador1;
	struct jogador jogador2;
	struct jogador jogador3;
	struct jogador jogador4;
	
	printf("Bem vindo ao domino, insira o nome do primeiro jogador\n");
	scanf(" %s", jogador1.Nome);
	system("cls");
	printf("Bem vindo(a), %s! Agora insira o nome do segundo jogador\n",jogador1.Nome);
	scanf(" %s", jogador2.Nome);
	system("cls");
	printf("Bem vindo(a), %s! Agora insira o nome do terceiro jogador\n",jogador2.Nome);
	scanf(" %s", jogador3.Nome);
	system("cls");
	printf("Bem vindo(a), %s! Agora insira o nome do quarto jogador\n",jogador3.Nome);
	scanf(" %s", jogador4.Nome);
	system("cls");
	printf("Bem vindo(a), %s",jogador4.Nome);
	
	
	
 return 0;
}
