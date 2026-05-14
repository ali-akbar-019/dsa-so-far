import heapq

start =      [[1, 2, 3],
               [4, 0, 6],
               [7, 5, 8]]

goal =        [[1, 2, 3],
              [4, 5, 6],
              [7, 8, 0]]

moves=[(-1, 0),(1, 0),(0, 1),(0, -1)]

# helper functions
def board_to_tuple(board):
    return tuple(tuple(row) for row in board)

#
def find_blank(board):
    for i in range(3):
        for j in range(3):
            if board[i][j] == 0:
                return i,j
            
# heuristic functions
def h_misplaced(board):
    cost = 0
    for i in range(3):
        for j in range(3):
            if board[i][j] != 0 and board[i][j] != goal[i][j]:
                cost = cost + 1
    
    return cost

#
def h_manhatten(board):
    distance = 0
    for i in range(3):
        for j in range(3):
            val = board[i][j]
            if(val != 0):
                goal_x = (val - 1) //3
                goal_y = (val - 1 )% 3
                d = abs(i - goal_x) + abs(j - goal_y)
                distance+= d
    
    return distance

def get_neighbors(board):
    neighbors = []
    x,y = find_blank(board)
    for dx, dy in moves:
        nx = x + dx
        ny = y + dy
        if(0<=nx<3 and 0<=ny <3):
            new_board = [row[:] for row in board]
            new_board[x][y], new_board[nx][ny]= new_board[nx][ny], new_board[x][y]
            neighbors.append(new_board)
    
    return neighbors
# a star
def a_star(start, goal, heuristic=h_manhatten):
    open_list = []
    close_list = set()
    
    heapq.heappush(open_list, (heuristic(start), 0, heuristic(start),start,[]));
    # 
    while open_list:
        _,g,_,board, path =  heapq.heappop(open_list)
        
        if board_to_tuple(board) in close_list:
            continue
        else:
            close_list.add(board_to_tuple(board))
        
        if board == goal:
            return path + [board], g
    
        for neighbor in get_neighbors(board):
            if board_to_tuple(neighbor) in close_list:
                continue
            
            tentative_g = g + 1 
            h = heuristic(neighbor)
            f = tentative_g + h
            heapq.heappush(open_list, (f, tentative_g, h, neighbor, path + [board]))

    
    return None

path, cost = a_star(start, goal)
print("cost: ", cost)
print("path")

for i in path:
    for j in i:
        print(j)
    print()