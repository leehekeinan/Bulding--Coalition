#include"../include/SelectionPolicy.h"

class Party;
class Simulation;
class Graph;   
      
   
Party* EdgeWeightSelectionPolicy::choose(int myPartyId,vector <Party*> parties,Simulation &sim) 
    {
        Party* ChosenParty = parties.at(0);
        int maxweight = 0;
        int size= parties.size();
        for(int i =0;i<size;i++){
            Graph* graph= sim.getNonConstGraph();
            int currentWeight= graph->getEdgeWeight(parties[i]->getId(),myPartyId); 
            if(currentWeight > maxweight){
                maxweight = graph->getEdgeWeight(parties[i]->getId(),myPartyId);
                ChosenParty = parties[i];
            }

        }
        return ChosenParty;
    }

EdgeWeightSelectionPolicy* EdgeWeightSelectionPolicy:: clone() const{
    return new EdgeWeightSelectionPolicy();
}

EdgeWeightSelectionPolicy :: ~EdgeWeightSelectionPolicy(){

    }

EdgeWeightSelectionPolicy:: EdgeWeightSelectionPolicy(){
        
    }

 