#pragma once
#include <vector>
#include"Graph.h"
#include "Coalition.h"
using std::string;
using std::vector;
class Agent;
class Graph;
class Coalition;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);
    void step();
    bool shouldTerminate() const;
    vector<Agent>* getNonConstAgents() ;
    const Graph &getGraph() const;
    Graph* getNonConstGraph() ;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    Party* getNonConstParty(int partyId) ;
    const vector<vector<int>> getPartiesByCoalitions() const;
    int getMainTime() const;
    int getNumberOfAgents() const;
    vector <Coalition> *getCoalitionsList () ;
    void addCoalition(Coalition col);
    Agent* getAgent(int id);


    

private:
    Graph mGraph;
    vector<Agent> mAgents;
    int MainTime;
    vector <Coalition> coalitions;
    

};
