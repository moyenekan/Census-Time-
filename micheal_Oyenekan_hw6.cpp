// micheal_Oyenekan_hw6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <fstream>
#include <string>
#include "Person.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <queue>
#include <iomanip>

using namespace std;
vector <Person> fileArray ;
void getfile();
void duplicateFirstName();
void duplicateCity();
void sortname();
void sortcity();




int main()
{

	getfile();// get all information from the file
	duplicateFirstName();// this prints out the sze of the unique first name
 sortname();// sorts out the unique first names
	 duplicateCity();// this prints out the sze of the unique city names
 sortcity(); //sorts out the unique city names

		return 0;
}

// get all information from the file
void getfile() {
	ifstream file;
	file.open("FakeNames.csv");

	string line, number;



	if (!file.is_open()) {
		cout << "File didnt open " << endl;
	}
	else {
		while (file.good()) {
			Person somebody;
			int pos1 = 0;
			getline(file, line);

			int pos2 = line.find(',', pos1);
			somebody.setNumber(line.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;

			pos2 = line.find(',', pos1);
			somebody.setGender(line.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;

			pos2 = line.find(',', pos1);
			somebody.setTitle(line.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;

			pos2 = line.find(',', pos1);
			somebody.setFName(line.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;

			pos2 = line.find(',', pos1);
			somebody.setMI(line.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;

			pos2 = line.find(',', pos1);
			somebody.setLName(line.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;

			pos2 = line.find(',', pos1);
			somebody.setStreet(line.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;

			pos2 = line.find(',', pos1);
			
			somebody.setCity(line.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;

			pos2 = line.find(',', pos1);
			somebody.setState(line.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;

			pos2 = line.find(',', pos1);
			somebody.setZip(line.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;

			pos2 = line.find(',', pos1);
			somebody.setEmail(line.substr(pos1, pos2 - pos1));
			pos1 = pos2 + 1;

			pos2 = line.find(',', pos1);
			somebody.setBirthday(line.substr(pos1, pos2 - pos1));
			fileArray.push_back(somebody);

		}
		// prints out thefirst and last person
		cout << "First Person: " << fileArray[1].getNumber() << ", " << fileArray[1].getFName() << fileArray[1].getMI() << ". " << fileArray[1].getLName() << ", " << fileArray[1].getBirthday() << endl;
		cout << "last Person: " << fileArray[6000].getNumber() << ", " << fileArray[6000].getFName() << fileArray[6000].getMI() << ". " << fileArray[6000].getLName() << ", " << fileArray[6000].getBirthday() << endl;
		cout << "Collection contains " << fileArray.size() << " records" << endl;

		ofstream file;
		file.open("person.txt");
		if (file.is_open()) {
			// prints out thefirst and last person
			file << "First Person: " << fileArray[1].getNumber() << ", " << fileArray[1].getFName() << fileArray[1].getMI() << ". " << fileArray[1].getLName() << ", " << fileArray[1].getBirthday() << endl;
			file << "last Person: " << fileArray[6000].getNumber() << ", " << fileArray[6000].getFName() << fileArray[6000].getMI() << ". " << fileArray[6000].getLName() << ", " << fileArray[6000].getBirthday() << endl;
			file << "Collection contains " << fileArray.size() << " records" << endl;
		}
		file.close();
	}

	file.close();

}

// this prints out the sze of the unique first name
void duplicateFirstName() {
	
	
	unsigned int counts;
	set<string> duplicate;	// loop to insert the duplicate 
	for (counts = 0; counts < fileArray.size(); counts++) {
		duplicate.insert(fileArray[counts].getFName());

	}
	cout << endl << "Collection contains " << duplicate.size() << "  Unique First names" << endl;
ofstream file;
	file.open("person.txt");
	if (file.is_open()) {
		file << endl << "Collection contains " << duplicate.size() << "  Unique First names" << endl;
	}
	file.close();
}
// sorts out the unique first names
void duplicateCity() {

	unsigned int counts;
	set<string> duplicate;
	// loop to insert the duplicate 
	for (counts = 0; counts < fileArray.size(); counts++) {
		duplicate.insert(fileArray[counts].getCity());

	}
	cout << endl << endl << "****************************************************************************************************" << endl;
	cout << endl << "Collection contains " << duplicate.size() << "  Unique city" << endl;
	ofstream file;
	file.open("person.txt");
	if (file.is_open()) {
		file << endl << endl << "****************************************************************************************************" << endl;
		file << endl << "Collection contains " << duplicate.size() << "  Unique First names" << endl;
	}
	file.close();
}

// this prints out the sze of the unique city names
void sortname() {

	int newline = 0;// this count is just a way for dispalay.

	int Hundred = 0; // show a 100 value.
	map<string, int> Names_count{}; // map that stors the name and couts it

	vector<pair<string, int>>  Sorted_Name;

	// this loop finds and remove the name
	for (vector<Person>::iterator it = fileArray.begin(); it != fileArray.end(); ++it)
	{
		string name = it->getFName();

		auto search = Names_count.find(name);
		if (search == Names_count.end())
		{
			Names_count[name] = 1;
		}
		else
		{

			Names_count[name] += 1;
		}
	}
	//the loop sorts the name
	for (map<string, int>::iterator itr = Names_count.begin(); itr != Names_count.end(); ++itr)
	{

		Sorted_Name.push_back(std::make_pair(itr->first, itr->second));
	}
	sort(Sorted_Name.begin(), Sorted_Name.end(), [=](std::pair<string, int>& a, std::pair<string, int>& b)
		{
			return a.second > b.second; });



	for (auto p : Sorted_Name)
	{
		if (Hundred == 100)
		{
			break;
		}
		else {
			cout << "      " << right << setw(14) << p.first << ": " << p.second;
			ofstream file;
			file.open("person.txt");
			if (file.is_open()) {
				file << "      " << right << setw(14) << p.first << ": " << p.second;
			}
			file.close();
			newline += 1;
			Hundred += 1;
			if (newline == 3) {
				cout << "\n";
				file << "\n";
				newline = 0;
			}
		}

	}
}

//sorts out the unique city names
void sortcity() {

	int newline = 0;// this count is just a way for dispalay.

	int Hundred = 0; // show a 100 value.
	map<string, int> Names_count{};

	vector<pair<string, int>>  Sorted_Name;

	// this loop finds and remove the name
	for (vector<Person>::iterator it = fileArray.begin(); it != fileArray.end(); ++it)
	{
		string name = it->getCity();

		auto search = Names_count.find(name);
		if (search == Names_count.end())
		{
			Names_count[name] = 1;
		}
		else
		{

			Names_count[name] += 1;
		}
	}
	//the loop sorts the name
	for (map<string, int>::iterator itr = Names_count.begin(); itr != Names_count.end(); ++itr)
	{

		Sorted_Name.push_back(std::make_pair(itr->first, itr->second));
	}
	sort(Sorted_Name.begin(), Sorted_Name.end(), [=](std::pair<string, int>& a, std::pair<string, int>& b)
		{
			return a.second > b.second; });



	for (auto p : Sorted_Name)
	{
		if (Hundred == 100)
		{
			break;
		}
		else {
			cout << "      " << right << setw(14) << p.first << ": " << p.second;
			ofstream file;
			file.open("person.txt");
			if (file.is_open()) {
			file << "      " << right << setw(14) << p.first << ": " << p.second;
			}
			
			newline += 1;
			Hundred += 1;
			if (newline == 3) {
				cout << "\n";
				file << "\n";
				newline = 0;
			}
			file.close();
		}

	}
}












