#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctime>

using namespace std;

int random_number(int rand_border){
	return (rand() % rand_border);
}

char *take_new_word(char *file_name, int file_length){
	FILE *f = fopen(file_name, "r");
	if (f == NULL){
		perror ("Error opening file");
		return "ERROR";
	}
	int counter = 0;
	int number_needed = random_number(file_length);
	char *buf;
	buf = new char[4096];
	char *str;
	cout << number_needed << endl;

	while (!feof(f)){
		if (fgets(buf, 4096, f) > 0 && 0 != strcmp(buf, "")){
			//cout << buf;
			str = strtok(buf, " ,.\n");
			do{
				cout <<counter<<" - "<< str<<endl;
				str = strtok(NULL, " ,.\n");
				if(counter == number_needed){
					fclose(f);
					return buf;
				}
				counter++;
			} while(str);

		}
	}
	free(buf);
	fclose(f);
	return "ERROR";
}
/*
int pre_load_txt(char *file_name){
	int word_count
}
*/
