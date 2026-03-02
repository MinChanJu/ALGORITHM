import sys
input = sys.stdin.readline

N = int(input())
parent = list(map(int, input().split()))

graph = {i: [] for i in range(N)}
for id, pid in enumerate(parent):
    if pid == -1: continue
    graph[pid].append(id)

def delete(id):
    global graph
    
    for cid in graph[id]:
        delete(cid)
    
    del graph[id]

deleteId = int(input())
delete(deleteId)
if parent[deleteId] != -1:
    graph[parent[deleteId]].remove(deleteId)

cnt = 0
for ls in graph.values():
    if len(ls) == 0: cnt += 1

print(cnt)
