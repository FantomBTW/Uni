def delElem(massive, deletable):
    k = 0
    i = 0
    while deletable in massive:
        if massive[i] == deletable:
            massive.remove(massive[i])
            k += 1
        else:
            i += 1
    return massive, k


def main():
    print(delElem([1, 2, 3, 4, 6, 6, 6], 6))
    return 0


if __name__ == "__main__":
    main()
