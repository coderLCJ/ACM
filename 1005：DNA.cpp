#include<iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << 'X';
        for (int i = 0; i<a - 2; i++)
            cout << ' ';
        cout << 'X' << endl;
        while (b--)
        {
            int p = a - 4, k = 1, T = a / 2 - 1;
            while (T--)
            {
                for (int i = 0; i<k; i++)
                    cout << ' ';
                cout << 'X';
                for (int i = 0; i<p; i++)
                    cout << ' ';
                cout << 'X' ;
                for (int i = 0; i<k; i++)
                    cout << ' ';
                cout << endl;
                p -= 2;
                k++;
            }
            for (int i = 0; i<k; i++)
                cout << ' ';
            cout << 'X' ;
            for (int i = 0; i<k; i++)
                cout << ' ';
            cout << endl;
            p = 1, k = a/2-1, T = a / 2;
            while (T--)
            {
                for (int i = 0; i < k; i++)
                    cout << ' ';
                cout << 'X';
                for (int i = 0; i < p; i++)
                    cout << ' ';
                cout << 'X';
                for (int i = 0; i<k; i++)
                    cout << ' ';
                cout << endl;
                p += 2;
                k--;
            }
        }
    }
}
