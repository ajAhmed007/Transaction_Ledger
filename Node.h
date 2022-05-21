#ifndef _Node_
#define _Node_
#include <iostream>
using namespace std;

class Node
{
protected:
    // pointer to the next node
    Node *next;

public:
   /**
    * @brief Construct a new Node object
    */
    Node();
    /**
     * @brief Destroy the Node object
     * 
     */
    ~Node();
    /**
     * @brief method to print the nodes
     * @param output ostream object
     * @param N a Node object
     * @return ostream& an ostream obj
     */
    friend ostream &operator<<(ostream &output, Node *N);
    /**
     * @brief Sets the next node pointer
     * @param nextNodeptr a Node pointer
     */
    void setNext(Node *nextNodeptr);
    /**
     * @brief Gets the next node pointer
     * @return Node* a Node pointer
     */
    Node *getNext() const;
    /**
     * @brief method to print nodes.
     * @return string 
     */
    virtual string printNode() const;
    
};

#endif
