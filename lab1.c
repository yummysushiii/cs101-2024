#include <stdio.h>

void print_sp(int row, int r){
	for(int space = 1; space <= row - r; space++){
		printf(" ");
	}
}

void print_num(int r){
	int coef;
	for( int j = 1; j <= r; j++){
		printf("%d",r);
		
	}
}

int main(){
	int row = 6;
	
	for(int r = 0;  r < row; r++){
		print_sp(row, r);
		print_num(r+1);
		printf("\n");
	}
	
	return 0;
}
