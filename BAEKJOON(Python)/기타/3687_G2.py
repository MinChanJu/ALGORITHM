import sys
input = sys.stdin.readline

T = int(input())
inp = [int(input()) for _ in range(T)]

dp = [float("inf")]*101
dp[2] = 1
dp[3] = 7
dp[4] = 4
dp[5] = 2
dp[6] = 0
dp[7] = 8
for i in range(8, 101):
  for j in range(2, i//2+1):
    num1 = str(dp[j]) + str(dp[i-j])
    num2 = str(dp[i-j]) + str(dp[j])
    
    if (num1[0] == "0"): num1 = "6" + num1[1:]
    if (num2[0] == "0"): num2 = "6" + num2[1:]

    dp[i] = min(dp[i], int(num1), int(num2))

for n in inp:
  if (n == 6):
    print("6", end=" ")
  else:
    print(dp[n], end = " ")
  
  if (n%2 == 1):
    print("7"+("1"*((n-3) // 2)))
  else:
    print("1"*(n // 2))