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
using namespace std;


int main()
{
    ifstream in("input.txt");
    set<string> data;
    vector<string> v;
    vector<string> spamer;
    vector<string> pearson;

    copy(istream_iterator<string>(in), istream_iterator<string>(), inserter(v, v.end()));
    int i=0;
    transform(v.begin(), v.end(),
                    v.begin(),[&i, &spamer, &pearson](string str)
              {
              if(i%2==0)
              {
                  spamer.push_back(str);
                  i++;
              }
              else
              {
                  pearson.push_back(str);
                  i++;
              }
                  return str;
              });
    auto iter = pearson.begin();
    i=0;
    transform(spamer.begin(), spamer.end(),
              spamer.begin(),[&i, &pearson, &data](string str)
              {if(str.substr(0,4)=="7800")
              {
                  data.insert(pearson[i]);
                  i++;
              }else {i++;}
              return str;
              });
    ofstream out("output.txt");
    out<<data.size();
    return 0;
}
