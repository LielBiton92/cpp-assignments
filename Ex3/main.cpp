#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "sources/Matrix.hpp"
using namespace zich;

void opt()
{
  cout << "***Matrix Calculator***" << endl;
  cout << "Arithmetic" << endl;
  cout << "type 'newMatrixM' to create Matrix M" << endl;
  cout << "type 'newMatrixN' to create Matrix N" << endl;
  cout << "type Plus/Minus to for M+N , N-M " << endl;
  cout << "tpye M+=N TO M=M+N" << endl;
  cout << "Increment/Decerment" << endl;
  cout << "type Increment++/++Increment/Decerment--/--Decerment" << endl;
  cout << "boolean compares" << endl;
  cout << "compare matrix and other matrix using 'M>N' , 'M<M' , M>=N , M<=N ,M==N, M!=N " << endl;
  cout << "Multification" << endl;
  cout << "good to know , matrix multification is defined only if matrix size is like PxQ * Q*R" << endl;
  cout << "out multification options is : type 'M*N , N*M , N*=number , M*=number" << endl;
  cout << " to see the options again , type options" << endl;
}

int main(int argc, char const *argv[])
{

  Matrix M;
  Matrix N;
  string input;
  char c;
  int number;
  bool flag = 1;
  opt();

  while (flag)
  {
    try
    {
      cin >> input;
      if (input == "newMatrixM")
      {
        cout << "enter a matrix" << endl;
        cout << "format : [1 2 3], [4 5 6]" << endl;
        c = std::getchar();
        cin >> M;
      }
      if (input == "newMatrixN")
      {
        cout << "enter a matrix" << endl;
        cout << "format : [1 2 3], [4 5 6]" << endl;
        c = std::getchar();
        cin >> N;
        cout << N << endl;
      }

      if (input == "Plus")
      {
        cout << "the answer is : " << endl;
        cout << M + N << endl;
      }

      if (input == "Minus")
      {
        cout << "the answer is : " << endl;
        cout << M - N << endl;
      }
      if (input == "OnaryMinusMatrix1")
      {
        cout << "the answer is : " << endl;
        cout << -M << endl;
      }
      if (input == "OnaryMinusMatrix2")
      {
        cout << "the answer is : " << endl;
        cout << -N << endl;
      }
      if (input == "Mult1")
      {
        cout << "the answer is : " << endl;
        cout << M * N << endl;
      }
      if (input == "Mult2")
      {
        cout << "the answer is" << endl;
        cout << N * M << endl;
      }
      if (input == "N*=M")
      {
        cout << "the answer is" << endl;
        N *= M;
        cout << N << endl;
      }
      if (input == "M*=N")
      {
        cout << "the answer is" << endl;
        M *= N;
        cout << M << endl;
      }
      if (input == "M*=number")
      {
        cout << "the answer is" << endl;
        cin >> number;
        M *= number;
        cout << M << endl;
      }
      if (input == "N*=number")
      {
        cout << "the answer is" << endl;
        cin >> number;
        N *= number;
        cout << N << endl;
      }

      if (input == "printMatrixM")
      {
        cout << M << endl;
      }
      if (input == "printMatrixN")
      {
        cout << N << endl;
      }

      if (input == "Increment++")
      {
        cout << M++ << endl;
      }
      if (input == "++Increment")
      {
        cout << ++M << endl;
      }
      if (input == "Decerment--")
      {
        cout << M-- << endl;
      }
      if (input == "--Decerment")
      {
        cout << --M << endl;
      }

      if (input == "M>N")
      {
        if (M > N)
        {
          cout << "M is greater then N" << endl;
        }
        else
        {
          cout << "M is less then N" << endl;
        }
      }
      if (input == "M<N")
      {
        if (M < N)
        {
          cout << "M is less then N" << endl;
        }
        else
        {
          cout << "M is greater then N" << endl;
        }
      }
      if (input == "M>=N")
      {
        if (M >= N)
        {
          cout << "M is greater or equal then N" << endl;
        }
        else
        {
          cout << "M is less then N" << endl;
        }
      }
      if (input == "M<=N")
      {
        if (M <= N)
        {
          cout << "M is less or equal then N" << endl;
        }
        else
        {
          cout << "M is greater then N" << endl;
        }
      }
      if (input == "M==N")
      {
        bool ans = M == N;
        if (ans)
        {
          cout << "true" << endl;
        }
        else
        {
          cout << "false" << endl;
        }
      }
      if (input == "M!=N")
      {
        bool ans = M != N;
        if (ans)
        {
          cout << "true" << endl;
        }
        else
        {
          cout << "false" << endl;
        }
      }

      if (input == "options")
      {
        opt();
      }

      if (input == "Exit")
      {
        flag = false;
      }
    }
    catch (exception &e)
    {
      cout << e.what() << endl;
    }
  }
  return 0;
}
