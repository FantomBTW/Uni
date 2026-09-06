def calculate_bmi():
    weight = float(input("Введите ваш вес (в кг): "))
    height = float(input("Введите ваш рост (в метрах, например, 1.75): "))
    if height <= 0:
        print("Рост должен быть больше нуля.")
        return
    bmi = weight / (height ** 2)
    print(f"Ваш индекс массы тела (ИМТ): {bmi:.2f}")

if __name__ == "__main__":
    calculate_bmi()
