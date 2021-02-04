/*
 * capacities.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */

#include<iostream>
#define CAPACITY_FILE "include/capacities.csv"
using namespace std;

#include<cstring>
#include<vector>

#include <fstream>
#include <sstream>

#ifndef CAPACITIES_H_
#define CAPACITIES_H_

#include "course.h"
#include "center.h"
class center;
class course;

class capacities
	{
	 public:
		string center_id;
		string course_name;
		int capacity;
		int filled_capacity;
	public:
		capacities();
		capacities(string &str1,string &str2,int num1,int num2);
		void set_capacity(int num1);
		void set_filled_capacity(int num2);
		string& get_course_name();
		string& get_center_id();
		int get_center_capacity();
		int get_filled_capacity();
		void display();
		center* find_center(vector<center>&cntr,const string &center_id);
		course* find_course(vector<course>&crs, const string &course_name);
		void load_capacities_csv(vector<capacities> &cp, vector<center> &cntr, vector<course> &crs);

	};



#endif /* CAPACITIES_H_ */
