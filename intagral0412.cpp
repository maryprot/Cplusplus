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
#include <thread>
#include <mutex>
using namespace std;

double func(double x)
{
    return exp(-x*x/2);
}

void calc(double a, double b, long long n, double& s)
{
    double quant=(b-a)/n;
    for(int i=0; i<n; i++)
    {
        s+=(func(a+i*quant)+func(a+(i+1)*quant))/2*quant;
    }
}
pair<double, double> integrate(long long bins, int num_threads, double first, double second)
{
    auto start = chrono::system_clock::now();
    vector<thread> ths;
    vector<double> results(num_threads, 0);
    double leng = second - first;
    for(int i=0; i<num_threads; i++)
    {
        thread th(calc, first+i*leng/num_threads, first+(i+1)*leng/num_threads, bins/num_threads, std::ref(results[i]));
        ths.push_back(move(th));
    }
    for(int i=0; i<ths.size(); i++)
    {
        ths[i].join();
    }
    double integral=0;
    for(int i=0; i<results.size(); i++)
    {
        integral+=results[i];
    }
    auto end = chrono::system_clock::now();
    pair<double, double> answer(integral/sqrt(2*M_PI), chrono::duration_cast<chrono::microseconds>(end-start).count());
    return answer;
}

int main()
{
    long long bins;
    int num_threads;
    bool debug=false;
    if(debug)
    {
        for(int i=1; i<=100; i++)
        {
            num_threads = i;
            bins = pow(10,5);
            double first = -0.5;
            double second = 0.5;
            pair<double, double> answer = integrate(bins, num_threads, first, second);
            cout<<"Answer: "<< answer.first << " Number of threads: " << i <<" Time: " << answer.second << " mcs. "<<endl;
        }
    }
    else
    {
        cin>>num_threads;
        bins = pow(10,5);
        double first = -0.5;
        double second = 0.5;
        pair<double, double> answer = integrate(bins, num_threads, first, second);
        cout<<"Answer: "<< answer.first << " Number of threads: " << num_threads <<" Time: " << answer.second << " mcs. "<<endl;
    }
    return 0;
}

