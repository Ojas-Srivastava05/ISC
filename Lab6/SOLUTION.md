# Lab Assignment 6 — Solution
**AI 331 | SVNIT Surat**

## Q1. One Time Pad
Key is a random string as long as the message. Each letter is added mod 26.

```
Encrypt: C = (P + K) mod 26
Decrypt: P = (C - K) mod 26
```

Example: `HELLO` with key `XMCKL` → `EQNVZ`

## Q2. Affine Cipher
```
Encrypt: C = (a*P + b) mod 26
Decrypt: P = a⁻¹ * (C - b) mod 26
```
`a` must be coprime with 26 (`gcd(a, 26) = 1`).

Example: `a = 5`, `b = 8`, `HELLO` → `RCLLA`

## Run
```bash
g++ -o otp_affine otp_affine.cpp
./otp_affine
```
