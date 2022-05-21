#include "Transaction.h"
#include "Node.h"
#include <iostream>

using namespace std;

/**
 * @brief default constructor
 * constructs a new Transaction object
 */
Transaction::Transaction()
{
}

/**
 * @brief Construct a new Transaction object
 * @param fromName1 person sending the monet
 * @param toName1 person receiving the money
 * @param amount1 amount being sent/deposited
 */
Transaction::Transaction(string toName1, string fromName1, int amount1)
{
  fromName = fromName1;
  toName = toName1;
  amount = amount1;
}

/**
 * @brief method to set fromName
 * @param from_Name person sending the money
 */
void Transaction::setfromName(const string &from_Name)
{
  fromName = from_Name;
}
/**
 * @brief Destroy the Transaction:: Transaction object
 */
Transaction::~Transaction()
{
  toName = "";
  fromName = "";
  amount = 0;
}

/**
 * @brief method to set toName
 * @param to_Name person receiving the monet
 */
void Transaction::setToName(const string &to_Name)
{
  toName = to_Name;
}

/**
 * @brief method to set amount
 * @param to_mount amount being sent/deposited
 */
void Transaction::setToAmount(const int &to_amount)
{
  amount = to_amount;
}

/**
 * @brief Get fromName
 * @return string fromName
 */
string Transaction::getFromName() const
{
  return fromName;
}

/**
 * @brief Get toName
 * @return string toName
 */
string Transaction::getToName() const
{
  return toName;
}

/**
 * @brief Get amount
 * @return int amount
 */
int Transaction::getAmount() const
{
  return amount;
}

/**
 * @brief method to print a Transaction
 * @return string transaction nodes
 */
string Transaction::printNode() const
{
  string s = "";
  s += toName;
  s += " ";
  s += fromName;
  s += " ";
  s += to_string(amount);
  return s;
}
