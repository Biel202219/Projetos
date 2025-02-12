#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include "/home/gabrielsg/Documents/programming/teste juan/httplib.h"

sqlite3* db;

bool abrirBanco(const std::string& nomeBanco) {
    return sqlite3_open(nomeBanco.c_str(), &db) == SQLITE_OK;
}

void fecharBanco() {
    sqlite3_close(db);
}

bool criarTabela() {
    const char* sql = "CREATE TABLE IF NOT EXISTS Produtos ("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "Nome TEXT NOT NULL, "
                      "Preco REAL NOT NULL);";
    char* erro;
    return sqlite3_exec(db, sql, nullptr, 0, &erro) == SQLITE_OK;
}

bool criarProduto(const std::string& nome, float preco) {
    std::string sql = "INSERT INTO Produtos (Nome, Preco) VALUES ('" + nome + "', " + std::to_string(preco) + ");";
    char* erro;
    return sqlite3_exec(db, sql.c_str(), nullptr, 0, &erro) == SQLITE_OK;
}

void lerProdutos(httplib::Response& res) {
    const char* sql = "SELECT * FROM Produtos;";
    sqlite3_stmt* stmt;
    std::string saida = "[";

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            if (saida.length() > 1) saida += ",";
            saida += "{\"ID\":" + std::to_string(sqlite3_column_int(stmt, 0)) +
                     ",\"Nome\":\"" + std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))) +
                     "\",\"Preco\":" + std::to_string(sqlite3_column_double(stmt, 2)) + "}";
        }
        saida += "]";
        sqlite3_finalize(stmt);
    }

    res.set_content(saida, "application/json");
}

bool atualizarProduto(int id, const std::string& nome, float preco) {
    std::string sql = "UPDATE Produtos SET Nome = '" + nome + "', Preco = " + std::to_string(preco) + " WHERE ID = " + std::to_string(id) + ";";
    char* erro;
    return sqlite3_exec(db, sql.c_str(), nullptr, 0, &erro) == SQLITE_OK;
}

bool deletarProduto(int id) {
    std::string sql = "DELETE FROM Produtos WHERE ID = " + std::to_string(id) + ";";
    char* erro;
    return sqlite3_exec(db, sql.c_str(), nullptr, 0, &erro) == SQLITE_OK;
}

void configurarServidor() {
    httplib::Server server;

    server.Post("/produtos", [](const httplib::Request& req, httplib::Response& res) {
        std::string nome;
        float preco;
        std::string corpo = req.body;
        size_t posNome = corpo.find("Nome=");
        size_t posPreco = corpo.find("&Preco=");
        if (posNome != std::string::npos && posPreco != std::string:: npos) {
            nome = corpo.substr(posNome + 5, posPreco - (posNome + 5));
            preco = std::stof(corpo.substr(posPreco + 7));
            if (criarProduto(nome, preco)) {
                res.set_content("Produto criado!", "text/plain");
            } else {
                res.set_content("Erro ao criar produto!", "text/plain");
            }
        } else {
            res.set_content("Dados inválidos!", "text/plain");
        }
    });

    server.Get("/produtos", [](const httplib::Request& req, httplib::Response& res) {
        lerProdutos(res);
    });

    server.Put("/produtos", [](const httplib::Request& req, httplib::Response& res) {
        int id = std::stoi(req.get_param_value("id"));
        std::string nome = req.get_param_value("Nome");
        float preco = std::stof(req.get_param_value("Preco"));
        if (atualizarProduto(id, nome, preco)) {
            res.set_content("Produto atualizado!", "text/plain");
        } else {
            res.set_content("Erro ao atualizar produto!", "text/plain");
        }
    });

    server.Delete("/prompts", [](const httplib::Request& req, httplib::Response& res) {
        int id = std::stoi(req.get_param_value("id"));
        if (deletarProduto(id)) {
            res.set_content("Produto deletado!", "text/plain");
        } else {
            res.set_content("Erro ao deletar produto!", "text/plain");
        }
    });

    server.listen("localhost", 8080);
}

int main() {
    if (!abrirBanco("/home/gabrielsg/Documents/programming/teste juan/teste.sqlite")) {
        std::cerr << "Erro ao abrir o banco de dados!" << std::endl;
        return 1;
    }

    criarTabela();
    configurarServidor();

    fecharBanco();
    return 0;
}
