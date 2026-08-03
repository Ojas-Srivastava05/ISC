"""
Lab Assignment 2 — Caesar Cipher
Information Security and Cryptography (AI 331)
SVNIT Surat | 5th Sem B.Tech. (AI)

Encrypt and decrypt messages by shifting alphabetic characters.
Non-alphabetic characters (spaces, digits, punctuation) are left unchanged.
"""


def caesar_encrypt(plaintext: str, key: int) -> str:
    """Encrypt plaintext by shifting letters forward by `key` positions."""
    key = key % 26
    result = []

    for ch in plaintext:
        if ch.isupper():
            # A=0 ... Z=25
            shifted = (ord(ch) - ord("A") + key) % 26
            result.append(chr(shifted + ord("A")))
        elif ch.islower():
            shifted = (ord(ch) - ord("a") + key) % 26
            result.append(chr(shifted + ord("a")))
        else:
            result.append(ch)

    return "".join(result)


def caesar_decrypt(ciphertext: str, key: int) -> str:
    """Decrypt ciphertext by shifting letters backward by `key` positions."""
    return caesar_encrypt(ciphertext, -key)


def brute_force(ciphertext: str) -> None:
    """Try all 26 keys (useful demonstration of Caesar Cipher weakness)."""
    print("\n--- Brute-force attack (all possible keys) ---")
    for k in range(26):
        print(f"Key {k:2d}: {caesar_decrypt(ciphertext, k)}")


def main() -> None:
    print("=" * 50)
    print("  Caesar Cipher — Encrypt / Decrypt")
    print("=" * 50)

    while True:
        print("\nOptions:")
        print("  1. Encrypt a message")
        print("  2. Decrypt a message")
        print("  3. Encrypt then Decrypt (demo)")
        print("  4. Brute-force decrypt (show all keys)")
        print("  5. Exit")

        choice = input("\nEnter choice (1-5): ").strip()

        if choice == "5":
            print("Exiting. Goodbye!")
            break

        if choice not in {"1", "2", "3", "4"}:
            print("Invalid choice. Try again.")
            continue

        message = input("Enter the message: ")

        if choice == "4":
            brute_force(message)
            continue

        try:
            key = int(input("Enter the key (integer shift, e.g. 3): "))
        except ValueError:
            print("Key must be an integer.")
            continue

        if choice == "1":
            cipher = caesar_encrypt(message, key)
            print(f"\nPlaintext : {message}")
            print(f"Key       : {key}")
            print(f"Ciphertext: {cipher}")

        elif choice == "2":
            plain = caesar_decrypt(message, key)
            print(f"\nCiphertext: {message}")
            print(f"Key       : {key}")
            print(f"Plaintext : {plain}")

        elif choice == "3":
            cipher = caesar_encrypt(message, key)
            recovered = caesar_decrypt(cipher, key)
            print(f"\nOriginal  : {message}")
            print(f"Key       : {key}")
            print(f"Encrypted : {cipher}")
            print(f"Decrypted : {recovered}")
            print(f"Match?    : {message == recovered}")


if __name__ == "__main__":
    main()
