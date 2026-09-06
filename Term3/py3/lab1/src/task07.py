import math

def circle_area():
    radius = float(input("Введите радиус круга: "))
    area = math.pi * (radius ** 2)
    print(f"Площадь круга: {area}")

if __name__ == "__main__":
    circle_area()
