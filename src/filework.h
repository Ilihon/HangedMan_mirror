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

char *load_txt(char *file_name){
	FILE *f = fopen(file_name, "r");
	int counter = 0;
	int number_needed = random_number(3);
	char *buf;
	buf = new char[4096];

	while (!feof(f)){
		if (fgets(buf, 4096, f) > 0 && 0 != strcmp(buf, "")){
			//cout << buf;
			if(counter == number_needed){
				return buf;
			}
			counter++;
		}
	}

}
