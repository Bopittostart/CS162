#include <iostream>
#include <string>
using namespace std;


int check_win(int gameboard[][3], int rows){
   
if(gameboard[0][0] == gameboard[0][1] && gameboard[0][1] == gameboard[0][2]){
    if(gameboard[0][0]==1){
        return 1;
    }
    else if(gameboard[0][0]==2){
        return 2;
    }
    else 
        return 0;
}
if(gameboard[1][0] == gameboard[1][1] && gameboard[1][1] == gameboard[1][2]){
    if(gameboard[1][0]==1){
        return 1;
    }
    else if(gameboard[1][0]==2){
        return 2;
    }
    else 
        return 0;
}
if(gameboard[2][0] == gameboard[2][1] && gameboard[2][1] == gameboard[2][2]){
    if(gameboard[2][0]==1){
        return 1;
    }
    else if(gameboard[2][0]==2){
        return 2;
    }
    else 
        return 0;
}
if(gameboard[0][0] == gameboard[1][0] && gameboard[1][0] == gameboard[2][0]){
    if(gameboard[0][0]==1){
        return 1;
    }
    else if(gameboard[0][0]==2){
        return 2;
    }
    else 
        return 0;
}
if(gameboard[0][1] == gameboard[1][1] && gameboard[1][1] == gameboard[2][1]){
    if(gameboard[0][1]==1){
        return 1;
    }
    else if(gameboard[0][1]==2){
        return 2;
    }
    else 
        return 0;
}
if(gameboard[0][2] == gameboard[1][2] && gameboard[1][2] == gameboard[2][2]){
    if(gameboard[0][2]==1){
        return 1;
    }
    else if(gameboard[0][2]==2){
        return 2;
    }
    else 
        return 0;
}
if(gameboard[0][0] == gameboard[1][1] && gameboard[1][1] == gameboard[2][2]){
    if(gameboard[0][0]==1){
        return 1;
    }
    else if(gameboard[0][0]==2){
        return 2;
    }
    else 
        return 0;
}
if(gameboard[0][2] == gameboard[1][1] && gameboard[1][1] == gameboard[2][0]){
    if(gameboard[0][2]==1){
        return 1;
    }
    else if(gameboard[0][2]==2){
        return 2;
    }
    else 
        return 0;
}
else 
    return 0;

}

void printboard(int gameboard[][3], int rows, int turn){
   
    cout << "Turn: " << turn << endl;
    cout << gameboard[0][0] << "|" << gameboard[0][1] << "|"<< gameboard[0][2] << endl;
    cout << "------" <<endl;
    cout << gameboard[1][0] << "|" << gameboard[1][1] << "|"<< gameboard[1][2] << endl;
    cout << "------" <<endl;
    cout << gameboard[2][0] << "|" << gameboard[2][1] << "|"<< gameboard[2][2] << endl;
    
}

void pve(int gameboard[][3], int rows){



}


void pvp(int gameboard[][3], int row){
    int won = 0;
    int turn = 0;
    while(won == 0){
    
    cout << "enter the X dimension you would like to play" <<endl;
    int x_cord;
    cin>> x_cord;
    cout << "enter the Y dimension you would like to play" <<endl;
    int y_cord;
    cin>> y_cord;
    x_cord--;
    y_cord--;
    turn = turn + 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == y_cord && j == x_cord){
                if (turn % 2 == 0) {
                    gameboard[i][j] = 2;
                } else {
                    gameboard[i][j] = 1;
                }
            
            }
        }
    }
printboard(gameboard, 3, turn);
won = check_win(gameboard, 3);
}

cout << "Player " << won << "Won the Game!!" << endl;
}

int main(){
    int gamemode = 0;
    cout << "Do you want to play against a bot (1) or a player (2)? " <<endl;
    cin >> gamemode;
    int gameboard[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    if (gamemode == 1){
        pve(gameboard, 3);
    }
    if (gamemode == 2){
        pvp(gameboard, 3);
    }
    else
       return 0; 
    
    

    return 0;
}
