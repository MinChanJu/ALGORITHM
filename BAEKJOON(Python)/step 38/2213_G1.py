import sys
input = sys.stdin.readline

n = int(input())
weight = [0] + list(map(int,input().split()))
graph = {i:[] for i in range(1,n+1)}
for _ in range(n-1):
    a, b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

visit = [0] * (n + 1)

def get_ans(node):
    visit[node] = 1
    wsum, nwsum = weight[node], 0
    nlist, nnlist = [node], []

    for next in graph[node]:
        if visit[next] == 0:
            sumw, sumnw, listn, listnn = get_ans(next)
            wsum += sumnw
            nlist += listnn
            if sumw > sumnw:
                nwsum += sumw
                nnlist += listn
            else:
                nwsum += sumnw
                nnlist += listnn

    return wsum, nwsum, nlist, nnlist

wa, wb, na, nb = get_ans(1)

if wa > wb:
    print(wa)
    print(*sorted(na))
else:
    print(wb)
    print(*sorted(nb))