#pragma once
#include<iostream>
#include"user.h"
#include<string>
using namespace std;


class olaDoc	//main class in which user is composed
{
protected:
	user man;

public:
	olaDoc(int u_t = 1, string cnic = "0000000000000", string u_n = "default", string psd = "Default@123"):man(u_t, cnic, u_n, psd)
	{

	}
}; 
