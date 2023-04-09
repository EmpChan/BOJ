a = list(map(int,input().split()))

if a[0] == a[1] and a[1] == a[2]:
    print(a[0]*1000+10000)
elif a[0] == a[1] or a[1]==a[2] or a[0]==a[2]:
    if a[0] == a[1]:
        print(a[0]*100+1000)
    elif a[1] == a[2]:
        print(a[1] *100+1000)
    else:
        print(a[0]*100+1000)
else:
    print(max(a)*100)