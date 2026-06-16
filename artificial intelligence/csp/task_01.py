

N = 8
def is_safe(board, row, col):
    # check the col
    for i in range(col):
        if(board[row][i] == 1):
            return False
    # upper diag
    for i, j in zip(range(row, -1,-1), range(col, -1, -1)):
        if(board[i][j] == 1):
            return False
    # lower
    for i,j in zip(range(row, N, 1), range(col, -1 ,-1)):
        if(board[i][j] == 1):
            return False
    
    return True
def solve_nqueen(board, col):
    if(col >= N):
        return True
    
    # sab rows chek karo
    for row in range(N):
        if(is_safe(board, row, col)):
            board[row][col] = 1
            if(solve_nqueen(board, col + 1)):
                return True
            # backtrack
            board[row][col] = 0

    return False

def print_board(board):
    for row in board:
        print(" ".join("Q" if cell == 1 else "." for cell in row))
# initial
board = [[0 for _ in range(N)] for _ in range(N)]

if solve_nqueen(board, 0):
    print_board(board)
else:
    print("No solution found")