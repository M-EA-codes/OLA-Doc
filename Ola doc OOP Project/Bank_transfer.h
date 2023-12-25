#pragma once
#include"Payment.h"

class bank_transfer:public payment		//Class for Bank transfers
{	
	int Branch_code;
protected:
	bank_transfer(int brch_code,int total_fee = 0, int chrgs = 0, int fine = 0, bool refd = false) :payment(total_fee, chrgs, fine, refd)
	{
		Branch_code=brch_code;
	}

};