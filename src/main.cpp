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
    char *word_result = load_txt("word.txt",3);
    //string buffer = load_txt("word.txt");
    //cout << buffer;
    //strcpy(word_result,buffer.c_str());
    cout << word_result;
    return 0;
}
