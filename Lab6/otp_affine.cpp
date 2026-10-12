// Lab Assignment 6 - One Time Pad and Affine Cipher

#include <iostream>
#include <string>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int modInverse(int a) {
    a = (a % 26 + 26) % 26;
    for (int i = 1; i < 26; i++)
        if ((a * i) % 26 == 1)
            return i;
    return -1;
}

string otpEncrypt(string text, string key) {
    string result = "";
    int k = 0;
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z') ch = ch - 32;
        if (ch >= 'A' && ch <= 'Z') {
            char kc = key[k];
            if (kc >= 'a' && kc <= 'z') kc = kc - 32;
            result += char((ch - 'A' + (kc - 'A')) % 26 + 'A');
            k++;
        }
    }
    return result;
}

string otpDecrypt(string text, string key) {
    string result = "";
    int k = 0;
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z') ch = ch - 32;
        if (ch >= 'A' && ch <= 'Z') {
            char kc = key[k];
            if (kc >= 'a' && kc <= 'z') kc = kc - 32;
            result += char((ch - 'A' - (kc - 'A') + 26) % 26 + 'A');
            k++;
        }
    }
    return result;
}

string affineEncrypt(string text, int a, int b) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z') ch = ch - 32;
        if (ch >= 'A' && ch <= 'Z')
            result += char((a * (ch - 'A') + b) % 26 + 'A');
    }
    return result;
}

string affineDecrypt(string text, int a, int b) {
    int aInv = modInverse(a);
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch >= 'a' && ch <= 'z') ch = ch - 32;
        if (ch >= 'A' && ch <= 'Z')
            result += char((aInv * (ch - 'A' - b + 26)) % 26 + 'A');
    }
    return result;
}

int letterCount(string text) {
    int n = 0;
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
            n++;
    }
    return n;
}

int main() {
    int choice;
    cout << "1. One Time Pad\n2. Affine Cipher\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        int mode;
        string text, key;
        cout << "1. Encrypt\n2. Decrypt\nEnter choice: ";
        cin >> mode;
        cin.ignore();

        cout << "Enter message: ";
        getline(cin, text);
        cout << "Enter key (same length as letters): ";
        getline(cin, key);

        if (letterCount(key) < letterCount(text)) {
            cout << "Key must be at least as long as the message.\n";
            return 1;
        }

        if (mode == 1)
            cout << "Ciphertext: " << otpEncrypt(text, key) << endl;
        else
            cout << "Plaintext: " << otpDecrypt(text, key) << endl;
    } else if (choice == 2) {
        int mode, a, b;
        string text;
        cout << "1. Encrypt\n2. Decrypt\nEnter choice: ";
        cin >> mode;
        cin.ignore();

        cout << "Enter message: ";
        getline(cin, text);
        cout << "Enter a: ";
        cin >> a;
        cout << "Enter b: ";
        cin >> b;

        if (gcd(a, 26) != 1) {
            cout << "a must be coprime with 26.\n";
            return 1;
        }

        if (mode == 1)
            cout << "Ciphertext: " << affineEncrypt(text, a, b) << endl;
        else
            cout << "Plaintext: " << affineDecrypt(text, a, b) << endl;
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
