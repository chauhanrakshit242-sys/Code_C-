#include <bits/stdc++.h>
using namespace std;

bool check(int n, int k, string &s, vector<int> &a, int x)
{
    int segments = 0;
    int i = 0;

    while(i < n)
    {
        if(s[i] == 'R' && a[i] > x)
        {
            i++;
            continue;
        }

        bool needBlue = false;

        while(i < n && !(s[i] == 'R' && a[i] > x))
        {
            if(s[i] == 'B' && a[i] > x)
                needBlue = true;
            i++;
        }

        if(needBlue)
            segments++;
    }

    return segments <= k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];

        int l = 0, r = 1e9;
        int ans = 1e9;

        while(l <= r)
        {
            int mid = l + (r - l) / 2;

            if(check(n, k, s, a, mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}