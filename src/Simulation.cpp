#include "Simulation.h"
#include "Coalition.h"
#include "iostream"



class Graph;

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents),MainTime(0),coalitions({}) 
{
    
    for (Agent agent:mAgents) {
        Coalition mycol= Coalition(&agent,this->getNonConstParty(agent.getPartyId()));
        addCoalition(mycol);
    }   
    
}

vector<Coalition> *Simulation ::getCoalitionsList () {
    
    return &coalitions;

}

void Simulation :: addCoalition(Coalition col){

    coalitions.push_back(col);
}


void Simulation::step()
{
       
    MainTime +=1;
    int size= mGraph.getNumVertices();
    for(int i =0;i < size;i++){
        if(getNonConstParty(i)->getState()== CollectingOffers){
            if(MainTime - getNonConstParty(i)->getOfferTime() == 3 ){
            getNonConstParty(i)->step(*this);}
        }
        
    }

    vector<Agent> Agents = this->getAgents(); 
    for (int i=0;i<(int)Agents.size();i++){
        Agents[i].step(*this);    
    }
}
            
bool Simulation::shouldTerminate() const
{
    for(int i=0;i<(int)coalitions.size(); i++){
        if(coalitions[i].getCoalitionMandates() >60){
            return true;    
        }

    }
    for(int j=0;j<mGraph.getNumVertices();j++){
        if(mGraph.getParty(j).getState() != Joined)
            return false;
    }
    return true;
    
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

Graph* Simulation::getNonConstGraph() 
{
    return &mGraph;
}

int Simulation::getMainTime() const
{
    return MainTime;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

vector<Agent>* Simulation::getNonConstAgents() 
{
    return &mAgents;
}

int Simulation::getNumberOfAgents() const
{
    return mAgents.size();
}

Agent* Simulation:: getAgent(int id){

    return &(mAgents.at(id));
}
const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

Party* Simulation::getNonConstParty(int partyId) 
{
    return mGraph.getNonConstParty(partyId);
}


    


/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    vector<vector<int>> output;
    int size1 = coalitions.size();
    for(int i =0;i<size1;i++){
        vector<int> col;
        for(int j=0;j<getNumberOfAgents();j++){
            Agent agent = this->mAgents[j];
            int x= agent.getCoalitionId();
            if(x == i){
                int yespartyId = mAgents.at(j).getPartyId();
                col.push_back(yespartyId);
            }
        }
    output.push_back(col);
    }

    return output;
}


