/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Maximum path sum I & II
 *
 * By starting at the top of the triangle below and moving to adjacent numbers on the row
 * below, the maximum total from top to bottom is 23.
 *
 *					3
 *				   7 4
 * 				  2 4 6
 * 				 8 5 9 3
 *
 * That is, 3 + 7 + 4 + 9 = 23.
 *
 * NOTE: As there are only 16384 routes, it is possible to solve this problem by trying 
 * every route. However, Problem 67, is the same challenge with a triangle containing 
 * one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
 */

 /**
  * This will be the solution to problem 18 & 67 of project euler. The difference of both
  * problems is the size of it. The first one can be solved using brute force, second one 
  * must be solved in a clever way.
  * Brute force solution consists in reaching all possible paths. When the triangle gets bigger
  * this solution is non-viable.
  *
  * In this problem we will introduce balanced binary trees. This will be used to represent the triangle.
  * This could be done with a struct and pointers but I personally think it will be easy to do with 
  * a matrix.
  *
  * To solve the problem in a clever way we will use dynamic programming. Starting at the bottom 
  * leaf and going up to find the max sum possible. Dividing the big problem into small problems 
  * we will finally find ourselve here:
  *
  * 				a
  *				   b c
  *
  * solution will be: a + max(b,c)
  */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


vector< vector<int> > initializeTree(){
	/**
	 * Pre: Root is the root of our tree.
	 * Post: Tree will have all items.
	 */

	//Deep will indicate the deepnes of the tree.
	int deep;
	cin >> deep;

	vector< vector<int> > tree(deep,vector<int>(deep + 1));

	//ValuesInLine will be used to know how many numbers are on each line.
	int valuesInLine = 1;

	int indexI=0;
	while (indexI < deep ){
		int indexJ=0;
		while (indexJ < valuesInLine){
			int value;
			cin >> value;
			tree[indexI][indexJ] = value;
			++indexJ;
		}
		++indexI;
		++valuesInLine;
	}

	return tree;
}


int getMaximumPathSum(vector< vector<int> > &tree){
	/**
	 * Pre: tree is a balanced binary tree stored in a matrix
	 * Post: maximum path is stored in tree[0][0].
	 */

	int indexI = tree.size() - 2;
	while (indexI > -1){
		int indexJ = 0;
		while (indexJ < indexI + 1){
			tree[indexI][indexJ] = tree[indexI][indexJ] + max(tree[indexI+1][indexJ], tree[indexI+1][indexJ+1]);
			++indexJ;
		}
		--indexI;
	}

	return tree[0][0];

}


int maximumPathSum(){
	/**
	 * Pre: Null
	 * Post: maximumPathSum will be returned
	 */

	vector< vector<int> > tree = initializeTree();
	return getMaximumPathSum(tree);	
}


int main()
{
	cout << "Solution is: " << maximumPathSum() << endl;
}