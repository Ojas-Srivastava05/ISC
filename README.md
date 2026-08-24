# AI 331 — Information Security and Cryptography
**SVNIT Surat | 5th Sem B.Tech. (AI) | 2026–27**  
Lab Assignments 1–4

---

## Folder Structure

```
ISC/
├── README.md
├── Lab1/   ← Cryptography basics + CIA Triad (theory)
├── Lab2/   ← Caesar Cipher
├── Lab3/   ← Brute-force Caesar + Monoalphabetic
└── Lab4/   ← Playfair Cipher
```

Each lab folder has the question PDF, `SOLUTION.md`, and C++ code (where needed).

---

## Assignment Summary

| Lab | Topic | Deliverable |
|-----|-------|-------------|
| **1** | Cryptography basics + CIA Triad | `Lab1/SOLUTION.md` |
| **2** | Caesar Cipher | `Lab2/caesar_cipher.cpp` |
| **3** | Brute-force Caesar + Monoalphabetic (MedTech) | `Lab3/medtech_cipher.cpp` |
| **4** | Playfair Cipher (drone command) | `Lab4/playfair_cipher.cpp` |

---

## How to Run

```bash
# Lab 2
cd Lab2 && g++ -o caesar_cipher caesar_cipher.cpp && ./caesar_cipher

# Lab 3
cd Lab3 && g++ -o medtech_cipher medtech_cipher.cpp && ./medtech_cipher

# Lab 4
cd Lab4 && g++ -o playfair_cipher playfair_cipher.cpp && ./playfair_cipher
```
