#include<iostream>
using namespace std;

void SwapArray(int a[], int length){
	int temp;
	for(int i = 0; i < length / 2; i++){
		temp = a[i];
		a[i] = a[length - 1 - i];
		a[length - 1 - i] = temp;
	}
}

int main(){
	const int length = 8;
	int ID[length] = {2, 4, 1, 7, 9, 6, 0, 1};
	SwapArray(ID, length);
	for(int i = 0; i < length; i++){
		cout << ID[i] << " ";
	}
	cout << endl;		
	cout << "I love it! \n";
	return 0;
}
