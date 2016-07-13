/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Multiples of 3 and 5
 *
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * My implementation has an input parameter. This parameter N is the number which you want the sum of all the multiples of 3 and 5 below this number.
 */

#include <iostream>
using namespace std;

int multiples3and5(int N){
	/**
	 * What we know is: 
	 * 	- The number of multiples of 3 below N is floor((N-1)/3)
	 *	- The number of multiples of 5 below N is floor((N-1)/5)
	 *	- We will need to take in mind multiples of 15 will be overcounted. 
	 *
	 * What will we do: 
	 * 	- Get the sum of the multiples of 3 below N
	 *	- Get the sum of the multiples of 5 below N
	 *	- Substract one time the multiples of 15 below N
	 */

	int result = 0;
	int multiplesOfThree = 3;
	int multiplesOfFive = 5;
	int multiplesOfFifteen = 15;

	while ( multiplesOfThree < N ){
		result = result + multiplesOfThree;
		multiplesOfThree += 3;
	}

	while ( multiplesOfFive < N ){
		result = result + multiplesOfFive;
		multiplesOfFive += 5;
	}

	while ( multiplesOfFifteen < N ){
		result = result - multiplesOfFifteen;
		multiplesOfFifteen += 15;
	}

	return result;
}


int main()
{
	int N;
	cout << "N ?" << endl;
	cin >> N ;
	cout << "The sum of all the multiples of 3 or 5 below " << N << " is " << multiples3and5(N) << endl;
}