#include <iostream>
#include <fstream>

using namespace std;

int insertionSort(int array[],int num);

int main() {
	ifstream in("in.txt");
	ofstream out("out.txt");
	int num,count;
	in >> count;
	int array[count];
	for(int i=0;i<count;i++) {
		in >> num;
		array[i] = num;
	}
	insertionSort(array,count);
	for(int value:array) {
		out << value << " ";
	}
	in.close();
	out.close();
}

int insertionSort(int array[],int num) {
	int current;
	int min = array[0];
	int j;
	for(int i=1;i<num;i++) {
		current = array[i];
		if (current < min) {
			j = i
			while(array[j] > array[j-1]) {
				swap(array,j,j-1);
			}
		}
	}
}

void swap(int array[],int index1,int index2) {
	int temp = array[index1];
	array[index1] = array[index2];
	array[index2] = temp;
}