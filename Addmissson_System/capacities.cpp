/*
 * capacities.cpp
 *
 *  Created on: 22-Apr-2020
 *      Author: sunbeam
 */
#include"capacities.h"


	capacities::capacities()
					{
						center_id="xyz";
						course_name="abc";
						capacity=0;
						filled_capacity=0;
					}

	capacities::capacities(string &str1,string &str2,int num1,int num2)
					{
						center_id=str1;
						course_name=str2;
						capacity=num1;
						filled_capacity=num2;
					}

	void capacities::set_capacity(int num1)

					{
						capacity=num1;
					}

	void capacities::set_filled_capacity(int num2)
					{
						filled_capacity=num2;
					}

	string& capacities::get_course_name()
						{
							return course_name;
						}
	string& capacities::get_center_id()
							{
								return center_id;
							}
	int capacities::get_center_capacity()
					{
						return capacity;
					}

	int capacities::get_filled_capacity()
					{
						return filled_capacity;
					}
	void capacities::display()
							{
								cout<<"Center id -> "<<center_id<<"  Course Name -> "<<   course_name<<"   Capacity-> "<<capacity<<"  Filled Capacity -> "<<filled_capacity<<endl<<endl;
							}



