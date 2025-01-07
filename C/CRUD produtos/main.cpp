#include <iostream>
#include <string>
#include <vector>

#define MAX_PRODUCTS 100

struct Product {
    int id;
    std::string nome;
    float preco;
};

std::vector<Product> products;

void createProduct() {
    if (products.size() >= MAX_PRODUCTS) {
        std::cout << "Product list is full!" << std::endl;
        return;
    }
    Product p;
    p.id = products.size() + 1;
    std::cout << "Nome produto: ";
    std::cin >> p.nome;
    std::cout << "Preco do produto: ";
    std::cin >> p.preco;
    products.push_back(p);
    std::cout << "Produto adicionado!" << std::endl;
}

void readProducts() {
    if (products.empty()) {
        std::cout << "Sem produtos disponiveis" << std::endl;
        return;
    }
    for (const auto& product : products) {
        std::cout << "ID: " << product.id << ", Nome: " << product.nome << ", Preco: " << product.preco << std::endl;
    }
}

void updateProduct() {
    int id;
    std::cout << "ID do pedido pra alterar: ";
    std::cin >> id;
    if (id <= 0 || id > products.size()) {
        std::cout << "ID de produto invalido!" << std::endl;
        return;
    }
    Product& p = products[id - 1];
    std::cout << "Insira o nome do novo produto: ";
    std::cin >> p.nome;
    std::cout << "Insira o novo preco do produto: ";
    std::cin >> p.preco;
    std::cout << "Produto atualizado com sucesso!" << std::endl;
}

void deleteProduct() {
    int id;
    std::cout << "Insira o ID do produto para excluir: ";
    std::cin >> id;
    if (id <= 0 || id > products.size()) {
        std::cout << "ID de produto invalido!" << std::endl;
        return;
    }
    products.erase(products.begin() + (id - 1));
    std::cout << "Produto deletado com sucesso!" << std::endl;
}

int main() {
    int choice = 0;
    while (true) {
        std::cout << "\n1. Criar Produto\n2. Ver Produtos\n3. Atualizar Produtos\n4. Excluir Produto\n5. Sair\n";
        std::cout << "Selecione uma opcao: ";
        std::cin >> choice;
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
                return 0;
            default:
                std::cout << "Opcao invalida!" << std::endl;
        }
    }
    return 0;
}