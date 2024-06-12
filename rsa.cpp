//rsa
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a % b);
}

int modInverse(int e, int phiN){
	int d = 0;
	while(d < phiN){
		if((e * d) % phiN == 1)
			return d;
		d++;
	}
	return 1;
}

int main(){
	int p, q;
	cout << "enter p, q prime numbers " << endl;
	cin >> p >> q;
	int n = p * q;
	int phiN = (p -1) * (q - 1);
	int e = 2;
	while(e < phiN){
		if(gcd(e, phiN) == 1)
			break;
		e++;
	}
	
	int d = modInverse(e, phiN);
	
	int plaintext, ciphertext = 1;
	cout << "enter cipher text < n" << endl;
	cin >> plaintext;
	for(int i= 0; i< e; i++)
		ciphertext = (ciphertext * plaintext) % n;
	int decipher = 1;
	for(int i = 0; i< d; i++)
		decipher = (decipher * ciphertext) % n;
	cout << ciphertext << "\t" << decipher << endl;
	return 0;
}