#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

using Index = size_t;
using Edge = pair <Index, Index>;
using Edge_list = vector <Edge>;
using Int8_matrix = vector <vector <int8_t> >;

Index vertices(Edge_list const& el)
{
  Index max_vertex = 0;
  for (auto [u, v] : el)
    max_vertex = max({u, v, max_vertex});
  return max_vertex + 1;
}

Int8_matrix edge_list_to_incidence_matrix(Edge_list const& el)
{
  auto const verts = vertices(el);
  auto const edges = el.size();
  Int8_matrix im(verts, vector <int8_t> (edges));
  for (Index e = 0; e < edges; ++e)
  {
    auto [u, v] = el[e];
    im[u][e] = 1;
    im[v][e] = -1;
  }
  return im;
}

Edge_list incidence_matrix_to_edge_list(Int8_matrix const& im){
  Edge_list el;
  if (auto const verts = im.size())
  {
    auto const edges = im[0].size();
    el.resize(edges);
    for (Index e = 0; e < edges ; ++e)
    {
      Index first = 0, second = 0;
      for (Index v = 0; v < verts; ++v)
      {
        if (im[v][e] == 1)
          first = v;
        if (im[v][e] == -1)
          second = v;
      }
      el[e] = Edge(first, second);
    }
  }
  return el;
}

int test()
{
  Int8_matrix im = { {1, -1, 0 , 0, 0 }, { -1, 0, 1, 1, 0 }, { 0, 0, 0, -1, -1}, { 0, 1, -1, 0, 1 } };
  Edge_list el = { { 0, 1 }, { 3, 0 }, { 1, 3 }, { 1, 2 }, { 3, 2 } };
  if (incidence_matrix_to_edge_list(im) != el)
    return 1;
  if (edge_list_to_incidence_matrix(el) != im)
    return 2;
  return 0;
}

int main()
{
  cout << "test (should write 0): " << test();
  return 0;
}
