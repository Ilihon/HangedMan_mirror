#include "draw.h"
#include "misstake.h"
#include "wordch.h"
#include <cstring>
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
    int r = 0;
    int f = 0;
    cout << "Ведите длину слова" << endl;
    cin >> r;
    cout << "Выберете сложность (0, 1, 2)" << endl;
    int diffic;
    cin >> diffic;
    int fch = 0;

    if (diffic == 0) {
        f = 10;
    } else if (diffic == 1) {
        f = 5;
    } else if (diffic == 2) {
        f = 3;
    } else {
        cout << "Неправильно ввели сложность, завершение" << endl;
        return 0;
    }
    char flse[f];
    for (int i = 0; i < f; i++) {
        flse[i] = '_';
    }

    char righ[r] = {"Lokomor"};
    char mem[r] = {"_______"};
    char sim;

    while (end == true) {
        int check = 0;
        cout << "Ведите предполагаемую букву" << endl;
        cin >> sim;
        for (int i = 0; i < r; i++) {
            if (sim == righ[i]) {
                misst = misstake(righ, mem, i, r);
                word(misst, flse, mem, diffic, r, f);
                check++;
                break;
            }
        }
        if ((check == 0) && (fch < f + 1)) {
            flse[fch] = sim;
            fch++;
            word(misst, flse, mem, diffic, r, f);
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
