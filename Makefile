all: run


dice: dice.cpp
	g++ dice.cpp -o dice

cards: cards.cpp
	g++ cards.cpp -o cards


run: cards dice
	./dice
	./cards


.PHONY: all run

clean:
	rm -f cards
