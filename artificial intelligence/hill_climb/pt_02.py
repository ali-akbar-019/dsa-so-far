import random
import string

initial = ['A', 'D', 'C', 'B']
goal = ['D', 'C', 'B', 'A']

# get fitness
def get_fitness(state):
    count = 0
    for i in range(len(goal)):
        if state[i] == goal[i]:
            count+=1
    return count



# mutate
def mutate(state):
    randomIndex1 = random.randint(0, len(state)- 1)
    randomIndex2 = random.randint(0, len(state)- 1)
    new_state = state[:]
    new_state[randomIndex1], new_state[randomIndex2]= new_state[randomIndex2], new_state[randomIndex1]

    return new_state

# hill climb
def hill_climb():
    current_solution = initial[:]
    current_fitness = get_fitness(current_solution)
    steps = 0
    print(f"Step: {steps}, current solution: {current_solution}, current fitness: {current_fitness}")
    while current_fitness < len(goal):
        steps+=1
        new_sol = mutate(current_solution)
        new_fit = get_fitness(new_sol)
        if new_fit>= current_fitness:
            current_fitness = new_fit
            current_solution = new_sol
            print(f"Step: {steps}, current solution: {current_solution}, current fitness: {current_fitness}")
    

hill_climb()