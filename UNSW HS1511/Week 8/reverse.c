#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse (char *message);

int main() {
    char *string = "Hello";
    printf("%s\n",reverse(string));
    return EXIT_SUCCESS;
}

char *reverse (char *message) {
    int size = 0;
    int count = 0;
    while(message[size] != '\0') {
        size ++;
    }
    char *pointer = malloc(sizeof(char) * size);
    while(message[count] != '\0') {
        pointer[count] = message[(size-1)- count];
        count ++;
    }
    pointer[count] = '\0'; 
    return pointer;
}