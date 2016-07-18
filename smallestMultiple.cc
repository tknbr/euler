/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Smallest multiple
 *
 * 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
 *
 * What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
 *
 *
 * In My implementation there is one input parameter N. This sets the range, from 1 to N .
 *
 */

/**
 * How are we going to face this problem?
 *
 * First we need to identify what are we asked for, this is a least common multiple of several integers.
 * 
 * How can we calculate lcm(a,b) in an efficient way?
 *
 * An eficient way is to transform lcm(a,b) to (a*b)/gcd(a,b). Now the problem is reduced to calculate the gcd of both numbers.
 * To calculate gcd in an efficient way we can use a binary gcd algorithm. 
 *
 */

#include <iostream>
using namespace std;

long int binaryGCD( long int a, long int b){
	/**
	 * This is a recursive implementation of the binary gcd algorithm. More info can be found in google. 
	 */

	// simple cases
	if ( a == b ) return a;	
	if ( a == 0 ) return b;
	if ( b == 0 ) return a;

	// look for factors of 2
	if ( ~a & 1 ) // a is even
	{
		if ( b & 1 ) // v is odd
			return binaryGCD( a >> 1, b);
		else // both are even
			return binaryGCD( a >> 1, b >> 1) << 1;
	}		

	if ( ~b & 1) // a is odd and b is even
		return binaryGCD( a, b >> 1);

	// reduce larger argument
	if ( a > b )
		return binaryGCD( ( a - b ) >> 1, b );

	return binaryGCD( ( b - a ) >> 1, a );
}

long int lcm( long int a, long int b){
	/**
	 * We reduce de lcm problem to (a*b)/gcd(a,b)
	 */
	return ( a * b ) / ( binaryGCD( a, b ) );
}


long int smallestMultiple(int N){
	/**
	 * Pre: N is an integer so that: 2 < N < ~40 
	 * Post: It will return the smallest positive number that is evenly divisible by all of the numbers form 1 to N
	 */

	long int result = lcm(1, 2);
	int iterator = 3;

	while ( iterator <= N ){
		result = lcm(result, iterator);
		++iterator;
	}

	return result;
}


int main(){
	int N;
	cout << "N ?" << endl;
	cin >> N;
	cout << "The smallest positive number that is evenly divisible by all of the numbers from 1 to " << N << " is " << smallestMultiple(N) << endl;
}