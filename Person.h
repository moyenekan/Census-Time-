#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Person
{
private:



string number, gender, title, fName, mI, lName, street, city, state, zip, email, birthday;



public:
	

	Person();
	~Person();

	void setNumber(string n);
	string getNumber();
	void setGender(string g);
	string getGender();
	void setTitle(string t);
	string getTitle();
	void setFName(string FN);
	string getFName();
	void setMI(string i);
	string getMI();
	void setLName(string LN);

	string getLName();
	void setStreet(string s);
	string getStreet();
	void setCity(string c);
	string getCity();
	void setState(string st);
	string getState();
	void setZip(string z);
	string getZip();
	void setEmail(string f);
	string getEmail();
	void setBirthday(string b);
	string getBirthday();
	



};

