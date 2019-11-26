#include "myBank.h"
#include <stdio.h>
#define numOfAcc 50
#define firstAcc 901

double bankAccount[numOfAcc][2];

double twoAfterPoint(double num) {
	num = ((int)(num * 100)) / 100.0;
	return num;
}

void newAccount(double sum) {
	int ind = 0;
	for (int i = 0; i < numOfAcc; i++) {
		if (bankAccount[i][0] == 0) {
			bankAccount[i][0] = (firstAcc + i);
			bankAccount[i][1] = sum;
			printf("The account number is: %d\n", (firstAcc + i));
			ind = 1;
			break;
		}
	}
	if (ind == 0) {
		printf("You can't open a new account\n");
	}
}

void balance(int numAcc) {
	if ((numAcc - firstAcc) < numOfAcc && (numAcc - firstAcc) >= 0) {
		if (bankAccount[numAcc - firstAcc][0] != 0) {
			double bal = bankAccount[numAcc - firstAcc][1];
			printf("The balance is: %0.2lf\n", bal);
		}
		else {
			printf("The account doesn't exist\n");
		}
	}
	else {
		printf("The account doesn't exist\n");
	}
}

void depositing(int numAcc, double amount) {
	if ((numAcc - firstAcc) < numOfAcc && (numAcc - firstAcc) >= 0) {
		if (bankAccount[numAcc - firstAcc][0] != 0) {
			double bal = (bankAccount[numAcc - firstAcc][1] + amount);
			bankAccount[numAcc - firstAcc][1] = bal;
			printf("The balance is: %0.2lf\n", bal);
		}
		else {
			printf("The account doesn't exist\n");
		}
	}
	else {
		printf("The account doesn't exist\n");
	}
}

void withdrawal(int numAcc, double amount) {
	if ((numAcc - firstAcc) < numOfAcc && (numAcc - firstAcc) >= 0) {
		if (bankAccount[numAcc - firstAcc][0] != 0) {
			if (((bankAccount[numAcc - firstAcc][1]) - amount) >= 0) {
				double bal = ((bankAccount[numAcc - firstAcc][1]) - amount);
				bankAccount[numAcc - firstAcc][1] = bal;
				printf("The balance is: %0.2lf\n", bal);
			}
			else {
				printf("You can't withdrawal\n");
			}
		}
		else {
			printf("The account doesn't exist\n");
		}
	}
	else {
		printf("The account doesn't exist\n");
	}
}

void close(int numAcc) {
	if ((numAcc - firstAcc) < numOfAcc && (numAcc - firstAcc) >= 0) {
		if (bankAccount[numAcc - firstAcc][0] != 0) {
			bankAccount[numAcc - firstAcc][0] = 0;
			bankAccount[numAcc - firstAcc][1] = 0;
			printf("The account closed\n");
		}
		else {
			printf("The account doesn't exist\n");
		}
	}
	else {
		printf("The account doesn't exist\n");
	}
}

void interest(int precent) {
	for (int i = 0; i < numOfAcc; i++) {
		if (bankAccount[i][0] != 0) {
			double amount = bankAccount[i][1];
			double inter = amount * (precent / 100.0);
			amount += inter;
			bankAccount[i][1] = amount;
		}
	}

}

void printAll() {
	for (int i = 0; i < numOfAcc; i++) {
		if (bankAccount[i][0] != 0) {
			double bal = bankAccount[i][1];
			int numAcc = bankAccount[i][0];
			printf("In account %d you have %0.2lf NIS\n", numAcc, bal);
		}
	}
}

void closeAll() {
	for (int i = 0; i < numOfAcc; i++) {
		if (bankAccount[i][0] != 0) {
			bankAccount[i][0] = 0;
			bankAccount[i][1] = 0;
		}
	}
	printf("All the account closed\n");
}