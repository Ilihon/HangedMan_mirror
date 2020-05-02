#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <cstring>
#include <ctime>
#include "filework.h"

using namespace std;

int main()
{
	  srand(time(NULL));
    cout << word_count_definition("word.txt") <<endl;
    char *word_result = take_new_word("word.txt", 11);
    cout << word_result;


    return 0;
}
