#include<iostream>
using std::cout;
using std::endl;

void swapGrades(float *grades, const int numGrades){
	for(int i = 0; i < numGrades / 2; i++){
		float temp = *(grades + i);
		*(grades + i) = *(grades + (numGrades - 1 - i));
		*(grades + (numGrades - 1 - i)) = temp; 
	}
	cout << endl;
}

void print(float *grades, const int numGrades, std::string label){
	cout << label << " Class Grades = {";
	for(int i = 0; i < numGrades; i++){
		if(i == numGrades - 1) cout << *(grades + i) << "} ";
		else cout << *(grades + i) << ", ";
	}
	cout << endl;
}

int main(){
	const int numGrades = 4;
	float classGrades[numGrades] = {91.8, 79.4, 100.4, 67.9};
	print(classGrades, numGrades, "Original");
	swapGrades(classGrades, numGrades);
	print(classGrades, numGrades, "Reversed");
	cout << endl;
	return 0;
}