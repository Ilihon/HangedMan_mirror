#include "draw.h"

extern int misse;
extern int missm;
extern int missh;
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
        if (misse > 10) {
            misse = 0;
            break;
        }
        cout << misse << endl;
        cout << hangman[misse - 1] << endl;
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