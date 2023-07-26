import sys
global visited

def dfs(u,n):
    visited[u]=1
    for i in range(n):
        if graph[u][i]==1 and visited[i]==0:
            dfs(i, n)


n=int(sys.stdin.readline())
m=int(sys.stdin.readline())
graph=[[0 for x in range(n)] for x in range(n)]

for k in range(m):
    i,j=map(int, sys.stdin.readline().split())
    graph[i-1][j-1]=graph[j-1][i-1]=1

visited =[0 for x in range(n)]
dfs(0,n)
print(visited.count(1)-1)
