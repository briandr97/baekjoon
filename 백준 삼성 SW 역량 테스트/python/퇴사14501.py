days=int(input())
board=[]
dp=[]
for i in range(days):
    board.append(list(map(int, input().split())))
    dp.append(0)
dp.append(0)

for i in range(days+1):
    if i: dp[i]=max(dp[i], dp[i-1])
    if i<days:
        next = i + board[i][0]
        if next<=days:
            dp[next]=max(dp[next], dp[i]+board[i][1])

print(dp[days])
