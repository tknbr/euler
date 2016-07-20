/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Largest product in a series
 *
 * The four adjacent digits in the 1000-digit number that have the greatest product are 9 × 9 × 8 × 9 = 5832.
 *
 * 73167176531330624919225119674426574742355349194934
 * 96983520312774506326239578318016984801869478851843
 * 85861560789112949495459501737958331952853208805511
 * 12540698747158523863050715693290963295227443043557
 * 66896648950445244523161731856403098711121722383113
 * 62229893423380308135336276614282806444486645238749
 * 30358907296290491560440772390713810515859307960866
 * 70172427121883998797908792274921901699720888093776
 * 65727333001053367881220235421809751254540594752243
 * 52584907711670556013604839586446706324415722155397
 * 53697817977846174064955149290862569321978468622482
 * 83972241375657056057490261407972968652414535100474
 * 82166370484403199890008895243450658541227588666881
 * 16427171479924442928230863465674813919123162824586
 * 17866458359124566529476545682848912883142607690042
 * 24219022671055626321111109370544217506941658960408
 * 07198403850962455444362981230987879927244284909188
 * 84580156166097919133875499200524063689912560717606
 * 05886116467109405077541002256983155200055935729725
 * 71636269561882670428252483600823257530420752963450
 * 
 * Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?
 */

 /**
  * To do this problem we will have to go through all the numbers in the 1000-digit number. I'll have a vector of 13 positions where I will
  * store the 13 numbers beeing avaluated.
  *
  * Take in mind the multiplication may be a long number so don't use ints in your implementation. In my case, as I know the result will be
  * a natural number I have used unsigned long int.
  */

#include <iostream>
#include <vector>
#include <stdlib.h> 

using namespace std;


unsigned long int multiplicationGreater(unsigned long int olderValue, vector<int> evaluatingNumbers){
	/**
	 * Pre: olderValue is a Natural, evaluatingNumbers is a vector of naturals.
	 * Post: if the multiplication of all the naturals in evaluatingNumbers is bigger than olderValue, then true.
	 */

	unsigned long int totalMultiplication = 1;
	
	for ( int i = 0; i < evaluatingNumbers.size(); ++i ){
		totalMultiplication *= evaluatingNumbers[i];
	}

	if ( totalMultiplication > olderValue ) return totalMultiplication;
	return 0;
}


unsigned long int getTheThirteen(string number){
	/**
	 * Pre: number is a very large natural number in a string format.
	 * Post: It will print the thirteen adjacent digits in the number that have the greatest product.
	 */

	vector<int> theEvaluator;
	unsigned long int multOfCurrentThirteen = 1;
	int indexInsideNumber = 0;
	for(int i = 0; i < 13; ++i){
		theEvaluator.push_back(atoi( number.substr(indexInsideNumber, 1).c_str() ));
		multOfCurrentThirteen *= atoi( number.substr(indexInsideNumber, 1).c_str() );
		++indexInsideNumber;
	}

	while ( indexInsideNumber < number.length() ){
		theEvaluator.erase(theEvaluator.begin());
		theEvaluator.push_back(atoi( number.substr(indexInsideNumber, 1).c_str() ));
		unsigned long int evaluate = multiplicationGreater(multOfCurrentThirteen, theEvaluator);
		if ( evaluate != 0 ){
			multOfCurrentThirteen = evaluate;
		}
		++indexInsideNumber;
	}

	return multOfCurrentThirteen;
}


int main()
{
	string number;
	cout << "Enter the 1000-digit number:" << endl;
	cin >> number; 
	cout << "The greatest product of thirteen adjacent digits in the 1000-digit number is: " << getTheThirteen(number) << endl;
}

