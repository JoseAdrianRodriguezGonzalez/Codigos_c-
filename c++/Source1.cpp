#include<stdio.h>
#include<conio.h>
main() {
	int b
	char a[10];
	printf("Como te llamas?");
	scanf("%i", &a);
	printf("Cuantos años tienes?");
	scanf("%i", &b);
	if (b < 18) {
		printf("Hola %i, yo soy menor que tu ", a);
	}
	else {
		printf("Hola %i, yo soy mayor que tu ", a);
	}
}