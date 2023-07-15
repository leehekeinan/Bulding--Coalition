#pragma once
#include <vector>
#include "Party.h"
//#include "Graph.h"

using std::vector;

class Party;
class Simulation;


 class SelectionPolicy{ 
    public:
        virtual Party* choose(int myPartyId,vector <Party*> parties,Simulation &sim) =0 ;
        virtual ~SelectionPolicy()= default;
        virtual SelectionPolicy* clone() const = 0;
        

};

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy();
        ~MandatesSelectionPolicy() override;
        Party* choose(int myPartyId,vector <Party*> parties,Simulation &sim);
        MandatesSelectionPolicy* clone() const;
        
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{ 
    public:
        EdgeWeightSelectionPolicy();
        ~EdgeWeightSelectionPolicy() override;
        Party* choose(int myPartyId,vector <Party*> parties,Simulation &sim);
        EdgeWeightSelectionPolicy* clone() const;
        
};