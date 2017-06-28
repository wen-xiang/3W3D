#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// usage: 
//  readLog filename 
//
//

int main (int argc, char**argv) {
		
	FILE *fp = fopen (argv[1], "r");
	//printf(argv[1]);
	
	
	char time[50];
	fscanf (fp, "%s", time);
	printf ("%s ", time);
	
	int n;
	fscanf (fp, "%d", &n);
	printf ("%d ", n);
	
	int dt, x, z, Or;
	for (int i = 0; i < n; i++) {
		fscanf (fp, "%d%d%d%d", &dt, &x, &z, &Or);
		printf ("%d %d %d %d ", dt, x, z, Or); 
	}
	//printf ("\n");
	fclose (fp);
	exit (0);   
}

