# Lab Assignment 5 — Solution
**AI 331 | SVNIT Surat**

## Scenario
Ground control → drone command using **2×2 Hill Cipher**  
**Key:** `K = [[3, 3], [2, 5]]`  
**Plaintext:** `MEET AT BASE`

## Tasks covered
1. Display key matrix  
2. Clean text + map A=0 … Z=25  
3. Split into 2-letter blocks  
4–5. Encrypt and show numbers + ciphertext  
6. Modular inverse of K mod 26  
7–8. Decrypt and verify  

## Run
```bash
g++ -o hill_cipher hill_cipher.cpp
./hill_cipher
```

## Formula
```
C = K × P  (mod 26)     encrypt
P = K⁻¹ × C (mod 26)    decrypt
```

## Results
| Block | Numbers | Cipher |
|-------|---------|--------|
| ME | [12, 4] | WS |
| ET | [4, 19] | RZ |
| AT | [0, 19] | FR |
| BA | [1, 0] | DC |
| SE | [18, 4] | OE |

**Ciphertext:** `WSRZFRDCOE`  
**K⁻¹ mod 26:** `[[15, 17], [20, 9]]`  
**Decrypted:** `MEETATBASE` ✓
