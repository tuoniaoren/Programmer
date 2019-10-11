import sys
x = sys.stdin.readline().split()
x = int(x[0])

stackData = []
stackMin = []

for _ in range(x):
    s = sys.stdin.readline().split()
    if s[0] == "push":
        data = int(s[1])
        stackData.append(data)
        if len(stackMin) == 0:
            stackMin.append(data)
        elif data > stackMin[-1]:
            stackMin.append(stackMin[-1])
        else:
            stackMin.append(data)
    elif s[0] == "pop":
        stackData.pop()
        stackMin.pop()
    else:
        print(stackMin[-1])