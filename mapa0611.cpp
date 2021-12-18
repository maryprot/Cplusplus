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

template<typename T, typename U>
ostream& operator<<(ostream& out, const map<T, U> mapa)
{
    for(auto data: mapa)
    {
        out<<data.first<<" "<<data.second<<endl;
    }
    return out;
}

int main()
{
    // task_1
    map<string, int> data;
    ifstream in1("task1_input.txt");
    while (in1)
    {
        string tmp;
        in1 >> tmp;
        if (tmp!="")
        {
            data[tmp]++;
        }
    }
    ofstream out_1("task1_output.txt");
    auto iter_1 = max_element(data.begin(), data.end(),
                  [] (const pair<string, int>& map1, const pair<string, int>& map2)
                  {return map1.second<map2.second;});
    out_1<<iter_1->first<<" "<<iter_1->second;
    // task_2
    set<string> spamers;
    ifstream spam_in("task2_inputspam.txt");
    while(spam_in)
    {
        string tmp;
        spam_in>>tmp;
        if (tmp!="")
        {
            spamers.insert(tmp);
        }
    }
    map<string, int> people;
    ifstream calls_in("task2_inputcalls.txt");
    while(calls_in)
    {
        string tmp;
        calls_in >> tmp;
        if (tmp!="")
        {
            string caller = tmp.substr(0, tmp.find(","));
            tmp = tmp.substr(tmp.find(",")+1, -1);
            string human = tmp.substr(0, tmp.find(","));
            int time = stoi(tmp.substr(tmp.rfind(",")+1, -1));
            if(spamers.count(caller)!=0)
            {
                people[human]+=time;
            }
            spamers.insert(tmp);
        }
    }
    auto iter_2 = max_element(people.begin(), people.end(),
                            [](const pair<string, int>& map1, const pair<string, int>& map2)
                            {return map1.second<map2.second;});
    fstream out_2("task2_output.txt");
    out_2<<iter_2->first<<" "<<iter_2->second;
    return 0;
}
