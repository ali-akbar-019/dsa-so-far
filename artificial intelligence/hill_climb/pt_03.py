import random
import string


# initial state
initial_state = ['A','H','G', 'F','E','D','C','B']

# goal state
goal_state = ['H','G','F','E','D','C','B','A']

# fitness
def get_fitness(state):
    count =0 
    for i in range(len(goal_state)):
        if(goal_state[i] == state[i]):
            count+=1
    return count


# mutate
def mutate(state):
    # get two random indexes and swap them
    randIndex1 = random.randint(0, len(state) - 1)
    randIndex2 = random.randint(0, len(state) - 1)
    # swap
    new_state = state[:]
    new_state[randIndex1], new_state[randIndex2] = new_state[randIndex2], new_state[randIndex1]

    return new_state


# now lets apply the hill climb

def hill_climb():
    current_solution = initial_state[:]
    current_fitness = get_fitness(current_solution)
    steps = 0
    print(f"Step: {steps}, current solution: {current_solution}, current fitness: {current_fitness}")
    while current_fitness < len(goal_state):
        steps+=1
        new_sol= mutate(current_solution)
        new_fit = get_fitness(new_sol)
        if new_fit >= current_fitness:
            current_solution = new_sol
            current_fitness = new_fit
            print(f"Step: {steps}, current solution: {current_solution}, current fitness: {current_fitness}")

hill_climb()