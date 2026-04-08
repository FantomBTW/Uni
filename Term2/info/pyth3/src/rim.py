def rimToNum(s):
    rimNumbers = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}

    prev = 0
    total = 0

    for symb in reversed(s):
        value = rimNumbers[symb]
        
        if prev > value:
            total -= value
        else:
            total += value

        prev = value

    return total
        

def main():
    print(rimToNum("XVI"))


if __name__ == "__main__":
    main()
