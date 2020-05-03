#include "wordch.h"

void word(int pass, char* flse, char* mem, int diff, int r, int f)
{
    system("clear");

    if (pass == 0)
        hangman_draw(1, diff);
    if (pass == 1)
        hangman_draw(0, diff);
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
