/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Large Sum
 *
 * Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
 *
 * 37107287533902102798797998220837590246510135740250
 * 46376937677490009712648124896970078050417018260538
 * 74324986199524741059474233309513058123726617309629
 *
 *						[...]
 *
 * 72107838435069186155435662884062257473692284509516
 * 20849603980134001723930671666823555245252804609722
 * 53503534226472524250874054075591789781264330331690
 *
 */

 /**
  * The max value we can manage of an unsigned long long int is 18446744073709551615. To sum 
  * the one-hundred 50-digit numbers we are going to save each number as a string and sum the
  * the digits individually. 
  */

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;


string calculateSum(vector< string > nums){
	/**
	 * Pre: nums is a vector of numbers stored in a string format. All numbers have the same length/size.
	 * Post: result will be the sum of all nums.
	 */
	string result;
	unsigned long long int carry = 0;
	for ( int i = nums[0].length() - 1; i >= 0 ; --i){
		for (int j = 0; j < nums.size(); ++j){
			carry += atoi( nums[j].substr(i, 1).c_str() );
		}
		result.insert(0, to_string(carry%10));
		carry /= 10;
		cout << " carry: " << carry << endl;
	}
	result.insert(0,to_string(carry));
	return result;
}


int main(){
	vector< string > nums;

	/**
	 * We introduce the numbers (100)
	 */
	for (int i = 0; i < 100; ++i){
		string number;
		cin >> number;
		nums.push_back(number);
	}

	string result = calculateSum(nums);

	cout << "The first 10 digits of the sum of the one-hundred 50-digit numbers is:" << result.substr(0,10) << endl;
}