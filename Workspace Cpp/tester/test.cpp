/*
 * test.cpp
 *
 *  Created on: Aug 30, 2018
 *      Author: mexib
 */




/*
 * hello.cpp

 *
 *  Created on: Aug 30, 2018
 *
 *
 *  // google
 *      Author: mexib
 */

/*
 * Derek Baum Lab 1
 */
#include <iostream>
using namespace std;
void modifyX(string co);
void modifyRef(int &x);

using namespace std;

int main() {
	string s = "0";
	string s2 = s + "1";
	cout<<s2<<endl;
	return 0;
}

// call by pointer
// you are giving the function the address variable
void modifyX(string co=""){
	cout<<co<<endl;
}

// call by reference
// you are assigning a new variable to the memory address that is passed in
// this is java

void modifyRef(int &x){
	x = 900;
}
