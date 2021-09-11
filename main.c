#include <stdio.h>
#include <stdlib.h>

//add to program - Banknotes in your drawing amount

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

int amountToBanknotes(int amount) {

    int tempAmount = amount;

    int count_500 = tempAmount / 500; // 123 / 500 = 0

    tempAmount = tempAmount % 500; // 123 % 500 = 123

    int count_100 = tempAmount / 100; // 123 / 100 = 1

    tempAmount = tempAmount % 100; // 123 % 100 = 23

    int count_50 = tempAmount / 50; // 23 / 50 = 0

    tempAmount = tempAmount % 50; // 23 % 50 = 23

    int count_20 = tempAmount / 20; // 23 / 20 = 1

    tempAmount = tempAmount % 20; // 23 % 20 = 3

    int count_10 = tempAmount / 10; // 3 / 10 = 0

    tempAmount = tempAmount % 10; // 3 % 10 = 3

    int count_5 = tempAmount / 5; // 3 / 5 = 0

    int count_1 = tempAmount % 5; // 3 % 5 = 3


if( count_500 != 0 ) { printf(" %d banknotes x $ 500  \n", count_500); }
if( count_100 != 0 ) { printf(" %d banknotes x $ 100  \n", count_100); }
if( count_50 != 0 )  { printf(" %d banknotes x $ 50 \n", count_50); }
if( count_20 != 0 )  { printf(" %d banknotes x $ 20 \n", count_20); }
if( count_10 != 0 )  { printf(" %d banknotes x $ 10 \n", count_10); }
if( count_5 != 0 )   { printf(" %d banknotes x $ 5 \n", count_5); }
if( count_1 != 0 )   { printf(" %d banknotes x $ 1 ", count_1); }




    //printf("%.0f", tempAmount);


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

    allMoney = 10093;

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

                    printf("Succesfully withdrawal $ %d from your account.\n\n", amountFromAccount );

                    amountToBanknotes(amountFromAccount);

                    printSpace();

                    codesMoney[loggedCodeID] = codesMoney[loggedCodeID] - amountFromAccount;

                    printf("Now you have $ %.2f in your card.\n\n", codesMoney[loggedCodeID] );

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
