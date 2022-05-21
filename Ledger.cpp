#include "Ledger.h"
#include "Transaction.h"
#include "State.h"
#include "Node.h"
#include <iostream>
#include <map>
using namespace std;

/**
 * @brief Construct a new Ledger object
 */
Ledger::Ledger()
{
  //initializing the member variables
  headPtr = nullptr;
  tail = nullptr;
  count = 0;
  lastStateNode = nullptr;
}

/**
 * @brief Destroy the Ledger:: Ledger object
 */
Ledger::~Ledger(){

}

/**
 * @brief method for print the ledger
 * @param output ostream object
 * @param L Ledger object
 * @return ostream& an ostream object
 */
ostream &operator<<(ostream &out, const Ledger &L)
{
  out << L.headPtr;
  return out;
}

/**
 * @brief Set the next pointer
 * @param nextNodeptr
 */
void Ledger::setNext(Ledger *nextPtr)
{
  next = nextPtr;
}

/**
 * @brief returns a pointer to the next node
 * @return Node* pointer to the next node
 */
Node *Ledger::getNext() const
{
  return headPtr;
}

/**
 * @brief adds a Transaction to the ledger. Every 10
 * transactions, automatically inserts a State node
 * that summarizes the current values of each account.
 * @param t Transaction object
 * @return Ledger a Ledger object
 */
Ledger Ledger::operator+=(const Transaction &t)
{
  //calling the helper add method to add transactions
  this->addNode(t);
  return *this;
}

/**
 * @brief method to add transaction nodes
 * @return true if add is successfull
 * @return false otherwise
 */
bool Ledger::addNode(const Transaction &T)
{
  //calling populate to add each member of the transactions
  return populate(T.getToName(), T.getFromName(), T.getAmount());
}

/**
 * @brief adds each member of the transactions.
 * @param toName1
 * @param fromName1
 * @param amount1
 * @return true if add is successfull
 * @return false otherwise
 */
bool Ledger::populate(const string &toName, const string &fromName, const int &amount)
{
  Transaction *linkedNode = new Transaction(toName, fromName, amount);
  
  traverse(linkedNode);
  count++;
  //reached a state node 
  if (count % 10 == 0)
  {
    // creating a state Node
    if (lastStateNode == nullptr)
    {
      //automatically creating a state node each time
      lastStateNode = new State((Transaction *)headPtr);
    }
    else
    {
      lastStateNode = new State(lastStateNode);
    }
    //traversing the list
    traverse(lastStateNode);
  }
  return true;
}

/**
 * @brief method to keep the pointer moving
 * updates the Node pointers.
 * @param node
 */
void Ledger::traverse(Node *node)
{
  if (headPtr == nullptr)
  {
    headPtr = node;
  }
  else
  {
    tail->setNext(node);
  }
  tail = node;
}

/**
 * @brief helper method used for inTheBlack() and inTheRed()
 * @param which an in used to determine whether negative or positive
 */
void Ledger::inTheWhatEver(int which)
{
  map<string, int> newMap;
  if (lastStateNode != nullptr)
  {
    //getMap() returns the map containing the customer
    //names and balances
    newMap = lastStateNode->getMap();
    //adding the last state node next.
    State::addToPrevousState((Transaction *)lastStateNode->getNext(), newMap);
  }
  else
  {
    //otherwise adding the head of the tractions 
    State::addToPrevousState((Transaction *)headPtr, newMap);
  }

  map<string, int>::const_iterator it;

  //for loop to print the map contents
  for (it = newMap.begin(); it != newMap.end(); it++)
  {
    // cout<<"testing in the black 3 ..."<<endl;
    int balance = it->second;
    if (balance * which > 0)
    {
      //cust names 
      cout << it->first;
      cout << " ";
      //cust amounts
      cout << balance;
      cout << endl;
    }
  }
}

/**
 * @brief using the state nodesprints the names and
 * balance of each user who has positive money
 */
void Ledger::InTheBlack()
{

  // State newNode = new State();
  // cout<<"testing in the black ..."<<endl;
  cout << "In The Black:" << endl;
  inTheWhatEver(1);
}

/**
 * @brief using the state nodesprints the names and
 * balance of each user who has negative money
 */
void Ledger::InTheRed()
{
  cout << "In The Red:" << endl;
  inTheWhatEver(-1);
}

/**
 * @brief prints the name and balance of each user
 * using the the state nodes.
 * @param L Ledger object
 */
void Ledger::Settle()
{
  cout << "Settle(): " << endl;
  cout << lastStateNode;
}

/**
 * @brief Removes all the transactions
 */
void Ledger::Clear()
{
  cout << "clearing Ledger..." << endl;
  Node *nodeToDeletePtr;
  while (headPtr != nullptr)
  {
    nodeToDeletePtr = headPtr;
    headPtr = headPtr->getNext();

    // return node to the system
    nodeToDeletePtr->setNext(nullptr);
    delete nodeToDeletePtr;
  }
  nodeToDeletePtr = nullptr;
  count = 0;
}

/**
 * @brief deletes a single exact match of a Transaction
 * with the same FromName, ToName, and Amount,
 * but only if it hasn't been included in a State
 * node yet. If the node isn't found then
 * throw an exception.
 * @param t
 * @return Ledger
 */
Ledger Ledger::operator-=(const Transaction &s)
{
  Transaction *curr = (Transaction *)((lastStateNode != nullptr) ? lastStateNode->getNext() : headPtr);
  //previous transaction
  Transaction *prev = (Transaction *)lastStateNode;
  for (; curr != nullptr; curr = (Transaction *)curr->getNext())
  {

    if (curr->getFromName() == s.getFromName() && curr->getToName() == s.getToName() && curr->getAmount() == s.getAmount())
    {
      if (prev == nullptr)
      {
        //prev must be before head 
        headPtr = curr->getNext();
      }
      else
      {
        //moving previous forward
        prev->setNext((Transaction *)curr->getNext());
      }
      if (curr == tail)
      {
        tail = prev;
      }
      curr->setNext(nullptr);
      //deleteing the transaction
      delete curr;
      return *this;
    }
    
    prev = curr;
  }

  return *this;
}
