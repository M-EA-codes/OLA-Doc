#pragma once
#include"Doctor.h"

class orthopedic :public doctor		////A class for orthopedic speacialization
{
	string specialization;
protected:
	orthopedic(int exp = 0, string hsptl = "", int avail_hrs = 0, int hrs_rate = 0, string locate = "", int u_t = 2, string cnic = "0000000000000", string u_n = "default", string psd = "Default@123", string specialization = "") :doctor(exp, hsptl, avail_hrs, hrs_rate, locate, u_t, cnic, u_n, psd)
	{
	}
};