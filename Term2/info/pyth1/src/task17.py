import sys


def is_positive(x):
    return True if x>0 else False


def main():
    print(is_positive(int(sys.argv[1])))

main()

