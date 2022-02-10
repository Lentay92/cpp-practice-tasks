#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename It1, typename It2, typename OutIt>
OutIt intersec(It1 from1, It1 to1, It2 from2, It2 to2, OutIt out)
{
    sort(from1, to1);
    to1 = unique(from1, to1);
    sort(from2, to2);
    to2 = unique(from2, to2);
    set_intersection(from1, to1, from2, to2, out);
    return out;
}

bool test_intersec()
{
    vector <string> v1
    {
      "he",
      "has",
      "left",
      "the",
      "reason",
      "behind",
      "jumping",
      "right",
      "into",
      "the",
      "fire"
    };

    vector <string> v2
    {
      "he",
      "tried",
      "so",
      "many",
      "times",
      "and",
      "lost",
      "the",
      "reason",
      "to",
      "proceed"
    };

    vector <string> result
    {
      "he",
      "reason",
      "the"
    };

    vector <string> f_result(3);
    intersec(v1.begin(), v1.end(), v2.begin(), v2.end(), f_result.begin());
    return f_result == result;
}

int main()
{
    cout << "test_intersec (should write 1): " <<test_intersec();
}
