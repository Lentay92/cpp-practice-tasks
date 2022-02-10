#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

using Index = size_t;
using Edge = pair<Index, Index>;
using Edge_list = vector<Edge>;
using Bool_matrix = vector<vector<bool>>;

ostream& operator<<(ostream& os, Edge_list const & el)
{
  for (auto [u, v]: el)
    os << u << " -- " << v << '\n';
  return os;
}

ostream& operator<<(ostream& os, Bool_matrix const & m)
{
  for (auto& row: m)
  {
    for (bool x: row)
      os << x;
    os << '\n';
  }
  return os;
}

Index vertices(Edge_list const & el)
{
  Index max_vertex = 0;
  for (auto [u, v]: el)
    max_vertex = max({u, v, max_vertex});
  return max_vertex + 1;
}

Bool_matrix edge_list_to_adjacency_matrix(Edge_list const & el)
{
  auto const verts = vertices(el);
  Bool_matrix am(verts, vector<bool>(verts));
  for (auto [u, v]: el)
  {
    am[u][v] = true;
    am[v][u] = true;
  }
  return am;
}

Edge_list adjacency_matrix_to_edge_list(Bool_matrix const & am)
{
  Edge_list el;
  auto const verts = am.size();
  for (Index u = 0; u < verts; ++u)
  {
    auto & row = am[u];
    for (Index v = 0; v <= u; ++v)
      if (row[v])
        el.emplace_back(v, u);
  }
  return el;
}

int test()
{
  Edge_list el { {0, 1}, {1, 2}, {0, 3} };
  Bool_matrix am { {0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 0}, {1, 0, 0, 0} };
  if (edge_list_to_adjacency_matrix(el) != am)
    return 1;
  if (adjacency_matrix_to_edge_list(am) != el)
    return 2;
  return 0;
}

int main()
{
  cout << "test (should write 0): " << test();
}
