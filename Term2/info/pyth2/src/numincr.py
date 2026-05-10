def increment(massive):
    massive = [str(x) for x in massive]
    num = int(''.join(massive))

    num += 1

    return [x for x in str(num)]


def main():
    print(increment([1]))
    print(increment([1, 9]))
    return 0


if __name__ == "__main__":
    main()
