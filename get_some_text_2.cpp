#include <string_view>
#include <iostream>

using namespace std;

double average_len(string_view text)
{
    size_t count = 0, from, to = 0;
    for (double i = 0;; ++i)
    {
        from = text.find_first_of("-.", to);
        if (from == string_view::npos)
            return count / i;
        to = text.find_first_not_of("-.", from);
        if (to == string_view::npos)
            return (count + text.size() - from) / (i + 1);
        count += to - from;
    }
}

bool average_len_test()
{
    string_view text = "ab-...cd.---.efg.hi--.";
    return average_len(text) == 3.25;
}

int main()
{
    cout << "get_some_text_test (should write 1): " <<average_len_test();
}
