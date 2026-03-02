import sys
input = sys.stdin.readline

N = int(input())
K = int(input())
sensors = list(map(int, input().split()))
sensors.sort()

if N <= K:
    print(0)
    sys.exit(0)

diff = [sensors[i+1] - sensors[i] for i in range(N-1)]
diff.sort(reverse=True)

print(sensors[-1] - sensors[0] - sum(diff[:K-1]))