import random
arr = [[1 for x in range(6)] for y in range(6)]

while 1:
    flag = 1
    val = 66
    for i in range(6):
        for j in range(6):
            if i != j:
                arr[i][j] = random.randint(1, 11)

    if arr[0][0] != 1:
        continue
    if arr[1][1] != 1:
        continue
    if arr[2][2] != 1:
        continue
    if arr[3][3] != 1:
        continue
    if arr[4][4] != 1:
        continue
    if arr[5][5] != 1:
        continue

    for i in range(6):
        sum = 0
        for j in range(6):
            sum += arr[i][j]
        for j in range(6):
            sum += arr[j][i]
        sum -= arr[i][i]

        if sum != val:
            flag = 0
            break

    if flag == 1:
        break

print(arr)
