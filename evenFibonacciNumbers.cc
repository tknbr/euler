/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Even Fibonacci numbers
 *
 * Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
 *
 * My implementation has an input parameter. This parameter N is the number which you want the sum of all the even Fibonacci numbers below this number.
 *
 */

#include <iostream>
using namespace std;

int evenFibonacciNumbers(int N)
{
	/**
	 * Pre: N is an integer and its value must be: 2 < N < 2.000.000.000 
	 * Post: returned value is the sum of the even fibonacci numbers < N
	 * 
	 * Division is a computational expensive operation. This is why we are going to use a mask to know if the number is even. 
	 *  
	 */

	 int secondPrevious = 0;
	 int firstPrevious = 1;
	 int evenFibonacciNumbersSum = 0;
	 int nextFibonacciNumber = firstPrevious + secondPrevious;

	 while ( nextFibonacciNumber < N ){

	 	if ( (nextFibonacciNumber & 1) == 0 ) evenFibonacciNumbersSum += nextFibonacciNumber;

	 	secondPrevious = firstPrevious;
	 	firstPrevious = nextFibonacciNumber;
	 	nextFibonacciNumber = firstPrevious + secondPrevious;

	 }

	 return evenFibonacciNumbersSum;
}

int main()
{
	int N;
	cout << "N ?" << endl;
	cin >> N ;
	cout << "The sum of the even Fibonacci numbers below " << N << " is " << evenFibonacciNumbers(N) << endl;
}