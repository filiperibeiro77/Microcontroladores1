#include <stdio.h>
#include <string.h>
#define MIL 1000
#define CENTENA 100
#define DEZENA 10
#define QUANTITY_OF_CHARACTERS 6
#define QUANTITY_OF_LINES 7
#define QUANTITY_OF_CHARACTERS_TOTAL 67

void ShowBase10 (unsigned int input_unidade, unsigned int input_dezena, unsigned int input_centena) {
    char numero[QUANTITY_OF_LINES][QUANTITY_OF_CHARACTERS_TOTAL];
    int begin_unidade = (((input_unidade + 1) * QUANTITY_OF_CHARACTERS) - QUANTITY_OF_CHARACTERS);
    int begin_dezena = (((input_dezena + 1) * QUANTITY_OF_CHARACTERS) - QUANTITY_OF_CHARACTERS);
    int begin_centena = (((input_centena + 1) * QUANTITY_OF_CHARACTERS) - QUANTITY_OF_CHARACTERS);
    int end_unidade = ((input_unidade + 1) * QUANTITY_OF_CHARACTERS);
    int end_dezena = ((input_dezena + 1) * QUANTITY_OF_CHARACTERS);
    int end_centena = ((input_centena + 1) * QUANTITY_OF_CHARACTERS);

    strcpy(numero[0], "...............................................................");
    strcpy(numero[1], "...===.........===...===.........===...===...===...===...===...");
    strcpy(numero[2], "...#.#.....#.....#.....#...#.#...#.....#.......#...#.#...#.#...");
    strcpy(numero[3], "...............===...===...===...===...===.........===...===...");
    strcpy(numero[4], "...#.#.....#...#.......#.....#.....#...#.#.....#...#.#.....#...");
    strcpy(numero[5], "...===.........===...===.........===...===.........===...===...");
    strcpy(numero[6], "...............................................................");

   	for (int i = 0; i < QUANTITY_OF_LINES; ++i) {
		
		for (int j = begin_centena; j < end_centena; ++j) {
			printf("%c", numero[i][j]);
		}
		
		for (int j = begin_dezena; j < end_dezena; ++j) {
			printf("%c", numero[i][j]);
		}

   		for (int j = begin_unidade; j < end_unidade; ++j) {
   			printf("%c", numero[i][j]);
   		}
   		printf("...\n");
   	}

}

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
	int unidade, dezena, centena;
	int number = 0;

	printf("Insira um número entre 0 e 999: ");
	scanf("%d", &number);
	number = test_input_complete(number);

	base10(number, &unidade, &dezena, &centena);
	ShowBase10(unidade, dezena, centena);
}

int main () {
	user_interaction_total();
	return 0;
}
