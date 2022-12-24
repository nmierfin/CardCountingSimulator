#include <stdlib.h>
#include <iostream>

extern "C"{
#include <stdlib.h>
#include <time.h>
}

using namespace std;

int iDiceRoll = 0;

int iOne = 0;
int iTwo = 0;
int iThree = 0;
int iFour = 0;
int iFive = 0;
int iSix = 0;

float fFraction[6];


int iRandomRoll(){
    int iRandomNumber = 0;
	iRandomNumber = 1 + rand() / (RAND_MAX / (6 - 1 + 1) + 1);
	return iRandomNumber;
}


int main()
{
    srand((unsigned int)time(NULL));
	//RANDOMLY ROLL THE DICE AND THEN DISPLAY THE NUMBERS FOR 10
	for (int i = 0; i < 10; i++) {
		iDiceRoll = int(iRandomRoll());
		if (iDiceRoll == 1) {
			iOne++;
		}
		if (iDiceRoll == 2) {
			iTwo++;
		}
		if (iDiceRoll == 3) {
			iThree++;
		}
		if (iDiceRoll == 4) {
			iFour++;
		}
		if (iDiceRoll == 5) {
			iFive++;
		}
		if (iDiceRoll == 6) {
			iSix++;
		}
	}

	fFraction[0] = float(iOne)/10;
	fFraction[1] = float(iTwo)/10;
	fFraction[2] = float(iThree)/10;
	fFraction[3] = float(iFour)/10;
	fFraction[4] = float(iFive)/10;
	fFraction[5] = float(iSix)/10;


	for (int i = 0; i < 6; i++) {
		cout << i + 1 << ": " << fFraction[i] << endl;
	}
	cout << " " << endl;

	iOne = 0;
	iTwo = 0;
	iThree = 0;
	iFour = 0;
	iFive = 0;
	iSix = 0;

	fFraction[0] = 0;
	fFraction[1] = 0;
	fFraction[2] = 0;
	fFraction[3] = 0;
	fFraction[4] = 0;
	fFraction[5] = 0;

	//RANDOMLY ROLL THE DICE AND THEN DISPLAY THE NUMBERS FOR 1000
	for (int i = 0; i < 1000; i++) {
		iDiceRoll = iRandomRoll();
		if (iDiceRoll == 1) {
			iOne++;
		}
		if (iDiceRoll == 2) {
			iTwo++;
		}
		if (iDiceRoll == 3) {
			iThree++;
		}
		if (iDiceRoll == 4) {
			iFour++;
		}
		if (iDiceRoll == 5) {
			iFive++;
		}
		if (iDiceRoll == 6) {
			iSix++;
		}
	}

	fFraction[0] = float(iOne)/1000;
	fFraction[1] = float(iTwo)/1000;
	fFraction[2] = float(iThree)/1000;
	fFraction[3] = float(iFour)/1000;
	fFraction[4] = float(iFive)/1000;
	fFraction[5] = float(iSix)/1000;


	for (int i = 0; i < 6; i++) {
		cout << i + 1 << ": " << fFraction[i] << endl;
	}
	cout << " " << endl;

	iOne = 0;
	iTwo = 0;
	iThree = 0;
	iFour = 0;
	iFive = 0;
	iSix = 0;

	fFraction[0] = 0;
	fFraction[1] = 0;
	fFraction[2] = 0;
	fFraction[3] = 0;
	fFraction[4] = 0;
	fFraction[5] = 0;


	//RANDOMLY ROLL THE DICE AND THEN DISPLAY THE NUMBERS FOR 100000
		for (int i = 0; i < 100000; i++) {
			iDiceRoll = iRandomRoll();
			if (iDiceRoll == 1) {
				iOne++;
			}
			if (iDiceRoll == 2) {
				iTwo++;
			}
			if (iDiceRoll == 3) {
				iThree++;
			}
			if (iDiceRoll == 4) {
				iFour++;
			}
			if (iDiceRoll == 5) {
				iFive++;
			}
			if (iDiceRoll == 6) {
				iSix++;
			}
		}

	fFraction[0] = float(iOne) / 100000;
	fFraction[1] = float(iTwo) / 100000;
	fFraction[2] = float(iThree) / 100000;
	fFraction[3] = float(iFour) / 100000;
	fFraction[4] = float(iFive) / 100000;
	fFraction[5] = float(iSix) / 100000;


	for (int i = 0; i < 6; i++) {
		cout << i + 1 << ": " << fFraction[i] << endl;
	}
	cout << " " << endl;

	iDiceRoll = 0;
	int iLess = 0;
	int iMore = 0;
	int iSameCount = 0;

	//SPLIT VALUES
	for (int i = 0; i < 10000; i++) {
		iDiceRoll = iRandomRoll();
		if (iDiceRoll <= 3) {
			iLess++;
		}
		else if (iDiceRoll >=4){
			iMore++;
		}
		if (iMore == iLess) {
			iSameCount++;
		}
	}
	cout << "The fraction of times the number of high rolls is equal to the number of low rolls: " <<  float(iSameCount)/10000 << endl;

	cout << " " << endl;

	//PERCENTAGE OF VALUES
	int iDiceRollNumberOne = 0;
	int iDiceRollNumberTwo = 0;
	int iSum = 0;
	int iValue[11] = {0};

	for (int i = 0; i < 10000; i++) {
		iDiceRollNumberOne = iRandomRoll();
		iDiceRollNumberTwo = iRandomRoll();
		iSum = iDiceRollNumberTwo + iDiceRollNumberOne;
		if (iSum == 2) {
			iValue[0]++;
		}
		if (iSum == 3) {
			iValue[1]++;
		}
		if (iSum == 4) {
			iValue[2]++;
		}
		if (iSum == 5) {
			iValue[3]++;
		}
		if (iSum == 6) {
			iValue[4]++;
		}
		if (iSum == 7) {
			iValue[5]++;
		}
		if (iSum == 8) {
			iValue[6]++;
		}
		if (iSum == 9) {
			iValue[7]++;
		}
		if (iSum == 10) {
			iValue[8]++;
		}
		if (iSum == 11) {
			iValue[9]++;
		}
		if (iSum == 12) {
			iValue[10]++;
		}
	}

	for (int i = 0 ; i < 11; i++) {
		cout << i + 2 << ": " << float(iValue[i]) / 10000<<endl;
	}
}
