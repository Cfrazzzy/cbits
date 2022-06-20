#include <iostream>
#include <Windows.h>
#include <string>
using namespace std; 



int xorbytes(int firstByte, int secondByte, int product) {
	_asm {
		mov eax, firstByte;
		mov ebx, secondByte;
		xor eax, ebx;
		mov product, eax;
	}
	return(product);
}

int main() {
	int firstByte, secondByte, product; 
	product = 0; 
	cout << "enter a character to xor : "; 
	cin >> firstByte; 
	cout << "enter your second character to xor: "; 
	cin >> secondByte; 
	int s = xorbytes(firstByte, secondByte, product);  
	cout << s; 
	Sleep(1000); 


	return 0; 
}

