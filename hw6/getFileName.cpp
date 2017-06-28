#include <stdio.h>
#include <stdlib.h> //exit
#include <string.h>
#include <io.h> //c_file
#include <direct.h> 

void split(char **arr, char *str, const char *del)
{
	char *s = strtok(str, del);
	while (s != NULL) {
		*arr++ = s;
		s = strtok(NULL, del);
	}
}

int main(int argc, char**argv)
{
	char sdir[256], filter[256], path[256];
	struct _finddata_t c_file, copied_c_file;
	long hFile;
	char *arr[2];
	char *str;
	const char *del = "_";
	int fileCount = 0;

	
	strcpy(sdir, ".\\log");
	strcpy(filter, "*.log");

	_chdir(sdir);
	hFile = _findfirst(filter, &c_file);
	//fprintf (stdout, "n");
	if (hFile != -1)
	{
		do {
			/*sprintf(path, "%s\\%s", sdir, c_file.name);
			printf("%s\n", path);*/
			memcpy(&copied_c_file, &c_file, sizeof(c_file));
			str = copied_c_file.name;
			split(arr, str, del);
			if ( strcmp(arr[0], argv[1] ) == 0 ) {
				printf("%s\n", c_file.name);
				fileCount++;
				//fprintf (stdout, "y");
			}
		} while (_findnext(hFile, &c_file) == 0);
	}
	/*char a= ' ';
	a = getchar();*/
	//printf("\n%d\n", fileCount);
	exit (fileCount);
}