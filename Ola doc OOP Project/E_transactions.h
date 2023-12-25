#pragma once
#include<iostream>
#include"Payment.h"
using namespace std;

class e_transaction:payment		//A class for E_Transactions
{
	
protected:
	e_transaction(int total_fee = 0, int chrgs = 0, int fine = 0, bool refd = false) :payment(total_fee, chrgs, fine, refd)
	{

	}
};