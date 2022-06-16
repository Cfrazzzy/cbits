//this program is to shift bits through both bitshift built in the assembly commands as well as using math
//Program created by Conrad Franke 

#include <iostream>
#include <Windows.h>
#include <string>
using namespace std; 

//shiftleft bitshift
//this works by multiplying the register by 2 
//function created by Conrad Franke 
//16 JUN 2022
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
//shift right
//this works by using the shr assembly function 
//function created by Conrad Franke 
//16 JUN 2022
int shiftRight(int firstByte, int secondByte, int product){
	_asm {
		mov eax, firstByte;
		mov ebx, secondByte;
		mov ecx, 0;
		start:
		inc ecx;
		shr eax, 1;
		cmp ecx, ebx;
		jl start
		mov product, eax;
	}
	return(product);
}
//main program 
//takes in user input, checks it, then goes to cooresponding function

int main() {
	int firstByte, secondByte, product, checker; 
	cout << "1 for shift right, 2 for shift left: "; 
	cin >> checker; 
	product = 0;
	cout << "enter a number to bitshift : ";
	cin >> firstByte;
	cout << "enter your second number for how many bitshifts: ";
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

