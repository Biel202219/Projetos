create table Cliente (
  ClienteID INTEGER PRIMARY KEY NOT NULL,
  Nome TEXT(255) NOT NULL,
  Telefone TEXT(11) not NULL,
  Emeil TEXT(255),
  Endereco TEXT(255) NOT NULL
);
  
create table produtos (
  ProdutoID INTEGER PRIMARY KEY NOT NULL ,
  Nome TEXT(255) NOT NULL,
  Categoria TEXT(255) NOT NULL,
  Preco TEXT(5) NOT NULL,
  Estoque TEXT(255) NOT NULL
);
  
create table Fornecedores (
  Fornecedorid INTEGER PRIMARY KEY NOT NULL,
  Nome TEXT(255) NOT NULL,
  Telefone TEXT(11) NOT NULL,
  Emeil TEXT(255),
  Endereco TEXT(255) NOT NULL
);
  
  
create table Vendas (
  VendasID INTEGER PRIMARY KEY NOT NULL,
  ProdutoID INTEGER NOT NULL,
  ClienteID INTEGER NOT NULL,
  FuncionarioID INTEGER NOT NULL,
  DATA TEXT(255) NOT NULL,
  QTD INTEGER NOT NULL,
  Total NUMERIC(255) NOT NULL
  );
  
CREATE TABLE Funcionario (
  FuncionarioID INTEGER PRIMARY KEY NOT NULL,
  Nome TEXT(255) NOT NULL,
  Cargo TEXT(255) NOT NULL,
  Telefone TEXT(11) NOT NULL,
  Email TEXT(255)
);


INSERT INTO cliente( ClienteID, Nome, Telefone, Email, Endereco)
VALUES(10011, 'Gabriel', 12995452874,, Brasil)

INSERT INTO produtos(ProdutoID, Nome, Categoria, Preco, Estoque)
VALUES(10021, 'Placa de video', 'Tecnologia', 9999.99, 20)

INSERT INTO fornecedores(FornecedorID, Nome, Telefone, Email, endereco)
VALUES(10031, 'Brain', 124545745,, Portugal)

INSERT INTO Funcionario(FuncionarioID, Nome, Caargo, Telefone, Email)
VALUES(100441, 'Ana Protasio', 'Almoxarifado', 12998752365)

INSERT INTO Vendas(VendasID, ProdutoID, CliebnteID, FuncionarioID, Data, QTD, Total)
VALUES(10051, 10021, 10011, 10041, '22-04-24', 1, 999,99)
