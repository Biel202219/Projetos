#include <stdio.h>
#include <math.h>

int main(){
	int a;
	int b;
	int x;
	
	printf("Digite um numero:");
	scanf("%d", &a);
	printf("Digite um segundo numero:");
	scanf("%d", &b);
	
	x = (a*a)+(b*b);
	printf("valor da conta:%d",x);
}	
