#include "draw.h"
#include "misstake.h"
#include "wordch.h"
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

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
        for (int i = 0; i < 7; i++) {
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
            cout << "Игра окончена, вы победили" << endl;
            end = false;
        }
        if (fch >= f) {
            cout << "Игра окончена, вы проиграли" << endl;
            end = false;
        }
        misst = 0;
        if (end == false) {
            char a;
            cin.clear();
            while (cin.get() != '\n') {
                // очистка потока для корректной работы getchar
            };
            cout << "Нажмите enter для выхода" << endl;
            a = getchar();
            system("clear");
        }
    }

    return 0;
}
