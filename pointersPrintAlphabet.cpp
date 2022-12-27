#include<iostream>
using std::cout;
using std::endl;

void constructAlphabet(char *array, const int numLetters){
	for(int i = 0; i < numLetters; i++){
		*(array + i) = (char)('A' + i);
	}
}

void print(char *array, const int numLetters){
	for(int i = 0; i < numLetters; i++){
		if(i % 2 != 0) cout << "Letter [" << i << "] : " << *(array + i) <<endl;
	}
}

int main(){
	const int numLetters = 26;
	char Alphabet[numLetters];
	constructAlphabet(Alphabet, numLetters);
	print(Alphabet, numLetters);
	return 0;
}
