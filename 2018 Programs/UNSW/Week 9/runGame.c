/*
Authors: Dillon de Silva, Joshua Quail, Jenny Ngyuen and Gidon Kessler
Campus: UNSW Sydney
Date: 20.4.18
Description:

Draft version of the struct we'll be using to 
store game data.
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Game.h"

static int decideAction (void);
static int rollDice (void);

void runGame (void) {
  int discipline[NUM_REGIONS] = {0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0, 1, 2, 3, 4, 5, 0};
  int dice[NUM_REGIONS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 2, 3, 4, 5, 6, 7, 8, 9};
  Game g = newGame (discipline, dice);
  
  int gameNotOver = 0;
  
  while (gameNotOver != 1) { 
      int diceValue;
      diceValue = rollDice();    //simulate throw of two dice - we will discuss how to do this in tutorial
                                // or you may wish to google it and find out how you could do it! 
      diceValue += rollDice();    //roll second dice 
      
      throwDice(g,diceValue);      
      
      action move; //human or mechanicalTurk(AI) decide what they want to do     

      //loop until player action is PASS or player wins 

      int player = getWhoseTurn (g);
      int numOfKPIPoints = getKPIpoints (g, player);
      while ((move.actionCode != PASS) && (numOfKPIPoints > 150)) { 
          move.actionCode = decideAction(); 
          assert (isLegalAction(g, move) == TRUE);
          if (move.actionCode == START_SPINOFF) { 
              int randomInt = rand () % 3;
              if (randomInt < 2) {
                move.actionCode = OBTAIN_PUBLICATION;
              } else {
                move.actionCode = OBTAIN_IP_PATENT;
              }
          }         
          makeAction(g, move);             
      } 
  } 

  disposeGame (g);
}

static int rollDice (void) {
  int inputDice = 0;
  printf ("What is the Dice Value: ");
  scanf ("%d\n", &inputDice);
  return inputDice;
}

static int decideAction (void) {
  int actionCode = 0;
  printf ("What Action Would You Like To Make: ");
  scanf ("%d\n", &actionCode);
  return actionCode;
}
