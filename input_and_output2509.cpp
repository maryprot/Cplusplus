#include <iostream>
#include <set>
#include <random>
#include <fstream> 
#include <vector>
#include <string>

using namespace std;

class Data
{
private:
    string caller;
    int money;
    string caller_get;
public:
    Data() : caller("79100017821"), money(0), caller_get("79100017821") {}
    friend ifstream& operator >> (ifstream& in, Data& data)
    {
        string str;
        getline(in, str);
        if (str.length() < 1) return in;
        data.caller = str.substr(0, 11);
        data.caller_get = str.substr(12, 11);
        data.money = stoi(str.substr(24));
        return in;
    }
    friend ostream& operator << (ostream& out, Data& data)
    {
        cout << data.caller << " " << data.caller_get << " " << data.money << endl;
        return out;
    }
    string const get_caller()
    {
        return this->caller;
    }
    int const get_money()
    {
        return this->money;
    }
};

class User
{
private:
    string number;
    int money;
public:
    User() : number("79100017821"), money(0){}
    void set_number(string number)
    {
        this->number = number;
    }
    string const get_number()
    {
        return this->number;
    }
    int const get_money()
    {
        return this->money;
    }
    void add_money(int money)
    {
        this->money += money;
    }
};


int main() 
{
    ifstream file;
    file.open("./input_file.txt");
    vector<User> users;
    while (!file.eof())
    {
        Data data;
        file >> data;
        User user;
        string caller = data.get_caller();
        int money = data.get_money();
        bool flag = false;
        for (int i=0; i < users.size(); i++)
        {
            if (users[i].get_number() == caller)
            {
                users[i].add_money(money);
                flag = true;
            }
        }
        if (flag == false)
        {
            user.set_number(caller);
            user.add_money(money);
            users.push_back(user);
        }
    }
    file.close();
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].get_money() << endl;
    }
    int max = 0;
    for (int i = 0; i < users.size(); i++)
    {
        if (max < users[i].get_money())
        {
            max = users[i].get_money();
        }
    }
    cout << "MAX " << max;
    return 0;
}
