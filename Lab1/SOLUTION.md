# Lab Assignment 1 — Solution
**Information Security and Cryptography (AI 331)**  
SVNIT Surat | 5th Sem B.Tech. (AI) | 2026–27

---

## 1. Basics of Cryptography and How It Works

### 1.1 What is Cryptography?

**Cryptography** is the science of securing information by transforming readable data (**plaintext**) into an unreadable form (**ciphertext**) so that only authorized parties can recover the original message. It protects data in storage and in transit against eavesdropping, tampering, and impersonation.

Related terms:
| Term | Meaning |
|------|---------|
| **Plaintext** | Original readable message |
| **Ciphertext** | Encrypted (scrambled) message |
| **Encryption** | Plaintext → Ciphertext |
| **Decryption** | Ciphertext → Plaintext |
| **Key** | Secret value that controls encryption/decryption |
| **Cipher / Algorithm** | Mathematical procedure used to encrypt/decrypt |
| **Cryptanalysis** | Study of breaking cryptographic systems |

### 1.2 Goals of Cryptography

Cryptography supports the core security goals:
- **Confidentiality** — only intended recipients can read the data
- **Integrity** — data has not been altered
- **Authentication** — verify identity of sender / system
- **Non-repudiation** — sender cannot deny sending a message

### 1.3 How Cryptography Works (Basic Model)

```
Sender                          Receiver
  |                                |
  |  Plaintext (M)                 |
  |       |                        |
  |  Encryption E_k(M)             |
  |       |                        |
  |  Ciphertext (C)  ──────────►   |
  |       (over insecure channel)  |
  |                                |  Decryption D_k(C)
  |                                |       |
  |                                |  Plaintext (M)
```

1. Sender and receiver share (or agree on) a **key** `k`.
2. Sender applies encryption: `C = E_k(M)`.
3. Ciphertext `C` travels over an insecure channel (internet, wireless, etc.).
4. Receiver applies decryption: `M = D_k(C)`.
5. An attacker who intercepts `C` without `k` should not recover `M`.

### 1.4 Types of Cryptography

#### A. Symmetric-Key Cryptography (Secret Key)
- Same key is used for encryption and decryption.
- Fast and suitable for bulk data.
- Challenge: **secure key distribution**.
- Examples: AES, DES, 3DES, Blowfish, ChaCha20.
- Classic example: **Caesar Cipher** (shift cipher), Vigenère Cipher.

#### B. Asymmetric-Key Cryptography (Public Key)
- Uses a **key pair**: public key (shared) + private key (secret).
- Encrypt with public key → decrypt with private key (confidentiality).
- Sign with private key → verify with public key (authentication / non-repudiation).
- Slower than symmetric crypto; often used to exchange session keys.
- Examples: RSA, ECC, Diffie–Hellman, ElGamal.

#### C. Hash Functions
- One-way functions: fixed-size digest from arbitrary input.
- Used for integrity checks, password storage, digital signatures.
- Properties: pre-image resistance, second pre-image resistance, collision resistance.
- Examples: SHA-256, SHA-3, BLAKE2.

#### D. Digital Signatures & Certificates
- Combine hashing + public-key crypto to prove origin and integrity.
- PKI / certificates bind public keys to identities (e.g., HTTPS / TLS).

### 1.5 Classical vs Modern Cryptography

| Aspect | Classical | Modern |
|--------|-----------|--------|
| Security basis | Secrecy of algorithm | Secrecy of key (Kerckhoffs’ principle) |
| Computation | Manual / simple math | Complex math, computers |
| Examples | Caesar, Substitution, Playfair | AES, RSA, ECC |
| Key management | Simple shared secrets | Key exchange, PKI, protocols |

### 1.6 Simple Illustration — Caesar Cipher Idea

Shift each letter by a fixed amount (the key).  
Example with key = 3:

```
Plaintext:  H E L L O
Ciphertext: K H O O R
```

Encryption: `C = (P + k) mod 26`  
Decryption: `P = (C − k) mod 26`

This is insecure today (only 25 useful keys) but shows the encryption–decryption idea clearly.

### 1.7 Where Cryptography Is Used

- Secure messaging (WhatsApp end-to-end encryption)
- HTTPS / TLS for websites
- Disk / file encryption
- Digital signatures and e-governance
- Cryptocurrencies and blockchain
- VPNs, Wi-Fi (WPA2/WPA3), smart cards

---

## 2. CIA Triad and Relation to Cryptography

### 2.1 What is the CIA Triad?

The **CIA Triad** is the foundational model of information security. It has three pillars:

```
            Confidentiality
                 /\
                /  \
               /    \
              /      \
             /________\
    Integrity          Availability
```

#### 1. Confidentiality
- Information is accessible only to authorized users.
- Prevents unauthorized disclosure / eavesdropping.
- Threats: snooping, interception, social engineering, malware.

#### 2. Integrity
- Information remains accurate and unaltered (except by authorized parties).
- Detects unauthorized modification.
- Threats: tampering, man-in-the-middle, bit-flipping attacks.

#### 3. Availability
- Systems and data are accessible when needed by authorized users.
- Threats: DoS / DDoS, ransomware, hardware failure, power outage.

> Some models extend CIA with **Authenticity**, **Accountability**, and **Non-repudiation**.

### 2.2 How Cryptography Relates to Each CIA Element

| CIA Element | Role of Cryptography | Mechanisms |
|-------------|----------------------|------------|
| **Confidentiality** | Primary contribution — hide content from unauthorized parties | Encryption (AES, RSA), key management, secure channels (TLS) |
| **Integrity** | Detect unauthorized changes | Cryptographic hash functions (SHA-256), MACs (HMAC), digital signatures |
| **Availability** | Indirect — crypto alone does not guarantee uptime, but supports resilient secure systems | Secure authentication (prevent account takeover), integrity of backups, anti-tampering of configs; overuse of crypto can hurt availability if keys are lost |

### 2.3 Detailed Mapping

**Confidentiality ↔ Cryptography**
- Symmetric encryption keeps stored/transmitted data secret.
- Asymmetric encryption enables secure communication without pre-shared secrets.
- Without encryption, CIA’s “C” is hard to achieve on open networks.

**Integrity ↔ Cryptography**
- Hashing: any change in data changes the digest.
- MAC / HMAC: integrity + authenticity using a shared key.
- Digital signatures: integrity + non-repudiation using private keys.
- Encryption alone does **not** always guarantee integrity (ciphertext can be modified); integrity needs hashes/MACs/signatures.

**Availability ↔ Cryptography**
- Crypto protects credentials so attackers cannot lock out users as easily.
- Signed updates ensure only genuine software is installed (availability of trusted systems).
- Poor key management (lost keys) can make encrypted data permanently unavailable — so crypto must be designed carefully with backup/key escrow policies where appropriate.
- Availability is mainly achieved by redundancy, failover, DDoS mitigation, and backups — cryptography supports but does not replace these.

### 2.4 Example Scenario

**Online banking transaction**
1. **Confidentiality**: TLS encrypts account numbers and passwords in transit.
2. **Integrity**: HMAC / AEAD (e.g., AES-GCM) ensures the transfer amount is not altered mid-path.
3. **Availability**: Bank servers stay online (load balancing, backups); strong auth reduces takeover risk that could disrupt service.

### 2.5 Conclusion

- Cryptography is the main technical tool for **confidentiality** and a core tool for **integrity** (and authentication / non-repudiation).
- **Availability** depends more on system design, but cryptography still plays a supporting role.
- Effective information security needs cryptography **plus** policies, access control, monitoring, and resilient infrastructure — not encryption alone.

---

## References (for study)

1. Stallings, W. — *Cryptography and Network Security*
2. Forouzan, B. A. — *Cryptography and Network Security*
3. NIST / ISO standards on CIA and cryptographic mechanisms
4. Course notes — AI 331, SVNIT Surat
