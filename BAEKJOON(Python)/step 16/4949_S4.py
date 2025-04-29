import sys
input=sys.stdin.readline
while 1:
    a=input()
    if a[0]=='.':
        break
    for i in a:
        if i not in "()[]":
            a=a.replace(i,'')
    while '[]'in a or '()'in a:
        a=a.replace('[]','')
        a=a.replace('()','')
    if len(a)==0:
        print("yes")
    else:
        print("no")