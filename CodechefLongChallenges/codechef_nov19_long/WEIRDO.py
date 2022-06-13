def vow(a):
    return (a == 'a' or a == 'e' or a == 'i' or a == 'u' or a == 'o')


t = input()
t = int(t)
while t > 0:
    t -= 1
    l = input()
    l = int(l)
    chefa = []
    chefb = []
    for i in range(l):
        st = input()
        prev = -1
        p = len(st)
        flag = 0
        for j in range(p):
            c = vow(st[j])
            if c == 0:
                if prev != -1:
                    if j - prev <= 2:
                        flag = 1
                        break

                prev = j

        if flag == 1:
            chefb.append(st)
        else:
            chefa.append(st)

    for st in chefa:
        p = len(chefa)
        nw = []
        cnt = []
        for i in range(26):
            nw.append(0)
            cnt.append(0)

        for i in range(p):
            nw[st[i]] += 1
            cnt[st[i]] += 1
