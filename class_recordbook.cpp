#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Recordbook
{
private:
    string title[3];
    string date[3];
    size_t mark[3];
public:
    string fio[3];
    void Input()
    {
        cout << "Enter your full name\n";
        for (size_t i = 0; i < 3; ++i)
            cin >> fio[i];
        cout << '\n';
        cout << "Enter the titles of the exam\n";
        for (size_t i = 0; i < 3; ++i)
            cin >> title[i];
        cout << '\n';
        cout << "Enter the dates of the exam\n";
        for (size_t i = 0; i < 3; ++i)
            cin >> date[i];
        cout << '\n';
        cout << "Enter the marks for the exam\n";
        for (size_t i = 0; i < 3; ++i)
            cin >> mark[i];
        cout << "\n\n";
    }
    void Change()
    {
        cout << "What you need to change?\n1.Title\n2.Date\n3.Name\n4.Mark\n(enter the necessery number)\n";
        size_t temp;
        cin >> temp;
        switch (temp)
        {
        case 1:
            cout << "Enter the titles of the exam\n";
            for (size_t i = 0; i < 3; ++i)
                cin >> title[i];
            break;
        case 2:
            cout << "Enter the dates of the exam\n";
            for (size_t i = 0; i < 3; ++i)
                cin >> date[i];
            break;
        case 3:
            cout << "Enter your full name\n";
            for (size_t i = 0; i < 3; ++i)
                cin >> fio[i];
            break;
        case 4:
            cout << "Enter the marks for the exam\n";
            for (size_t i = 0; i < 3; ++i)
                cin >> mark[i];
            break;
        }
    }
    void Output()
    {
        for (size_t i = 0; i < 3; ++i)
            cout << fio[i] << ' ';
        cout << '\n';
        for (size_t i = 0; i < 3; ++i)
            cout << title[i] << " " << date[i] << "\t" << mark[i] << "\n";
        cout << '\n';
    }
    bool operator==(Recordbook& Zachetka)
    {
        for (size_t i = 0; i < 3; ++i)
            if (this->title[i] == Zachetka.title[i] &&
                this->date[i] == Zachetka.date[i] &&
                this->mark[i] == Zachetka.mark[i] &&
                this->fio[i] == Zachetka.fio[i])
                return true;
        return false;
    }
    bool operator<(Recordbook& Zachetka)
    {
        return fio[0] < Zachetka.fio[0];
    }
    bool operator>(Recordbook& Zachetka)
    {
        return fio[0] > Zachetka.fio[0];
    }
};

bool comp_fio(Recordbook const& a, Recordbook const& b)
{
    return a.fio[0] < b.fio[0];
}

class Group
{
private:
    vector <Recordbook> roster;
public:
    Group(size_t vec_sz)
    {
        Recordbook Zachetka;
        for (size_t i = 0; i < vec_sz; ++i)
        {
            Zachetka.Input();
            roster.push_back(Zachetka);
        }
        Sort();
    }
    void Sort()
    {
        sort(roster.begin(), roster.end(), comp_fio);
    }
    void Add()
    {
        Recordbook Zachetka;
        Zachetka.Input();
        roster.push_back(Zachetka);
        Sort();
    }
    void Output()
    {
        for (size_t i = 0; i < size(roster); ++i)
        {
            roster[i].Output();
        }
    }
    void Find()
    {
        cout << "Enter student's surname\n";
        string str;
        cin >> str;
        size_t i = 0;
        for (i; i < size(roster); ++i)
            if (str == roster[i].fio[0])
            {
                roster[i].Output();
                break;
            }
        cout << "Delete this recordbook? (Y/N)\n";
        char tmp; cin >> tmp;
        if (tmp == 'Y')
        {
            roster.erase(roster.begin() + i);
        }
        else if (tmp == 'N')
            return;
        else cout << "Error: incorrect input\n";
    }
    Group operator+(Group& Gruppa)
    {
        vector <Recordbook> union_vec;
        Recordbook* p1 = &roster[0];
        Recordbook* p2 = &Gruppa.roster[0];

        for (size_t i = 0; i < size(roster) - 1; ++i)
        {
            if (*(p2 + i) < *p1)
                union_vec.push_back(*(p2 + i));
            if (*(p2 + i) > *p1)
            {
                union_vec.push_back(*p1);
                swap(*p1 , *(p2 + i));
            }
        }
        roster = union_vec;
        return *this;
    }
    Group operator-(Group& Gruppa)
    {
        for (size_t i = 0; i < size(Gruppa.roster); ++i)
            for (size_t j = 0; j < size(this->roster); ++j)
                if (Gruppa.roster[i] == this->roster[j])
                    this->roster.erase(roster.begin() + j);
        return *this;
    }
    ~Group()
    {
        roster.clear();
    }
};

class Subject
{
public:
    virtual void subj_out() = 0;
};

class Offset: public Subject
{
    vector <string> subj = { "General physics", "English" };
public:
    void subj_out()
    {
        cout << "Offset subjects: " << subj[0] << ", " << subj[1] <<'\n';
    }
};

class Exam: public Subject
{
    vector <string> subj = { "Algebra and geometry" , "Mathematical analysis", "Basics of programming" };
public:
    void subj_out()
    {
        cout << "Exam subjects: " << subj[0] << ", " << subj[1] << ", " << subj[2] <<'\n';
    }
};

int main()
{

}
