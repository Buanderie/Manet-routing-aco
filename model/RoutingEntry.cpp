#include "RoutingEntry.hpp"
#include "Graph.h"
#include <iostream>

RoutingEntry::RoutingEntry(int dest, int nhop) : destinationAddress(dest),
                                                 nextHopAddress(nhop),
                                                 pheromone(0.0) {
}

void RoutingEntry::increasePheromone() {
    pheromone += PHEROMONE_DELTA;
}

void RoutingEntry::evaporatePheromone(){
    pheromone = (1-EVAPORATION_FACTOR)*pheromone;
}
