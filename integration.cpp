#include<iostream>
using std::cout;
using std::cin;
using std::endl;

typedef double(*FUNC)(double n);

double straightLine(double n){
	return 2.0;
}

double diagonalLine(double n){
	return n;
}

double square(double n){
	return n * n;
}

double cube(double n){
	return n * n * n;
}

double integrate(FUNC f, double a, double b){
	double delta = 0.000001;
	double s = 0;
	double x = a;
	while(x <= b){
		s += f(x) * delta;
		x += delta;
	}	
	return s;
}

int main(){	
	cout << "The integral of f(x) = 2 between 1 and 5 is " << integrate(straightLine, 1, 5) <<endl;
	cout << "The integral of f(x) = x between 1 and 5 is " << integrate(diagonalLine, 1, 5) <<endl;
	cout << "The integral of f(x) = x^2 between 1 and 5 is " << integrate(square, 1, 5) <<endl;
	cout << "The integral of f(x) = x^3 between 1 and 5 is " << integrate(cube, 1, 5) << endl;
	return 0;
}