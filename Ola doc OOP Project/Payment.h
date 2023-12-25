#pragma once


class payment
{
	int Total_fee;
	int charges;
	int Due_fine;
	bool refund;

protected:
	payment(int total_fee = 0, int chrgs = 0, int fine = 0,bool refd=false) :charges(chrgs), Total_fee(total_fee), Due_fine(fine),refund(refd)
	{

	}

	int calculate_fine()
	{
		return Due_fine;
	}

	void Apply_for_refund()
	{
		cout << "Refund Granted" << endl;
		refund = true;
	}
};