/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Sum square difference
 *
 * The sum of the squares of the first ten natural numbers is,
 *				1^2 + 2^2 + ... + 10^2 = 385
 *
 * The square of the sum of the first ten natural numbers is,
 *				(1 + 2 + ... + 10)2 = 552 = 3025
 *
 * Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
 *
 * Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 *
 * My implementation has an input parameter. This parameter N is the upper bound of the sum.
 */

 /**
  * This problem has two sub-problems:
  * 	
  * 	1. Calculate the sum of the squares
  *		2. Calculate the square of the sum
  *
  * To do the first part we are going to use the square pyramidal number formula (https://en.wikipedia.org/wiki/Square_pyramidal_number):
  *
  *				(2*N^3 + 3*N^2 + N)/6
  *
  * To do the second part we are going to use the generic formula to calculate the sum and then square it:
  *
  *				(N(N + 1))/2
  */

#include <iostream>
#include <math.h> 
using namespace std;

long int squareOfTheSum( int N ){
	/**
	 * Pre: N is a natural 0 < N < 600.000
	 * Post: The result is the square of the sum of the first N natural numbers.
	 */

	return pow( ( N*( N + 1 ) )/2, 2);	 
}

long int sumOfTheSquare( int N){
	/**
	 * Pre: N is a natural 0 < N < 600.000
	 * Post: The result is the sum of the square of the first N natural numbers.
	 */

	return ( 2*pow(N, 3) + 3*pow(N, 2) + N )/6;
}


int main()
{
	int N;
	cout << "N ?" << endl;
	cin >> N ;
	cout << "The difference between the sum of the squares of the first " << N << " natural numbers and the square of the sum is: " << squareOfTheSum(N) - sumOfTheSquare(N) << endl;
}