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
	int ID[length] = {1, 2, 3, 4, 5, 6, 7, 8};
	SwapArray(ID, length);
	for(int i = 0; i < length; i++){
		cout << ID[i] << " ";
	}
	cout << endl;		
	cout << "I love it! \n";
	return 0;
}
