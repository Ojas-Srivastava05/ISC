# Lab Assignment 4 — Solution
**AI 331 | SVNIT Surat**

## Scenario
Ground control → drone command using Playfair Cipher  
**Key:** `DRONE`  
**Plaintext:** `ATTACK AT THE STATION`

## Tasks
1. Build 5×5 key matrix  
2. Format digraphs (X for repeats / odd length)  
3. Encrypt  
4. Decrypt to verify  

## Run
```bash
g++ -o playfair_cipher playfair_cipher.cpp
./playfair_cipher
```

## Key matrix (key = DRONE)
```
D R O N E
A B C F G
H I K L M
P Q S T U
V W X Y Z
```
(I/J share one cell — J is skipped)

## Rules
- **Same row** → shift right (encrypt) / left (decrypt)  
- **Same column** → shift down (encrypt) / up (decrypt)  
- **Rectangle** → swap columns  

## Sample output
```
Digraphs  : AT XT AC KA TX TH ES TA TI ON
Ciphertext: FPYSBFHCSYPLOUPFQLNE
Decrypted : ATXTACKATXTHESTATION
```
(Decrypted keeps filler X’s from digraph formatting.)
