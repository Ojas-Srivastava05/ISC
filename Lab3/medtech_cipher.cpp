// Lab Assignment 3 - MedTech Encryption Prototype
// Task 1: Brute-force Caesar
// Task 2: Monoalphabetic Substitution Cipher

#include <iostream>
#include <string>
using namespace std;

// Plain : ABCDEFGHIJKLMNOPQRSTUVWXYZ
// Cipher: QWERTYUIOPASDFGHJKLZXCVBNM
string key = "QWERTYUIOPASDFGHJKLZXCVBNM";

// ---------- Task 1: Brute-force Caesar ----------
void brute_force_caesar(string ciphertext) {
    cout << "\nBrute-force Caesar (all 25 keys):\n";
    for (int k = 1; k <= 25; k++) {
        string plain = "";
        for (int i = 0; i < ciphertext.length(); i++) {
            char ch = ciphertext[i];
            if (ch >= 'A' && ch <= 'Z')
                plain += char((ch - 'A' - k + 26) % 26 + 'A');
            else if (ch >= 'a' && ch <= 'z')
                plain += char((ch - 'a' - k + 26) % 26 + 'a');
            else
                plain += ch;
        }
        cout << "Key " << k << ": " << plain << endl;
    }
}

// ---------- Task 2: Monoalphabetic Cipher ----------
string mono_encrypt(string text) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch >= 'A' && ch <= 'Z')
            result += key[ch - 'A'];
        else if (ch >= 'a' && ch <= 'z')
            result += char(key[ch - 'a'] + 32); // lowercase
        else
            result += ch; // keep digits, spaces, '-'
    }
    return result;
}

string mono_decrypt(string text) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];
        if (ch >= 'A' && ch <= 'Z') {
            for (int j = 0; j < 26; j++) {
                if (key[j] == ch) {
                    result += char('A' + j);
                    break;
                }
            }
        } else if (ch >= 'a' && ch <= 'z') {
            for (int j = 0; j < 26; j++) {
                if (key[j] == ch - 32) {
                    result += char('a' + j);
                    break;
                }
            }
        } else {
            result += ch;
        }
    }
    return result;
}

int main() {
    // Sample medical data
    string patientId = "PATIENT-9842";
    string diagnosis = "PATIENT HAS MILD FEVER";

    cout << "=== MedTech Encryption Prototype ===\n\n";
    cout << "Patient ID : " << patientId << endl;
    cout << "Diagnosis  : " << diagnosis << endl;

    // Monoalphabetic encrypt / decrypt
    string encId = mono_encrypt(patientId);
    string encNote = mono_encrypt(diagnosis);

    cout << "\n--- Monoalphabetic Cipher ---\n";
    cout << "Encrypted ID   : " << encId << endl;
    cout << "Decrypted ID   : " << mono_decrypt(encId) << endl;
    cout << "Encrypted Note : " << encNote << endl;
    cout << "Decrypted Note : " << mono_decrypt(encNote) << endl;

    // Caesar encrypt patient ID with key 7, then brute-force it
    string caesarCipher = "";
    int caesarKey = 7;
    for (int i = 0; i < patientId.length(); i++) {
        char ch = patientId[i];
        if (ch >= 'A' && ch <= 'Z')
            caesarCipher += char((ch - 'A' + caesarKey) % 26 + 'A');
        else
            caesarCipher += ch;
    }

    cout << "\n--- Caesar Cipher (key = 7) ---\n";
    cout << "Encrypted ID: " << caesarCipher << endl;
    brute_force_caesar(caesarCipher);

    return 0;
}
