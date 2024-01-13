#include <iostream>
#include<conio.h>
#include <windows.h>
#include<iomanip>
#include <fstream>
using namespace std;

void storeHighestScore(int score);
int loadHighestScore();
// Function prototypes
void gotoxy(int x, int y);
// Player movement functions
void erasetank(int &pX, int &pY);
void printtank(int &pX, int &pY, string &rifle);
void movestankLeft(int &pX, int &pY, string &rifle);
void movetankRight(int &pX, int &pY, string &rifle, int &score);
void movetankup(int &pX, int &pY, string &rifle);
void movetankdown(int &pX, int &pY, string &rifle);

// Enemy type 1 functions
void printEnemy1(int &eX, int &eY);
void eraseEnemy1(int &eX, int &eY);
void moveEnemy1(int &eX, int &eY, int &pX, int &pY);
//                enemy 1 bullet functions
void moveEnemyBullets(int &ex, int &ey, int &pX, int &pY);

// Enemy type 2 functions
void printEnemy2(int &ex, int &ey);
void eraseEnemy2(int &ex, int &ey);
void moveEnemy2(int &ex, int &ey);
//                enemy 2 bullet functions
void moveEnemyBullet(int &ex, int &ey, int &pX, int &pY);
void removeEnemyBullet();
void drawEnemyBullet();

// Enemy type 3 functions
void printEnemy3(int &EX, int &EY);
void eraseEnemy3(int &EX, int &EY);
void moveEnemy3(int &EX, int &EY);
//                enemy 3 bullet functions
void drawEnemyBullet3();
void moveEnemyBullet3(int &ex, int &ey, int &pX, int &pY);
void removeEnemyBullet3();

// Bullet functions
void moveBullet(int &ex, int &ey, int &eX, int &eY, int &EX, int &EY, int &score);
void removeBullet();
void drawBullet();

// World-related functions
void printWorld();
char getCharAtxy(short int x, short int y);

// Character and color generation functions
void generateCharacters();
void generateColors();

// Other game-related functions
int isAlphabet(string value);
void moveBullet();
void shootBullet(int pX, int pY);
void display();
void win();
void gameover();

void controls();

// Color constants
        string setcolor(unsigned short color)
    {
        HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hcon, color);
        return "";
    }  
int bulletX = 0;
int highestScore = 0;
int black = 0, blue = 1, green = 2, cyan = 3, red = 4, magenta = 5, brown = 6, lightwhite = 7, darkwhite = 8, lightblue = 9, lightgreen = 10, lightcyan = 11, lightred = 12, lightmagenta = 13, yellow = 14, white = 15;
int prevBulletX=0;
int prevBulletY=0;
int bulletY = 0;
// int enemyBulletX = -1;
// int enemyBulletY = -1;
// bool enemyBulletActive = false;
int health=500;
int health1=5,health2=5,health3=5; 
void drawEnemyBullets(int &pX,int &pY);
void removeEnemyBullets(int &pX,int &pY);
const int MAX_ENEMY_BULLETS = 5; // Adjust the maximum number of enemy bullets
int enemyX=0;
int enemyY=0;
int enemyX3=0;
int enemyY3=0;
bool live=true;
bool enemi2=true;
bool enemi3=true;
bool enemy2a=true;
bool e3=true;
bool active=true;
int enemyBulletX[MAX_ENEMY_BULLETS];
int enemyBulletY[MAX_ENEMY_BULLETS];
bool enemyBulletActive[MAX_ENEMY_BULLETS];
bool bulletActive = false;
    int i=0;
int count=0;
bool level1=true;
bool touch=true;

// Main function
main()
{
// Variables
string rifle = "||";
int score=0;
int EX=116,EY=53;
int pX = 3, pY = 20;
int eX = 120, eY = 20;
int ex = 126, ey = 6;
int fire=0;
string ops="";

storeHighestScore(score);
highestScore=loadHighestScore();
if(highestScore>10000){
    highestScore=0;
}
int op=isAlphabet(ops);
while (true)
{

    system("cls");
    if(op==0){
        ops="";
display();
gotoxy(75,55);
cin>>ops;
op=isAlphabet(ops);
    }
    else{
      op==0;
      display();

gotoxy(75,55);
cin>>ops;
op=isAlphabet(ops);
        }
    if(op==3){
        system("cls");
storeHighestScore(score);
        exit(0);
    }
    if(op==2){
        system("cls");
       controls();

       getch();
    }
if(op==1){
    
    system("cls");

    printWorld();
    printtank(pX,pY,rifle);
   
while (true){
    
        gotoxy(90,2);
    cout<<"Highest Score: "<<highestScore;
     gotoxy(120,2);
    setcolor(1);
    cout<<"Health: "<<health;
    setcolor(15);
    gotoxy(112,3);
    setcolor(4);
    cout<<"Enemy 1 Health: "<<health1;
      gotoxy(112,4);
    setcolor(4);
    cout<<"Enemy 2 Health: "<<health2;
    setcolor(15);
         gotoxy(134,3);
    setcolor(4);
    cout<<"Enemy 3 Health: "<<health3;
    setcolor(15);
    if(health<=0){
        health=5;
        int pX = 3, pY = 20;
int eX = 120, eY = 20;                    //reset health after game over
int ex = 126, ey = 6;
        break;
    }
        if(health1>=0 && active){             //enemy 1
    moveEnemy2(ex, ey);                      
    if(ex<100){
    }
    if(health1<=0){
        eraseEnemy2(ex,ey);
        active=false;
    }
    }
    if(health1>0 ){//
    moveEnemyBullets(ex, ey,pX,pY);
    }
    if(health2>=0 && enemy2a){
    moveEnemy1(eX, eY,pX,pY);
    moveEnemyBullet(eX,eY,pX,pY);
    if(health2==0){
        eraseEnemy1(eX,eY);
         gotoxy(enemyX, enemyY);
        cout << "  ";
        enemy2a=false;
    }
    }

    if(health1<=0&&health2<=0 && health3<=0){
        system("cls");
        EX=116,EY=53;
 pX = 3, pY = 20;
 eX = 120, eY = 20;
 ex = 126, ey = 6;
        health1=5;
        health=500;
        health2=5;
         enemy2a=true;
e3=true;
 active=true;
        health3=5;
        win();
        break;
    }
    if(health3>=0 && e3){
    moveEnemy3(EX,EY);
    touch=true;
    moveEnemyBullet3(EX, EY,pX,pY);
  if(health3==0){
        eraseEnemy3(EX,EY);
        gotoxy(enemyX3-3, enemyY3+2);
        cout << "   ";
        e3=false;
    }
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        movestankLeft(pX, pY,rifle);
    }
    if (GetAsyncKeyState(VK_UP))
    {
        movetankup(pX, pY, rifle);
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        movetankdown(pX, pY,rifle);

    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        movetankRight(pX, pY, rifle, score);
    }
if (GetAsyncKeyState(VK_SPACE)) {
        shootBullet(pX, pY);
    }

    if (GetAsyncKeyState('F')) {
        setcolor(green);
        if (!bulletActive) {
            if (count == 0) {
                rifle = "//";
                count = 1;
            } else if (count == 1) {
                rifle = "==";
                count = 2;
            } else if (count == 2) {
                rifle = "||";
                count = 0;
            }
            printtank(pX, pY, rifle);
        }
        setcolor(15);
    }

    if (health <= 0) {
        enemy2a=true;
 e3=true;
active=true;
        health=500;
          EX=116,EY=53;
 pX = 3, pY = 20;
 eX = 120, eY = 20;
 ex = 126, ey = 6;
        health1=5;
        health2=5;
        health3=5;
        gameover();
        break;
    }
    removeBullet();
    moveBullet(ex, ey, eX, eY, EX, EY, score);
    drawBullet();
    removeEnemyBullets(pX, pY);
    gotoxy(3, 3);
    cout << "Score: " << score;
    Sleep(20);
}
}
}
}
//                                         store highest score
int loadHighestScore() {
    fstream file;
    int highestScore;

    file.open("highestScore.txt", ios::in);
    if (file.is_open()) {
        file >> highestScore;
        file.close();
    } else {
        file.open("highestScore.txt", ios::out);
        file << 0;
        file.close();
        highestScore = 0;
    }
    return highestScore;
}
   
//                                                                    highest score
void storeHighestScore(int score) {
    fstream file;
    file.open("highestScore.txt", ios::out);
    
    if (!file.is_open()) {
        file << 0;
        return;
    }

    if (score > highestScore) {
        file << score;
    }

    file.close();

}
//                                                                    shoot bullet
void shootBullet(int pX, int pY) {
    if (!bulletActive) {
        bulletX = pX+23;
        bulletY = pY +3;
        bulletActive = true;
    }
}
//                                                                   draw player bullet
 void drawBullet() 
    {
        setcolor(10);
        if (bulletActive) {
        gotoxy(bulletX, bulletY);
        if(count==0){
        cout << '|';
        }
if(count==1){
        cout << '/';
        }
        if(count==2){
        cout << ">";
        }         
          prevBulletX = bulletX;
        prevBulletY = bulletY;
    }
    }
   //                                                               remove player bullet
   void removeBullet()
    {
    if (bulletActive) 
    {
        gotoxy(bulletX, bulletY);
        cout << " ";
    }
}
//                                                                    move player bullet

void moveBullet(int &ex, int &ey, int &eX, int &eY,int &EX,int &EY, int &score) {
    if(bulletActive){

        // Check if the bullet hit enemy 1
        if ( bulletX >= eX && bulletX <= eX + 29 && bulletY <= eY + 5 && enemy2a) {
            bulletActive = false;
            health2--;
            score += 10;
        }

        // Check if the bullet hit enemy 2
        if ( bulletX >= ex && bulletX <= ex + 10 && bulletY >= ey && bulletY <= ey + 7 && active) {
            bulletActive = false;
            health1--;
            score += 20;
        }
if (bulletX >= EX && bulletX <= EX + 5 && bulletY >= EY-5 && bulletY <= EY -2 && e3)
            {
            bulletActive = false;
                health3--;
                score+=30;
            }
        // Move horizontally and vertically
        if(count==1){
        bulletX++;
        bulletY--;
        } 
        if(count==0){
        bulletY--;
        }
        if(count==2){
            bulletX++;
        }

        if (bulletY <= 0 || getCharAtxy(bulletX, bulletY) != ' ') {
            bulletActive = false;
        }
    }

}
void drawEnemyBullet3()
{
    setcolor(4);
    if (enemi3)
    {
        gotoxy(enemyX3, enemyY3-3);
        cout << "(_)";
    }
setcolor(15);
}

void removeEnemyBullet3()
{
    if (enemi3)
    {
        gotoxy(enemyX3, enemyY3-3);
        cout << "   ";
    }
}

void moveEnemyBullet3(int &EX, int &EY, int &pX, int &pY)
{
    if(touch){

    if (!enemi3 && rand() % 100 < 5)
    {
        enemyX3 = EX;
        enemyY3 = EY;
        enemi3 = true;
    }

    if (enemi3)
    {
        removeEnemyBullet3();  

        if (getCharAtxy(enemyX3 - 3, enemyY3) == ' ' || getCharAtxy(enemyX3 - 3, enemyY3) == ' ')
        {
            enemyX3--;
         if ((enemyX3 >= pX && enemyX3-1 <= pX +22  &&
     enemyY3 >= pY && enemyY3 <= pY + 2&& pX+23<=enemyX3-3)) // Adjusted player's height
{
    removeBullet();
    touch = false;
    health -= 2;
}

        } else
        {
            enemi3 = false;  
        }
        if (enemyX3 < 4)
        {
            enemi3 = false;  
        }

        drawEnemyBullet3(); 
    }
    }
}

void drawEnemyBullet()
{
    if (enemi2)
    {
        setcolor(4);
        gotoxy(enemyX, enemyY);
        cout << "<=";
    }
setcolor(15);
}

void removeEnemyBullet()
{
    if (enemi2)
    {
        gotoxy(enemyX, enemyY);
        cout << "  ";
    }
}

void moveEnemyBullet(int &ex, int &ey,int &pX,int &pY)
{
    if (!enemi2 && rand() % 100 < 5)
    {
        enemyX = ex;
        enemyY = ey;
        enemi2 = true;
    }

    if (enemi2)
    {
        removeEnemyBullet();  

       
        if (getCharAtxy(enemyX - 3, enemyY) == ' ')
        {
            enemyX--;  
        if(enemyX >= pX && enemyX <= pX + 25 && enemyY >= pY && enemyY <= pY + 7){
            health--;
        }
        }
        else
        {
            
            enemi2 = false;  
        }

        if (enemyX <= 0)
        {
            enemi2 = false;  
        }

        drawEnemyBullet(); 
    }
}
      
   
int isAlphabet(string value)
{
    try
    {

        int values = stoi(value);
        if (values == 1 || values == 2 || values == 4 || values == 5 || values == 6 || values == 0 || values == 3 || values == 8 || values == 7 || values == 9)
        {
            return values;
        }
        else
        {
            return 0;
        }
    }
    catch (invalid_argument)
    {
        return 0;
    }
    catch (out_of_range)
    {
        return 0;
    }
}
// ...

void drawEnemyBullets(int &pX,int &pY)
{
    for (int i = 0; i < MAX_ENEMY_BULLETS; ++i)
    {
        setcolor(4);
        if (enemyBulletActive[i]&&enemyBulletX[i] >=pX && enemyBulletX[i]<=pX+25 && enemyBulletY[i]<pY)
        {
            gotoxy(enemyBulletX[i], enemyBulletY[i]);
            cout <<"\\_/";
        }
        
            
    }
    setcolor(15);
}

void removeEnemyBullets(int &pX,int &pY)
{
    for (int i = 0; i < MAX_ENEMY_BULLETS; ++i)
    {
        if (enemyBulletActive[i]&&enemyBulletX[i] >=pX && enemyBulletX[i]<=pX+25 && enemyBulletY[i]<pY)
       
        {

        }
    }
}

void moveEnemyBullets(int &ex, int &ey, int &pX, int &pY) {
    for (int i = 0; i < MAX_ENEMY_BULLETS; ++i) {
        if (rand() % 100 < 5 && !enemyBulletActive[i] && enemyBulletY[i] + 4 != pY && ex>=pX && ex<=pX+25 && ex<110) {
            // Fire a new bullet
            enemyBulletX[i] = ex;
            enemyBulletY[i] = ey + 6;
            enemyBulletActive[i] = true;
        }

        if (enemyBulletActive[i]) {
            gotoxy(enemyBulletX[i], enemyBulletY[i]);
            cout << "   ";

            if (enemyBulletY[i] + 1 == pY || getCharAtxy(enemyBulletX[i], enemyBulletY[i] + 1) != ' ') {
                if (enemyBulletY[i] + 1 == pY) {
                    health--;
                }
                enemyBulletActive[i] = false;
            } else {
                enemyBulletY[i]++;
                if (enemyBulletY[i] >= 58) {
                    enemyBulletActive[i] = false;
                }

                // Draw the bullet at the new position
                gotoxy(enemyBulletX[i], enemyBulletY[i]);
                cout << "\\_/";
            }
        }
    }
}

void controls(){
    setcolor(15);
    cout << "###########################################################################################################################################################" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "###########################################################################################################################################################" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#            @@@@@@@@      @ @       @      @  @@@@@@@@@  @@@@@@@@@      @ @     @@        @@@@@@@@@@                                                     #" << endl;
    cout << "#           @            @      @    @ @    @     @@      @@      @    @     @   @@        @@       @                                                     #" << endl;
    cout << "#           @           @        @   @  @   @     @@      @@     @    @       @  @@          @@                                                           #" << endl;
    cout << "#           @           @        @   @   @  @     @@      @@ @@@@     @       @  @@            @@@                                                        #" << endl;
    cout << "#           @           @        @   @    @ @     @@      @@    @     @       @  @@         @      @                                                      #" << endl;
    cout << "#            @@@@@@@@    @  @  @     @     @@     @@      @@      @    @  @  @   @@@@@@@@@  @@@@@@@@                                                      #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#           1) press Space to fire                                                            Try to win the game with maximum health                     #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#           2) press F to change fire direction                                               your score will increase after killng enemies               #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#           3) press arrow keys to move                                                       If u killed by enemy u lost                                 #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "###########################################################################################################################################################" << endl;


}
//                                                                   Move surfer up
void movetankup(int &pX,int &pY,string &rifle)
{
    if (getCharAtxy(pX, pY - 2) == ' ' && pY >= 15)
    {

        erasetank(pX,pY);
        pY = pY - 2;
        printtank(pX,pY,rifle);
    }
}
//                                                        Move surfer left
void movestankLeft(int &pX, int &pY,string &rifle)
{
    if (getCharAtxy(pX - 1, pY) == ' '  && getCharAtxy(pX -1, pY + 6) == ' ' && getCharAtxy(pX - 1, pY + 5) == ' ' && getCharAtxy(pX - 1, pY + 4) == ' ' && getCharAtxy(pX -1, pY + 3) == ' ' && getCharAtxy(pX - 1, pY + 2) == ' ')
    {
        erasetank(pX, pY);
        pX = pX - 2;
        printtank(pX, pY, rifle);
    }
}

//                                                         Move surfer right
void movetankRight(int &pX, int &pY, string &rifle, int &score)
{
    if (getCharAtxy(pX + 29, pY) == '*' || getCharAtxy(pX + 25, pY + 6) == '*' ||
        getCharAtxy(pX + 29, pY + 5) == '*' || getCharAtxy(pX + 25, pY + 4) == '*' ||
        getCharAtxy(pX + 29, pY + 3) == '*' || getCharAtxy(pX + 25, pY + 2) == '*')
    {
        erasetank(pX, pY);
        score = score + 1;
        pX = pX + 2;
        printtank(pX, pY, rifle);
    }
    if (getCharAtxy(pX + 18, pY) == ' ' && getCharAtxy(pX + 23, pY + 6) == ' ' && getCharAtxy(pX + 24, pY + 5) == ' ' && getCharAtxy(pX + 25, pY + 4) == ' ' && getCharAtxy(pX + 27, pY + 3) == ' ' && getCharAtxy(pX + 20, pY + 2) == ' ')
    {

        erasetank(pX, pY);
        pX = pX + 2;
        printtank(pX, pY, rifle);
    }
}

// Move surfer down
void movetankdown(int &pX, int &pY, string &rifle)
{
    if (getCharAtxy(pX, pY + 4) == ' ')
    {
        erasetank(pX, pY);
        pY = pY + 2;
        printtank(pX, pY, rifle);
    }
}


void printWorld()
{
    setcolor(11);
    cout << "###########################################################################################################################################################" << endl;
    cout << "#                                                                              TANK WARS                                                                  #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "###########################################################################################################################################################" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "###########################################################################################################################################################" << endl;
setcolor(15);
}  



//                                                                      erase player
void erasetank(int &pX,int &pY)
{
    gotoxy(pX, pY);
    cout << "                      ";
    gotoxy(pX, pY + 1);
    cout << "                      ";
    gotoxy(pX, pY + 2);
    cout << "                      ";
    gotoxy(pX, pY + 3);
    cout << "                           ";
}
//                                                                     print player
void printtank(int &pX,int &pY,string &rifle)
{
    setcolor(2);
    setcolor(10);
    gotoxy(pX, pY);
    cout<<"    __                "<<endl;
    gotoxy(pX, pY + 1);
    cout<<" --||||||||=========  "<<endl;
    gotoxy(pX, pY + 2);
    cout<<" [|||||||||||||]      "<<endl;
    gotoxy(pX, pY + 3);
    cout<<" \\ooooooooooo/      "<<endl;
    setcolor(15);
}
//                                                                      gotoxy function
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
//                                                                  get charcter at x and y
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

//  print enemy
void printEnemy1(int &eX, int &eY)
{
    setcolor(6);
    gotoxy(eX, eY);
    cout<<"      ________"<<endl;
    gotoxy(eX, eY + 1);
    cout<<"*====|________\\"<<endl;
    gotoxy(eX, eY + 2);
    cout<<" _/            \\"<<endl;
    gotoxy(eX, eY + 3);
   cout<<"/_______________|"<<endl;
    gotoxy(eX, eY + 4);
    cout<<"\\()()()()()()()/" <<endl;
    setcolor(15);
}
//                                                                        erase enemy
void eraseEnemy1(int &eX, int &eY)
{
    gotoxy(eX, eY);
    cout << "                            " << endl;
    gotoxy(eX, eY + 1);
    cout << "                            " << endl;
    gotoxy(eX, eY + 2);
    cout << "                            " << endl;
    gotoxy(eX, eY + 3);
    cout << "                            " << endl;
    gotoxy(eX, eY + 4);
    cout << "                            " << endl;

}
//                                                                        move enemy
void moveEnemy1(int &eX, int &eY,int &pX,int &pY)
{

    static bool patrol = true; 

    eraseEnemy1(eX, eY);
    if (patrol)
    {
        eY = eY + 1;
        eX = eX - 1;
       if(eX > pX && eX < pX + 29 && eY+7 >= pY && eY <= pY + 7|| eY==32){
            patrol = false;
        }
    }
    else
    {
        eY = eY - 1;
        eX = eX + 1;
        if (eY == 20)
        {
            patrol = true;
        }
    }

    printEnemy1(eX,eY);
    Sleep(50); 
    }

// text
 void text(){
    setcolor(12);
    gotoxy(40,3);
cout<<"                     ___   ____                                            ";
    gotoxy(40,4);
cout<<"                                          ||   / |  / / // | |     //   ) )";
    gotoxy(40,5);
cout<< "                                         ||  /  | / / //__| |    //___/ / ";
    gotoxy(40,6);
cout<<"                                           || / /||/ / / ___  |   / ___ (   ";
    gotoxy(40,7);
cout<<"                                          ||/ / |  / //    | |  //   | |   ";
    gotoxy(40,8);
cout<<"                                          |  /  | / //     | | //    | |   ";
    setcolor(15);
 }
//                                                                        display
void display(){
    setcolor(14);
    
    cout << "###########################################################################################################################################################" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "#                                                                                                                                                         #" << endl;
    cout << "###########################################################################################################################################################" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << R"(#                                          __          ____  _     ____ ___  _   _____ ____  _      _____                                              #)" << endl;
    cout << R"(#                                        /  |        /  __\\/ \   /  _ \\  \//  /  __//  _ \/ \__/|/  __/                                              #)" << endl;
    cout << R"(#                                         | |        |  \/|| |   | / \| \  /   | |  _| / \|| |\/|||  \                                                 #)" << endl;
    cout << R"(#                                        _| |_       |  __/| |_/\| |-|| / /    | |_//| |-||| |  |||  /_                                                #)" << endl;
    cout << R"(#                                       |_____|       \_/   \____/\_/ \|/_/     \____\\_/ \|\_/  \|\____\                                              #)" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << R"(#                                                                                                                                                      #)" << endl;
    cout << R"(#                                                                                                                                                      #)" << endl;
    cout << R"(#                                                                                                                                                      #)" << endl;
    cout << R"(#                                                                                                                                                      #)" << endl;
    cout<<R"(#                                               _____  _    _   _ _  __ __        ___    ____                                                            #)"<<endl;
    cout<<R"(#                                               |_   _|/ \  | \ | | |/ / \ \      / / \  |  _ \                                                          # )"<<endl;
    cout<<R"(#                                                 | | / _ \ |  \| | ' /   \ \ /\ / / _ \ | |_)                                                           #)"<<endl;
    cout<<R"(#                                                 | |/ ___ \| |\  | . \    \ V  V / ___ \|  _ <                                                          # )"<<endl;
    cout<<R"(#                                                 |_/_/   \_\_| \_|_|\_\    \_/\_/_/   \_\_| \_                                                          # )"<<endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "##########################################################################################################################################################" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "#                                                                   Select option                                                                        #" << endl;
    cout << "#                                                          ________________________________                                                              #" << endl;
    cout << "#                                                         |                                |                                                             #" << endl;
    cout << "#                                                         |                                |                                                             #" << endl;
    cout << "#                                                         |________________________________|                                                             #" << endl;
    cout << "#                                                                                                                                                        #" << endl;
    cout << "###########################################################################################################################################################" << endl;



















}
//                                                                       print enemy 2
void printEnemy2(int &ex, int &ey)
{
    gotoxy(ex, ey);
	cout<<"       _ /_"<<endl;
    
    gotoxy(ex, ey + 1);
   cout<<"======/      |"<<endl;
    gotoxy(ex, ey + 2);
    cout<<" /_|_         \\"<<endl;
    gotoxy(ex, ey + 3);
    cout<<"/ __           \\"<<endl;
    gotoxy(ex, ey + 4);
    cout<<"\\/============\\/"<<endl;
    gotoxy(ex, ey + 5);
    cout<<"  '-==========-'   "<<endl;
    
    
}
//                                                                       erase enemy 2
void eraseEnemy2(int &ex,int &ey)
{
    gotoxy(ex, ey);
    cout << "                   " << endl;
    gotoxy(ex, ey + 1);
    cout << "                   " << endl;
    gotoxy(ex, ey + 2);
    cout << "                   " << endl;
    gotoxy(ex, ey + 3);
    cout << "                   " << endl;
    gotoxy(ex, ey + 4);
    cout << "                   " << endl;
    gotoxy(ex, ey + 5);
    cout << "                   " << endl;
    gotoxy(ex, ey + 6);
    cout << "                   " << endl;
}
//                                                                       move enemy 2
void moveEnemy2(int &ex,int &ey)
{
    eraseEnemy2(ex,ey);
    ex = ex - 3;
    if (ex == 3)
    {
        ex = 126;
    }
    printEnemy2(ex,ey);
    Sleep(50);
}
//                                                                    generate characters
void generateCharacters()
{
  char character;
  for (int x = 0; x < 256; x++)
  {
    // pick the characters combinations to make your players and enemies
    character = x;
    cout << x << " " << character << endl;
  }
}
                                                                    //  print enemy 2
void printEnemy3(int &EX, int &EY)
{
    setcolor(1);
    gotoxy(EX, EY-5);
    cout << "|    _/--\\_" << endl;
    gotoxy(EX, EY - 4);
    cout << "|___ (`_`#)" << endl;
    gotoxy(EX, EY - 3);
    cout << "()__|---->," << endl;
    gotoxy(EX, EY - 2);
    cout << "     _/--\\_" << endl;
    setcolor(15);
}
//                                                                       erase enemy 2
void eraseEnemy3(int &EX,int &EY)
{
    gotoxy(EX, EY-5);
    cout << "            " << endl;
    gotoxy(EX, EY - 4);
    cout << "            " << endl;
    gotoxy(EX, EY - 3);
    cout << "            " << endl;
    gotoxy(EX, EY - 2);
    cout << "            " << endl;
}
//                                                                       move enemy 2
void moveEnemy3(int &EX,int &EY)
{
    if(health3>0){
    eraseEnemy3(EX,EY);
    if (live)
    {
    printEnemy3(EX,EY);
    }
    }
    else{
        eraseEnemy3(EX,EY);
    }
}
//     
void gameover(){
    setcolor(4);
system("cls");
setcolor(5);
gotoxy(50,15);
cout<<"GAME OVER TRY AGAIN "<<endl;

setcolor(15);             
}
void win(){
    setcolor(lightcyan);
gotoxy(50,15);
cout<<"YOU WIN CONGRATULATIONS "<<endl;   

     Sleep(2000);
setcolor(15);                                                 
}
void finalenemy(){

cout<<"       _\\______            "<<endl;
cout<<"      /        \\========   "<<endl;
cout<<" ____|__________\\_____    "<<endl;
cout<<"/ ___________________ \\    "<<endl;
cout<<"\\/ _===============_ \\/   "<<endl;
cout<<"  \\|  ||  ||  ||  ||  |/   "<<endl;
cout<<"   |  ||  ||  ||  ||  |    "<<endl;
cout<<"   |  ||  ||  ||  ||  |    "<<endl;
cout<<"========================  "<<endl;
cout<<"========================  "<<endl;

}
