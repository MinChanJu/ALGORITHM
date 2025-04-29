n, m = map(int, input().split())
ls = []
def product(start):
    if len(ls) == m:
        print(' '.join(map(str, ls)))
        return
    for i in range(start, n + 1):
        ls.append(i)
        product(i)
        ls.pop()
product(1)