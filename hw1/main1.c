#include <stdio.h>

int main(){
	char a[] = "AABBBCCCCddd";
	int j = 1;
	for(int i = 0; i < sizeof(a)-1; i++){
		if(a[i] == a[i+1]){
			j = j+1;
			
			continue;
		}
		printf("%c", a[i]);
		printf("%d", j);
		j=1;
	}	
	return 0;
} 
