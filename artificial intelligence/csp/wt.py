# regions
regions=["WA", "NT", "SA", "Q", "NSW", "V", "T"]
# colors
colors=['red','green','blue']

neighbors={
    "WA": ["NT", "SA"],
    "NT": ["WA", "SA", "Q"],
    "SA": ["WA","NT", "Q", "NSW","V"],
    "Q":["NT", "SA", "NSW"],
    "NSW": ["Q", "SA", "V"],
    "V": ["SA", "NSW"],
    "T":[]
}

# now we have to use the CSP in here
# is consistent
def is_consistent(region , assignments, color):
    # sarey neighbors me deko
    for ngb in neighbors[region]:
        if assignments.get(ngb) == color:
            return False
    return True

# CSP
def csp(assignments):
    if(len(assignments) == len(regions)):
        return assignments
    # 
    region = next(r for r in regions if r not in assignments)
    for color in colors:
        if(is_consistent(region, assignments, color)):
            assignments[region] = color
            result = csp(assignments)
            if(result != None):
                return result
            del assignments[region]
    return None

solution = csp({})
if solution:
    for region,color in solution.items():
        print(region + "->"+ color)
else:
    print("No solution found") 