#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int test_input (int input_number) {
	while (input_number > 9 || input_number < 0) {
		printf("Valor Invalido! Insira um valor entre 0 e 9: ");
		scanf("%d", &input_number);
	}

	return input_number;
}

void user_interaction (){
    unsigned int unidade = 0;
    unsigned int dezena = 0;
    unsigned int centena = 0;
    
    printf("Insira a unidade do número que você deseja representar: ");
    scanf("%d", &unidade);
    unidade = test_input(unidade);
    printf("Insira a dezena do número que você deseja representar: ");
    scanf("%d", &dezena);
    dezena = test_input(dezena);
    printf("Insira a centena do número que você deseja representar: ");
    scanf("%d", &centena);
    centena = test_input(centena);

    show_base_10(unidade, dezena, centena);
}

int main () {
    user_interaction();
    return 0;
}
