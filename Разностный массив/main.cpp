// https://algocourses.ru/files/course_bp2024/contest-44337-ru.pdf
// Задача: D

#include <iostream>
#include <vector>

using namespace std;

#define int long long

vector<int> x[1000006];
vector<int> ps[1000006];

int32_t main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 0; i <= n + 2; i++)
    {
        for (int j = 0; j <= m + 2; j++)
        {
            x[i].push_back(0);
            ps[i].push_back(0);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int lx, ly, rx, ry, d;
        cin >> lx >> ly >> rx >> ry >> d;
        x[lx][ly] += d;
        x[rx + 1][ry + 1] += d;
        x[rx + 1][ly] -= d;
        x[lx][ry + 1] -= d;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ps[i][j] = x[i][j];
            ps[i][j] += ps[i - 1][j];
            ps[i][j] += ps[i][j - 1];
            ps[i][j] -= ps[i - 1][j - 1];
            cout << ps[i][j] << " ";
        }
        cout << "\n";
    }
}
