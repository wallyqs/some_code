#!/usr/bin/env python
# TSP DataMaker
# Waldemar Quevedo Salinas

from math import pi
from math import e
import math

class City:    
    coorx = 0
    coory = 0

class TSP:
    cities = []
    cities_number = 0           # number of cities
    cities_distances = [[]]
    
    def __init__(self, n):
        self.cities_number = n
        print self.cities_number

    def get_distance(self, p2, p1):
        return math.sqrt((p2.coorx - p1.coorx )**2 + (p2.coory - p1.coory)**2)
    
    def compute_distances(self):
        # List of the cities
        for i in range(self.cities_number):
            self.cities.append(City())

        # Matrix with the distances. 
        self.cities_distances = [[0 for i in range(self.cities_number)] for i in range(self.cities_number)]
        step = 2 * pi / self.cities_number

        # Obtain the position for each city, CITIES_NUMBER they will form a circle
        for i in range(self.cities_number):
            this_step = i * step
            x = math.cos(this_step)
            y = math.sin(this_step)
            self.cities[i].coorx = x
            self.cities[i].coory = y

        # Print the coordinates of each object
        for city in self.cities:
            print city.coorx, city.coory

        for i in range(self.cities_number):
            for j in range(self.cities_number):
                self.cities_distances[i][j] = self.get_distance(self.cities[i], self.cities[j])
                # print "Distance from: ", i, j, cities_distances[i][j]
        return self.cities_distances

if __name__ == '__main__':
    import sys
    print "Getting TSP data"
    n = int(sys.argv[1])
    TSP(n)
    TSP.compute_distances()    
