import heapq

graph = {
    'S':[('A', 4),('B', 10),('C', 11)],
    'A':[('B', 8),('D', 5)],
    'B':[],
    'C':[],
    'D':[('H', 16),('I', 20),('F', 1)],
    'H':[],
    'I':[],
    'F':[('G', 13)],
    'G':[],
}
heuristics={
    'S': 7,
    'A': 8,
    'B': 6,
    'C': 5,
    'D': 5,
    'H': 7,
    'I': 4,
    'F': 3,
    'G': 0,
}

def a_star(start, goal):
    open_list = []
    close_list = set()
    # format: f, g, h, node, parent
    heapq.heappush(open_list, (heuristics[start], 0, heuristics[start], start, None))
    # g values k leye
    g_values=  {
        start:0
    }
    # parents
    parents={
        start:None
    }
    # iterations
    while open_list:
        _,g,_,current,_ = heapq.heappop(open_list)
        if current == goal:
            path = []
            while current:
                path.append(current)
                current= parents[current]
            return path[::-1], g
        if current in close_list:
            continue
        else:
            close_list.add(current)
        
        # 
        for neighbor, edge_cost in graph.get(current,[]):
            if neighbor in close_list:
                continue
            tentative_g = g + edge_cost
            if neighbor not in g_values or tentative_g < g_values[neighbor]:
                g_values[neighbor] = tentative_g
                parents[neighbor] = current
                h = heuristics[neighbor]
                f = tentative_g + h
                
                heapq.heappush(open_list, (f, tentative_g, h, neighbor, current))
    
    return None
path, cost = a_star('S', 'G')
print("cost: ", cost)
print("path: ", path)
