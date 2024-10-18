import sys

'''argc = len(sys.argv)'''

def find_primes(n):
    all_num = []
    for i in range(n-1):
        all_num.append(i+2)
    for j in range(n-1):
        for i in range(n-1):
            if (all_num[i] != 0) & (all_num[i]%j == 0):
                if (all_num[i] != j):
                    all_num[i] = 0
    for i in range(n-1):
        print(all_num[i])

if __name__ == '__main__':
        n = int(sys.argv[1])
        find_primes(n)
