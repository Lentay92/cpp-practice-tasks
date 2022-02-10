#include <vector>
#include <iostream>

using namespace std;

using Index = size_t;
using Adjacency = vector<Index>;
using Bool_matrix = vector<vector<bool>>;
using Adjacency_list = vector<Adjacency>;

Adjacency_list adjacency_matrix_to_adjacency_list(Bool_matrix const & am)
{
  auto const verts = am.size();
  Adjacency_list al(verts);
  for (Index u = 0; u < verts; ++u)
  {
    auto & row = am[u];
    for (Index v = 0; v < verts; ++v)
      if (row[v])
      {
        al[u].push_back(v);
      }
  }
  return al;
}

Bool_matrix adjacency_list_to_adjacency_matrix(Adjacency_list const & al)
{
  auto const verts = al.size();
  Bool_matrix am(verts, vector<bool>(verts));
  for (Index u = 0; u < verts; ++u)
    for (auto v: al[u])
      am[u][v] = true;
  return am;
}

int test()
{
  Adjacency_list al { {1, 2}, {0, 2, 3}, {0, 1, 3}, {1, 2} };
  Bool_matrix am { {0, 1, 1, 0}, {1, 0, 1, 1}, {1, 1, 0, 1}, {0, 1, 1, 0} };
  if (adjacency_matrix_to_adjacency_list(am) != al)
    return 1;
  if (adjacency_list_to_adjacency_matrix(al) != am)
    return 2;
  return 0;
}

int main()
{
  cout << "test: " << test();
}
