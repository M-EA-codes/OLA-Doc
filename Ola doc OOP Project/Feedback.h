#pragma once
#include<iostream>
#include<string>
#include"fstream"
using namespace std;

class feedback		//A class for taking Feedback
{
protected:
	char usn[20];
	int rati;
	char fedbck[100];
public:

	//constructor
	feedback(string usnm="", int rater = 0, string feedbck = "")
	{
		rati = rater;
		strcpy_s(fedbck, feedbck.c_str());
		strcpy_s(usn, usnm.c_str());
	}

	void set_usn(string s)		//A setter for username
	{
		strcpy_s(usn, s.c_str());
	}
	void set_rating(int r)			//A setter for Rating
	{
		rati = r;
	}
	void set_feedback(string s)			//A setter for Feedback
	{
		strcpy_s(fedbck, s.c_str());
	}

	int get_rating()		//A getter for rating
	{
		return rati;
	}
	char* get_feedback()		//A getter for Feedback
	{
		return fedbck;
	}

	void give_feedback(string file, feedback& temp)		//A function for taking feedback
	{
//		feedback temp;
		ofstream myFile(file, ios::binary | ios::app);
		myFile.write((char*)&temp, sizeof(temp));
		myFile.close();
	}
	

};