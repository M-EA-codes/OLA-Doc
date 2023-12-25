#pragma once
#include<iostream>
#include"E_transactions.h"

class jazzcash :public e_transaction	//A class for transaction through Jazzcash
{
	int balance;
protected:
	jazzcash(int bal= 0, int total_fee = 0, int chrgs = 0, int fine = 0, bool refd = false):e_transaction(total_fee, chrgs, fine, refd)
	{
		balance = bal;
	}
};