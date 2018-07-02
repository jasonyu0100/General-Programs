#include <iostream>
#include <cstdlib>
using namespace std;

struct book {
	char title[50];
	char author[50];
	int id;
};

typedef struct book *Book;


void printBook(struct book curr);

int main() {
	struct book myBook;
	strcpy(myBook.title,"Madsf");
	strcpy(myBook.author,"afds");
	myBook.id = 1324;
	printBook(myBook);
	Book thing = (Book)malloc(sizeof(struct book));
	printBook(*thing);
}

void printBook(struct book curr) {
	cout << curr.title << endl;
	cout << curr.author << endl;
	cout << curr.id << endl;
}