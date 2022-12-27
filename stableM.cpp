#include<iostream>
#include<cmath>
using std::endl;
using std::cout;

bool okay(int q[], int c){
	static int mp[3][3] = {{0, 2, 1},
			       {0, 2, 1},
			       {1, 2, 0}};
	static int wp[3][3] = {{2, 1, 0},
			       {0, 1, 2},
			       {2, 0, 1}};
	for(int i = 0; i < c; i++){
		if(q[c] == q[i]) return false;
	}
	for(int i = 0; i < c; i++){
		if(mp[c][q[i]] < mp[c][q[c]] and wp[q[i]][c] < wp[q[i]][i]) return false;
		if(wp[q[c]][i] < wp[q[c]][c] and mp[i][q[c]] < mp[i][q[i]]) return false;
	}
	return true;
}	

void backtrack(int& c){
	c--;
	if(c < 0) exit(1);
}

void print(int q[]){
	static int num = 0;
	cout << "Stable Marriage Matching Results #" << ++num << ": " << endl;
	cout << "Men" << "\t" << "Women" <<endl;
	for(int i = 0; i < 3; i++){
		cout << " " << i << "\t" << " " << q[i] <<endl;
	}
	cout <<endl;
}

int main(){
	int q[3], c = 0;
	q[0] = 0;
	int gate = 1;
	while(1){
		while(c < 3){
			if(gate){
				c++;
				if(c > 2) break;
				q[c] = -1;
			}
			while(q[c] < 3){
				q[c]++;
				if(q[c] > 2){
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






