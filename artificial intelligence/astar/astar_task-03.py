import heapq


graph = {
    "S": [("A", 4), ("B", 10), ("C", 11)],
    "A": [("B", 8), ("D", 5)] ,
    "B":[],
    "C": [],
    "D": [("H", 16), ("I", 20), ("F", 1)],
    "F": [("G", 13)],
    "H":[],
    "I": [],
    "G":[]
}

heuristics = {
    "S": 7,
    "A": 8,
    "B": 6,
    "C": 5,
    "D": 5,
    "H": 7,
    "I": 4,
    "F": 3,
    "G":0
}

# 
start = 'S'
goal = 'G'


def a_star(start, goal):
    open_list = []
    close_list = set()
    
    heapq.heappush(open_list, (heuristics[start], 0, heuristics[start], start, None))
    g_values={
        start: 0
    }
    parents={
        start: None

    }
    while open_list:
        _, g, _, current, _ = heapq.heappop(open_list)
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
        

        for ngbr, edge_cost in graph.get(current, []):
            if ngbr in close_list:
                continue
            tentative_g = g + edge_cost
            
            if ngbr not in g_values or tentative_g < g_values[ngbr]:
                g_values[ngbr] = tentative_g
                parents[ngbr] = current
                h = heuristics[ngbr]
                f = tentative_g + h
                heapq.heappush(open_list, (f, tentative_g, h, ngbr, current))
    
    return None


path, cost = a_star(start, goal)


print("G: ", cost)
print(" -> ".join(path))