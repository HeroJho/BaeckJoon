#include <string>
#include <vector>

using namespace std;
int winCheck(const vector<string>& board, char w){
    vector<int> col(3), row(3), dia(2);
    for( int i = 0; i < 3; ++i){
        for( int j = 0; j < 3; ++j){
            if(board[i][j] == w){
                row[i]++;
                col[j]++;
                if( i == j ) dia[0]++;
                if( i+j == 2 )dia[1]++;
                if( row[i] == 3 || col[j] == 3 || dia[0] == 3 || dia[1] == 3) return 1;
            }
        }
    }
    return 0;
}
int solution(vector<string> board) {
    int answer = 1, O = 0, X = 0, o = 0, x = 0;
    for(int i = 0 ; i < board.size(); ++ i) for( int j = 0 ; j < board[i].length(); ++j){
        if( board[i][j] == 'O') O++;
        else if ( board[i][j] == 'X') X++;
    }
    if(O-X < 0 || O-X > 1) return 0;
    if( O >= 3){
        o = winCheck(board,'O');
        x = winCheck(board,'X');
        if(o & x || (o & !(O-X)) || (x & (O-X)))
            return 0;
    }
    return answer;
}