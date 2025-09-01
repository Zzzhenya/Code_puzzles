
def limitations(x, y, z, n):
    arr = []
    for i in range (x + 1):
        for j in range (y + 1):
            for k in range (z + 1):
                if [i,j,k] not in arr:
                    if i + j + k != n:
                        arr.append([i,j,k])
    return (arr)

if __name__ == '__main__':
    x = int(input())
    y = int(input())
    z = int(input())
    n = int(input())
    arr = limitations(x,y,z,n)
    print(arr)
    # for x in arr:
        # print(x)