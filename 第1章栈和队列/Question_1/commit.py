import sys
n = int(input())
s = []
for i in range(n):
    op = sys.stdin.readline().split()
    if(op[0] == "push"):
        s.append(int(op[1]))
    if(op[0] == "pop"):
        s.pop()
    if(op[0] == "getMin"):
        print(min(s))
