/**
 * Developed by Arnau Bagó Castro
 * 
 * Linkedin: https://es.linkedin.com/in/arnaubago
 * Github: https://github.com/tknbr/euler
 * 
 * Part of the Project Euler problems ( https://projecteuler.net )
 *
 * Lattice paths
 *
 * Starting in the top left corner of a 2×2 grid, and only being able 
 * to move to the right and down, there are exactly 6 routes to the bottom right corner.
 *
 * How many such routes are there through a 20×20 grid?
 *
 * Althought this problem is thought to be solved by a square matrix I'll solve it by a
 * no square matrix. NxM will be the inputs.
 */

/**
 * This problem can be solved putting a weight in each edge and counting. 
 */

#include <iostream>
#include <vector>

using namespace std;

unsigned long long int latticePaths(int N, int M){
/**
 * Pre: N & M are naturals and represent the size of the matrix.
 * Post: The routes to the bottom right corner from the top left corner being eable to move 
 * to the right and down only.
 *
 * First we are going to initialize the matrix and then count.
 */

	vector< vector <unsigned long long int > > matrix(N+2, vector<unsigned long long int>(M+2));
	for (int i = 0; i < N; ++i) 
		matrix[i][N] = 1;
	for (int i = 0; i < M; ++i)
		matrix[M][i] = 1;	

	for (int i = N-1; i >= 0; --i) 
		for ( int j = M-1; j >= 0; --j)
			matrix[i][j] = matrix[i+1][j] + matrix[i][j+1];

	return matrix[0][0];
}


int main(){
	int N, M;
	cout << "N ?" << endl;
	cin >> N;
	cout << "M ?" << endl;
	cin >> M;
	cout << "Matrix " << N << " x " << M << " has " << latticePaths(N, M) << " paths." << endl;
}