#include<iostream>
using namespace std;

int memo[5][5] = {0};

int numPaths(const int row, const int col){
	if(row == 0 || col == 0) return 1;
	if(memo[row][col] > 0) return memo[row][col];
	return memo[row][col] = numPaths(row, col - 1) + numPaths(row - 1, col);
}	

int main(){
	cout << numPaths(4, 4) << endl;
	return 0;
}
