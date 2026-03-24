# Secure Password Generator

A fast and cryptographically secure password generator written in **C++** using the libsodium library.

It generates high-entropy passwords suitable for any use case (accounts, encryption keys, API tokens, etc.). The tool also asks whether you want to save the generated password to a `passwords.json` file for easy management.

---

## Features

- **Cryptographically secure** random generation via libsodium (`randombytes_buf`)
- Customizable password length
- Includes uppercase, lowercase, numbers, and special characters by default
- Simple and clean command-line interface
- Optional saving of passwords to a JSON file
- Lightweight and fast (compiled binary)
- Cross-platform (Linux, macOS, Windows with minor adjustments)

---

## Quick Start

### Prerequisites

- **C++ compiler** (g++ or clang++)
- **libsodium** library installed
- **make** (optional but recommended)

### Installation

#### 1. Install libsodium

**Arch**
```bash
sudo pacman -Syu && sudo pacman -S libsodium
```

**Ubuntu / Debian:**
```bash
sudo apt update && sudo apt install libsodium-dev
```

**macOS**
```bash
brew install libsodium
```

Windows: Use vcpkg or download from the official libsodium site.

### Clone and build
```bash
git clone https://github.com/1-MarJr/secure-password-generator.git
cd secure-password-generator

# Build the project
make
```
This will produce an executable named password

### Usage
Run the generator
```bash
./password
```
The program will:

Ask for the desired password length (recommended: 16–32+)
Generate a strong random password
Display it
Ask if you want to save it to passwords.json

Example interaction:
```text
Enter password length: 20
Generated Password: X7#kP9$mQ2@vL8&nR3^t

Do you want to save this password? (y/n): y
Password saved to passwords.txt!
```

### Project Architecture
```text
secure-password-generator/
|---Makefile
|---README.md
|---passwords.txt  # This is used to store passwords
|---password.cpp   # Main source file
```

### Building the program manually
```bash
g++ -o password password.cpp -lsodium -std=c++17
```
