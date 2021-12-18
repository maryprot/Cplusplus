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
using namespace std;

int main()
{
    ifstream in1("task1_input_0.txt");
    string line;
    set<string> data;
    while(in1)
    {
        in1>>line;
        data.insert(line);
    }
    cout<<"Number of unique users_1 "<<data.size()<<endl;
    ofstream out1("task1_output_0.txt");
    out1 << data.size();
    data.clear();
    set<pair<string, string>> data2;
    ifstream in2("task2_input_0.txt");
    pair<string,string> person;
    while(in2)
    {
        getline(in2, line);
        if(line.size()!=0)
        {
            person.first = line.substr(0, line.find(','));
            person.second = line.substr(line.find(',')+1, -1);
            data2.insert(person);
        }
    }
    ofstream out2("task2_output_0.txt");
    out2<<data2.size();
    cout<<"Number of unique users_2 "<<data2.size();
    return 0;
}
