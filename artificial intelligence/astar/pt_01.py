import heapq

graph={
    'S': [('A', 5),('B', 3),('C', 4)],
    'A': [('D', 2),('E', 5)],
    'B': [('F', 8),('G', 5)],
    'C': [('H', 3),('I', 2)],
    'D': [],
    'E': [('J', 3),('K', 6)],
    'F': [],
    'G': [],
    'H': [('L', 5),('M', 1)],
    'I': [],
    'J': [],
    'K': [],
    'L': [],
    'M': [],
  
}
heuristics={
    'S': 7,
    'A': 0,
    'B': 1,
    'C': 4,
    'D': 0,
    'E': 2,
    'F': 0,
    'G': 1,
    'H': 1,
    'I': 3,
    'L': 0,
    'M': 0,
}
# a star

def a_star(start, goal):
    open_list = []
    close_list = set()
    heapq.heappush(open_list, (heuristics[start], 0, heuristics[start], start, None))
    g_values = {
        start:0
    }
    parents={
        start: None
    }
    while open_list:
        _,g,_,current,_ = heapq.heappop(open_list)
        
        if current == goal:
            path = []
            while current:
                path.append(current)
                current = parents[current]
            return path[::-1], g
        if current in close_list:
            continue
        else:
            close_list.add(current)
        
        for neighbor, edge_cost in graph.get(current,[]):
            if neighbor in close_list:
                continue
            tentative_g = g+ edge_cost
            if neighbor not in g_values or tentative_g < g_values[neighbor]:
                g_values[neighbor] = tentative_g
                parents[neighbor] = current
                h = heuristics[neighbor]
                f = tentative_g + h
                heapq.heappush(open_list, (f, tentative_g,h, neighbor,current))
    
    return None
path, cost= a_star('S', 'M')
print("cost: ", cost)
print("path: ", path)