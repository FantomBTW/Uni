import sys


def exist(board, word):
    def dfs(r, c, index):
        # in func for vars
        if index == len(word):
            return True

        if (r < 0 or r >= rows or c < 0 or c >= cols or 
            board[r][c] != word[index]):
            return False

        # attended
        temp = board[r][c]
        board[r][c] = '#'
    
        found = (dfs(r + 1, c, index + 1) or
                dfs(r - 1, c, index + 1) or
                dfs(r, c + 1, index + 1) or
                dfs(r, c - 1, index + 1))

        # restoring
        board[r][c] = temp

        return found

    rows, cols = len(board), len(board[0])
    

    # looking in every cell
    for i in range(rows):
        for j in range(cols):
            if dfs(i, j, 0):
                return True
                
    return False


def main(word):
    board = [
                ["a", "b", "c", "e"],
                ["s", "f", "c", "s"],
                ["a", "d", "e", "e"],
            ]
    print(exist(board, word));


if __name__ == "__main__":
    main(sys.argv[1])
