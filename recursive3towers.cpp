#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void move(int from, int to, int extra, int numRings){
	static int numMoves = 0;
	if(numRings == 1){
		cout << "Move #" << ++numMoves <<": \tTransfer ring " << numRings << " from rod " << (char)(from + 'A') << " to rod " << (char)(to + 'A') <<endl;
		return;
	}
	move(from, extra, to, numRings - 1);
	cout << "Move #" << ++numMoves <<": \tTransfer ring " << numRings << " from rod " << (char)(from + 'A') << " to rod " << (char)(to + 'A') <<endl;
	move(extra, to, from, numRings - 1);
	return;
}

int main(){
	int numRings, from = 0, to = 1, extra = 2;
	cout << "Enter # rings: \n";
	cin >> numRings;
	move(from, to, extra, numRings);

	return 0;
}