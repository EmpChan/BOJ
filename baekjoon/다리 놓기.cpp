def pacto(n,m=1):
    a=1
    for i in range(m,n+1):
        a*=i
    return a
def combi(n,m):
    return int(pacto(n)/(pacto(n-m)*pacto(m)))
t=int(input())
for i in range(t):
    a=list(input().split())
    print(combi(int(a[1]),int(a[0])))