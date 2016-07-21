/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Special Pythagorean triplet
 *
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
 * 									a^2 + b^2 = c^2
 *
 * For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 *
 * My implementation has an input parameter. This parameter N will serve the equation a + b + c = N
 */

 /**
  * This problem has two premises which we must take in mind: 
  *
  * 	1.	a + b + c = N --> c =  N - a - b
  *
  * 	2.  		    a < b < c
  *
  * From 1 & 2 we can state that a will be a value between 0 and N/3, b will be a value between a and (2*N)/3
  * and c will be c = N - a - b
  */

#include <iostream>
using namespace std;

void pythagoreanTriplet(int N){
	/**
	 * Pre: N is an integer
	 * Post: If exists, a b c will be output where a² + b² = c², a < b < c and a + b  = N
	 */

  for (int a = 1; a < (N/3); ++a){

    for (int b = a + 1; b < ((2*N)/3); ++b){
      int c = N - a - b;

      if ( a*a + b*b == c*c ){
        cout << "a = " << a << " b = " << b << " c = " << c << endl;
        return;
      }
    }
  }

  cout << "There is no a, b and c for the N introduced" << endl;
}


int main(){
  cout << "N ?" << endl;
  int N;
  cin >> N;
  pythagoreanTriplet(N);
}