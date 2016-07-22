/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Summation of primes
 *
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 *
 * My implementation has an input parameter. This parameter N is the upper bound we want to find the sum of all the primes below it.
 */

 /**
  * To resolve this problem we are going to use some functions used in older problems. 
  */


#include <iostream>
#include <vector>

using namespace std;


bool isPrime(unsigned long int numberToTest, vector<unsigned long int> primeNumbers){
	/**
	 * This is not a generic primality test. It's specific for this program.
	 * Pre: numberToTest is a natural, primeNumbers are all the primes inferior to numberToTest
	 * Post: true if it is a prime
	 */
	
	for ( int i = 0; i < primeNumbers.size(); ++i ){
		if ( ( numberToTest % primeNumbers[i] ) == 0 ) return false;
	}

	return true;
}


unsigned long long int sumPrimesBelow(unsigned long int N){
	/**
	 * Pre: N is a natural 0 < N < max_long_unsigned_int
	 * Post: The sum of all the primes below N
	 */
	
	unsigned long long int sumPrimes = 2;
	vector<unsigned long int> primeNumbers;
	primeNumbers.push_back(2);
	for ( unsigned long int i = 3; i < N; ++ i ){
		if ( isPrime(i, primeNumbers) ){
			primeNumbers.push_back(i);
			sumPrimes += i;
		}
	}

	return sumPrimes;
}


int main(){
	cout << "N ?";
	unsigned long int N;
	cin >> N;
	cout << "The sum of all the primes below " << N << " is: " << sumPrimesBelow(N) << endl;
}