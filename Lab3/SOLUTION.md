# Lab Assignment 3 — Solution
**AI 331 | SVNIT Surat**

## Tasks
1. `brute_force_caesar(ciphertext)` — print all 25 decrypts  
2. Monoalphabetic Substitution Cipher for patient data  

## Run
```bash
g++ -o medtech_cipher medtech_cipher.cpp
./medtech_cipher
```

## Key idea
- **Caesar brute-force:** try keys 1–25  
- **Monoalphabetic:** each letter maps via a fixed 26-letter key  
  `ABCDEFGHIJKLMNOPQRSTUVWXYZ` → `QWERTYUIOPASDFGHJKLZXCVBNM`  
  Digits and `-` are kept as-is  

## Sample
```
Patient ID : PATIENT-9842
Encrypted  : HQZOTFZ-9842
Diagnosis  : PATIENT HAS MILD FEVER
Encrypted  : HQZOTFZ IQL DOSR YTCTK
```
Caesar key 7 → `WHAPLUA-9842`; brute-force finds original at key 7.
