#include <cassert>
#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_set>

using Index = std::size_t;
using Adjacency = std::unordered_set<Index>;
using Vertices_list = std::vector<Adjacency>;

std::ostream& write_vertices_list(std::ostream& out, Vertices_list const& vertices)
{
  out << "{\n";
  for (auto u: vertices)
  {
    for(auto v: u)
      out << " " << v;
    out << ";";
  }
  return out << "\n}\n";
}

int skipws_then_peek(std::istream& in)
{
  if (char ch; in >> ch)
  {
    in.unget();
    return ch;
  }
  return -1;
}

bool expect(std::istream& in, char prefix)
{
  if (in.peek() == (unsigned char)prefix)
  {
    in.ignore();
    return true;
  }
  in.setstate(std::ios::failbit);
  return false;
}


bool expect(std::istream& in, std::string_view prefix)
{
  while (!prefix.empty() && expect(in, prefix.front()))
    prefix.remove_prefix(1);
  return prefix.empty();
}

bool skipws_then_expect(std::istream& in, char prefix)
{
  assert(!std::isspace((unsigned char)prefix));
  if (char x; (in >> x) && (x == prefix))
    return true;
  in.setstate(std::ios::failbit);
  return false;
}

bool skipws_then_expect(std::istream& in, std::string_view prefix)
{
  return prefix.empty() ||
        (skipws_then_expect(in, prefix.front()) &&
         expect(in, prefix.substr(1)));
}

std::istream& read_vertices_list(std::istream& in, Vertices_list& vertices)
{
  bool success = false;
  if (skipws_then_expect(in, '{'))
  {
    vertices.clear();
    std::unordered_set<Index> i;
    char ch;
    for (Index u; skipws_then_peek(in) != '}' && in >> u;)
    {
      i.emplace(u);
      if (in >> ch)
      {
        if (ch == ';')
        {
          vertices.push_back(i);
          i.clear();
        }
        else
          in.unget();
      }
    }
    if (!i.empty())
      vertices.push_back(i);
    success = skipws_then_expect(in, '}');
  }
  if (!success)
    in.setstate(std::ios::failbit);
  return in;
}

void test_write_vertices_list()
{
  Vertices_list vertices
  {
    {1, 2, 3, 4}, {2, 0, 4}, {1, 0, 3}, {2, 0, 4}, {1, 0, 3}
  };
  std::ostringstream out;
  write_vertices_list(out, vertices);
  std::cout << out.str();
}

int test_read_vertices_list()
{
  Vertices_list vertices
  {
    {1, 2, 3, 4}, {2, 0, 4}, {1, 0, 3}, {2, 0, 4}, {1, 0, 3}
  },
  vertices_out;
  std::istringstream in;
  in.str("{1 2 3 4; 2 0 4; 1 0 3 ; 2 0 4; 1 0 3;}");
  read_vertices_list(in, vertices_out);
  if (vertices_out != vertices)
    return 1;
  return 0;
}

int main()
{
  test_write_vertices_list();
  std::cout << "\ntest read_vertices_list (should write 0): " << test_read_vertices_list();
  return 0;
}
