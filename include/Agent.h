#pragma once
#include <vector>
//#include "Graph.h"
//#include "Coalition.h"
#include "Simulation.h"
#include "SelectionPolicy.h"
//#include "Party.h"
using std:: vector;

class SelectionPolicy;
class Simulation;
class Coalition;
class Graph;
class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(const Agent& other);
     ~Agent();
    Agent& operator=(const Agent& other);
    Agent(Agent&& other);
    void clear();
    Agent& operator=(Agent&& other);
    int getPartyId() const;
    int getId() const;
    void step(Simulation &sim);
    int getCoalitionId() const;
    void setCoalitionId(int mycolId);
    void SetId(int newid);
    void SetPartyId(int newid);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int myCoalitionId;
};
