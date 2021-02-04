/*
 * admission.cpp
 *
 *  Created on: 22-Apr-2020
 *      Author: sunbeam
 */

#include "admission.h"
 //void sort_A_rank();
 //void sort_B_rank();
 //void sort_C_rank();
admission::admission() {}
	//student class---

	student* admission::find_std(vector<student> &std ,int formno)
				{
					unsigned i;
					for(i=0;i<std.size();i++)
						{
							if(std[i].get_form_no()==formno)
							return &std[i];
						}
					return NULL;
				}

	void admission::load_student_csv(vector<student> &students)
			{
				ifstream fp;
				fp.open(STUDENT_FILE);
				string line;
				//int c=0;
				if(!fp)
					{
						cerr<<"Failed To open File"<<endl;
						return;
					}
				while(getline(fp,line))
					{
						unsigned i;
						stringstream str(line);
						string token[13];
						for(i=0;i<13;i++)
							{
								getline(str,token[i],',');
							}
					student obj(stoi(token[0]),token[1],stoi(token[2]),stoi(token[3]),stoi(token[4]),token[5],stof(token[6]),stoi(token[7]),token[8],token[9],stof(token[10]),stoi(token[11]),token[12]);
						//c++;
					students.push_back(obj);
					}
				//cout<<"student File get Loaded "<<c<<endl;
				fp.close();
			}

	void admission::save_students(vector<student>& students) {

		unsigned i;
		ofstream fp ("updated_student.csv",ios::out | ios::trunc);
		if(!fp) {
			perror("failed to open file");
			return;
		}

		for(i=0; i<students.size(); i++) {
			fp << students[i].form_no << "," << students[i].name << ","
					<< students[i].rank_a_section << "," << students[i].rank_b_section << ","
					<< students[i].rank_c_section<< "," <<students[i].degree << "," << students[i].percentage << ","
					<< students[i].allocated_preference << "," << students[i].allocated_course_name << ","
					<< students[i].allocated_center_id<< "," << students[i].payment<<","<<students[i].reported_to_center<< "," << students[i].PRN<<endl;
		}

		fp.close();
		cout << "Updated list of students saved." << endl;
	}

	void admission::save_students_for_fee(vector<student>& students) {

			unsigned i;
			ofstream fp;
			fp.open(STUDENT_FILE);
			if(!fp) {
				perror("failed to open file");
				return;
			}

			for(i=0; i<students.size(); i++) {
				fp << students[i].form_no << "," << students[i].name << ","
						<< students[i].rank_a_section << "," << students[i].rank_b_section << ","
						<< students[i].rank_c_section<< "," <<students[i].degree << "," << students[i].percentage << ","
						<< students[i].allocated_preference << "," << students[i].allocated_course_name << ","
						<< students[i].allocated_center_id<< "," << students[i].payment<<","<<students[i].reported_to_center<< "," << students[i].PRN<<endl;
			}

			fp.close();
			cout << "Updated list of students saved." << endl;
		}

	void admission::save_students_preference(vector<student>&students ) {

			unsigned i,j;
			ofstream fp ("updated_preference.csv",ios::out | ios::trunc);
			if(!fp) {
				perror("failed to open file");
				return;
			}

			for(i=0; i<students.size(); i++) {
				student *d= &students[i];
				for(j=0;j<d->prf.size();j++)
				{
					preference *pf=&d->prf[j];
				fp << pf->form_no << "," << pf->preference_no << ","
						<< pf->course_name << "," << pf->center_id<<endl;
				}
			}

			fp.close();
			cout << "Updated list of students preference saved." << endl;
		}



	//preference class--

	void admission::load_preference_csv(vector<student> &std)
				{
					ifstream fp;
					fp.open(PREFERENCES_FILE);
					string line;
					//int c=0;
					if(!fp)
						{
							cerr<<"Failed To open File"<<endl;
							return;
						}
					while(getline(fp,line))
						{
							unsigned i;
							stringstream str(line);
							string token[4];
							for(i=0;i<4;i++)
							{
								getline(str,token[i],',');
							}
							preference obj(stoi(token[0]),stoi(token[1]),token[2],token[3]);
							student *s=find_std(std,obj.get_form_no());

							//c++;
							s->prf.push_back(obj);
						}
					//cout<<"Preference File get loaded "<<c<<endl;
					fp.close();
				}




	//degree class--
	void admission::load_degree(vector<degree> &dg)
			{
				ifstream fp;
				fp.open(DEGREES_FILE);
				string line;
				int c=0;

				if(!fp)
				{
					cerr<<"Failed To open File"<<endl;
					return;
				}

				while(getline(fp,line))
				{
				degree obj(line);

				dg.push_back(obj);
				c++;
				}
			}

//	void admission::save_degree(vector<degree> &dg) {
//			ofstream fp;
//			unsigned i;
//			fp.open(DEGREES_FILE);
//			if(!fp) {
//				perror("failed to open file");
//				return;
//			}
//
//			for(i=0; i<dg.size(); i++) {
//				fp << dg[i]<<endl;
//			}
//
//			fp.close();
//			cout << "degree saved." << endl;
//		}



	//course class--

	void admission::load_course_csv(vector<course> &courses)
				{	//int c=0;
					ifstream fp;
					fp.open(COURSES_FILE);
					if(!fp)
						{
							cerr<<"Failed To open File"<<endl;
							return;
						}
						string line;

					while(getline(fp,line))
						{
							stringstream str(line);
							string token[5];
							for(int i=0;i<4;i++)
								{
									getline(str,token[i],',');
								}
							course obj(stoi(token[0]),token[1],token[2],token[3]);
							courses.push_back(obj);
							//c++;
						}
					fp.close();
					//cout<<"Courses are Loaded "<<c<<endl;
				}



	//eligibility class

	course* admission::find_course_eligibilty(vector<course> &courses,const string &course_name)
					{
						unsigned i;
						for(i=0;i<courses.size();i++)
						{
							if(courses[i].get_course_name()==course_name)
								return &courses[i];
						}
						return NULL;
					}

	void admission::load_eligibility_csv(vector<course> &courses)
					{
						string line;
						//int c=0;
						ifstream fp;
						fp.open(ELIGIBILITY_FILE);
						if(!fp)
							{
								cerr<<"Failed to Open File"<<endl;
								return;
							}
						while(getline(fp,line))
						{
							stringstream str(line);
							string token[3];
							for(int i=0;i<3;i++)
							{
								getline(str,token[i],',');
							}
							eligibility obj(token[0],token[1],stoi(token[2]));
							course* crs=find_course_eligibilty(courses,obj.get_course_name());
							crs->elg.push_back(obj);
							//c++;

						}

						//cout<<"Eligibility File loaded "<<c<<endl;
					}

	//center class--

	void admission::load_center_csv(vector<center> &cntr)
					{
						ifstream fp;
						string line;
						//int c=0;
						fp.open(CENTERS_FILE);
						if(!fp)
							{
								cerr<<"Failed to open center file";
								return;
							}
						while(getline(fp,line))
						{
							stringstream str(line);
							string token[5];
							for(int i=0;i<5;i++)
								{
									getline(str,token[i],',');
								}
							center c1(token[0],token[1],token[2],token[3],token[4]);
							cntr.push_back(c1);
							//c++;
						}
						fp.close();
						//cout<<"Centers are Loaded "<<c<<endl;
					}



	//capacity class--

	center* admission::find_center(vector<center>&cntr,const string &center_id)
							{
								unsigned i;
								for(i=0;i<cntr.size();i++)
								{
									if(cntr[i].center_id==center_id)
									return &cntr[i];
								}
								return NULL;

							}

	course* admission::find_course(vector<course>&crs, const string &course_name)
							{
								unsigned i;

								for(i=0;i<crs.size();i++)
								{
									if(crs[i].course_name==course_name)
										return &crs[i];
								}
								return NULL;
							}

	void admission::load_capacities_csv(vector<capacities> &cp, vector<center> &cntr, vector<course> &crs)
								{
									ifstream fp;
									fp.open(CAPACITY_FILE);
									string line;
									//int c=0;
									if(!fp)
										{
											cerr<<"Failed To open File"<<endl;
											return;
										}
									while(getline(fp,line))
										{
											unsigned i;
											stringstream str(line);
											string token[4];
											for(i=0;i<4;i++)
												{
													getline(str,token[i],',');
												}
											capacities obj(token[0],token[1],stoi(token[2]),stoi(token[3]));
											//c++;
											cp.push_back(obj);
											center *cn=find_center(cntr,obj.get_center_id());
											course *c1=find_course(crs,obj.get_course_name());
											cn->course_cap[obj.get_course_name()]=cp.size()-1;
											c1->center_cap[obj.get_center_id()]=cp.size()-1;

										}
									//cout<<"Capacity File get Loaded "<<c<<endl;

									fp.close();
								}
	void admission::save_capacity(vector<capacities>& capacity) {
		ofstream fp ("updated_capacity.csv",ios::out | ios::trunc);
				unsigned i;
				if(!fp) {
					perror("failed to open file");
					return;
				}

				for( i=0;i<capacity.size();i++)
				{
					fp << capacity[i].center_id<< "," <<capacity[i].course_name<< ","<<capacity[i].capacity << "," << capacity[i].filled_capacity <<endl;
				}

				fp.close();
				cout << "Updated capacity of centers saved." << endl;
			}



	//algorithm--

	void admission:: first_round_A_allocation(int j,int pos)
	{

		unsigned i,k,p,c=0;
		string sec="A",crs_name,cntr_id;
		for(i=0;i<students.size();i++)
		{
			if(students[i].get_payment()>=0)
			{
			for(j=0;j<students[i].prf.size();j++)
			{
				if(j==pos)
				{
				for(k=0;k<courses.size();k++)
				{
					if(sec==courses[k].section&&students[i].prf[j].get_course_name()==courses[k].course_name)
						{
							for(p=0;p<capcity.size();p++)
								{
									if(students[i].prf[j].get_course_name()==capcity[p].course_name&&students[i].prf[j].get_center_id()==capcity[p].center_id)
										{
											//cout<<students[i].prf[j].get_course_name()<<endl;
											if(capcity[p].filled_capacity!=capcity[p].capacity)
												{
													students[i].set_allocated_center_id(students[i].prf[j].center_id);
													students[i].set_allocated_course_name(students[i].prf[j].get_course_name());
													students[i].set_allocated_preference(students[i].prf[j].get_preference_no());
													capcity[p].set_filled_capacity((capcity[p].get_filled_capacity()+1));
													students[i].display();
												}
										}
								 }
						}
					}

				}
			}
			}
		}

	}

	void admission:: first_round_B_allocation(int j, int pos)
	{		int found=0;
			unsigned i,k,p,c=0;
			string sec2="B",crs_name;
			for(i=0;i<students.size();i++)
			{

				if(students[i].get_payment()>=0)
			   {
				for(j=0;j< students[i].prf.size();j++)
				{
					if(j==pos)
					{
					for(k=0;k<courses.size();k++)
					{
						if(students[i].prf[j].get_course_name()==courses[k].course_name)
							{
								if(sec2==courses[k].section)
								{

									crs_name=students[i].prf[j].get_course_name();
											for(p=0;p<capcity.size();p++)
												{
													if(students[i].prf[j].get_course_name()==capcity[p].course_name&&students[i].prf[j].get_center_id()==capcity[p].center_id)
															{
																if(students[i].allocated_course_name=="NA")
																	{
																		if(capcity[p].filled_capacity!=capcity[p].capacity)
																		{

																			//cout<<capcity[p].course_name<<"  "<<++c<<endl;
																		students[i].set_allocated_center_id(students[i].prf[j].center_id);
																		students[i].set_allocated_course_name(crs_name);
																		students[i].set_allocated_preference(students[i].prf[j].get_preference_no());
																		capcity[p].set_filled_capacity((capcity[p].get_filled_capacity()+1));
																		found=1;

																		}
																	}
																}

												}

								    }
								}
					}
				if(found==1)
				{
					break;
				}
					}
				}
			   }
			}

		}

	void admission:: first_round_C_allocation(int j,int pos)
	{

			unsigned i,k,p;
			int found =0;
			string sec="A",crs_name,cntr_id;
			string sec2="B",sec3="C";
			for(i=0;i<students.size();i++)
			{
				if(students[i].payment>=0)
				{
				for(j=0;j<students[i].prf.size();j++)
					{
					 if(pos==j)
						{
						 for(k=0;k<courses.size();k++)
						  {
							if(sec3==courses[k].section&&students[i].prf[j].get_course_name()==courses[k].course_name)
								{
									for(p=0;p<capcity.size();p++)
										{
											if(students[i].prf[j].get_course_name()==capcity[p].course_name&&students[i].prf[j].get_center_id()==capcity[p].center_id)
												{
													if(capcity[p].filled_capacity!=capcity[p].capacity)
														{
															students[i].set_allocated_center_id(students[i].prf[j].center_id);
															students[i].set_allocated_course_name(students[i].prf[j].course_name);
															students[i].set_allocated_preference(students[i].prf[j].get_preference_no());
															capcity[p].set_filled_capacity((capcity[p].get_filled_capacity()+1));
														}
												}
										 }
								}
						  }
					if(found==0)
					{
						break;
					}
						}
					}
				}
			 }

		}

	void admission:: Find_Student_Not_Filled_Payment()
	{
		unsigned i,j,c=0;
		for(i=0;i<students.size();i++)
				{

			for(j=0;j<courses.size();j++)
			{
			if( students[i].allocated_course_name==courses[j].course_name)

				//if(students[i].allocated_preference>0)
					{
						if(students[i].payment!=11800)
						{		//students[i].display();
								//cout<<++c<<endl;
							students[i].set_payment(-1);
						}
					}
				}
	}}

	void admission:: Clear_allocated_center()
	{
		unsigned i,j;

		for(i=0;i<students.size();i++)
		{
			for(j=0;j<capcity.size();j++)
				{	//cout<<capcity[j].course_name<<endl;
					capcity[j].set_filled_capacity(0);
				}
			students[i].set_allocated_center_id("NA");
			students[i].set_allocated_course_name("NA");
			students[i].set_allocated_preference(0);
		}
	}
	admission::~admission() {}

