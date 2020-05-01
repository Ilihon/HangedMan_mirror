#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int misse = 0;
int missm = 0;
int missh = 0;

void hangman_draw(int misstakes, int difficulty)
{
    string hangman[10]
            = {"\n"
               "\n"
               "\n"
               "\n"
               "\n"
               "\n"
               "\n"
               "\n"
               "==================\n"
               "|                |",

               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "==================\n"
               "|                |",

               "|==========        \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "==================\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "==================\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|         O        \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "==================\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|         O        \n"
               "|         |       \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "==================\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|         O        \n"
               "|        /|        \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "==================\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|         O        \n"
               "|        /|\\      \n"
               "|                  \n"
               "|                  \n"
               "|                  \n"
               "==================\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|         O        \n"
               "|        /|\\      \n"
               "|        /         \n"
               "|                  \n"
               "|                  \n"
               "==================\n"
               "|                |",

               "|==========        \n"
               "|         |        \n"
               "|         |        \n"
               "|         O        \n"
               "|        /|\\      \n"
               "|        / \\      \n"
               "|                  \n"
               "|                  \n"
               "==================\n"
               "|                |"};

    switch (difficulty) {
    case 0:

        if (misstakes > 0)
            misse++;
        if (misse > 9) {
            misse = 0;
            break;
        }
        cout << misse << endl;
        cout << hangman[misse] << endl;
        break;
    case 1:

        if (misstakes > 0)
            missm += 2;
        if (missm == 10) {
            missm -= 1;
        }
        if (missm > 9) {
            missm = 0;
            break;
        }
        cout << hangman[missm] << endl;
        cout << missm << endl;
        break;
    case 2:

        if (misstakes > 0)
            missh += 3;
        if (missh > 9) {
            missh = 0;
            break;
        }
        cout << missh << endl;
        cout << hangman[missh] << endl;
        break;
    }
}

void word(char* righ, char* flse, char* mem, int i, int r, int f)
{
    system("clear");
    int pass = 0;
    for (int b = 0; b < r; b++) {
        if (b == i) {
            mem[b] = righ[i];
            for (int c = b + 1; c < r; c++) {
                if ((righ[c] == mem[b]) && (mem[c] == '_'))
                    mem[c] = righ[c];
                else {
                    if (mem[c] == '_')
                        mem[c] = '_';
                }
            }
            pass = 1;
        }
    }
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
}

int main()
{
    setlocale(LC_CTYPE, "");
    cout << "Тест" << endl;
    int miss = 0;
    int diff = 0;
    bool end = true;
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
                word(righ, flse, mem, i, r, f);
                check++;
                break;
            }
        }
        if (check == 0) {
            flse[fch] = sim;
            fch++;
            word(righ, flse, mem, 25, r, f);
        }
    }

    cin >> diff;
    hangman_draw(miss, diff);

    return 0;
}
