#include <iostream>
#include <string>
#include <vector>

using namespace std;

size_t substr_count(vector<string> text, string substr)
{
    size_t count = 0;

    for (size_t j = 0; j < text.size(); ++j)
        for (size_t i = 0; i < text[j].length(); ++i)
            if (text[j][i] == substr[0])
                if (text[j].substr(i, substr.length()) == substr)
                {
                    ++count;
                    i += substr.length() - 1;
                }
    return count;
}

bool test_substr_count()
{
    vector<string> text = {"end", "of", "passion", "play", "crumbling", "away"};
    string substr = "ay";
    return (substr_count(text, substr) == 2);
}

int main()
{
    cout << "test (should be 1): " << test_substr_count();
}
