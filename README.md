# RSA Encryption and Decryption

This program implements RSA encryption and decryption in C++. It allows you to encrypt a message using a public key and decrypt the encrypted message using the corresponding private key.

## Prerequisites

- C++ Compiler (e.g., g++)
- Standard C++ Library

## Getting Started

1. Clone the repository or download the source code files.

2. Compile the C++ code using a C++ compiler. For example, using g++:
```bash
g++ main.cpp -o rsa
```
3. Run the executable file:
```bash
./rsa
```
## Usage

1. Enter the prime numbers `p` and `q` when prompted. These primes are used to generate the keys.

2. Enter the public key `e`. This key is used for encryption.

3. Enter the message to encrypt. The message should be a positive integer.

4. The program will output the encrypted message.

5. The program will automatically perform decryption using the generated private key and display the decrypted message.

## Example

Here's an example usage of the program:
```
Enter prime number p: 17
Enter prime number q: 11
Enter public key e: 7
Enter message to encrypt: 88

Encrypted message: 40
Decrypted message: 88

```


In this example, the prime numbers `p = 17` and `q = 11` are chosen, and the public key `e = 7` is used for encryption. The message `88` is encrypted to `40` and then decrypted back to `88` using the generated private key.

## Notes

- The prime numbers `p` and `q` should be distinct and prime for the RSA algorithm to work correctly.

- The public key `e` should be a positive integer greater than `1` and less than Euler's totient function `phi(n)`.

- The program performs basic input validation and checks for prime numbers, but it's always recommended to input valid and appropriate values.

