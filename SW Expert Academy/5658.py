import sys
input = sys.stdin.readline

dic = { "0" : 0, "1" : 1, "2" : 2, "3" : 3, "4" : 4, "5" : 5, "6" : 6, "7" : 7, "8" : 8, "9" : 9, "A" : 10, "B" : 11, "C" : 12, "D" : 13, "E" : 14, "F" : 15}

T = int(input())
answer = []
for tc in range(T):
    N, K = map(int, input().split())
    num = input().rstrip()
    ans = []
    c = N // 4
    for i in range(c):
        for j in range(i, N, c):
            if (j+c >= N): ans.append(num[j:j+c]+num[:j+c-N])
            else: ans.append(num[j:j+c])
    ans = list(set(ans))
    ans.sort(reverse=True)
    sum = 0
    for i in range(c):
        sum += dic[ans[K-1][i]]*16**(c-1-i)

    answer.append(f"#{tc+1} {sum}")
print(*answer, sep="\n")