import random
import string

TARGET = "ArtificialIntelligence"

# random solution generator
def random_solution(length):
    solution = ''.join(random.choice(string.printable[:95]) for _ in range(length))
    return solution

# fitness check
def get_fitness(solution):
    count =0
    for i in range(len(solution)):
        if solution[i] == TARGET[i]:
            count+=1
    
    return count

# mutate
def mutate(solution):
    randIndex=  random.randint(0, len(solution) -1)
    randChar = random.choice(string.printable[:95])
    
    new_solution = list(solution)
    new_solution[randIndex] = randChar
    
    return ''.join(new_solution)

# hill climb
def hill_climb():
    current_solution = random_solution(len(TARGET))
    current_fitness = get_fitness(current_solution)
    steps = 0
    print(f"Step: {steps}, current solution: {current_solution}, current fitness {current_fitness}")
    # 
    while current_fitness < len(TARGET):
        steps+=1
        new_sol = mutate(current_solution)
        new_fit = get_fitness(new_sol)
        # 
        if new_fit >= current_fitness:
            current_solution = new_sol
            current_fitness = new_fit
            print(f"Step: {steps}, current solution: {current_solution}, current fitness {current_fitness}")

hill_climb()