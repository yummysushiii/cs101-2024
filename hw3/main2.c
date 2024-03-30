#include <stdio.h>
void replace_all(char* str, char oldChar, char newChar){
	while(*str != '\0'){
		if(*str=='a'){
			*str = *str - oldChar + newChar;
		}
		
		str++;
	}
}

int main() {
    char str[100], oldChar = 'a', newChar = 'A'; 
    scanf("%s", str);
    
    replace_all(str, oldChar, newChar);
    printf("%s", str);
    return 0;
}
