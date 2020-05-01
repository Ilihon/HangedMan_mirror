#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void hangman_draw(int misstakes)
{
    string hangman[6]
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
               "|                |"};

    for (int i = 0; i < 3; i++) {
        system("clear");
        cout << hangman[i] << endl;
        char ch = getchar();
        system("clear");
    }
}

int main()
{
    setlocale(LC_CTYPE, "");
    cout << "Тест" << endl;
    int miss = 0;
    hangman_draw(miss);
    return 0;
}
