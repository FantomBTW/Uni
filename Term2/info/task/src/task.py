import sys


def rotate_array(massive, K):
    N = len(massive)
    K = K % N
    new_massive = [0 for _ in range(N)]
    for i in range(len(massive)):
        new_index = (i+K) % N

        new_massive[new_index] = massive[i]
    return new_massive


def main():
    K = int(sys.argv[1])
    massive = sys.argv[2:]
    print(rotate_array(massive, K))


main()
