# Lab Assignment 2 — Solution
**Information Security and Cryptography (AI 331)**  
SVNIT Surat | 5th Sem B.Tech. (AI) | 2026–27

---

## Aim

Implement a **Caesar Cipher** to encrypt and decrypt messages by shifting characters.

---

## Theory

The Caesar Cipher is a classical substitution cipher attributed to Julius Caesar. Each letter in the plaintext is shifted by a fixed number of positions (the **key**) in the alphabet.

### Encryption

For a letter with position `P` (A=0, B=1, …, Z=25) and key `k`:

```
C = (P + k) mod 26
```

### Decryption

```
P = (C − k) mod 26
```

### Example (key = 3)

| Plaintext | H | E | L | L | O |
|-----------|---|---|---|---|---|
| Shift +3  | K | H | O | O | R |
| Ciphertext| K | H | O | O | R |

- Non-alphabetic characters (spaces, digits, punctuation) are left unchanged.
- Case is preserved (uppercase stays uppercase, lowercase stays lowercase).
- Only **25 useful keys** (1–25), so the cipher is trivial to break by brute force.

---

## Algorithm

### Encrypt
1. Read plaintext and key `k`.
2. For each character:
   - If letter: shift forward by `k` positions (wrap around using mod 26).
   - Else: keep as is.
3. Output ciphertext.

### Decrypt
1. Read ciphertext and key `k`.
2. Shift each letter **backward** by `k` (same as encrypt with `−k`).
3. Output plaintext.

---

## Implementation

File: `caesar_cipher.py`

### Core functions

```python
def caesar_encrypt(plaintext: str, key: int) -> str:
    key = key % 26
    result = []
    for ch in plaintext:
        if ch.isupper():
            shifted = (ord(ch) - ord("A") + key) % 26
            result.append(chr(shifted + ord("A")))
        elif ch.islower():
            shifted = (ord(ch) - ord("a") + key) % 26
            result.append(chr(shifted + ord("a")))
        else:
            result.append(ch)
    return "".join(result)


def caesar_decrypt(ciphertext: str, key: int) -> str:
    return caesar_encrypt(ciphertext, -key)
```

### How to run

```bash
python3 caesar_cipher.py
```

Menu options:
1. Encrypt a message  
2. Decrypt a message  
3. Encrypt then Decrypt (demo)  
4. Brute-force decrypt (all 26 keys)  
5. Exit  

---

## Sample Output

### Encrypt (key = 3)

```
Enter choice (1-5): 1
Enter the message: Hello SVNIT
Enter the key (integer shift, e.g. 3): 3

Plaintext : Hello SVNIT
Key       : 3
Ciphertext: Khoor VYQLW
```

### Decrypt (key = 3)

```
Enter choice (1-5): 2
Enter the message: Khoor VYQLW
Enter the key (integer shift, e.g. 3): 3

Ciphertext: Khoor VYQLW
Key       : 3
Plaintext : Hello SVNIT
```

### Round-trip demo

```
Enter choice (1-5): 3
Enter the message: Information Security
Enter the key (integer shift, e.g. 3): 5

Original  : Information Security
Key       : 5
Encrypted : Nsktwrfynts Xjhzwnyd
Decrypted : Information Security
Match?    : True
```

---

## Security Observation

Caesar Cipher is **insecure** for real use because:
- Key space is tiny (only 25 non-trivial keys).
- Frequency analysis easily recovers plaintext (e.g., ‘E’ is most common in English).
- Option 4 in the program demonstrates a full brute-force attack in seconds.

It remains useful for learning the concepts of **encryption, decryption, keys, and modular arithmetic**.

---

## Conclusion

A Caesar Cipher was implemented in Python to encrypt and decrypt messages using a shift key. The program demonstrates classical substitution cryptography, modular wrap-around of the alphabet, and why such ciphers are cryptographically weak today.
