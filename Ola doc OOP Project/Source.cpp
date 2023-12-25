#include<iostream>
#include"user.h"
#include"Patient.h"
#include"Doctor.h"
#include"olaDoc.h"
#include"Admin.h"
#include"Feedback.h"
using namespace std;


int main()
{
	bool first_menu = true;
	bool second_menu = false;
	bool admin_menu = false;
	bool doctor_menu = false;
	bool patient_menu = false;
	int choice = 0;

	while (first_menu)	// First main menu
	{
		cout << "\\********************************************************************************/\n\n";
		cout << "\t********************  Wellcome to Ola Doc  ********************\n\n" << endl;
		cout << "\t\t\t**********  Main Menu  **********" << endl;

		cout << "1. Login as Admin.\n" << endl;
		cout << "2. Login as Doctor.\n" << endl;
		cout << "3. Login as Patient.\n" << endl;
		cout << "4. For Signup/Register.\n" << endl;
		cout << "0. Exit." << endl;

		cin >> choice;

		switch (choice)
		{
		case 0:
		{
			exit(0);
			break;
		}
		case 1:
		{
			string un;
			string psd;

			cin.ignore();
			cout << "Please enter your username: " << endl;
			getline(cin, un);

			cin.ignore();
			cout << "Please enter your password: " << endl;
			cin >> psd;
			Admin A;

			admin_menu = A.verify_credentials("Admin_file.dat", un, psd);
			if (admin_menu)
			{
				second_menu = false;
				first_menu = false;
			}
			else
			{
				first_menu = true;
			}
			break;
		}
		case 2:
		{
			string un;
			string psd;

			cin.ignore();
			cout << "Please enter your username: " << endl;
			getline(cin, un);

			cin.ignore();
			cout << "Please enter your password: " << endl;
			cin >> psd;
			doctor A;
			doctor_menu = A.verify_credentials("Doctor_file.dat", un, psd);
			if (doctor_menu)
			{
				second_menu = false;
				first_menu = false;
			}
			else
			{
				first_menu = true;
			}
			break;
		}

		case 3:
		{

			string un;
			string psd;

			cin.ignore();
			cout << "Please enter your username: " << endl;
			getline(cin, un);

			cin.ignore();
			cout << "Please enter your password: " << endl;
			cin >> psd;
			patient A;

			patient_menu = A.verify_credentials("Patients_file.dat", un, psd);
			if (patient_menu)
			{
				second_menu = false;
				first_menu = false;
			}
			else
			{
				first_menu = true;
			}
			break;

		}
		case 4:
		{
			first_menu = false;
			second_menu = true;
			break;
		}
		default:
		{
			cout << "\nEnter a valid number: " << endl;
			break;
		}
		}

	while (admin_menu)	// Admin Menu
	{
		int c1;
		cout << "\n******************************\n" << endl;
		cout << "1. Add Doctor." << endl;
		cout << "2. Update Doctor." << endl;
		cout << "3. Show Doctors." << endl;
		cout << "4. Show all patients." << endl;
		cout << "5. Log out." << endl;
		cout << "6. Exit" << endl;

		cin >> c1;

		switch (c1)
		{
		case 1:
		{
			cout << "Registering a new Doctor: " << endl;

			int ut = 1;
			int exp;
			int h_rate;

			string usn;
			string cnic;
			string pasd1 = "Doct@123";
			string pasd2 = "pas";
			string hospital;
			string location;

			doctor dr_1;

			cout << "Please enter your username: ";
			cin.ignore();
			getline(cin, usn);

			dr_1.set_username(usn);
			cout << "Please enter your CNIC: ";
			cin >> cnic;

			bool flag = false;
			while (flag == false)
			{
				if (is_CNIC_unique<typename doctor>("Doctor_file.dat", cnic) == true)
				{
					flag = true;
				}
				else
				{
					cout << "This CNIC also exist in the system: \nPlease Reenter CNIC number:" << endl;
					cin >> cnic;
					flag = false;
				}
			}

			dr_1.set_CNIC(cnic);

			while (pasd1 != pasd2)
			{
				cin.ignore();
				cout << "Please enter your password: ";
				cin >> pasd1;

				cin.ignore();
				cout << "Please re-enter your password to confirm: ";
				cin >> pasd2;
			}

			dr_1.set_password(pasd1);

			cout << "Please enter your experience in years:";
			cin >> exp;
			dr_1.set_exp(exp);

			cin.ignore();
			cout << "Please enter your current hospital_name:";
			cin >> hospital;

			dr_1.set_hospital(hospital);

			cout << "Please enter your hourly rate: ";
			cin >> h_rate;

			dr_1.set_h_rate(h_rate);

			cin.ignore();
			cout << "Please enter your current city: ";
			cin >> location;

			dr_1.Registration<typename doctor>("Doctor_file.dat", dr_1);
			cout << "Registered Successfully:\n" << endl;
			break;
		}
		case 2:
		{
			cout << "Doctor Updated Successfully";
			break;
		}
		case 3:
		{
			cout << "Showing Doctors:" << endl;
			doctor temp;
			ifstream myFile("Doctor_file.dat", ios::binary);
			while (myFile.read((char*)&temp, sizeof(temp)))
			{
				temp.Display();
				myFile.close();
			}
		}
		case 4:
		{
			cout << "Showing Patients:" << endl;
			patient temp;
			ifstream myFile("Patients_file.dat", ios::binary);
			while (myFile.read((char*)&temp, sizeof(temp)))
			{
				temp.Display();
				myFile.close();
			}
			break;
		}
		case 5:
		{
			first_menu = true;
			break;
		}
		case 6:
		{
			exit;
			break;
		}
		default:
		{
			cout << "Please enter a valid number." << endl;
			break;
		}
		}

	}

	while (doctor_menu)	//Doctor Menu
	{
		int s;
		cout << "***********************" << endl;
		cout << "1. Show Doctors.\n";
		cout << "2. Show Appointments.\n";
		cout << "3. Log out.\n";
		cout << "4. Exit.\n";
		cin >> s;

		switch (s)
		{
		case 1:
		{
			cout << "Showing Doctor:" << endl;
			doctor temp;
			ifstream myFile("Doctor_file.dat", ios::binary);
			while (myFile.read((char*)&temp, sizeof(temp)))
			{
				temp.Display();
				myFile.close();
			}
			first_menu = true;
			break;
		}

		case 2:
		{
			cout << "Total Appointments:-\n 0 Appointments" << endl;
			first_menu = true;
			break;

		}
		case 3:
		{
			cout << "Logging Out: " << endl;
			first_menu = true;
		}

		case 4:
		{
			exit;
			break;
		}
		default:
			break;
		}
	}

	while (patient_menu) //Patient Menu
	{
		int s;
		cout << "***********************" << endl;
		cout << "1. Show Doctors.\n";
		cout << "2. Show Appointments.\n";
		cout << "3. Book Appointment.\n";
		cout << "4. Give Feedback.\n";
		cout << "5. Give Payment\n";
		cout << "6. Log out.\n";
		cout << "7. Exit.\n";
		cin >> s;

		switch (s)
		{
		case 1:
		{
			cout << "Showing Doctor:" << endl;
			doctor temp;
			ifstream myFile("Doctor_file.dat", ios::binary);
			while (myFile.read((char*)&temp, sizeof(temp)))
			{
				temp.Display();
				myFile.close();
			}
			first_menu = true;
			break;
		}

		case 2:
		{
			cout << "Total Appointments:-\n 0 Appointments" << endl;
			first_menu = true;
			break;

		}

		case 3:
		{
			int b;
			cout << "Appointment Booking:-" << endl;
			cout << "1. Inperson.\n" << endl;
			cout << "2. Video_consultation." << endl;
			cin >> b;

			cout << "Appointment Done." << endl;
			break;
		}

		case 4:
		{
			string usn;
			int rat;
			string fedbck;

			cin.ignore();
			cout << "Enter Username of doctor for feedback:\n";
			getline(cin, usn);

			cout << "Enter your rating out of 5:" << endl;
			cin >> rat;

			cin.ignore();
			cout << "Enter your Feedback:";
			getline(cin, fedbck);

			feedback F1(usn, rat, fedbck);

			F1.give_feedback("feedback.dat", F1);
		}

		case 5:
		{
			int s;
			cout << "1. Bank Transfer:" << endl;
			cout << "2. E-transaction:" << endl;
			cin >> s;

			if (s == 1)
			{
				int p;
				cout << "1. PAYPAK:" << endl;
				cout << "2. Union Pay:" << endl;
				cin >> p;

				cout << "Enter Account Number: " << endl;
				cin >> s;
				if (p == 1)
				{
					cout << "Payment done through PayPak:" << endl;
				}
				else
				{
					cout << "Payment done through Union Pay: " << endl;
				}
			}
			else
			{
				int p;
				cout << "1. Jazzcash:" << endl;
				cout << "2. Easypaisa:" << endl;
				cin >> p;

				cout << "Enter Phone no. " << endl;
				cin >> s;

				if (p == 1)
				{
					cout << "Payment done through Jazzcash:" << endl;
				}
				else
				{
					cout << "Payment done through Easypaisa: " << endl;
				}
			}
			break;
		}

		case 6:
		{
			cout << "Logging Out: " << endl;
			first_menu = true;
			break;
		}

		case 7:
		{
			exit(0);
			break;
		}
		default:
			break;
		}

	}

	while (second_menu)
	{
		cout << "\\********************************************************************************/\n\n";
		cout << "1. Register as Admin.\n" << endl;
		cout << "2. Register as Doctor.\n" << endl;
		cout << "3. Register as Patient.\n" << endl;
		cout << "4. Go Back.\n" << endl;
		cout << "0. Exit." << endl;

		cin >> choice;

		switch (choice)
		{
		case 0:
		{
			exit;
			break;
		}
		case 1:
		{
			cout << "Registering a new admin: " << endl;

			int ut = 1;
			string usn;
			string cnic;
			string pasd1 = "Admin@123";
			string pasd2 = "pas";

			Admin Ad_1;

			cout << "Please enter your username: ";
			cin.ignore();
			getline(cin, usn);

			Ad_1.set_username(usn);
			cout << "Please enter your CNIC: ";
			cin >> cnic;

			bool flag = false;
			while (flag == false)
			{
				if (is_CNIC_unique<typename Admin>("Admin_file.dat", cnic) == true)
				{
					flag = true;
				}
				else
				{
					cout << "This CNIC also exist in the system: \nPlease Reenter CNIC number:" << endl;
					cin >> cnic;
					flag = false;
				}
			}
			Ad_1.set_CNIC(cnic);

			while (pasd1 != pasd2)
			{
				cout << "Please enter your password: ";
				cin >> pasd1;

				cout << "Please re-enter your password to confirm: ";
				cin >> pasd2;
			}

			Ad_1.set_password(pasd1);

			Ad_1.Registration<typename Admin>("Admin_file.dat", Ad_1);
			cout << "Registered Successfully:\n" << endl;
			break;
		}

		case 2:
		{
			cout << "Registering a new Doctor: " << endl;

			int ut = 1;
			int exp;
			int h_rate;

			string usn;
			string cnic;
			string pasd1 = "Doct@123";
			string pasd2 = "pas";
			string hospital;
			string location;

			doctor dr_1;

			cout << "Please enter your username: ";
			cin.ignore();
			getline(cin, usn);

			dr_1.set_username(usn);
			cout << "Please enter your CNIC: ";
			cin >> cnic;

			bool flag = false;
			while (flag == false)
			{
				if (is_CNIC_unique<typename doctor>("Doctor_file.dat", cnic) == true)
				{
					flag = true;
				}
				else
				{
					cout << "This CNIC also exist in the system: \nPlease Reenter CNIC number:" << endl;
					cin >> cnic;
					flag = false;
				}
			}

			dr_1.set_CNIC(cnic);

			while (pasd1 != pasd2)
			{
				cin.ignore();
				cout << "Please enter your password: ";
				cin >> pasd1;

				cin.ignore();
				cout << "Please re-enter your password to confirm: ";
				cin >> pasd2;
			}

			dr_1.set_password(pasd1);

			cout << "Please enter your experience in years:";
			cin >> exp;
			dr_1.set_exp(exp);

			cin.ignore();
			cout << "Please enter your current hospital_name:";
			cin >> hospital;

			dr_1.set_hospital(hospital);

			cout << "Please enter your hourly rate: ";
			cin >> h_rate;

			dr_1.set_h_rate(h_rate);

			cin.ignore();
			cout << "Please enter your current city: ";
			cin >> location;

			dr_1.Registration<typename doctor>("Doctor_file.dat", dr_1);
			cout << "Registered Successfully:\n" << endl;
			break;
		}

		case 3:
		{
			cout << "Registering a new patient: \n";
			int ut = 1;
			string usn;
			string cnic;
			string pasd1 = "Patin@123";
			string pasd2 = "pas";

			patient pat_1;

			cout << "Please enter your username: ";
			cin.ignore();
			getline(cin, usn);

			pat_1.set_username(usn);
			cout << "Please enter your CNIC: ";
			cin >> cnic;

			bool flag = false;
			while (flag == false)
			{
				if (is_CNIC_unique<typename patient>("Patients_file.dat", cnic) == true)
				{
					flag = true;
				}
				else
				{
					cout << "This CNIC also exist in the system: \nPlease Reenter CNIC number:" << endl;
					cin >> cnic;
					flag = false;
				}
			}

			pat_1.set_CNIC(cnic);

			while (pasd1 != pasd2)
			{
				cout << "Please enter your password: ";
				cin >> pasd1;

				cout << "Please re-enter your password to confirm: ";
				cin >> pasd2;
			}

			pat_1.set_password(pasd1);
			cout << "Password set successfully: " << endl;

			pat_1.Registration<typename patient>("Patients_file.dat", pat_1);
			cout << "Registered Successfully:\n" << endl;
			break;
		}

		case 4:
		{
			first_menu = true;
			second_menu = false;
			break;
		}

		default:
		{
			cout << "Enter valid number" << endl;
			break;
		}

		}

	}

}
	return 0;
}