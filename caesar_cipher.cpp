/*
 * Lab Assignment 2 — Caesar Cipher (C++)
 * Information Security and Cryptography (AI 331)
 * SVNIT Surat | 5th Sem B.Tech. (AI)
 *
 * Encrypt and decrypt messages by shifting alphabetic characters.
 * Non-alphabetic characters (spaces, digits, punctuation) are left unchanged.
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string caesarEncrypt(const string &plaintext, int key) {
    key = ((key % 26) + 26) % 26;  
    string result;
    result.reserve(plaintext.size());

    for (char ch : plaintext) {
        if (isupper(static_cast<unsigned char>(ch))) {
            int shifted = (ch - 'A' + key) % 26;
            result += static_cast<char>(shifted + 'A');
        } else if (islower(static_cast<unsigned char>(ch))) {
            int shifted = (ch - 'a' + key) % 26;
            result += static_cast<char>(shifted + 'a');
        } else {
            result += ch;
        }
    }
    return result;
}

string caesarDecrypt(const string &ciphertext, int key) {
    return caesarEncrypt(ciphertext, -key);
}

void bruteForce(const string &ciphertext) {
    cout << "\n--- Brute-force attack (all possible keys) ---\n";
    for (int k = 0; k < 26; k++) {
        cout << "Key ";
        if (k < 10) cout << " ";
        cout << k << ": " << caesarDecrypt(ciphertext, k) << "\n";
    }
}

int main() {
    cout << "==================================================\n";
    cout << "  Caesar Cipher — Encrypt / Decrypt (C++)\n";
    cout << "==================================================\n";

    while (true) {
        cout << "\nOptions:\n";
        cout << "  1. Encrypt a message\n";
        cout << "  2. Decrypt a message\n";
        cout << "  3. Encrypt then Decrypt (demo)\n";
        cout << "  4. Brute-force decrypt (show all keys)\n";
        cout << "  5. Exit\n";
        cout << "\nEnter choice (1-5): ";

        string choice;
        if (!getline(cin, choice)) break;

        if (choice == "5") {
            cout << "Exited \n";
            break;
        }

        if (choice != "1" && choice != "2" && choice != "3" && choice != "4") {
            cout << "Invalid choice. Try again.\n";
            continue;
        }

        cout << "Enter the message: ";
        string message;
        getline(cin, message);

        if (choice == "4") {
            bruteForce(message);
            continue;
        }

        cout << "Enter the key (integer shift, e.g. 3): ";
        string keyStr;
        getline(cin, keyStr);

        int key;
        try {
            key = stoi(keyStr);
        } catch (...) {
            cout << "Key must be an integer.\n";
            continue;
        }

        if (choice == "1") {
            string cipher = caesarEncrypt(message, key);
            cout << "\nPlaintext : " << message << "\n";
            cout << "Key       : " << key << "\n";
            cout << "Ciphertext: " << cipher << "\n";
        } else if (choice == "2") {
            string plain = caesarDecrypt(message, key);
            cout << "\nCiphertext: " << message << "\n";
            cout << "Key       : " << key << "\n";
            cout << "Plaintext : " << plain << "\n";
        } else if (choice == "3") {
            string cipher = caesarEncrypt(message, key);
            string recovered = caesarDecrypt(cipher, key);
            cout << "\nOriginal  : " << message << "\n";
            cout << "Key       : " << key << "\n";
            cout << "Encrypted : " << cipher << "\n";
            cout << "Decrypted : " << recovered << "\n";
            cout << "Match?    : " << (message == recovered ? "True" : "False") << "\n";
        }
    }

    return 0;
}
