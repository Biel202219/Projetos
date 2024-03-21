#include <stdio.h>
#include <stdlib.h>

void performOperation(char operation, float num1, float num2) {
    float result;

    switch(operation) {
        case '+':
            result = num1 + num2;
            printf("Resultado: %.2f\n", result);
            break;
        case '-':
            result = num1 - num2;
            printf("Resultado: %.2f\n", result);
            break;
        case '*':
            result = num1 * num2;
            printf("Resultado: %.2f\n", result);
            break;
        case '/':
            if(num2 == 0) {
                printf("Erro: Divisão por zero.\n");
            } else {
                result = num1 / num2;
                printf("Resultado: %.2f\n", result);
            }
            break;
        default:
            printf("Operação inválida.\n");
            break;
    }
}

int main() {
    char operation;
    float num1, num2;
    char cont;

    do {
        printf("Digite o primeiro número: ");
        scanf("%f", &num1);
        printf("Digite o segundo número: ");
        scanf("%f", &num2);

        printf("Digite a operacao (+, -, *, /): ");
        scanf(" %c", &operation);

        performOperation(operation, num1, num2);

        printf("Deseja continuar calculando? (s/n): ");
        scanf(" %c", &cont);
    } while(cont == 's' || cont == 'S');

    return 0;
}
