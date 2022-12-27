#include<iostream>
#include<vector>
using namespace std;
using std::vector;

int fib(int n){
	static int memo[100]={0};
	if(n == 1 || n == 2) return  n - 1;
	if(memo[n] != 0){
		return memo[n];
	}	
	return memo[n] = fib(n - 1) + fib(n - 2);
}

int main(){
	cout << fib(99) << endl;
	return 0;
}
