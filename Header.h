//3
//Header
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;
template<class T>
class Vector
{
	T* vector = nullptr; int size = 0;
public:
	
	Vector();
	Vector(T _size);
	Vector(const Vector& _vector);
	~Vector();
	
	void Menu();
	void SetVector();
	void PrTVector();
	void AddSize(T add);
	void AddEnd();
	void AddStart();
	void AddNeedPosition(int NeedPosition);
	void DeleteStart();
	void DeleteEnd();
	void DeleteNeedPosition(int NeedPosition);
	void DeleteVector();
	T GetMaxElement();
	T GetMinElement();
	T SizeArray();
	T GetSearchIndexElement(int NeedPosition);
	void SetElement(int index, T element);
	void SortGrowth();
	void SortDecrease();
	void Reverse();
	void Left(T number);
	void Right(T number);
	
	bool operator==(const Vector<T>& vectot);
	bool operator!=(const Vector<T>& vectot);
	Vector operator+(const Vector<T>& vector);
	Vector& operator=(const Vector<T>& vector);
	Vector& operator+=(const Vector<T>& vector);
	Vector& operator-=(const Vector<T>& vector);
	T operator[](int index);
	void operator()(T increase);
	
	template<class T>
	friend ostream& operator<<(ostream& os, const Vector<T>& prT);
	template<class T>
	friend istream& operator>>(istream& is, Vector<T>& set);
};

template<class T>
class Matrix
{
	Vector<T>* matrix = nullptr;
	int rows, cols;
public:
	Matrix();
	Matrix(int rows, int cols);
	Matrix(const Matrix& copy);
	~Matrix();
	//
	void Menu();
	void Set();
	void PrT();
	void AddEndLine(Vector<T>&);
	void AddStartLine(Vector<T>&);
	void AddSpecifiedPosition(int, Vector<T>&);
	void AddFewLinesToThePosition(int, T, Vector<T>*&);
	void DeleteEndLine();
	void DeleteFirstLine();
	void DeleteMatrix();
	void DeleteSpecifiedPosition(int);
	void DeleteFewLinesFromSpecifiedPosition(int, T);
	void AddColumnEnd();
	void AddColumnStart();
	void AddColumnToTheSpecifiedPosition(int);
	void AddMultipleColumnSpecifiedPosition(int, T);
	void DeleteColumnEnd();
	void DeleteColumnStart();
	void DeleteColumnSpecifiedPosition(int);
	void DeleteMultipleColumnFromTheSpecifiedPosition(int, T);
	T SearchMaxElement(int);
	T SearchMinElement(int);
	T SearchMaxElementOfAllArray();
	T SearchMinElementOfAllArray();
	void SortsLineAtTheSpecifiedPositionForGrowth(int);
	void SortsLineAtTheSpecifiedPositionForDecrease(int);
	void SortAllLinesForGrowth();
	void SortAllLinesForDecrease();
	void ReverseAllLines();
	void ReverseAllColumn();
	void ExpandsArray(int, int);
	void TransposeTheMatrix();
	void Left(T);
	void Right(T);
	//
	bool operator==(const Matrix<T>& New);
	bool operator!=(const Matrix<T>& New);
	Matrix& operator+=(const Matrix<T>& New);
	Matrix& operator-=(const Matrix<T>& New);
	Matrix& operator++();
	Matrix& operator++(int);
	Matrix& operator--();
	Matrix& operator--(int);
	void operator~();
	Matrix& operator=(const Matrix<T>& copy);
	T operator()(int row, int col);
	//friend
	template<class T>
	friend T operator+(const Matrix<T>&, const Matrix<T>&);
	template<class T>
	friend T operator-(const Matrix<T>&, const Matrix<T>&);
	template<class T>
	friend ostream& operator << (ostream&, const Matrix<T>&);
	template<class T>
	friend istream& operator >> (istream&, Matrix<T>&);
};

template<class T>
void CreateVectorS(Vector<T>*&, int, int);
template<class T>
void SetVectorS(Vector<T>*&, int);