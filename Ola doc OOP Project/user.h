#pragma once
//#include"olaDoc.h"
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

bool is_CNIC_valid(string cnic)	//A function to check validity of CNIC
{
	bool flag = true;
	int i = 0;
	while (i < cnic.size() && flag)
	{
		if (cnic[i] == '0' || cnic[i] == '1' || cnic[i] == '2' || cnic[i] == '3' || cnic[i] == '4' || cnic[i] == '5' || cnic[i] == '6' || cnic[i] == '7' || cnic[i] == '8' || cnic[i] == '9')
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
		i++;
	}

	if (cnic.size() == 13 && flag)
	{
		//cout << "CNIC IS VALID:-" << endl;
		return true;
	}
	else
	{
		//cout << "CNIC IS NOT VALID:-" << endl;
		return false;
	}
} 

bool is_username_valid(string un)	//A function to check validity of username
{
	bool flag=true;
	int i = 0;
	while (i < un.length() && flag == true)
	{
		if (un[i] >= 65 && un[i] <= 90 || (un[i] == 32))
		{
			flag = true;
		}
		else if (un[i] >= 97 && un[i] <= 122)
		{
			flag = true;
		}
		else
		{
			//cout << "\nUsername is not valid:- " << endl;
			return false;
		}
		i++;
	}

	if (flag==true)
	{
		//cout << "\nUsername is valid:-" << endl;
		return flag;
	}
	else
	{
		return false;
	}

}

bool is_password_valid(string pswd)	//A function to check validity of Password
{
	bool flag = true;
	bool has_capital = false;
	bool has_small = false;
	bool has_number = false;
	bool has_character = false;
	int i = 0;
	while (i < pswd.length() && flag == true)
	{
		if (pswd.length() >= 8)
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
		if (pswd[i] >= 65 && pswd[i] <= 90)
		{
			//flag = true;
			has_capital = true;
		}
		
		if (pswd[i] >= 97 && pswd[i] <= 122)
		{
			//flag = true;
			has_small = true;
		}
		
		if (pswd[i] >= 33 && pswd[i] <= 47 || (pswd[i] >= 58 && pswd[i] <= 64))
		{
			//flag = true;
			has_character = true;
		}
		
		if (pswd[i] >= 48 && pswd[i] <= 57)
		{
			//flag = true;
			has_number = true;
		}
		i++;
	}

	if (has_capital && flag && has_small && has_number && has_character)
	{
		//cout << "\nPassword is valid:-" << endl;
		return true;
	}
	else
	{
		return false;
	}
	//cout << "Returning flag: " << flag << endl;
	//return flag;
}


template<typename T>
bool is_CNIC_unique(string file, string cnic)	//A function to check Uniqueness of CNIC
{
	char CNIC[15];
	strcpy_s(CNIC, cnic.c_str());
	T temp;
	ifstream myFile(file, ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp)))
	{
		if (strcmp(CNIC, temp.get_CNIC()) == 0)
		{
			return false;
			myFile.close();
		}
	}
	return true;
}


class user		//A main class of users
{
protected:
	int user_type;
	char CNIC[14];
	char username[20];
	char password[20];
public:
	//Default and Parametrized Constructor
	user(int u_t = 1, string cnic = "0000000000000", string u_n = "default", string psd = "Default123")
	{
		user_type = u_t;
		//cout << "Usertype assigned: " << endl;
		set_password(psd);
		//cout<<"Password Set successfully: "<<endl;
		set_username(u_n);
		//cout << "Username Set successfully: " << endl;
		set_CNIC(cnic);
		//cout<<"CNIC Set successfully: "<<endl;
	}

	void set_CNIC(string cnic)	// A setter for CNIC
	{
		bool done = false;
		while (done == false)
		{
			if (is_CNIC_valid(cnic) == true)
			{
				strcpy_s(CNIC, cnic.c_str());
				done = true;
			}
			else
			{
				cout << "\nPlease re-enter the correct CNIC again: ";
				getline(cin, cnic);

				if (is_CNIC_valid(cnic) == true)
				{
					strcpy_s(CNIC, cnic.c_str());
					done = true;
				}
			}
		}
	}

	void set_username(string un)	////A setter for username
	{
			bool done = false;
			while (done == false)
			{
				if (is_username_valid(un) == true)
				{
					strcpy_s(username, un.c_str());
					done = true;
				}
				else
				{
					cout << "\nPlease re-enter the correct Username again: ";
					getline(cin, un);

					if (is_username_valid(un) == true)
					{
						strcpy_s(username, un.c_str());
						done = true;
					}
				}
			}
		}

	void set_password(string psd)//A setter for password
	{
		bool done = false;
		while (done == false)
		{
			//cout << "Before validation: " << endl;
			if (is_password_valid(psd) == true)
			{
				//cout << "Before copying: " << endl;
				strcpy_s(password, psd.c_str());
				done = true;
			}
			else
			{
				cin.ignore();
				cout << "\nPlease re-enter the correct Password again: ";
				getline(cin, psd);

				if (is_password_valid(psd) == true)
				{
					strcpy_s(password, psd.c_str());
					done = true;
				}
			}
		}
	}

	
	char* get_CNIC()	//A Getter for CNIC
	{
		return CNIC;
	}

	char* get_username()	//A Getter for Username
	{
		return username;
	}	
	
	char* get_password()	//A Getter for Password
	{
		return password;
	}

	// Copy constructor
	user(const user& u1)
	{
		user_type = u1.user_type;
		strcpy_s(CNIC, u1.CNIC);
		strcpy_s(username, u1.username);
		strcpy_s(password, u1.password);
	}

	virtual void verify_credentials()
	{

	}

	virtual void Display()
	{

	}
	
	template<typename T>
	bool Registration(string file, T& object)		//For Registration
	{
		ofstream myFile(file, ios::binary | ios::app);
		myFile.write((char*)&object, sizeof(object));
		myFile.close();

		return true;
	}


};