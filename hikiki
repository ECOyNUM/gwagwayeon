#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int> >v[20];
vector<int>dist(20,INT_MAX);
vector<int>way[20];
void init(){
    v[1].push_back({2, 9});
    v[1].push_back({7, 14});
    v[2].push_back({3, 8});
    v[3].push_back({4, 15});
    v[3].push_back({8, 9});
    v[4].push_back({5, 10});
    v[4].push_back({6, 9});
    v[5].push_back({9, 16});
    v[5].push_back({13, 8});
    v[6].push_back({9, 3});
    v[7].push_back({14, 10});
    v[8].push_back({9, 9});
    v[8].push_back({10, 5});
    v[9].push_back({11, 3});
    v[10].push_back({11, 8});
    v[10].push_back({14, 8});
    v[10].push_back({15, 6});
    v[11].push_back({12, 8});
    v[11].push_back({15, 5});
    v[12].push_back({13, 8});
    v[13].push_back({17, 10});
    v[14].push_back({15, 11});
    v[14].push_back({16, 16});
    v[15].push_back({16, 11});
    v[15].push_back({17, 17});
    v[16].push_back({18, 8});
    v[17].push_back({18, 10});
    for(int i=1;i<=17;i++){
        for(int j=0;j<v[i].size();j++) {
            int p = v[i][j].first;
            v[p].push_back({i, v[i][j].second});
        }
    }
}

void dijkstra(int s)
{
    priority_queue<pair<int, int> > pq;
    dist[s]=0;
    pq.push({0, s});
    int node, nnode,cost;
    while(!pq.empty())
    {
        node=pq.top().second;
        cost=-pq.top().first;
        pq.pop();
        if(dist[node]<cost)continue;
        for(int i=0;i<v[node].size();i++)
        {
            nnode=v[node][i].first;
            if(dist[nnode]>dist[node]+v[node][i].second)
            {
                way[nnode].clear();
                way[nnode].push_back(node);
                dist[nnode]=dist[node]+v[node][i].second;
                pq.push({-dist[nnode], nnode});
            }
        }
    }
}
int main() {
    int start,End;
    init();
    scanf("%d %d",&start,&End);
    dijkstra(start);
    printf("%d\n",dist[End]);
    int now;
    now=End;
    while(1)
    {
        printf("%d ",now);
        now=way[now][0];
        if(now==1)break;
    }


    return 0;
}
