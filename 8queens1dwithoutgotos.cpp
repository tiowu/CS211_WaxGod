#include<iostream>
#include<cmath>
using namespace std;

bool okay(int q[], int c){
	for(int i = 0; i < c; i++){
		if(q[c] == q[i] || abs(q[c] - q[i]) == (c - i)) return false;
	}
	return true;
}

void backtrack(int &c){
	c--;
	if(c < 0){
	    exit(1);
	}
}

void print(int q[]){
	static int num = 0;
	cout << "Solution #" << ++num << " : \n";
	for(int i = 0; i < 8; i++){
		for(int c = 0; c < 8; c++){
			if(i == q[c]) cout << "1 ";
			else cout << "0 ";
		}
		cout << endl;	
	}
	cout <<endl;
}

int main(){
	int q[8], c = 0;
	q[0] = 0;
	bool gateC = 1;
	bool gateQ = 1;
	while(true){
		while(c < 8){
		    if(gateC){
		        c++;
		        if(c == 8) break;
		    }
			if(gateQ) q[c] = -1;
			while(q[c] < 8){
				q[c]++;
				if (q[c] > 7){
				        gateC = 0;
					gateQ = 0;
					backtrack(c);
					break;
				}
				if(okay(q, c)){
					gateC = 1;	
					gateQ = 1;
					break;
				}
			}
		}
	gateC = 0;
	gateQ = 0;
	print(q);
	backtrack(c);
	}
}
