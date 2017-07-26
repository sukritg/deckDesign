
#ifndef MATRIX_H
#define MATRIX_H

#include <string>
#include <iostream>

class matrix
{
    public:
        matrix();
        matrix(int _rows, int _cols);
        matrix(int _rows, int _cols, std::string _name);
        matrix(const matrix &);
        ~matrix();

        int rowSize() const;
        int colSize() const;
        std::string getName() const;
        void setName(std::string _name);
        void setSize(int _rows, int _cols);
        void setValue(double _value);

        void errorHandler(int _errorCode);
        void errorHandler(int _errorCode) const;
        bool isEmpty();
         bool isEmpty() const;

        matrix & operator= (const matrix &mat);

        double & operator() (int _row, int _col);
        double & operator() (int _row, int _col) const;

        matrix operator+ (const matrix &rhs);
        matrix operator- (const matrix &rhs);
        matrix operator* (const matrix &rhs);
        matrix operator~ ();
    protected:


    private:
        double **data;
        int rows, cols;
        std::string name;
};
#endif // MATRIX_H
