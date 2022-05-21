#include <iostream>
#include "Ledger.h"
#include "Transaction.h"

using namespace std;

int main () {

	Ledger myLedger;
	
	Transaction t1 = Transaction("alice", "EXTERNAL", 100);
	Transaction t2 = Transaction("bob", "EXTERNAL", 10);
	Transaction t3 = Transaction("fred", "EXTERNAL", 50);

	// test adding money
	myLedger += t1;
	myLedger += t2;
	myLedger += t3;
	
	myLedger += Transaction("alice", "fred", 50);
	myLedger += Transaction("bob", "fred", 100);
	myLedger += Transaction("sam", "alice", 100);
	myLedger += Transaction("alice", "fred", 30);
	Transaction t4 = Transaction("fred", "bob", 2) ;
	myLedger += t4;

	
	
	myLedger -= t4;

	for (int i = 0; i < 50; i++) {
		myLedger +=  Transaction("fred", "carol", 1);
	}

	cout << myLedger << endl;
	cout << endl << endl;
	myLedger.Settle();
	cout << endl << endl;
	myLedger.InTheBlack();
	cout << endl << endl;
	myLedger.InTheRed();

	myLedger.Clear();
	
	cout << myLedger << endl;






	return 0;
}
