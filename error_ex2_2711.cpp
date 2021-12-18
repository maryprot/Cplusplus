#include <iostream>
#include <fstream>
#include <random>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <unordered_set>
#include <iterator>
#include <optional>
using namespace std;

bool check_str(string s)
{
    optional<long long> data;
    try
    {
        long long str = stoll(s);
        if(to_string(str).length()==11)
        {
            data = str;
            if(data.value_or(0))
            {
                return 1;
            }
        }
        return 0;
    }
    catch(...)
    {return 0;}
}

int main()
{
    ifstream in1("task2_input.txt");
    int calls=0;
    set<string> numbers;
    vector<int> bugs;
    bool error=0;
    while(in1 and error==0)
    {
        string str;
        getline(in1, str);
        if(str!="")
        {
            if(count(str.begin(), str.end(),','))
            {
                int dot = str.find(",");
                string p1 = str.substr(0, dot);
                string p2 = str.substr(dot+1,-1);
                if(check_str(p1) && check_str(p2))
                {
                    numbers.insert(p1);
                    numbers.insert(p2);
                    calls++;
                }
                else
                {
                    error=1;
                }
            }
            else
            {
                error=1;
            }
            if(error==1)
            {
                bugs.push_back(bugs.size());
            }
        }
    }

    ofstream out1("task2_output.txt");
    out1<<calls<<endl;
    out1<<numbers.size()<<endl;
    ofstream out1_bugs("task2_error.txt");
    for(int i=0; i<bugs.size(); i++)
    {
        out1_bugs<<bugs[i]+1<<endl;
    }
    return 0;
}
