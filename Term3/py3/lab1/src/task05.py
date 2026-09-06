from datetime import datetime

def show_datetime():
    current_time = datetime.now()
    print(f"Текущая дата и время: {current_time}")

if __name__ == "__main__":
    show_datetime()
