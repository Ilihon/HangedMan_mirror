#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <ctime>
#include "filework.h"

#define WORDSEASY "word1.txt"
#define WORDSNORM "word2.txt"
#define WORDSHARD "word3.txt"

using namespace std;

int main()
{
	  srand(time(NULL));
		int check = file_check(WORDSEASY, WORDSNORM, WORDSHARD);
		if(check == 0){
			cout << "Файл пуст" << endl;
			return 0;
		}
		if(check == -1){
			cout << "Не найден файл с нужным именем" << endl;
			return 0;
		}
		int word_count = word_count_definition(WORDSEASY);
    cout << word_count <<endl;
    char *word_result = take_new_word(WORDSEASY, word_count);
    cout << word_result<<endl;
    return 0;
}
