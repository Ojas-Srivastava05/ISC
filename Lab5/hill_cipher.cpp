// Lab Assignment 5 - Hill Cipher (2x2)
// Key: [[3, 3], [2, 5]] | Plaintext: MEET AT BASE

#include <iostream>
#include <string>
using namespace std;

int key[2][2] = {{3, 3}, {2, 5}};
int invKey[2][2];

// modular inverse of a under mod m (extended Euclid)
int modInverse(int a, int m) {
    a = (a % m + m) % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1;
}

// Task 6: inverse of key matrix mod 26
int buildInverse() {
    int det = key[0][0] * key[1][1] - key[0][1] * key[1][0];
    det = (det % 26 + 26) % 26;

    int detInv = modInverse(det, 26);
    if (detInv == -1) {
        cout << "Key matrix is not invertible mod 26!\n";
        return 0;
    }

    // adj = [[d, -b], [-c, a]]
    invKey[0][0] = (key[1][1] * detInv) % 26;
    invKey[0][1] = ((-key[0][1] * detInv) % 26 + 26) % 26;
    invKey[1][0] = ((-key[1][0] * detInv) % 26 + 26) % 26;
    invKey[1][1] = (key[0][0] * detInv) % 26;
    return 1;
}

void encryptBlock(int p1, int p2, int &c1, int &c2) {
    // C = K * P  (mod 26)
    c1 = (key[0][0] * p1 + key[0][1] * p2) % 26;
    c2 = (key[1][0] * p1 + key[1][1] * p2) % 26;
}

void decryptBlock(int c1, int c2, int &p1, int &p2) {
    // P = K^{-1} * C  (mod 26)
    p1 = (invKey[0][0] * c1 + invKey[0][1] * c2) % 26;
    p2 = (invKey[1][0] * c1 + invKey[1][1] * c2) % 26;
}

int main() {
    string plaintext = "MEET AT BASE";

    cout << "=== Hill Cipher (2x2) ===\n\n";

    // Task 1: display key matrix
    cout << "Key Matrix K:\n";
    cout << "| " << key[0][0] << "  " << key[0][1] << " |\n";
    cout << "| " << key[1][0] << "  " << key[1][1] << " |\n";

    // Task 2: uppercase, remove spaces, map to numbers
    string clean = "";
    for (int i = 0; i < plaintext.length(); i++) {
        char ch = plaintext[i];
        if (ch >= 'a' && ch <= 'z') ch = ch - 32;
        if (ch >= 'A' && ch <= 'Z') clean += ch;
    }
    if (clean.length() % 2 == 1) clean += 'X'; // pad if odd

    cout << "\nPlaintext (cleaned): " << clean << endl;
    cout << "Numbers (A=0..Z=25): ";
    for (int i = 0; i < clean.length(); i++)
        cout << (clean[i] - 'A') << " ";
    cout << endl;

    // Task 3–5: blocks, encrypt, show numbers + ciphertext
    string ciphertext = "";
    int cNums[100], n = 0;

    cout << "\n--- Encryption ---\n";
    for (int i = 0; i < clean.length(); i += 2) {
        int p1 = clean[i] - 'A';
        int p2 = clean[i + 1] - 'A';
        int c1, c2;
        encryptBlock(p1, p2, c1, c2);

        cNums[n++] = c1;
        cNums[n++] = c2;
        ciphertext += char(c1 + 'A');
        ciphertext += char(c2 + 'A');

        cout << "Block " << clean[i] << clean[i + 1]
             << " [" << p1 << ", " << p2 << "] -> ["
             << c1 << ", " << c2 << "] -> "
             << char(c1 + 'A') << char(c2 + 'A') << endl;
    }
    cout << "Ciphertext: " << ciphertext << endl;

    // Task 6: modular inverse of key
    if (!buildInverse()) return 1;
    cout << "\nInverse Key Matrix K^-1 (mod 26):\n";
    cout << "| " << invKey[0][0] << "  " << invKey[0][1] << " |\n";
    cout << "| " << invKey[1][0] << "  " << invKey[1][1] << " |\n";

    // Task 7–8: decrypt and verify
    string recovered = "";
    cout << "\n--- Decryption ---\n";
    for (int i = 0; i < n; i += 2) {
        int p1, p2;
        decryptBlock(cNums[i], cNums[i + 1], p1, p2);
        recovered += char(p1 + 'A');
        recovered += char(p2 + 'A');
        cout << "Block [" << cNums[i] << ", " << cNums[i + 1]
             << "] -> [" << p1 << ", " << p2 << "] -> "
             << char(p1 + 'A') << char(p2 + 'A') << endl;
    }

    cout << "\nDecrypted : " << recovered << endl;
    cout << "Original  : " << clean << endl;
    cout << "Match?    : " << (recovered == clean ? "Yes" : "No") << endl;

    return 0;
}
