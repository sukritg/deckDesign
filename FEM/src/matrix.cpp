
#include "matrix.h"

matrix::matrix()
{
    data = nullptr;
    rows = 0;
    cols = 0;
    name = " ";
}


matrix::matrix(int _rows, int _cols)
{
    data = nullptr;
    setSize(_rows,_cols);
    name = " ";
}


matrix::matrix(int _rows, int _cols, std::string _name)
{
    data = nullptr;
    name = _name;
    setSize(_rows,_cols);
}

matrix::matrix(const matrix &mat)
{
    data = nullptr;
    name = mat.getName();
    setSize(mat.rowSize(),mat.colSize());
    for (int i=0; i < rows; i++)
    {
        for (int j=0; j < cols; j++)
        {
            data[i][j] = mat(i+1,j+1);
        }
    }

}

void matrix::errorHandler(int _errorCode)
{
    std::cout << "Error in Matrix : " << name << std::endl;
    switch (_errorCode)
    {
        case 1: {std::cout << "Invalid row or column size" << std::endl;break;}
        case 2: {std::cout << "Self assignment of matrix detected" << std::endl; break;}
        case 3: {std::cout << "Please initialize the size of the matrix before setting the value" << std::endl; break;}
    }

}

void matrix::errorHandler(int _errorCode) const
{
    std::cout << "Error in Matrix : " << name << std::endl;
    switch (_errorCode)
    {
        case 1: {std::cout << "Invalid row or column size" << std::endl;break;}
        case 2: {std::cout << "Self assignment of matrix detected" << std::endl; break;}
        case 3: {std::cout << "Please initialize the size of the matrix before setting the value" << std::endl; break;}
        case 4: {std::cout << "Dimensions does not look okay for product of matrices" << std::endl; break;}

    }

}



matrix::~matrix()
{
    delete[] data;
}



void matrix::setSize(int _rows, int _cols)
{
    if (data != nullptr)
    {
        delete[] data;
    }

    if (_rows <= 0 || _cols <= 0)
        {errorHandler(1); return;}
    else
    {
        rows = _rows;
        cols = _cols;
        data = new double *[rows];
        for (int i=0; i<rows; i++)
            data[i] = new double[cols];
    }
    setValue(0);
}

int matrix::rowSize() const
{
    return rows;
}
int matrix::colSize() const
{
    return cols;
}

 std::string matrix::getName() const
 {
     return name;
 }
void matrix::setValue(double _value)
{
     if (data == nullptr)
    {
        errorHandler(3); return;
    }
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            data[i][j] = _value;
        }
    }
}

matrix & matrix::operator= (const matrix &rhs)
 {

     // check for self-assignment
     if (this == &rhs)
        {
            errorHandler(2); return *this;
        }
    // deallocate memory
        if (data != nullptr) {delete[] data;}
    // allocate memory
        name = rhs.getName();
        setSize(rhs.rowSize(),rhs.colSize());
    // copy value from rhs
        for (int i=0; i<rows; i++)
        {
            for( int j=0; j<cols; j++)
            {
                data[i][j] = rhs.data[i][j];
            }
        }
        return *this;
 }




 bool matrix::isEmpty()
 {
     if (data == nullptr) return true;
     else return false;
 }

 bool matrix::isEmpty() const
 {
     if (data == nullptr) return true;
     else return false;
 }

 void matrix::setName(std::string _name)
 {
     name = _name;
 }

//Operators

double & matrix::operator() (int _row, int _col)
{
    if (_row <= 0 || _col <= 0 || _row > rows || _col > cols)
        {errorHandler(1); return data[0][0];}
    else
        {
            return data[_row-1][_col-1];
        }
}


double & matrix::operator() (int _row, int _col) const
{
    if (_row <= 0 || _col <= 0 || _row > rows || _col > cols)
        {errorHandler(1); return data[0][0];}
    else
        {
            return data[_row-1][_col-1];
        }
}

// Addition

matrix matrix::operator+ (const matrix &rhs)
{
    //check
    if (rhs.rowSize() == rows && rhs.colSize() == cols)
    {
        matrix temp(rows,cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp(i+1,j+1) = rhs(i+1,j+1) + data[i][j];
            }
        }
    return temp;
    }

}

// Subtraction

matrix matrix::operator- (const matrix &rhs)
{
    //check
    if (rhs.rowSize() == rows && rhs.colSize() == cols)
    {
        matrix temp(rows,cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp(i+1,j+1) = - rhs(i+1,j+1) + data[i][j];
            }
        }
    return temp;
    }
}

matrix matrix::operator* (const matrix &rhs)
{
    if (cols == rhs.rowSize())
    {
        matrix temp(rows,rhs.colSize());
        temp.setValue(0);

        for (int i=0; i < rows; i++)
        {
            for (int j=0; j < rhs.colSize(); j++)
            {
                temp(i+1,j+1) = 0;
                for(int k=0; k < cols; k++)
                {
                    temp(i+1,j+1) = temp(i+1,j+1) + data[i][k] * rhs(k+1,j+1);
                }
            }
        }
    return temp;
    }
    else errorHandler(4);
}


matrix matrix::operator~()
{
    matrix temp(cols,rows);
    temp.setName("Inverse of "+name);
    for (int i = 0; i<cols; i++)
    {
        for (int j = 0; j<rows; j++)
        {
            temp(i+1,j+1) = data[j][i];
        }
    }
    return temp;
}



