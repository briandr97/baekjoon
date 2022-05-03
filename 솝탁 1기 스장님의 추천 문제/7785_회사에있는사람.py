n = int(input())
name = [n]
door = [n]
b = []
for i in n:
    name[i], door[i] = input().split()
    if name[i] in name:
        b.append(name[i])
for i in n:
    if i in b: continue
    else: print(name[i])

