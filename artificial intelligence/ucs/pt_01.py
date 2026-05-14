import heapq

goal = [
    [0,1, 2],
    [3,4,5],
    [6,7,8]
]

start = [
    [0,1,3],
    [4,2,5],
    [7,8,6]
]

# helper functions
moves = [(-1, 0), (1,0), (0,-1), (0, 1)]

# board to tuple
def board_to_tuple(board):
    return tuple(tuple(row) for row in board)
# get blank
def find_blank(board):
    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:
                return i,j
            
# find the neighbors
def get_neighbors(board):
    neighbors = []
    x,y = find_blank(board)
    for dy, dx in moves:
        nx = x + dx
        ny = y + dy
        
        if(0<= nx < 3 and 0 <= ny < 3):
            new_board = [row[:] for row in board]
            new_board[x][y], new_board[nx][ny] = new_board[nx][ny], new_board[x][y]

            neighbors.append(new_board)
    return neighbors

# ucs
def ucs(start, goal):

    pq = []
    heapq.heappush(pq, (0, start, []))
    visited = set()

    while pq:
        cost, board, path = heapq.heappop(pq)
        if board_to_tuple(board) in visited:
            continue

        visited.add(board_to_tuple(board))

        if board == goal:
            return cost, path + [board]
    
        for neighbor in get_neighbors(board):
            heapq.heappush(pq, (cost + 1, neighbor, path + [board]))

    return None

cost, path = ucs(start, goal)
print("cost: ", cost)
for board in path:
    for row in board:
        print(row)
    print()