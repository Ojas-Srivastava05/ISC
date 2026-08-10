// Lab Assignment 2 - Caesar Cipher

#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, int key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch >= 'A' && ch <= 'Z')
            result += char((ch - 'A' + key) % 26 + 'A');
        else if (ch >= 'a' && ch <= 'z')
            result += char((ch - 'a' + key) % 26 + 'a');
        else
            result += ch;
    }
    return result;
}

string decrypt(string text, int key) {
    return encrypt(text, 26 - (key % 26));
}

int main() {
    string message;
    int key, choice;

    cout << "1. Encrypt\n2. Decrypt\nEnter choice: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter message: ";
    getline(cin, message);

    cout << "Enter key: ";
    cin >> key;

    if (choice == 1)
        cout << "Ciphertext: " << encrypt(message, key) << endl;
    else
        cout << "Plaintext: " << decrypt(message, key) << endl;

    return 0;
}
