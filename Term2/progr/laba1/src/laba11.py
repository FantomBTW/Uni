glob = 5


def summa(a, b):
    return a+b


def srarf(a):
    return sum(a)/len(a)  # длина массива на его размер


def main():
    a, b = [int(x) for x in input("введите значения для суммирования\n").split()]
    print("сумма =", summa(a, b))

    ls = [int(x) for x in input("введите значения для усреднения через пробел\n").split()]
    print(srarf(ls))

    print("glob=", glob, sep='')

    loc = 5
    # после завершения функции, память о переменных в ней очистится


if __name__ == "__main__":
    main()
