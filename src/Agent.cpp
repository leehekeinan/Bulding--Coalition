#include "Agent.h"
//#include"Graph.h"


Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), myCoalitionId(agentId)
{
    
}

Agent::Agent(const Agent& other): mAgentId(other.mAgentId),mPartyId(other.mPartyId),mSelectionPolicy (other.mSelectionPolicy->clone()), myCoalitionId(other.myCoalitionId)
{
}

void Agent:: clear(){

    if(mSelectionPolicy!=nullptr)
      delete mSelectionPolicy;
}


Agent::~Agent(){
    clear();
}

Agent& Agent:: operator=(const Agent& other){
    if(this!=&other){
        clear();
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy;
        myCoalitionId = other.getCoalitionId();
    }
    return *this;

}
Agent::Agent (Agent&& other): mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy),myCoalitionId(other.getCoalitionId())
{
    other.mSelectionPolicy = nullptr;

}

Agent& Agent:: operator=(Agent&& other){
    if(this != &other){
      clear();
      mAgentId = other.mAgentId;
      mPartyId = other.mPartyId;
      mSelectionPolicy = other.mSelectionPolicy;
      myCoalitionId = other.myCoalitionId;
      other.mSelectionPolicy = nullptr;
     }
    return *this;
}

int Agent::getId() const
{
    return mAgentId;
}


void Agent:: SetPartyId(int newid){
  mPartyId = newid;
}

void Agent:: SetId(int newid){
  mAgentId = newid;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::setCoalitionId(int mycolId){

  myCoalitionId = mycolId;

}


int Agent::getCoalitionId () const
{
    return myCoalitionId;
}

void Agent::step(Simulation &sim)
  {
  
  vector <Party*> toSelection;
  int mpartyid = getPartyId();
  Graph* graph= sim.getNonConstGraph();
  for(int j=0;j<graph->getNumVertices();j++){
    if(graph->getEdgeWeight(mpartyid,j)>0){
      Party* optional_party = graph->getNonConstParty(j);
      if(optional_party->getState() != Joined){
        if(optional_party->getState() == CollectingOffers)
        {
          int size= optional_party->getOffersList().size();
          bool ans =true;
          for(int k=0; k<size && (ans!=false) ; k++){
            if (optional_party->getOffersList()[k]== myCoalitionId)
              ans = false;
          }
          if(ans == true){
            toSelection.push_back(optional_party);
          } 
        }
        else{
            toSelection.push_back(optional_party);
          }
      }

    }
  }
    if(toSelection.size()!=0){
      Party* chosen = mSelectionPolicy->choose(this->getPartyId(),toSelection,sim);
      if(chosen->getState() == Waiting){
        chosen->setState(CollectingOffers);
        chosen->setOfferTime(sim.getMainTime());
       }
      chosen->getOffersList().push_back(myCoalitionId);
      chosen->getAgentList()->push_back(mAgentId);
    }

  }



   

