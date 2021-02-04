/*
 * course.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */
#include<iostream>
#include<cstring>
using namespace std;
#include <fstream>
#include <sstream>
#include<map>
#include<vector>

#define COURSES_FILE "include/courses.csv"

#ifndef COURSE_H_
#define COURSE_H_
#include"eligibility.h"
#include"capacities.h"
class capacities;
class course{
public:
	int course_id;
	string course_name;
	string course_fees;
	string section;
	vector<eligibility> elg;
	map<string,int>center_cap;

public:
	course();
	course(int cid, string &cname, string &fee, string &sec);
	void set_course_id(int cid);
	void set_course_name(const string& cname);
	void set_course_fee( string &fee);
	void set_section(string &sec);
	int get_course_id();
	string& get_course_name();
	string& get_course_fee();
	string& get_section();

	void display();

	void display_center_cap(vector<capacities> &cap);

	void display_course_eligibility();
	//void load_course_csv(vector<course> &courses);
};




#endif /* COURSE_H_ */
