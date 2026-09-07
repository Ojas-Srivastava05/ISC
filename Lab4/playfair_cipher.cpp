#include <iostream>
#include <string>
using namespace std;

char matrix[5][5];

void buildMatrix(string key) {
    int used[26] = {0};
    used['J' - 'A'] = 1;

    int row = 0, col = 0;

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

string prepareText(string text) {
    string clean = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z') ch = ch - 32;
        if (ch == 'J') ch = 'I';
        if (ch >= 'A' && ch <= 'Z') clean += ch;
    }

    string fixed = "";
    for (int i = 0; i < clean.length(); i++) {
        fixed += clean[i];
        if (i + 1 < clean.length() && clean[i] == clean[i + 1])
            fixed += 'X';
    }

    if (fixed.length() % 2 == 1)
        fixed += 'X';

    return fixed;
}

string processPair(char a, char b, int dir) {
    int r1, c1, r2, c2;
    findPos(a, r1, c1);
    findPos(b, r2, c2);

    string out = "";
    if (r1 == r2) {
        out += matrix[r1][(c1 + dir + 5) % 5];
        out += matrix[r2][(c2 + dir + 5) % 5];
    } else if (c1 == c2) {
        out += matrix[(r1 + dir + 5) % 5][c1];
        out += matrix[(r2 + dir + 5) % 5][c2];
    } else {
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

    buildMatrix(key);
    cout << endl;
    printMatrix();

    string digraphs = prepareText(plaintext);
    cout << "\nDigraphs  : ";
    for (int i = 0; i < digraphs.length(); i += 2)
        cout << digraphs[i] << digraphs[i + 1] << " ";
    cout << endl;

    string ciphertext = encrypt(digraphs);
    cout << "Ciphertext: " << ciphertext << endl;

    string recovered = decrypt(ciphertext);
    cout << "Decrypted : " << recovered << endl;

    return 0;
}
