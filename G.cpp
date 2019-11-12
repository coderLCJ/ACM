#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3+10;
const int INF = 1e9+10;

struct Node
{
    int to;
    int dis;
    bool operator < (const Node& that) const
    {
        return this->dis > that.dis;
    }
};

int Map[MAXN][MAXN];
int Dis[MAXN];
int Poi[MAXN];
int Vis[MAXN];
int v, e, s, k, c;

int Dij(int S)
{
    for (int i = 1;i <= v;i++)
        Dis[i] = INF;
    memset(Vis, 0, sizeof(Vis));
    Dis[S] = 0;
    priority_queue<Node> que;
    que.push(Node{S, 0});
    while (!que.empty())
    {
        int node = que.top().to;
        que.pop();
        if (Vis[node] == 1)
            continue;
        Vis[node] = 1;
        for (int i = 1;i <= v;i++)
        {
            if (Vis[i] == 1)
                continue;
            if (Dis[i] > Dis[node]+Map[node][i])
            {
                Dis[i] = Dis[node]+Map[node][i];
                que.push(Node{i, Dis[i]});
            }
        }
    }
    int maxlen = 0;
    for (int i = 1;i <= v;i++)
        maxlen = max(maxlen, Dis[i]);
    return maxlen;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d%d", &v, &e, &s, &k, &c);
        for (int i = 1;i <= k;i++)
            scanf("%d", &Poi[i]);
        for (int i = 1;i <= v;i++)
        {
            for (int j = 1;j <= v;j++)
            {
                if (i == j)
                    Map[i][j] = 0;
                else
                    Map[i][j] = Map[j][i] = INF;
            }
        }
        int l, r, w;
        for (int i = 1;i <= e;i++)
        {
            scanf("%d%d%d", &l, &r, &w);
            if (w < Map[l][r])
                Map[l][r] = Map[r][l] = w;
        }
        int sup = Dij(s);
//        for (int i = 1;i <= v;i++)
//            cout << Dis[i] << ' ' ;
//        cout << endl;
        int point = 0;
        for (int i = 1;i <= k;i++)
            point = max(point, Dij(Poi[i]));
        if (sup <= point*c)
            printf("%d\n", sup);
        else
            printf("%d\n", point);
    }
    return 0;
}
