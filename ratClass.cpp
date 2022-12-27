#include<iostream>
using namespace std;

class Rat{
public:
	int n;
	int d;
public:	
	//default constructor
	Rat(){
	n = 0;
	d = 1;
	}
	//parameter constructor
	Rat(int i, int j){
	n = i;
	d = j;
	}
	//conversion constructor 
	Rat(int i){
	n = i;
	d = 1;
	}
	//getter & setter  member functions
	int getN(){ return n;}
	int getD(){ return d;}
	void setN(int i){n = i;}
	void setD(int j){d = j;}
	//operator overload
	Rat operator+(Rat y){
		Rat t;
		t.n = n * y.d + d * y.n;
		t.d = d * y.d;
		return t;
	}
	Rat operator-(Rat y){
		Rat t;
		t.n = n * y.d - d * y.n;
		t.d = d * y.d;
		return t;
	}
	Rat operator*(Rat y){
		Rat t;
		t.n = n * y.n;
		t.d = d * y.d;
		return t;
	}	
	Rat operator/(Rat y){
		Rat t;
		t.n = n * y.d;
		t.d = d * y.n;
		return t;
	}
	bool operator==(const Rat o){
		if(this->n == o.n && this->d == o.d) return true;
		else return false;
	}	

	/*	
	Rat operator+(const Rat& j, const Rat& k){
		Rat t;
		t.n = j.n * k.d + j.d * k.n;
		t.d = j.d * k.d;
		return t;
	}//when defined outside class, the data memebers have to be public.
	*/

	friend ostream& operator<<(ostream &os, Rat i);
	friend istream& operator>>(istream &is, Rat& h);
};

Rat operator+(const Rat& j, const Rat& k){
	Rat t;
	t.n = j.n * k.d + j.d * k.n;
	t.d = j.d * k.d;
	return t;
}//when defined outside class, the data memebers have to be public.

ostream& operator<<(ostream &os, Rat i){
	os<< i.n << "/" << i.d;
	return os;
}

istream& operator>>(istream &is, Rat& h){
	is>> h.n >> h.d;
	return is;
}

int main(){
	Rat x(1, 3), y(1, 3), z, g;
	cout << "x is 1/2 and y is 1/3 " <<endl;
	z = x + y;
	cout << "x + y = " << z.getN() << "/" << z.getD() <<endl;
	z = x - y;
	cout << "x - y = " << z.getN() << "/" << z.getD() <<endl;
	z = x * y;
	cout << "x * y = " << z.getN() << "/" << z.getD() <<endl;
	z = x / y;	
	cout << "x / y = " << z.getN() << "/" << z.getD() <<endl;
	cout << endl << x * y <<endl;
	cout << "Please enter a Rat number: \n";
	cin >> g;
	cout << g <<endl;
	cout << "5 + x = " << 5 + x <<endl;
	cout << (x==y);
	return 0;
}