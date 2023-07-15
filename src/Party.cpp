#include "Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting),offers({}),offerTime(0),AgentList({}) 
{
   AgentList.reserve(10);

}

Party::Party(const Party& other): mId(other.mId),mName(other.mName), mMandates(other.mMandates),mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState), offers(other.offers), offerTime(other.offerTime), AgentList(other.AgentList)
{

}

   
Party::~Party(){
    if(mJoinPolicy != nullptr){
        delete mJoinPolicy;
    mJoinPolicy = nullptr;
    }
    
}

Party& Party:: operator=(const Party& other){
    if(this!=&other){
        this->~Party();
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy;
        AgentList = other.AgentList;
        offerTime = other.offerTime;
        offers = other.offers;
    }
    return *this;

}

Party::Party(Party&& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), offers(other.offers), offerTime(other.offerTime), AgentList(other.AgentList)
{
    other.mJoinPolicy = nullptr;

}

Party& Party:: operator=(Party&& other){
    if(this != &other){
        this->~Party();
        mId = other.getId();
        mName = other.getName();
        mMandates = other.getMandates();
        mJoinPolicy = other.mJoinPolicy;
        AgentList = other.AgentList;
        offerTime = other.getOfferTime();
        offers = other.getOffersList();
        other.mJoinPolicy = nullptr;
    }
    return *this;


}

State Party::getState() const
{
    return mState;
}

vector <int>& Party:: getOffersList() {

    return offers;
}

void Party::setState(State state)
{
    mState = state;
}

vector<int>* Party::getAgentList() 
{
    
    return &AgentList;
}

int Party::getOfferTime() const
{
    return offerTime;
}
void Party::setOfferTime(int newtime) 
{
     offerTime = newtime;
}
int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

int Party::getId() const
{
    return mId;
}


void Party::step(Simulation &s)
{
    vector <int>* myAgentList = &AgentList;
    Agent* const chosen = mJoinPolicy->join(myAgentList, s);
    this->setState(Joined);
    Agent newagent = Agent(*chosen);
    newagent.SetId(s.getNumberOfAgents());
    newagent.SetPartyId(mId);
    s.getCoalitionsList()->at(newagent.getCoalitionId()).setCoalitionMandates(this->getMandates());
    s.getNonConstAgents()->push_back(newagent);


               
    }

       


    

