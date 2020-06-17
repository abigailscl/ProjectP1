/***********************************************************************
 * Module:  Banca.h
 * Author:  Abigail
 * Modified: Saturday, June 13, 2020 21:35:23
 * Purpose: Declaration of the class Banca
 ***********************************************************************/
#pragma one
#if !defined(__ModeloBancario_Banca_h)
#define __ModeloBancario_Banca_h

class Person;

#include "Person.h"
#include <ostream>

using namespace std;

class BankStream {
public:
    BankStream();
    ~BankStream();
    Person registerPerson(void);
    Person readData(void);
    Person searchCustomer(void);
    void modifyFile(Person customer);
    void readFile(Person customer);

    Person** person;
private:
    ofstream file();
};
#endif
