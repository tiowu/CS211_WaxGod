#include<iostream>
#include<cmath>
using namespace std;

bool okay(int* q, int c, int n){
	for(int i = 0; i < c; i++){
		if(abs((q[i]/n) - (q[c]/n)) == abs((q[c]%n) - (q[i]%n))) return false;
	}
	return true;
}

int factorial(int k){
	if(k <= 1) return 1;
	return factorial(k - 1) * k;
}

void move(int *q, int c, int k, int n, int& solution){
	if(c == k){
		print(q, k, n);
		solution++;
		return;
	}
	for(int j = 0; j < n * n; j++){
		q[c] = j;
		if(okay(q, c, n)) move(q, c + 1, k, n, solution);
	}
}

int main(){
	int k, n, solution = 0;
	do{
		cout << "Enter number of Bishops: \n";
		cin >> k;
		cout << "Enrter the size of chess board: \n";
		cin >> n;
		if(k <= n) break;
		else cout << "Error. k must be smaller or equal to n. So ";
	}while(n < k);
	int *q = new int[k];
	move(q, 0, k, n, solution);
	cout << "Solutions for " << k << " bishops on a " << n << "X" << n << " chess board is: ";
	cout << solution/factorial(k) << endl;
}	



