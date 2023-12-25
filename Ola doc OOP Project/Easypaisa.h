#pragma once
#include"E_transactions.h"
#include<iostream>

class easypaisa :public e_transaction		//A class for payment through easypaisa
{
	int balance;
	protected:
		easypaisa(int bal = 0, int total_fee = 0, int chrgs = 0, int fine = 0, bool refd = false) :e_transaction(total_fee, chrgs, fine, refd)
		{
			balance = bal;
		}
	};