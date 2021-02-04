/*
 * center.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */
#include<iostream>
#include<cstring>
using namespace std;
#define CENTERS_FILE "include/centers.csv"

#include<map>
#ifndef CENTER_H_
#define CENTER_H_

#include"capacities.h"
class capacities;

class center{
public:

	string center_id;
	string center_name;
	string address;
	string coordinator;
	string password;
	map<string, int> course_cap;
public:

		center();
		center(const string &str1,const string &str2,const string &str3,const string &str4,const string &str5);
		void display();
		void displaycap(vector<capacities> &cs);
		void set_center_id(const string &str1);
		void set_center_name(const string &str2);
		void set_center_address(const string &str3);
		void set_center_coordinator(const string &str4);
		void set_center_password(const string &str5);
		string& get_center_id();
		string& get_center_name();
		string& get_center_address();
		string& get_center_coordinator();
		string& get_center_password();
		//map<string, int>& get_centermap();
		string& get_first_ele_map();
};



#endif /* CENTER_H_ */
