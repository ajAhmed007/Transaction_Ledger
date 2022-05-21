#ifndef _Ledger_
#define _Ledger_
#include "Node.h"
#include "Transaction.h"
#include "State.h"
#include <iostream>

using namespace std;
class Ledger : public Node
{
private:
  // keeping track of the number of nodes
  int count;
  // pointer to the head
  Node *headPtr;
  // keeps track of the last state node
  State *lastStateNode;
  // tail node for adding nodes at the end
  Node *tail;
  /**
   * @brief helper method used for inTheBlack() and inTheRed()
   * @param which an in used to determine whether negative or positive
   */
  void inTheWhatEver(int which);

public:
  /**
   * @brief Construct a new Ledger object
   */
  Ledger();
  /**
   * @brief Destroy the Ledger object
   * 
   */
  ~Ledger();
  /**
   * @brief Set the next pointer
   * @param nextNodeptr
   */
  void setNext(Ledger *nextPtr);
  /**
   * @brief returns a pointer to the next node
   * @return Node* pointer to the next node
   */
  Node *getNext() const;
  /**
   * @brief method for print the ledger
   * @param output ostream object
   * @param L Ledger object
   * @return ostream& an ostream object
   */
  friend ostream &operator<<(ostream &out, const Ledger &L);
  
  /**
   * @brief prints the name and balance of each user
   * using the the state nodes.
   * @param L Ledger object
   */
  void settle(const Ledger &L);
  /**
   * @brief adds a Transaction to the ledger. Every 10
   * transactions, automatically inserts a State node
   * that summarizes the current values of each account.
   * @param t Transaction object
   * @return Ledger a Ledger object
   */
  Ledger operator+=(const Transaction &t);
  /**
   * @brief deletes a single exact match of a Transaction
   * with the same FromName, ToName, and Amount,
   * but only if it hasn't been included in a State
   * node yet. If the node isn't found then
   * throw an exception.
   * @param t
   * @return Ledger
   */
  Ledger operator-=(const Transaction &t);
  /**
   * @brief overloaded method to add nodes into the transaction
   * @param toName1
   * @param fromName1
   * @param amount1
   * @return true if add is successfull
   * @return false otherwise
   */
  bool populate(const string &toName1, const string &fromName1, const int &amount1);
  /**
   * @brief Removes all the transactions
   */
  void Clear();
  /**
   * @brief method to add transaction nodes
   * @return true if add is successfull
   * @return false otherwise
   */
  bool addNode(const Transaction &);
  /**
   * @brief method to keep the pointer moving
   * updates the Node pointers.
   * @param node
   */
  void traverse(Node *node);

  /**
   * @brief prints the name and balance of each user
   * using the state nodes.
   */
  void Settle();

  /**
   * @brief using the state nodesprints the names and
   * balance of each user who has positive money
   */
  void InTheBlack();
  /**
   * @brief using the state nodesprints the names and
   * balance of each user who has negative money
   */
  void InTheRed();
};
#endif