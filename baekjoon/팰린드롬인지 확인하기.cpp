s = input()
flag = False
for i in range(int(len(s)/2)):
    if s[i] != s[len(s)-i-1]:
        flag = True
        break
if flag:
    print(0)
else:
    print(1)

