/*
 * eligibility.cpp
 *
 *  Created on: 22-Apr-2020
 *      Author: sunbeam
 */
#include"eligibility.h"

	eligibility::eligibility()
		{
			degree="xyz";
			min_percentage=0;
		}
	eligibility::eligibility(string &crn,string &deg,int per)
		{
			course_name=crn;
			degree=deg;
			min_percentage=per;
		}
	void eligibility::set_course_name(const string &str)
		{
			course_name=str;
		}
	void eligibility::set_degree(const string &str1)
		{
			degree=str1;
		}
	void eligibility::set_min_percentage(int num1)
		{
			min_percentage=num1;
		}
	string& eligibility::get_course_name()
		{
			return course_name;
		}

	string& eligibility::get_degree()
		{
			return degree;
		}
	int eligibility::get_min_percentage()
		{
			return min_percentage;
		}

	void eligibility::display_eligibility()
		{
			cout<<"		"<<"--->   Degree -> "<<degree<<"   Minimum  % -> "<<min_percentage<<endl;
		}




