#pragma once
#include<string>
#include"user.h"

class doctor :public user		//A Class for doctors
{
protected:
	int experience_years;
//	int specialization area,
	char hospital[30];
	int	availability_hours;
	int h_rate;
	char location[20];
public:		
	//Default and Parametrized constructor
	doctor(int exp=0,string hsptl="", int avail_hrs=0, int hrs_rate=0, string locate="", int u_t = 2, string cnic = "0000000000000", string u_n = "default", string psd = "Default@123") :user(u_t, cnic, u_n, psd)
	{
		set_exp(exp);
		set_hospital(hsptl);
		availability_hours = avail_hrs;
		set_h_rate(hrs_rate);
		set_location(locate);
	}

	void set_exp(int e)			//setter for experience
	{
		bool flag = false;
		while(flag)
		{
			if (e >= 0)
			{
				experience_years = e;
			}
			else
			{
				cout << "\nEnter valid experience: " << endl;
				cin >> e;
			}
		}
	}

	void set_hospital(string hsptl)		//setter for Hospital
	{
		strcpy_s(hospital, hsptl.c_str());
	}

	void set_location(string locate)	//setter for location
	{
		strcpy_s(location, locate.c_str());
	}

	void set_h_rate(int s)			//setter for Hourly rate
	{
		bool flag = false;
		while (flag)
		{
			if (s > 0)
			{
				h_rate = s;
			}
			else
			{
				cout << "\nEnter valid Hourly Rate: " << endl;
				cin >> s;
			}
		}
	}

	char* get_hospital()		//getter for Hospital
	{
		return hospital;
	}

	char* get_location()		//getter for Location
	{
		return location;
	}

	int get_exp()				//getter for experience
	{
		return experience_years;
	}

	int get_h_rate()			//getter for Available hours
	{
		return availability_hours;
	}

	bool verify_credentials(string file, string usn, string pasd)		//Polymorphically implemented function for validation of login credentials
	{
		char usnm[25];
		char paswd[30];
		strcpy_s(usnm, usn.c_str());
		strcpy_s(paswd, pasd.c_str());
		doctor temp;
		bool flag = false;
		ifstream myFile(file, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)) && flag == false)	////compairing data from for login
		{
			bool u1 = false;
			bool p1 = false;

			if (strcmp(usnm, temp.get_username()) == 0)
			{
				u1 = true;
			}

			if (strcmp(paswd, temp.get_password()) == 0)
			{
				p1 = true;
			}

			if ((u1 == true) && (p1 == true))
			{
				cout << "\nLogged In Successfully:" << endl;
				return true;
				myFile.close();
			}

		}
		cout << "\nWrong Credentials:" << endl;
		return false;
	}

	void Display()					//A function to display attributes of doctor
	{
		string un=get_username();
		cout << "Username: " << un << endl;
		cout << "CNIC#: " << get_CNIC() << endl;
		cout << "Experience: " << get_exp() << endl;
		cout << "Current Hospital: " << get_hospital() << endl;
		cout << "Current City: " << get_location() << endl;
	}
};