import sys

n = sys.stdin.readline().strip()
x = int(n[0])
data1 = []
data2 = []

for _ in range(x):
    w = sys.stdin.readline().strip()
    S = w.split()
    if S[0] == "add":
        data1.append(int(S[1]))
    elif S[0] == "poll":
        m = len(data2)
        if m == 0:
            while len(data1) != 0:
                data2.append(data1.pop())
        data2.pop()
    else:
        m = len(data2)
        if m == 0:
            while len(data1) != 0:
                data2.append(data1.pop())
        print(data2[-1])

