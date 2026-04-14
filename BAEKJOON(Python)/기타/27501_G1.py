import sys
input = sys.stdin.readline

N = int(input())
graph = [[] for _ in range(N + 1)]
for _ in range(N-1):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

beauty = [[0, 0, 0]]
for _ in range(N):
    beauty.append(list(map(int, input().split())))

parent = [0] * (N + 1)
order = []
parent[1] = -1
stack = [1]

while stack:
    node = stack.pop()
    order.append(node)
    
    for n_node in graph[node]:
        if n_node == parent[node]: continue
        parent[n_node] = node
        stack.append(n_node)

dp = [[0, 0, 0] for _ in range(N + 1)]
for node in reversed(order):
    dp[node][0] = beauty[node][0]
    dp[node][1] = beauty[node][1]
    dp[node][2] = beauty[node][2]

    for n_node in graph[node]:
        if n_node == parent[node]:
            continue
        dp[node][0] += max(dp[n_node][1], dp[n_node][2])
        dp[node][1] += max(dp[n_node][0], dp[n_node][2])
        dp[node][2] += max(dp[n_node][0], dp[n_node][1])

result = max(dp[1])

if dp[1][0] >= dp[1][1] and dp[1][0] >= dp[1][2]: root_color = 0
elif dp[1][1] >= dp[1][0] and dp[1][1] >= dp[1][2]: root_color = 1
else: root_color = 2

rgb_r = ["R", "G", "B"]
answer = [''] * (N + 1)
stack = [(1, root_color)]

while stack:
    node, color = stack.pop()
    answer[node] = rgb_r[color]

    for n_node in graph[node]:
        if n_node == parent[node]: continue

        if color == 0:
            if dp[n_node][1] >= dp[n_node][2]: stack.append((n_node, 1))
            else: stack.append((n_node, 2))

        elif color == 1:
            if dp[n_node][0] >= dp[n_node][2]: stack.append((n_node, 0))
            else: stack.append((n_node, 2))

        else:
            if dp[n_node][0] >= dp[n_node][1]: stack.append((n_node, 0))
            else: stack.append((n_node, 1))

print(result)
print(''.join(answer[1:]))
