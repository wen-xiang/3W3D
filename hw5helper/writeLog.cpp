#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// usage: 
//  writeLog filename startTime records [dt code]
//
//
#include <string.h>
void split(char **arr, char *str, const char *del)
{
    char *s = strtok(str, del);
    while(s != NULL){
        *arr++ = s;
        s = strtok(NULL, del);
    }
}

int main (int argc, char**argv) {
	/*char *str = argv[1];
	char *arr[2];
	const char *del = "/";
	split(arr, str, del);
	//printf(arr[0]+"888"+ arr[1]+"999"+ arr[2]+"777"+argv[1]);
	//printf(arr[1]);*/
	printf(argv[1]);
		
	//FILE *fp = fopen (arr[1], "w");
	FILE *fp = fopen (argv[1], "w");
	
	fprintf (fp, "%s ", argv[2] );  // startTime ... as a string (will overflow 32-bit long)
	fprintf (fp, "%d ", atoi(argv[3]) );  // nrecords
	
	int n = atoi (argv[3]);
	int startRec = 4;
	for (int i = 0; i < n; i++) {
		fprintf (fp, "%d ", atoi(argv[startRec++]));
		fprintf (fp, "%d ", atoi(argv[startRec++])); 
	}

	fclose (fp);
	exit (0);   
}

