#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int receipt_id;
	int receipt_price;
	char receipt_time[32];
	int lotto_set[5][7];
} lotto_record_t;

void lotto_writefile(lotto_record_t lotto[], int num, int num_records, char* time_str, char matrix[][7]){
	FILE* fp = fopen("record.bin", "ab+");
	
	int price = num*100;
	lotto[num_records-1].receipt_id=num_records;
	lotto[num_records-1].receipt_price=price;
	strcpy(lotto[num_records-1].receipt_time, time_str);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 7; j++) {
			
	        lotto[num_records-1].lotto_set[i][j] = matrix[i][j];
	        
	    }
	}
	fwrite(&lotto[num_records-1], sizeof(lotto[num_records-1]), 1, fp);
	fclose(fp);

	return 0;
}

void lotto_readfile(lotto_record_t lotto[], int num_records){
	FILE* fp = fopen("record.bin", "rb");	

	int ans1, ans2, ans3;
	printf("�п�J�������X (�̦h�T��) : ");
	scanf("%d", &ans1);
	scanf("%d", &ans2);
	scanf("%d", &ans3);
	printf("%s%02d %02d %02d", "��J�������X�� : ", ans1, ans2, ans3);
	printf("\n�H�U�������m�� :");
	
	for(int m = 0; m < num_records; m++){
		fread(&lotto[m], sizeof(lotto_record_t), 1, fp);
		for (int i = 0; i < 5; i++) {
		    for (int j = 0; j < 7; j++) {
		    	if(ans1 == lotto[m].lotto_set[i][j] || ans2 == lotto[m].lotto_set[i][j] || ans3 == lotto[m].lotto_set[i][j]){
		    		printf("%s%d", "\n�m�� No. ", i+1);
		    		printf("%s%s", "\n��X�ɶ� :  ", lotto[m].receipt_time);
		    		printf("%s", "\n���X : ");	
		    		for(int k = 0; k < 7; k++){
		    			printf("%02d ", lotto[m].lotto_set[i][k]);
					} 
					break;
				}
		    }
		}
	}
	fclose(fp);
	
	return 0;
}

int main() {
	lotto_record_t lotto[2];
	FILE* file = fopen("record.bin", "rb");
	int num_records = 0;
    if (file != NULL) {
        fseek(file, 0, SEEK_END); // �����ɮ׫��Ш��ɮק���
	    long file_size = ftell(file); // ����ɮפj�p
	    num_records = file_size / sizeof(lotto_record_t) + 1; // �p���Ƶ���
		
        fclose(file);
    } else {
        num_records = 1;
    }
    
	printf("�аݱz�n�R�X�ռֳz�m:");
	int num = 0;
	
	scanf("%d", &num);
	if(num>0 && num<6){	
		time_t curtime;
		time(&curtime);
		char* time_str;
		time_str = ctime(&curtime);
	    time_str[strcspn(time_str, "\n")] = 0;
		FILE* fp;
		srand(time);
		char matrix[5][7];
		int ans;
		srand(1);
		char filename[20];
    	sprintf(filename, "lotto[%05d].txt", num_records); 
	    fp = fopen(filename, "w");
	    
	    for(int i=0; i<5; i++){
	    	for(int j=0; j<7; j++){
	    		if(i<num){
	    			matrix[i][j] = rand() % 69 + 1;
		    		for(int m = 0; m < j; m++){
		    			if(matrix[i][m] == matrix[i][j]){
		    				matrix[i][j] =  rand() % 69 + 1;
						}
					}
				}
				else{
					matrix[i][j]=0;
				}
	    		
			}
		}
	    
	    fprintf(fp,"======== lotto649 ========\n");
	    fprintf(fp,"%s%d%s","=======+ No.0000", num_records," +=======\n");
	    fprintf(fp,"%s%s%s", "=", time_str, "=\n");
		for(int i=0; i<5; i++){
			fprintf(fp, "%s%d%s", "[", i+1,"]:");
			for(int j=0; j<7; j++){
				if(i >= num){
					fprintf(fp, " __");
				}
				else if(matrix[i][j]/10 ==0){
					fprintf(fp, " %d%d", 0, matrix[i][j]);
				}
				else{
					fprintf(fp, " %d", matrix[i][j]);
				}
			}
			fprintf(fp, "\n");
		}
	    fprintf(fp,"======== csie@CGU ========\n");
	    fclose(fp);
	    
	    lotto_writefile(lotto, num, num_records, time_str, matrix);
	}
	else if(num == 0){
		lotto_readfile(lotto, num_records-1);
	}
	
	return 0;
}
