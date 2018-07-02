#include <stdlib.h>
#include <stdio.h>


typedef struct _node *link;

typedef struct _node {
	int value;
	link next;
} node;

typedef struct _list {
	link head;
} *list;

void reverse(list l) {
	link prev = NULL;
	link current = l->head;
	link next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	l->head = prev;
}

list zip(list l1,list l2) {
	int count = 0;
	link l1Value = l1->head;
	link nextl1Value = NULL;
	link l2Value = l2->head;
	link nextl2Value = NULL;

	list newList = malloc(sizeof(list));
	newList->head = l1Value;

	while (l1Value != NULL && l2Value != NULL) {
		nextl1Value = l1Value->next;
		nextl2Value = l2Value->next;
		l1Value->next = l2Value;
		l2Value->next = nextl1Value;
		l1Value = nextl1Value;
		l2Value = nextl2Value;
		count ++;
	}

	return newList;
}

int linkedListSize(list l) {
	int size = 0;
	link curr = l->head;
	while (curr != NULL) {
		curr = curr->next;
		size ++;
	}
	return size;
}

void printList(list l) {
	link curr = l->head;
	while(curr != NULL) {
		printf("%d -> ",curr->value);
		curr = curr->next;
	}
	printf("NULL\n");
}

link createLink(int value) {
	link currentLink = malloc(sizeof(link));
	currentLink->value = value;
	currentLink->next = NULL;
	return currentLink;
}

int main() {
	list l = malloc(sizeof(list));
	link one = createLink(1);
	link two = createLink(2);
	link three = createLink(3);
	link four = createLink(4);
	l->head = one;
	one->next = two;
	two->next = three;
	three->next = four;

	list l2 = malloc(sizeof(list));
	link one2 = createLink(5);
	link two2 = createLink(6);
	link three2 = createLink(7);
	link four2 = createLink(8);
	l2->head = one2;
	one2->next = two2;
	two2->next = three2;
	three2->next = four2;

	printList(l);
	printList(l2);
	list zippedList = zip(l,l2);
	printList(zippedList);
	reverse(zippedList);
	printList(zippedList);
}
