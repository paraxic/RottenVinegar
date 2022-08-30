#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//Vignere Cipher
void vinegar(char * str, const char * key, char * out) {
	size_t i = 0, k = 0, o = 0;
	size_t str_len = 0, key_len = 0, out_len = 0;
	str_len = strnlen(str,500);
	key_len = strnlen(key,500);
	//printf("Debug: Inside Vinegar\n");
	// i + k = o (str character + key character = out character)
	for( i = 0; i < str_len; i++) {
		if(k <= key_len) { k = 0; }  //reach end of key start at beginning
		out[o++] = str[i] + key[k++]; 
	}
}

void un_vinegar(char * str, const char * key, char * out) {
	size_t i = 0, k = 0, o = 0;
	size_t str_len = 0, key_len = 0, out_len = 0;
	str_len = strnlen(str,500);
	key_len = strnlen(key,500);
	//printf("Debug: Inside Un_Vinegar\n");
	// i + k = o (str character + key character = out character)
	for( i = 0; i < str_len; i++){
		if(k <= key_len) { k = 0; }  //reach end of key start at beginning
		out[o++] = str[i] - key[k++]; 
	}
}

void rot(char * str, char rotv, char * out) {
	size_t i = 0;
	for( i = 0; i < strnlen(str,500); i++) {
		out[i] = str[i] + rotv;
	}
}

void un_rot(char * str, char rotv, char * out) {
	size_t i = 0;
	for( i = 0; i < strnlen(str,500); i++) {
		out[i] = str[i] - rotv;
	}
}

void print_hex(char * hex) {
	size_t len = strnlen(hex,5000);
	size_t i = 0;
	for(i = 0; i < len; i++) {
		printf("%hhx ",hex[i]);
	}
	printf("\n");
}

int main(int argc, char * argv[]) {

char * text = argv[1];
char * key = argv[2];
char * ES1 = malloc(sizeof(char) * 500);
char * DS1 = malloc(sizeof(char) * 500);
char * ES2 = malloc(sizeof(char) * 500);
char * DS2 = malloc(sizeof(char) * 500);

printf("Text: %s\n",text);
vinegar(text,key,ES1); //Text has been Vignere'd 
printf("ES1(Vignere): %s\n", ES1);
rot(ES1,0x0d,ES2);
printf("ES2(Vignere+Rot): %s\n",ES2);//Text Fully encrypted
un_rot(ES2,0x0d,DS1);
printf("DS1(Vignere): %s\n",DS1); //Text has ROT removed
un_vinegar(DS1,key,DS2); //all Encryption removed (PlainText)
printf("DS2(Vignere+Rot): %s\n",DS2);
printf("VG Encrypted (hex): ");
print_hex(ES1);
printf("VG+ROT Encrypted (hex): ");
print_hex(ES2);
free(ES1);
free(ES2);
free(DS1);
free(DS2);
return EXIT_SUCCESS;
}
