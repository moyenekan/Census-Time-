#include "Person.h"
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;


Person::Person()
{
}


Person::~Person()
{
}

void Person::setNumber(string n) {
	number = n;
}
string Person::getNumber() {
	return number;
}
void Person::setGender(string g) {
	gender = g;
}
string Person::getGender() {
	return gender;
}
void Person::setTitle(string t) {
	title = t;
}
string Person::getTitle() {
	return title;
}
void Person::setFName(string FN) {
	fName = FN;
}
string Person::getFName() {
	return fName;
}
void Person::setMI(string i) {
	mI = i;
}
string Person::getMI() {
	return mI;
}
void Person::setLName(string LN) {
	lName = LN;
}
string Person::getLName() {
	return lName;
}
void Person::setStreet(string s) {
	street = s;
}
string Person::getStreet() {
	return street;
}
void Person::setCity(string c) {
	city = c;
}
string Person::getCity() {
	return city;
}
void Person::setState(string st) {
	state = st;
}
string Person::getState() {
	return state;
}
void Person::setZip(string z) {
	zip = z;
}
string Person::getZip() {
	return zip;
}
void Person::setEmail(string f) {
	email = f;
}
string Person::getEmail() {
	return email;
}
void Person::setBirthday(string b) {
	birthday = b;
}
string Person::getBirthday() {
	return birthday;
}

