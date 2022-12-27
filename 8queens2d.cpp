#include<iostream>
using namespace std;

int main(){
	int cb[8][8] = {0}, r, c = 0;
	cb[0][0] = 1;
NC:
	c++;
	if(c > 7) goto PRINT;
	r = -1;
NR:
	r++;
	if(r > 7) goto BACKTRACK;
	for(int i = 0; i < c; i++){
		if(cb[r][i] == 1) goto NR;
	}
	for(int i = 1; (r - i) >= 0 and (c - i) >= 0; i++){
		if(cb[r - i][c - i] == 1) goto NR;
	}
	for(int i = 1; (r + i) < 8 and (c - i) >= 0; i++){
		if(cb[r + i][c - i] == 1) goto NR;
	}
	cb[r][c] = 1;
	goto NC;
BACKTRACK:
	c--;
	if(c < 0) return 0;
	r = 0;
	while(cb[r][c] != 1){
		r++;
	}
	cb[r][c] = 0;
	goto NR;
PRINT:
	static int num = 0;
	cout << "Solution #" << ++num << " : \n";
	for(int i = 0; i < 8; i++){
		for(int d = 0; d < 8; d++){
			cout << cb[i][d] << " ";
		}
		cout <<endl;
	}
	cout << endl;
	goto BACKTRACK;
}




