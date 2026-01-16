#include "../include/utils.h"

int random_number(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int main() {
	srand(time(NULL));

	int min = 2;
	int max = 7;
	int max_operations = 10;
	int user_value = 0;
	int quit = 0;
	int score = 0;

	for (int i = 0; i < max_operations && !quit; i++) {
		
		int a = random_number(min, max);
		int b = random_number(min, max);
		int c = 0;
	
		do {
			printf("%d x %d = ", a, b);		
			
			if (scanf("%d", &user_value) == 1) {
				
				if (user_value == a * b) {
	  				printf("Bonne réponse!\n");
					score++;
				} else {
	 				printf("Mauvaise réponse.. La réponse était %d.\n", a * b);
				} 
				
				if (i == max_operations - 1) {
					printf("\nTu as %d bonne(s) réponse(s) sur %d.\n\n", score, max_operations); 
				}	

				break;
			
			} else {
				
				c = getchar();
				
				if (c == EOF) {
					quit = 1;
					break;
				}	

				while (c != '\n' && c != EOF) {
					c = getchar();
				}

				printf("Erreur de saisie.\n");
			}
		
		} while (1);
	}	
	return 0;
}	
