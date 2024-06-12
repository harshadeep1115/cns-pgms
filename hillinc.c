
//Hill cipher
#include<stdio.h>
#include<conio.h> 
#include<string.h>

char arr[26];

int find_pos(char a) {
	int i;
	for(i=0; i<26; i++) {
		if(a == arr[i])	return i;
	}
	return -1;
}

void encrypt(char pt[], char ct[], int key[2][2], int ct_arr[]) {
	int pt_len = strlen(pt), i, j=0, k=0;
	for(i=0; i<pt_len; i+=2) {
		int t1 = find_pos(pt[i]);
		int t2 = find_pos(pt[i+1]);
		
		int p1 = t1*key[0][0] + t2*key[0][1];
		int p2 = t1*key[1][0] + t2*key[1][1];
		
		ct_arr[k++] = p1;
		ct_arr[k++] = p2;
		
		ct[j++] = arr[p1%26];
		ct[j++] = arr[p2%26];
		
	}
	ct[j] = '\0';
}

void decrypt(char ct[], int inv[2][2], int ct_arr[], char dt[]) {
	int i, j=0;
	int det = inv[0][0]*inv[1][1] - inv[0][1]*inv[1][0];
	if(det == 0)	{
		printf("\nDet is 0.");
		return;
	}
	for(i=0; i<strlen(ct); i+=2) {
		int t1 = ct_arr[i];
		int t2 = ct_arr[i+1];
		
		int p1 = t1*inv[0][0] + t2*inv[0][1];
		int p2 = t1*inv[1][0] + t2*inv[1][1];
		
		p1 = p1/det;
		p2 = p2/det;
		
		dt[j++] = arr[p1];
		dt[j++] = arr[p2];
	}
	dt[j] = '\0';
}

int main() {
	char pt[30], ct[30], dt[30];
	int key[2][2], i, j, ct_arr[30];
	printf("Enter the plain text: ");
	scanf("%s", &pt);
	printf("Enter the key matrix: ");
	for(i=0; i<2; i++) {
		for(j=0; j<2; j++) {
			scanf("%d", &key[i][j]);
		}
	}
	
	for(i=0; i<26; i++) {
		arr[i] = (char)(97+i);
	}
	
	encrypt(pt, ct, key, ct_arr);
	printf("\n Cipher text: %s", ct);
		
	int inv[2][2];
	inv[0][0] = key[1][1];
	inv[1][1] = key[0][0];
	inv[0][1] = -key[0][1];
	inv[1][0] = -key[1][0];
	
	decrypt(ct, inv, ct_arr, dt);
	printf("\n Original text: %s", dt);	
	return 0;
}