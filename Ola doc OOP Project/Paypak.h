#pragma once
#include"Bank_transfer.h"
#include<string>
using namespace std;

class paypak :public bank_transfer	//A Class for payment through Pay-Pak 
{
	string Branch_name;
protected:
	paypak(string bank_nm,int brch_code, int total_fee = 0, int chrgs = 0, int fine = 0, bool refd = false) :bank_transfer(brch_code,total_fee, chrgs, fine, refd)
	{
		Branch_name = bank_nm;
	}

};