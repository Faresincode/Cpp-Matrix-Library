#include <iostream>
#include "clsMatrix.h"

using namespace std;

int main() {
    cout << "=== Cpp-Matrix-Library Demo ===\n\n";

    // 1. Create a 3x3 matrix
    clsMatrix M1(3, 3);
    cout << "Created a 3x3 matrix (M1):\n";
    M1.Print();

    // 2. Fill matrix with values
    cout << "\nFilling M1 with values...\n";
    int counter = 1;
    for (int i = 0; i < M1.Rows(); i++) 
    {
        for (int j = 0; j < M1.Cols(); j++) {
            M1.SetValue(i, j, counter++);
        }
    }
    M1.Print();

    // 3. Access single element
    cout << "\nM1[1][2] = " << M1.GetValue(1, 2) << "\n";

    // 4. Copy constructor demo
    cout << "\nCreating M2 as a copy of M1...\n";
    clsMatrix M2 = M1;
    M2.Print();

    // 5. Modify M2 and prove deep copy
    M2.SetValue(0, 0, 999);
    cout << "\nM2 after modifying (0,0) = 999:\n";
    M2.Print();
    cout << "\nM1 remains unchanged:\n";
    M1.Print();

    // 6. Resize M1
    cout << "\nResizing M1 to 2x4...\n";
    M1.Resize(2, 4);
    int value = 10;
    for (int i = 0; i < M1.Rows(); i++) 
    {
        for (int j = 0; j < M1.Cols(); j++) {
            M1.SetValue(i, j, value++);
        }
    }
    M1.Print();

    // 7. Count frequency of a number
    cout << "\nCount of 12 in M1: "
        << clsMatrix::CountNumberFrequencyInMatrix(M1.Raw(), M1.Rows(), M1.Cols(), 12) << "\n";

    // 8. Sum of all elements
    cout << "Sum of elements in M1 = " << M1.Sum() << "\n";

    // 9. Transpose example
    cout << "\nTranspose of M1:\n";
    clsMatrix M3 = M1.Transpose();
    M3.Print();

    // 10. Add two matrices (M1 + M3)
    cout << "\nM1 + M3:\n";
    clsMatrix M4 = M1.Add(M3);
    M4.Print();

    // 11. Multiply two matrices
    cout << "\nMultiplying M1 * M3:\n";
    clsMatrix M5 = M1.Multiply(M3);
    M5.Print();

    cout << "\n=== End of Demo ===\n";


    return 0;

}


