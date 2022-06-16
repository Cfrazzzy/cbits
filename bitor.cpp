#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;



int orbytes(int firstByte, int secondByte, int product) {
	_asm {
		mov eax, firstByte;
		mov ebx, secondByte;
		or eax, ebx;
		mov product, eax;
	}
	return(product);
}

int main() {
	int firstByte, secondByte, product;
	product = 0;
	cout << "enter a character to or : ";
	cin >> firstByte;
	cout << "enter your second character to or: ";
	cin >> secondByte;
	int s = orbytes(firstByte, secondByte, product);
	cout << s;
	Sleep(1000);


	return 0;
}
