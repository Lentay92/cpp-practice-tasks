#include <string>
#include <vector>
#include <iostream>
using namespace std;

size_t new_size(vector <string>& text)
{
    size_t cnt = 0;
    for (size_t i = 0; i < size(text) - 1; ++i)
        if (text[i].back() == '\\')
            ++cnt;
    return size(text) - cnt;
}

vector <string> str_conc(vector <string>& text)
{
    size_t new_sz = new_size(text);
    vector <string> new_text(new_sz);
    size_t k = 0;
    for (size_t i = 0; i < size(text) - 1; ++i)
    {
        if (text[i].back() == '\\')
        {
            new_text[k].append(text[i]);
            new_text[k].pop_back();
            if (text[i + 1].back() == '\\')
                --k;
            else
            {
                new_text[k].append(text[i + 1]);
                ++i;
            }
            ++k;
        }
        else
        {
            new_text[k] = text[i];
            ++k;
        }
    }
    new_text[k] = (text.back());
    return new_text;
}


int test_str_conc()
{
    vector <string> text
    {
    "alpha beta gamma\\",
    "delta epsilon zeta",
    "eta theta iota\\ ",
    "kappa lambda\\",
    " mu nu xi \\",
    "omicron pi rho",
    "upsilon phi chi",
    "psi omega\\"
    };

    text = str_conc(text);
    if (text[0] != "alpha beta gammadelta epsilon zeta")
        return 1;
    if (text[1] != "eta theta iota\\ ")
        return 2;
    if (text[2] != "kappa lambda mu nu xi omicron pi rho")
        return 3;
    if (text[3] != "upsilon phi chi")
        return 4;
    if (text[4] != "psi omega\\")
        return 5;
    return 0;
}

int main()
{
    cout << "test_str_conc (should write 0): ";
    cout << test_str_conc();
    return 0;
}
