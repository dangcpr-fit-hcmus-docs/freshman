// Bai02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int SoTu(string s)
{
    int SoTu = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            SoTu++;
            for (int j = i; j < s.size(); j++)
            {
                i = j;
                if ((s[j] < 'A' || s[j] > 'Z') && (s[j] < 'a' || s[j] > 'z'))
                {
                    break;
                }
            }
        }
    }
    return SoTu;
}
string ChuanHoaChuoi(string s)
{
    string t;
    int i = 0;
    while (s[0] == ' ')
    {
        s.erase(s.begin());
    }
    while (s[s.size() - 1] == ' ')
    {
        s.erase(s.begin() + s.size() - 1);
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (i == s.size() - 1)
        {
            t += s[s.size() - 1];
        }
        else
        {
            if (s[i] != ' ' || s[i + 1] != ' ')
            {
                t += s[i];
            }
        }
    }
    return t;
}
int main()
{
    string s = "  Hoi  thuoc ,  ththt    ";
    cout << SoTu(s) << endl;
    cout << ChuanHoaChuoi(s);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
