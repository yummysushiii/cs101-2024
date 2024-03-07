#include <stdio.h>

int main(){
	FILE* fp;
	int a[] = {0,1,2};
	char b[] = "ABC";
	float c[] = {1.1, 1.2, 1.3};
	int ra[3];
	char rb[3];
	float rc[3];
	fp = fopen("a.bin", "wb+");
	fwrite(a, sizeof(a), 1, fp);
	fwrite(b, sizeof(b), 1, fp);
	fwrite(c, sizeof(c), 1, fp);
	fseek(fp, 0, SEEK_SET);
	fread(ra, sizeof(a), 1, fp);
	fread(rb, sizeof(b), 1, fp);
	fread(rc, sizeof(c), 1, fp);
	
	for(int i = 0; i < 3; i++){
		printf("%d ", ra[i]);
	}
	printf("%s", "\n");
	for(int i = 0; i < 3; i++){
		printf("%c ", rb[i]);
	}
	printf("%s", "\n");
	for(int i = 0; i < 3; i++){
		printf("%f ", rc[i]);
	}
	
	return 0;
}
