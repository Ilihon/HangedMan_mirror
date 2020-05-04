#ifndef FILEWORK_H
#define FILEWORK_H


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cctype>

#define WORDSEASY "src/word1.txt"
#define WORDSNORM "src/word2.txt"
#define WORDSHARD "src/word3.txt"
#define IGNORESYM " ,.\nабвгдеёжзийклмнопрстуфхцчщьыъэюя0123456789"
using namespace std;

int random_number(int rand_border);
char *take_new_word(char *file_name, int file_length);
int word_count_definition(char *file_name);
int file_check(char *file_name_easy, char *file_name_normal, char *file_name_hard);

#endif
