#include "filework.h"
#include "misstake.h"
#include <cstring>
#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int misse = 0;
int missm = 0;
int missh = 0;
int endg = 0;

int main()
{
    setlocale(LC_CTYPE, "");

    srand(time(NULL));
    int check = file_check(WORDSEASY, WORDSNORM, WORDSHARD);
    if (check == 0) {
        cout << "Файл пуст" << endl;
        return 0;
    }
    if (check == -1) {
        cout << "Не найден файл с нужным именем" << endl;
        return 0;
    }
    int word_count = word_count_definition(WORDSEASY);
    cout << word_count << endl;
    char* word_result = take_new_word(WORDSEASY, word_count);
    cout << word_result << endl;

    cout << "Тест" << endl;
    bool end = true;
    int misst = 0;
    int right_letters = 7;
    int false_letters = 0;

    cout << "Выберете сложность (0, 1, 2)" << endl;
    int diffic;
    cin >> diffic;
    int fch = 0;

    if (diffic == 0) {
        false_letters = 10;
    } else if (diffic == 1) {
        false_letters = 5;
    } else if (diffic == 2) {
        false_letters = 3;
    } else {
        cout << "Неправильно ввели сложность, завершение" << endl;
        return 0;
    }
    char flse[false_letters];
    for (int i = 0; i < false_letters; i++) {
        flse[i] = '_';
    }

    char righ[right_letters] = {"Lokomor"};
    char mem[right_letters] = {"_______"};
    char sim;

    while (end == true) {
        int check = 0;
        cout << "Ведите предполагаемую букву" << endl;
        cin >> sim;
        for (int i = 0; i < right_letters; i++) {
            if (sim == righ[i]) {
                misst = misstake(righ, mem, i, right_letters);
                word(misst, flse, mem, diffic, right_letters, false_letters);
                check++;
                break;
            }
        }
        if ((check == 0) && (fch < false_letters + 1)) {
            flse[fch] = sim;
            fch++;
            word(misst, flse, mem, diffic, right_letters, false_letters);
        }
        if (misst == 2) {
            cout << "Игра окончена, вы победили" << endl;
            end = false;
        }
        if (fch >= false_letters) {
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
