#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

template <typename M>
bool is_square_matrix(M const &m)
{
  if (empty(m))
    return true;
  size_t const rows = size(m);
  for (auto &row: m)
    if (size(row) != rows)
      return false;
  return true;
}

template <typename M>
bool is_L_matrix(M const &m)
{
  if (!is_square_matrix(m))
    return false;
  for (size_t i = 0; i < size(m); ++i)
  {
    if (m[i][i] <= 0)
      return false;
    for (size_t j = 0; j < size(m); ++j)
      if (i != j && m[i][j] > 0)
        return false;
  }
  return true;
}

int main()
{
  vector <vector <int>> m(3);
  m[0] = {1, -1, -2};
  m[1] = {0,  2, -2};
  m[2] = {-1, -2, 3};
  cout << is_L_matrix(m);
}
