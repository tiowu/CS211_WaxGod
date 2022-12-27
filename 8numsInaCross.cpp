#include<iostream>
#include<cmath>
using std::cout;
using std::endl;
using std::cin;

bool okay(int q[], int c){
	static int a[8][5]={{-1},
			    {0, -1},
			    {0, -1},
			    {0, 1, 2, -1},
			    {0, 1, 3, -1},
			    {1, 4, -1},
			    {2, 3, 4, -1},
			    {3, 4, 5, 6, -1}};  
	for(int i = 0; i < c; i++){
		if(q[i] == q[c]) return false;
	}
	int g = 0;
	while(a[c][g] != -1){
		if(abs(q[c] - q[a[c][g]]) == 1) return false;
		g++;
	}
	return true;
}


int main(){
	int q[8], c = 0;
	q[0] = 1;
NC:
	c++;
	if(c > 7) goto PRINT;
	q[c] = 0;
NR:
	q[c]++;
	if(q[c] > 8) goto BACKTRACK;
	if(!okay(q, c)) goto NR;
	else goto NC;
BACKTRACK:
	c--;
	if(c < 0) return 0;
	goto NR;
PRINT:
	static int num = 0;
	cout << "Solution #" << ++num << " : \n";
	for(int i = 0; i < 8; i++){
		if(i == 0 || i == 6){
			cout << " " << q[i];
		}
		else if(i == 1 || i == 5){
			cout << q[i] << endl;
		}
		else cout << q[i];
	}
	cout << endl <<endl;
	goto BACKTRACK;
}