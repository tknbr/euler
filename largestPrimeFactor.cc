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
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 *
 * My implementation has an input parameter. In this specific case our input parameter will be: 600851475143
 *
 */

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/**
 * The first thing we need to take care here is the input number. We know it will be a large number. This is why we can not use the type int.
 * Instead we will use the type long int.
 */

bool isPrime(long int numberToTest, vector<long int> primeNumbers){
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

long int largestPrimeFactor(long int N){
	/**
	 * Pre:  0 < N < long_int_max
	 * Post: Value retuned will be the largest prime factor of N
	 *
	 * I will start explaining the basic way of calculating the prime factors of an integer N and then I will optimize it. 
	 *
	 * First implementation: 
	 *	For every integer value in between 0 and N we will try to devide N by it. If the modulus is 0 and the integer is a prime, we will
	 *  take this as a prime factor. 
	 *
	 * First optimization: 
	 * 	We just need to check the values between 0 and sqrt(N). This will make our algorithm way faster.
	 *
	 * Second optimization:
	 * 	Once we tested if 2 is a prime number we can discard all other even values between 2 < value < sqrt(N). In this case we will
	 *  evaluate just half of the cases we evaluated in the first optimization
	 *
	 * Third optimization:
	 * 	We will divide our number N by 2, 3 and 5. From this point on we will alternately add 2 and 4 to the trial divisors ( 7, 11, 13, 17, .. )
	 *  since all prime numbers greater than 3 are of the form 6k+-1 for some integer k. This will leave us with just 2/6 cases from First implementation
	 *
	 * Fourth optimization:
	 * 	The next step would be to store all the numbers between 2 - N. Each time we find a prime we will mark all the multiples of this prime from our "table".
	 *  This way we will:
	 *		1. be sure all the numbers are prime
	 *		2. we will have to test less cases than in third optimization
	 *	Pros: Fast algorithm
	 * 	Cons: It uses lots of sapce. 
	 *
	 * The fourth optimization will be ok for numers not larger than 2^16
	 * 
	 * A fast way to compute this would be using the Pollard's rho algorithm ( https://en.wikipedia.org/wiki/Pollard's_rho_algorithm )
	 * but I will try another thing. 
	 * 
	 * I will use the Third optimization but storing the prime numbers I find. This way I will have all the prime numbers in the range 2 < number_I_am_testing
	 * stored.  
	 */

	vector<long int> primeNumbers;
	long int upperBound = sqrt(N);
	long int largestPrimeFactorSoFar = 1;

	// test if is even
	if ( (N & 1) == 0 ) largestPrimeFactorSoFar = 2;
	primeNumbers.push_back(2);
	if ( (N % 3) == 0 ) largestPrimeFactorSoFar = 3;
	primeNumbers.push_back(3);
	if ( (N % 5) == 0 ) largestPrimeFactorSoFar = 5;
	primeNumbers.push_back(5);
	long int numberTesting = 7;

	while ( numberTesting <= upperBound ) {
		/**
		 * It is important to set the order like this. First check if it is a divisor and then if it is prime. 
		 * This is because checking if it costs less and if the test is false it won't check if it's a prime number.
		 */

		if ( ( N % numberTesting ) == 0 and isPrime(numberTesting, primeNumbers) ){
			largestPrimeFactorSoFar = numberTesting;
			primeNumbers.push_back(numberTesting);
		} 

		numberTesting += 4;

		if ( numberTesting <= upperBound and ( N % numberTesting ) == 0 and isPrime(numberTesting, primeNumbers) ){
			largestPrimeFactorSoFar = numberTesting;
			primeNumbers.push_back(numberTesting);
		} 
		
		numberTesting += 2;
	}

	return largestPrimeFactorSoFar;
}


int main()
{
	long int N;
	cout << "N ?" << endl;
	cin >> N ;
	cout << "The largest prime factor of the number " << N << " is " << largestPrimeFactor(N) << endl;
}