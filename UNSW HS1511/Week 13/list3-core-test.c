// a concrete linked list
 
// list is a pointer to a struct - containing the head ptr
// 18 may 2014 tests expanded. includes tests on append to 
// explicitly detect non-null "next" in the appended node.
 
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list3-core.h"
 
 
// simple unit tests on the list
static void testList (void);
 
int main (int argc, char *argv[])  {
    printf ("Testing list3-core...\n");
    testList();
    printf ("All list3-core tests passed!  You are awesome\n");
 
    return EXIT_SUCCESS;
}
 
 
static void testList (void) {
    // create empty lst
    list myList = malloc (sizeof (*myList));
    myList->head = NULL;
    // myList is a struct which has an element head which
    // points to the first node of the list aka the head
 
 
    // simple test on showlist and numItems
    showList (myList);
    assert (numItems (myList) == 0);
 
    // attach one node to the list
    link ptrToNewNode = malloc (sizeof(node));
    assert (ptrToNewNode != NULL); 
    ptrToNewNode->value = 1;
    ptrToNewNode->next = NULL;
    myList->head = ptrToNewNode;  
 
    // simple test on showlist and numItems
    showList (myList);
    assert (numItems (myList) == 1);
 
    // attach a second node to the list
    ptrToNewNode = malloc (sizeof (node));
    assert (ptrToNewNode != NULL);  
 
    ptrToNewNode->value = 2;
    ptrToNewNode->next = NULL;
 
    myList->head->next = ptrToNewNode;
 
    showList (myList);
    assert (numItems (myList) == 2);
 
    // insert a node containing 0 at te head, ie before 
    // the 1->2->X list, to produce 0->1->2->X
 
    frontInsert (myList, 0); 
    assert (myList != NULL);
    assert (myList->head != NULL);
    assert (myList->head->value == 0);
    assert (myList->head->next  != NULL);
    assert (myList->head->next->value == 1);
 
    showList (myList);
    assert (numItems (myList) == 3);
 
    // insert at end 
    append (myList, 4);
 
    assert (myList != NULL);
    assert (myList->head != NULL);
    assert (myList->head->next != NULL);
    assert (myList->head->next->next != NULL);
    assert (myList->head->next->next->next != NULL);
    assert (myList->head->next->next->next->value == 4);
    assert (myList->head->next->next->next->next  == NULL);
 
    showList (myList);
    assert (numItems (myList) == 4);
 
    // test lookup
    assert (lookup (myList,0)==0);
    assert (lookup (myList,1)==1);
    assert (lookup (myList,2)==2);
    assert (lookup (myList,3)==4);

    printf ("testing newList()\n");
    list testList = newList();
    assert (testList->head == NULL);
 
 
    printf ("testing deleteHead()\n");
    // create a 3 element list
    testList->head = malloc (sizeof (node));
    testList->head->value = 3;
    testList->head->next  = malloc (sizeof (node));
    testList->head->next->value = 1;
    testList->head->next->next  = malloc (sizeof (node));
    testList->head->next->next->value = 4;
    testList->head->next->next->next  = NULL;
 
    deleteHead (testList);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 1);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 4);
    assert (testList->head->next->next == NULL);
 
    deleteHead (testList);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 4);
    assert (testList->head->next == NULL);
 
    deleteHead (testList);
 
    assert (testList != NULL);
    assert (testList->head == NULL);
 
 
    printf ("testing deleteLast()\n");
    // create a 3 element list
    testList->head = malloc (sizeof (node));
    testList->head->value = 3;
    testList->head->next  = malloc (sizeof (node));
    testList->head->next->value = 1;
    testList->head->next->next  = malloc (sizeof (node));
    testList->head->next->next->value = 4;
    testList->head->next->next->next  = NULL;
 
    deleteLast (testList);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 1);
    assert (testList->head->next->next == NULL);
 
    deleteLast (testList);
 
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next == NULL);
    showList(testList);
    deleteLast (testList);
    showList(testList);
    assert (testList != NULL);
    assert (testList->head == NULL);
 
 
    printf ("testing concatenate()\n");
 
    // (3,2) -> (5,0)
    // create a 3 element list
    testList->head = malloc (sizeof (node));
    testList->head->value = 3;
    testList->head->next  = malloc (sizeof (node));
    testList->head->next->value = 1;
    testList->head->next->next  = malloc (sizeof (node));
    testList->head->next->next->value = 4;
    testList->head->next->next->next  = NULL;
 
    // create a two element list
    list testListB = newList();
 
    testListB->head = malloc (sizeof (node));
    testListB->head->value = 1;
    testListB->head->next  = malloc (sizeof (node));
    testListB->head->next->value = 5;
    testListB->head->next->next  = NULL;
    showList(testList);
    showList(testListB);

    concatenate (testList, testListB);
    showList(testList);
    assert (testListB != NULL);
    assert (testListB->head == NULL);
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 1);
    assert (testList->head->next->next != NULL);
    assert (testList->head->next->next->value == 4);
    assert (testList->head->next->next->next != NULL);
    assert (testList->head->next->next->next->value == 1);
    assert (testList->head->next->next->next->next != NULL);
    assert (testList->head->next->next->next->next->value == 5);
    assert (testList->head->next->next->next->next->next == NULL);
    
 
    // (5,0) -> (5,0)
    concatenate (testList, testListB);
    assert (testListB != NULL);
    assert (testListB->head == NULL);
    
    assert (testList != NULL);
    assert (testList->head != NULL);
    assert (testList->head->value == 3);
    assert (testList->head->next != NULL);
    assert (testList->head->next->value == 1);
    assert (testList->head->next->next != NULL);
    assert (testList->head->next->next->value == 4);
    assert (testList->head->next->next->next != NULL);
    assert (testList->head->next->next->next->value == 1);
    assert (testList->head->next->next->next->next != NULL);
    assert (testList->head->next->next->next->next->value == 5);
    assert (testList->head->next->next->next->next->next == NULL);
 
    // (0,5) -> (5,0)
    
    concatenate (testListB, testList);
    
    assert (testList != NULL);
    assert (testList->head == NULL);
 
    assert (testListB != NULL);
    assert (testListB->head != NULL);
    assert (testListB->head->value == 3);
    assert (testListB->head->next != NULL);
    assert (testListB->head->next->value == 1);
    assert (testListB->head->next->next != NULL);
    assert (testListB->head->next->next->value == 4);
    assert (testListB->head->next->next->next != NULL);
    assert (testListB->head->next->next->next->value == 1);
    assert (testListB->head->next->next->next->next != NULL);
    assert (testListB->head->next->next->next->next->value == 5);
    assert (testListB->head->next->next->next->next->next == NULL);
 
    printf ("testing count42s()\n");
    assert (count42s (testList) == 0);
    assert (count42s (testListB) == 0);
 
    testListB->head->value = 42;
    assert (count42s (testListB) == 1);
 
    testListB->head->next->value = 42;
    assert (count42s (testListB) == 2);
 
    testListB->head->next->next->value = 42;
    assert (count42s (testListB) == 3);
 
    testListB->head->next->next->next->value = 42;
    assert (count42s (testListB) == 4);
 
    testListB->head->next->next->next->next->value = 42;
    assert (count42s (testListB) == 5);
 
 
}