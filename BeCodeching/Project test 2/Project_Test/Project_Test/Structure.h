#pragma once
#include<iostream>
#include<fstream>
#include<string>
#define MAX 100
using namespace std;

//======================================== 
//======================================== 
//---------- data 1 môn học -----------
typedef struct subject
{
	string code; //mã môn học
	string name; //tên môn học
	int t_credits; //số tín chỉ lý thuyết
	int p_credits; //số tín chỉ thực hành
} subject;
//--------- data ds môn học ----------
typedef struct subject_array_list
{
	int num = 0;
	subject list[MAX];
} subject_array_list;
//======================================== 
//=========================================
//--------- data 1 điểm của môn học -----------
typedef struct subject_point
{
	string code; //mã môn học
	int t_num; //lần thi
	float point; //điểm
}subject_point;
struct subject_point_node
{
	//----- data ------
	subject_point data;
	//-- pointer ------
	subject_point_node* pnext;
};
typedef struct subject_point_node		subject_point_node;
//--------- data ds điểm của môn học -----------
typedef struct subject_point_link_list
{
	subject_point_node* phead = NULL;
	subject_point_node* ptail = NULL;
}subject_point_link_list;
//======================================== 
//=========================================
//--------- data 1 sinh viên -----------
typedef struct student
{
	//-------------- data -------------
	string code; //mã số sinh viên 
	string l_name; //họ sinh viên
	string f_name; //tên sinh viên 
	string gender; //giới tính sv
	string t_num; //số điện thoại sinh viên
	int sub_p_num; //data số lượng điểm sinh viên 
	//-------------- (ds điểm)*pointer -------
	subject_point_link_list sub_p_list;
}student;
struct student_node
{
	//------ data ------
	student data;
	//--- pointer ------
	student_node* pnext;
};
typedef struct student_node			student_node;
//--------- data ds sinh viên -----------
typedef struct student_link_list
{
	student_node* phead = NULL;
	student_node* ptail = NULL;
}student_link_list;
//======================================== 
//=========================================
//--------- data 1 lớp học -----------
typedef struct student_class
{
	//--------- data ------------
	string code; //mã lớp
	string name; //tên lớp
	int y_begin; //năm nhập học
	int st_num; //số sinh viên của 1 lớp
	//------ (ds sinh viên)*pointer ------------
	student_link_list st_ls;
} student_class;
typedef struct student_class_array_list
{
	int num = 0;
	student_class list[MAX];
}student_class_array_list;