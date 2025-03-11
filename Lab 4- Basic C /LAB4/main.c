#include <stdbool.h>
#include <stdio.h>



bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}



int main(void) {
    bool quit = false; //Controls Loop

    int choice = 0; //Global Variables
    int digit = 5;

    while (!quit) {

        //MENU SYSTEM
        printf("__________________________________ \n");
        printf("1. New Number \n"); //Default int = 5
        printf("2. Print Odds, Evens, and Zeros \n");
        printf("3. Print Primes 2 - Integer \n");
        printf("4. Exit\n");
        printf("__________________________________ \n");

        printf("\n");
        printf("Please Select A Menu Option: \n");
        scanf("%d", &choice); // NOLINT(*-err34-c)


        //CHOICE SWITCH
        switch (choice) {

            case 1://DONE!
                printf("Enter a New Number: \n");
                printf("_____________________ \n");
                scanf("%d", &digit);
            if (digit < 0) {
                printf("No Negative Numbers Try Again: \n");
                break;
            }

            else {
                printf("The number is: %d\n", digit);
                break;
            }

            case 2://DONE!
                printf("\n");
                printf("Print Odds,Evens,Zeros: \n");
                printf("_________________________ \n");

                int zeroCount = 0;
                int oddCount = 0;
                int evenCount = 0;

                for (int i = 0; i <= digit; i++) {
                    if (i == 0) {
                        zeroCount++;
                    }
                    else if (i % 2 == 0) {
                        evenCount++;
                    }
                    else {
                        oddCount++;
                    }
                }
            printf("Number of Zeros: %d\n",zeroCount);
            printf("Number of Odds: %d\n",oddCount);
            printf("Number of Evens: %d\n",evenCount);
            printf("\n");
            break;


            case 3: //DONE!!
                printf("Prime Numbers between 2 and %d: \n", digit);
                printf("__________________________________ \n");
            for (int i = 2; i <= digit; i++) {
                if (is_prime(i)) {

                    printf("%d", i);
                    printf("\n");
                }
            }

            break;


            case 4: //DONE!!
                quit = true;
                printf("Bye-Bye \n");
            break;


            default: //DONE!!
                printf("Invalid Option Try Again: \n"); //Used when given invalid option

            break;
        }

    }
   return 0;
}