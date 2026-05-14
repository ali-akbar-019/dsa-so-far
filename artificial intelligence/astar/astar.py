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

# now a start algorithm
def a_star(start,goal):
    open_list = []
    close_list = set()
    # format: f, g, h, node, parent
    heapq.heappush(open_list, (heuristic[start], 0, heuristic[start], start, None))
    # track the best g values for all
    g_values={
        start:0
    }
    # track the parents of all
    parents={
        start: None
    }
    # iterations
    while(open_list):
        _,g,_,current,_ = heapq.heappop(open_list)
        if current == goal:
            path = []
            while current:
                path.append(current)
                current = parents[current]
            # path array reversed ho gi to us ko seda karo wapas reverse kar k 
            # return kar do path and actual cost
            return path[::-1], g #this is reverse it back ta k wo seda ho jaye q k ham current se oper parent tka gaye ha , hame parent se current tk ana ha 
        
        if current in close_list:
            continue
        else:
            close_list.add(current)

        for neighbor, edge_cost in graph.get(current, []):
            if neighbor in close_list:
                continue    
            # tentative g
            prev_plus_curr_g_ki_value =  g + edge_cost
            # ab agar ye value g values wali list me nahi present ya ye choti ha or us me bari value present ha fir add kar do
            if neighbor not in g_values or prev_plus_curr_g_ki_value < g_values[neighbor]:
                g_values[neighbor] = prev_plus_curr_g_ki_value
                # parent set kar do
                parents[neighbor] = current
                # h
                h = heuristic[neighbor]
                # f = gn + hn
                f= prev_plus_curr_g_ki_value + h

                heapq.heappush(open_list, (f, prev_plus_curr_g_ki_value, h, neighbor, current))
        
    return None

start = 'Arad'
goal = 'Bucharest'
path, cost = a_star(start, goal)
print("cost: ",cost)
print("path: ", path)


