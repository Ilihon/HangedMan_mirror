#include "draw.h"
#include "misstake.h"
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void word(int pass, char* flse, char* mem, int i, int r, int f)
{
    system("clear");

    if (pass != 1)
        hangman_draw(1, 1);
    if (pass != 0)
        hangman_draw(0, 1);
    cout << "Неправильные буквы" << endl;

    for (int b = 0; b < f; b++) {
        cout << flse[b];
    }
    cout << endl;
    cout << "Отгаданные буквы" << endl;

    for (int b = 0; b < r; b++) {
        if (mem[b] != ' ')
            cout << mem[b];
    }
    cout << endl;
    cout << endg << endl;
}

int main()
{
    setlocale(LC_CTYPE, "");
    cout << "Тест" << endl;
    bool end = true;
    int misst = 0;
    int r = 7;
    int f = 5;
    int fch = 0;
    char righ[r] = {"Lokomor"};
    char flse[f] = {"_____"};
    char mem[r] = {"_______"};
    char sim;

    while (end == true) {
        int check = 0;
        cout << "Ведите предполагаемую букву" << endl;
        cin >> sim;
        for (int i = 0; i < 8; i++) {
            if (sim == righ[i]) {
                misst = misstake(righ, mem, i, r);
                word(misst, flse, mem, i, r, f);
                check++;
                break;
            }
        }
        if ((check == 0) && (fch < f + 1)) {
            flse[fch] = sim;
            fch++;
            word(misst, flse, mem, 25, r, f);
        }
        if (misst == 2) {
            system("clear");
            cout << "Игра окончена, вы победили" << endl;
            end = false;
        }
        if (fch >= f) {
            system("clear");
            cout << "Игра окончена, вы проиграли" << endl;
            end = false;
        }
        misst = 0;
    }

    return 0;
}
