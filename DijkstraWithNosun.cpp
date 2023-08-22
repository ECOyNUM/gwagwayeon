#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int> >v[20];
int start,End;
int nosun[20][5],cur,cnt;
vector<int>dist(20,INT_MAX);
vector<int> route[1000];
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
    nosun[1][1]=1;
    nosun[2][1]=1;
    nosun[3][1]=1, nosun[3][3]=1;
    nosun[4][1]=1, nosun[4][3]=1;
    nosun[5][1]=1, nosun[5][4]=1;
    nosun[6][3]=1;
    nosun[7][1]=1;
    nosun[8][3]=1, nosun[8][4]=1;
    nosun[9][3]=1, nosun[9][4]=1;
    nosun[10][1]=1, nosun[10][3]=1, nosun[10][4]=1;
    nosun[11][1]=1, nosun[11][3]=1;
    nosun[12][1]=1;
    nosun[13][1]=1, nosun[13][4]=1;
    nosun[14][1]=1, nosun[14][4]=1;
    nosun[15][2]=1, nosun[15][3]=1, nosun[15][4]=1;
    nosun[16][2]=1, nosun[16][4]=1;
    nosun[17][2]=1, nosun[17][4]=1;
    nosun[18][2]=1, nosun[18][4]=1;

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

void fin(int now, int cnt, int prev)
{

    for(int i=1;i<=4;i++)
    {
        if(nosun[now][i]&&nosun[prev][i])
        {
            route[cur].push_back(i);
            if(now!=start)
            fin(way[now][0], 0, now);
            for(int j=0;j<route[cur].size()-1;j++)
            {
                route[cur+1].push_back(route[cur][j]);
            }
            cur++;
        }
    }
}

int main() {

    init();
    scanf("%d %d",&start,&End);
    dijkstra(start);
    printf("%d\n",dist[End]);
    int now;
    now=End;
    fin(way[now][0], 0, End);
    while(1)
    {
        printf("%d\n", now);
        now=way[now][0];
        cnt++;
        if(now==start)break;
    }

    printf("%d\n", cur);
    for(int i=0;i<=cur;i++)
    {
        if(route[i].size()==cnt){
            for(int j=0;j<route[i].size();j++)
                printf("%d ", route[i][j]);
        printf("\n");
        }
    }
    /*if(nosun[End][1])
    findroute(way[now][0], 0, End);
    if(nosun[End][2])
    findroute(way[now][0], 0, 2);
    if(nosun[End][3])
    findroute(way[now][0], 0, 3);
    if(nosun[End][4])
    findroute(way[now][0], 0, 4);*/


    return 0;
}
