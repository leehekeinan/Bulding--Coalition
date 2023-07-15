#pragma once
//#include "Agent.h"
#include "Party.h"
class Agent;
class Party;
using std:: vector;

class Coalition
{
public:
    Coalition(Agent* agent,Party* party);
    int getCoalitionMandates() const;
    void setCoalitionMandates(int num);
    int getColId() const;

private:
    int ColId;
    int NumberOfmMandates;
    
};
