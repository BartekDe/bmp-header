#include <stdio.h>
int main(int argc, char* argv[]) {
	unsigned char bufferOriginal[54];//will store the header of the original file

	FILE *ptrOriginal = fopen(argv[1], "rb");//pointer to the original file
	FILE *ptrNew = fopen(argv[2], "r+b");//pointer to the file that we overwrite

	if(ptrOriginal == NULL) {
		printf("couldn't open first file, exiting\n");
		return 0;	
	}

	if(ptrNew == NULL) {
		printf("couldn't open second file, exiting\n");
		return 0;
	}
	
	fread(bufferOriginal, sizeof(bufferOriginal), 1, ptrOriginal);//saving the original header in the bufferOriginal
	
	printf("copied the original header\n");
	
	fseek(ptrNew, 0, SEEK_SET);//sets the position to the beginning of the file
	
	printf("writing the header to the new file\n");
	
	fwrite(bufferOriginal, sizeof(bufferOriginal), sizeof(bufferOriginal), ptrNew);//writing first 54 bytes from the original file to new file
	printf("done.\n");
return 0;	
}
