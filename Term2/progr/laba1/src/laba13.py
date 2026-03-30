import laba12
import labahead
import sys


def main():
    # готовим флаги, чтоб знать, почему код не подходит
    flag1 = 0
    flag2 = 0
    flag3 = 0

    # получаем a-b-c
    code = sys.argv[1]
    a, b, c = [int(x) for x in code.split('-')]
    if labahead.simple(a) == 'y':
        flag1 = 1
    if laba12.palindrome(b)[0] == 'y':
        flag2 = 1
    if labahead.step(c) == 'y':
        flag3 = 1

    if flag1 + flag2 + flag3 == 3:
        print('Корректен')
    else:
        print('flag1=', flag1, 'flag2=', flag2, 'flag3=', flag3, sep='')


if __name__ == "__main__":
    main()
