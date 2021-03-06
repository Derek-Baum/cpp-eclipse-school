/*
 * huffmain.cpp
 *
 *  Created on: Oct 10, 2018
 *      Author: Derek Baum
 */
#include <iostream>
#include "LLPQ.hpp"
#include "LLNode.hpp"
#include <stdlib.h>
#include <fstream>
#include "LLHuff.hpp"


using namespace std;


int main(){
	cout<<"reading file"<<endl;
	LLHuff code("test.txt");
	code.ReadFile();
	code.pq->printLLPQ();
	code.pq->sortLL();
	code.pq->printLLPQ();
	code.MakeHuff();
	cout<<"we get past makehuff"<<endl;
	code.printTree();
	code.compressFile();
	cout<<"we get past compressfile"<<endl;
	code.ReadAscii();

	cout<<"nah yo"<<endl;
	return 0;
}


