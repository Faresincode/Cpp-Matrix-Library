#pragma once
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;


class clsMatrix
{

private:

	short _Rows = 3;
	short _Cols = 3;
	int *_Matrix;
	
protected:

	static int RandomNumber(int From, int To)
	{
		 
		return rand() % (To - From + 1) + From;
	}

public:
	
	//default constructor
	clsMatrix()
	{
		_Rows = 0;
		_Cols = 0;
		_Matrix = nullptr;
	}

	//constructor
	clsMatrix(int *Matrix ,short Rows, short Cols)
	{
		_Rows = Rows;
		_Cols = Cols;
		_Matrix = new int [_Rows*_Cols];
		for (int i = 0; i < _Rows * _Cols; ++i)
			_Matrix[i] = Matrix[i];

	}

	// Copy constructor
	clsMatrix(const clsMatrix& other)
	{
		_Rows = other._Rows;
		_Cols = other._Cols;
		_Matrix = new int[_Rows * _Cols];
		for (int i = 0; i < _Rows * _Cols; i++)
			_Matrix[i] = other._Matrix[i];
	}

	//destructor
	~clsMatrix()
	{
		delete[] _Matrix;
		_Matrix = nullptr;
	}

	//========================== Set and Get Property =============================================

	void setRows(short Rows)
	{
		this->_Rows = Rows;
	}
	short getRows()
	{
		return this->_Rows;
	}
	__declspec(property(get = getRows, put = setRows))short MatrixRows;

	void setCols(short Cols)
	{
		this->_Cols = Cols;
	}
	short getCols()
	{
		return this->_Cols;
	}
	__declspec(property(get = getCols, put = setCols))short MatrixCols;

	void setMatrix(int* InputMatrix, short NewRows, short NewCols)
	{
		// If sizes are different, deallocate old memory
		if (NewRows != _Rows || NewCols != _Cols)
		{
			delete[] _Matrix;     // free old memory
			_Matrix = nullptr;    // avoid dangling pointer

			_Matrix = new int[NewRows * NewCols];  // allocate new 
		}
		//  Update size
		_Rows = NewRows;
		_Cols = NewCols;
		// Copy data from inputMatrix to internal matrix
		CopyMatrix(InputMatrix, _Matrix, _Rows, _Cols);
	}
	const int * getMatrix() const
	{
		return _Matrix;
	}
	//==============================================================================================
	static void FillMatrixWithRandomNumbers(int* arr, short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				arr[i * Cols + j] = RandomNumber(1, 100);
			}
		}
	}
	void FillMatrixWithRandomNumbers()
	{
		clsMatrix::FillMatrixWithRandomNumbers(_Matrix, _Rows, _Cols);
	}

	static void FillMatrixWithOrderedNumbers(int* arr, short Rows, short Cols)
	{
		short Counter = 0;
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				Counter++;
				arr[i * Cols + j] = Counter;
			}
		}
	}
	void FillMatrixWithOrderedNumbers()
	{
		clsMatrix::FillMatrixWithOrderedNumbers(_Matrix, _Rows, _Cols);
	}

	static void FillIdentityMatrix(int* Matrix1, short Rows, short Cols)
	{

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{

				if (i == j)
					Matrix1[i * Cols + j] = 1;
				else
					Matrix1[i * Cols + j] = 0;

			}
		}

	}
	void FillIdentityMatrix()
	{
		clsMatrix::FillIdentityMatrix(_Matrix, _Rows, _Cols);
	}
	//==============================================================================================

	static int SumRow(int* arr, short RowNumber, short Cols)
	{
		int Sum = 0;
		for (short j = 0; j < Cols; j++)
		{
			Sum += arr[RowNumber * Cols + j];
		}
		return Sum;
	}
	int SumRow(short RowNumber)
	{
		return clsMatrix::SumRow(_Matrix, RowNumber, _Cols);
	}

	static int SumCol(int* arr, short Rows,short Cols, short ColNumber)
	{
		int Sum = 0;
		for (short i = 0; i < Rows; i++)
		{
			Sum += arr[i*Cols+ColNumber];
		}
		return Sum;
	}
	int SumCol(short ColNumber)
	{
		return clsMatrix::SumCol(_Matrix, _Rows,_Cols, ColNumber);
	}

	static void SumMatrixRowsInArray(int* arr, int arrSum[], short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			arrSum[i] = SumRow(arr, i, Cols);
		}
	}
	void SumMatrixRowsInArray(int arrSum[])
	{
		clsMatrix::SumMatrixRowsInArray(_Matrix, arrSum,_Rows,_Cols);
	}

	static void SumMatrixColsInArray(int* arr, int arrSum[], short Rows, short Cols)
	{
		for (short j = 0; j < Cols; j++)
		{
			arrSum[j] = SumCol(arr, Rows,Cols, j);
		}
	}
	void SumMatrixColsInArray(int arrSum[])
	{
		clsMatrix::SumMatrixColsInArray(_Matrix, arrSum, _Rows,_Cols);
	}

	static int SumOfMatrix(int* Matrix, short Rows, short Cols)
	{
		int Sum = 0;
		for (short i = 0; i < Rows; i++)
			for (short j = 0; j < Cols; j++)
				Sum += Matrix[i * Cols + j];
		return Sum;
	}
	int SumOfMatrix()
	{
		return clsMatrix::SumOfMatrix(_Matrix, _Rows, _Cols);
	}

	static void CopyMatrix(int* Matrix, int* Matrix2, short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{

				Matrix2[i * Cols + j] = Matrix[i * Cols + j];

			}

		}

	}
	void CopyMatrix(int* MatrixToCopy)
	{
		clsMatrix::CopyMatrix(MatrixToCopy, _Matrix, _Rows, _Cols);
	}

	static void MultiplyMatrix(int* Matrix1, int* Matrix2, int* MatrixResult, short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
			for (short j = 0; j < Cols; j++)
				MatrixResult[i * Cols + j] = Matrix1[i * Cols + j] * Matrix2[i * Cols + j];
	}
	void MultiplyMatrix(int* MatrixToMultiplyWith, int* MatrixResult)
	{
		clsMatrix::MultiplyMatrix(_Matrix, MatrixToMultiplyWith, MatrixResult, _Rows, _Cols);
	}

	//==============================================================================================
	static int CountNumberFrequencyInMatrix(int* Matrix, short Rows, short Cols, int Number)
	{
		int Counter = 0;
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix[i * Cols + j] == Number)
				{
					Counter++;
				}
			}
		}

		return Counter;
	}
	int CountNumberFrequency(int Number)
	{
		return clsMatrix::CountNumberFrequencyInMatrix(_Matrix, _Rows, _Cols, Number);
	}

	static int MinNumberInMatrix(int* Matrix1, short Rows, short Cols)
	{
		int Min = Matrix1[0];
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix1[i * Cols + j] < Min)
				{
					Min = Matrix1[i * Cols + j];
				}
			}
		}

		return Min;

	}
	int MinNumberInMatrix()
	{
		return clsMatrix::MinNumberInMatrix(_Matrix, _Rows, _Cols);
	}

	static int MaxNumberInMatrix(int* Matrix1, short Rows, short Cols)
	{
		int Max = Matrix1[0];
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix1[i * Cols + j] > Max)
				{
					Max = Matrix1[i * Cols + j];
				}
			}
		}

		return Max;

	}
	int MaxNumberInMatrix()
	{
		return clsMatrix::MaxNumberInMatrix(_Matrix, _Rows, _Cols);
	}
	//===================================== Boolian Methodes ================================================
	static bool IsEqualSumOfMatrices(int* Matrix1, int* Matrix2, short Rows, short Cols)
	{
		return ((SumOfMatrix(Matrix1, Rows, Cols)) == (SumOfMatrix(Matrix2, Rows, Cols)));
	}
	bool IsEqualSumOfMatrices(int * Matrix2)
	{
		return clsMatrix::IsEqualSumOfMatrices(_Matrix, Matrix2, _Rows, _Cols);
	}

	static bool IsTypicalMatrices(int* Matrix1, int* Matrix2, short Rows, short Cols)
	{

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (Matrix1[i * Cols + j] != Matrix2[i * Cols + j])
				{
					return false;
				}
			}
		}
		return true;
	}
	bool IsTypicalMatrices(int *Matrix2)
	{
		return clsMatrix::IsTypicalMatrices(_Matrix,Matrix2,_Rows,_Cols);
	}

	static bool IsIdenticalMatrix(int* Matrix, short Rows, short Cols)
	{

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{

				if (i == j && Matrix[i * Cols + j] != 1)
					return false;
				if (i != j && Matrix[i * Cols + j] != 0)
					return false;

			}
		}

		return true;

	}
	bool IsIdenticalMatrix()
	{
		return  clsMatrix::IsIdenticalMatrix(_Matrix,_Rows,_Cols);
	}

	static bool IsScalarMatrix(int* Matrix, short Rows, short Cols)
	{
		int FirstDiagElement = Matrix[0];
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				//check for diagonals element
				if (i == j && Matrix[i * Cols + j] != FirstDiagElement)
				{
					return false;
				}
				//check for rest elements
				else if (i != j && Matrix[i * Cols + j] != 0)
				{
					return false;
				}
			}
		}

		return true;

	}
	bool IsScalarMatrix()
	{
		return clsMatrix::IsScalarMatrix(_Matrix, _Rows, _Cols);
	}

	static bool IsSparceMatrice(int *Matrix, short Rows, short Cols)
	{
		short MatrixSize = Rows * Cols;
		return (CountNumberFrequencyInMatrix(Matrix, Rows,  Cols,0) >= (MatrixSize / 2));
	}
	bool IsSparceMatrice()
	{
		return clsMatrix::IsSparceMatrice(_Matrix, _Rows, _Cols);
	}

	static bool IsNumberInMatrix(int *Matrix, int NumberToCheck, short Rows, short Cols)
	{

		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				if (NumberToCheck == Matrix[i * Cols + j])
				{
					return true;
				}
			}
		}

		return false;

	}
	bool IsNumberInMatrix(int NumberToCheck)
	{
		return clsMatrix::IsNumberInMatrix(_Matrix, NumberToCheck, _Rows, _Cols);
	}

	static bool IsPalindromMatrix(int* Matrix, short Row, short Cols)
	{


		for (short i = 0; i < Row; i++)
		{

			for (short j = 0; j < Cols / 2; j++)
			{
				if (Matrix[i * Cols + j] != Matrix[i * Cols + (Cols - 1 - j)])
				{
					return false;
				}

			}
		}

		return true;

	}
	bool IsPalindromMatrix()
	{
		return  clsMatrix::IsPalindromMatrix(_Matrix, _Rows, _Cols);
	}

	//================================ Print Methods ============================================
	static void PrintIntersectedNumbers(int *Matrix1, int* Matrix2, short Rows, short Cols)
	{
		int Number;
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				Number = Matrix1[i * Cols  + j];

				if (IsNumberInMatrix(Matrix2, Number, Rows, Cols))
				{
					cout << setw(3) << Matrix1[i * Cols + j] << "    ";
				}


			}
		}

	}

	static void PrintMiddleRowOfMatrix(int* Matrix, short Row, short Cols)
	{
		int MiddleRow = Row / 2;
		for (short j = 0; j < Cols; j++)
			printf(" %*d ", 2, Matrix[(MiddleRow * (Cols)) + j]);
		cout << "\n";
	}
	void PrintMiddleRow()
	{
		clsMatrix::PrintMiddleRowOfMatrix(_Matrix, _Rows, _Cols);
	}

	static void PrintMiddleColsOfMatrix(int* Matrix, short Row, short Cols)
	{
		int MiddelCols = Cols / 2;
		for (short i = 0; i < Row; i++)
			printf(" %*d ", 2, Matrix[i*Cols+MiddelCols]);
		cout << "\n";
	}
	void PrintMiddleCols()
	{
		clsMatrix::PrintMiddleColsOfMatrix(_Matrix, _Rows, _Cols);
	}

	static void PrintEachRowSum(int* arr, short Rows, short Cols)
	{
		cout << "\nThe the following are the sum of each row in the matrix:\n";
		for (short i = 0; i < Rows; i++)
		{
			cout << " Row " << i + 1 << " Sum = " << SumRow(arr, i, Cols) << endl;
		}
	}
	void PrintEachRowSum()
	{
		clsMatrix::PrintEachRowSum(_Matrix, _Rows, _Cols);
	}

	static void PrintEachColSum(int* arr, short Rows, short Cols)
	{
		cout << "\nThe the following are the sum of each col in the matrix:\n";
		for (short j = 0; j < Cols; j++)
		{
			cout << " Col " << j + 1 << " Sum = " <<
				SumCol(arr, Rows,Cols, j) << endl;
		}
	}
	void PrintEachColSum()
	{
		clsMatrix::PrintEachColSum(_Matrix, _Rows, _Cols);
	}

	void PrintMatrix(int *Matrix, short Rows, short Cols)
	{
		for (short i = 0; i < Rows; i++)
		{
			for (short j = 0; j < Cols; j++)
			{
				//printf(" %0*d ",2, arr[i][j]);
				cout << setw(5) << Matrix[i * Cols + j];
			}
			cout << "\n";
		}
	}
	void PrintMatrix()
	{
		clsMatrix::PrintMatrix(_Matrix, _Rows, _Cols);
	}
	//==============================================================================================




};

