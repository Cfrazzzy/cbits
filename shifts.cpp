#include <iostream>
#include <Windows.h>
#include <string>
using namespace std; 

int shiftLeft(int firstByte, int secondByte, int product) {
	_asm {
		mov eax, firstByte;
		mov ebx, secondByte;
		mov ecx, 0; 
		start: 
		inc ecx; 
		imul eax, 2; 
		cmp ecx, ebx; 
		jl start
		mov product, eax;
	}
	return(product);
}
int shiftRight(int firstByte, int secondByte, int product){
	_asm {
		mov eax, firstByte;
		mov ebx, secondByte;
		mov ecx, 1;
		start:
		inc ecx;
		shr eax, 2;
		cmp ecx, ebx;
		jl start
		mov product, eax;
	}
	return(product);
}

int main() {
	int firstByte, secondByte, product, checker; 
	cout << "1 for shift right, 2 for shift left: "; 
	cin >> checker; 
	product = 0;
	cout << "enter a character to xor : ";
	cin >> firstByte;
	cout << "enter your second character to xor: ";
	cin >> secondByte;
	if (checker == 1) {
		int s = shiftRight(firstByte, secondByte, product);
		cout << s;
		Sleep(1000);
	}
	else if(checker == 2) {
		int s = shiftLeft(firstByte, secondByte, product);
		cout << s;
		Sleep(1000);
	}
	else{
		cout << "BAD INPUT TERMINATING PROCESS"; 
		Sleep(1000); 
		exit; 
	}


	return 0; 
}

