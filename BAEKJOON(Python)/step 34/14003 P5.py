import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int,input().split()))
LIS = [A[0]]
dp = [1]*N
length = 0
length_i = 0
for i in range(1,N):
    if LIS[-1] < A[i]:
        LIS.append(A[i])
        dp[i] = len(LIS)
    else:
        s = 0
        e = len(LIS)-1
        while s<=e:
            mid = (s+e)//2
            if LIS[mid] < A[i]:
                s = mid + 1
            else:
                e = mid - 1
        LIS[s] = A[i]
        dp[i] = s+1

    if dp[i] > length:
        length_i = i
        length = dp[i]
LIS = [A[length_i]]
for i in range(length_i, -1, -1):
    if dp[i] == dp[length_i] - 1 and A[i] < A[length_i]:
        LIS.append(A[i])
        length_i = i
print(len(LIS))
LIS.reverse()
print(*LIS)