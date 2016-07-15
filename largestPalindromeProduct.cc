/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Largest palindrome product
 *
 * A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 */

#include <iostream>
#include <math.h>
#include <string>
#include <sstream>

using namespace std;

string to_string(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

bool isPalindrome(int possiblePalindrome){
	/**
	 * Pre: possiblePalindrome is a positive integer
	 * Post: True if possiblePalindrome is a palindrome, else False
	 */

	string numberReceived = to_string(possiblePalindrome);
	string reverseNumberReceived = string( numberReceived.rbegin(), numberReceived.rend());
	if ( numberReceived == reverseNumberReceived ) return true;
	return false;
}

int largestPalindromeFromProduct(int N){
	/**
	 * Pre: N is a num between 1 < N < 10. Tip: Don't use a number grater than 4 if you don't want to be waiting forever.
	 * Post: largest palindrome from the product of two numbers of N-digits
	 */

	int maxPalindromeFound = -1;

	int upperBound = pow(10, N);

	for (int firstMultiplier = pow(10, N-1); firstMultiplier < upperBound; firstMultiplier++){
		for( int secondMultiplier = pow(10, N-1); secondMultiplier < upperBound; secondMultiplier++){
			int firstxsecond = firstMultiplier*secondMultiplier;
			if (isPalindrome(firstxsecond) and firstxsecond > maxPalindromeFound) maxPalindromeFound = firstxsecond;
		}
	}

	return maxPalindromeFound;
}

int main(){
	int N;
	cout << "N ?" << endl;
	cin >> N;
	cout << "The largest palindrome obtained from the product of two " << N << "-digits is: " << largestPalindromeFromProduct(N) << endl;
}