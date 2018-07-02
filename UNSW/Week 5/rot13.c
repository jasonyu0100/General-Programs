#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define START_OF_LOWER 97
#define START_OF_UPPER 65

char encode(char c);
void testEncode(void);

int main(void) {
    testEncode();
	return EXIT_SUCCESS;
}

void testEncode(void) {
    assert(encode('a')=='n');
    assert(encode('b')=='o');
    assert(encode('c')=='p');
    assert(encode('z')=='m');
    assert(encode('A')=='N');
    assert(encode('B')=='O');
    assert(encode('C')=='P');
    assert(encode('Z')=='M');
    printf("All test passed!\n");
}


char encode(char c) {
	char new;
    int charRepresentation = c;
	if ((charRepresentation >= START_OF_LOWER) && (charRepresentation < (START_OF_LOWER + 26))) {
        charRepresentation += 13;
		int difference = (charRepresentation - START_OF_LOWER) % 26;
		new = START_OF_LOWER + difference;
	} else if ((charRepresentation >= START_OF_UPPER) && (charRepresentation < (START_OF_UPPER + 26))) {
        charRepresentation += 13;
		int difference = (charRepresentation - START_OF_UPPER) % 26;
		new = START_OF_UPPER + difference;
	} else {
		new = charRepresentation;
    }
	return new;
}
