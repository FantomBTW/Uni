import sys


def main():
    N = int(sys.argv[1])
    matrix = [[0]*N for _ in range(N)]

    dirs = [[1, 0], [0, 1], [-1, 0], [0, -1]]
    nowDir = 0
    dir = dirs[nowDir]

    pos = [0, 0]

    for i in range(1, N*N+1):
        if (pos[0]+dir[0] > N or matrix[pos[0]+dir[0], pos] > 0) or \
            (pos[1]+dir[1] > N or matrix[pos[1]+dir[1], pos] > 0):
            nowDir += 1
            dir = dirs[nowDir]

        matrix[pos[0], pos[1]]

    print(matrix)


main()
