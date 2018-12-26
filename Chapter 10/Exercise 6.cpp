#include <iostream>
#include <string>
#include <vector>
//-------------------------------------------------------------------

int get_arabic(const char& r);
std::vector<int>get_values(const Roman_int& r);

//-------------------------------------------------------------------

struct Roman_int
{
       Roman_int() :roman{"nulla"}{}
       Roman_int(std::string r) :roman{r}{}
       
       int as_int();
       bool is_valid() const;
       
       std::string roman;
};

//-------------------------------------------------------------------

std::string Roman_int::as_int()
{
    
}

std::vector<int> Roman_int::get_values() const
{
    std::vector<int>v;
    for (int x = 0; x < roman.size(); ++x)
        v.push_back(get_arabic(roman[x]));
    return v;
}

bool Roman_int::is_valid() const
{
    vector<int>values = 
    for (int x = 0; x < 
}

//-------------------------------------------------------------------

int get_arabic(const char& r)
{
    int arab;
    switch(r)
    {
    case 'I':
        arab = 1;
        break;
    case 'V':
        arab = 5;
        break;
    case 'X':
        arab = 10;
        break;
    case 'L':
        arab = 50;
        break;
    case 'C':
        arab = 100;
        break;
    case 'D':
        arab = 500;
        break;
    case 'M':
        arab = 1000;
        break;
    }
    return arab;
}

//-------------------------------------------------------------------
