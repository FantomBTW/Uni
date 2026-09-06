def check_even_odd():
    number = int(input("Введите целое число: "))
    if number % 2 == 0:
        print(f"Число {number} чётное.")
    else:
        print(f"Число {number} нечётное.")

if __name__ == "__main__":
    check_even_odd()
