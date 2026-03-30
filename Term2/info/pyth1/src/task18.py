import sys

def main():
    text = input("")
    text = text.strip()
    text = text.replace('а', '@')
    text = text.upper()

    if "ПРИВЕТ" in text:print("Да")
    else:print("Нет")

    print(text.count('@'))

main()

