#include <iostream>
using namespace std;
char game[3][3] =  {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};
char player = 'X';
char whowin();
void play();
void draw();

int main()
{
    while (true)
    {
        system("cls");
        draw();
        play();
        draw();
        if (whowin() == 'X') {
            cout << "X is The Winner\n";
            break;
        }
        else if (whowin() == 'O') {
            cout << "O is The Winner\n";
            break;
        }
        else if (whowin() == 'N') {
            cout << "No Winner\n";
            break;
        }
    }


    return 0;
}


void draw() {

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << game[i][j] << "  ";
        }
        cout << endl;
    }
}
void play() {
    cout << "Choose your Position player " << player << " ";
    char pos; cin >> pos;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (game[i][j] == pos) {
                game[i][j] = player;
            }
        }
    }
    player = (player == 'X') ? 'O' : 'X';

}
char whowin()
{
    for (int i = 0; i < 3; i++)
    {
        int xc = 0, oc = 0;
        for (int j = 0; j < 3; j++) {
            if (game[i][j] == 'X') {
                xc++;
            }
            else if (game[i][j] == 'O') {
                oc++;
            }
        }
        if (xc == 3)
        {
            return 'X';
        }
        else if (oc == 3) {
            return 'O';
        }
    }
    for (int i = 0; i < 3; i++)
    {
        int xc = 0, oc = 0;
        for (int j = 0; j < 3; j++) {
            if (game[j][i] == 'X') {
                xc++;
            }
            else if (game[j][i] == 'O') {
                oc++;
            }
        }
        if (xc == 3)
        {
            return 'X';
        }
        else if (oc == 3) {
            return 'O';
        }
    }
    int xc = 0, oc = 0;
    for (int i = 0; i < 3; i++) {
        if (game[i][i] == 'X') {
            xc++;
        }
        else if (game[i][i] == 'O') {
            oc++;
        }
    }
    if (xc == 3)
    {
        return 'X';
    }
    else if (oc == 3) {
        return 'O';
    }

    int xx = 0;
    int oo = 0;
    for (int i = 0, j = 2; i < 3; i++, j--)
    {
        if (game[i][j] == 'X') {
            xx++;
        }
        else if (game[i][j] == 'O') {
            oo++;
        }
    }
    if (xx == 3)
    {
        return 'X';
    }
    else if (oo == 3) {
        return 'O';
    }

    int playpos = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) {
            if (game[i][j] != 'X' && game[i][j] != 'O')
                playpos++;
        }

    }
    if (playpos == 0)
    {
        return 'N';
    }
    else
        return '.';

}


