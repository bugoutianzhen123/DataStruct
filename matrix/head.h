#include <bits/stdc++.h>

using namespace std;

struct location
{
    int row;
    int cloumn;

    bool operator<(const location &other) const
    {
        if (row != other.row)
            return row < other.row;
        return cloumn < other.cloumn;
    }
};

class Matrix
{
public:
    int Row, Column, numbers;
    map<location, int> matrix;

    Matrix()
    {
    }

    ~Matrix()
    {
    }

    Matrix &Insert(int row, int column, int data)
    {
        location loc = {row, column};
        if (matrix.find(loc) == matrix.end())
        {
            matrix[loc] = data;
        }
        else
        {
            cout << "" << endl;
        }

        return *this;
    }

    Matrix &a(Matrix *other)
    {
        if (Row != other->Row || Column != other->Column)
        {
            cout << "can't " << endl;
        }
    }
};