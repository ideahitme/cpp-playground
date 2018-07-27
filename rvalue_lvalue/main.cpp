#include <iostream>
int main() { 
	int& foo();
	int* p = &foo();

	std::cout << p << std::endl;
}

//int& fun() { 
	//int a = 5;
	//return a;
//}
