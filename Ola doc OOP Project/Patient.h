#pragma once
#include"user.h"

class patient :public user		//A class for patient
{
protected:

public:
	//Default and Parametrized constructor
	patient(int u_t = 3, string cnic = "0000000000000", string u_n = "default", string psd = "Default@123") :user(u_t, cnic, u_n, psd)
	{

	}


	bool verify_credentials(string file, string usn, string pasd)	////Polymorphically implemented function for validation of login credentials
	{
		char usnm[25];
		char paswd[30];
		strcpy_s(usnm, usn.c_str());
		strcpy_s(paswd, pasd.c_str());
		patient temp;
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

	void Display()
	{
		string un = get_username();
		cout << "Username: " << un << endl;
		cout << "CNIC#: " << get_CNIC() << endl;
	}
};