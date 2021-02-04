/*
 * admission.h
 *
 *  Created on: 22-Apr-2020
 *      Author: sunbeam
 */

#ifndef ADMISSION_H_
#define ADMISSION_H_

#include<iostream>
using namespace std;

#include "student.h"
#include "course.h"
#include"eligibility.h"
#include "center.h"
#include "degree.h"
#include "capacities.h"

#include<algorithm>
#include<vector>
#include<map>
#include <fstream>
#include <sstream>
class admission
{
public:
	student s;
	preference pf;
	course cs;
	center cn;
	capacities cps;
	vector<degree> degrees;
	vector<student> students;
	//vector<preference> preferences;
	vector<course>courses;
	//vector<eligibility> eligibilities;
	vector<center>centers;
	vector<capacities> capcity;

public:
	admission();
student *find_std(vector<student> &std ,int formno);

void load_student_csv(vector<student> &students);
void save_students(vector<student>& students);
void save_students_for_fee(vector<student>& students);
void load_preference_csv(vector<student> &std);

void save_students_preference(vector<student>&std );

void load_degree(vector<degree> &dg);

//void admission::save_degree(vector<degree> &dg);

void load_course_csv(vector<course> &courses);

course* find_course_eligibilty(vector<course> &courses,const string &course_name);

void load_eligibility_csv(vector<course> &courses);

void load_center_csv(vector<center> &cntr);

center* find_center(vector<center>&cntr,const string &center_id);

course* find_course(vector<course>&crs, const string &course_name);

void load_capacities_csv(vector<capacities> &cp, vector<center> &cntr, vector<course> &crs);

void save_capacity(vector<capacities>& capacity);

void first_round_A_allocation(int j,int pos);

void first_round_B_allocation(int j,int pos);

void first_round_C_allocation(int j,int pos);

void Find_Student_Not_Filled_Payment();

void Clear_allocated_center();

void second_round_allocation();
	virtual ~admission();
};

#endif /* ADMISSION_H_ */
