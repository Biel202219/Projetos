#imports
from cgitb import text
from re import T
from tkinter import CENTER
from tkinter.tix import COLUMN
import turtle
from tkinter import *
from datetime import date


#básico 
janela =Tk() 
janela.title("files system")
janela.geometry("1043x520")
janela.resizable(width=FALSE, height=FALSE)

#variáveis
txtNome = StringVar()
txtEndereco = StringVar()
txtIndicacao = StringVar()
txtDescricao = StringVar()
numDataNasc = StringVar()
numDatahj = StringVar()
numCPF = StringVar()
numCEP = StringVar()
numIdade = StringVar()

#labels 
lblNome= Label (janela, text="Nome")
lblEndereco= Label (janela, text="Endereço")
lblIndicacao= Label (janela, text="Indicação")
lblDescricao= Label (janela, text="Discrição")
lblDataNasc= Label (janela, text="Data de Nascimento")
lblDatahj= Label (janela, text="Data Atual")
lblCPF= Label (janela, text="CPF")
lblCEP= Label (janela, text="CEP")
lblIdade= Label (janela, text="Idade")

#inputs
entDatahj= Entry(janela, textvariable= numDatahj)
entDataNasc= Entry(janela, textvariable= numDataNasc)
entIdade= Entry(janela, textvariable= numIdade)
entNome= Entry(janela, textvariable= txtNome, width=50)
entEndereco= Entry(janela, textvariable= txtEndereco, width=50)
entCEP= Entry(janela, textvariable= numCEP)
entCPF= Entry(janela, textvariable= numCPF)
entIndicacao= Entry(janela, textvariable= txtIndicacao)
entDescricao= Entry(janela, textvariable= txtDescricao, width=50)

#Cliente Cadastrados
listClientes= Listbox(janela, height=20, width=90)

#ScrollBar para o ListBox
scrollClientes= Scrollbar(janela)

#botões
btnViewAll= Button(janela, text="Ver todos")
btnBuscar= Button(janela, text="Buscar")
btnInserir= Button(janela, text="Inserir Cliente")
btnUpdate= Button(janela, text="Atualizar Selecionados")
btnDel= Button(janela, text="Deletar Selecionados")
btnClose= Button(janela, text="Fechar")

#Associando os objetos a grid das respectivas janelas

lblNome.grid(row=0,column=0)
lblDatahj.grid(row=1,column=0)
lblDataNasc.grid(row=2,column=0)
lblCPF.grid(row=3, column=0)
lblCEP.grid(row=4, column=0)
lblEndereco.grid(row=5, column=0)
lblIndicacao.grid(row=6, column=0)
lblDescricao.grid(row=7, column=0)
lblIdade.grid(row=8,column=0)
entNome.grid(row=0, column=1)
entDatahj.grid(row=1, column=1)
entDataNasc.grid(row=2, column=1)
entCPF.grid(row=3, column=1)
entCEP.grid(row=4, column=1)
entEndereco.grid(row=5, column=1)
entIndicacao.grid(row=6, column=1)
entDescricao.grid(row=7, column=1)
entIdade.grid(row=8,column=1)
listClientes.grid(row=0, column=2, rowspan=10, padx=10, pady=10)
scrollClientes.grid(row=0, column=5, rowspan=10)
btnViewAll.grid(row=12, column=0, columnspan=2)
btnBuscar.grid(row=13, column=0, columnspan=2)
btnInserir.grid(row=14, column=0, columnspan=2)
btnUpdate.grid(row=15, column=0, columnspan=2)
btnDel.grid(row=16, column=0, columnspan=2)
btnClose.grid(row=17, column=0, columnspan=2)

janela.mainloop()



