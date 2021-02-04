/*
 * student.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */
#include<cstring>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
#include <fstream>
#include <sstream>
#include<algorithm>
#define STUDENT_FILE "include/students.csv"
#define PREFERENCES_FILE "include/preferences.csv"

#ifndef STUDENT_H_
#define STUDENT_H_

class student;

class preference
{
public:
	int form_no;
	int preference_no;
	string course_name;
	string center_id;
public:
	preference()
		{	form_no=0;
			preference_no=0;
			course_name="abc";
			center_id="xyz";
		}
	preference(int num1,int num2,string &str1,string str2)
		{	form_no=num1;
			preference_no=num2;
			course_name=str1;
			center_id=str2;
		}
	void set_form_no(int no)
		{
			form_no=no;
		}
	void set_preference_no(int num)
		{
			preference_no=num;
		}
	void set_course_name(const string &str)
		{
			course_name=str;
		}
	void set_center_id(const string &str)
		{
			center_id=str;
		}
	int get_form_no()
		{
			return form_no;
		}
	int get_preference_no()
		{
			return preference_no;
		}
	string get_course_name()
		{
			return course_name;
		}
	string get_center_id()
		{
			return center_id;
		}
	void display()
		{
			cout<<"form no- "<<form_no<<" ,"<<"Pref no- "<<preference_no<<" ,"<<"Course name- "<<course_name<<" ,"<<"Center id- "<<center_id<<endl<<endl;;

		}
};

class student{
public:
	int form_no;
	string name;
	int rank_a_section;
	int rank_b_section;
	int rank_c_section;
	string degree;
	float percentage;
	int allocated_preference;
	string allocated_course_name;
	string allocated_center_id;
	float payment;
	int reported_to_center;
	string PRN;
	vector<preference> prf;
public:
	student()
			{
				form_no=0;
				name="abc";
				rank_a_section=0;
				rank_b_section=0;
				rank_c_section=0;
				degree="xyz";
				percentage=0.0;
				allocated_preference=0;
				allocated_course_name="NA";
				allocated_center_id="NA";
				payment=0;
				reported_to_center=0;
				PRN="NA";
			}

	student(int num1,string &str1,int num2,int num3,int num4,string &str2,float num5,int num6,string &str3,string &str4,float num7,int num8,string &str5)
		{
			form_no=num1;
			name=str1;
			rank_a_section=num2;
			rank_b_section=num3;
			rank_c_section=num4;
			degree=str2;
			percentage=num5;
			allocated_preference=num6;
			allocated_course_name=str3;
			allocated_center_id=str4;
			payment=num7;
			reported_to_center=num8;
			PRN=str5;
		}

	void set_form_no(int num1)
		{
			form_no=num1;
		}

	void set_student_name(const string &str1)
		{
			name=str1;
		}

	void set_rank_a_section(int num2)
		{
			rank_a_section=num2;
		}

	void set_rank_b_section(int num3)
		{
			rank_b_section=num3;
		}

	void set_rank_c_section(int num4)
		{
			rank_c_section=num4;
		}

	void set_degree(const string &str2)
		{
			degree=str2;
		}

	void set_percentage(float num5)
		{
			percentage=num5;
		}

	void set_allocated_preference(int num6)
		{
			allocated_preference=num6;
		}

	void set_allocated_course_name(const string &str3)
		{
			allocated_course_name=str3;
		}

	void set_allocated_center_id(const string &str4)
		{
			allocated_center_id=str4;
		}

	void set_payment(float num7)
		{
			payment=num7;
		}

	void set_reported_to_center(int num)
		{
			reported_to_center=num;
		}

	void set_PRN(const string &str6)
		{
			PRN=str6;
		}

	int get_form_no()
		{
			return form_no;
		}

	string get_student_name()
		{
			return name;
		}

	int get_rank_a_section()
		{
			return rank_a_section;
		}

	int get_rank_b_section()
		{
			return rank_b_section;
		}

	int get_rank_c_section()
		{
			return rank_c_section;
		}

	string get_degree()
		{
			return degree;
		}

	float get_percentage()
		{
			return percentage;
		}

	int get_allocated_preference()
		{
			return allocated_preference;
		}

	string get_allocated_course_name()
		{
			return allocated_course_name;
		}

	string get_allocated_center_id()
		{
			return allocated_center_id;
		}

	float get_payment()
		{
			return payment;
		}

	int get_reported_to_center()
		{
			return reported_to_center;
		}

	string get_PRN()
		{
			return PRN;
		}


		void display()
		{
			cout<<form_no<<",  "<<name<<",	"<<rank_a_section<<",  "<<rank_b_section<<",  "<<rank_c_section<<",  "<<degree<<",  "<<percentage<<",  "<<allocated_preference<<",  "<<allocated_course_name<<",  "<<allocated_center_id<<",  "<<payment<<",  "<<reported_to_center<<",  "<<PRN <<endl<<endl;
		}

		void display_prf()
		{
			unsigned i;
			for(i=0;i<prf.size();i++)
			{
				cout << "  -";
				prf[i].display();
			}
		}

};



#endif /* STUDENT_H_ */
