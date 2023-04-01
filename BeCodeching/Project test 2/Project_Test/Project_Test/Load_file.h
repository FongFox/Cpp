#pragma once
#include"Structure.h"
//====================================================================
//======== Khu vực nguyên mẫu hàm cần thiết cho load file ============
student_node* create_new_student_node(student a);
void add_node_last(student_link_list& st_ls, student a);
subject_point_node* create_subject_point_node(subject_point a);
void add_node_last(subject_point_link_list& ls, subject_point a);

//==================================================
//================ nguyên mẫu hàm =======================
//---------------- ghi file ds môn học ------------------
void write_subject_list_file(subject_array_list ls);
//---------------- Doc file ds môn học ------------------
void load_subject_list_file(subject_array_list& ls);
//---------------- ghi file ds lớp ------------------
void write_student_class_list_file(student_class_array_list ls);
//---------------- Doc file ds lớp ------------------
void load_student_class_list_file(student_class_array_list& ls);
//----------- ghi file ds sinh viên của 1 lớp -----
void write_student_list_file(student_class_array_list ls);
//---------- Đọc file ds sinh viên ------------
void load_student_list_file(student_class_array_list& ls);
//----------- ghi file ds diem ---------
void write_student_list_file(student_class_array_list ls);
//---------- Đọc file ds điểm ------------
void load_subject_point_list_file(student_class_array_list& ls);



//==================================================
//================= định nghĩa hàm ======================
//---------------- ghi file ds môn học ------------------
void write_subject_list_file(subject_array_list ls)
{
	ofstream file("ds_mh.txt", ios::out);
	for (int i = 0; i < ls.num; i++)
	{
		file << ls.list[i].code << "|";
		file << ls.list[i].name << "|";
		file << ls.list[i].t_credits << "|";
		file << ls.list[i].p_credits;
		if (i + 1 < ls.num)
		{
			file << endl;
		}
	}
	cout << "Xuat thanh cong!" << endl;
	file.close();
}
//---------------- Doc file ds môn học ------------------
void load_subject_list_file(subject_array_list& ls)
{
	ifstream file("ds_mh.txt", ios::in);
	if (file.fail() == true)
	{
		cout << "Loi khong mo duoc file!";
		return;
	}
	while (!file.eof())
	{
		//------- lấy data từ file -------
		subject a;
		getline(file, a.code, '|');
		getline(file, a.name, '|');
		file >> a.t_credits; 
		file.ignore();
		file >> a.p_credits; 
		file.ignore();
		//------ thêm data vào ds mh ------
		ls.list[ls.num++] = a;
	}
	cout << "Doc file mh thanh cong!" << endl;
	file.close();
}
//---------------- ghi file ds lớp ------------------
void write_student_class_list_file(student_class_array_list ls)
{
	ofstream file("ds_lop.txt", ios::out);
	for (int i = 0; i < ls.num; i++)
	{
		file << ls.list[i].code << "|";
		file << ls.list[i].name << "|";
		file << ls.list[i].y_begin;
		if (i + 1 < ls.num)
		{
			file << endl;
		}
	}
	cout << "Xuat thanh cong!" << endl;
	file.close();
}
//---------------- Doc file ds lớp ------------------
void load_student_class_list_file(student_class_array_list& ls)
{
	ifstream file("ds_lop.txt", ios::in);
	if (file.fail() == true)
	{
		cout << "Loi khong mo duoc file!";
		return;
	}
	while (!file.eof())
	{
		//------- lấy data từ file -------
		student_class a;
		getline(file, a.code, '|');
		getline(file, a.name, '|');
		file >> a.y_begin; 
		file.ignore();
		//------ thêm data vào ds mh ------
		ls.list[ls.num++] = a;
	}
	cout << "Doc file lop thanh cong!" << endl;
	file.close();
}
//----------- ghi file ds sinh viên của 1 lớp -----
void write_student_list_file(student_class_array_list ls)
{
	ofstream file("ds_sv.txt", ios::out);
	for (int i = 0; i < ls.num; i++)
	{
		file << ls.list[i].st_num << endl;
		for (student_node* p = ls.list[i].st_ls.phead; p != NULL; p = p->pnext)
		{
			file << p->data.code << "|";
			file << p->data.l_name << "|";
			file << p->data.f_name << "|";
			file << p->data.gender << "|";
			file << p->data.t_num;
			if (p->pnext != NULL)
			{
				file << endl;
			}
		}
	}
	cout << "Ghi file thanh cong!" << endl;
	file.close();
}
//---------- Đọc file ds sinh viên ------------
void load_student_list_file(student_class_array_list& ls)
{
	ifstream file("ds_sv.txt", ios::in);
	if (file.fail() == true)
	{
		cout << "Loi khong mo duoc file!"; system("pause");
		return;
	}
	for (int i = 0; i < ls.num; i++)
	{
		int n; file >> n; file.ignore();
		for (int j = 1; j <= n; j++)
		{
			student a;
			getline(file, a.code, '|');
			getline(file, a.l_name, '|');
			getline(file, a.f_name,'|');
			getline(file, a.gender,'|');
			getline(file, a.t_num);
			add_node_last(ls.list[i].st_ls, a);
		}
	}
	cout << "load file sv thanh cong!" << endl;
	file.close();
}
//----------- ghi file ds diem ---------
void write_subject_point_list_file(student_class_array_list ls)
{
	ofstream file("ds_diem.txt", ios::out);
	for (int i = 0; i < ls.num; i++)
	{
		for (student_node* p = ls.list[i].st_ls.phead; p != NULL; p = p->pnext)
		{
			file << p->data.sub_p_num << endl;
			for (subject_point_node* k = p->data.sub_p_list.phead; k != NULL; k = k->pnext)
			{
				file << k->data.code << "|";
				file << k->data.t_num << "|";
				file << k->data.point;
				if (k->pnext != NULL)
				{
					file << endl;
				}
			}
		}
	}
	cout << "Ghi file thanh cong!" << endl;
	file.close();
}
//---------- Đọc file ds điểm ------------
void load_subject_point_list_file(student_class_array_list& ls)
{
	ifstream file("ds_diem.txt", ios::in);
	if (file.fail() == true)
	{
		cout << "Loi khong mo duoc file!"; system("pause");
		return;
	}
	for (int i = 0; i < ls.num; i++)
	{
		for (student_node* p = ls.list[i].st_ls.phead; p != NULL; p = p->pnext)
		{
			int n;
			file >> n; 
			file.ignore();
			for (int i = 1; i <= n; i++)
			{
				subject_point a;
				getline(file, a.code, '|');
				file >> a.t_num; 
				file.ignore();
				file >> a.point; 
				file.ignore();
				add_node_last(p->data.sub_p_list, a);
			}
		}
	}
	cout << "load file diem thanh cong!" << endl;
	file.close();
}