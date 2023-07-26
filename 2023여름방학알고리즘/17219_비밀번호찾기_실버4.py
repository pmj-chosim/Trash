import sys

n, m = map(int, input().split())
site = {}
for i in range(n):
    a, b = input().split()
    site[a] = b

for _ in range(m):  
    query = input()
    print(site.get(query, "Not found"))