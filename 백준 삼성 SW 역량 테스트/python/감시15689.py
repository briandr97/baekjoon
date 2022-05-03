#글로벌 변수들 선언
import copy
board=[]
cctv=[]
dx=[0,1,0,-1]
dy=[-1,0,1,0]

def out(x,y):
    if x<0 or x>=n or y<0 or y>=m:
        return True
    else:
        return False

def move(x,y,direction):
    d = direction%4
    nx,ny=x,y
    while(True):
        nx += dx[d]
        ny += dy[d]
        if out(nx,ny) or boardCopy[nx][ny]==6:
            break
        elif boardCopy[nx][ny]!=0:
            continue
        else:
            boardCopy[nx][ny]=7

#main
n,m=map(int,input().split())
ans=0
for i in range(n):
    board.append(list(map(int,input().split())))
    for j in range(m):
        if board[i][j]!=0 and board[i][j]!=6:
            cctv.append([i,j,board[i][j]])
        if board[i][j]==0:
            ans+=1

for i in range(1<<(2*len(cctv))):
    boardCopy=copy.deepcopy(board)
    temp = i
    for j in range(len(cctv)):
        d=temp%4
        temp//=4
        x, y, k = cctv[j][0], cctv[j][1], cctv[j][2]
        if k==1:
            move(x,y,d)
        elif k==2:
            move(x,y,d)
            move(x,y,d+2)
        elif k==3:
            move(x,y,d)
            move(x,y,d+1)
        elif k==4:
            move(x,y,d)
            move(x,y,d+1)
            move(x,y,d+2)
        else:
            move(x,y,d)
            move(x,y,d+1)
            move(x,y,d+2)
            move(x,y,d+3)
    c=0
    for a in range(n):
        for b in range(m):
            if boardCopy[a][b]==0:
                c+=1
    ans=c if c<ans else ans

print(ans)
