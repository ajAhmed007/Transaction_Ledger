#ifndef _STATE_
#define _STATE_
#include <map>

#include "Transaction.h"
#include "Node.h"
#include <iostream>
using namespace std;

class State : public Node
{
private:
      //map to hold customer names and balances
      map<string, int> bankBook;
      //a pointer to the previous state node
      State *previousState;

public:
      /**
       * @brief Construct a new State object
       */
      State();
      /**
       * @brief Destroy the State object
       */
      ~State();
      /**
       * @brief Construct a new State object taking a 
       * pointer to a Transaction
       * @param headPtr a pointer to a Transaction
       */
      State(const Transaction *headPtr);
      /**
       * @brief Construct a new State object taking a
       * pointer to a State
       * @param previousState a pointer to the previous State
       */
      State(const State *previousState);
      /**
       * @brief method that adds to the previous state 
       * given the map that hold the customer names and 
       * balances
       * @param curr a Transaction pointer to keep track of the current Transaction
       * @param bankBook the map containing the customer names and balances
       */
      static void addToPrevousState(const Transaction *curr, map<string, int> &bankBook);
      /**
       * @brief method that updates the map. 
       * Checks whethe the person sending the money is external 
       * if not it will update the amounts of the fromName and toName 
       * accordingly.
       * @param toTarget person receiving the money
       * @param fromTarget person sending the money
       * @param amountTarget amount reveived
       * @param bankBook a map that holds each customer and their balance
       */
      static void updatesMap(const string &toTarget, const string &fromTarget, int amountTarget, map<string, int> &bankBook);
      void settle(const State &L);
      /**
       * @brief method that prints a State.
       * @return string 
       */
      virtual string printNode() const;
      /**
       * @brief method to retreive the map.
       * @return map<string, int> of customer names and balances
       */
      map<string, int> getMap();
};
#endif
