#include <iostream>

using namespace std;

string nlist[100000];
int c = 0;
void sep(string a)
{
    string cup="";
    for (int i = 1; i < a.length()-1; i++)
    {
        if (a[i] != ',')
            cup += a[i];
        else
        {
            nlist[c++] = cup;
            cup = "";
        }
    }
    nlist[c] = cup;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        int s = 0, e = 0, r = 0, n, d = 0;
        string inp;
        cin >> inp;
        cin >> n;
        string nums;
        cin >> nums;
        c = 0;
        for (auto i : inp)
        {
            if (i == 'R')
            {
                r++;
            }
            else
            {
                d++;
                if (r % 2 == 0)
                {
                    s ++;
                }
                else
                {
                    e ++;
                }
            }
        }
        sep(nums);
        if (d > n)
            cout << "error" << '\n';
        else
        {
            cout << '[';
            if (r % 2 == 0)
            {
                for (int i = s; i <= c - e; i++)
                {
                    if (i != c - e)
                        cout << nlist[i] << ',';
                    else
                        cout << nlist[i];
                }
            }
            else
            {
                for (int i = c - e; i >= s; i--)
                {
                    if (i != s)
                        cout << nlist[i] << ',';
                    else
                        cout << nlist[i];
                }
            }
            cout << ']' << '\n';
        }
    }

    return 0;
}