//this header file is to help me with bitshifting and doing other operations. I will hopefully be able to do reversing in the future easier by having
//programmed this header file. This will also help me obfuscate things such as programs in the future. This is needed for c++ in the future and 
//should be implemented along with more bit friendly libraries for reverse engineers and forensic analysists alike. Personal oponion. 
//use case - add to directory or visual studio and #include "binaryops.h". Functions can be called as they are listed. 
#pragma once
// my_class.h
//shift left
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
int shiftRight(int firstByte, int secondByte, int product) {
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
//xor 
int xorbytes(int firstByte, int secondByte, int product) {
	_asm {
		mov eax, firstByte;
		mov ebx, secondByte;
		xor eax, ebx;
		mov product, eax;
	}
	return(product);
}
//or 
int orbytes(int firstByte, int secondByte, int product) {
	_asm {
		mov eax, firstByte;
		mov ebx, secondByte;
		or eax, ebx;
		mov product, eax;
	}
	return(product);
}
//and 
int andbytes(int firstByte, int secondByte, int product) {
	_asm {
		mov eax, firstByte;
		mov ebx, secondByte;
		and eax, ebx;
		mov product, eax;
	}
	return(product);
}

