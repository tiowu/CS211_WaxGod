#include<iostream>
#include<cmath>
using std::cout;
using std::cin;
using std::endl;

bool okay(int q[], int c){
	for(int i = 0; i < c; i++){
		if(q[c] == q[i] || abs(q[c] - q[i]) == (c - i)) return false;
	}
	return true;
}

int printSolutions(int numQueens){
	int *q = new int[numQueens];
	int solutions = 0, c = 0;
	q[0] = 0;
	bool gate = 1;
	while(1){
		while(c < numQueens){
			if(gate){
				c++;
				if(c == numQueens) break;
				q[c] = -1;
			}
			while(q[c] < numQueens){
				q[c]++;
				if(q[c] == numQueens){
					gate = 0;
					c--;
					if(c < 0){
						delete []q;
						return solutions;
					}
					break;
				}
				if(okay(q, c)){
					gate = 1;
					break;
				}
			}	
		}
		gate = 0;
		solutions++;
		c--;
		if(c < 0){
			delete []q;
			return solutions;
		}
	}
}

int main(){
	int numQueens;
	cout << "How many Queens would you like to see on a chessboard? \n";
	cin >> numQueens;
	for(int i = 1; i <= numQueens; i++){
		cout << "There are " << printSolutions(i) << " solutions to the " << i << " queens problem.\n"; 
	}
	return 0;
}
