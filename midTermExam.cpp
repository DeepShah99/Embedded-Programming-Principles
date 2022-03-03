/*******************************************************************************
  * File Name          : midTermExam.cpp
  * Description        : program to simulate 4 rolls of a dice and roll as many times till the time we get a sequence
  *                      of 1,2,3,4 or 2,3,4,5 or 3,4,5,6                       
  *
  * Author             : Deep Shah
  * Date               : 8th July 2021
  ******************************************************************************
  */
#include <stdio.h>          // used by printf
#include <stdlib.h>         // used by srand and rand functions
#include <time.h>           // used by time function

#define diceRolls 1000      // maximum rolls allowed to get the desired sequence
#define totalDices 4        // this code is valid for dices 2 to 6 

// FUNCTION      : randomize
// DESCRIPTION   : Initialize the random number generator
// PARAMETERS    : none
// RETURNS       : none 
void randomize(void);

// FUNCTION      : randomDice
// DESCRIPTION   : Return a random number between 1 to 6
// PARAMETERS    : none
// RETURNS       : none
int randomDice(void);

// FUNCTION      : checkForSequence
// DESCRIPTION   : function that is responsible for checking of the sequence
// PARAMETERS    : none
// RETURNS       : none
void checkForSequence(void);

void randomize(void)
{
    srand((unsigned)time(NULL));
    return;
}


int randomDice(void)
{
    return((rand() % 6) + 1);
}

void checkForSequence() {
    int diceArray[diceRolls][totalDices];          
    int i = 0;
    while (1) {
        printf("Non Sorted:\n");
        for (int j = 0; j < totalDices; j++) {     // loop to initialize and print random values 
            diceArray[i][j] = randomDice();
            printf("%d  %d\n", i + 1, diceArray[i][j]);
        }
 
        for (int x = 0; x < totalDices; x++)       // loop to sort the numbers in an ascending order
        {

            for (int y = x + 1; y < totalDices; y++)
            {

                if (diceArray[i][x] > diceArray[i][y])  // if lower index number is greater than swap
                {
                    int temp;                     
                    temp = diceArray[i][x];
                    diceArray[i][x] = diceArray[i][y];
                    diceArray[i][y] = temp;

                }

            }

        }
        printf("Sorted:\n");
        for (int j = 0; j < totalDices; j++) {        // print ascendng sorted numbers 
            printf("%d  %d\n", i + 1, diceArray[i][j]);
        }
        
        int sumDiffCounter = 0;
        for (int k = 0; k < totalDices - 1; k++) {
            if (diceArray[i][k + 1] - diceArray[i][k] == 1) {  // for eg-1,2,3,4 then 2 - 1 = 3 - 2 = 4 - 3 = 1 hence, sumDiffcounter will be 3
                sumDiffCounter++;
            }
        }
        if (sumDiffCounter == totalDices - 1) {  // for eg - True if sumDiffCounter = 4 - 1 = 3 for comb. 1,2,3,4. 
            printf("Sequence achieved at Dice Roll: %d\n", i + 1);
            break;                               // desired sequence achieved  
        }
        i++;
    }

}

int main()
{
    randomize();
    checkForSequence();      

}

