#include <stdio.h>
#include <stdlib.h>

typedef struct _node *link;

typedef struct _node {
	int value;
	link next;
} node;

typedef struct _list {
	link head;
} *list;

void printList(list l);
link createNode(int value);

void insertValue(int value, int position,list l);

int main(void) {
	list linkedList = malloc(sizeof(list));
	link first = createNode(1);
	link two = createNode(2);
	link three = createNode(3);
	linkedList->head = first;
	first->next = two;
	two->next = three;
	three->next = NULL;

	printList(linkedList);
	insertValue(4,2,linkedList);
	printList(linkedList);

	return EXIT_SUCCESS;
}

void printList(list l) {
	link curr = l->head;
	while (curr != NULL) {
		int currentValue = curr->value;
		printf("%d->",currentValue);
		curr = curr->next;
	}
	printf("NULL\n");
}

void insertValue(int value, int position,list l) {
	link currentValue = createNode(value);
	link curr = l->head;
	if (position == 0) {
		l->head = currentValue;
	} else {
		int count = 1;
		while (curr != NULL && count < position) {
			printf("asdf");
			curr = curr->next;
			count ++;
		}
		link nextNode = curr->next;
		curr->next = currentValue;
		currentValue->next = nextNode;
	}

}

link createNode(int value) {
	link currentLink = malloc(sizeof(link));
	currentLink->value = value;
	currentLink->next = NULL;
	return currentLink;
}
