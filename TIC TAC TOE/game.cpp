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
