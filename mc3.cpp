#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

class Matrix
{
private:
    int row, col;
    int matrix[10][10];
    int result[10][10];

public:
    // Default Constructor.
    Matrix()
    {
        row = 0;
        col = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = 0;
                //result[i][j];
            }
        }
    }

    // Constructor.
    Matrix(int r, int c)
    {
        row = r;
        col = c;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = 0;
                //result[i][j];
            }
        }
    }

    // Operator overload.
    int &operator()(int row, int col)
    {
        return matrix[row][col];
    }

    // Get matrix size and populate all matrix elements.
    void getInput()
    {
        do
        {
            cout << "Rows = ";
            cin >> row;
            cout << "Columns = ";
            cin >> col;
            if (row < 1 || col < 1 || row > 10 || col > 10)
            {
                cout << "Invalid entries. Min size = 1x1 and max size = 10x10.\n";
            }
        } while (row < 1 || col < 1 || row > 10 || col > 10);

        cout << "Remember to enter matrix entries from top-left to bottom-right.\n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << "Matrix Entry (" << i << "," << j << ") = ";
                cin >> matrix[i][j];
                result[i][j] = 0;
            }
        }
    }

    // Output the full matrix to the screen in matrix representation.
    void displayMatrix()
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout << setw(5) << matrix[i][j];
            }
            cout << endl;
        }
    }

    // Output the full resultant matrix to the screen in matrix representation.
    void displayResultMatrix(int rows, int cols)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << setw(5) << result[i][j];
            }
            cout << endl;
        }
    }

    // Perform matrix addition.
    void matrixAddition(Matrix m)
    {
        if (row == m.row && col == m.col)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    matrix[i][j] += m(i, j);
                }
            }
            displayMatrix();
        }
        else
        {
            cout << "Cannot complete matrix addition with these matrices.\n";
        }
    }

    // Perform matrix subtraction.
    void matrixSubtraction(Matrix m)
    {
        if (row == m.row && col == m.col)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    matrix[i][j] -= m(i, j);
                }
            }
            displayMatrix();
        }
        else
        {
            cout << "Cannot complete matrix subtraction with these matrices.\n";
        }
    }

    // Perform matrix multiplication.
    void matrixMultiplication(Matrix m)
    {
        if (col == m.row)
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < m.col; j++)
                {
                    result[i][j] = 0;
                    for (int k = 0; k < m.row; k++)
                    {
                        result[i][j] += matrix[i][k] * m(k, j);
                    }
                }
            }
            displayResultMatrix(row, m.col);
        }
        else
        {
            cout << "Cannot complete matrix multiplication with these matrices.\n";
        }
    }

    // Find matrix determinant.
    double determinant(Matrix m, int row)
    {
        double det = 0;
        Matrix submatrix;

        if (row == 2)
        {
            return (m(0, 0) * m(1, 1)) - (m(0, 1) * m(1, 0));
            //cout << det << endl;
        }
        else
        {
            for (int x = 0; x < row; x++)
            {
                double subi = 0;
                for (int i = 1; i < row; i++)
                {
                    double subj = 0;
                    for (int j = 0; j < row; j++)
                    {
                        if (j == x)
                            continue;
                        submatrix(subi, subj) = m(i, j);
                        //cout << m(i,j);
                        subj++;
                    }
                    subi++;
                }
                det = det + (pow(-1, x) * m(0, x) * determinant(submatrix, row - 1));
            }
            cout << det << endl;
            //return det;
        }
    }

    int getRow()
    {
        return row;
    }

    int getCol()
    {
        return col;
    }
};

int main()
{

    cout << "Enter first matrix:\n";
    Matrix a;
    a.getInput();

    cout << "Enter second matrix:\n";
    Matrix b;
    b.getInput();

    cout << "First matrix:\n";
    a.displayMatrix();
    cout << "Second matrix:\n";
    b.displayMatrix();

    int choice;

    cout << "Choose which operation to be performed: \n"
         << "Enter 1 for matrix addition.\n"
         << "Enter 2 for matrix subtracion.\n"
         << "Enter 3 for matrix multiplication.\n"
         << "Enter 4 to find the matrix determinant.\n";

    cout << "Please enter your operation choice: ";
    cin >> choice;
    cout << endl;

    if (choice == 1)
    {
        cout << "Addition:\n";
        a.matrixAddition(b);
    }
    else if (choice == 2)
    {
        cout << "Subtraction:\n";
        a.matrixSubtraction(b);
    }
    else if (choice == 3)
    {
        cout << "Multiplication:\n";
        a.matrixMultiplication(b);
    }
    else if (choice == 4)
    {
        if (a.getRow() != a.getCol()) // Check if row equals col
        {
            cout << "Cannot find determinant since first matrix is not square.\n";
        }
        else
        {
            cout << "Determinant of first matrix: ";
            a.determinant(a, a.getRow()); 
        }

        if (b.getRow() != b.getCol()) // Check if row equals col
        {
            cout << "Cannot find determinant since second matrix is not square.\n";
        }
        else
        {
            cout << "Determinant of second matrix: ";
            b.determinant(b, b.getRow());
        }
    }
    cout << endl;
    return 0;
}