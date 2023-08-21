#include <stdio.h>
#define LIN 20
#define COL 30

int main(){
	int lugares[LIN][COL] = {0};
	float valorinteira, valormeia, valortotal;
	int fileira, assento, inteira = 0, meia = 0, cortesia = 0, ocupado = 0, continuar = 0, tipo;
	int i, j;
	
	printf("-- CINEMA --\n\nDigite o valor da entrada (inteira): ");
	scanf("%f", &valorinteira);
	
	valormeia = valorinteira/2;
	
	do{
		printf("\nDigite a fileira do assento a ser vendido (0-19): ");
		scanf("%i", &fileira);
		printf("Digite o assento a ser vendido (0 - 29): ");
		scanf("%i", &assento);
		
		if(fileira > LIN - 1 || assento > COL - 1 || fileira < 0 || assento < 0){
			printf("\nPor favor, escolha um assento existente.\n");
		} else{
			if(lugares[fileira][assento] == 1){
				printf("\nEsse lugar ja foi ocupado. Por favor, escolha outro.\n");
			} else{
				lugares[fileira][assento] = 1;
				
				printf("Digite o tipo do ingresso:\n1 - Normal\n2 - Meia entrada\n3 - Cortesia\n");
				do{
					scanf("%i", &tipo);
					if(tipo < 1 || tipo > 3){
						printf("Digite um tipo valido: ");
					}
				} while(tipo < 1 || tipo > 3);
				
				if(tipo == 1){
					inteira++;
				} else{
					if(tipo == 2){
						meia++;
					} else{
						cortesia++;
					}
				}
				
				printf("\nDeseja continuar? (Digite 1 para sim e 0 para nao): ");
				scanf("%i", &continuar);
			}
		}
	} while(fileira > LIN - 1 || assento > COL - 1 || fileira < 0 || assento < 0 || continuar == 1);
	
	printf("\nASSENTOS\n1: ocupados\n0: livres\n\n");
	
	for(i = 0; i < LIN; i++){
		for(j = 0; j < COL; j++){
			printf("%i ", lugares[i][j]);
		}
		printf("\n");
	}
	
	printf("\nINGRESSOS\nEntrada inteira: %i\nMeia entrada: %i\nCortesia: %i", inteira, meia, cortesia);
	
	valortotal = (valorinteira * (float)inteira) + (valormeia * (float)meia); //considerei cortesia como gratuito
	
	printf("\nTotal arrecadado: R$ %.2f", valortotal);
	
	return 0;
}
