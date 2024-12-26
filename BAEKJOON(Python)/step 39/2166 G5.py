import sys
input = sys.stdin.readline

N = int(input())
x_vector = []
y_vector = []
for _ in range(N):
    x, y = map(int, input().split())
    x_vector.append(x)
    y_vector.append(y)
x_vector.append(x_vector[0])
y_vector.append(y_vector[0])
sum1, sum2 = 0, 0
for i in range(N):
    sum1 += x_vector[i] * y_vector[i+1]
    sum2 += x_vector[i+1] * y_vector[i]
result = 0.5 * abs(sum1-sum2)
print("{:.1f}".format(result))