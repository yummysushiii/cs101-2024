#include <stdio.h>

int main(){
	char a[] = "A4B1C3f3";
	int j = 1;
	printf("%d", a[1]-48);
	
	for(int i = 0; i < sizeof(a)-1; i++){
		if(i%2!=0){
			for(j = 0; j < a[i]-48; j++){
				printf("%c", a[i-1]);
			}
		}
	}	
	return 0;
} 
