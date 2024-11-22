// https://algocourses.ru/files/course_bp2024/contest-45800-ru.pdf
// Задача: A

#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <deque>

#define int long long
#define INF INT_MAX
#define mk(a, b) make_pair(a, b)
#define opt                      \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);            \
    cout.tie(nullptr)
#define MAXN 100001

using namespace std;

int input[MAXN];
pair<int, int> tree[MAXN * 4 + 40];

pair<int, int> ownmax(pair<int, int> a, pair<int, int> b)
{
    if (a.first > b.first)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void modify(int v, int tl, int tr, int pos, int val)
{
    if (tl == tr)
    {
        tree[v].first = val;
        tree[v].second = pos;
        return;
    }
    int sr = (tl + tr) / 2;
    if (pos <= sr)
    {
        modify(v * 2, tl, sr, pos, val);
    }
    else
    {
        modify(v * 2 + 1, sr + 1, tr, pos, val);
    }
    tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}

pair<int, int> get(int v, int tl, int tr, int l, int r)
{
    if (l > r)
        return mk(-INF, 0);
    if (l == tl && r == tr)
        return tree[v];
    int sr = (tl + tr) / 2;
    return ownmax(get(v * 2, tl, sr, l, min(r, sr)), get(v * 2 + 1, sr + 1, tr, max(l, sr + 1), r));
}

int32_t main()
{
    opt;
    int N, K;
    cin >> N;
    for (int i = 0; i <= 4 * N + 40 - 1; i++)
    {
        tree[i].first = -INF;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> input[i];
    }
    for (int i = 1; i <= N; i++)
    {
        modify(1, 1, N, i, input[i]);
    }
    cin >> K;
    for (int i = 1; i <= K; i++)
    {
        int l, r;
        cin >> l >> r;
        pair<int, int> answer = get(1, 1, N, l, r);
        cout << answer.first << " " << answer.second << "\n";
    }
}