#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define true 1
#define false 0

int main(int argc, char* argv[]){
	int option;
	while(true){
	printf("Select an option:\n");
	printf("1) Summary\n2) Sell on credit\n");
	scanf("%d",&option);
	if(option != 1 && option != 2)
		return 2;
	if(option == 1){
		double temp, sum = 0;
		int i = 0;
		while(true){
			printf("Item #%d: ", (i+1));
			scanf("%lf", &temp);
			sum+=temp;
			if(temp == 0)
				break;
			i++;
		}
		printf("Result is: %.2lf\n", sum);
	}else if(option == 2){
		char name[10], product[10];
		double price;
		printf("Su nombre: ");
		scanf("%s", &name);
		printf("Su producto: ");
		scanf("%s", &product);
		printf("El precio: ");
		scanf("%lf", &price);
		FILE *file = fopen("sell_on_credit.json", "a+");
		if(file == NULL)
			return 100;
		fprintf(file, ",{\"name\":\"%s\",\n\"product\":\"%s\",\n\"price\":\"$%.2lf\"}",name, product, price);
		printf("%s, %s, %lf, added! \n", name, product, price);
		fclose(file);
	}
	}
	return 0;
}
