import heapq

goal = [[1, 2, 3],
    [4, 5, 6],
    [7, 8, 0]]


moves = [(-1,0), (1,0), (0, -1), (0, 1)]

# helper functions
# convert the board to the tuple
def board_to_tuple(board):
    return tuple(tuple(row) for row in board)
# find the blank
def find_blank(board):
    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:
                return i, j
# get neighbors
def get_neighbors(board):
    neighbors = []
    x,y = find_blank(board)
    # now all the possibilities - (moves L R U B)
    for dx, dy in moves:
        nx = x + dx
        ny = y + dy
        # check if they are in the range
        if(0<=nx<3 and 0<=ny < 3):
            # get a copy of the board
            new_board = [row[:] for row in board]
            # swap with the neighbors 
            new_board[x][y], new_board[nx][ny] = new_board[nx][ny], new_board[x][y]

            # add to the neighbors
            neighbors.append(new_board)
    
    return neighbors
# ucs
def ucs(start, goal):
    
    pq = []
    heapq.heappush(pq, (0, start, [start]))
    visited = set()

    while(pq):
        cost, board, path = heapq.heappop(pq)

        if board_to_tuple(board) in visited:
            continue
        else:
            visited.add(board_to_tuple(board))
        
        if board == goal:
            return cost, path
        
        for neighbor in get_neighbors(board):
            heapq.heappush(pq, (cost +1, neighbor, path + [neighbor]))

    return None

start =  [[1, 2, 3], 
    [4, 0, 6], 
    [7, 5, 8]] 


solution = ucs(start, goal)
if solution == None:
    print("No solution found")
else:   
    cost, path= solution
    print("cost: ", cost)
    for board in path:
        for row in board:
            print(row)
        print()
        