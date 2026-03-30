def palindrome(pali):
    pali = str(pali)
    flag = 1
    lenstr = len(pali)//2
    for i in range(lenstr):
        if pali[i] != pali[-(i+1)]:
            flag = 0
            break
    # если не палиндром, то найдётся такой элемент, что pali[i]!=pali[-(i+1)]

    if flag == 1:
        return ['y', f"{pali} --Палиндром"]
    return ['n', f"{pali} -- Не Палиндром"]


def main():
    s = input("проверка на палиндрома\n")
    print(palindrome(s)[1])


if __name__ == "__main__":
    main()
