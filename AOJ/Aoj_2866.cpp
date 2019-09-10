#include<bits/stdc++.h>
using namespace std;
#define MAXSIZE 10001
#define MAXOUTSIZE MAXSIZE * 2 + 1
int main()
{
    char a[MAXSIZE] = {'0'},
         b[MAXSIZE] = {'0'},
         c[MAXOUTSIZE] = {'\0'};
    int a_int[MAXSIZE] = {0},
        b_int[MAXSIZE] = {0},
        c_int[MAXOUTSIZE] = {0};
    cin >> a;
    cin >> b;

    int len_a = strlen(a), len_b = strlen(b);
    memset(a_int, 0, sizeof a_int);
    memset(b_int, 0, sizeof b_int);
    memset(c_int, 0, sizeof c_int);

    for (int i = len_a - 1, j = 0; i >= 0; i--, j++)
    {
        a_int[j] = a[i] - '0';
    }
    for (int i = len_b - 1, j = 0; i >= 0; i--, j++)
    {
        b_int[j] = b[i] - '0';
    }

    for (int i = 0; i < len_a; i++)
    {
        for (int j = 0; j < len_b; j++)
        {
            c_int[i + j] += a_int[i] * b_int[j];
        }
    }
    int ans_len = 0;
    for (int i = 0; i < 2 * MAXSIZE; i++)
    {
        c_int[i + 1] += c_int[i] / 10;
        c_int[i] %= 10;
        ans_len = i;
    }
    while (c_int[ans_len] == 0)
    {
        ans_len--;
    }

    if (ans_len < 0)
    {
        cout << "0";
        return 0;
    }

    for (int i = ans_len; i >= 0; i--)
    {
        c[i] = c_int[i] + '0';
    }

    for (int i = MAXOUTSIZE - 1; i >= 0; i--)
    {
        if ('\0' != c[i])
        {
            cout << c[i];
        }
    }

    return 0;
}
