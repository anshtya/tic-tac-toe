#include <iostream>
using namespace std;
void start(){ //prints the layout of the game and its slots
    cout<<endl<<"  1  |  2  |  3  "
        <<endl<<"-----------------"
        <<endl<<"  4  |  5  |  6  "
        <<endl<<"-----------------"
        <<endl<<"  7  |  8  |  9  "<<endl
        <<endl<<"User 1 will use O"
        <<endl<<"User 2 will use X";
}
void initialize(char init[][3]){ //initializes the slots with blank spaces
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            init[i][j] = ' ';
        }
    }
}
void printBoard(char board[][3]){  //prints the board
    cout<<endl;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout<<"  "<< board[i][j] << "  ";
            if(j != 2){
                cout<<"|";
            }
        }
        if(i != 2){
            cout<<endl<<"-----------------"<<endl;
        }
    }
}

bool rowCheck(char row[][3]){  //checks similarity in rows
    for (int i = 0; i < 3; i++){
        if(row[i][0] == row[i][1] && row[i][1] == row[i][2] && row[i][0] != ' '){
            return true;
        }
    }
    return false;
}
bool columnCheck(char column[][3]){  //checks similarity in columns
    for (int i = 0; i < 3; i++){
        if(column[0][i] == column[1][i] && column[1][i] == column[2][i] && column[0][i] != ' '){
            return true;
        }
    }
    return false;
}
bool diagonalCheck(char diagonal[][3]){  //checks similarity in diagonals
    if(diagonal[0][0] == diagonal[1][1] && diagonal[1][1] == diagonal[2][2] && diagonal[0][0] != ' '){
        return true;
    }
    else if(diagonal[0][2] == diagonal[1][1] && diagonal[1][1] == diagonal[2][0] && diagonal[2][0] != ' '){
        return true;
    }
    return false;
}
bool Check(char check[][3]){ //returns true if any of the similarities exists
    return(rowCheck(check) || columnCheck(check) || diagonalCheck(check));
}
void switchUser(string* user){  //switches user after its turn
    if(*user == "User 1"){
        *user = "User 2";
    }
    else if(*user == "User 2"){
        *user = "User 1";
    }
}
char playAgain(){  //play again condition
    char choice;
    cout<<endl<<"Do you want to play again? (y/n): ";
    cin>>choice;
    return choice;
}
int main(){
    char ticTacToe[3][3], symbol;
    int totalSlots, slot;
    string user;
    do{
        start();
        initialize(ticTacToe);
        totalSlots = 1;
        user = "User 1";
        while(totalSlots <= 9 && Check(ticTacToe) == false){ 
            cout<<endl<<endl<<user;
            cout<<" Select number: ";
            cin>>slot;
            if(slot < 1 || slot > 9){
                cout<<endl<<"Invalid Number Choice! Enter Again";
                continue;
            }
            else if(ticTacToe[(slot/3)][(slot%3)-1] == 'x' || ticTacToe[(slot/3)][(slot%3)-1] == 'X' || ticTacToe[(slot/3)][(slot%3)-1] == 'o' || ticTacToe[(slot/3)][(slot%3)-1] == 'O'){
                cout<<endl<<"The slot is already occupied! Enter Again";
                continue;
            }
            cout<<"(O/X): ";
            cin>>symbol;
            if((user == "User 1" && (symbol == 'x' || symbol == 'X')) || (user == "User 2" && (symbol == 'o' || symbol == 'O'))){
                cout<<endl<<"Invalid Symbol Choice! Enter Again";
                continue;
            }
            ticTacToe[(slot/3)][(slot%3)-1] = symbol;
            printBoard(ticTacToe);
            totalSlots++;
            if(Check(ticTacToe) == true){
                cout<<endl<<endl<<user<<" wins the game."<<endl;
            }
            else if(totalSlots > 9 && Check(ticTacToe) == false){
                cout<<endl<<endl<<"Match drawn"<<endl;
            }
            else{
                switchUser(&user);
            }
        }
    }while(playAgain() == 'y');

    return 0;
}