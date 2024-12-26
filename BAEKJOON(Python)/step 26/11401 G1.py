import sys
input=sys.stdin.readline
MOD = 1000000007
def nCrModP(n, r, p):
    if r == 0:
        return 1
    fact = [0] * (n + 1)
    fact[0] = 1
    for i in range(1, n + 1):
        fact[i] = (fact[i - 1] * i) % p
    def modInverse(x, p):
        return pow(x, -1, p)
    return (fact[n] * modInverse(fact[r], p) * modInverse(fact[n - r], p)) % p
n,k=map(int,input().split())
if k>n//2:
    k=n-k
result = nCrModP(n, k, MOD)
print(result)