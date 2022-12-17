#include <iostream>

using namespace std;

char line[550000];

int get_n(int n)
{
    int i = 1;
    for (int j = 0; j < n; j++)
    {
        i *= 3;
    }
    return i;
}
void voidit(int s, int n)
{
    //cout << s << "\n";
    if (n <= 1)
        return;
    int cup = n / 3;
    for (int i = s + cup + 1; i <= s + cup + cup; i++)
    {
        line[i] = ' ';
    }
    voidit(s, cup);
    voidit(s + cup * 2, cup);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int q;
    while (true)
    {
        cin >> q;
        if (cin.eof()) {
            break;
        }
        q = get_n(q);
        for (int i = 1; i <= q; i++)
        {
            line[i] = '-';
        }
        voidit(0, q);
        for (int i = 1; i <= q; i++)
        {
            cout << line[i];
        }
        cout << '\n';
    }

    return 0;
}