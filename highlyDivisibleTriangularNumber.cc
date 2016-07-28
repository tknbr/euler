/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Highly divisible triangular number
 *
 * The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28.
 * The first ten terms would be:
 *
 *					1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * Let us list the factors of the first seven triangle numbers:
 * 
 * 					1: 1
 *					3: 1,3
 *					6: 1,2,3,6
 *					10: 1,2,5,10
 *					15: 1,3,5,15
 *					21: 1,3,7,21
 *					28: 1,2,4,7,14,28
 *
 * We can see that 28 is the first triangle number to have over five divisors.
 * What is the value of the first triangle number to have over five hundred divisors?
 *
 * My implementation has an input parameter. This parameter N is the number of divisors we are looking for to find the first number.
 *
 */

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;



unsigned long long kthNumber(unsigned int k){
	/**
	 * Pre: k is a natural
	 * Post: return the k-th triangle
	 */

	return (k*(k+1))/2;
}




unsigned int numberOfDivisors(unsigned long long int n){
	/**
	 * Pre: Nth is a triangular number, k is the index of the triangular number	
	 * Post: the number of divisors with 0 residuo that Nth has.
	 */

	// At least we know we have for sure 1 divisor.
	unsigned int divisors = 1;
	unsigned int count = 0;

	while ( (n % 2) == 0 ){
		++count;
		n /= 2;
	}
	divisors *= (count + 1);

	for ( unsigned int i = 3; i <= n; ++i ){
		count = 0;
		while ( (n%i) == 0 ){
			++count;
			n /= i;
		}
		divisors *= (count + 1);
	}
	return divisors;

}


unsigned long long int firstTriangularNumberWithNDivisors(unsigned int n){
	/**
	 * Pre: n is a natural
	 * Post: It will return the first triangular number to have at least N divisors.
	 */

	unsigned long long int index = 1;
	unsigned long long int Nth = kthNumber(index);
	while (numberOfDivisors(Nth) < n){
		index +=1;
		Nth = kthNumber(index);
	}
	cout << "k = " << index << endl;
	return Nth;
}



int main(){
	cout << "N ?" << endl;
	unsigned long int N;
	cin >> N;
	cout << "The first triangular number to have " << N << " exact divisors is: " << firstTriangularNumberWithNDivisors(N) << endl;
}