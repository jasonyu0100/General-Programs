#include <iostream>

using namespace std;
template<typename T>
T square(T x) {
    return x*x;
}

template<typename T>
class myArray {
    T arr[1000];
    int size;
    public:
    myArray(): size(0) {}
    void push(T v) {arr[size] = v;size++;}
    T get(int i) const {return arr[i];}
    int getSize() const {return size;}
    void print() const {for(int i=0;i<size;i++) {cout<<arr[i]<<endl;}}

};

template<typename T>
myArray<T> operator*(const myArray<T> rhs,const myArray<T>  lhs) {
    myArray<T> ret;
    for (int i=0;i<rhs.getSize();i++) {
        ret.push(rhs.get(i)*lhs.get(i));
    }
    return ret;
}

int main() {
    myArray <int> arr;
    arr.push(1);
    arr.push(5);

    square(arr).print();
    int i = 5;
    int &j = i;
    printf("i:%d j:%d\n",i,j);
    i = 10;
    printf("i:%d j:%d\n",i,j);
    return 0;
}