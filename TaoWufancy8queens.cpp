#include<iostream> 
#include<cmath>
using std::cout;
using std::endl;

namespace newType{
	typedef std::string box[5][7];
	//using box = string[5][7];
}
using newType::box;

bool okay(int q[], int c){
	for(int i = 0; i < c; i++){
		if(q[c] == q[i] || abs(q[c] - q[i]) == (c - i)) return false;
	}
	return true;
}

void backtrack(int& c){
	c--;
	if(c < 0) exit(1);
}

void print(int q[], box* board[][8], int a, int b){
	box bb, wb, bq, wq;
	
	//fill in the black box, white box, black queen, white queen arrays	
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 7; j++){
			bb[i][j] = "█";
			wb[i][j] = " ";
			bq[i][j] = "█";
			wq[i][j] = " ";
		}
	}
	
	//fill the chess board with the addresses of black box and white box
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if((i + j) % 2 == 0) board[i][j] = &wb;
			else board[i][j] = &bb;
		}
	}
	
	//fill the white queen and black queen arrays
	for(int i = 0; i < 5; i++){
		for(int c = 0; c < 7; c++){
			if(i == 1 and c == 1){
				wq[i][c] = "█";
				bq[i][c] = " ";
			}
			if(i == 2 and c == 1){
				wq[i][c] = "█";
				bq[i][c] = " ";
			}
			if(i == 3 and c == 1){
				wq[i][c] = "█";
				bq[i][c] = " ";
			}
			if(i == 3 and c == 2){
				wq[i][c] = "█";
				bq[i][c] = " ";
			}
			if(i == 1 and c == 3){
				wq[i][c] = "█";
				bq[i][c] = " ";
			}
			if(i == 2 and c == 3){
				wq[i][c] = "█";
				bq[i][c] = " ";
			}
			if(i == 3 and c == 3){
				wq[i][c] = "█";
				bq[i][c] = " ";
			}
			if(i == 3 and c == 4){
				wq[i][c] = "█";
				bq[i][c] = " ";
			}
			if(i == 1 and c == 5){
				wq[i][c] = "█";
				bq[i][c] = " ";
			}
			if(i == 2 and c == 5){
				wq[i][c] = "█";
				bq[i][c] = " ";
			}
			if(i == 3 and c == 5){
				wq[i][c] = "█";
				bq[i][c] = " ";
			}
		}
	}

	//fill chess board with 8 queens positions, i.e. the addresses of black queen and white queen arrays
	for(int i = 0; i < 8; i++){
		if((q[i] + i) % 2 == 0) board[q[i]][i] = &wq;
		else board[q[i]][i] = &bq;
	}
		
	static int num = 0;
	cout << "   Solution #" << ++num << " : \n";	

	cout << "  ";
	for(int i = 0; i < 7 * 8 + 2; i++){
		cout << " ";
	}
	cout <<endl;

	for(int i = 0; i < 8; i++){
		for(int k = 0; k < 5; k++){
			cout << "  " << "|";
			for(int j = 0; j < 8; j++){
				for(int l = 0; l < 7; l++){
					cout << (*board[i][j])[k][l];
				}
			}
			cout << "|" << endl;
		}
	}
	
	//reset chess board
	for(int i = 0; i < 8; i++){
		if((q[i] + i) % 2 == 0) board[q[i]][i] = &wb;
		else board[q[i]][i] = &bb;
	}	
	
	cout << "  ";
	for(int i = 0; i < 7 * 8 + 2; i++){
		cout << "—";
	}
	cout << endl << endl;
}

int main(){
	box *board[8][8];
	int q[8], c = 0;
	q[0] = 0;
	int gate = 1;
	while(1){
		while(c < 8){
			if(gate){
				c++;
				if(c > 7) break;
				q[c] = -1;
			}
			while(q[c] < 8){
				q[c]++;
				if(q[c] > 7){
					gate = 0;
					backtrack(c);
					break;
				}
				if(okay(q, c)){
					gate = 1;
					break;
				}
			}
		}
		gate = 0;	
		backtrack(c);
		print(q, board, 8, 8);
	}
}


