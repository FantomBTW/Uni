import math

def calculate_factorial():
    number = int(input("Введите неотрицательное целое число: "))
    if number < 0:
        print("Факториал определен только для неотрицательных чисел.")
    else:
        result = math.factorial(number)
        print(f"Факториал числа {number} равен {result}")

if __name__ == "__main__":
    calculate_factorial()
