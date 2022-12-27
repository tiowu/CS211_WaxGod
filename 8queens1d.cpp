#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int q[8], c = 0;
	q[0] = 0;
NC:
	c++;
	if(c > 7) goto PRINT;
	q[c] = -1;
NR:
	q[c]++; 
	if(q[c] > 7) goto BACKTRACK;
	for(int i = 0; i < c; i++){
		if(q[i] == q[c] || abs(q[c] - q[i]) == (c - i)) goto NR;
	}
	goto NC;
BACKTRACK:
	c--;
	if(c < 0) return 0;
	goto NR;
PRINT:
	static int numPattern = 0;
	cout << "Pattern #" << ++numPattern << " : " <<endl;
	for(int i = 0; i < 8; i++){
		for(int c = 0; c < 8; c++){
			if(i == q[c]) cout << "1 ";
			else cout << "0 ";
		}
		cout <<endl;
	}
	cout << endl;
	goto BACKTRACK;
}



