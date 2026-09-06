def multiplication_table():
    number = int(input("Введите число для таблицы умножения: "))
    for i in range(1, 11):
        print(f"{number} x {i} = {number * i}")

if __name__ == "__main__":
    multiplication_table()
