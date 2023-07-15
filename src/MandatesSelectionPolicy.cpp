#include"../include/SelectionPolicy.h"

class Party;
class Simulation;
class Graph;


    Party* MandatesSelectionPolicy::choose(int myPartyId,vector <Party*> parties,Simulation &sim) 
    {
        Party* ChosenParty = parties[0];
        int size= parties.size();
        int maxmandates= ChosenParty->getMandates();
            for(int i =1;i<size;i++){
                int currentMandates= parties[i]->getMandates();
                if(maxmandates < currentMandates){
                    maxmandates= currentMandates;
                    ChosenParty = parties[i];
                }
                    
                    
            }
            return ChosenParty;
    }


    MandatesSelectionPolicy* MandatesSelectionPolicy:: clone() const{
        return new MandatesSelectionPolicy();
    }

    MandatesSelectionPolicy:: MandatesSelectionPolicy(){
        
    }
    MandatesSelectionPolicy:: ~MandatesSelectionPolicy(){

    }


