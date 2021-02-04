/*
 * course.cpp
 *
 *  Created on: 22-Apr-2020
 *      Author: sunbeam
 */
#include"course.h"

course::course()
		{
			course_id=0;
			course_name="xyz";
			course_fees="0";
			section='a';
		}

course::course(int cid, string &cname, string &fee, string &sec) {
		course_id = cid;
		course_name = cname;
		course_fees = fee;
		section = sec;
		}

		void course::set_course_id(int cid) {
			course_id = cid;
		}
		void course::set_course_name(const string& cname) {
			course_name = cname;
		}
		void course::set_course_fee( string &fee) {
			course_fees = fee;
		}
		void course::set_section(string &sec) {
			section = sec;
		}
		int course::get_course_id() {
			return course_id;
		}
		string& course::get_course_name() {
			return course_name;
		}
		string& course::get_course_fee() {
			return course_fees;
		}
		string& course::get_section() {
			return section;
		}

	void course::display()
		{	cout<<endl;
			cout<<"COURSE ID 		: "<<course_id<<endl;
			cout<<"COURSE NAME 		: "<<course_name<<endl;
			cout<<"COURSE FEE		: "<<course_fees<<endl;
			cout<<"SECTION		  	: "<<section<<endl;
		}

	void course::display_center_cap(vector<capacities> &cap)
		{
			map<string, int> ::iterator itr;
			itr=center_cap.begin();
			while(itr!=center_cap.end())
			{
				cap[itr->second].display();//error
				itr++;
			}
		}

	void course::display_course_eligibility()
	{
		unsigned i;
		for(i=0;i<elg.size();i++){
		elg[i].display_eligibility();//error
		}
	}




