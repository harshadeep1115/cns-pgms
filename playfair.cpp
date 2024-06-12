//playfair
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string preparePlaintext(string plaintext) {
    string result = "";
    for (int i = 0; i < plaintext.length(); i++) {
        char c = plaintext[i];
        if (isalpha(c))
            result += toupper(c);
    }
    return result;
}

string generateKeyTable(string key) {
    string keyTable = "";
    bool used[26] = {false};

    for (int i = 0; i < key.length(); i++) {
        char c = key[i];
        if (c == 'J') 
            c = 'I';
        if (!used[c - 'A']) {
            keyTable += c;
            used[c - 'A'] = true;
        }
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (c != 'J' && !used[c - 'A']) {
            keyTable += c;
            used[c - 'A'] = true;
        }
    }
    return keyTable;
}

string encrypt(string plaintext, string keyTable) {
    string ciphertext = "";
    for (int i = 0; i < plaintext.length(); i += 2) {
        char a = plaintext[i];
        char b = (i + 1 < plaintext.length()) ? plaintext[i + 1] : 'X'; 

        if (a == b) {
            b = 'X';
            i--; 
        }
        int row1, col1, row2, col2;
        row1 = keyTable.find(a) / 5;
        col1 = keyTable.find(a) % 5;
        row2 = keyTable.find(b) / 5;
        col2 = keyTable.find(b) % 5;
        if (row1 == row2) {
            ciphertext += keyTable[row1 * 5 + (col1 + 1) % 5];
            ciphertext += keyTable[row2 * 5 + (col2 + 1) % 5];
        } else if (col1 == col2) {
            ciphertext += keyTable[((row1 + 1) % 5) * 5 + col1];
            ciphertext += keyTable[((row2 + 1) % 5) * 5 + col2];
        } else {
            ciphertext += keyTable[row1 * 5 + col2];
            ciphertext += keyTable[row2 * 5 + col1];
        }
    }
    return ciphertext;
}

string decrypt(string ciphertext, string keyTable) {
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i += 2) {
        char a = ciphertext[i];
        char b = ciphertext[i + 1];
        int row1, col1, row2, col2;
        row1 = keyTable.find(a) / 5;
        col1 = keyTable.find(a) % 5;
        row2 = keyTable.find(b) / 5;
        col2 = keyTable.find(b) % 5;
        if (row1 == row2) {
            plaintext += keyTable[row1 * 5 + (col1 - 1 + 5) % 5];
            plaintext += keyTable[row2 * 5 + (col2 - 1 + 5) % 5];
        } else if (col1 == col2) {
            plaintext += keyTable[((row1 - 1 + 5) % 5) * 5 + col1];
            plaintext += keyTable[((row2 - 1 + 5) % 5) * 5 + col2];
        } else {
            plaintext += keyTable[row1 * 5 + col2];
            plaintext += keyTable[row2 * 5 + col1];
        }
    }
    
// plaintext.erase(remove(plaintext.begin(), plaintext.end(), 'X'), plaintext.end());
   return plaintext;
}

int main() {
    string key = "MONARCHY";
    string plaintext;
    cout << "Enter plain text: ";
    cin >> plaintext;
    plaintext = preparePlaintext(plaintext);
    string keyTable = generateKeyTable(key);
    string ciphertext = encrypt(plaintext, keyTable);
    cout << "Plaintext: " << plaintext << endl;
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = decrypt(ciphertext, keyTable);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}