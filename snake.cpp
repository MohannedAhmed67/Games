#include <iostream>
using namespace std;
#include <conio.h>
#include <windows.h>

bool gameover;
const int width = 40;
const int height = 20;
int x, y, fruitx, fruity, score;
enum direction {STOP = 0, RIGHT, LEFT, UP, DOWN};
direction vec;
int length;
int lenx[50], leny[50];



void setup()
{
    gameover = false;
    vec = STOP;
    x = width / 2;
    y = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;

}

void draw()
{
    system("cls");
    for (int i = 0; i < width; i++)
    {
        cout<<"#";
    }
    cout<<endl;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1)
            {
                cout<<"#";
            }
            else if (i == y && j == x)
            {
                cout<<"@";
            }
            else if (i == fruity && j == fruitx)
            {
                cout<<"$";
            }
            else
            {
                bool check = false;
                for (int z = 0; z < length; z++)
                {
                    if(lenx[z] == j && leny[z] == i)
                    {
                        cout<<'%';
                        check = false;
                    }
                }
                if (!check)
                {
                 cout<<" ";
                }
            }
        }
        cout << endl;
    }
    for (int i = 0; i < width; i++)
    {
        cout<<"#";
    }
    cout<<endl;
    cout<<"Score: "<< score<< endl;
}




void input()
{
if(_kbhit())
{
    switch (_getch())
    {
    case 'w':
        vec = UP;
        break;
    case 's':
        vec = DOWN;
        break;
    case 'a':
        vec = LEFT;
        break;
    case 'd':
        vec = RIGHT;
        break;
    case 'j':
        gameover = true;
        break;
    }
}


}

void motion()
{
int x1 = lenx[0];
int y1 = leny[0];
lenx[0] = x;
leny[0] = y;
int x2, y2;

for (int i = 1; i < length; i++)
{
    x2 = lenx[i];
    y2 = leny[i];
    lenx[i] = x1;
    leny[i] = y1;
    x1 = x2;
    y1 = y2;
}

 switch(vec)
 {
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    default:
        break;
}
//if (x > width || x < 0 || y > height || y < 0)
//{
  //  gameover = true;
//}
if (x < 0)
{
    x = width - 1;
}
else if (x > width)
{
    x = 0;
}
else if (y < 0)
{
    y = height - 1;
}
else if (y > height)
{
    y = 0;
}
for (int i = 0; i < length; i++)
{
    if (lenx[i] == x && leny[i] ==y)
    {
        gameover = true;
    }
}

if (y == fruity && x == fruitx)
{
    score++;
    fruitx = rand() % width;
    fruity = rand() % height;
    length++;
}
}


int main()
{

setup();

while (!gameover)
{

draw();
input();
motion();
Sleep(20);


}
return 0;
}
