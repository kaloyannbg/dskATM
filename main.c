#include <stdio.h>
#include <stdlib.h>

#define CODES 3

float allMoney;

int codes[CODES][4] = {

                        {1, 2, 3, 4},
                        {1, 0, 0, 0},
                        {5, 3, 5, 3},

                      };

float codesMoney[CODES] = { 3000, 4000, 5000 };

int code[4];

int codeCopy[4];

void printSpace(void) {

    printf("\n");

    printf("\n");

}

void printMoneyFromATM(void) {

    printf(" -- Money at ATM: $ %.2f -- ", allMoney);

}

void printMenuATM(void) {

    printf("1. Check your account \n");
    printf("2. Check DSK ATM all money\n");
    printf("0. Quit from program\n ");

}

void printAcoountMenu() {

    printf("1. I want to draw money. \n");
    printf("0. Quit from that card ");

}

void yellow(void) {
    printf("\033[1;33m");
}

void resetColor(void) {
    printf("\033[0m");
}

int main()
{

    system("color 07");

    allMoney = 10000;

    int menuATMchoice, tempAccountCode, countIntegerInCode;

    int menuAccountChoice;

    int accountCode; // USER CODE FOR READ

    int amountFromAccount;

    do {

    countIntegerInCode = 0;

      printf("\n\n     -- -- DSK ATM by Kaloqn Angelov -- --\n\n");

      printMenuATM();

      printf("\nEnter your choice: ");

      scanf("%d", &menuATMchoice);

      printf("\n");
        yellow();
      if(menuATMchoice == 1) {
        printf("Enter your card...\n");
        printf("Innitialize...\n");
        printf("Type your 4-digit code: ");

        scanf("%d", &accountCode);

        tempAccountCode = accountCode;

        while(tempAccountCode > 0) {

            code[countIntegerInCode] = tempAccountCode % 10;

            tempAccountCode = tempAccountCode / 10;

            countIntegerInCode++;

        }

        printf("\n");




        if(countIntegerInCode == 4) {

        int tempZ;

        tempZ = 0;

        for(int z = 3; z >= 0; z--) {

            codeCopy[tempZ] = code[z];

            tempZ++;
        }



        for(int i = 0; i < tempZ; i++) {
            printf("[%d]", codeCopy[i]);
        }

        printSpace();

        int succesCount = 0;

        int succesLogin = 0;

        int loggedCodeID = 5000;

        for(int i = 0; i < CODES; i++ ) {

            for(int j = 0; j < 4; j++) {

                //printf("[%d]", codes[i][j]);

                if(codes[i][j] == codeCopy[j]) {
                    succesCount++;
                }

            }

                if(succesCount == 4) {
                    loggedCodeID = i;
                    succesLogin = 1;
                    break;
                }

        succesLogin = 0;

        succesCount = 0;

        }

        if(succesLogin == 1) {

            printf(" --Hello! Succesfully authentication --");

            printf("\n -- You have: $ %.2f in card. --", codesMoney[loggedCodeID] );

            printSpace();

            printAcoountMenu();

            printSpace();

            printf("Enter your Account Menu choice: ");

            scanf("%d", &menuAccountChoice);

            printSpace();

            if(menuAccountChoice == 1) {

                printf("Enter amount: ");

                scanf("%d", &amountFromAccount);

                printSpace();

                if(amountFromAccount < 0) {

                    printf("Try to enter properly amount");

                } else if (amountFromAccount > codesMoney[loggedCodeID]) {

                    printf("You don\'t have $ %d in your card. You have: $ %.2f", amountFromAccount, codesMoney[loggedCodeID]);


                } else if (amountFromAccount > allMoney) {

                    printf("All money in ATM is: $ %.2f can\'t get that $ %d", allMoney, amountFromAccount);

                } else {

                    printf("Succesfully withdrawal $ %d from your account.\n", amountFromAccount );

                    codesMoney[loggedCodeID] = codesMoney[loggedCodeID] - amountFromAccount;

                    printf("Now you have $ %.2f in your card.\n", codesMoney[loggedCodeID] );

                    allMoney = allMoney - amountFromAccount;

                }

            } else {

              printf("Invalid choice.");

            }

        } else {
            printf("Wrong code! Try again.");
        }

        } else {

        printf("Error! This code need to be 4 digits. And can\'t start with 0");

        }


      } else if(menuATMchoice == 2) {

        printMoneyFromATM();

      } else if(menuATMchoice == 0) {

      } else {
        printf("Incorrect menu choice. Try again.");
      }

      resetColor();

    } while(menuATMchoice != 0);



    printf("\n\n\n");
    return 0;
}
