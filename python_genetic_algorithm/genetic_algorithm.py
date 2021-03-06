#!/usr/bin/env python
# Genetic Algorithm for TSP data
# Waldemar Quevedo Salinas

from tsp import TSP
from random import shuffle
from random import random as rand
from random import randrange

cities_distances = 0 

def eval_solution(current_chromosome):
    # Only evaluate if both chromosomes are of the same size
    if cities_distances[0].__len__() == current_chromosome.__len__():
        # print "Calculating Total Distance"
        total_distance = 0
        for i in range(current_chromosome.__len__()):
            if i < (current_chromosome.__len__() - 1):
                total_distance  += cities_distances[current_chromosome[i]][current_chromosome[i + 1]] 
                # print "Distance this far is: ", total_distance
            else:
                total_distance += cities_distances[current_chromosome[-1]][current_chromosome[0]] 
                print "Total Distance: ", total_distance
        return total_distance

def crossover(parent1, parent2):
    print "Crossover Operation"
    n = parent1.__len__()
    locus = randrange(0,n)             # set crossover point, randomly choose from 0..7
    child1 = []
    child2 = []
    
    print "parents: ", parent1, parent2
    
    # Copy both childs as their first parent up until the crossover point
    for i in range(locus):
        child1.append(parent1[i])
        child2.append(parent2[i])

    # Copy the remaining alleles from the other parent
    for allele in parent2:
        if not child1.__contains__(allele):
            child1.append(allele)

    for allele in parent1:
        if not child2.__contains__(allele):
            child2.append(allele)
    print "children: ", child1, child2
    return [child1, child2]

# Swaps the location of two alleles
def mutate(chromosome):
    print "Mutating the Chromosome"
    n = chromosome.__len__()
    position1 = randrange(0,n)
    position2 = randrange(0,n)
    tmp = chromosome[position1]
    chromosome[position1] = chromosome[position2]
    chromosome[position2] = tmp
    return chromosome

def total_fitness(generation):
    total = 0
    for chromosome in generation:
        total += eval_solution(chromosome)
    return total

# less apt ... more apt
def sort_generation(generation):
    sorted_generation = generation[:]
    for i in range(sorted_generation.__len__() - 1):
        for j in range(sorted_generation.__len__() - 1):
            if eval_solution(generation[i]) > eval_solution(generation[j]):
                tmp = generation[j]
                generation[j] = generation[i]
                generation[i] = tmp


def randomly_delete(generation):
    print "randomly deleting a member of the population to make it even"
    r = randrange(0, generation.__len__())
    generation.pop(r)
    

if __name__ == '__main__':
    print "Genetic Algorithm (e.g. chromosome => [0,1,2,3,4,5,6,7] "
    tsp_problem = TSP(8)        # use 8 cities from now, use sys.argv later
    cities_distances = tsp_problem.compute_distances()
    locuses = cities_distances[0].__len__() # loci?
    p_c = 0.7                   # crossover probability
    p_m = 0.001                 # mutation probability, tried with 0.005...
    best_generation = []
    n = 8                       # number of chromosomes in the generation
    max_generations = 2
    generation = []
    generation_fitnesses = []
    base = range(0,locuses)           # [0,1,2,3,4,5,6,7]
   

    # Create a random first generation
    for i in range(n):
        next = base[:]
        shuffle(next)
        generation.append(next)
  
    # Consider this to be the best first generation
    best_generation = generation[:]      
    best_generations_list = []

    # Evolution Process
    for i in range(max_generations):
        offsprings_generation = []
        offsprings_number = 0
        while offsprings_number < 10:
            # sort_generation(generation)
            fitnesses = []
            for chromosome in generation:
                fitness = eval_solution(chromosome)
                fitnesses.append(fitness)
            
            total_generation_fitness = total_fitness(generation)
        
            # Uniform distribution with this data
            uniform_fitnesses = []
            for fitness in fitnesses:
                uniform_fitnesses.append(fitness/total_generation_fitness)
        
            # Accumulated distribution
            accumulated_fitnesses = []
            total_accumulated_fitness = 0
            for fitness in uniform_fitnesses:
                total_accumulated_fitness += fitness
                accumulated_fitnesses.append(total_accumulated_fitness)
        
            print "Uniform: ", uniform_fitnesses
            print "Accumulated: ", accumulated_fitnesses
        
            # Now let's do the crossover and mutation operation
            # First, let's select the parents
            pair = []
            for i in range(2):
                r = rand()
                print "random number: ", r
                # Select first probability that is greater than random
                selected_chromosome = []
                for j in range(accumulated_fitnesses.__len__()):
                    if accumulated_fitnesses[j] > r:
                        print "selected: ", j
                        selected_chromosome = generation[j]
                        break
                pair.append(selected_chromosome)
            
            # Random crossover
            crossover_pair = []
            if rand() < p_c:
                print "pair", pair
                print "There was a crossover"
                if not pair[0]:
                    pair[0] = pair[1]
                if not pair[1]:
                    pair[1] = pair[0]
                crossover_pair = crossover(pair[0],pair[1])
                print "crossover_pair: ", crossover_pair
            else:
                print "No crossover"
                crossover_pair = pair[:]

            # Random mutation
            mutated_chromosome = []
            for mutated_chromosome in crossover_pair:
                for i in range(locuses):
                    if rand() < p_m:
                        print "to be mutated: ", mutated_chromosome
                        # mutated_chromosome = mutate(mutated_chromosome)                    
                        mutate(mutated_chromosome)
                        print "after mutation: ", mutated_chromosome
        
            for chromosome in crossover_pair:
                offsprings_generation.append(chromosome)
            
            offsprings_number += 2
            print "total offsprings_number until now: ", offsprings_number

        # Replace the current generation with the new one with offsprings
        generation = offsprings_generation[:]
        
        # The generation have of an even size for future evolutions
        while generation.__len__() != n:
            randomly_delete(generation)
            print "size of the generation: ", generation.__len__()
            
        # if this generation is better than the last one, replace it 
        if total_fitness(generation) < total_fitness(best_generation):
            print "yes it is"
            best_generation = generation[:]
            print best_generation
            best_generations_list.append(best_generation)
        else:
            print "no it isn't"
            generation = best_generation[:]
            print generation

        print "best_generation: ", best_generation
        print "eval: ", total_fitness(best_generation)        
