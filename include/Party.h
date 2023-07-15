#pragma once
#include <string>
#include <vector>
#include "Agent.h"
#include "JoinPolicy.h"

using std::vector;
using std::string;
class JoinPolicy;
class Simulation;
class Agent;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *jp); 
    Party(const Party& other);
    ~Party();
    Party& operator=(const Party& other);
    Party(Party&& other);
    Party& operator=(Party&& other);
    State getState() const;
    void setState(State state);
    int getMandates() const;
    int getId() const;
    void step(Simulation &s);
    const string &getName() const;
    int getOfferTime() const;
    vector<int>* getAgentList();
    vector<int> &getOffersList() ; 
    void setOfferTime(int newtime);
    
    

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    vector<int> offers;
    int offerTime;
    vector<int> AgentList; 
};
