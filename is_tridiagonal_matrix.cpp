#include <iostream>
#include <cmath>

using namespace std;

bool tri_diagonal_matrix(double const* const* matrix, int rows, int cols)
{
    if (rows != cols)
        return false;
    for (int i = 0; i < rows; ++i)
    {
        auto const row = matrix[i];
        for (int j = 0; j < cols; ++j)
        {
            auto const item = row[j];
            if ((item != 0) && (fabs(i-j) > 1))
            return false;
        }
    }
 return true;
}

bool tri_diagonal_matrix(double const matrix[], int rows, int cols)
{
    if (rows != cols)
        return false;
    for (int i = 0; i < rows; ++i, matrix += cols)
    {
        for (int j = 0; j < cols; ++j)
        {
            auto const item = matrix[j];
            if ((item != 0) && (fabs(i-j) > 1))
                return false;
        }
    }
return true;
}

bool tri_diagonal_matrix_packed_adapter(double const matrix[], int rows, int cols)
{
    auto r = new double const*[rows];
    for (size_t i = 0; i < rows; ++i, matrix += cols)
    	r[i] = matrix;
    bool result = tri_diagonal_matrix(r, rows, cols);
    delete[] r;
    return result;
}

// Тест
int test_tri_diagonal_matrix (bool (&tridiag)(double const matrix[], int rows, int cols))
{
    double m[]
    {
    2, 1, 0, 0, 0,
	1, 2, 1, 0, 0,
	0, 3, 4, 5, 0,
	0, 0, 2, 1, 1,
	0, 0, 0, 1, 2
    };

    if (!tridiag(m, 5, 5))
		return 1;
	m[3]= 10;
	if (tridiag(m, 5, 5))
		return 2;
    return 0;
}

int main()
{
    cout << "tri_diagonal_matrix tests (should write 0 0): ";
    cout << test_tri_diagonal_matrix(tri_diagonal_matrix) << ' ';
    cout << test_tri_diagonal_matrix(tri_diagonal_matrix_packed_adapter);
    return 0;
}
