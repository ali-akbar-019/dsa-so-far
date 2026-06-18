import heapq



# graph given ho ga
graph = {
    'Arad': [('Zerind', 75), ('Sibiu', 140), ('Timisoara', 118)],
    'Zerind': [('Arad', 75), ('Oradea', 71)],
    'Timisoara': [('Arad', 118), ('Lugoj', 111)],
    'Sibiu': [('Arad', 140), ('Fagaras', 99), ('Oradea', 151), ('Rimnicu Vilcea', 80)],
    'Oradea': [('Zerind', 71), ('Sibiu', 151)],
    'Fagaras': [('Sibiu', 99), ('Bucharest', 211)],
    'Rimnicu Vilcea': [('Sibiu', 80), ('Pitesti', 97), ('Craiova', 146)],
    'Pitesti': [('Rimnicu Vilcea', 97), ('Bucharest', 101), ('Craiova', 138)],
    'Craiova': [('Rimnicu Vilcea', 146), ('Pitesti', 138)],
    'Bucharest': [('Fagaras', 211), ('Pitesti', 101)]
}
# given ho gi bas ham ne likhni ho gi
heuristic = {
    'Arad': 366,
    'Zerind': 374,
    'Timisoara': 329,
    'Sibiu': 253,
    'Oradea': 380,
    'Fagaras': 178,
    'Rimnicu Vilcea': 193,
    'Pitesti': 98,
    'Craiova': 160,
    'Bucharest': 0     
}

def a_star(start, goal):
    open_list = []
    close_list = set()
    # f g h node parent
    heapq.heappush(open_list, (heuristic[start], 0, heuristic[start], start, None))
    # g values
    g_value={
        start: 0

    }
    # parents
    parents={
        start:None
    }
    
    while(open_list):
        _,g,_, current,_ = heapq.heappop(open_list)
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
        
        # 
        for ngbr, edge_cost in graph.get(current, []):
            if ngbr in close_list:
                continue
            
            tentaive_g = g + edge_cost
            if(ngbr not in g_value or tentaive_g < g_value[ngbr]):
                g_value[ngbr] = tentaive_g
                parents[ngbr] = current
                
                h = heuristic[ngbr]
                f = tentaive_g + h

                heapq.heappush(open_list, (f, tentaive_g, h, ngbr, current))
        
    return None

start = "Arad"
goal = "Bucharest"
path, cost = a_star(start, goal)


print("G: ", cost)
print(" -> ".join(path))