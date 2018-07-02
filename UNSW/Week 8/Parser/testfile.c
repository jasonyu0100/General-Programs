#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getSubString(char *string, int start, int end);
int main() {
    double thing = 5;
    printf("%f\n",thing);
    printf("%d\n",1 / 5);
    char *buff = "this is a test string";
    int start = 10;
    int end = 13;
    printf("word: %s\n",getSubString(buff, start, end));
}

char* getSubString(char *string, int start, int end) {
    int size = end - start + 1;
    char subString[size];
    char *pointer;
    pointer = malloc(size * sizeof(char));
    memcpy(subString, &string[start], size);
    subString[size] = '\0';
    pointer = subString;
    pointer = "6254";
    return pointer;
}