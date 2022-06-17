//Program created by Conrad Franke to take in file (jpg/text/any) and translate it to binary for future tool :)
#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;
int main() {
    int x = 0; 
    char str[1024];
    cout << "enter filename to read binary (must be in same directory): ";
    cin.get(str, 1024);    //get filename and string
    ifstream is(str);     // open file
    char c;
    int i = 0; 
    while (is.get(c)) {         // loop getting single characters
        bitset<8> x(c);
        cout <<x<<" number at: "<<i << "\n";
        i++;
    }
    is.close();                // close file
	return 0;
}

