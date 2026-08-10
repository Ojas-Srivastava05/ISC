# AI 331 — Information Security and Cryptography
**SVNIT Surat | 5th Sem B.Tech. (AI) | 2026–27**  
Lab Assignments 1–3

---

## Folder Structure

```
ISC/
├── README.md                 ← you are here
├── Lab1/
│   ├── Lab_Assignment_1.pdf  ← question paper
│   └── SOLUTION.md           ← theory write-up
├── Lab2/
│   ├── Lab_Assignment_2.pdf  ← question paper
│   ├── caesar_cipher.cpp     ← C++ implementation
│   └── SOLUTION.md           ← report + theory
└── Lab3/
    ├── Lab_Assignment_3.pdf  ← question paper
    ├── medtech_cipher.cpp    ← C++ implementation
    └── SOLUTION.md           ← report + theory
```

---

## Assignment Summary

| Lab | Topic | Type | Deliverable |
|-----|-------|------|-------------|
| **1** | Cryptography basics + CIA Triad | Theory | `Lab1/SOLUTION.md` |
| **2** | Caesar Cipher encrypt/decrypt | Coding (C++) | `Lab2/caesar_cipher.cpp` |
| **3** | Brute-force Caesar + Monoalphabetic Cipher (MedTech) | Coding (C++) | `Lab3/medtech_cipher.cpp` |

---

## How to Run

### Lab 2 — Caesar Cipher
```bash
cd Lab2
g++ -std=c++17 -o caesar_cipher caesar_cipher.cpp
./caesar_cipher
```

### Lab 3 — MedTech Prototype
```bash
cd Lab3
g++ -std=c++17 -o medtech_cipher medtech_cipher.cpp
./medtech_cipher
```
Use menu option **7** for the full MedTech demo (patient ID + diagnosis + brute-force).

---

## Quick Reference

**Lab 1:** Confidentiality, Integrity, Availability — and how encryption, hashing, and MACs map to each.

**Lab 2:** `C = (P + k) mod 26` / `P = (C − k) mod 26`

**Lab 3:**
1. Try all keys 1–25 to break Caesar.
2. Substitute each letter via a 26-letter permutation key; keep digits/`-` as-is.
