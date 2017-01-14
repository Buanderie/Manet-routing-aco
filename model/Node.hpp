#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include "RoutingEntry.hpp"
#include "Packet.h"

class RoutingEntry;
class Node;

typedef std::vector<std::shared_ptr<RoutingEntry> > tRoutingEntryVec;
typedef std::vector<std::shared_ptr<Node> > tNodeVec;
typedef std::pair<std::shared_ptr<RoutingEntry>,float> tRentryProbPair;

class Node: public std::enable_shared_from_this<Node> {

private:

    std::set<int> visitedAnts;
    std::vector<std::pair<int, tPacketptr>> entryBuffer;
    std::vector<std::pair<int, tPacketptr>> internalEntryBuffer;

private:

    tRoutingEntryVec findDestinationEntries(tPacketptr packet);
    std::shared_ptr<RoutingEntry> findBestPath (tRoutingEntryVec vec);

    void passDiscoveryAnt(int previousAddress, tPacketptr ant);
    void passRegularPacket(tPacketptr packet);

public:

    tRoutingEntryVec routingTable;

    Node(){}
    Node(std::string name, int address);
    int address;
    std::string name;
    tNodeVec neighbours;

    void addNeighbour(std::shared_ptr<Node> node);

    void sendPacket(int fromHop, tPacketptr packet);
    void postTick();
    void tick();

    void updateRoutingEntry(tPacketptr packet);
    std::shared_ptr<RoutingEntry> getEntryForDestinationAndHop(int dest, int hop);

};
