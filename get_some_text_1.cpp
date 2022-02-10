#include <string_view>
#include <iostream>

using namespace std;

string_view get_some_text(string_view text)
{
    size_t from = 0, to;
    from = text.find('*');
    from = text.find_first_not_of('*', from);
    if (from != string_view::npos)
    {
        to = text.find_first_of("*", from);
        if (to == string_view::npos)
            return text;
        return text.substr(from, to - from);
    }
    return text;
}

bool get_some_text_test()
{
    string_view text = "ab****cde***fg";
    return get_some_text(text) == "cde";
}

int main()
{
    cout << "get_some_text_test (should write 1): " <<get_some_text_test();
}
