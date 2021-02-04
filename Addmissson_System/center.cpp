/*
 * center.cpp
 *
 *  Created on: 22-Apr-2020
 *      Author: sunbeam
 */
#include"center.h"
map<string, int> course_cap;
center::center()
		{
			center_id="0";
			center_name="CDAC";
			address="INDIA";
			coordinator="XYZ";
			password="CDAC";
		}
center::center(const string &str1,const string &str2,const string &str3,const string &str4,const string &str5)
		{
			center_id=str1;
			center_name=str2;
			address=str3;
			coordinator=str4;
			password=str5;
		}
	void center::display()
		{
			cout<<"Center id 		->  "<<center_id<<endl;
			cout<<"Center Name 		->  "<<center_name<<endl;
			cout<<"Address	  		->  "<<address<<endl;
			cout<<"Coordinator 		->  "<<coordinator<<endl;
			cout<<"Password    		->  "<<password<<endl;
			cout<<endl;
		}
	void center::displaycap(vector<capacities> &cs)
	{
		map<string, int>::iterator itr;
		itr=course_cap.begin();
		while(itr!=course_cap.end())
		{
			cs[itr->second].display();    //error
			itr++;
		}

	}
	void center::set_center_id(const string &str1)
		{
			center_id=str1;
		}
	void center::set_center_name(const string &str2)
		{
			center_name=str2;
		}
	void center::set_center_address(const string &str3)
		{
			address=str3;
		}
	void center::set_center_coordinator(const string &str4)
		{
			coordinator=str4;
		}
	void center::set_center_password(const string &str5)
		{
			password=str5;
		}

	string& center::get_center_id()
		{
			return center_id;
		}
	string& center::get_center_name()
		{
			return center_name;
		}
	string& center::get_center_address()
		{
			return address;
		}
	string& center::get_center_coordinator()
		{
			return coordinator;
		}
	string& center::get_center_password()
		{
			return password;
		}



