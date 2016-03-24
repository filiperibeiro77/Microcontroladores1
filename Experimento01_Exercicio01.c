#include <stdio.h>
#define MIL 1000
#define CENTENA 100
#define DEZENA 10

void base10 (int input_number, int *input_unidade, int *input_dezena, int *input_centena) {
	int calc_unidade = 0, calc_dezena = 0, calc_centena = 0;

	calc_unidade = input_number % DEZENA;
	calc_dezena = (input_number % CENTENA - calc_unidade)/DEZENA;
	calc_centena = (input_number % MIL - calc_unidade - calc_dezena)/CENTENA;	

	*input_unidade = calc_unidade;
	*input_dezena = calc_dezena;
	*input_centena = calc_centena;	
}

int test_input_complete (int input_number) {
	while (input_number > 999 || input_number < 0) {
		printf("Valor Invalido! Insira um valor entre 0 e 999: ");
		scanf("%d", &input_number);
	}

	return input_number;
}

void user_interaction_total () {
	int unidade = 0, dezena = 0, centena = 0;
	int number = 0;

	printf("Insira um número entre 0 e 999: ");
	scanf("%d", &number);
	number = test_input_complete(number);

	base10(number, &unidade, &dezena, &centena);
	printf("Centena = %d Dezena = %d Unidade = %d\n", centena, dezena, unidade);
}

int main () {
	user_interaction_total();
	return 0;
}
