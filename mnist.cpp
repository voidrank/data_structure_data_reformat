#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

#define _1 first
#define _2 second

#define eps 1e-8

#define sqr(x) ((x)*(x))


using namespace std;


typedef pair<double, double> point;


const int N = 1000000;

int n, m, cnt;

vector<int> e[N];
map<int, int> st;
point pos[N];

double dis[N];
priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > Q;


double cal_dis(const point& a, const point& b) {
    return sqrt(sqr(a._1 - b._1) + sqr(a._2 - b._2));
}


int main() {

    // nds
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int id;
        double lat, lon;
        scanf("%d%lf%lf", &id, &lat, &lon);
        st[id] = cnt;
        pos[cnt] = make_pair(lat, lon);
        cnt++;
    }

    // egs
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        x = st[x];
        y = st[y];
        e[x].push_back(y);
        e[y].push_back(x);
    }

    for (int i = 0; i < n; ++i)
        dis[i] = 1e9;


    // find a relative node
    int id = 0;
    for (int i = 0; i < n; ++i)
        if (e[i].size() > 0) {
            id = i;
            break;
        }
    dis[id] = 0;
    Q.push(make_pair(0, id));


    // dij with heap
    for ( ; !Q.empty(); Q.pop()) {

        double cdis = Q.top()._1;
        int cid = Q.top()._2;
        
        if (abs(cdis - dis[cid]) > eps)
            continue;

        for (int i = 0; i < e[cid].size(); ++i) {
            double temp = cdis + cal_dis(pos[cid], pos[e[cid][i]]);
            if (temp < dis[e[cid][i]]) {
                dis[e[cid][i]] = temp;
                Q.push(make_pair(temp, e[cid][i]));
            }
        }
    }

    for (int i = 0; i < n; ++i)
        if (dis[i] < 1e7)
            printf("%d %.5f\n", i, dis[i]);
    

    return 0;
}
