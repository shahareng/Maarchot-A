#include "myBank.h"
#include <stdio.h>

int main() {

	char sw;

	do {

		printf("Choose a action:");
		if (scanf(" %c", &sw) == 1) {

			switch (sw) {

			case 'O':
				printf("Initial deposit?:");
				double sum;
				if (scanf(" %lf", &sum) == 1) {
					if (sum < 0) {
						printf("The amount need to be positive. Please enter again:");
						scanf(" %lf", &sum);
					}
					newAccount(twoAfterPoint(sum));
				}
				else {
					printf("Illegal input\n");
				}
				break;

			case 'B':
				printf("Account number?:");
				int numAccB;
				if (scanf(" %d", &numAccB) == 1) {
					balance(numAccB);
				}
				else {
					printf("Illegal input\n");
				}
				break;

			case 'D':
				printf("Account number?:");
				int numAccD;
				if (scanf(" %d", &numAccD) == 1) {
					printf("Amount?:");
					double amountD;
					if (scanf(" %lf", &amountD) == 1) {
						if (amountD < 0) {
							printf("The amount need to be positive. Please enter again:");
							scanf(" %lf", &amountD);
						}
						depositing(numAccD, twoAfterPoint(amountD));
					}
					else {
						printf("Illegal input\n");
					}
				}
				else {
					printf("Illegal input\n");
				}
				break;

			case 'W':
				printf("Account number?:");
				int numAccW;
				if (scanf(" %d", &numAccW) == 1) {
					printf("Amount?:");
					double amountW;
					if (scanf(" %lf", &amountW) == 1) {
						if (amountW < 0) {
							printf("The amount need to be positive. Please enter again:");
							scanf(" %lf", &amountW);
						}
						withdrawal(numAccW, twoAfterPoint(amountW));
					}
					else {
						printf("Illegal input\n");
					}

				}
				else {
					printf("Illegal input\n");
				}
				break;

			case 'C':
				printf("Account number?:");
				int numAccC;
				if (scanf(" %d", &numAccC) == 1) {
					close(numAccC);
				}
				else {
					printf("Illegal input\n");
				}
				break;

			case 'I':
				printf("Interest rate?:");
				double precent;
				if (scanf(" %lf", &precent) == 1) {
					interest(precent);
				}
				else {
					printf("Illegal input\n");
				}
				break;

			case 'P':
				printAll();
				break;

			case 'E':
				closeAll();
				break;

			default:
				printf("Error! this action doesn't exist\n");
			}

		}
		else {
			printf("Illegal Input");
		}

	} while (sw != 'E');

	return 0;
}