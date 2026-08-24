// Lab Assignment 4 - Playfair Cipher
// Key: DRONE | Plaintext: ATTACK AT THE STATION

#include <iostream>
#include <string>
using namespace std;

char matrix[5][5];

// 1. Build 5x5 key matrix (I/J share one cell — we skip J)
void buildMatrix(string key) {
    int used[26] = {0};
    used['J' - 'A'] = 1; // treat J as I

    int row = 0, col = 0;

    // place key letters first
    for (int i = 0; i < key.length(); i++) {
        char ch = key[i];
        if (ch >= 'a' && ch <= 'z') ch = ch - 32;
        if (ch == 'J') ch = 'I';
        if (ch < 'A' || ch > 'Z') continue;
        if (used[ch - 'A']) continue;

        matrix[row][col] = ch;
        used[ch - 'A'] = 1;
        col++;
        if (col == 5) { col = 0; row++; }
    }

    // fill remaining letters
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (used[ch - 'A']) continue;
        matrix[row][col] = ch;
        used[ch - 'A'] = 1;
        col++;
        if (col == 5) { col = 0; row++; }
    }
}

void printMatrix() {
    cout << "5x5 Key Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void findPos(char ch, int &r, int &c) {
    if (ch == 'J') ch = 'I';
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (matrix[i][j] == ch) {
                r = i; c = j;
                return;
            }
}

// 2. Format plaintext into digraphs
string prepareText(string text) {
    string clean = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z') ch = ch - 32;
        if (ch == 'J') ch = 'I';
        if (ch >= 'A' && ch <= 'Z') clean += ch;
    }

    // insert X between repeated letters (e.g. TT -> TX T)
    string fixed = "";
    for (int i = 0; i < clean.length(); i++) {
        fixed += clean[i];
        if (i + 1 < clean.length() && clean[i] == clean[i + 1])
            fixed += 'X';
    }

    // pad X if odd length
    if (fixed.length() % 2 == 1)
        fixed += 'X';

    return fixed;
}

// 3. Encrypt one digraph (dir = +1 encrypt, -1 decrypt)
string processPair(char a, char b, int dir) {
    int r1, c1, r2, c2;
    findPos(a, r1, c1);
    findPos(b, r2, c2);

    string out = "";
    if (r1 == r2) {
        // same row — shift columns
        out += matrix[r1][(c1 + dir + 5) % 5];
        out += matrix[r2][(c2 + dir + 5) % 5];
    } else if (c1 == c2) {
        // same column — shift rows
        out += matrix[(r1 + dir + 5) % 5][c1];
        out += matrix[(r2 + dir + 5) % 5][c2];
    } else {
        // rectangle — swap columns
        out += matrix[r1][c2];
        out += matrix[r2][c1];
    }
    return out;
}

string encrypt(string digraphs) {
    string cipher = "";
    for (int i = 0; i < digraphs.length(); i += 2)
        cipher += processPair(digraphs[i], digraphs[i + 1], 1);
    return cipher;
}

// 4. Decrypt
string decrypt(string cipher) {
    string plain = "";
    for (int i = 0; i < cipher.length(); i += 2)
        plain += processPair(cipher[i], cipher[i + 1], -1);
    return plain;
}

int main() {
    string key = "DRONE";
    string plaintext = "ATTACK AT THE STATION";

    cout << "=== Playfair Cipher (Drone Command) ===\n\n";
    cout << "Key       : " << key << endl;
    cout << "Plaintext : " << plaintext << endl;

    // Task 1
    buildMatrix(key);
    cout << endl;
    printMatrix();

    // Task 2
    string digraphs = prepareText(plaintext);
    cout << "\nDigraphs  : ";
    for (int i = 0; i < digraphs.length(); i += 2)
        cout << digraphs[i] << digraphs[i + 1] << " ";
    cout << endl;

    // Task 3
    string ciphertext = encrypt(digraphs);
    cout << "Ciphertext: " << ciphertext << endl;

    // Task 4
    string recovered = decrypt(ciphertext);
    cout << "Decrypted : " << recovered << endl;

    return 0;
}
