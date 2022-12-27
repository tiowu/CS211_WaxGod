#include<iostream>
#include<cmath>
using std::cout;
using std::endl;

bool okay(int q[], int c){
	static int adj[8][5] = {{-1},
			  	{0, -1},
			  	{0, -1},
			  	{0, 1, 2, -1},
			  	{0, 1, 3, -1},
			  	{1, 4, -1},
			  	{2, 3, 4, -1},
			  	{3, 4, 5, 6, -1}};
	for(int i = 0; i < c; i++){
		if(q[c] == q[i]) return false;
	}
	int g = 0;
	while(adj[c][g] != -1){
		if(abs(q[c] - q[adj[c][g]]) == 1) return false;
		g++;
	}
	return true;
}

void backtrack(int& c){
	c--;
	if(c < 0) exit(1);
}

void print(int q[]){
	static int num = 0;
	cout << "Solution #" << ++num << ": \n";
	for(int i = 0; i < 8; i++){
		if(i == 0 || i == 6) cout << " " << q[i];
		else if(i == 1 || i == 5) cout << q[i] << endl;
		else cout << q[i];
	}
	cout <<endl;
	cout <<endl;
}

int main(){
	int q[8], c = 0;
	q[0] = 1;
	int gate = 1;
	while(1){
		while(c < 8){
			if(gate){
				c++;
				if(c > 7) break;
				q[c] = 0;
			}
			while(q[c] < 9){
				q[c]++;
				if(q[c] > 8){
					gate = 0;
					backtrack(c);
					break;
				}
				if(okay(q, c)){
					gate = 1;
					break;
				}
			}
		}
		gate = 0;
		print(q);
		backtrack(c);
	}
}





























