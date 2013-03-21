#include <stdio.h>
#include <string.h>
#define LINES 15
#define CHARACTERS 8

main()
{//открыли файл дл€ чтени€, второй дл€ записи результата
	int i, k, n = 0;
	FILE *original_f;//,*new_f;
	char a[LINES][CHARACTERS];
	int numbers[LINES];

	if ((original_f = fopen("linear_program.txt", "r")) == NULL) {
		perror("Error");
		return 0;
	}

	for(i = 0; i < LINES; i++)
		fgets(a[i], 8, original_f);
	printf("Processed file: \n");
	for(i = 0; i < LINES; i++) {
		printf("%s", a[i]);
		//printf(".");
	}

	fclose(original_f);
	printf("\n\nStart processing:");
	for(k = 0; k <= LINES; k++) {//сравнение строк
		i=k+1;
		for(i; i < LINES; i++) {
				printf("\n\n	Search equivalent strings... k = %d, i = %d", k, i);
				printf("\n	strcmp(a[%d], a[%d]) = %d", k, i, strcmp(a[k], a[i]));
				if ((strcmp(a[k], a[i])) == 0) {
					if  (k+1 == i){
						printf("\n	Strings equal and one by one!");
						printf("\n	Strings numbers: %d, %d", k, i);
						printf("\n	String: %s", a[k]);
						printf("\n		function REMEMBER_NUMBERS call");
						numbers[n] = i;
						n++;
						//DELETE_STR(i, a);
					} else {
						printf("\n	Strings equal");
						printf("\n	Strings numbers: %d, %d", k, i);
						printf("\n	String: %s", a[k]);	
						printf("\n		function COMPARE_STR call");
						//compare_result = COMPARE_STR(i, k, a);
						//printf("\n		COMPARE_STR(%d, %d, a) = %d", i, k, compare_result);	
						if (COMPARE_STR(i, k, a) == 0) {
							printf("\n		function REMEMBER_NUMBERS call");	
							numbers[n] = i;
							n++;
						} else {
							printf("\n		nothing to remove");	
						}
					}
				} else {
					printf("\n	Strings are not equal");
				}
		}
	}
	printf("\nn = %d", n);
	//numbers[n] = LINES - n;
	printf("\n	numbers: ");
	for(i = 0; i < n; i++) {
		printf("%d, ", numbers[i]);
	}
	for(i = 0; i < n; i++) {
		k = numbers[i];
		*a[k] = NULL;
	}
	printf("\nEnd processing.");
	printf("\n\nResult file: \n");
	for(i = 0; i < LINES; i++) {
		printf("%s", a[i]);
	}
	printf("\n");
}
 int COMPARE_STR(int i, int k, char a[LINES][CHARACTERS]) {//сравнение символов. ѕровер€ет наличие всех переменных катой строки среди первых символов во всех строках между катой и итой в массиве а
	int m;
	//printf("\n	compare i = %d, k = %d\n", i, k);//‘ункци€ возвращает 1, если хот€ бы одна переменна€ присутствует в строках между
	for(m = k+1; m < i; m++) {
		//printf("\n	strchr(%s, %c)", a[i], a[m][0]);
		if ((strchr(a[i], a[m][0])) == NULL) {
			//printf("\n	no match");
			return 0;
		}
		else { 
			//printf("\n	matches are found");
			return 1;
		}
	}
}