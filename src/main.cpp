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
        system("clear");
        cout << hangman[misse] << endl;
        misse++;
        if (misse > 9) {
            misse = 0;
            break;
        }
        cout << misse << endl;
        break;
    case 1:
        system("clear");
        cout << hangman[missm] << endl;
        missm += 2;
        if (missm == 10) {
            missm -= 1;
        }
        if (missm > 9) {
            missm = 0;
            break;
        }
        cout << missm << endl;
        break;
    case 2:
        system("clear");
        cout << hangman[missh] << endl;
        missh += 3;
        if (missh > 9) {
            missh = 0;
            break;
        }
        cout << missh << endl;
        break;
    }
}

void word(char* righ, char* flse, int i, int r, int f)
{
    char mem[r];
    for (int b = 0; b < r; b++) {
        if (b == i) {
            mem[b] = righ[i];
            cout << mem[b];
        }
    }
    cout << "Неправильные буквы" << endl;
    for (int b = 0; b < f; b++) {
        cout << flse[b];
    }
    cout << endl;
    cout << "Отгаданные буквы" << endl;
}

int main()
{
    setlocale(LC_CTYPE, "");
    cout << "Тест" << endl;
    int miss = 0;
    int diff = 0;
    bool end = true;
    int r = 8;
    int f = 5;
    char righ[r] = {"gaybar!"};
    char flse[f] = {"    "};
    char sim;
    cout << "Ведите предполагаемую букву" << endl;
    cin >> sim;
    for (int i = 0; i < 8; i++) {
        if (sim == righ[i]) {
            word(righ, flse, i, r, f);
        }
    }
    while (end == true) {
        cin >> diff;
        hangman_draw(miss, diff);
    }
    return 0;
}
