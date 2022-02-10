#include <string>
#include <vector>
#include <iostream>

using namespace std;

size_t spaces_count(const string &str)
{
  size_t count = 0;
  for (size_t i = 0; str[i] == ' '; ++i)
    count++;
  return count;
}

void space2tab_str(string &str, size_t tab_size)
{
  size_t spaces = spaces_count(str);
  str.replace(0, spaces - (spaces % tab_size), spaces / tab_size, '\t');
}

void space2tab_text(vector <string> &text, size_t tab_size)
{
    for (size_t i = 0; i < size(text); ++i)
      space2tab_str(text[i], tab_size);
}

int test_space2tab()
{
    vector <string> text
    {
      "    A line",
      "dog woof",
      "   CAT MEOW",
      "stringoftext",
    };

    space2tab_text(text, 2);
    if (text[0] != "\t\tA line")
        return 1;
    if (text[1] != "dog woof")
        return 2;
    if (text[2] != "\t CAT MEOW")
        return 3;
    if (text[3] != "stringoftext")
        return 4;

    return 0;
}

int main()
{
  cout << "test_space2tab (should write 0): ";
  cout << test_space2tab();
}
