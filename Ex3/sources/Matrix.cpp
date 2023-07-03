
#include <iostream>
#include <stdexcept>
#include "Matrix.hpp"

using namespace zich;

// check_throws

void Matrix::check_matrix_size(const Matrix &mat1, const Matrix &mat2)
{
    if (mat1.row != mat2.row or mat1.col != mat2.col)
    {
        throw std::invalid_argument("rows and cols not equals");
    }
}

void Matrix::check_building_matrix(const std::vector<double> &matri, int row, int col)
{
        if (row < 1 or col < 1)
    {
        throw std::invalid_argument("rows and cols cannot be negative");
    }

    if (row * col != matri.size())
    {
        throw std::invalid_argument("invalid matrix");
    }
}

void Matrix::check_valid_mult(const Matrix &mat1, const Matrix &mat2)
{
    if (mat1.col != mat2.row)
    {
        throw std::logic_error("multification is not define");
    }
}
Matrix::Matrix(){
    this->row=0;
    this->col=0;
}

Matrix::Matrix(int row, int col)
{
    this->row = row;
    this->col = col;
    this->mat.resize((unsigned int)(row*col));
    
    
    
}

Matrix::Matrix(const std::vector<double> &matri, int row, int col)
{
    check_building_matrix(matri, row, col);
    this->col = col;
    this->row = row;
    for (unsigned int i = 0; i < row * col; i++)
    {
        mat.push_back(matri[i]);
    }
}

//-----------------------------
// Arithmetic Operators
//-----------------------------

Matrix Matrix::operator-()
{
    Matrix mat1(this->row, this->col);

    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        mat1.mat[i]=(-1) * (this->mat[i]);
    }
    return mat1;
}

Matrix Matrix::operator-(const Matrix &mat1)
{
    check_matrix_size(*this, mat1);
    Matrix matr(this->row, this->col);
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        matr.mat[i]=(this->mat[i] - mat1.mat[i]);
    }
    return matr;
}
Matrix Matrix::operator-=(const Matrix &mat1)
{
    return *this=*this-mat1;
}

Matrix Matrix::operator+()
{
    Matrix matr(this->row, this->col);
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        matr.mat[i]=(this->mat[i]);
    }
    return matr;
}

Matrix Matrix::operator+(const Matrix &mat1)
{
    check_matrix_size(*this, mat1);
    Matrix matr(this->row, this->col);
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        matr.mat[i]=(this->mat[i] + mat1.mat[i]);
    }
    return matr;
}
Matrix Matrix::operator+=(const Matrix &mat1)
{
    return *this=*this+mat1;

}

//-----------------------------
// Comparison Operators
//-----------------------------

bool zich::Matrix::operator!=(const Matrix &mat1) const
{
    return !(*this==mat1);
}
bool zich::Matrix::operator==(const Matrix &mat1) 
{
    check_matrix_size(*this, mat1);

    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        if (this->mat[i] != mat1.mat[i])
        {
            return false;
        }
    }
    return true;
}

bool zich::Matrix::operator<=(const Matrix &mat1) const
{
    check_matrix_size(*this, mat1);

    bool ans = false;
    if (this->sum() <= mat1.sum())
    {
        ans = true;
    }

    return ans;
}
bool zich::Matrix::operator>=(const Matrix &mat1) const
{
    check_matrix_size(*this, mat1);

    bool ans = false;
    if (this->sum() >= mat1.sum())
    {
        ans = true;
    }

    return ans;
}

int zich::Matrix::sum() const
{

    int res = 0;
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        res += this->mat[i];
    }
    return res;
}

bool zich::Matrix::operator<(const Matrix &mat1) const
{
    return !(*this>=mat1);

}
bool zich::Matrix::operator>(const Matrix &mat1) const
{
    return !(*this<=mat1);
}
//-----------------------------
// Increment Decrement Operators
//-----------------------------

Matrix& Matrix::operator--()
{
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        this->mat[i]--;
    }
    return *this;
}

Matrix Matrix::operator--(const int d)
{

    Matrix temp = *this;
    --*this;
    return temp;
}

Matrix& Matrix::operator++()
{
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        this->mat[i]++;
    }
    return *this;
}

Matrix Matrix::operator++(const int d)
{
    Matrix temp = *this;
    ++*this;
    return temp;
}

Matrix Matrix::operator*(const Matrix &mat1)
{
    check_valid_mult(*this, mat1);
    Matrix matr(this->row, mat1.col);
    for (unsigned int i = 0; i < this->row; i++)
    {
        for (unsigned int j = 0; j < mat1.col; j++)
        {
            for (unsigned int k = 0; k < this->col; k++)
            {
                matr.mat[i * (unsigned int)matr.col + j] += this->mat[i * (unsigned int)this->col + k] * mat1.mat[k * (unsigned int)mat1.col + j];
            }
        }
    }

    return matr;
}



Matrix Matrix::operator*=(const Matrix &mat1)
{
    return *this=*this*mat1;
}
Matrix Matrix::operator*=(const double d)
{
    for (unsigned int i = 0; i < this->mat.size(); i++)
    {
        this->mat[i] = (d) * (this->mat[i]);
    }
    return *this;
}

//-----------------------------
// I/O Operators
//-----------------------------

namespace zich
{

    bool operator==(const Matrix &mat1 , const Matrix&mat2)
{
        if (mat1.row != mat2.row or mat1.col != mat2.col)
    {
        throw std::invalid_argument("rows and cols not equals");
    }

    for (unsigned int i = 0; i < mat1.mat.size(); i++)
    {
        if (mat1.mat[i] != mat2.mat[i])
        {
            return false;
        }
    }
    return true;
}

    Matrix operator*(double d, const Matrix &mat1)
        {
          Matrix matr(mat1.row , mat1.col);
        for (unsigned int i = 0; i < mat1.mat.size(); i++)
        {
            matr.mat[i]=(d*mat1.mat[i]);
        }
        return matr;
    }

    Matrix operator*(const Matrix &mat1 , double d){
        return d*mat1;
    }

    std::ostream &operator<<(std::ostream &out, const Matrix &num)
    {
        std::string res;
        for (unsigned int i = 0; i < num.row; i++)
        {
            out<< '[';
            for (unsigned int j = 0; j < num.col; j++)
            {
                if ((int)num.mat[i * (unsigned int)num.col + j] == num.mat[i * (unsigned int)num.col + j])
                {
                    out<< std::to_string(int(num.mat[i * (unsigned int)num.col + j]));
                }
                else{
                    out<<  std::to_string(num.mat[i * (unsigned int)num.col + j]);

                }
                
                if (j != num.col - 1)
                {
                    out<<  " ";
                }
            }
            out<< ']';
            if(i!=num.row-1){
            out<< "\n";
            }
        }

        return out;
    }

    std::vector<std::string> split(std::string const &str, std::string const &delim)
    {
        std::vector<std::string> tokens;
        size_t start = 0;
        size_t end = 0;
        while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
        {
            end = str.find(delim, start);
            tokens.push_back(str.substr(start, end - start));
        }
        return tokens;
    }
    std::vector<std::string> split2(std::string const &str, char delim)
    {
        std::vector<std::string> tokens;
        size_t start = 0;
        size_t end = 0;
        while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
        {
            end = str.find(delim, start);
            tokens.push_back(str.substr(start, end - start));
        }
        return tokens;
    }

    std::istream &operator>>(std::istream &in, Matrix &mat)
    {
        std::string inmatrix;
        std::getline(in,inmatrix);
        if((inmatrix.find("  ")!=std::string::npos)){
            throw std::invalid_argument("invalid argument");
        }
        if(inmatrix[0]!='[' or inmatrix[(inmatrix.size()-1)]!=']'){
            throw std::runtime_error("error");
        }
        std::vector<std::string> tokens = split(inmatrix, ", ");
        std::vector<double> numbers;
        int rows_size = tokens.size();
        int cols_size = split2(tokens[0], ' ').size();
        for (unsigned int i = 0; i < tokens.size(); i++)
        {
          //  std::cout << tokens[i];
            unsigned int start = 1;
            for (unsigned int j = 1; j < tokens[i].size(); j++)
            {
                if (tokens[i].at(j) == ' ' or tokens[i].at(j) == ']')
                {
                    
                    std::string helper = tokens[i].substr(start, j - 1);
                    double num = std::stod(helper);
                    numbers.push_back(num);
                    start = j + 1;
                }
            }
        }
        mat.mat = numbers;
        mat.row = rows_size;
        mat.col = cols_size;
        return in;
    }

}
