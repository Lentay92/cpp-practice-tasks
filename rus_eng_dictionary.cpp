#include <iostream>
#include <map>
#include <string>

using namespace std;

class Dictionary
{
private:
    map <string, string> dict;
public:
    void Add(size_t n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enter the word in English\n";
            string str_en;
            cin >> str_en;
            cout << "Enter the word in Russian\n";
            string str_ru;
            cin >> str_ru;
            dict[str_en] = str_ru;
        }
    }

    void Out()
    {
        map <string, string> :: iterator it = dict.begin();
        for (size_t i = 1; it != dict.end(); it++, i++)
            cout << i << ") " << it -> first << " --- " << it -> second << '\n';
    }

    void Find(string str)
    {
        map <string, string> :: iterator it;
        it = dict.find(str);
        if (it == dict.end())
        {
            cout << "This word is not found\n";
            return;
        }
        cout << "Translation for this word: " << it -> second << '\n';
    }

    void Delete(string str)
    {
        map <string, string> :: iterator it;
        it = dict.find(str);
        if (it == dict.end())
        {
            cout << "This word is not found\n";
            return;
        }
        dict.erase(it);
    }

    void Change(string str)
    {
        Delete(str);
        cout << "Now you must enter new word and it's translation\n";
        Add(1);
    }
};

int main()
{

}
