n = input()
n = int(n)
str1 = input()
s = int(str1)
qt = s+1
qt = str(qt)
flag = 0
length = len(str1)

if len(qt) > length:
    flag = 1

if length % n == 0 and flag  == 0:
    a = str1[:n]
    j = a
    k = length//n
    i = 1
    while i < k:
        j = j + a
        i  = i+1
    # print(j)
    # print(str)
    j = int(j)

    if j > s:
        print(j,end='')
    else:
        b = str1[:n]
        c = int(b)
        c = c+1
        # print(type(c))
        c = str(c)
        # c = d
        i = 1
        j1 = c
        print(j1,end='')
        while i < k:
            # j1 = j1 + c
            print(c,end='')
            i  = i+1
        # print(j1)
else:
    k = length//n
    k = k+1
    a = "0"
    j = "1"
    i = 1
    while i < n:
        j = j + a
        i = i+1

    i = 1
    p = j
    print(p,end='')
    while i < k:
        # p = p + j
        print(j,end='')
        i = i+1
    
print('\n')
        

