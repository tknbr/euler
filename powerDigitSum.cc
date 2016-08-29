/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Power digit sum
 *
 * 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 * What is the sum of the digits of the number 2^1000?
 *
 */

#include <iostream>
#include <vector>
using namespace std;

int powerDigitSum(int n){
	/**
	 * Pre: n is a natural.
	 * Post: result is the sum of the digits of 2^n
	 *
	 * We know result the result of 2^n can be a large number. We will store 
	 * result in a vector.
	 */
	vector<int> largeNumber(1,1);

	while (n > 0) {
		int resto = 0;
		for ( int i = largeNumber.size() -1; i >= 0; --i ){
			int multiplication = largeNumber[i]*2 + resto;
			largeNumber[i] = multiplication % 10;
			resto = multiplication / 10;
		}
		if ( resto != 0) largeNumber.insert(largeNumber.begin(), resto);
		--n;
	}
	int sum = 0;
	for ( int i = 0; i < largeNumber.size(); ++i) sum += largeNumber[i];

	return sum;

}

int main()
{
	int N;
	cout << "N ?" << endl;
	cin >> N ;
	cout << "What is the sum of the digits of the number 2^" << N << " is " << powerDigitSum(N) << endl;
}