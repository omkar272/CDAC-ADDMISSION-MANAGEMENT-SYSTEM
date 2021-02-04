/*
 * main.cpp
 *
 *  Created on: 16-Apr-2020
 *      Author  : Omkar Gaikwad
 *      Batch   : KD3
 *      ROLL NO : 36394
 *
 *
 */


#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <istream>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <algorithm>

#include "student.h"
#include "course.h"
#include"eligibility.h"
#include "center.h"
#include "degree.h"
#include "capacities.h"
#include"admission.h"
admission addmissions;

using namespace std;
typedef enum{EXIT,STUDENT,ADMIN,CENTER_COORDINATOR}MENUOPERATION;

	 int menu_choice();

 	 int menu_chooice_for_student();

 	 int menu_chooice_for_sign_in_student();

 	 int menu_choice_for_admin();

 	 int menu_choice_for_sign_in_admin();

	 int menu_choice_for_center_coordinator();

	 int menu_choice_for_center_sign_in_coordinator();

	 bool comp_student_A_rank( const student& s1,const student& s2);

	 bool comp_student_B_rank( const student& s1,const student& s2);

	 bool comp_student_C_rank( const student& s1,const student& s2);

	 void sort_A_rank();

	 void sort_B_rank();

	 void sort_C_rank();

	 bool comp_student_course( const student& s1,const student& s2);

	 bool comp_student_center( const student& s1,const student& s2);

	 bool comp_student_name( const student& s1,const student& s2);

	 void round_one_allocation();

int main()
{
	unsigned i,z=0,j,q,p,s,pref;
	int num,found=0,flag=0;
	string name;
	//for registration
	student s1;//student obj
	string nam,cntr;
	int rank_a, rank_b,rank_c,formnum;
	string deg;

	float per;
	//
	preference pf;
	int prefno;	//prefrence number
	string crsname,id;
	float fee;
	string adminpass="admin";

	string usrnm,pass;	//center coordinator
	int reportedstatus;

		addmissions.load_student_csv(addmissions.students);
		addmissions.load_preference_csv(addmissions.students);
		addmissions.load_course_csv(addmissions.courses);
		addmissions.load_eligibility_csv(addmissions.courses);
		addmissions.load_center_csv(addmissions.centers);
		addmissions.load_capacities_csv(addmissions.capcity, addmissions.centers, addmissions.courses);
		addmissions.load_degree(addmissions.degrees);

	int choice;
	while((choice=menu_choice())!=EXIT)
	{
		switch(choice)
			{
				case EXIT:
					break;
				case STUDENT:

					while((choice=menu_chooice_for_student())!=EXIT)
					{
						switch(choice)
						{
						case 0:
							break;
						case 1:
							cout<<"Register New student "<<endl;

								cout<<"Enter your form no"<<endl;
								cin>>formnum;
								s1.set_form_no(formnum);
								cout<<"Enter your name :"<<endl;
								cin>>nam;
								s1.set_student_name(nam);
								cout<<"Enter your A, B & C section rank (Note: if not appeared in any section place it as -1):"<<endl;
								cin>>rank_a;
								s1.set_rank_a_section(rank_a);
								cin>>rank_b;
								s1.set_rank_b_section(rank_b);
								cin>>rank_c;
								s1.set_rank_c_section(rank_c);
								cout<<"Enter your Qualification Degree :"<<endl;
								cin>>deg;
								cout<<"Enter Percentage :"<<endl;
								cin>>per;
								found=0;
								//cout<<deg<<endl;

								for(j=0;j<addmissions.degrees.size();j++)
								{
									if(deg==addmissions.degrees[j].degrees&&per>45)
									{
										s1.set_degree(deg);
										s1.set_percentage(per);
										addmissions.students.push_back(s1);
										found=1;
									}
								}

								if(found==0)
								{
									cout<<"You are not elligible for examination !!!!"<<endl;
								}

								for(j=0;j<addmissions.students.size();j++)
								{
									addmissions.students[j].display();
								}
								addmissions.save_students(addmissions.students);
							break;
						case 2:
							//sign in--
							//cout<<"Sign in"<<endl;
							found=0;
							cout<<"Enter Your Form no"<<endl;
							cin>>num;
							cout<<"Enter Your Password(Hint :Name)"<<endl;
							cin>>name;

							for(i=0;addmissions.students.size();i++)
								{
									if(addmissions.students[i].form_no==num&&addmissions.students[i].name==name)
										{	found=1;
											while((choice=menu_chooice_for_sign_in_student())!=EXIT)
												{
													switch(choice)
															{
																case 0 :
																	break;
																case 1:
																	cout<<"1. LIST COURSES ------------------------>"<<endl;
																	cout<<"You are Elligible for only those courses :-"<<endl;
																	for(j=0;j<addmissions.courses.size();j++)
																	{
																		for(q=0;q<addmissions.courses[j].elg.size();q++)
																		{
																			if(addmissions.students[i].degree==addmissions.courses[j].elg[q].degree)
																			{
																				if(addmissions.students[i].percentage>=addmissions.courses[j].elg[q].min_percentage)
																				{
																					cout<<addmissions.courses[j].elg[q].course_name<<endl;
																				}
																			}
																		}
																	}

																	break;
																case 2:
																	 cout<<"2. LIST OF ALL CENTERS ------------------------------>"<<endl;
																	 	 for(i=0;i<addmissions.centers.size();i++)
																	 	 {
																	 		 addmissions.centers[i].display();
																	 	 }
																	break;
																case 3:
																	cout<<"3. GIVE PREFERENCE ---------------------------->"<<endl;
																	cout<<"How many numbers of preference want to enter "<<endl;
																	cin>>pref;
																		for(j=0;j<addmissions.courses.size();j++)
																		 {
																			for(q=0;q<addmissions.courses[j].elg.size();q++)
																				{
																					if(addmissions.students[i].degree==addmissions.courses[j].elg[q].degree)
																						{
																							if(addmissions.students[i].percentage>=addmissions.courses[j].elg[q].min_percentage)
																								{
																									cout<<addmissions.courses[j].elg[q].course_name<<"--Available in these institute :"<<endl;
																									map<string, int> ::iterator itr;
																									itr=addmissions.courses[j].center_cap.begin();
																									while(itr!=addmissions.courses[j].center_cap.end())
																									{
																										for(s=0;s<addmissions.centers.size();s++)
																											{
																												if(itr->first==addmissions.centers[s].center_id)
																													{
																														addmissions.centers[s].display();
																														flag=1;
																													}
																											 }
																											itr++;
																									}

																								}
																						}
																					}//end of eligibility for loop
																				}//end of course for loop
																		if(flag==1)
																			{
																				for(j=0;j<pref;j++)
																					{
																						pf.set_form_no(addmissions.students[i].form_no);
																						cout<<"Enter Center Id :"<<endl;
																						cin>>id;
																						pf.set_center_id(id);
																						cout<<"Enter Course Name :"<<endl;
																						cin>>crsname;
																						pf.set_course_name(crsname);
																						cout<<"Preference no :"<<endl;
																						cin>>prefno;
																						pf.set_preference_no(prefno);
																					}
																				addmissions.students[i].prf.push_back(pf);
																			}
																		else
																			{
																				cout<<"SORRYY!!!!  You are not eligible for any course!!!!!!!!"<<endl;
																			}
																			for(i=0;i<addmissions.students.size();i++)
																				{
																					for(j=0;j<addmissions.students[i].prf.size();j++)
																						{
																							addmissions.students[i].prf[j].display();
																						}
																				}
																		addmissions.save_students_preference(addmissions.students);

																				break;
																   case 4:
																			 cout<<" SEE ALLOCATED CENTER ----------------------------->"<<endl<<endl;

																			 for(j=0;j<addmissions.centers.size();j++)
																			 {
																				 if(addmissions.students[i].allocated_center_id==addmissions.centers[j].center_id)
																				 {
																					 addmissions.centers[j].display();
																				 }
																			 }
																			 cout<<"Allocated course is :"<<endl;
																			 cout<<addmissions.students[i].allocated_course_name<<endl;
																			break;
																case 5:
																			 cout<<" UPDATE PAYMENT DETAILS ---------------------------------->"<<endl;
																			 if(addmissions.students[i].allocated_preference!=0)
																			 {
																				 cout<<"Enter amount of fees you want to pay "<<endl;
																				 cin>>fee;
																				addmissions.students[i].set_payment(addmissions.students[i].payment+fee);
																				addmissions.students[i].display();
																				addmissions.save_students_for_fee(addmissions.students);
																			 }
																			 else
																				 cout<<"You have no any allocated  seat!!!!!!"<<endl;
																			break;
																default:
																	cout<<"You Entered Incorrrect Choice"<<endl;

																}//end switch
														}//end while loop
										}//end if condition

								}//end of for loop
							if(found==0)
							{
								cout<<"Your Entered ID and PASSWORD are Incorrect!!!"<<endl<<endl;
								break;
							}
							//break of student case student case over
							break;
						default:
							cout<<"You Entered Incorrrect Choice"<<endl;
							break;
						}
					}
					break;
				case ADMIN:

					while((choice=menu_choice_for_admin())!=EXIT)

					{
						switch(choice)
						{

						case EXIT:
							break;
						case 1:
							//cout<<"Sign In"<<endl;
							cout<<"Enter Your Username (Hint: admin) "<<endl;
							cin>>usrnm;
							cout<<"Enter Password "<<endl;
							cin>>pass;
							if(usrnm==adminpass&&usrnm==adminpass){
							while((choice=menu_choice_for_sign_in_admin())!=0)
							{
								switch(choice)
								{
								case EXIT:
									break;
								case 1:
									cout<<" LIST COURSES AND ELIGIBILITY"<<endl;

									for(i=0;i<addmissions.courses.size();i++)
									{	cout<<"#Course-------------------------------"<<endl;
										addmissions.courses[i].display();
										cout<<"Elligibilities----->"<<endl;
										addmissions.courses[i].display_course_eligibility();
										cout<<endl;
									}
									break;

								case 2:
									cout<<" LIST CENTER AND CAPACITIES "<<endl;
									for(i=0;i<addmissions.centers.size();i++)
									{	cout<<"#Centers-------------------------------"<<endl;
										addmissions.centers[i].display();
										addmissions.centers[i].displaycap(addmissions.capcity);
									}

											break;
								case 3:
									cout<<"LIST OF ALL STUDENTS ------------------------------->"<<endl;

									for(i=0;i<addmissions.students.size();i++)
										{
											addmissions.students[i].display();
										}
									break;
								case 4 :
									cout<<"4. UPDATE STUDENT RANK ------------------------->"<<endl;
										cout<<"Enter Form number :"<<endl;
										cin>>formnum;
										cout<<"Enter Rank A , B & C section (Note: if not appeared for any section please fill as a -1)"<<endl;
										cin>>rank_a;
										cin>>rank_b;
										cin>>rank_c;
									for(i=0;i<addmissions.students.size();i++)
										{
											if(addmissions.students[i].form_no==formnum)
											{
												addmissions.students[i].set_rank_a_section(rank_a);
												addmissions.students[i].set_rank_b_section(rank_b);
												addmissions.students[i].set_rank_c_section(rank_c);
											}
										}
									for(i=0;i<addmissions.students.size();i++)
										{
											addmissions.students[i].display();
										}
									addmissions.save_students(addmissions.students);
									break;
								case 5:
									cout<<"5. ALLOACATE CENTERS TO STUDENTS FOR FIRST ROUND---->"<<endl;

										round_one_allocation();
										z=0;
								//only for printing purpose on console allocated student after round 2--
											for(i=0;i<addmissions.students.size();i++)
												{	if(addmissions.students[i].allocated_preference)
													{		cout<<++z<<endl;
															addmissions.students[i].display();
													}}
											for(i=0;i<addmissions.capcity.size();i++)
														{
															addmissions.capcity[i].display();
														}
									addmissions.save_students(addmissions.students);
									addmissions.save_capacity(addmissions.capcity);
									break;
								case 6:
									cout<<" ALLOCATE CENTERS TO STUDENTS FOR SECOND ROUND----->"<<endl<<endl;

										//cout<<"Allocation second round"<<endl;
										//make -1 payment and clear allocated center
										addmissions.Find_Student_Not_Filled_Payment();
										addmissions.Clear_allocated_center();
										round_one_allocation();

									//only for printing purpose on console allocated student after round 2--
										z=0;
										for(i=0;i<addmissions.students.size();i++)
										{	if(addmissions.students[i].allocated_preference)
											{		cout<<++z<<endl;
													addmissions.students[i].display();
											}
										}
										for(i=0;i<addmissions.capcity.size();i++)
											{
												addmissions.capcity[i].display();
											}

										addmissions.save_students(addmissions.students);
										addmissions.save_capacity(addmissions.capcity);
										break;
								case 7:
								cout<<" #LIST OF ALLOACATED STUDENTS--------->"<<endl<<endl;


									for(i=0;i<addmissions.students.size();i++)
									{	if(addmissions.students[i].allocated_preference)
											{
												addmissions.students[i].display();
											}
									}


										break;
								case 8:
									cout<<"8. LIST OF FEES PAID STUDENT ---------------------------->"<<endl;
									for(i=0;i<addmissions.students.size();i++)
										{	if(addmissions.students[i].payment>0)
											{
												addmissions.students[i].display();
											}
										}
											break;

								case 9:
									cout<<"9. LIST OF REPORTED STUDENTS AT CENTER -------------------------->"<<endl;
									for(i=0;i<addmissions.students.size();i++)
									{
										if(addmissions.students[i].reported_to_center>0)
										{
											addmissions.students[i].display();
										}
									}
												break;
								case 10:
									cout<<"10. GENERATE PRN"<<endl;
									sort(addmissions.students.begin(),addmissions.students.end(),comp_student_course);
									sort(addmissions.students.begin(),addmissions.students.end(),comp_student_center);
									sort(addmissions.students.begin(),addmissions.students.end(),comp_student_name);

									for(i=0;i<addmissions.students.size();i++)
									{
										if(addmissions.students[i].allocated_preference)
										{

											if(addmissions.students[i].allocated_course_name=="PG-DAC"||addmissions.students[i].allocated_course_name=="PG-DMC"||addmissions.students[i].allocated_course_name=="PG-DESD")
												{
													if(addmissions.students[i].payment>=94000)
													{
														string cntrid=addmissions.students[i].allocated_center_id;
														string crsnm=addmissions.students[i].allocated_course_name;
														string forn= to_string(addmissions.students[i].form_no);
														addmissions.students[i].set_PRN(cntrid + "_"+ crsnm + "_"+forn);
														addmissions.students[i].display();
													}
												}
											if(addmissions.students[i].allocated_course_name=="PG-DBDA")
												{
													if(addmissions.students[i].payment>=115000)
														{
															string cntrid=addmissions.students[i].allocated_center_id;
															string crsnm=addmissions.students[i].allocated_course_name;
															string forn= to_string(addmissions.students[i].form_no);
															addmissions.students[i].set_PRN(cntrid + "_"+ crsnm + "_"+forn);
															addmissions.students[i].display();
														}
												}

											if(addmissions.students[i].allocated_course_name=="PG-DGI")
												{
													if(addmissions.students[i].payment>=115000)
														{
															string cntrid=addmissions.students[i].allocated_center_id;
															string crsnm=addmissions.students[i].allocated_course_name;
															string forn= to_string(addmissions.students[i].form_no);
															addmissions.students[i].set_PRN(cntrid + "_"+ crsnm + "_"+forn);
															addmissions.students[i].display();

														}
												}
										}
									}
									addmissions.save_students(addmissions.students);
									break;

								case 11:
									cout<<"11. LIST OF ADDMITED STUDENTS FOR GIVEN CENTER------------------>"<<endl;
									cout<<"Enter Center ID "<<endl;
									cin>>cntr;
									cout<<"Enter course Name "<<endl;
									cin>>crsname;
									for(i=0;i<addmissions.students.size();i++)
									{
										if(addmissions.students[i].allocated_center_id==cntr&&addmissions.students[i].allocated_course_name==crsname)
											{

												addmissions.students[i].display();
											}
									}
									break;
								}//switch loop
							}//while loop admin
							}//if conditon
						else
						{
							cout<<"Your Entered ID and PASSWORD are Incorrect!!!"<<endl<<endl;
							break;
						}
							break;//sign in case break
						}//switch loop end
		}//while loop admin

						break;//admin case break--


		case CENTER_COORDINATOR:
			found=0;
			while((choice=menu_choice_for_center_coordinator())!=0)
			{
			   switch(choice)
				 {
				   case EXIT:
						break;
				   case 1:
						//cout<<"Sign in"<<endl;

						cout<<"Enter Your Username (Hint: Center ID) "<<endl;
						cin>>usrnm;
						cout<<"Enter Password (Hint: Center NAME)"<<endl;
						cin>>pass;
						for(i=0;i<addmissions.centers.size();i++)
						{
						if(addmissions.centers[i].center_id==usrnm&& addmissions.centers[i].password==pass)
							{	found=1;
							  while((choice=menu_choice_for_center_sign_in_coordinator())!=0)
								{
								  switch(choice)
								  {
									case EXIT:
										break;
									case 1:
										cout<<"LIST COURSES-------------------->"<<endl;
										for(j=0;j<addmissions.capcity.size();j++)
										{
										  if(addmissions.centers[i].center_id==addmissions.capcity[j].center_id)
											{
											   for(p=0;p<addmissions.courses.size();p++)
												{
												   if(addmissions.capcity[j].course_name==addmissions.courses[p].course_name)
													{
														addmissions.courses[p].display();
													}
												}
											}
										}
										break;
									case 2:
										cout<<"LIST OF ALLOACATED STUDENTS -------------------->"<<endl;
											for(j=0;j<addmissions.students.size();j++)
											 {
												if(addmissions.students[j].allocated_center_id==addmissions.centers[i].center_id)
												{
													addmissions.students[j].display();
												}
											 }

										break;
									case 3:
										found=0;
										cout<<"UPDATE_REPORTED_STATUS -------------------->"<<endl;
										cout<<"Enter Form number of student to be reported ->"<<endl;
										cin>>formnum;
										cout<<"Enter reported status ->"<<endl;
										cin>>reportedstatus;
										for(j=0;j<addmissions.students.size();j++)
										{
											if(addmissions.students[j].allocated_center_id==addmissions.centers[i].center_id)
											{
												if(addmissions.students[j].form_no==formnum)
												{
													addmissions.students[j].set_reported_to_center(reportedstatus);
													addmissions.students[j].display();
													found=1;
												}
											}
										}
										if(found==0)
										{
											cout<<"Entered Student is not allocated to thise center!!!!!"<<endl;
										}
										addmissions.save_students_for_fee(addmissions.students);
										addmissions.save_students(addmissions.students);
										break;
									case 4:
										cout<<"LIST_ADMITED_STUDENT------------------------------>"<<endl;
										cout<<"Enter course Name --->";
										cin>>crsname;
										sort(addmissions.students.begin(),addmissions.students.end(),comp_student_name);
										for(j=0;j<addmissions.students.size();j++)
											{
												if(crsname==addmissions.students[j].allocated_course_name&&addmissions.centers[i].center_id==addmissions.students[j].allocated_center_id)
												{

													addmissions.students[j].display();
												}
											}
										break;
									default :
									cout<<"Your entered Choice is Incorrect"<<endl;
								}
								}
							}
						}//while sign in
							break; //sign in break
					default :
						cout<<"Your entered Incorrect Choice"<<endl;

					}//switch

				}//while looop center coorinator

			}	//switch case main
	}//while menu choice

return 0;


}//main loop


int menu_choice()
 	 	 {
 		 	int mchoice;
 		 	cout<<endl;
 		 	cout<<"0. EXIT"<<endl;
 		 	cout<<"1. STUDENT"<<endl;
 		 	cout<<"2. ADMIN"<<endl;
 		 	cout<<"3. CENTER COORDINATOR"<<endl;
 		 	cin>>mchoice;
 		 	return mchoice;
 	 	 }

 	 int menu_chooice_for_student()
 	 	 {
  			int mchoice;
  				 cout<<endl;
 				 cout<<"0. EXIT"<<endl;
 				 cout<<"1. REGISTER NEW STUDENT"<<endl;
 				 cout<<"2. SIGN IN"<<endl;
 				 cin>>mchoice;
 				 return mchoice;
 	 	 }

 	 int menu_chooice_for_sign_in_student()
 	 	 {
 			int mchoice;
 				 cout<<endl;
 				 cout<<"0. EXIT"<<endl;
				 cout<<"1. LIST COURSES"<<endl;
				 cout<<"2. LIST OF ALL CENTERS"<<endl;
				 cout<<"3. GIVE PREFERENCE"<<endl;
				 cout<<"4. SEE ALLOCATED CENTER"<<endl;
				 cout<<"5. UPDATE PAYMENT DETAILS"<<endl;
				 cin>>mchoice;
				 return mchoice;
 	 	 }

 	 int menu_choice_for_admin()
 	 	 {
 			int mchoice;
 					cout<<endl;
 					cout<<"0. EXIT"<<endl<<"1. SIGN IN"<<endl;
 					cin>>mchoice;
 					return mchoice;
 	 	 }
 	 int menu_choice_for_sign_in_admin()
 	 	 {
 		 	 int mchoice;
					cout<<endl;
					cout<<"0. EXIT"<<endl;
					cout<<"1. LIST COURSES AND ELIGIBILITY"<<endl;
					cout<<"2. LIST CENTER AND CAPACITIES "<<endl;
					cout<<"3. LIST STUDENT"<<endl;
					cout<<"4. UPDATE STUDENT RANK"<<endl;
					cout<<"5. ALLOACATE CENTERS FIRST ROUND"<<endl;
					cout<<"6. ALLOCATE CENTERS SECOND ROUND"<<endl;
					cout<<"7. LIST ALLOACATE STUDENT"<<endl;
					cout<<"8. LIST PAID STUDENT"<<endl;
					cout<<"9. LIST REPORTED STUDENT"<<endl;
					cout<<"10. GENERATE PRN"<<endl;
					cout<<"11. LIST ADMITED STUDENTS FOR GIVEN CENTER"<<endl;
					cin>>mchoice;
					return mchoice;
 	 	 }

	 int menu_choice_for_center_coordinator()
	 	 {
		 	 int mchoice;
		 	 	 	cout<<"0. EXIT"<<endl<<"1. SIGN IN"<<endl;
		 	 	 	cin>>mchoice;
		 	 	 	return mchoice;
 		}

	 int menu_choice_for_center_sign_in_coordinator()
	 	{
		 	 int mchoice;
		 	 	 	cout<<"0. EXIT"<<endl;
		 	 	 	cout<<"1. LIST COURSES"<<endl;
					cout<<"2. LIST ALLOACATED STUDENT"<<endl;
					cout<<"3. UPDATE REPORTED STATUS"<<endl;
					cout<<"4. LIST ADMITED STUDENT"<<endl;
					cin>>mchoice;
					return mchoice;
	 	}

	 bool comp_student_A_rank( const student& s1,const student& s2)
	 	 {
 			return s1.rank_a_section <s2.rank_a_section;
	 	 }
	 bool comp_student_B_rank( const student& s1,const student& s2)
	 	 {
  			return s1.rank_b_section <s2.rank_b_section;
	 	 }
	 bool comp_student_C_rank( const student& s1,const student& s2)
	 	 {
		 	 return s1.rank_c_section <s2.rank_c_section;
	 	 }

	 void sort_A_rank()
		{
	 	 	 return sort(addmissions.students.begin(),addmissions.students.end(),comp_student_A_rank);
		}
	 void sort_B_rank()
 		{
		 	 return sort(addmissions.students.begin(),addmissions.students.end(),comp_student_B_rank);
 		}
	 void sort_C_rank()
 		{
 	 	 	 return sort(addmissions.students.begin(),addmissions.students.end(),comp_student_C_rank);
 		}

	 bool comp_student_course( const student& s1,const student& s2)
	 	{
  			 return s1.allocated_course_name.compare(s2.allocated_course_name) < 0? true : false;
	 	}

	 bool comp_student_center( const student& s1,const student& s2)
	 	{
  			 return s1.allocated_center_id.compare(s2.allocated_center_id) < 0? true : false;
	 	}

	 bool comp_student_name( const student& s1,const student& s2)
	 	 {
   			 return s1.name.compare(s2.name) < 0? true : false;
	 	 }

	 void round_one_allocation()
	 	 {
		 	 sort_A_rank();
		 	 int pos1,i;
		 	 pos1=-1;
		 	 for(i=0;i<10;i++)
		 	 	{
		 		 	pos1++;
	 				addmissions.first_round_A_allocation(i,pos1);
		 	 	}

		 	 sort_B_rank();
		 	 pos1=-1;
		 	 for(i=0;i<10;i++)
		 	 	 {
		 		 	 pos1++;
		 		 	 addmissions.first_round_B_allocation(i,pos1);
		 	 	 }

		 	 sort_C_rank();
	 		pos1=-1;
	 		for(i=0;i<10;i++)
	 			{
	 				pos1++;
	 				addmissions.first_round_C_allocation(i,pos1);
	 			}
	 	 }









