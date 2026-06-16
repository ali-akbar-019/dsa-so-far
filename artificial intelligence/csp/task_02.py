courses = ["C1", "C2", "C3", "C4"]
classrooms = ["R1", "R2", "R3"]
timeslots = ["T1", "T2", "T3", "T4"]

def is_consistent(room, course, time ,assignments):
    for c in assignments:
        r, t = assignments[c]
        
        if(room == r and t == time):
            return False

        if(room == r and t == time):
            return False

    return True

def csp(assignments):
    
    if len(assignments) == len(courses):
        return assignments
    
    # else course uthao aik jo assign nahi howa
    course = next(course for course in courses if course not in assignments)
    
    # check
    for c in classrooms:
        for t in timeslots:
            if(is_consistent(c, course, t, assignments)):
                assignments[course] = (c, t)
                result = csp(assignments)
                if result is not None:
                    return result
                del assignments[course]
    return None
    

solution = csp({})
if solution:
    print(solution)
else:
    print("No solution found")
