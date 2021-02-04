/*
 * eligibility.h
 *
 *  Created on: 22-Apr-2020
 *      Author: sunbeam
 */
#include<iostream>
#include<cstring>
using namespace std;
#include <fstream>
#include <sstream>
#include<map>
#include<vector>

#define ELIGIBILITY_FILE "include/eligibilities.csv"
#include"course.h"

#ifndef ELIGIBILITY_H_
#define ELIGIBILITY_H_
class course;
class eligibility
{

public:
	string course_name;
	string degree;
	int min_percentage;

public:
	eligibility();
	eligibility(string &crn,string &deg,int per);
	void set_course_name(const string &str);
	void set_degree(const string &str1);
	void set_min_percentage(int num1);
	string& get_course_name();
	string& get_degree();
	int get_min_percentage();
	void display_eligibility();
	//course* find_course_eligibilty(vector<course> &courses,const string &course_name);
	//void load_eligibility_csv(vector<course> &courses);
};




#endif /* ELIGIBILITY_H_ */
