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
