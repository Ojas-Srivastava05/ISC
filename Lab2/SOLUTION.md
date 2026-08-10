# Lab Assignment 2 — Solution
**AI 331 | SVNIT Surat**

## Aim
Caesar Cipher: shift letters by key `k`.

```
Encrypt: C = (P + k) mod 26
Decrypt: P = (C - k) mod 26
```

## Run
```bash
g++ -o caesar_cipher caesar_cipher.cpp
./caesar_cipher
```

## Example
```
Message: Hello SVNIT
Key: 3
Ciphertext: Khoor VYQLW
```
