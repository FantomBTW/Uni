def maxprefix(massive):
    i = 0
    stroka = []
    while 1:
        symbol = massive[0][i]
        if all(massive[x][i] == symbol for x in range(len(massive))):
            stroka.append(symbol)
        else:
            return ''.join(stroka)
        i += 1


def main():
    print(maxprefix(["flight", "flower", "flow"]))
    print(maxprefix(["flight", "flower", "sun"]))


if __name__ == "__main__":
    main()
