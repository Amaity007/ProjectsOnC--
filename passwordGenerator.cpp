// #include<bits/stdc++.h>     //[We can also use this all in one library instead of using different individual library]
#include <iostream>
#include <random>
#include <string>
#include <ctime>
using namespace std;
string getPassword(int length)
{
    string password = "";
    string Char = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@#$*123456789";
    mt19937_64 rng(time(nullptr));
    uniform_int_distribution<int> dist(0, Char.size() - 1);

    for (int i = 0; i < length; ++i)
    {
        password += Char[dist(rng)];
    }

    return password;
}

int main()
{
    int ln;
    cout << "What will be the length of the password: ";
    cin >> ln;

    string pswd = getPassword(ln);
    cout << "Password Generated: " << endl;
    cout << pswd << endl;

    return 0;
}
