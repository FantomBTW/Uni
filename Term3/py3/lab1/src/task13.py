import math

def square_root():
    number = float(input("Введите число: "))
    if number < 0:
        print("Нельзя извлечь квадратный корень из отрицательного числа в действительных числах.")
    else:
        result = math.sqrt(number)
        print(f"Квадратный корень из {number} равен {result}")

if __name__ == "__main__":
    square_root()
