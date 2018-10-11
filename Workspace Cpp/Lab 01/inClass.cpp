/*
 * Derek Baum
 * brad and brian
 */
#include <iostream>
#include <math.h>
using namespace std;
//name functions up here if you write them below main
void two();
bool isPrime(int x);
int sum();
int termCount();
void multTables(int x);
void allMultTables();
int collatz();
void printLeapYears(int startYear, int endYear);
void drawX(int x);
void collatzTester(int min, int max);
bool recursivePrime(int x);
void recursiveTable(int x);
int main() {
	cout << "askjdnfasdfg" << endl;
	cout << boolalpha;
	cout << isPrime(7) << endl;
	cout << sum() << endl;
	cout << termCount() << endl;
	two();
	multTables(2);
	two();
	allMultTables();
	two();
	cout << collatz() << endl;
	two();
	printLeapYears(2018, 2418);
	drawX(5);
	drawX(11);
	drawX(20);
	collatzTester(3,100);
	cout << boolalpha;
	cout << recursivePrime(4) << endl;
	recursiveTable(5);
	return 0;
}
void two() {
	cout << "********************************************" << endl;
}
bool isPrime(int x) {
	two();
	int i = 1;

	while(++i <= sqrt(x)){
		if(x % i == 0)
			return false;
	}
	return true;
}
int sum(){
	two();
	int i = 0;
	int sum = 0;
	while(i <= 300){
		sum+=i;
		if(i % 20 == 0)
			cout << sum << endl;
		i++;
	}
	return sum;
}
int termCount(){
	two();
	int i = 1;
	int sum = 0;
	while(sum < 100000){
		sum+= i;
		i++;
	}

	return i-1;
}

void multTables(int x){
	for(int i = 1; i <= 12; i++){
		cout << x*i;
		cout << " ";
	}
	cout << "" << endl;
}

void allMultTables(){

	for(int i = 1; i <= 12; i++){
		multTables(i);
		cout << "" << endl;
	}

}

int collatz(){
	int x;
	cout << "Type an integer." << endl;

	cin >> x;

	int count = 0;
	while(x!=1){
		if(x%2==0){
			x/=2;
		}else{
			x = x*3 + 1;
		}
		count++;
	}
	cout << "Your number converged to 0 after ";
	cout << count;
	cout << " loops." << endl;

	return count;
}

//you said to do it for the next 400 years but i made it so that
// you can do it for the years within a range
void printLeapYears(int startYear, int endYear){
	while(startYear < endYear){
		if(startYear % 4 == 0){
			if(startYear % 100 == 0){
				if(startYear % 400 == 0){
					cout << startYear << endl;
					startYear+=4;
				}else{
					startYear+=4;
				}
			}else{
				cout << startYear << endl;
				startYear+=4;
			}
		}else{
			startYear++;
		}
	}
}

void drawX(int x){
	if(x%2==0)
		x++;
	for(int i = 1; i < x*2; i++){
		for(int j = 0; j < x*2; j++){
			if(j == i || j == (x*2 - i)){
				cout << "*";
			}else{
				cout << " ";
			}
		}
		cout << "" << endl;
	}

}

void collatzTester(int min, int max){

	for(int i = min;i <= max;i++){
		int x = i;
		cout << x;
		while(x!=1){
			if(x%2==0){
				x/=2;
			}else{
				x = x*3 + 1;
			}
		}
		cout << " .... We got 1, so the Collatz Conjecture is still working." << endl;
	}
}

bool recursivePrime(int x, int div){

	if(x < 3){
		return x==2;
	}else if(div > sqrt(x)){
		return true;
	}else if(x%div == 0){
		return false;
	}else{
		return recursivePrime(x, div+1);
	}

}
bool recursivePrime(int x){
	return recursivePrime(x, 2);
}

void recursiveTable(int x,int i){
	if(i > 12)
		return;
	cout << x*i;
	cout << " ";
	recursiveTable(x, i+1);
}
void recursiveTable(int x){
	recursiveTable(x,1);
}

