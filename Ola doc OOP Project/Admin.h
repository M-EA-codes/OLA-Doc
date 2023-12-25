#pragma once
#include"user.h"
#include"Appointment.h"


//An Admin Class
class Admin :public user
{
protected:
	appointment* app;		//Aggregation of Appointment
public:
	Admin(int u_t = 1, string cnic = "0000000000000", string u_n = "default", string psd = "Default@123") :user(u_t, cnic, u_n, psd)
	{

	}

	// Copy constructor
	Admin(const Admin& A1)	
	{
		user_type = A1.user_type;
		strcpy_s(CNIC, A1.CNIC);
		strcpy_s(username, A1.username);
		strcpy_s(password, A1.password);
		app = A1.app;
	}

	bool verify_credentials(string file, string usn,string pasd)	//Polymorphically implemented function for validation of login credentials
	{
		char usnm[25];
		char paswd[30];
		strcpy_s(usnm, usn.c_str());
		strcpy_s(paswd, pasd.c_str());
		Admin temp;
		bool flag = false;
		ifstream myFile(file, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)) && flag == false)		//compairing data from for login
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
		cout << "\nWrong Credentials:" << endl;  //Incase of invalid credentials
		return false;
	}

};