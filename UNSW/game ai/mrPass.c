/*
 *  Mr Pass.  Brain the size of a planet!
 *
 *  Proundly Created by Richard Buckland
 *  Share Freely Creative Commons SA-BY-NC 3.0. 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "Game.h"
#include "mechanicalTurk.h"

action decideAction (Game g) {
    //Requirements MJ MTV M$
    int currentPlayer = getWhoseTurn(g);
    int MJcount = getStudents(g, currentPlayer, STUDENT_MJ);
    int MTVcount = getStudents(g, currentPlayer, STUDENT_MTV);
    int MMONEYcount = getStudents(g, currentPlayer, STUDENT_MMONEY);
    action nextAction;
    if (MJcount > 0 && MTVcount > 0 && MMONEYcount > 0) {
        nextAction.actionCode = START_SPINOFF;
    } else {
        nextAction.actionCode = PASS;
    }
    return nextAction;
}
