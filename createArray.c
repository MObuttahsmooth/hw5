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
	fclose(vectorfp);
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
	fclose(fp);
	return rows;
}

void printResult(int resultVector[], int vectorLength){
	char resultVectorString[1000];
	int resultIndex = 0;
	FILE *fp = fopen("result.txt", "w");
	if(fp == NULL) { return; }
	int i = 0;
	for(i = 0; i < vectorLength-1; i++){
		fprintf(fp, "%d ", resultVector[i]);
	}
	fprintf(fp, "%d", resultVector[i]);
	fclose(fp);
}

int main(){
	// int vector[1000];
	// int *matrix = malloc(1000000*sizeof(int));
	// int columns = getVector(vector);
	// int rows = getMatrix(matrix);
	// printf("%i columns: %i, %i rows: %i\n", columns, vector[3], rows, matrix[35]);
	int result[8] = {1, 5, 8, 7, 14, 15, 20043, 24};
	printResult(result, 8);
	return 0;
}