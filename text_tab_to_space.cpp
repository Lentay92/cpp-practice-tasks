#include <string>
#include <vector>
#include <iostream>
using namespace std;

size_t count_tabs(const string &s)
{
  size_t count = 0;
  for (size_t i = 0; i < size(s) && s[i] == '\t'; ++i)
    count++;
  return count;
}

void tab2space_str(string &s, size_t tab_size)
{
  size_t tabs = count_tabs(s);
  s.replace(0, tabs, tab_size * tabs, ' ');
}

void tab2space_text(vector <string> &text, size_t tab_size)
{
    for (size_t i = 0; i < size(text); ++i)
      tab2space_str(text[i], tab_size);
}

int test_tab2space()
{
    vector <string> text
    {
      "\tA line",
      "dog\twoof",
      "\t\tCAT MEOW",
      "stringoftext",
    };

    tab2space_text(text, 2);
    if (text[0] != "  A line")
        return 1;
    if (text[1] != "dog\twoof")
        return 2;
    if (text[2] != "    CAT MEOW")
        return 3;
    if (text[3] != "stringoftext")
        return 4;
    return 0;
}

int main()
{
  cout << "test_tab2space (should write 0):";
  cout << test_tab2space();
  return 0;
}
