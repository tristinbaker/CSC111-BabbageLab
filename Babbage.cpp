/*
 * File: babbage.cpp
 * Purpose: Print out log tables just like Charles Babbage would have wanted.
 * 	        RIP.
 */
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {

	int lines, pages;
    int row, section;
	double input, output;

	// Get the amount of lines wanted
	cout << "Lines Per Page: ";
	cin >> lines;

	// Get the amount of pages wanted
	cout << "Pages: ";
	cin >> pages;

    //calculate and set page width
    int iw = ceil(log10(0.1 + lines * 0.4 * pages + row * 0.1)) + 5;
    int ow = ceil(log10(log(0.1 + lines * 0.4 * pages + row * 0.1))) + 7;
    int fw = 4 * (ow + iw);
    for(section = 0; section < pages; section++) {
        //print out the numbers of the header
        cout << fixed << setprecision(1);
        input = 0.1 + lines * 0.4 * section;
        cout << left << setw(iw) << input;
        input = lines * 0.4 * section + lines * 0.1 * 4;
        cout << setw(fw - iw) << right << input << endl;

        //print out the rest of the header
        cout << setw(fw) << setfill('-') << "-" << endl;
        cout << right << setfill(' ');

        for(row = 0; row < lines; row++) {
            //calculate first value of each row
            input = 0.1 + lines * 0.4 * section + row * 0.1;

            for(int col = 0; col < 4; col++) {
                cout << fixed << setprecision(1);
                //output first value
		cout << right << setw(iw) << input;
		//calculate output
                cout << fixed << setprecision(4);
		output = log(input);
	        //output.. output
		cout << right << setw(ow) << fixed << output;
                input += lines * 0.1;
            }
            cout << endl;
        }
        cout << setw(fw) << setfill('-') << "-" << endl;
        cout << right << setfill(' ') << endl << endl << endl;
   }
return 0;
}
