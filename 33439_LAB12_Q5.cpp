#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;
void printBoard(vector<vector<int>>& board, vector<vector<bool>>& revealed) {
  cout<<"\n  0 1 2 3\n";
  for(int i=0; i<4; i++) {
    cout<<i<<" ";
    for(int j=0; j<4; j++) {
      if(revealed[i][j]) {
        cout<<board[i][j]<<' ';
      } 
      else cout<<"* ";
    }
    cout<<"\n";
  }
  cout<<"\n";
}
bool insideGrid(int i, int j) {
  return i>=0 && i<4 && j>=0 && j<4;
}
bool isHidden(int i, int j, vector<vector<bool>>& revealed) {
  return !revealed[i][j];
}
int playTurn(vector<vector<int>>& board,
             vector<vector<bool>>& revealed,
             int turns=0,
             int matched=0) {
  cout<<"Present Board:\n";
  printBoard(board, revealed);
  int r1, c1;
  cout<<"Pick card no 1 (row col): ";
  cin>>r1>>c1;
  if(!insideGrid(r1, c1)){
    cout<<"Out of map. Try again.\n";
    return playTurn(board, revealed, turns, matched);
  }
  cout<<"flipped: "<<board[r1][c1]<<"\n";
  int r2, c2;
  cout<<"Pick card no 2 (row col): ";
  cin>>r2>>c2;
  if(!insideGrid(r2, c2) || (r1==r2 && c1==c2)){
    cout<<"Wrong Choide. Try again.\n";
    return playTurn(board, revealed, turns, matched);
  }
  if(!isHidden(r1, c1, revealed) || !isHidden(r2, c2, revealed)){
    cout<<"Card already flippled.\n";
    return playTurn(board, revealed, turns, matched);
  }
  cout<<"flipped: "<<board[r2][c2]<<"\n";
  turns++;
  if(board[r1][c1]==board[r2][c2]){
    cout<<"Match!\n";
    revealed[r1][c1]=true;
    revealed[r2][c2]=true;
    matched+=2;
  } 
  else cout<<"Match Not.\n";
  if(matched==16){
    cout<<"You Wiiin in  "<<turns<<" moves.\n";
    printBoard(board, revealed);
    return turns;
  }
  return playTurn(board, revealed, turns, matched);
}
int main(){
  srand(static_cast<unsigned int>(time(0)));
  vector<vector<int>> board(4, vector<int>(4, 0));
  vector<vector<bool>> revealed(4, vector<bool>(4, false));
  vector<int> pool;
  pool.reserve(16);
  for(int i = 1; i<= 8; i++){
    pool.push_back(i);
    pool.push_back(i);
  }
  for(int i=15; i>0; i--){
    int j=rand()%(i+1);
    swap(pool[i], pool[j]);
  }
  for(int i=0; i<4; i++){
    for(int j=0; j<4; j++) {
      board[i][j]=pool[i*4+j];
    }
  }
  int totalMoves=0;
  playTurn(board, revealed, totalMoves);
  return 0;
}