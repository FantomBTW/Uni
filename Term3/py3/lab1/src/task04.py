def celsius_to_fahrenheit():
    celsius = float(input("Введите температуру в градусах Цельсия: "))
    fahrenheit = celsius * 9 / 5 + 32
    print(f"Температура по Фаренгейту: {fahrenheit}")

if __name__ == "__main__":
    celsius_to_fahrenheit()
