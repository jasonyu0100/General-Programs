#include <iostream>
using namespace std;

double average(double array[],int n);

int main(void) {
	double array[]= {1,2,3.5,4,5};
	int n = sizeof(array) / sizeof(array[0]);
	cout<<average(array,n)<<endl;

	char string[] = "hello world";
	cout << string << strlen(string) <<endl;
	string[3] = '\0';
	cout << string << strlen(string) <<endl;
	return 0;
}

double average(double array[],int n) {
	double total = 0;
	for (int i=0;i<n;i++) {
		total += array[i];
	}
	return (total / n);
}