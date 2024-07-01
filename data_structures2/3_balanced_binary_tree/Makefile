# Aluno: Lucas Yukio Fukuda Matsumoto
# Disciplina: Estruturas de Dados 2
# Profa. Juliana de Santi
# Lista Implementação de AVL

# Detecta automaticamente o sistema operacional
# Configurações para Windows
ifeq ($(OS),Windows_NT)
    RM = del /Q
    MKDIR = mkdir
    SUFFIX = .exe
	PAUSE_CMD = pause
	OPEN_CMD = cmd /C $(EXEC)
	#Define o nome para o arquivo executável (saida) gerado após a compilação
    EXEC = saida$(SUFFIX)
	
# Configurações para Unix-like
else
    UNAME := $(shell uname)
	
	#Define o nome para o arquivo executável (saida) gerado após a compilação
	EXEC = saida
	
	RM = rm -f
	MKDIR = mkdir -p
	SUFFIX =
	PAUSE_CMD =
	OPEN_CMD = ./$(EXEC)
endif

#Neste exemplo de Makefile, os arquivos objetos (.o) são gerados separadamente, assim, somente arquivos fonte (.c) alterados são recompilados para gerar um novo .o. Então, o novo .o é linkado com os outros .o (dos arquivos não alterados) para gerar o executável. O make sabe o que deve ser recompilado com base nos timestamps dos arquivos fonte e seus respectivos arquivos objeto.

#cria a variável CC para o nome do compilador utilizado (gcc)
CC = gcc

#Cria variável SRC com todos os arquivos fonte (.c) presentes do diretório atual
SRC = $(wildcard *.c)

#Cria variável OBJ com todos os arquivos .o criados a partir de cada arquivo .c
OBJ = $(SRC:.c=$(SUFFIX))

######### Sintaxe ###########
#regra: dependências
#<TAB>	comando	
#############################

#================
#A regra "all" é usada para construir o sistema de forma incremental 
all: $(EXEC)
	@echo " "
	@echo "Compilacao concluida!!"
	@echo " "
	$(OPEN_CMD)
	$(PAUSE_CMD)

#================
#A regra $(EXEC): tem como dependências os arquivos objeto (.o), ou seja, para criar o executavel saida precisamos dos 4 arquivos .o (progPrincipal.o, mult.c soma.o, par.o)
# $@ expande a regra-alvo; neste caso saida
# $^ expande as dependências da regra; neste exemplo os 4 arquivos .o 
#O comando cria o executável ($@ regra-alvo) a partir dos arquivos .o ($^ dependências). Equivalente à gcc -o saida progPrincipal.o mult.o soma.o par.o
$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) 

#================
#A regra %.o: (ou seja, a regra para cada um dos arquivos .o) tem como dependências os arquivos .c (%c)
#O comando gera os arquivos .o ($@ regra-alvo) a partir de seus respectivos arquivos .c ($^ dependências). 
%$(SUFFIX): %.c
	$(CC) -o $@ -c $<

#================
#A regra clean: apaga os arquivos .o ao digitarmos make clean na console
clean: 
	$(RM) $(OBJ)

#================
#A regra execClean: apaga o arquivo executável ao digitarmos make cleanExec na console	
cleanExec:
	$(RM) $(EXEC)

.PHONY: all clean cleanExec