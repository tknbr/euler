/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Longest Collatz sequence
 *
 * 
 *
 * The following iterative sequence is defined for the set of positive integers:
 *
 *		n → n/2 (n is even)
 *		n → 3n + 1 (n is odd)
 *
 * Using the rule above and starting with 13, we generate the following sequence:
 * 
 *		13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *
 * It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
 *
 * Which starting number, under one million, produces the longest chain?
 *
 * NOTE: Once the chain starts the terms are allowed to go above one million.
 *
 *
 * This problem will have an input parameter N. N will determine the size of the problem.
 */

/**
 * To do this problem we need to test every number in order to know the length of the sequence it produces. To reduce
 * computation cost we can store the length of the sequences calculated and pair it to the number that produces it. This
 * will be used in future calculations to reduce the computation cost. 
 */

#include <iostream>
#include <unordered_map>

using namespace std;


unsigned long long int lengthSeq(unsigned long long int i, unordered_map <unsigned long long int, unsigned long long int> &collatzRelation){
	/**
	 * Pre: i is a natural, collatzRelation sotre the length of the collatz sequence of some numbers.
	 * Post: returns the length of the collatz sequence of i.
	 * Check we've passed collatzRelation as reference. If we don't do that we will waste a larger
	 * amount of memory than necessary. Although, copying each time the unordered_map will enlarge the
	 * processing time.
	 */
	unsigned long long int actualLength = 0;
	while (true){
		if ( collatzRelation[i] != 0 ) return actualLength + collatzRelation[i];
		if ( i%2 == 0 ){
			i /= 2;
		} else {
			i = 3*i + 1;
		}
		actualLength++;
	}
}


unsigned long long int largestCollatzSequenceUnder(unsigned long long int N){
	/**
	 * Pre: N is an unsigned long long int
	 * Post: result is the starting number of the largest collatz sequence under N
	 */

	unsigned long long int largestSequence = 1;
	unsigned long long int startingNumber = 1;
	unordered_map <unsigned long long int, unsigned long long int> collatzRelation;
	collatzRelation[1] = 1;

	for ( unsigned long long int i = 2; i < N; ++i ){
		
		unsigned long long int lengthSequence = lengthSeq(i, collatzRelation);
		if (lengthSequence > largestSequence){
			largestSequence = lengthSequence;
			startingNumber = i;
		}
		collatzRelation[i] = lengthSequence;
		cout << i << " is: " << lengthSequence << endl;
	}
	return startingNumber;
}

int main(){
	int N;
	cout << "N ?" << endl;
	cin >> N;
	cout << "The starting number under " << N << " that produces the longes chain is: " << largestCollatzSequenceUnder(N) << endl;
}