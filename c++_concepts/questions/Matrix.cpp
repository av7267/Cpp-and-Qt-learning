#include <iostream>

using namespace std;

template<typename T>
class Matrix{
    public:

    T* data;
    size_t rows;
    size_t cols;

    Matrix(size_t rows, size_t cols)
    {
        
        this -> rows = rows;
        this -> cols = cols;

        data = new T[rows * cols];
    }

    Matrix(const Matrix& other) //copy constructor
    {
        
        rows = other.rows;
        cols = other.cols;
        data = new T[rows * cols];

        for(int i=0;i<rows*cols;i++)
        {
            data[i] = other.data[i];
        }
    }

    Matrix& operator =(const Matrix& other)
    {
        if(this != &other)
        {
            delete[] data;
            
            rows = other.rows;
            cols = other.cols;

            data = new T[rows * cols];

            for(int i =0;i<rows;i++)
            {
                data[i] = other.data[i];
            }

        }
        return *this;
    }


    Matrix(Matrix&& other)
    {
        data = other.data;
        rows = other.rows;
        cols = other.cols;
        other.rows = 0;
        other.cols = 0;
        other.data = nullptr;
    }

    Matrix& operator =(Matrix&& other)
    {
        if(this != &other)
        {
            delete[] data;

            data = other.data;
            rows = other.rows;
            cols = other.cols;

            other.rows = 0;
            other.cols = 0;
            other.data = nullptr;
        }
        return *this;
    }

    T& operator()(size_t row, size_t col)
    {
        return data[row * cols + col];
    }


    const T& operator()(size_t row, size_t col) const
    {
        return data[row * cols + col];
    }


    friend ostream& operator<<(ostream& os, const Matrix<T>& matrix)
    {
        for (size_t i = 0; i < matrix.rows; i++)
        {
            for (size_t j = 0; j < matrix.cols; j++)
            {
                os << matrix.data[i * matrix.cols + j] << " ";
            }
            os << endl;
        }
        return os;
    }

    
    ~Matrix()
    {
        delete[] data;
    }

};


int main()
{
    Matrix<int> a(2, 3);

    a(0, 0) = 1;
    a(0, 1) = 2;
    a(0, 2) = 3;

    a(1, 0) = 4;
    a(1, 1) = 5;
    a(1, 2) = 6;

    cout << "Matrix A:" << endl;
    cout << a;

    cout << "Element: " << a(1, 2) << endl;

    //double matrix
    
    Matrix<double> numbers(2, 2);
    
    numbers(0, 0) = 1.5;
    numbers(0, 1) = 2.5;
    numbers(1, 0) = 3.5;
    numbers(1, 1) = 4.5;

    cout << "\nDouble Matrix:" << endl;
    cout << numbers;


}