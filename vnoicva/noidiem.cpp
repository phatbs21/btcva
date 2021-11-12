#include <bits/stdc++.h>
using namespace std;
//██████╗░░█████╗░██████╗░██████╗░░█████╗░████████╗████████╗░█████╗░░██████╗
//██╔══██╗██╔══██╗██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██╔══██╗██╔════╝
//██████╔╝███████║██████╔╝██████╔╝██║░░██║░░░██║░░░░░░██║░░░██║░░██║╚█████╗░
//██╔═══╝░██╔══██║██╔══██╗██╔══██╗██║░░██║░░░██║░░░░░░██║░░░██║░░██║░╚═══██╗
//██║░░░░░██║░░██║██║░░██║██║░░██║╚█████╔╝░░░██║░░░░░░██║░░░╚█████╔╝██████╔╝
//╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░░░╚═╝░░░░░░╚═╝░░░░╚════╝░╚═════╝░
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k = 0;
    vector<int> p(1000009, 0), f(1000009, 0), b(1000009, 0);
    cin >> n;
    p[n + 1] = n + 1;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
    {
        f[i] = lower_bound(b.begin() + 1, b.begin() + k + 1, p[i]) - b.begin();
        k = max(k, f[i]);
        b[f[i]] = p[i];
    }
    cout << k << "\n";
    vector<int> t;
    int truy = k;
    for (int i = n; i >= 1; i--)
        if (f[i] == truy)
        {
            t.push_back(p[i]);
            truy--;
        }
    int i = t.size();
    while (i--)
        cout << t[i] << " ";
}
