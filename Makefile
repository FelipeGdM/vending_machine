# Name: Makefile
# Baseado em: https://github.com/ThundeRatz/STM32ProjectTemplate
# Equipe ThundeRatz de Robótica
# 03/2020
#
# Para usar este Makefile, os arquivos .c devem estar dentro da pasta /src
# e os arquivos .h devem estar dentro da pasta /inc. O arquivo de Makefile
# deve estar na raiz do projeto, junto das duas pastas.
#
# É necessário ter instalado o compilador C "gcc" (GNU C compiler) e a ferramenta
# "make". Ambos podem ser instalados com o MSYS2 (https://www.msys2.org/)
#
# Para compilar o projeto, basta executar o comando "make" ou "make all"
# Para limpar arquivos compilados previamente, utilize o comando "make clean"
#
# Organização dos arquivos:
#
# /inc
# ├ timer.h
# ├ sensores.h
# └ ...
# /src
# ├ main.c
# ├ timer.c
# ├ sensores.c
# └ ...
# Makefile

###############################################################################
## Configuração do compilador
###############################################################################

# Nome do projeto
PROJECT = vending_machine

# Executável do compilador
CC = gcc
CFLAGS = -Iinc

# Pasta dos binários compilados
BUILD_DIR := build

# Código fonte
C_SOURCES    := $(shell find src -name "*.c")
C_HEADERS    := $(shell find inc -name "*.h")

# Binários compilados
OBJECTS      := $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))

vpath %.c $(sort $(dir $(C_SOURCES)))

###############################################################################
## Regras do Makefile
###############################################################################

all: $(PROJECT)

$(BUILD_DIR)/%.o: %.c $(C_HEADERS) Makefile | $(BUILD_DIR)
	@echo "  CC $<"
	@$(CC) -c $< -o $@ $(CFLAGS)

$(PROJECT): $(OBJECTS)
	@echo "Criando $@"
	@$(CC) -o $@ $^ $(CFLAGS)

clean:
	@echo "Limpando arquivos compilados"
	@-rm -rf $(BUILD_DIR)
	@rm -f $(PROJECT)

# Cria o build_dir
$(BUILD_DIR):
	@echo "Criando pasta de build"
	@mkdir -p $@
