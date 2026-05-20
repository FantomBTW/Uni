import sys

def reverseBits(n):
    q = f"{n:032b}";
    qnew = q[::-1]
    return int(qnew, 2);

def main(n):
    print(reverseBits(int(n)));

if __name__ == "__main__":
    main(sys.argv[1])
