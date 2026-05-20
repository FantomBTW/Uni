import sys;

def searchMatrix(matrix, target):
    m = len(matrix)
    n = len(matrix[0])
    
    """
    left, right = 0, m * n - 1

    while left <= right:
        mid = (left + right) // 2

        # Преобразуем индекс mid в координаты строки и столбца
        row = mid // n
        col = mid % n

        mid_element = matrix[row][col]

        if mid_element == target:
            return True
        elif mid_element < target:
            left = mid + 1
        else:
            right = mid - 1

    return False
    """

def main():
    matrix = [
        [1,  3,  5,  7],
        [10, 11, 16, 20],
        [23, 30, 34, 60]
    ]
    searchMatrix(matrix, sys.argv[1]);
    print(searchMatrix(matrix, 3))  # Вывод: True
    print(searchMatrix(matrix, 13)) # Вывод: False

if __name__ == "__main__":
    main()
