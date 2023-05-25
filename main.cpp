#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the modular exponentiation
long long modPow(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exponent = exponent / 2;
    }

    return result;
}

// Function to check if a number is prime
bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to find the greatest common divisor using Euclid's algorithm
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    // Step 1: Choose two distinct prime numbers p and q
    int p, q;
    cout << "Enter prime number p: ";
    cin >> p;
    cout << "Enter prime number q: ";
    cin >> q;

    // Verify if p and q are prime numbers
    if (!isPrime(p) || !isPrime(q)) {
        cout << "p and q must be prime numbers." << endl;
        return 0;
    }

    // Step 2: Calculate n = p * q
    int n = p * q;

    // Step 3: Calculate Euler's totient function phi(n) = (p-1) * (q-1)
    int phi = (p - 1) * (q - 1);

    // Step 4: Choose an integer e such that 1 < e < phi and gcd(e, phi) = 1
    int e;
    cout << "Enter public key e: ";
    cin >> e;

    // Verify if e is valid
    if (e <= 1 || e >= phi || gcd(e, phi) != 1) {
        cout << "Invalid public key e." << endl;
        return 0;
    }

    // Step 5: Calculate the private key d such that (d * e) % phi = 1
    int d = 0;
    while ((d * e) % phi != 1) {
        d++;
    }

    // Step 6: Encryption
    long long message, encrypted;
    cout << "Enter message to encrypt: ";
    cin >> message;

    encrypted = modPow(message, e, n);
    cout << "Encrypted message: " << encrypted << endl;

    // Step 7: Decryption
    long long decrypted;
    decrypted = modPow(encrypted, d, n);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
