# Makefile for Java project

JAVAC = javac
JAVA = java
JFLAGS = -d bin

SRC_DIR = src
BIN_DIR = bin

MAIN_CLASS = WeightedGraph 

SOURCES = $(wildcard $(SRC_DIR)/*.java)

all: $(BIN_DIR)/classes

$(BIN_DIR)/classes: $(SOURCES) | $(BIN_DIR)
	$(JAVAC) $(JFLAGS) $(SOURCES)
	touch $(BIN_DIR)/classes

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

run: all
	$(JAVA) -cp $(BIN_DIR) $(MAIN_CLASS)

clear:
	rm -rf $(BIN_DIR)
