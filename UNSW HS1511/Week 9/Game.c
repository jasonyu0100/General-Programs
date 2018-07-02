/*
Authors: Dillon de Silva, Joshua Quail, Jenny Nguyen and Gidon Kessler
Campus: UNSW Sydney
Date: 20.4.18
Description:

Draft version of the struct we'll be using to
store game data.
*/

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "Game.h"
#include <stdio.h>

#define OFFSET 1
#define MAX_VERTICES 48
#define MAX_EDGES 72
#define REGIONS_PER_VERTEX 3
#define NEIGHBOURS_PER_REGION 6
#define NUM_OF_EXCHANGES 10
#define GAME_SIZE 28520
//#define GAME_SIZE 100000

// struct for storing the players locations
typedef struct _location {
  path destination;
  int type;
} location;

// struct for storing the regions surrounding a path clockwise from the direction
typedef struct _stance {
  int left;
  int forward;
  int right;
} stance;

// struct for storing neighbouring regions of a single region
typedef int neighbours[NEIGHBOURS_PER_REGION];

// Struct for storing game data.
typedef struct _game {
  int currentTurn;
  int diceValue;
  int whichPlayerTurn;

  int discipline[NUM_REGIONS];
  int dice[NUM_REGIONS];

  int studentsThD[NUM_UNIS];
  int studentsBPS[NUM_UNIS];
  int studentsBQN[NUM_UNIS];
  int studentsMJ[NUM_UNIS];
  int studentsMTV[NUM_UNIS];
  int studentsMMoney[NUM_UNIS];

  int numOfPublications[NUM_UNIS];
  int numOfIPPatents[NUM_UNIS];
  int numOfCampuses[NUM_UNIS];
  int numOfGO8s[NUM_UNIS];
  int numOfARCs[NUM_UNIS];

  location listOfCampuses[MAX_VERTICES];
  location listOfGO8s[MAX_VERTICES];
  location listOfARCs[MAX_EDGES];
  location listOfExchanges[NUM_OF_EXCHANGES];

  neighbours neighbouringRegions[NUM_REGIONS];
} * game;

// Static Functions
static void addLocation(Game g, action a) {
  location l;
  memcpy(l.destination, a.destination, PATH_LIMIT);
  int player = g->whichPlayerTurn;

  if (a.actionCode == BUILD_CAMPUS) {
    if (player == UNI_A) {
      l.type = CAMPUS_A;
    } else if (player == UNI_B) {
      l.type = CAMPUS_B;
    } else {
      l.type = CAMPUS_C;
    }
    g->listOfCampuses[g->numOfCampuses[UNI_A - OFFSET] +
      g->numOfCampuses[UNI_B - OFFSET] +
      g->numOfCampuses[UNI_C - OFFSET]] = l;
    g->numOfCampuses[player - OFFSET]++;
  } else if (a.actionCode == BUILD_GO8) {
    if (player == UNI_A) {
      l.type = GO8_A;
    } else if (player == UNI_B) {
      l.type = GO8_B;
    } else {
      l.type = GO8_C;
    }
    g->listOfGO8s[g->numOfGO8s[UNI_A - OFFSET] +
      g->numOfGO8s[UNI_B - OFFSET] +
      g->numOfGO8s[UNI_C - OFFSET]] = l;
    g->numOfGO8s[player - OFFSET]++;
  } else {
    if (player == UNI_A) {
      l.type = ARC_A;
    } else if (player == UNI_B) {
      l.type = ARC_B;
    } else {
      l.type = ARC_C;
    }
    g->listOfARCs[g->numOfARCs[UNI_A - OFFSET] +
      g->numOfARCs[UNI_B - OFFSET] +
      g->numOfARCs[UNI_C - OFFSET]] = l;
    g->numOfARCs[player - OFFSET]++;
  }
}

static stance move(Game g, stance c, char step) {
  stance result;
  int counter = 0;

  if (step == 'R') {
    result.left = c.forward;
    result.right = c.right;

    neighbours n, m;
    memcpy(n, g->neighbouringRegions[c.right - OFFSET], REGIONS_PER_VERTEX);
    memcpy(m, g->neighbouringRegions[c.forward - OFFSET], REGIONS_PER_VERTEX);
    while (counter < NEIGHBOURS_PER_REGION) {
      if (n[counter] == m[counter]) {
        result.forward = n[counter];
        break;
      }

      counter++;
    }
  } else if (step == 'L') {
    result.left = c.left;
    result.right = c.forward;

    neighbours n, m;
    memcpy(n, g->neighbouringRegions[c.left - OFFSET], REGIONS_PER_VERTEX);
    memcpy(m, g->neighbouringRegions[c.forward - OFFSET], REGIONS_PER_VERTEX);
    while (counter < NEIGHBOURS_PER_REGION) {
      if (n[counter] == m[counter]) {
        result.forward = n[counter];
        break;
      }

      counter++;
    }
  } else {
    result.left = c.right;
    result.right = c.left;

    neighbours n, m;
    memcpy(n, g->neighbouringRegions[c.right - OFFSET], REGIONS_PER_VERTEX);
    memcpy(m, g->neighbouringRegions[c.left - OFFSET], REGIONS_PER_VERTEX);
    while (counter < NEIGHBOURS_PER_REGION) {
      if (n[counter] == m[counter]) {
        result.forward = n[counter];
        break;
      }
    }

    counter++;
  }

  return result;
}

static stance pathToRegion(Game g, path p) {
  int counter = 0;
  char nextStep = p[0];
  stance nextStance;
  nextStance.left = 0;
  nextStance.forward = 1;
  nextStance.right = 0;

  while (nextStep != 0 && counter < PATH_LIMIT) {
    nextStance = move(g, nextStance, nextStep);
    if (nextStance.left == 0 && nextStance.forward == 0 && nextStance.right == 0) {
      return nextStance;
    }
    counter++;
    nextStep = p[counter];
  }

  return nextStance;
}

static int isAdjacent(path origin, path toTest) {
  int adjacent = 0; // flag
  int counter = 0;
  int originEnd, toTestEnd;
  char current;

  while (counter < PATH_LIMIT) {
    current = origin[counter];
    if (origin[counter] == 0) {
      originEnd = counter;
    }

    current = toTest[counter];
    if (toTest[counter] == 0) {
      toTestEnd = counter;
    }
    counter++;
  }

  if (abs(originEnd - toTestEnd) == 1) {
    adjacent = 1;
  }

  return adjacent;
}

// Function implementations from Game.h
Game newGame (int discipline[], int dice[]) {
  Game g = malloc(GAME_SIZE);

  g->currentTurn = -1;
  g->whichPlayerTurn  = 0;
  memcpy(g->discipline, discipline, NUM_REGIONS);
  memcpy(g->dice, dice, NUM_REGIONS);

  neighbours nA = {2, 3, 5};
  memcpy(g->neighbouringRegions[0], nA, NEIGHBOURS_PER_REGION);
  neighbours nB = {1, 4, 5, 7};
  memcpy(g->neighbouringRegions[1], nB, NEIGHBOURS_PER_REGION);
  neighbours nC = {1, 5, 6, 8};
  memcpy(g->neighbouringRegions[2], nC, NEIGHBOURS_PER_REGION);
  neighbours nD = {2, 7, 9};
  memcpy(g->neighbouringRegions[3], nD, NEIGHBOURS_PER_REGION);
  neighbours nE = {1, 2, 3, 7, 8, 10};
  memcpy(g->neighbouringRegions[4], nE, NEIGHBOURS_PER_REGION);
  neighbours nF = {3, 8, 11};
  memcpy(g->neighbouringRegions[5], nF, NEIGHBOURS_PER_REGION);
  neighbours nG = {2, 4, 5, 9, 10, 12};
  memcpy(g->neighbouringRegions[6], nG, NEIGHBOURS_PER_REGION);
  neighbours nH = {3, 5, 6, 10, 11, 13};
  memcpy(g->neighbouringRegions[7], nH, NEIGHBOURS_PER_REGION);
  neighbours nI = {4, 7, 12, 14};
  memcpy(g->neighbouringRegions[8], nI, NEIGHBOURS_PER_REGION);
  neighbours nJ = {5, 7, 8, 12, 13, 15};
  memcpy(g->neighbouringRegions[9], nJ, NEIGHBOURS_PER_REGION);
  neighbours nK = {6, 8, 13, 16};
  memcpy(g->neighbouringRegions[10], nK, NEIGHBOURS_PER_REGION);
  neighbours nL = {7, 9, 10, 14, 15, 17};
  memcpy(g->neighbouringRegions[11], nL, NEIGHBOURS_PER_REGION);
  neighbours nM = {8, 10, 11, 15, 16, 18};
  memcpy(g->neighbouringRegions[12], nM, NEIGHBOURS_PER_REGION);
  neighbours nN = {9, 12, 17};
  memcpy(g->neighbouringRegions[13], nN, NEIGHBOURS_PER_REGION);
  neighbours nO = {10, 12, 13, 17, 18, 19};
  memcpy(g->neighbouringRegions[14], nO, NEIGHBOURS_PER_REGION);
  neighbours nP = {11, 13, 18};
  memcpy(g->neighbouringRegions[15], nP, NEIGHBOURS_PER_REGION);
  neighbours nQ = {12, 14, 15, 19};
  memcpy(g->neighbouringRegions[16], nQ, NEIGHBOURS_PER_REGION);
  neighbours nR = {13, 15, 16, 19};
  memcpy(g->neighbouringRegions[17], nR, NEIGHBOURS_PER_REGION);
  neighbours nS = {15, 17, 18};
  memcpy(g->neighbouringRegions[18], nS, NEIGHBOURS_PER_REGION);

  int counter = 0;
  location list[MAX_VERTICES];
  while (counter < NUM_UNIS) {
    location campus = g->listOfCampuses[counter];

    g->studentsBPS[counter] += 3;
    g->studentsBQN[counter] += 3;
    g->studentsMJ[counter]++;
    g->studentsMTV[counter]++;
    g->studentsMMoney[counter]++;

    // init campuses
    if (counter == UNI_A - OFFSET) {
      path l = {};
      memcpy(campus.destination, l, PATH_LIMIT);
      campus.type = CAMPUS_A;
      list[0] = campus;
      path k = {'R', 'R', 'L', 'R', 'L', 'L', 'R', 'L', 'R', 'L', 'L', 'R', 'L', 'R', 'L'};
      memcpy(campus.destination, k, PATH_LIMIT);
      campus.type = CAMPUS_A;
      list[1] = campus;
    } else if (counter == UNI_B - OFFSET) {
      path l = {'R', 'R', 'L', 'R', 'L'};
      memcpy(campus.destination, l, PATH_LIMIT);
      campus.type = CAMPUS_B;
      list[2] = campus;
      path k = {'L', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'L'};
      memcpy(campus.destination, k, PATH_LIMIT);
      campus.type = CAMPUS_B;
      list[3] = campus;
    } else {
      path l = {'L', 'R', 'L', 'R', 'L'};
      memcpy(campus.destination, l, PATH_LIMIT);
      campus.type = CAMPUS_C;
      list[4] = campus;
      path k = {'R', 'R', 'L', 'R', 'L', 'L', 'R', 'L', 'R', 'L'};
      memcpy(campus.destination, k, PATH_LIMIT);
      campus.type = CAMPUS_C;
      list[5] = campus;
    }
    g->numOfCampuses[counter] += 2;

    counter++;
  }

  memcpy(g->listOfCampuses, list, MAX_VERTICES);

  location l;

  path p = {'R', 'R'};
  memcpy(p, l.destination, PATH_LIMIT);
  l.type = STUDENT_MTV;
  g->listOfExchanges[0] = l;

  path q = {'R'};
  memcpy(q, l.destination, PATH_LIMIT);
  l.type = STUDENT_MTV;
  g->listOfExchanges[1] = l;

  path r = {'L', 'R'};
  memcpy(r, l.destination, PATH_LIMIT);
  l.type = STUDENT_MMONEY;
  g->listOfExchanges[2] = l;

  path s = {'L', 'R', 'L'};
  memcpy(s, l.destination, PATH_LIMIT);
  l.type = STUDENT_MMONEY;
  g->listOfExchanges[3] = l;

  path t = {'R', 'R', 'L', 'R', 'L', 'L', 'R', 'L', 'R', 'L', 'L'};
  memcpy(t, l.destination, PATH_LIMIT);
  l.type = STUDENT_BPS;
  g->listOfExchanges[4] = l;

  path u = {'R', 'R', 'L', 'R', 'L', 'L', 'R', 'L', 'R', 'L', 'L', 'R'};
  memcpy(u, l.destination, PATH_LIMIT);
  l.type = STUDENT_BPS;
  g->listOfExchanges[5] = l;

  path v = {'L', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'R'};
  memcpy(v, l.destination, PATH_LIMIT);
  l.type = STUDENT_MJ;
  g->listOfExchanges[6] = l;

  path w = {'L', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R', 'L', 'R', 'R', 'L'};
  memcpy(w, l.destination, PATH_LIMIT);
  l.type = STUDENT_MJ;
  g->listOfExchanges[7] = l;

  path x = {'L', 'R', 'L', 'R', 'L', 'R', 'R', 'L', 'R'};
  memcpy(x, l.destination, PATH_LIMIT);
  l.type = STUDENT_BQN;
  g->listOfExchanges[8] = l;

  path y = {'L', 'R', 'L', 'R', 'L', 'R', 'R', 'L'};
  memcpy(y, l.destination, PATH_LIMIT);
  l.type = STUDENT_BQN;
  g->listOfExchanges[9] = l;

  return g;
}

void disposeGame (Game g) {
  free(g);
}

void makeAction (Game g, action a) {
  // assert(isLegalAction(g, a));

  if (a.actionCode == BUILD_CAMPUS) {
    int player = g->whichPlayerTurn - OFFSET;
    g->studentsBPS[player]--;
    g->studentsBQN[player]--;
    g->studentsMJ[player]--;
    g->studentsMTV[player]--;
    addLocation(g, a);
  } else if (a.actionCode == BUILD_GO8) {
    int player = g->whichPlayerTurn - OFFSET;
    g->studentsMJ[player] -= 2;
    g->studentsMMoney[player] -= 3;
    addLocation(g, a);
  } else if (a.actionCode == OBTAIN_ARC) {
    int player = g->whichPlayerTurn - OFFSET;
    g->studentsBPS[player]--;
    g->studentsBQN[player]--;
    addLocation(g, a);
  } else if (a.actionCode == START_SPINOFF) {
    int player = g->whichPlayerTurn - OFFSET;
    g->studentsMJ[player]--;
    g->studentsMTV[player]--;
    g->studentsMMoney[player]--;
  } else if (a.actionCode == OBTAIN_PUBLICATION) {
    int player = g->whichPlayerTurn - OFFSET;
    g->numOfPublications[player]++;
  } else if (a.actionCode == OBTAIN_IP_PATENT) {
    int player = g->whichPlayerTurn - OFFSET;
    g->numOfIPPatents[player]++;
  } else if (a.actionCode == RETRAIN_STUDENTS) {
    int player = g->whichPlayerTurn;
    int rate = getExchangeRate(g, player, a.disciplineFrom, a.disciplineTo);

    if (a.disciplineFrom == STUDENT_BPS) {
      g->studentsBPS[player - OFFSET] -= rate;
    } else if (a.disciplineFrom == STUDENT_BQN) {
      g->studentsBQN[player - OFFSET] -= rate;
    } else if (a.disciplineFrom == STUDENT_MJ) {
      g->studentsMJ[player - OFFSET] -= rate;
    } else if (a.disciplineFrom == STUDENT_MTV) {
      g->studentsMTV[player - OFFSET] -= rate;
    } else if (a.disciplineFrom == STUDENT_MMONEY) {
      g->studentsMMoney[player - OFFSET] -= rate;
    }

    if (a.disciplineTo == STUDENT_BPS) {
      g->studentsBPS[player - OFFSET]++;
    } else if (a.disciplineTo == STUDENT_BQN) {
      g->studentsBQN[player - OFFSET]++;
    } else if (a.disciplineTo == STUDENT_MJ) {
      g->studentsMJ[player - OFFSET]++;
    } else if (a.disciplineTo == STUDENT_MTV) {
      g->studentsMTV[player - OFFSET]++;
    } else if (a.disciplineTo == STUDENT_MMONEY) {
      g->studentsMMoney[player - OFFSET]++;
    }
  }
}

void throwDice (Game g, int diceScore) {
  g->currentTurn++;
  g->diceValue = diceScore;
  g->whichPlayerTurn++;
  if (g->whichPlayerTurn == UNI_C + OFFSET) {
    g->whichPlayerTurn = UNI_A;
  }

  int counter = 0;
  while (counter < NUM_UNIS) {
    if (diceScore == 7) {
      g->studentsThD[counter] += g->studentsMTV[counter] + g->studentsMMoney[counter];
      g->studentsMTV[counter] = 0;
      g->studentsMMoney[counter] = 0;
    }

    counter++;
  }

  counter = 0;
  while (counter < MAX_VERTICES) {
    int regions[REGIONS_PER_VERTEX] = {pathToRegion(g, g->listOfCampuses[counter].destination).left,
      pathToRegion(g, g->listOfCampuses[counter].destination).forward,
      pathToRegion(g, g->listOfCampuses[counter].destination).right};

    int dice = 0;
    while (dice < REGIONS_PER_VERTEX) {
      if (getDiceValue(g, regions[dice]) == diceScore) {
        int region = 0;
        while (region < REGIONS_PER_VERTEX) {
          if (getDiscipline(g, regions[region]) == STUDENT_THD) {
            if (g->listOfCampuses[counter].type <= CAMPUS_C) {
              g->studentsThD[g->listOfCampuses[counter].type - OFFSET]++;
            } else {
              g->studentsThD[g->listOfCampuses[counter].type - GO8_A] += 2;
            }
          } else if (getDiscipline(g, regions[region]) == STUDENT_BPS) {
            if (g->listOfCampuses[counter].type <= CAMPUS_C) {
              g->studentsBPS[g->listOfCampuses[counter].type - OFFSET]++;
            } else {
              g->studentsBPS[g->listOfCampuses[counter].type - GO8_A] += 2;
            }
          } else if (getDiscipline(g, regions[region]) == STUDENT_BQN) {
            if (g->listOfCampuses[counter].type <= CAMPUS_C) {
              g->studentsBQN[g->listOfCampuses[counter].type - OFFSET]++;
            } else {
              g->studentsBQN[g->listOfCampuses[counter].type - GO8_A] += 2;
            }
          } else if (getDiscipline(g, regions[region]) == STUDENT_MJ) {
            if (g->listOfCampuses[counter].type <= CAMPUS_C) {
              g->studentsMJ[g->listOfCampuses[counter].type - OFFSET]++;
            } else {
              g->studentsMJ[g->listOfCampuses[counter].type - GO8_A] += 2;
            }
          } else if (getDiscipline(g, regions[region]) == STUDENT_MTV) {
            if (g->listOfCampuses[counter].type <= CAMPUS_C) {
              g->studentsMTV[g->listOfCampuses[counter].type - OFFSET]++;
            } else {
              g->studentsMTV[g->listOfCampuses[counter].type - GO8_A] += 2;
            }
          } else if (getDiscipline(g, regions[region]) == STUDENT_MMONEY) {
            if (g->listOfCampuses[counter].type <= CAMPUS_C) {
              g->studentsMMoney[g->listOfCampuses[counter].type - OFFSET]++;
            } else {
              g->studentsMMoney[g->listOfCampuses[counter].type - GO8_A] += 2;
            }
          }

          region++;
        }
      }

      dice++;
    }

    counter++;
  }
}

int getDiscipline (Game g, int regionID) {
  return g->discipline[regionID - OFFSET];
}

int getDiceValue (Game g, int regionID) {
  return g->dice[regionID - OFFSET];
}

int getMostARCs (Game g) {
  int largest = 0;
  int player;
  int counter = 0;

  if (g->currentTurn == -1) {
    return NO_ONE;
  }

  while (counter < NUM_UNIS) {
    if (g->numOfARCs[counter] > largest) {
      largest = g->numOfARCs[counter];
      player = counter + OFFSET;
    }
    counter++;
  }

  return player;
}

int getMostPublications (Game g) {
  int largest = 0;
  int player;
  int counter = 0;

  if (g->currentTurn == -1) {
    return NO_ONE;
  }

  while (counter < NUM_UNIS) {
    if (g->numOfPublications[counter] > largest) {
      largest = g->numOfPublications[counter];
      player = counter + OFFSET;
    }

    counter++;
  }

  return player;
}

int getTurnNumber (Game g) {
  return g->currentTurn;
}

int getWhoseTurn (Game g) {
  if (g->currentTurn == -1) {
    return NO_ONE;
  } else {
    return g->whichPlayerTurn;
  }
}

int getCampus(Game g, path pathToVertex) {
  int counter = 0;
  int result = VACANT_VERTEX;

  while (counter < MAX_VERTICES) {
    location l = g->listOfCampuses[counter];
    if (memcmp(l.destination, pathToVertex, PATH_LIMIT) == 0) {
      result = l.type;
    }

    counter++;
  }

  if (result == VACANT_VERTEX) {
    counter = 0;
    while (counter < MAX_VERTICES) {
      location l = g->listOfGO8s[counter];
      if (memcmp(l.destination, pathToVertex, PATH_LIMIT) == 0) {
        result = l.type;
      }

      counter++;
    }
  }

  return result;
}

int getARC(Game g, path pathToEdge) {
  int counter = 0;
  int result = VACANT_ARC;

  while (counter < MAX_VERTICES) {
    location l = g->listOfARCs[counter];
    if (memcmp(l.destination, pathToEdge, PATH_LIMIT) == 0) {
      result = l.type;
    }

    counter++;
  }

  return result;
}

int isLegalAction (Game g, action a) {
  int isLegal = 0;

  if (g->currentTurn == -1) {
    return isLegal;
  }

  if (a.actionCode == PASS) {
    isLegal = 1;
  } else if (a.actionCode == BUILD_CAMPUS) {
    int player = g->whichPlayerTurn - OFFSET;
    assert(pathToRegion(g, a.destination).left != 0 &&
      pathToRegion(g, a.destination).forward != 0 &&
      pathToRegion(g, a.destination).right != 0);
    int counter = 0;
    int adjacent = 0;
    while (counter < MAX_VERTICES) {
      if (isAdjacent(a.destination, g->listOfARCs[counter].destination)) {
        if (g->listOfARCs[counter].type == CAMPUS_A || g->listOfARCs[counter].type == GO8_A) {
          adjacent = 1;
        }
      }

      counter++;
    }
    assert(adjacent);

    if (g->studentsBPS[player] >= 1 && g->studentsBQN[player] >= 1 &&
      g->studentsMJ[player] >= 1 && g->studentsMTV[player] >= 1) {
        isLegal = 1;
      }
  } else if (a.actionCode == BUILD_GO8) {
    int player = g->whichPlayerTurn - OFFSET;
    assert(pathToRegion(g, a.destination).left != 0 &&
      pathToRegion(g, a.destination).forward != 0 &&
      pathToRegion(g, a.destination).right != 0);
    int counter = 0;
    int adjacent = 0;
    while (counter < MAX_VERTICES) {
      if (isAdjacent(a.destination, g->listOfARCs[counter].destination)) {
        if (g->listOfARCs[counter].type == CAMPUS_A || g->listOfARCs[counter].type == GO8_A) {
          adjacent = 1;
        }
      }

      counter++;
    }
    assert(adjacent);

    if (g->studentsMJ[player] >= 2 && g->studentsMMoney[player] >= 3) {
      if (g->numOfGO8s[UNI_A - OFFSET] + g->numOfGO8s[UNI_B - OFFSET] + g->numOfGO8s[UNI_C - OFFSET] <= 8) {
        isLegal = 1;
      }
    }
  } else if (a.actionCode == OBTAIN_ARC) {
    int player = g->whichPlayerTurn - OFFSET;
    assert(pathToRegion(g, a.destination).left != 0 &&
      pathToRegion(g, a.destination).forward != 0 &&
      pathToRegion(g, a.destination).right != 0);
    int counter = 0;
    int adjacent = 0;
    while (counter < MAX_VERTICES) {
      if (isAdjacent(a.destination, g->listOfGO8s[counter].destination) ||
        isAdjacent(a.destination, g->listOfCampuses[counter].destination) ||
        isAdjacent(a.destination, g->listOfARCs[counter].destination)) {
          if (g->listOfARCs[counter].type == CAMPUS_A || g->listOfARCs[counter].type == GO8_A) {
            adjacent = 1;
          }
      }

      counter++;
    }
    assert(adjacent);

    if (g->studentsBPS[player] >= 1 && g->studentsBQN[player] >= 1) {
      isLegal = 1;
    }
  } else if (a.actionCode == START_SPINOFF) {
    int player = g->whichPlayerTurn - OFFSET;
    if (g->studentsMJ[player] >= 1 && g->studentsMTV[player] >= 1 &&
      g->studentsMMoney[player] >= 1) {
        isLegal = 1;
      }
  } else if (a.actionCode == OBTAIN_PUBLICATION) {
    isLegal = 1;
  } else if (a.actionCode == OBTAIN_IP_PATENT) {
    isLegal = 1;
  } else if (a.actionCode == RETRAIN_STUDENTS) {
    int player = g->whichPlayerTurn;
    int rate = getExchangeRate(g, player, a.disciplineFrom, a.disciplineTo);
    if (a.disciplineFrom == STUDENT_BPS) {
      if (g->studentsBPS[player - OFFSET] >= rate) {
        isLegal = 1;
      }
    } else if (a.disciplineFrom == STUDENT_BQN) {
      if (g->studentsBQN[player - OFFSET] >= rate) {
        isLegal = 1;
      }
    } else if (a.disciplineFrom == STUDENT_MJ) {
      if (g->studentsMJ[player - OFFSET] >= rate) {
        isLegal = 1;
      }
    } else if (a.disciplineFrom == STUDENT_MTV) {
      if (g->studentsMTV[player - OFFSET] >= rate) {
        isLegal = 1;
      }
    } else if (a.disciplineFrom == STUDENT_MMONEY) {
      if (g->studentsMMoney[player - OFFSET] >= rate) {
        isLegal = 1;
      }
    }
  }

  return isLegal;
}

int getKPIpoints (Game g, int player) {
  int points = 0;

  if (getMostPublications(g) == player) {
    points += 10;
  } if (getMostARCs(g) == player) {
    points += 10;
  }

  points += g->numOfIPPatents[player - OFFSET] * 10;
  points += g->numOfCampuses[player - OFFSET] * 10;
  points += g->numOfGO8s[player - OFFSET] * 20;
  points += g->numOfARCs[player - OFFSET] * 2;

  return points;
}

int getARCs (Game g, int player) {
  return g->numOfARCs[player - OFFSET];
}

int getGO8s (Game g, int player) {
  return g->numOfGO8s[player - OFFSET];
}

int getCampuses (Game g, int player) {
  return g->numOfCampuses[player - OFFSET];
}

int getIPs (Game g, int player) {
  return g->numOfIPPatents[player - OFFSET];
}

int getPublications (Game g, int player) {
  return g->numOfPublications[player - OFFSET];
}

int getStudents (Game g, int player, int discipline) {
  int students = 0;

  if (discipline == STUDENT_THD) {
    students = g->studentsThD[player - OFFSET];
  } else if (discipline == STUDENT_BPS) {
    students = g->studentsBPS[player - OFFSET];
  } else if (discipline == STUDENT_BQN) {
    students = g->studentsBQN[player - OFFSET];
  } else if (discipline == STUDENT_MJ) {
    students = g->studentsMJ[player - OFFSET];
  } else if (discipline == STUDENT_MTV) {
    students = g->studentsMTV[player - OFFSET];
  } else if (discipline == STUDENT_MMONEY) {
    students = g->studentsMMoney[player - OFFSET];
  }

  return students;
}

int getExchangeRate (Game g, int player, int disciplineFrom, int disciplineTo) {
  int counter = 0;
  int campus;

  while (counter < MAX_VERTICES) {
    campus = 0;
    while (campus < NUM_OF_EXCHANGES) {
      if (g->listOfCampuses[campus].type == CAMPUS_A || g->listOfCampuses[campus].type == GO8_A) {
        if (memcmp(g->listOfExchanges[counter].destination, g->listOfCampuses[campus].destination, PATH_LIMIT) == 0) {
          if (g->listOfExchanges[counter].type == disciplineTo) {
            return 2;
          }
        }
      }
    }
  }

  return 4;
}
