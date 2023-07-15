#pragma once
#include <vector>
//#include "Party.h"
//#include "Graph.h"


using std::vector;

class Party;
class Graph;
class Agent;
class Simulation;

class JoinPolicy{ 
    public:
        virtual Agent* join(vector <int>* agents,Simulation &sim) =0;
        virtual ~JoinPolicy() = default;
        virtual JoinPolicy* clone() const = 0;
};

class MandatesJoinPolicy: public JoinPolicy{
    public:
        MandatesJoinPolicy();
        ~MandatesJoinPolicy() override;
        Agent* join(vector <int>* agents,Simulation &sim);
        MandatesJoinPolicy* clone() const;
        
 };

class LastOfferJoinPolicy: public JoinPolicy{ 
    public:
        LastOfferJoinPolicy();
        ~LastOfferJoinPolicy() override;
        Agent* join(vector <int>* agents,Simulation &sim);
        LastOfferJoinPolicy* clone() const;
       
};