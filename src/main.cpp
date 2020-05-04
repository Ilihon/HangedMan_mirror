#include "draw.h"
#include "filework.h"
#include "misstake.h"

using namespace std;

int misse = 0;
int missm = 0;
int missh = 0;
int endg = 0;

int main()
{
    // system("clear");
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

    cout << "Тест" << endl;
    bool end = true;
    int misst = 0;
    int false_letters = 0;

    cout << "Выберете сложность (0, 1, 2)" << endl;
    int diffic;
    cin >> diffic;
    int fch = 0;

    int word_count;
    char* righ;

    if (diffic == 0) {
        false_letters = 10;
        word_count = word_count_definition(WORDSEASY);
        righ = take_new_word(WORDSEASY, word_count);
    } else if (diffic == 1) {
        false_letters = 5;
        word_count = word_count_definition(WORDSNORM);
        righ = take_new_word(WORDSNORM, word_count);
    } else if (diffic == 2) {
        false_letters = 3;
        word_count = word_count_definition(WORDSHARD);
        righ = take_new_word(WORDSHARD, word_count);
    } else {
        cout << "Неправильно ввели сложность, завершение" << endl;
        return 0;
    }
    int right_letters = strlen(righ);
    char flse[false_letters];
    memset(flse, '_', false_letters);
    char mem[right_letters];
    memset(mem, '_', right_letters);
    system("clear");
    cout << endl << "Слово " << righ << " - " << right_letters << " - ";
    for (int i = 0; i < false_letters; i++) {
        cout << flse[i];
    }
    cout << " - ";
    for (int i = 0; i < right_letters; i++) {
        cout << mem[i];
    }
    cout << endl;
    hangman_draw(0, 0);
    char sim;
    while (end == true) {
        int check = 0;
        cout << endl << "Ведите предполагаемую букву" << endl;
        cin >> sim;
        sim=(char)tolower(sim);
        for (int i = 0; i < right_letters; i++) {
            if (sim == righ[i]) {
                misst = misstake(righ, mem, i, right_letters);
                word(misst, flse, mem, diffic, right_letters, false_letters);
                check++;
                break;
            }
        }
        if ((check == 0) && (fch < false_letters + 1)) {
            int exist = 0;
            for (int i = 0; i < false_letters; i++) {
                if (sim == flse[i]) {
                    exist = 1;
                    break;
                }
            }
            if (exist == 1) {
                word(1, flse, mem, diffic, right_letters, false_letters);
                cout << "This letter already wrong." << endl;
            } else {
                flse[fch] = sim;
                fch++;
                word(misst, flse, mem, diffic, right_letters, false_letters);
            }
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
