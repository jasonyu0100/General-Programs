// a concrete linked list
// list is a pointer to a struct - containing the head ptr
// v1.1 fixed error found by Christopher Chaaya and now sets
// the next field of newly created nodes to be NULL:
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list3-core.h"
 
// print out a list
void showList(list listToPrint) {
    assert(listToPrint != NULL);
    link current = listToPrint->head;
    while (current != NULL) {
        printf("%d",current->value);
        current = current->next;
    }
    printf ("X\n");
}

// inset item at the front of the list
void frontInsert (list l, int item) {
    assert(l != NULL);
    link previousNode = l->head;
    link newNode = malloc(sizeof(link));
    newNode->value = item;
    newNode->next = previousNode;
    l->head = newNode;
}

// count the number of items in the list
int numItems (list l) {
    assert(l != NULL);
    int count = 0;
    link current = l->head;
    while (current != NULL) {
        current = current->next;
        count ++;
    }
    return count;
}

// insert at end of list
void append (list l, int value) {
    assert(l != NULL);
    link current = l->head;
    while (current->next != NULL) {
        current = current->next;
    }
    link newNode = malloc(sizeof(link));
    newNode->value = value;
    newNode->next = NULL;
    current->next = newNode;
}

// find the value stored at position i
// i MUST be a valid position in the list
// dont call this on positions outside the list
int lookup (list l, int position) {
    assert(l != NULL);
    int count = 0;
    link current = l->head; 
    while (count < position) {
        current = current->next;
        count ++;
    }
    assert(current != NULL);
    return current->value;
}