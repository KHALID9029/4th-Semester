#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

const int N=1e5;
const int INF=1e9+10;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

void dfs(int x,int y,vector<vector<char>>&a,vector<vector<int>>&vis)
{
    vis[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=a.size()||ny<0||ny>=a[0].size()) continue;
        if(vis[nx][ny]||a[nx][ny]=='#') continue;
        dfs(nx,ny,a,vis);
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    vector<vector<char>>a(n,vector<char>(m));
    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];

    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='.'&&!vis[i][j])
            {
                dfs(i,j,a,vis);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}