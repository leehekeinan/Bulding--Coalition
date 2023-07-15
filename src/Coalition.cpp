#include"../include/Coalition.h"


class Agent;

Coalition::Coalition(Agent* agent,Party* party):ColId(agent->getId()),NumberOfmMandates(party->getMandates())
{
} 

int Coalition::getCoalitionMandates() const{
    return NumberOfmMandates;
}
void Coalition::setCoalitionMandates(int num) {
     NumberOfmMandates += num;
}
int Coalition::getColId() const{
    return ColId;
}
    








