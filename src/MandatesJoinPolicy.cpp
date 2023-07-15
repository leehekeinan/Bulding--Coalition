#include"../include/JoinPolicy.h"
#include"../include/Agent.h"

class Simulation;
class Agent;


    Agent* MandatesJoinPolicy::join(vector <int>* agents,Simulation &sim) 
    {
        int chosenAgentId= agents->at(0);
        Agent* ChosenAgent = sim.getAgent(chosenAgentId);
        int maxmandates= sim.getCoalitionsList()->at(ChosenAgent->getCoalitionId()).getCoalitionMandates();
        int size = agents->size();
        for(int i =0;i<size;i++){
            Agent* optinalAgent= sim.getAgent(agents->at(i));
            int currentmandates= sim.getCoalitionsList()->at(optinalAgent->getCoalitionId()).getCoalitionMandates();
            if (currentmandates > maxmandates) {
                ChosenAgent = optinalAgent;
                maxmandates= currentmandates;
            }      
            }
        return ChosenAgent;
    }
            
    
    MandatesJoinPolicy:: ~MandatesJoinPolicy(){
        
    }

    MandatesJoinPolicy::MandatesJoinPolicy(){
        
    }
    MandatesJoinPolicy* MandatesJoinPolicy:: clone() const{
    return new MandatesJoinPolicy();
    }

 


