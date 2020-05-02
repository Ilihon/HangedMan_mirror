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
