#include"../include/JoinPolicy.h"
#include"../include/Agent.h"

class Simulation;
class Agent;


    Agent* LastOfferJoinPolicy::join(vector <int>* agents,Simulation &sim) 
    {
        int chosenAgentId= agents->back();
        Agent* agent= sim.getAgent(chosenAgentId);
        return agent;
    }
    LastOfferJoinPolicy:: ~LastOfferJoinPolicy(){
        
    }
    LastOfferJoinPolicy::LastOfferJoinPolicy(){
        
    }
    LastOfferJoinPolicy* LastOfferJoinPolicy:: clone() const{
    return new LastOfferJoinPolicy();
    }