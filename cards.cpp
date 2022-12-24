#include <iostream>
#include <stdlib.h>

using namespace std;

extern "C"{
#include <stdlib.h>
#include <time.h>
}


enum CARDTYPE {
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
	EMPTY
};

int iRandomRoll() {
	int iRandomNumber = 0;
	iRandomNumber = 0 + rand() / (RAND_MAX / (51 - 0 + 1) + 1);
	return iRandomNumber;
}

class Cards
{
public:
	CARDTYPE cardtype;

	int iCardValue() {
		if (cardtype = TWO) {
			return 2;
		}
		else if (cardtype = THREE) {
			return 3;
		}
		else if (cardtype = FOUR) {
			return 4;
		}
		else if (cardtype = FIVE) {
			return 5;
		}
		else if (cardtype = SIX) {
			return 6;
		}
		else if (cardtype = SEVEN) {
			return 7;
		}
		else if (cardtype = EIGHT) {
			return 8;
		}
		else if (cardtype = NINE) {
			return 9;
		}
		else if (cardtype = TEN) {
			return 10;
		}
		else if (cardtype = JACK) {
			return 10;
		}
		else if (cardtype = QUEEN) {
			return 10;
		}
		else if (cardtype = KING) {
			return 10;
		}
	}

	//Cards();
	//~Cards();
};


class DECK
{
public:

	Cards cTheCards[52];
	int iRemainingCards;

	Cards deal() {
		if (iRemainingCards == 0) {
            Cards emptycard;
            emptycard.cardtype = EMPTY;
			return emptycard;
		}
		iRemainingCards--;
		return cTheCards[iRemainingCards];
	}

	void shuffle() {
		int randominteger = 0;
		Cards TempCard;
		for (int i = 0; i < 52; i++) {
			randominteger = iRandomRoll();
			TempCard = cTheCards[randominteger];
			cTheCards[randominteger] = cTheCards[i];
			cTheCards[i] = TempCard;
		}
	}
	void reset(){
        iRemainingCards = 52;
	}


	DECK()
	{
		cTheCards[0].cardtype = ACE;
		cTheCards[1].cardtype = ACE;
		cTheCards[2].cardtype = ACE;
		cTheCards[3].cardtype = ACE;

		cTheCards[4].cardtype =	TWO;
		cTheCards[5].cardtype = TWO;
		cTheCards[6].cardtype = TWO;
		cTheCards[7].cardtype = TWO;

		cTheCards[8].cardtype = THREE;
		cTheCards[9].cardtype = THREE;
		cTheCards[10].cardtype = THREE;
		cTheCards[11].cardtype = THREE;

		cTheCards[12].cardtype = FOUR;
		cTheCards[13].cardtype = FOUR;
		cTheCards[14].cardtype = FOUR;
		cTheCards[15].cardtype = FOUR;

		cTheCards[16].cardtype = FIVE;
		cTheCards[17].cardtype = FIVE;
		cTheCards[18].cardtype = FIVE;
		cTheCards[19].cardtype = FIVE;

		cTheCards[20].cardtype = SIX;
		cTheCards[21].cardtype = SIX;
		cTheCards[22].cardtype = SIX;
		cTheCards[23].cardtype = SIX;

		cTheCards[24].cardtype = SEVEN;
		cTheCards[25].cardtype = SEVEN;
		cTheCards[26].cardtype = SEVEN;
		cTheCards[27].cardtype = SEVEN;

		cTheCards[28].cardtype = EIGHT;
		cTheCards[29].cardtype = EIGHT;
		cTheCards[30].cardtype = EIGHT;
		cTheCards[31].cardtype = EIGHT;

		cTheCards[32].cardtype = NINE;
		cTheCards[33].cardtype = NINE;
		cTheCards[34].cardtype = NINE;
		cTheCards[35].cardtype = NINE;

		cTheCards[36].cardtype = TEN;
		cTheCards[37].cardtype = TEN;
		cTheCards[38].cardtype = TEN;
		cTheCards[39].cardtype = TEN;

		cTheCards[40].cardtype = JACK;
		cTheCards[41].cardtype = JACK;
		cTheCards[42].cardtype = JACK;
		cTheCards[43].cardtype = JACK;

		cTheCards[44].cardtype = QUEEN;
		cTheCards[45].cardtype = QUEEN;
		cTheCards[46].cardtype = QUEEN;
		cTheCards[47].cardtype = QUEEN;

		cTheCards[48].cardtype = KING;
		cTheCards[49].cardtype = KING;
		cTheCards[50].cardtype = KING;
		cTheCards[51].cardtype = KING;

		iRemainingCards = 52;
	}

	~DECK()
	{
	}
};



int main()
{
	srand((unsigned int)time(NULL));

	int iThreshold = 10;
	int iBustedIndex = 0;
	DECK DECKOFCARDS;


	//THRESHOLDING PORTION OF THE CODE QUESTION 4--



	for (int j = 0; j < 11; j++) {

		iBustedIndex = 0;

		for (int i = 0; i < 10000; i++) {
			int iValueinHand = 0;
			DECKOFCARDS.shuffle();
			while (iValueinHand <= iThreshold) {
				Cards card;
				card = DECKOFCARDS.deal();
				if (card.cardtype != ACE) {
					iValueinHand = iValueinHand + card.iCardValue();
				}
				else {
					if ((iValueinHand + 11) > 21) {
						iValueinHand = iValueinHand + 1;
					}
					else {
						iValueinHand = iValueinHand + 11;
					}
				}
			}
			if (iValueinHand > 21) {
				iBustedIndex++;
			}
			DECKOFCARDS.reset();
		}
		iThreshold++;
		cout << j + 1 << "The threshold is " << iThreshold << "The probability of busting is " << float(iBustedIndex) / 10000 << ". " << endl;
	}

	//BLACKJACK SIMULATOR
    DECK Black_Jack_Simulator_Deck_of_Cards;
    Cards CardsOfThePlayers[6];
    Cards CardsOfTheDealer[15];
    Cards YourCards[15];
    const int iBetHigh = 1;
    const int iBetLow = 0;
    int iCurrentBet = 0;
    int iRunningCount = 0;
    int iCurrentHnad = 0;
    int iMadeTheRightChoice = 0;
    bool bWon = false;
    bool bDealerWon = false;
    int iAmountOfGames = 0;

    Black_Jack_Simulator_Deck_of_Cards.shuffle();

    while(iAmountOfGames<10000){
        //INITIATE THE FIRST HAND

            //CHECKS TO SEE IF YOU WON. USED TO COMPARE THE WON AND BET HIGH OR LOW VALUES TO SEE HOW MANY TIMES YOU MADE THE RIGHT CHOICE.
            //SHUFFLE THE DECK
            STARTACTUALNEWGAME:
            Black_Jack_Simulator_Deck_of_Cards.shuffle();
            iAmountOfGames++;
            //cout<<iAmountOfGames<<endl;
            STARTOFGAME:

            bWon = false;
            bDealerWon = false;

            //MAKE YOUR BET
            if(iAmountOfGames == 1){
                iCurrentBet = iBetLow;
            }
            else {
                if(iRunningCount > 0){
                    iCurrentBet = iBetHigh;
                }
                else{
                    iCurrentBet = iBetLow;
                }
            }

            //DEAL THE FIRST CARD TO THE DEALER --
            CardsOfTheDealer[0] = Black_Jack_Simulator_Deck_of_Cards.deal();

            //DEAL THE CARDS TO THE OTHER PLAYERS
            for(int j = 0; j<6; j++){
                CardsOfThePlayers[j] = Black_Jack_Simulator_Deck_of_Cards.deal();
            }

            //CHECK TO SEE IF THEIR HANDS ARE EMPTY. IF SO START OVER THE GAME.
            for(int k = 0; k<6; k++){
                if (CardsOfThePlayers[k].cardtype == EMPTY){
                    Black_Jack_Simulator_Deck_of_Cards.reset();
                    iRunningCount = 0;
                    goto STARTOFGAME;
                }
            }
            if (CardsOfTheDealer[0].cardtype == EMPTY){
                Black_Jack_Simulator_Deck_of_Cards.reset();
                iRunningCount = 0;
                goto STARTOFGAME;
            }

            for(int z = 0; z<6; z++){
                if (CardsOfThePlayers[z].cardtype == TEN || CardsOfThePlayers[z].cardtype == JACK || CardsOfThePlayers[z].cardtype == QUEEN || CardsOfThePlayers[z].cardtype == KING || CardsOfThePlayers[z].cardtype == ACE){
                    iRunningCount--;
                }
                else if (CardsOfThePlayers[z].cardtype == TWO || CardsOfThePlayers[z].cardtype == THREE || CardsOfThePlayers[z].cardtype == FOUR || CardsOfThePlayers[z].cardtype == FIVE || CardsOfThePlayers[z].cardtype == SIX){
                    iRunningCount++;
                }
            }

            if (CardsOfTheDealer[0].cardtype == TEN || CardsOfTheDealer[0].cardtype == JACK || CardsOfTheDealer[0].cardtype == QUEEN || CardsOfTheDealer[0].cardtype == KING || CardsOfTheDealer[0].cardtype == ACE){
                    iRunningCount--;
                }
            else if (CardsOfTheDealer[0].cardtype == TWO || CardsOfTheDealer[0].cardtype == THREE || CardsOfTheDealer[0].cardtype == FOUR || CardsOfTheDealer[0].cardtype == FIVE || CardsOfTheDealer[0].cardtype == SIX){
                    iRunningCount++;
            }


            //START THE ROUND
            //DEAL TO THE PLAYER AKA MAYSELF
            iCurrentHnad = 0;
            int bBusted = false;
			while (iCurrentHnad <= 18) {

                //DEALS THE CARDS
				Cards card;
				card = Black_Jack_Simulator_Deck_of_Cards.deal();


				//COUNTS THE CARDS AND CHECKS IF THE DECK IS EMPTY
                if (card.cardtype == TEN || card.cardtype == JACK || card.cardtype == QUEEN || card.cardtype == KING || card.cardtype == ACE){
                    iRunningCount--;
                }
                else if(card.cardtype == TWO || card.cardtype == THREE || card.cardtype == FOUR || card.cardtype == FIVE || card.cardtype == SIX){
                    iRunningCount++;
                }
                else if(card.cardtype == EMPTY){
                    Black_Jack_Simulator_Deck_of_Cards.reset();
                    iRunningCount = 0;
                    goto STARTOFGAME;
                }

                //ADJUSTS THE VALUE OF THE HAND
				if (card.cardtype != ACE) {
					iCurrentHnad = iCurrentHnad + card.iCardValue();
				}
				else {
					if ((iCurrentHnad + 11) > 21) {
						iCurrentHnad = iCurrentHnad + 1;
					}
					else {
						iCurrentHnad = iCurrentHnad + 11;
					}
				}
				//cout<<"IN THE PLAYERS HAND"<<endl;
				//cout<<iCurrentHnad<<endl;
			}


            //CHECKS TO SEE IF I HAD A PRELIMINARY WIN

            //IF YOU PRELIMINARILY WON
            if (iCurrentHnad == 21){
                bWon = true;
                if (bWon == true && iCurrentBet == iBetHigh){
                    iMadeTheRightChoice++;
                }
                goto STARTACTUALNEWGAME;
            }

            //IF YOU PREIMINILARILY BUSTED
			if (iCurrentHnad > 21) {
				bBusted = true;
				if (bBusted == true && iCurrentBet == iBetLow){
                    iMadeTheRightChoice++;
				}
				goto STARTACTUALNEWGAME;
			}



			//DEAL TO THE DEALER TO SEE WHO WINS

			int iDealersHand = 0;
            int bDealerBusted = false;

			while (iDealersHand <= 17) {

                //DEALS THE CARDS
				Cards card;
				card = Black_Jack_Simulator_Deck_of_Cards.deal();


				//COUNTS THE CARDS AND CHECKS IF THE DECK IS EMPTY
                if (card.cardtype == TEN || card.cardtype == JACK || card.cardtype == QUEEN || card.cardtype == KING || card.cardtype == ACE){
                    iRunningCount--;
                }
                else if(card.cardtype== TWO || card.cardtype == THREE || card.cardtype == FOUR || card.cardtype == FIVE || card.cardtype == SIX){
                    iRunningCount++;
                }
                else if(card.cardtype == EMPTY){
                    Black_Jack_Simulator_Deck_of_Cards.reset();
                    iRunningCount = 0;
                    goto STARTOFGAME;
                }

                //ADJUSTS THE VALUE OF THE HAND
				if (card.cardtype != ACE) {
					iDealersHand = iDealersHand + card.iCardValue();
				}
				else {
					if ((iDealersHand + 11) > 21) {
						iDealersHand = iDealersHand + 1;
					}
					else {
						iDealersHand = iDealersHand + 11;
					}
				}
				//cout<<"IN THE DEALERS HAND"<<endl;
			}

			//PRELINARY CHECK TO SEE IF THE DEALER WON
            if(iDealersHand == 21){
                bDealerWon = true;
                if (bDealerWon == true && iCurrentBet == iBetLow){
                    iMadeTheRightChoice++;
                }
                goto STARTACTUALNEWGAME;
            }

            if (iDealersHand > 21){
                bDealerBusted = true;
                if(bDealerWon == true && iCurrentBet == iBetHigh){
                    iMadeTheRightChoice++;
                }
                goto STARTACTUALNEWGAME;
            }



            //IF THE OTHER SCENERIOS WERE NOT SATISFIED THEN COMPARE HANDS. WHOEVER HAS THE BEST HAND WILL WIN.----
            if (iCurrentHnad > iDealersHand){
                bWon = true;
                if(bWon == true && iCurrentBet == iBetHigh){
                    iMadeTheRightChoice++;
                }
                goto STARTACTUALNEWGAME;
            }
            else if(iCurrentHnad < iDealersHand){
                if(iCurrentBet == iBetLow){
                    iMadeTheRightChoice++;
                }
                goto STARTACTUALNEWGAME;
            }
    }
    cout<< "The fraction of time that I bet correctly is: "<< float(iMadeTheRightChoice)/10000 <<endl;
}
