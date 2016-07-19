/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Largest prime factor
 *
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10 001st prime number?
 *
 * My implementation has an input parameter. This input parameter is the N-essim prime number
 *
 */

/**
 * For this problem we are going to use the same strategy we used for the largest prime Factor problem. 
 */

#include <iostream>
#include <vector>

using namespace std;

bool isPrime(long int numberToTest, vector<long int> primeNumbers){
	/**
	 * This is not a generic primality test. It's specific for this program.
	 * Pre: numberToTest is a natural, primeNumbers are all the primes inferior to numberToTest.
	 * Post: true if it is a prime.
	 */
	
	for ( int i = 0; i < primeNumbers.size(); ++i ){
		if ( ( numberToTest % primeNumbers[i] ) == 0 ) return false;
	}

	return true;
}


long int NPrime(int N){
	/**
	 * Pre: N is a natural.
	 * Post: The N prime number will be returned.
	 */

	vector<long int> primeNumbers;
	long int currentNumber = 3;
	primeNumbers.push_back(2);
	while(primeNumbers.size() < N){
		
		if( isPrime(currentNumber, primeNumbers) ){
			primeNumbers.push_back(currentNumber);
		}

		++currentNumber;
	}

	return primeNumbers[primeNumbers.size() - 1];
}


int main(){
	int N;
	cout << "N ?" << endl;
	cin >> N ;
	cout << "The " << N << " prime is: " << NPrime(N) << endl;
}