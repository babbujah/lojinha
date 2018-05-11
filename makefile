# Makefile for "laboratório 3"
# Created by Bruno César 10/05/2018
#
# Makefile completo separando os diferentes elementos da aplicacao como codigo (src),
# cabecalhos (include), executáveis (build), bibliotecas (lib), etc.
# Cada elemento é alocado em uma pasta especifica, organizando melhor o codigo fonte.
#
# Algumas variáveis são usadas com significado especial:
#
# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito
#

# Comandos do sistema operacional
# Linux: rm -rf 
# Windows: cmd //C del 
RM = rm -rf 

# Compilador
CC = g++

# Variaveis para os subdiretorios
SRC = ./src
INC = ./include
BIN = ./bin
OBJ = ./build
DOC = ./doc

# Criando estruturas de diretórios
MKDIR_P = mkdir -p

# Todos os diretórios da aplicação
DIR_CRT = $(BIN) $(OBJ) $(DOC)

# Define o nome do binario/executavel final
PROG = $(BIN)/lojinha

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean debug doxy doc

# Opcoes de compilacao
CPPFLAGS = -g -Wall -pedantic -std=c++11 -I$(INC)

# Lista dos arquivos objeto (.o) que formam o binário/executável final
OBJS = $(OBJ)/produto.o $(OBJ)/roupa.o $(OBJ)/bebida.o $(OBJ)/fruta.o $(OBJ)/main.o

all : $(OBJS)
	$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)

# Alvo para a compilação com informações de debug
# Altera a flag CFLAGS, incluindo as opções -g -O0 e recompila todo o projeto
debug: CFLAGS += -g -O0 
debug: all

# Alvo para a construcão do objeto build/main.o
# Define os arquivos objeto dos quais main.o depende.
$(OBJ)/main.o: $(OBJ)/produto.o $(OBJ)/roupa.o $(OBJ)/fruta.o $(OBJ)/bebida.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

$(OBJ)/produto.o: $(INC)/produto.h
	# Cria as pastas bin, build e doc se não existem
	$(MKDIR_P) $(DIR_CRT)
	# Remove os arquivo .o da pasta build
	$(RM) $(PROG) $(OBJS)
	$(CC) $(CPPFLAGS) -c $(SRC)/produto.cpp -o $@

$(OBJ)/roupa.o: $(INC)/roupa.h $(OBJ)/produto.o
	$(CC) $(CPPFLAGS) -c $(SRC)/roupa.cpp -o $@

$(OBJ)/fruta.o: $(INC)/fruta.h $(OBJ)/produto.o
	$(CC) $(CPPFLAGS) -c $(SRC)/fruta.cpp -o $@

$(OBJ)/bebida.o: $(INC)/bebida.h $(OBJ)/produto.o
	$(CC) $(CPPFLAGS) -c $(SRC)/bebida.cpp -o $@

# Alvo para a criação do arquivo Doxyfile.
doxy:
	doxygen -g

# Alvo (target) para a geração automática de documentacão usando o Doxygen.
# Sempre remove a documentacão anterior (caso exista) e gera uma nova.
doc:
	$(RM) $(DOC)/*
	doxygen ./Doxyfile

# Alvo (target) usado para limpar os arquivos temporários (objeto)
# gerados durante a compilacão, assim como os arquivos binários/executáveis.
clean:
	$(RM) $(PROG) $(OBJS)
