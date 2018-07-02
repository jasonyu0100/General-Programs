#include <iostream>
int count = 0;
int fibonacci(int i);
extern void write_extern(void);

int main() {
	int i = 0;
	while (i < 10) {
		std::cout << fibonacci(i) << '\n';
		i ++;
	}
	int a = 5;
	a>>= 2;
	std::cout << a << "fads"<< '\n';
	write_extern();
	count = 5;
	write_extern();

}

int fibonacci(int i) {
	if (i == 1 || i == 0) {
		return 1;
	} else {
		return fibonacci(i-1) + fibonacci(i - 2);
	}
}