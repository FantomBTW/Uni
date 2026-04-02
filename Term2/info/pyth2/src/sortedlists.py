def uniquelize(massive):
    uniqueNums = set()
    for i in range(len(massive)):
        if massive[i] in uniqueNums:
            massive[i] = '_'
        else:
            uniqueNums.add(massive[i])
    retmassive = [x for x in uniqueNums]
    while len(retmassive) < len(uniqueNums):
        retmassive.append('_')

    return len(uniqueNums), retmassive

    massive.sort()
    return len(uniqueNums), massive


def main():
    print(uniquelize([1, 1, 2, 2, 2, 2, 3, 6, 7]))


if __name__ == "__main__":
    main()
