#include "Node.h"
#include <ostream>

#include <iostream>

using namespace std;
/**
 * @brief Construct a new Node object
 */
Node::Node()
{
}
/**
 * @brief Destroy the Node:: Node object
 * 
 */
Node::~Node(){

}
/**
 * @brief method to print the nodes
 * @param output ostream object
 * @param N a Node object
 * @return ostream& an ostream obj
 */
ostream &operator<<(ostream &output, Node *N)
{

  // Node *ptr = N;
  output << "head";
  for (Node *ptr = N; ptr != nullptr; ptr = ptr->next)
  {
    output << " -> "
           << "[" << ptr->printNode() << "]";
  }
  output << " -> nullPtr" << endl;
  return output;
}

/**
 * @brief Sets the next node pointer
 * @param nextNodeptr a Node pointer
 */
void Node::setNext(Node *nextNodeptr)
{
  next = nextNodeptr;
}

/**
 * @brief Gets the next node pointer
 * @return Node* a Node pointer
 */
Node *Node::getNext() const
{
  return next;
}

/**
 * @brief method to print nodes.
 * @return string
 */
string Node::printNode() const
{
  string sNode = "";
  return sNode;
}