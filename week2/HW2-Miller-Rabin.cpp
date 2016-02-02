
#include<iostream>
#include <fstream>
#include<stdlib.h>
using namespace std;
// to get the result of  x^n mod m
 int powermod(long long x, long long n, int m) {
	 int prod = 1;
	 if (n == 1) {
		 return x%m;
	 }
	 while (n > 0) {
		 if (n % 2 == 1) {
			 prod = (prod*x) % m;
		 }
		 x = (x*x) % m;
		 n = floor(n / 2);
	 }
	 return prod;
 }
bool Miller0Rabin(int n, int Testtimes) {
	if (n < 2) {
		return false;
	}
	if (n != 2 && n % 2 == 0) {
		return false;
	}
	int d = n - 1;
	int s = 0;
	while (d % 2 == 0) {
		d /= 2;
		s++;
	}
	    //make the a^n to 2^s*d
	for (int i = 1; i <= Testtimes; i++) {
		bool skip = false;
		int a = rand() % (n - 2) + 2;
		//generate a random number from 2 to n-2
		long long x = powermod(a, d, n);

		if (x == 1 || x == n - 1) {
			continue;
		}
		for (int i = 0; i < s - 1; i++) {
			x = (x*x) % n;
			if (x == 1) {
				return false;
			}else if (x == n - 1) {
				skip = true;
				break;
			}
		}
		if (!skip) {
			return false;
		}
	}
	return true;
}

int main() {
	fstream file;
	long long testNum;
	long long testTime = 5;
	file.open("hw2.dat");
	if (!file) {
		cout << "open file fail!!" << endl;
		return -1;
	}
	while (file >> testNum) {
	
		if (Miller0Rabin(testNum, testTime)) {
			cout << testNum << " true" << endl;
		}
		else {
			cout << testNum << " false" << endl;
		}
	}

	return 0;
}