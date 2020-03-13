//Source
template<class T>
Vector<T>::Vector()
{
	vector = new T[0];
}
template<class T>
Vector<T>::Vector(T _size)
{
	this->size = _size;
	this->vector = new T[size] {0};
}
template<class T>
Vector<T>::Vector(const Vector& _Vector)
{
	this->size = _Vector.size;
	this->vector = new T[this->size];
	for (int i = 0; i < this->size; i++)
		this->vector[i] = _Vector.vector[i];
}
template<class T>
Vector<T>::~Vector()
{
	if (vector != nullptr)
	{
		delete[]this->vector;
		this->vector = nullptr;
	}
}
template<class T>
void Vector<T>::Menu()
{
	cout << "\n\n 0) Вихiд \n"
		" 1) Заповнює масив iз n елементiв випадковими числами : \n"
		" 2) Виводить масив на екран \n"
		" 3) Добавляє елемент вкiнець масиву \n"
		" 4) Добавляє елемент на початок масиву \n"
		" 5) Добавляє елемент в потрiбну позицiю \n"
		" 6) Видаляє з масиву перший елемент \n"
		" 7) Видаляє з масиву останнiй елемент \n"
		" 8) Видаляє елемент з потрiбної позицiї \n"
		" 9) Видаляє масив \n"
		" 10) Повертає максимальний елемент масиву \n"
		" 11) Повертає мiнiмальний елемент масиву \n"
		" 12) Повертає кiлькiсть елементiв масиву \n"
		" 13) Повертає елемент з потрiбним iндексом \n"
		" 14) Сортує масив по зростанню \n"
		" 15) Сортує масив по спаданню \n"
		" 16) Перевертає масив(reverse) \n"
		" 17) == \n"
		" 18) != \n"
		" 19) + \n"
		" 20) [] \n"
		" 21) () \n"
		" 22) left \n"
		" 23) right \n"
		" 24) cout<< \n"
		" 25) cin>> \n";
}
template<class T>
void Vector<T>::SetVector()
{
	for (int i = 0; i < size; i++)
		vector[i] = rand() % 10;
}
template<class T>
void Vector<T>::PrTVector()
{
	cout << "\n\n";
	for (int i = 0; i < size; i++)
		cout << setw(5) << vector[i];
	cout << "\n\n";
}
template<class T>
void Vector<T>::AddSize(T add)
{
	size += add;
}
template<class T>
void Vector<T>::AddEnd()
{
	size++;
	T* vector2 = new T[size];
	for (int i = 0; i < size; i++)
		vector2[i] = vector[i];
	vector2[size - 1] = rand() % 10;
	delete[]vector;
	vector = vector2;
}
template<class T>
void Vector<T>::AddStart()
{
	size++;
	T* vector2 = new T[size];
	for (int i = 0, j = 1; i < size; i++, j++)
		vector2[j] = vector[i];
	vector2[0] = rand() % 10;
	delete[]vector;
	vector = vector2;
}
template<class T>
void Vector<T>::AddNeedPosition(int NeedPosition)
{
	size++;
	T* vector2 = new T[size];
	for (int i = 0, j = 0; i < size; i++)
	{
		if (i != NeedPosition)
		{
			vector2[i] = vector[j];
			j++;
		}
		else
			vector2[i] = rand() % 10;
	}
	delete[]vector;
	vector = vector2;
}
template<class T>
void Vector<T>::DeleteStart()
{
	size--;
	T* vector2 = new T[size];
	for (int i = 1; i < size + 1; i++)
		vector2[i - 1] = vector[i];
	delete[]vector;
	vector = vector2;
}
template<class T>
void Vector<T>::DeleteEnd()
{
	size--;
	T* vector2 = new T[size];
	for (int i = 0; i < size; i++)
		vector2[i] = vector[i];
	delete[]vector;
	vector = vector2;
}
template<class T>
void Vector<T>::DeleteNeedPosition(int NeedPosition)
{
	size--;
	T* vector2 = new T[size];
	for (int i = 0, j = 0; i < size + 1; i++)
		if (i != NeedPosition)
		{
			vector2[j] = vector[i];
			j++;
		}
	delete[]vector;
	vector = vector2;
}
template<class T>
void Vector<T>::DeleteVector()
{
	size = 0;
	T* vector2 = new T[size];
	delete[]vector;
	vector = vector2;
}
template<class T>
T Vector<T>::GetMaxElement()
{
	T max = vector[0];
	for (int i = 0; i < size; i++)
		if (max < vector[i])
			max = vector[i];
	return max;
}
template<class T>
T Vector<T>::GetMinElement()
{
	T min = vector[0];
	for (int i = 0; i < size; i++)
		if (min > vector[0])
			min = vector[0];
	return min;
}
template<class T>
T Vector<T>::SizeArray()
{
	return size;
}
template<class T>
T Vector<T>::GetSearchIndexElement(int NeedPosition)
{
	return vector[NeedPosition];
}
template<class T>
void Vector<T>::SortGrowth()
{
	T swap;
	for (int i = 0; i < size; i++)
		for (int j = size - 1; j > 0; j--)
			if (vector[j] < vector[j - 1])
			{
				swap = vector[j];
				vector[j] = vector[j - 1];
				vector[j - 1] = swap;
			}
}
template<class T>
void Vector<T>::SortDecrease()
{
	T swap;
	for (int i = 0; i < size; i++)
		for (int j = size - 1; j > 0; j--)
			if (vector[j] > vector[j - 1])
			{
				swap = vector[j];
				vector[j] = vector[j - 1];
				vector[j - 1] = swap;
			}
}
template<class T>
void Vector<T>::Reverse()
{
	T* vector2 = new T[size];
	for (int i = 0, j = size - 1; i < size; i++, j--)
		vector2[i] = vector[j];
	delete[]vector;
	vector = vector2;
}
template<class T>
Vector<T> Vector<T>::operator+(const Vector& vector)
{
	Vector NewVector(5);
	for (int i = 0; i < this->size; i++)
		NewVector.vector[i] = (this->vector[i]) + (vector.vector[i]);
	return NewVector;
}
template<class T>
Vector<T>& Vector<T>::operator=(const Vector& vector)
{
	if (this->vector != nullptr)
	{
		delete[]this->vector;
		this->vector = nullptr;
	}
	size = vector.size;
	this->vector = new T[size];
	for (int i = 0; i < size; i++)
		this->vector[i] = vector.vector[i];
	return *this;
}
template<class T>
T Vector<T>::operator[](int index)
{
	return vector[index];
}
template<class T>
void Vector<T>::operator()(T increase)
{
	for (int i = 0; i < size; i++)
		vector[i] += increase;
}

template<class T>
void Vector<T>::Left(T number)
{
	for (int i = 0; i < number; i++)
	{
		T* arr2 = new T[size];
		arr2[0] = this->vector[size - 1];
		for (int i = 1, j = 0; i < size; i++, j++)
			arr2[i] = this->vector[j];
		delete[] this->vector;
		this->vector = arr2;
	}
}
template<class T>
void Vector<T>::Right(T number)
{
	for (int i = 0; i < number; i++)
	{
		T* arr2 = new T[size];
		arr2[size - 1] = this->vector[0];
		for (int i = 0, j = 1; j < size; i++, j++)
			arr2[i] = this->vector[j];
		delete[] this->vector;
		this->vector = arr2;
	}
}

template<class T>
bool Vector<T>::operator==(const Vector& NewVector)
{
	T count = 0;
	for (int i = 0; i < size; i++)
		if (this->vector[i] != NewVector.vector[i])
			count++;
	if (count == 0)
		return 1;
	return 0;
}
template<class T>
bool Vector<T>::operator!=(const Vector& NewVector)
{
	T count = 0;
	for (int i = 0; i < size; i++)
		if (this->vector[i] == NewVector.vector[i])
			count++;
	if (count != size)
		return 1;
	return 0;
}
template<class T>
Vector<T>& Vector<T>::operator+=(const Vector& vector)
{

	T* NewVector = new T[this->size + vector.size];

	for (int i = 0; i < this->size; i++)
		NewVector[i] = this->vector[i];
	for (int i = this->size, j = 0; i < this->size + vector.size; i++, j++)
		NewVector[i] = vector.vector[j];

	this->~Vector();

	this->size += vector.size;
	this->vector = NewVector;
	return *this;
}
template<class T>
Vector<T>& Vector<T>::operator-=(const Vector& vector)
{
	for (int i = 0; i < size; i++)
		this->vector[i] -= vector.vector[i];
	return *this;
}
template<class T>
ostream& operator<<(ostream& os, const Vector<T>& prT)
{
	cout << "\n\n\n";
	for (int i = 0; i < prT.size; i++)
		cout << setw(3) << prT.vector[i];
	cout << "\n\n\n";
	return os;
}
template<class T>
istream& operator>>(istream& is, Vector<T>& set)
{
	for (int i = 0; i < set.size; i++)
		cin >> set.vector[i];
	return is;
}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
template<class T>
void Matrix<T>::Menu()
{
	cout << "\n 0) Exit \n"
		" 1) Set \n"
		" 2) PrT \n"
		" 3) Add the row to the end \n"
		" 4) Add the row to the start \n"
		" 5) Adds a row to the specified position \n"
		" 6) Add multiple rows to the desired position \n"
		" 7) Delete the line from the end \n"
		" 8) Delete first line \n"
		" 9) Remove matrix \n"
		" 10) Delete row from specified position \n"
		" 11) Delete a few lines starting from the specified position \n"
		" 12) Add a column to the end \n"
		" 13) Add column to the top \n"
		" 14) Add a column to the specified position \n"
		" 15) Add multiple columns starting from the specified position \n"
		" 16) Remove the column from the end \n"
		" 17) Remove the column from the beginning \n"
		" 18) Remove the column from the specified position \n"
		" 19) Delete multiple columns starting from the specified position \n"
		" 20) Search for the maximal element of the specified string \n"
		" 21) Search for the minimum element of the specified string \n"
		" 22) Search for the maximum element of an entire array \n"
		" 23) Find the minimal element of the whole array \n"
		" 24) Sorts the line at the specified position for growth \n"
		" 25) Sorts the line at the specified position by decrease \n"
		" 26) Sorts each row of the array for growth \n"
		" 27) Sorts each row of the array by decrease \n"
		" 28) Turns each row in reverse \n"
		" 29) Turns each column backwards \n"
		" 30) Expands the array to the specified number of rows and columns \n"
		" 31) Transpose the matrix \n"
		" 32) Performs a cyclic shift of the array to the specified number of positions to the left \n"
		" 33) Performs a cyclic shift of the array to the specified number of positions to the right \n"
		;
}
template<class T>
Matrix<T>::Matrix()
{
	matrix = new Vector<T>[0];
	rows = cols = 0;
}
template<class T>
Matrix<T>::Matrix(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;

	this->matrix = new Vector<T>[rows];
	for (int i = 0; i < rows; i++)
		this->matrix[i].Vector::Vector(cols);
}
template<class T>
Matrix<T>::Matrix(const Matrix& copy)
{
	this->rows = copy.rows;
	this->cols = copy.cols;
	this->matrix = new Vector[rows];

	for (int i = 0; i < rows; i++)
		this->matrix[i] = copy.matrix[i];
}
template<class T>
Matrix<T>::~Matrix()
{
	if (this->matrix != nullptr)
	{
		delete[]this->matrix;
		this->matrix = nullptr;
	}
}
//
template<class T>
void Matrix<T>::Set()
{
	for (int i = 0; i < rows; i++)
		this->matrix[i].SetVector();
}
template<class T>
void Matrix<T>::PrT()
{
	for (int i = 0; i < rows; i++)
		this->matrix[i].PrTVector();
}
template<class T>
void Matrix<T>::AddEndLine(Vector<T>& v)
{
	Vector<T>* tmp = new Vector<T>[this->rows + 1];
	for (int i = 0; i < rows; i++)
		tmp[i] = this->matrix[i];

	tmp[rows] = v;

	delete[] this->matrix;

	this->matrix = tmp;
	rows++;
}
template<class T>
void Matrix<T>::AddStartLine(Vector<T>& v)
{
	Vector<T>* NewMatrix = new Vector<T>[rows + 1];

	for (int i = 1; i < rows + 1; i++)
		NewMatrix[i] = this->matrix[i - 1];

	NewMatrix[0] = v;

	this->~Matrix();

	this->matrix = NewMatrix;
	rows++;
}
template<class T>
void Matrix<T>::AddSpecifiedPosition(int position, Vector<T>& v)
{
	Vector<T>* NewMatrix = new Vector<T>[rows + 1];

	for (int i = 0, j = 0; i < rows + 1; i++)
		if (i != position)
		{
			NewMatrix[i] = this->matrix[j];
			j++;
		}

	NewMatrix[position] = v;

	this->~Matrix();

	this->matrix = NewMatrix;
	rows++;
}
template<class T>
void Matrix<T>::AddFewLinesToThePosition(int position, T number, Vector<T>*& lines)
{
	Vector<T>* NewMatrix = new Vector<T>[rows + number];

	for (int i = 0, j = 0; i < rows + number; i++)
	{

		if (i != position)
		{
			NewMatrix[i] = this->matrix[j];
			j++;
		}
		else
		{
			for (int x = 0; x < number; x++, i++)
				NewMatrix[i] = lines[x];
			i--;
		}
	}

	this->~Matrix();

	this->matrix = NewMatrix;
	rows += number;
}
template<class T>
void Matrix<T>::DeleteEndLine()
{
	Vector<T>* NewMatrix = new Vector<T>[rows - 1];

	for (int i = 0; i < rows - 1; i++)
		NewMatrix[i] = this->matrix[i];

	this->~Matrix();

	this->matrix = NewMatrix;
	rows--;
}
template<class T>
void Matrix<T>::DeleteFirstLine()
{
	Vector<T>* NewMatrix = new Vector<T>[rows - 1];

	for (int i = 1, j = 0; i < rows; i++, j++)
		NewMatrix[j] = this->matrix[i];

	this->~Matrix();

	this->matrix = NewMatrix;
	rows--;
}
template<class T>
void Matrix<T>::DeleteMatrix()
{
	this->~Matrix();
	rows = cols = 0;
}
template<class T>
void Matrix<T>::DeleteSpecifiedPosition(int position)
{
	Vector<T>* NewMatrix = new Vector<T>[rows - 1];

	for (int i = 0, j = 0; i < rows; i++)
		if (i != position)
		{
			NewMatrix[j] = this->matrix[i];
			j++;
		}

	this->~Matrix();

	this->matrix = NewMatrix;
	rows--;
}
template<class T>
void Matrix<T>::DeleteFewLinesFromSpecifiedPosition(int position, T number)
{
	Vector<T>* NewMatrix = new Vector<T>[rows - number];

	for (int i = 0, j = 0; i < rows; i++)
	{
		if (i != position)
		{
			NewMatrix[j] = this->matrix[i];
			j++;
		}
		else
		{
			for (int x = 0; x < number; x++, i++);
			i--;
		}
	}

	this->~Matrix();

	this->matrix = NewMatrix;
	rows -= number;
}
template<class T>
void Matrix<T>::AddColumnEnd()
{
	for (int i = 0; i < rows; i++)
		this->matrix[i].AddEnd();
	cols++;
}
template<class T>
void Matrix<T>::AddColumnStart()
{
	for (int i = 0; i < rows; i++)
		this->matrix[i].AddStart();
	cols++;
}
template<class T>
void Matrix<T>::AddColumnToTheSpecifiedPosition(int position)
{
	for (int i = 0; i < rows; i++)
		this->matrix[i].AddNeedPosition(position);
	cols++;
}
template<class T>
void Matrix<T>::AddMultipleColumnSpecifiedPosition(int position, T number)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < number; j++)
			this->matrix[i].AddNeedPosition(position + j);
	cols += number;
}
template<class T>
void Matrix<T>::DeleteColumnEnd()
{
	for (int i = 0; i < rows; i++)
		this->matrix[i].DeleteEnd();
	cols--;
}
template<class T>
void Matrix<T>::DeleteColumnStart()
{
	for (int i = 0; i < rows; i++)
		this->matrix[i].DeleteStart();
	cols--;
}
template<class T>
void Matrix<T>::DeleteColumnSpecifiedPosition(int position)
{
	for (int i = 0; i < rows; i++)
		this->matrix[i].DeleteNeedPosition(position);
	cols--;
}
template<class T>
void Matrix<T>::DeleteMultipleColumnFromTheSpecifiedPosition(int position, T number)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < number; j++)
			this->matrix[i].DeleteNeedPosition(position + j);
	cols -= number;
}
template<class T>
T Matrix<T>::SearchMaxElement(int index)
{
	return this->matrix[index].GetMaxElement();
}
template<class T>
T Matrix<T>::SearchMinElement(int index)
{
	return this->matrix[index].GetMinElement();
}
template<class T>
T Matrix<T>::SearchMaxElementOfAllArray()
{
	T max = this->matrix[0].GetMaxElement();

	for (int i = 0; i < rows; i++)
		if (this->matrix[i].GetMaxElement() > max)
			max = this->matrix[i].GetMaxElement();
	return max;
}
template<class T>
T Matrix<T>::SearchMinElementOfAllArray()
{
	T min = this->matrix[0].GetMinElement();

	for (int i = 0; i < rows; i++)
		if (this->matrix[i].GetMinElement() < min)
			min = this->matrix[i].GetMinElement();
	return min;
}
template<class T>
void Matrix<T>::SortsLineAtTheSpecifiedPositionForGrowth(int position)
{
	this->matrix[position].SortGrowth();
}
template<class T>
void Matrix<T>::SortsLineAtTheSpecifiedPositionForDecrease(int position)
{
	this->matrix[position].SortDecrease();
}
template<class T>
void Matrix<T>::SortAllLinesForGrowth()
{
	for (int i = 0; i < rows; i++)
		this->matrix[i].SortGrowth();
}
template<class T>
void Matrix<T>::SortAllLinesForDecrease()
{
	for (int i = 0; i < rows; i++)
		this->matrix[i].SortDecrease();
}
template<class T>
void Matrix<T>::ReverseAllLines()
{
	for (int i = 0; i < rows; i++)
		this->matrix[i].Reverse();
}
template<class T>
void Matrix<T>::ReverseAllColumn()
{
	Vector<T>* NewMatrix = new Vector<T>[rows];

	for (int i = rows - 1, j = 0; i >= 0; i--, j++)
		NewMatrix[j] = this->matrix[i];

	this->~Matrix();

	this->matrix = NewMatrix;
}
template<class T>
void Matrix<T>::ExpandsArray(int add_rows, int add_cols)
{
	Vector<T> vect(cols);

	for (int i = 0; i < add_rows; i++)
	{
		vect.SetVector();
		this->AddEndLine(vect);
	}

	for (int j = 0; j < rows; j++)
		for (int i = 0; i < add_cols; i++)
			this->matrix[j].AddEnd();

	this->cols += add_cols;
}

template<class T>
void Matrix<T>::TransposeTheMatrix()
{
	Vector<T>* NewMatrix;
	CreateVectorS(NewMatrix, cols, rows);

	for (int i = 0; i < cols; i++)
		for (int j = 0; j < rows; j++)
			NewMatrix[i].SetElement(j, this->matrix[j][i]);

	this-> ~Matrix();

	this->matrix = NewMatrix;
}
template<class T>
void Matrix<T>::Left(T number)
{
	for (int i = 0; i < rows; i++)
		this->matrix[i].Left(number);
}
template<class T>
void Matrix<T>::Right(T number)
{
	for (int i = 0; i < rows; i++)
		this->matrix[i].Right(number);
}
//
template<class T>
bool Matrix<T>::operator==(const Matrix<T>& New)
{
	for (int i = 0; i < rows; i++)
		if (New.matrix[i] != this->matrix[i])
			return 0;
	return 1;
}
template<class T>
bool Matrix<T>::operator!=(const Matrix<T>& New)
{
	int count = 0;
	for (int i = 0; i < rows; i++)
		if (New.matrix[i] == this->matrix[i])
			count++;

	if (count == New.rows)
		return 0;
	return 1;
}
template<class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix<T>& New)
{
	for (int i = 0; i < rows; i++)
		this->matrix[i] += New.matrix[i];
	return *this;
}
template<class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix<T>& New)
{
	for (int i = 0; i < rows; i++)
		this->matrix[i] -= New.matrix[i];
	return *this;
}
template<class T>
Matrix<T>& Matrix<T>::operator++()
{
	Vector<T> NewVector(cols);
	NewVector.SetVector();

	this->AddStartLine(NewVector);

	return *this;
}
template<class T>
Matrix<T>& Matrix<T>::operator++(int)
{
	Matrix<T> NewMatrix;
	Vector<T> NewVector(cols);

	NewVector.SetVector();
	NewMatrix = *this;

	this->AddEndLine(NewVector);

	return NewMatrix;
}
template<class T>
Matrix<T>& Matrix<T>::operator--()
{
	this->DeleteFirstLine();

	return *this;
}
template<class T>
Matrix<T>& Matrix<T>::operator--(int)
{
	Matrix<T> NewMatrix;
	NewMatrix = *this;

	this->DeleteEndLine();
	return NewMatrix;
}
template<class T>
void Matrix<T>::operator~()
{
	this->TransposeTheMatrix();
}
template<class T>
T operator+(const Matrix<T>& m1, const Matrix<T>& m2)
{
	T sum = 0;

	for (int i = 0; i < m1.rows; i++)
		for (int j = 0; j < m1.cols; j++)
			sum += m1.matrix[i].GetSearchIndexElement(j);

	for (int i = 0; i < m2.rows; i++)
		for (int j = 0; j < m2.cols; j++)
			sum += m2.matrix[i].GetSearchIndexElement(j);

	return sum;
}
template<class T>
T operator-(const Matrix<T>& m1, const Matrix<T>& m2)
{
	T difference_1 = 0, difference_2 = 0;

	for (int i = 0; i < m1.rows; i++)
		for (int j = 0; j < m1.cols; j++)
			difference_1 += m1.matrix[i].GetSearchIndexElement(j);

	for (int i = 0; i < m2.rows; i++)
		for (int j = 0; j < m2.cols; j++)
			difference_2 += m2.matrix[i].GetSearchIndexElement(j);

	return difference_1 - difference_2;
}
template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& copy)
{
	if (this == &copy)
		return *this;

	this->~Matrix();

	this->rows = copy.rows;
	this->cols = copy.cols;

	this->matrix = new Vector[this->rows];
	for (int i = 0; i < this->rows; i++)
		this->matrix[i].Vector::Vector(this->cols);

	for (int i = 0; i < this->rows; i++)
		this->matrix[i] = copy.matrix[i];

	return *this;
}
template<class T>
T Matrix<T>::operator()(int row, int col)
{
	return this->matrix[row].GetSearchIndexElement(col);
}
//
template<class T>
void Vector<T>::SetElement(int index, T element)
{
	this->vector[index] = element;
}
template<class T>
ostream& operator << (ostream& os, const Matrix<T>& prT)
{
	cout << "\n\n\n";
	for (int i = 0; i < prT.rows; i++)
		prT.matrix[i].PrTVector();
	cout << "\n\n\n";
	return os;
}
template<class T>
istream& operator >> (istream& is, Matrix<T>& set)
{
	T element;

	for (int i = 0; i < set.rows; i++)
		for (int j = 0; j < set.cols; j++)
		{
			cin >> element;
			set.matrix[i].SetElement(j, element);
		}

	return is;
}
template<class T>
void CreateVectorS(Vector<T>*& vect, int size, int cols)
{
	vect = new Vector<T>[size];
	for (int i = 0; i < size; i++)
		vect[i].Vector::Vector(cols);
}
template<class T>
void SetVectorS(Vector<T>*& vect, int size)
{
	for (int i = 0; i < size; i++)
		vect[i].SetVector();
}