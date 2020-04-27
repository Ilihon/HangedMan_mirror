

char *load_txt(char *file_name){
	FILE *f = fopen(file_name, "r");
	
	while (!feof(f))
		char buf[4096];
		if (fgets(buf, 4096, f) > 0 && 0 != strcmp(buf, "")) 	
		{

		}
	}
	
	
}

