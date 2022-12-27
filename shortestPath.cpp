#include<iostream>
using namespace std;

const int rows = 5;
const int cols = 6;

int cost(int i, int j){
	static int memo[5][6]{0};
	int weight[rows][cols] = {{3, 4, 1, 2, 8, 6},
				  {6, 1, 8, 2, 7, 4},
				  {5, 9, 3, 9, 9, 5},
				  {8, 4, 1, 3, 2, 6},
				  {3, 7, 2, 8, 6, 4}};
	if(j == 0) return weight[i][0];
	if(memo[i][j] != 0) return memo[i][j];
	int arr[3];
	arr[0] = weight[i][j] + cost((i - 1 + rows) % 5, j - 1);
	arr[1] = weight[i][j] + cost(i, j - 1);
	arr[2] = weight[i][j] + cost((i + 1) % 5, j - 1);
	int lowestCost = arr[0];
	for(int i = 0; i < 3; i++){
		if(lowestCost > arr[i]) lowestCost = arr[i];
	}
	return memo[i][j] = lowestCost;
}

int main(){
	int min, ex[rows];
	for(int i = 0; i < rows; i++){
		ex[i] = cost(i, cols - 1);
	}
	min = ex[0];
	for(int i = 0; i < rows; i++){
		if(min > ex[i]) min = ex[i];
	}
	cout << "The shortest path is of length " << min <<endl;
	return 0;
}