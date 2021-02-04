/*
 * degree.h
 *
 *  Created on: 17-Apr-2020
 *      Author: sunbeam
 */
#include<iostream>
#include<cstring>
using namespace std;
#include<map>
#define DEGREES_FILE "include/degrees.txt"
#ifndef DEGREE_H_
#define DEGREE_H_

class degree{
public:
	string degrees;
public:
	degree()
		{
			degrees="abc";
		}

	degree(string deg) {
		degrees=deg;
		}

	void set_deg(string deg) {
			degrees = deg;
		}

	void display()
		{
				cout<<"Degree			:"<<degrees<<endl<<endl;
		}
	void set_degree(const string &str)
		{
			degrees=str;
		}
	string get_degree(const string &str)
		{
			return degrees;
		}

};

//	void load_degree(vector<degree> &dg)
//	{
//		ifstream fp;
//		fp.open(DEGREES_FILE);
//		string line;
//		int c=0;
//
//		if(!fp)
//		{
//			cerr<<"Failed To open File"<<endl;
//			return;
//		}
//
//		while(getline(fp,line))
//		{
//		degree obj(line);
//
//		dg.push_back(obj);
//		c++;
//		}
//		cout<<"Degree File get Loaded "<<c<<endl;
//	}
//



#endif /* DEGREE_H_ */
