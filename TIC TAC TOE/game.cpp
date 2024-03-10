#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
string setcolor(unsigned short color);
int checkwin();
void board();
int main() {
    int choice;
    char mark;
do {
        board();
        setcolor(11);
cout << "Player 1, enter a number: ";
        cin >> choice;
setcolor(15);
        mark = 'X';
 if (choice >= 1 && choice <= 9 && square[choice] == (choice + '0'))
            square[choice] = mark;
else {
            cout << "Invalid move ";
            getch();
        }
int a = checkwin();
        if (a == 1) {
            cout << "Player 1 wins";
            break;
        }
else if (a == 0)
         {
            cout << "Game draw";
            break;
             if (choice >= 1 && choice <= 9 && square[choice] == (choice + '0'))
            square[choice] = mark;
        else {
            cout << "Invalid move ";
            getch();
        }
        }
board();
        setcolor(6);
        cout << "Player 2, enter a number: ";
        cin >> choice;
        setcolor(2);
        mark = 'O';
        setcolor(2);
 a = checkwin();
        if (a == 1) {
            cout << "Player 2 wins";
            break;
        } else if (a == 0) {
            cout << "Game draw";
            break;
        }
    } 
 while (true);

    getch();
    return 0;
}
 void board(){
    system("cls");
    setcolor(4);
    cout<<R"( ____  ____  ___    ____   __    ___    ____  _____  ____ )"<<endl;
    cout<<R"((_  _)(_  _)/ __)  (_  _) /__\  / __)  (_  _)(  _  )( ___))"<<endl;
    cout<<R"(  )(   _)(_( (__     )(  /(__)\( (__     )(   )(_)(  )__) )"<<endl;
    cout<<R"( (__) (____)\___)   (__)(__)(__)\___)   (__) (_____)(____))"<<endl;
    setcolor(15);
    cout<<endl;
    setcolor(3);
    cout<<"PLAYER 1(X)------PLAYER 2(O)"<<endl;
    cout<<endl;
setcolor(15);
cout<<" "<<endl;
    setcolor(5);
    cout<<"     |     |     "<<endl;
    cout<<"  "<<square[1]<<"  |  "<<square[2]<<"  |  "<<square[3]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<square[4]<<"  |  "<<square[5]<<"  |  "<<square[6]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<square[7]<<"  |  "<<square[8]<<"  |  "<<square[9]<<"  "<<endl;
    cout<<"     |     |     "<<endl;
    setcolor(15);
    cout<<" "<<endl;
    cout<<" "<<endl;
}
int checkwin() {
    if (square[1] == square[2] && square[2] == square[3]) {
        return 1;
    } else if (square[4] == square[5] && square[5] == square[6]) {
        return 1;
    } else if (square[7] == square[8] && square[8] == square[9]) {
        return 1;
    } else if (square[1] == square[4] && square[4] == square[7]) {
        return 1;
    } else if (square[2] == square[5] && square[5] == square[8]) {
        return 1;
    } else if (square[3] == square[6] && square[6] == square[9]) {
        return 1;
    } else if (square[1] == square[5] && square[5] == square[9]) {
        return 1;
    } else if (square[3] == square[5] && square[5] == square[7]) {
        return 1;
    } else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
               square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
               != '7' && square[8] != '8' && square[9] != '9') {
        return 0;
    } else {
        return -1;
    }
}
string setcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    return "";
}

