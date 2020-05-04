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
    system("clear");
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

    cout << "Hangman" << endl;
    bool end = true;
    int misst = 0;
    int diffic = 0;
    int fch = 0;
    char* righ;
    int false_letters = 0;
    while(1){
      cout << "Выберете сложность (1, 2, 3)" << endl;
      char diff[256];
      cin >> diff;
      diffic = atoi(diff);
      false_letters = setdificulty(diffic, &righ);
      if(false_letters!=0){
        break;
      }
    }


    int right_letters = strlen(righ);
    char flse[false_letters];
    memset(flse, '_', false_letters);
    char mem[right_letters];
    memset(mem, '_', right_letters);
    system("clear");
    /*cout << endl << "Слово " << righ << " - " << right_letters << " - ";
    for (int i = 0; i < false_letters; i++) {
        cout << flse[i];
    }
    cout << " - ";
    for (int i = 0; i < right_letters; i++) {
        cout << mem[i];
    }
    cout << endl;*/
    hangman_draw(0, 0);
    char sim;
    while (end == true) {
        int check = 0;
        cout << endl << "Ведите предполагаемую букву" << endl;
        cin >> sim;
        sim = (char)tolower(sim);
        int existr = 0;
        for (int i = 0; i < right_letters; i++) {
            if (sim == mem[i]) {
                existr = 1;
                word(1, flse, mem, diffic, right_letters, false_letters);
                cout << "This letter already right." << endl;
                break;
            }
        }
        for (int i = 0; i < right_letters; i++) {
            if ((sim == righ[i]) && (existr == 0)) {
                misst = misstake(righ, mem, i, right_letters);
                word(misst, flse, mem, diffic, right_letters, false_letters);
                check++;
                break;
            }
        }
        if ((check == 0) && (fch < false_letters + 1) && (existr == 0)) {
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
