#include <stdio.h>
#include <stdlib.h>

int getVector(int vector[]){
	FILE *vectorfp;
	char tempString[10];
	char c;
	int stringCounter = 0;
	int elementCount = 0;
	vectorfp = fopen("vector.txt", "r");
	while((c = getc(vectorfp)) != EOF){
		if(c == ' '){
			tempString[stringCounter] = '\0';
			vector[elementCount] = atoi(tempString);
			elementCount++;
			stringCounter = 0;
			continue;
		}
		tempString[stringCounter] = c;
		stringCounter++;
	} 
	tempString[stringCounter] = '\0';
	vector[elementCount] = atoi(tempString);
	elementCount++;
	return elementCount;
}

int getMatrix(int matrix[]){
	FILE *fp;
	char tempString[10];
	int stringCounter = 0;
	int rows;
	int elementCount = 0;
	char c;
	fp = fopen("matrix.txt", "r");
	c = getc(fp);
	tempString[0] = c;
	tempString[1] = '\0';
	rows = atoi(tempString);
	c = getc(fp);
	while((c = getc(fp)) != EOF){
		if(c == ' ' || c == '\n'){
			tempString[stringCounter] = '\0';
			matrix[elementCount] = atoi(tempString);
			elementCount++;
			stringCounter = 0;
			continue;	
		}
		tempString[stringCounter] = c;
		stringCounter++;
	}
	tempString[stringCounter] = '\0';
	matrix[elementCount] = atoi(tempString);
	elementCount++;
	return rows;
}

int main(){
	int vector[1000];
	int *matrix = malloc(1000000*sizeof(int));
	int columns = getVector(vector);
	int rows = getMatrix(matrix);
	printf("%i columns: %i, %i rows: %i\n", columns, vector[3], rows, matrix[35]);
	return 0;
}