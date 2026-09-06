def swap_variables():
    a = input("Введите значение первой переменной (a): ")
    b = input("Введите значение второй переменной (b): ")
    print(f"До обмена: a = {a}, b = {b}")
    a, b = b, a
    print(f"После обмена: a = {a}, b = {b}")

if __name__ == "__main__":
    swap_variables()
