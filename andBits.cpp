#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;



int andbytes(int firstByte, int secondByte, int product) {
	_asm {
		mov eax, firstByte;
		mov ebx, secondByte;
		and eax, ebx;
		mov product, eax;
	}
	return(product);
}

int main() {
	int firstByte, secondByte, product;
	product = 0;
	cout << "enter a character to and : ";
	cin >> firstByte;
	cout << "enter your second character to and: ";
	cin >> secondByte;
	int s = andbytes(firstByte, secondByte, product);
	cout << s;
	Sleep(1000);


	return 0;
}
