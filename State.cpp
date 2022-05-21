#include "State.h"
#include "Node.h"
#include <stdlib.h>
#include <map>
#include <iostream>
using namespace std;

/**
 * @brief Construct a new State object
 */
State::State()
{
}

/**
 * @brief Construct a new State object taking a
 * pointer to a State
 * @param previousState a pointer to the previous State
 */
State::State(const State *previousState)
{
        bankBook = previousState->bankBook;
        addToPrevousState((Transaction *)previousState->getNext(), bankBook);
}

/**
 * @brief Construct a new State object taking a
 * pointer to a Transaction
 * @param headPtr a pointer to a Transaction
 */
State::State(const Transaction *previousState)
{
         addToPrevousState(previousState, bankBook);
}

/**
 * @brief Destroy the State:: State object
 */
State::~State()
{
        previousState = nullptr;
        //bankBook.size() == 0;
}

/**
 * @brief method that adds to the previous state
 * given the map that hold the customer names and
 * balances
 * @param curr a Transaction pointer to keep track of the current Transaction
 * @param bankBook the map containing the customer names and balances
 */
void State::addToPrevousState(const Transaction *curr, map<string, int> &bankBook)
{
        for (; curr != nullptr; curr = (Transaction *)curr->getNext())
        {
                string toTarget = curr->getToName();
                string fromTarget = curr->getFromName();
                int amountTarget = curr->getAmount();
        
                updatesMap(toTarget, fromTarget, amountTarget, bankBook);
        }
}
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
void State::updatesMap(const string &toTarget, const string &fromTarget, int amountTarget, map<string, int> &bankBook)
{
        //checking whether fromName is external 
        if (fromTarget != "EXTERNAL")
        {
                //finds the name in the map
                auto search = bankBook.find(fromTarget);
                //while we're not at the end of the map...
                if (search != bankBook.end())
                {
                        //the amount is the previous amount - current amount 
                        int amount = search->second - amountTarget;
                        bankBook[fromTarget] = amount;
                }
                else
                {       //otherwise, inser new amount
                        bankBook.insert(pair<string, int>(fromTarget, 0 - amountTarget));
                        
                }
        }
        //do the following if not "EXTERNAL"
        auto search = bankBook.find(toTarget);
        if (search != bankBook.end())
        {
                int amount = search->second + amountTarget;
                bankBook[toTarget] = amount;
        }
        else
        {
                bankBook.insert(pair<string, int>(toTarget, amountTarget));
               
        }
}

/**
 * @brief method that prints a State.
 * @return string
 */
string State::printNode() const
{
        string s = "";
        map<string, int>::const_iterator it;
        string prefix = "*STATE_NODE: ";
        for (it = bankBook.begin(); it != bankBook.end(); it++)
        {
                s += prefix;
                s += it->first;
                s += " ";
                s += to_string(it->second);
                prefix = ", ";
        }
        return s;
}

map<string, int> State::getMap()
{
        return bankBook;
}
