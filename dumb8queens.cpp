#include<iostream>
#include<cmath>
using std::cout;
using std::endl;

bool okay(int* q){
	for(int c = 7; c >= 0; c--){	
		for(int i = 0; i < c; i++){
			if(*(q + c) == *(q + i) || abs(*(q + c) - *(q + i)) == (c - i)) return false;
		}
	}
	return true;
}

void print(int* q){
	static int num = 0;
	cout << "solution #" << ++num << " : \n";
	for(int i = 0; i < 8; i++){
		for(int c = 0; c < 8; c++){
			if(i == *(q + c)) cout << "1 ";
			else cout << "0 ";
		}
		cout << endl;
	}
}

int main(){
	int q[8];
	for(int i0 = 0; i0 < 8; i0++){
		for(int i1 = 0; i1 < 8; i1++){
			for(int i2 = 0; i2 < 8; i2++){
				for(int i3 = 0; i3 < 8; i3++){
					for(int i4 = 0; i4 < 8; i4++){
						for(int i5 = 0; i5 < 8; i5++){
							for(int i6 = 0; i6 < 8; i6++){
								for(int i7 = 0; i7 < 8; i7++){
									*q = i0;
									*(q + 1) = i1;
									*(q + 2) = i2;
									*(q + 3) = i3;
									*(q + 4) = i4;
									*(q + 5) = i5;
									*(q + 6) = i6;
									*(q + 7) = i7;
									if(okay(q)){
										print(q);
										/*
										static int num = 0;
										cout << "Solution #" << ++num << " : \n";
										for(int i = 0; i < 8; i++){
											for(int c = 0; c < 8; c++){
												if(i == *(q + c)) cout << "1 ";
												else cout << "0 ";
											}
											cout << endl;
										}
										*/
										cout <<endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}



