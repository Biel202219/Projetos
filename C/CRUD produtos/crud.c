#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char nome[50];
    float preco;
} Product;

Product products[MAX_PRODUCTS];
int productCount = 0;

void createProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Product list is full!\n");
        return;
    }
    Product p;
    p.id = productCount + 1;
    printf("Nome produto: ");
    scanf("%49s", p.nome);
    printf("Preco do produto: ");
    scanf("%f", &p.preco);
    products[productCount++] = p;
    printf("Produto adicionado!\n");
}

void readProducts() {
    if (productCount == 0) {
        printf("Sem produtos disponiveis\n");
        return;
    }
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Nome: %s, Preco: %.2f\n", products[i].id, products[i].nome, products[i].preco);
    }
}

void updateProduct() {
    int id;
    printf("ID do pedido pra alterar: ");
    scanf("%d", &id);
    if (id <= 0 || id > productCount) {
        printf("ID de produto invalido!\n");
        return;
    }
    Product *p = &products[id - 1];
    printf("Insira o nome do novo produto: ");
    scanf("%49s", p->nome);
    printf("Insira o novo preco do produto: ");
    scanf("%f", &p->preco);
    printf("Produto atualizado com sucesso!\n");
}

void deleteProduct() {
    int id;
    printf("Insira o ID do produto para excluir: ");
    scanf("%d", &id);
    if (id <= 0 || id > productCount) {
        printf("ID de produto invalido!\n");
        return;
    }
    for (int i = id - 1; i < productCount - 1; i++) {
        products[i] = products[i + 1];
    }
    productCount--;
    printf("Produto deletado com sucesso!\n");
}

int main() {
    int choice = 0;
    while (1) {
        printf("\n1. Criar Produto\n2. Ver Produtos\n3. Atualizar Produtos\n4. Excluir Produto\n5. Sair\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createProduct();
                break;
            case 2:
                readProducts();
                break;
            case 3:
                updateProduct();
                break;
            case 4:
                deleteProduct();
                break;
            case 5:
                exit(0);
            default:
                printf("Opcao invalida!\n");
        }
    }
    return 0;
}