TARGET = main

SRC = src
INC = inc
OBJ = obj

SOURCE = $(wildcard $(SRC)/*.cpp)
OBJECT = $(patsubst %,$(OBJ)/%, $(notdir $(SOURCE:.cpp=.o)))

CC = g++
CFLAGS = -Wall -std=c++17 -pedantic -I$(INC)

RED = \033[1;31m
GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
NC = \033[1;0m
./$(TARGET) : $(OBJECT)
	@echo "$(RED)Linkowanie...$(NC)"
	$(CC) -o $@ $^
	@echo "$(BLUE)Linkowanie zakonczone sukcesem.$(NC)"

$(OBJ)/%.o : $(SRC)/%.cpp
	@echo "$(GREEN)Kompilacja...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY : help run clean info

run : ./$(TARGET)
	@echo "$(YELLOW)Uruchamianie programu....$(NC)"
	./$(TARGET)

clean :
	rm -f $(OBJECT) ./$(TARGET)
help :
	@echo "src: $(SOURCE)"
	@echo "obj: $(OBJECT)"
info :
	@echo "Uniwersalny plik Makefile do budowy programu w jezyku C"
	@echo "Do poprawnego działania wymagane jest zachowanie struktury modulowej programu"
	@echo "inc - katalog na pliki naglowkowe"
	@echo "src - katalog na pliki zrodlowe"
	@echo "obj - katalog na pliki wynikowe (na wejsciu pusty)" 
