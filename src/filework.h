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
	char *line;
	line = new char[4096];
	char *buf;
	cout << number_needed << endl;

	while (!feof(f)){
		if (fgets(line, 4096, f) > 0 && 0 != strcmp(line, "")){
			//cout << buf;
			buf = strtok(line, " ,.\n"); //разделяет строку ну слова, если идут через пробел, запятую, точку или конец строки
			do{
				cout <<counter<<" - "<< buf<<endl;
				if(counter == number_needed){
					//переводит слово в нижний регистр
				  //for (int i = 0; i < strlen(buf); ++i) {
    				//buf[i] = tolower(buf[i]);
						//cout << buf[i]+1;
						//cout << strcmp(buf,"Юра0");
	    			//if(buf[i]>='А' && buf[i]<='Я'){
							//cout << i;
						//	buf[i]+='я'-'Я';
						//}
					//}
					//cout << buf <<endl;
					//cout << buf;
					///////////////////////////////////
					fclose(f);
					return buf;
				}
				buf = strtok(NULL, " ,.\n");
				counter++;
			} while(buf);

		}
	}
	fclose(f);
	free(line);
	//free(buf);
	return "ERROR";
}

int word_count_definition(char *file_name){
	FILE *f = fopen(file_name, "r");
	if (f == NULL){
		perror ("Error opening file");
		return -1;
	}
	int word_count = 0;
	char *line;
	line = new char[4096];
	char *buf;
	while (!feof(f)){
		if (fgets(line, 4096, f) > 0 && 0 != strcmp(line, "")){
			buf = strtok(line, " ,.\n");
			do{
				word_count++;
				buf = strtok(NULL, " ,.\n");
			} while(buf);

		}
	}
	fclose(f);
	free(line);
	return word_count;
}
