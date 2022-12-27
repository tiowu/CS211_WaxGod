#include<iostream>
#include<vector> 
using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main(){
        vector<int>T[3];
        int n, candidate, to, from = 0, numMoves = 0;
        cout << "Enter # rings: \n";
        cin >> n;
        if(n % 2 == 0) to = 2;
        else to = 1;
        for(int i = n + 1; i >= 1; i--) T[0].push_back(i);
        T[1].push_back(n + 1);
        T[2].push_back(n + 1);
        while(T[1].size() != n + 1){
                if(n % 2 == 0){
                        T[to].push_back(T[from].back());
                        candidate = T[from].back();
                        T[from].pop_back();
                        cout << "Move #" << ++numMoves <<": \tTransfer ring " << candidate << " from rod " << (char)(from + 'A') << " to rod " << (char)(to + 'A') <<endl;
                        if(T[(to + 2) % 3].back() < T[(to + 1) % 3].back()) from = (to + 2) % 3;
                        else from = (to + 1) % 3;
                        if(T[from].back() < T[(from + 2) % 3].back()) to =(from + 2) % 3;
                        else to = (from + 1) % 3;
                }
                else{
                        T[to].push_back(T[from].back());
                        candidate = T[from].back();
                        T[from].pop_back();
                        cout << "Move #" << ++numMoves << ": \tTransfer ring " << candidate << " from rod " << (char)(from + 'A') << " to rod " << (char)(to + 'A') <<endl;
                        if(T[(to + 1) % 3].back() < T[(to + 2) % 3].back()) from = (to + 1) % 3;
                        else from = (to + 2) % 3;
                        if(T[from].back() < T[(from + 1) % 3].back()) to = (from + 1) % 3;
                        else to = (from + 2) % 3;
                }
        }

        return 0;
}