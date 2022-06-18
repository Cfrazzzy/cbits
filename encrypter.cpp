//Program created by Conrad Franke to take in file (jpg/text/any) and translate it to binary for future tool :)
#include <iostream>
#include <fstream>
#include "binary.h"
#include <bitset>
using namespace std;
int main() {
    int x = 0; 
    char str[1024];
    string secondfile = ""; 
    cout << "enter filename to read binary (must be in same directory): ";
    cin.get(str, 1024);    //get filename and string
    ifstream is(str);     // open file; 
    cout << "enter second file to output to: ";
    cin >> secondfile; 
    ofstream my_file(secondfile);
    char c;
    int i = 0; 
    int controller = 0;
    cout << "Enter mode: "<<"\n"<<"1: XOR"<<"\n"<<"2: BITSHIFT LEFT ENCRYPT"<<"\n"<<"INPUT: ";
    cin >> controller; 
    if (controller == 1) {
        while (is.get(c)) {         // loop getting single characters
            int y = xorbytes(c, 'b', '0');
            my_file << char(y);
            //bitset<8> x(c);
            //cout <<x<<" number at: "<<i << "\n";
            i++;
        }
    }
    else if (controller == 2) {
        cout << "shift by: ";
        char shifter;
        cin >> shifter;
        while (is.get(c)) {         // loop getting single characters
            int y = shiftLeft(c, shifter, '0');
            my_file << char(y);
            //bitset<8> x(c);
            //cout <<x<<" number at: "<<i << "\n";
            i++;
        }

    }
    is.close();                // close file
    my_file.close(); 
	return 0;
}

