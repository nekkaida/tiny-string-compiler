# String Processing Toy Compiler

This project implements a simple **toy compiler** using **Lex** and **Yacc** (Flex and Bison) for processing string operations. The compiler supports various string manipulations such as concatenation, substring extraction, length calculation, reversing strings, and palindrome checking.

---

## **Table of Contents**

- [Features](#features)
- [Supported Operations](#supported-operations)
- [Installation](#installation)
- [How to Use](#how-to-use)
- [Examples](#examples)
- [Project Structure](#project-structure)
- [Future Enhancements](#future-enhancements)
- [Acknowledgments](#acknowledgments)

---

## **Features**

- A toy compiler designed to demonstrate the basics of lexical analysis and parsing.
- Implements string operations and stores results in a symbol table.
- Written using **Flex (Lex)** for lexical analysis and **Bison (Yacc)** for parsing.
- Provides meaningful error handling for invalid syntax or operations.
- Dynamic memory management to handle strings efficiently.

---

## **Supported Operations**

| **Operation**         | **Syntax**                        | **Description**                                                  |
|------------------------|------------------------------------|------------------------------------------------------------------|
| String Concatenation   | `s3 = s1 + s2;`                   | Concatenates `s1` and `s2`.                                      |
| Length Calculation     | `len = length(s1);`              | Returns the length of `s1`.                                      |
| String Reversal        | `rev = reverse(s1);`             | Reverses the string `s1`.                                        |
| Palindrome Checking    | `is_pal = palindrome(s1);`       | Checks if `s1` is a palindrome (`true` or `false`).              |
| Substring Extraction   | `sub = substring(s1, 0, 5);`     | Extracts a substring from `s1` starting at index `0` to `5`.     |

---

## **Installation**

### **Prerequisites**
Ensure the following tools are installed on your system:

- **Flex** (Lexical Analyzer)
- **Bison** (Parser Generator)
- **GCC** (C Compiler)

### **Setup**

1. Clone the repository or download the files:
   ```bash
   git clone https://github.com/your-repo/string-processing-compiler.git
   cd string-processing-compiler
