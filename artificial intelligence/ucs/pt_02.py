import heapq

graph ={
    'S':[('A', 5),('B', 9),('D', 6)],
    'A':[('B', 3), ('G1', 9)],
    'B':[('A', 2), ('C', 1)],
    'C':[('G2', 5), ('S', 6)],
    'D':[('C', 2), ('E', 2)],
    'E': [('G3', 7)],
    'G1': [],
    'G2': [],
    'F': [('D', 2), ('G3', 8)],
    'G3': []
}


def ucs(start,goal):
    pq = []
    heapq.heappush(pq, (0, start, [start]))
    visited = set()

    while(pq):
        cost, node, path = heapq.heappop(pq)
        if node in visited:
            continue
        
        visited.add(node)
        
        if node == goal:
            return cost, path
        
        for neighbor, edge_cost in graph[node]:
            heapq.heappush(pq, (cost + edge_cost , neighbor, path + [neighbor]))
    return None

start= 'S'
goal = 'G3'
cost, path = ucs(start, goal)
print("cost: " , cost)
print("path: ", "->".join(path))
