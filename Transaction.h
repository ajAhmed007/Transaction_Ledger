#ifndef _TRANSACTION_
#define _TRANSACTION_
#include "Node.h"
#include <iostream>
using namespace std;

class Transaction : public Node {
    private:
        //person sending the money
        string fromName;
        //person receiving the money
        string toName;
        //amount being sent/deposited
        int amount;
    public:
        /**
         * @brief default constructor 
         * constructs a new Transaction object
         */
        Transaction();
        /**
         * @brief Destroy the Transaction object
         */
        ~Transaction();
        /**
         * @brief Construct a new Transaction object
         * @param fromName1 person sending the monet
         * @param toName1 person receiving the money
         * @param amount1 amount being sent/deposited
         */
        Transaction(string fromName1, string toName1, int amount1);
        /**
         * @brief method to set fromName
         * @param from_Name person sending the money
         */
        void setfromName(const string &from_Name);
        /**
         * @brief method to set toName
         * @param to_Name person receiving the monet
         */
        void setToName(const string &to_Name);
        /**
         * @brief method to set amount
         * @param to_mount amount being sent/deposited
         */
        void setToAmount(const int &to_mount);
        /**
         * @brief Get fromName 
         * @return string fromName
         */
        string getFromName() const;
        /**
         * @brief Get toName
         * @return string toName 
         */
        string getToName() const;
        /**
         * @brief Get amount
         * @return int amount 
         */
        int getAmount() const;
        /**
         * @brief method to print a Transaction 
         * @return string transaction nodes
         */
        virtual  string printNode() const;
};
#endif