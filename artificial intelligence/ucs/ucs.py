import heapq


# first of all make a graph
graph = {
     'A': [('B', 1), ('C', 4)], 
    'B': [('D', 2), ('E', 5)], 
    'C': [('F', 1), ('G', 3)], 
    'D': [], 
    'E': [], 
    'F': [], 
    'G': [] 
}

# ucs function

def ucs(start, goal):
    pq = []
    # formal: gn, current node, current path
    heapq.heappush(pq, (0, start, [start]));

    # visited values k leye
    visited = set()

    while(pq):
        cost, node, path = heapq.heappop(pq)
        if node in visited:
            continue
        else:
            visited.add(node)

        if node == goal:
            return cost, path
        
        for neighbor, edge_cost in graph[node]:
            heapq.heappush(pq, (cost + edge_cost, neighbor, path + [neighbor]))
    
    return None

start = 'A'
goal = 'G'
cost, path = ucs(start, goal)

print("Cost: ", cost)
print("path: ", "->".join(path))
