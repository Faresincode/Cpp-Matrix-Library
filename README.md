# 🧮 Cpp Matrix Library
👉 A clean C++ Matrix class showcasing dynamic memory management and OOP best practices.

A clean and minimal **C++ Matrix Library** that demonstrates dynamic memory management, safe constructors/destructors, and OOP best practices.  
Perfect for learning, practicing, or using as a lightweight matrix utility in your projects.

---

## ✨ Features
- 📐 Create and resize matrices dynamically  
- 🎯 Safe memory management (RAII principles)  
- 🔄 Copy constructor (deep copy, no dangling pointers)  
- ➕ Matrix addition & multiplication  
- 🔃 Transpose operation  
- 🔢 Count frequency of numbers in a matrix  
- 🔍 Access & modify elements safely  
- 🖨️ Pretty-print matrices to console  

---

## 🚀 Getting Started

### 1. Clone the repository
```bash
git clone https://github.com/Faresincode/Cpp-Matrix-Library.git
cd Cpp-Matrix-Library
```
---

## 📂 Project Structure
```
Cpp-Matrix-Library/
│── clsMatrix.h       # Matrix class (header)
│── main.cpp          # Demo with all features
│── README.md         # This file
```

---

## 🧑‍💻 Example Usage
```cpp

#include <iostream>
#include "clsMatrix.h"
using namespace std;

int main()
{
    short Rows = 3, Cols = 3;

    // === Matrix 1 ===
    int values1[3][3] =
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Matrix M1:" << endl;
    clsMatrix::PrintMatrix(&values1[0][0], Rows, Cols);

    cout << "\nFrequency of 5 in M1: "
         << clsMatrix::CountNumberFrequencyInMatrix(&values1[0][0], Rows, Cols, 5)
         << endl;

    cout << "Frequency of 10 in M1: "
         << clsMatrix::CountNumberFrequencyInMatrix(&values1[0][0], Rows, Cols, 10)
         << endl;

    // === Matrix 2 ===
    int values2[3][3] =
    {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "\nMatrix M2:" << endl;
    clsMatrix::PrintMatrix(&values2[0][0], Rows, Cols);

    cout << "\nFrequency of 2 in M2: "
         << clsMatrix::CountNumberFrequencyInMatrix(&values2[0][0], Rows, Cols, 2)
         << endl;

    cout << "Frequency of 9 in M2: "
         << clsMatrix::CountNumberFrequencyInMatrix(&values2[0][0], Rows, Cols, 9)
         << endl;

    // === Matrix 3 (2x4) ===
    clsMatrix M3(2, 4);
    int values3[2][4] =
    {
        {11, 12, 13, 14},
        {21, 22, 23, 24}
    };

    cout << "\nMatrix M3 (2x4):" << endl;
    clsMatrix::PrintMatrix(&values3[0][0], 2, 4);

    cout << "\nFrequency of 23 in M3: "
         << clsMatrix::CountNumberFrequencyInMatrix(&values3[0][0], 2, 4, 23)
         << endl;

    cout << "Frequency of 100 in M3: "
         << clsMatrix::CountNumberFrequencyInMatrix(&values3[0][0], 2, 4, 100)
         << endl;

    // === Matrix 4 (4x4) ===
    clsMatrix M4(4, 4);
    int values4[4][4] =
    {
        {1, 1, 2, 2},
        {3, 3, 4, 4},
        {5, 5, 6, 6},
        {7, 7, 8, 8}
    };

    cout << "\nMatrix M4 (4x4):" << endl;
    clsMatrix::PrintMatrix(&values4[0][0], 4, 4);

    cout << "\nFrequency of 1 in M4: "
         << clsMatrix::CountNumberFrequencyInMatrix(&values4[0][0], 4, 4, 1)
         << endl;

    cout << "Frequency of 7 in M4: "
         << clsMatrix::CountNumberFrequencyInMatrix(&values4[0][0], 4, 4, 7)
         << endl;

    cout << "Frequency of 9 in M4: "
         << clsMatrix::CountNumberFrequencyInMatrix(&values4[0][0], 4, 4, 9)
         << endl;

    // === Matrix 5 (1x5) ===
    clsMatrix M5(1, 5);
    int values5[1][5] = { {42, 42, 42, 42, 42} };

    cout << "\nMatrix M5 (1x5):" << endl;
    clsMatrix::PrintMatrix(&values5[0][0], 1, 5);

    cout << "\nFrequency of 42 in M5: "
         << clsMatrix::CountNumberFrequencyInMatrix(&values5[0][0], 1, 5, 42)
         << endl;

    cout << "Frequency of 7 in M5: "
         << clsMatrix::CountNumberFrequencyInMatrix(&values5[0][0], 1, 5, 7)
         << endl;

    return 0;
}
```

---

## Example Console Output

```
Matrix M1:
    1    2    3
    4    5    6
    7    8    9

Frequency of 5 in M1: 1
Frequency of 10 in M1: 0

Matrix M2:
    9    8    7
    6    5    4
    3    2    1

Frequency of 2 in M2: 1
Frequency of 9 in M2: 1

Matrix M3 (2x4):
   11   12   13   14
   21   22   23   24

Frequency of 23 in M3: 1
Frequency of 100 in M3: 0

Matrix M4 (4x4):
    1    1    2    2
    3    3    4    4
    5    5    6    6
    7    7    8    8

Frequency of 1 in M4: 2
Frequency of 7 in M4: 2
Frequency of 9 in M4: 0

Matrix M5 (1x5):
   42   42   42   42   42

Frequency of 42 in M5: 5
Frequency of 7 in M5: 0
```

---

This demonstrates:
- Different matrix sizes (1x5, 2x4, 3x3, 4x4)
- Counting existing and non-existing values
- Printing cleanly formatted matrices
```

---

## 🎓 Why This Project?
This repository is designed for **students and C++ learners** who want to:
- Understand **dynamic memory** (`new`/`delete`) safely  
- Practice **constructors, destructors, and deep copy**  
- Get hands-on with **basic matrix operations**  

---

## 📜 License
This project is licensed under the **MIT License** – free to use, modify, and share.

---

🔥 **Cpp-Matrix-Library** = Learning + Practice + Clean Code!
