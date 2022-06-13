t = int(input())

while(t > 0):
    n = int(input())
    p = int(input())
    v = []
    mp = {}

    for i in range(0, n):
        a = int(input())
        if a in mp.keys():
            mp[a] += 1
        else:
            mp.__setitem__(a, 1)
        v.append(a)

    tmp = mp

    while(1):
        flag = 0
        val1 = 0
        val2 = 0
        mp = tmp
        print(len(tmp))
        tmp = {}
        for key in reversed(sorted(mp.keys())):
            print("a")
            print(key, mp[key])
            if(mp[key] == 0):
                continue
            if(flag == 0):
                val1 += p**key
                mp[key] -= 1
                flag = 1
            else:
                val2 += p**key
                mp[key] -= 1

        for key in mp.keys():
            if(mp[key] != 0):
                tmp.__setitem__(key, mp[key])

        pp = abs(val1-val2)
        # print(val1, val2)
        if(pp != 0):
            if pp in tmp.keys():
                tmp[pp] += 1
            else:
                tmp.__setitem__(pp, 1)

        qq = len(tmp)
        print(qq)
        # for keys in mp.keys():
        #     print(keys, mp[keys])

        if qq <= 1:
            flagg = 1
            break

    ans = 0
    for keys in mp.keys():
        ans += p**(keys*mp[keys])

    # print(ans)
    ans %= 1e9+7
    print(ans)

    t -= 1
