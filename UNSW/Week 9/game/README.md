# Game.c
HS1511 Game.c


testGame.c 
Project homepage
 
**NOTE: You can't create groups for the Knowledge Island/Game tasks until AFTER the Mandelbrot due date**
 

The KI team task 1.0: testGame.c
To implement  unit tests for the interface functions in Game.h .

Check out Game.h

 

Create a Group of 4.
You'll need to create a Game ADT foursome group if you have not already done so.  To create your GameADT4 group follow these instructions. 

What to Do
In your team of four:

Pretend all the functions in Game.c have already been written.  
Plan and write testGame.c - which #includes Game.h and which contains a main function which
creates a Game (or several Games) and uses them to
extensively test the Game ADT interface functions.  Do this exactly like the other unit tests we have written in class.  E.g. test using asserts.
At the end, if you have passed all the tests, printf "All tests passed, you are Awesome!".
What to submit
Submit your testGame.c file in your project foursome below. You'll need to create a Game ADT foursome group if you have not already done so - make sure your nominated group submitter submits the file on behalf of that group.

Submit your first draft of testGame.c file in your project foursome by the given due date. (You can then resubmit and improve your code during the next 2 weeks or so timeframe after that where we run your tests against other groups game implementations).

To check your submission compiles please check on a cse machine. Note that this will not create a runnable executable but will help type check your code.  We will be compiling your code for the competition with the following compiler and options.

clang -Wall -Werror -g -std=c99 -shared -fPIC testGame.c -o testGame.so
Peeping Ahead...
To come in tasks next week:

Teamwork 2.0: Game.c

In your team of four:

implement the Game logic by creating and implementing the methods of Game.c.  Note that the Game is to be an ADT (with interface given in Game.h).
Teamwork 3.0: runGame.c

Pretend all the functions in Game.c have already been written (even if they haven't been finished yet)

In your team of four

write in a file called runGame.c (which #includes Game.h) and contains a main function which lets you interactively step through a game, i.e. the user types in what action to perform rather than asking the player AIs which you will write later in a subsequent task.
i.e. the runGame program should let you manually decide and input (using scanf) the move each player makes in turn, and the dice rolls, until the game is over.
