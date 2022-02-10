#include <iostream>
#include <cstring>

using namespace std;

size_t text_size(char const * const * text)
{
    size_t size = 0;
    while (*text++)
    ++size;
    return size;
}

size_t count_tabs(char const * s)
{
  size_t count = 0;
  for (size_t i = 0; s[i] == '\t'; ++i)
    count++;
  return count;
}

char * tab2space(char const * s, size_t tab_size)
{
    size_t tabs = count_tabs(s);
    size_t len = strlen(s);
    size_t new_len = len + (tab_size - 1) * tabs;
    char * new_s = new char[new_len + 1];
    memset(new_s, ' ', tab_size * tabs);
    strcpy(new_s + tab_size * tabs, s + tabs);
    return new_s;
}

char ** new_text(char const * const * text, size_t tab_size)
{
    auto tsz = text_size(text);
    auto new_t = new char *[tsz + 1];
    new_t[tsz] = nullptr;
    for (size_t i = 0; text[i]; ++i)
    {
        new_t[i] = tab2space(text [i], tab_size);
    }
    return new_t;
}

int test_tab2space()
{
    char const * text[]
    {
      "\tA line",
      "dog\twoof",
      "\tCAT MEOW",
      "stringoftext",
      nullptr
    };
    auto new_tx = new_text(text, 2);
    if (strcmp(new_tx[0], "  A line"))
        return 1;
    if (strcmp(new_tx[1], "dog\twoof"))
        return 2;
    if (strcmp(new_tx[2],"  CAT MEOW"))
        return 3;
    if (strcmp(new_tx[3],"stringoftext"))
        return 4;
    return 0;
}

int main()
{
    cout << "test tab2space (should write 0): ";
    cout << test_tab2space();
    return 0;
}
