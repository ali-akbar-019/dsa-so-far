import random
import string

TARGET = "HELLOWORLD"

# make a random solution
def random_solution(length):
    solution = ''.join(random.choice(string.printable[:95]) for _ in range(length))
    return solution

# get the fitness
def get_fitness(solution):
    count =0
    for i in range(len(solution)):
        if solution[i] == TARGET[i]:
            count+=1

    return count

# mutate
def mutate(solution):
    randIndex=  random.randint(0, len(solution) - 1)
    randChar= random.choice(string.printable[:95])
    # convert the string to a list bcz strings can not be changed in python
    new_solution = list(solution)
    new_solution[randIndex] = randChar
    return ''.join(new_solution)

def hill_climb():
    curr_solution = random_solution(len(TARGET))
    curr_fitness = get_fitness(curr_solution)
    steps = 0
    print(f"Step: {steps}, current solution: {curr_solution}, current fitness: {curr_fitness}")

    # jab tk sara match na ho jaye tb tk
    while curr_fitness < len(TARGET):
        steps+=1
        new_sol = mutate(curr_solution)
        new_fit = get_fitness(new_sol)
        if(new_fit>= curr_fitness):
            curr_solution = new_sol
            curr_fitness = new_fit
            print(f"Step: {steps}, current solution: {curr_solution}, current fitness: {curr_fitness}")
    
hill_climb()