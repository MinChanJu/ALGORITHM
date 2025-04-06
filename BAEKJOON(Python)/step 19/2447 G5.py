def star(N):
    if N == 3:
        stars = ["***", "* *", "***"]
        return stars
    updated_stars = [x * 3 for x in star(N//3)]+[x + (" " * (N//3)) + x for x in star(N//3)]+[x * 3 for x in star(N//3)]
    return updated_stars

N = int(input())
print(*star(N), sep="\n")