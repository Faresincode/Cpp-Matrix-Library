# 🧮 Cpp-Matrix-Library
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
git clone https://github.com/yourusername/Cpp-Matrix-Library.git
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
#include "clsMatrix.h"

int main() {
    clsMatrix M1(3, 3);

    int counter = 1;
    for (int i = 0; i < M1.Rows(); i++) {
        for (int j = 0; j < M1.Cols(); j++) {
            M1.SetValue(i, j, counter++);
        }
    }

    std::cout << "Matrix M1:\n";
    M1.Print();

    std::cout << "Transpose:\n";
    clsMatrix T = M1.Transpose();
    T.Print();

    return 0;
}
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
