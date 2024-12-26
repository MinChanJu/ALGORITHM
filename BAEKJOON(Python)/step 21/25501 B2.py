import sys
input=sys.stdin.readline

def isPalindrome(s,k):
    return recursion(s, 0, len(s)-1, k)

def recursion(s, l, r, k):
    k+=1
    if l >= r:
        return 1,k
    elif s[l] != s[r]:
        return 0,k
    else:
        return recursion(s, l+1, r-1, k)

T=int(input())
for _ in range(T):
    S=input().strip()
    print(isPalindrome(S,0)[0],isPalindrome(S,0)[1])