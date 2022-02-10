#include <vector>
#include <iostream>

using namespace std;

using Index = size_t;
using Bool_matrix = vector<vector<bool>>;
using Int_matrix = vector<vector<int8_t>>;

ostream& operator<<(ostream& os, Bool_matrix const & m)
{
  for (auto & row: m)
  {
    for (bool x: row)
      os << x;
    os << '\n';
  }
  return os;
}

ostream& operator<<(ostream& os, Int_matrix const & m)
{
  for (auto & row: m)
  {
    for (bool x: row)
      os << x;
    os << '\n';
  }
  return os;
}

size_t directed_edges(Bool_matrix const & am)
{
  size_t count = 0;
  auto const verts = am.size();
  for (size_t i = 0; i < verts; ++i)
  {
    auto & row = am[i];
    for (size_t j = 0; j < verts; ++j)
      if (row[j])
        ++count;
  }
  return count;
}

Int_matrix adjacency_matrix_to_incidence_matrix(Bool_matrix const & am)
{
  auto const verts = am.size();
  auto const edges = directed_edges(am);
  Int_matrix im(verts, vector<int8_t>(edges));
  for (size_t i = 0, e = 0; i < verts; ++i)
  {
    auto & row = am[i];
    for (size_t j = 0; j < verts; ++j)
      if (row[j])
      {
        im[i][e] = 1;
        im[j][e] = -1;
        ++e;
      }
  }
  return im;
}

Bool_matrix incidence_matrix_to_adjacency_matrix(Int_matrix const & im)
{
  Bool_matrix am;
  if (auto const verts = im.size())
  {
    am.resize(verts, vector<bool>(verts));
    auto const edges = im[0].size();
    for (Index e = 0; e < edges; ++e)
    {
      Index first = 0, second = 0;
      for (Index v = 0; v < verts; ++v)
      {
        if (im[v][e] == 1)
          first = v;
        if (im[v][e] == -1)
          second = v;
      }
      am[first][second] = true;
    }
  }
  return am;
}

int test()
{
  Int_matrix im { {1, 0, 0, -1, 0}, {-1, 1, 1, 0, 0}, {0, -1, 0, 0, -1}, {0, 0, -1, 1, 1} };
  Bool_matrix am { {0, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 0, 0}, {1, 0, 1, 0} };
  if (incidence_matrix_to_adjacency_matrix(im) != am)
    return 1;
  if (adjacency_matrix_to_incidence_matrix(am) != im)
    return 2;
  return 0;
}

int main()
{
  cout << "test (should write 0): " << test();
}
