#pragma once
#include"Structure.h"
#include"Load_file.h"
//==============================================
//=============== nguyên mẫu hàm ====================
//---------------- ds môn học ------------------
istream& operator >> (istream& is, subject& a);
void input_subject_list(subject_array_list& ls);
ostream& operator << (ostream& os, subject a);
void output_subject_list(subject_array_list ls);
//---------------- ds lớp ------------------
istream& operator >> (istream& is, student_class& a);
void input_student_class_list(student_class_array_list& ls);
ostream& operator << (ostream& os, student_class a);
void output_student_class_list(student_class_array_list ls);
//-------------- ds sinh viên --------------
//student_node* create_new_student_node(student a);
//void add_node_last(student_link_list& st_ls, student a);
int check_class_code(student_class_array_list ls, string code);
istream& operator >> (istream& is, student& a);
void input_student_list_in_one_class(student_class_array_list& ls);
ostream& operator << (ostream& os, student a);
void output_student_list_in_one_class(student_class_array_list ls);
ostream& operator << (ostream& os, student a);
void output_student_list_on_all_classes(student_class_array_list ls);
void arrange_student_list_with_alphabet(student_class_array_list& ls);
void output_student_list_with_year_begin(student_class_array_list ls);
//---------------- ds điểm ------------------
//subject_point_node* create_subject_point_node(subject_point a);
//void add_node_last(subject_point_link_list& ls, subject_point a);
int check_sub_code(subject_array_list ls, subject_point a);
istream& operator >> (istream& is, subject_point& a);
void input_subject_point_list_in_one_class(student_class_array_list& ls, subject_array_list ls_1);
ostream& operator << (ostream& os, subject_point& a);
void output_subject_point_list_in_one_class(student_class_array_list ls);
void output_subject_point_list_in_all_class(student_class_array_list ls);
void output_subject_point_list_in_1_student(student_class_array_list ls);


//==============================================
//==============================================
//---------- menu ------------
void menu()
{
	bool quit = false; 
	student_class_array_list cl_ls;
	subject_array_list sub_ls;
	while (quit == false)
	{
		system("cls");
		int c;
		cout << "1. Nhap ds mon." << endl;
		cout << "2. Xuat ds mon." << endl;
		cout << "3. Xuat file ds mon." << endl;
		cout << "4. Doc file ds mon." << endl;
		cout << "====================================" << endl;
		cout << "5. Nhap ds lop." << endl;
		cout << "6. Xuat ds lop." << endl;
		cout << "7. Xuat file ds lop." << endl;
		cout << "====================================" << endl;
		cout << "8. Doc file ds lop -> ds sv -> ds diem." << endl;
		cout << "====================================" << endl;
		cout << "9. Nhap ds sinh vien cua 1 lop." << endl;
		cout << "10. Xuat ds sinh vien cua 1 lop." << endl;
		cout << "11. Xuat ds sinh vien cua tat ca lop." << endl;
		cout << "12. Sap xep ds sinh vien theo alphabet." << endl;
		cout << "13. Xuat ds sinh vien theo nam nhap hoc." << endl;
		cout << "14. Xuat file ds sinh vien." << endl;
		cout << "====================================" << endl;
		cout << "15. Nhap ds diem cho sv." << endl;
		cout << "16. Xuat ds diem cho 1 lop." << endl;
		cout << "17. Xuat ds diem cho tat ca lop." << endl;
		cout << "18. Xuat ds diem cho 1 sinh vien cua 1 lop." << endl;
		cout << "19. Xuat file ds diem sinh vien." << endl;
		cout << "0. Thoat." << endl;
		cout << "Nhap lc: "; cin >> c; cin.ignore();
		switch (c)
		{
		case 1:
			input_subject_list(sub_ls);
			break;
		case 2:
			output_subject_list(sub_ls); system("pause");
			break;
		case 3: 
			write_subject_list_file(sub_ls); system("pause");
			break;
		case 4:
			load_subject_list_file(sub_ls); system("pause");
			break;
		case 5:
			input_student_class_list(cl_ls);
			break;
		case 6:
			output_student_class_list(cl_ls); system("pause");
			break;
		case 7:
			write_student_class_list_file(cl_ls); system("pause"); 
			break;
		//===========================================================
		case 8:
			load_student_class_list_file(cl_ls); 
			load_student_list_file(cl_ls);
			load_subject_point_list_file(cl_ls);
			system("pause"); break;
		//===========================================================
		case 9:
			input_student_list_in_one_class(cl_ls);
			break;
		case 10:
			output_student_list_in_one_class(cl_ls);
			system("pause"); break;
		case 11:
			output_student_list_on_all_classes(cl_ls);
			system("pause"); break;
		case 12:
			arrange_student_list_with_alphabet(cl_ls);
			system("pause"); break;
		case 13:
			output_student_list_with_year_begin(cl_ls);
			system("pause"); break;
		case 14:
			write_student_list_file(cl_ls);
			system("pause"); break;
		case 15:
			input_subject_point_list_in_one_class(cl_ls, sub_ls);
			break;
		case 16:
			output_subject_point_list_in_one_class(cl_ls);
			system("pause"); break;
		case 17:
			output_subject_point_list_in_all_class(cl_ls);
			system("pause"); break;
		case 18:
			output_subject_point_list_in_1_student(cl_ls);
			system("pause"); break;
		case 19:
			write_subject_point_list_file(cl_ls);
			system("pause"); break;
		case 0:
			cout << "Quitting!" << endl; 
			quit = true; 
			break;
		default:
			cout << "Loi, vui long nhap lai!"; break;
		}
	}
}
//==============================================
//============== định nghĩa hàm =====================
//---------------- ds môn học ------------------
istream& operator >> (istream& is, subject& a)
{
	cout << "Nhap ma so mon hoc: "; getline(is, a.code);
	cout << "Nhap ten mon hoc: "; getline(is, a.name);
	cout << "Nhap so tin chi ly thuyet: "; is >> a.t_credits;
	cout << "Nhap so tin chi thuc hanh: "; is >> a.p_credits;
	return is;
}
void input_subject_list(subject_array_list& ls)
{
	int n;
	cout << "Nhap so luong mon can nhap: "; cin >> n; 
	for (int i = 1; i <= n; i++)
	{
		cin.ignore();
		cout << "======== Nhap mon hoc thu " << i << " ==========" << endl;
		subject a;
		cin >> a;
		ls.list[ls.num++] = a;
	}
}
ostream& operator << (ostream& os, subject a)
{
	os << "Ma so mon hoc: " << a.code << endl;
	os << "Ten mon hoc: " << a.name << endl;
	os << "So tin chi ly thuyet: " << a.t_credits << endl;
	os << "So tin chi thuc hanh: " << a.p_credits << endl;
	return os;
}
void output_subject_list(subject_array_list ls)
{
	for (int i = 0; i < ls.num; i++)
	{
		cout << "======== Ds mon hoc thu " << i + 1 << " ============" << endl;
		cout << ls.list[i];
	}
}
//---------------- ds lớp ------------------
istream& operator >> (istream& is, student_class& a)
{
	cout << "Nhap ma lop: "; getline(is, a.code);
	cout << "Nhap ten lop: "; getline(is, a.name);
	cout << "Nhap nam hoc: "; is >> a.y_begin;
	return is;
}
void input_student_class_list(student_class_array_list& ls)
{
	int n;
	cout << "Nhap so luong lop can nhap: "; cin >> n; 
	for (int i = 1; i <= n; i++)
	{
		cin.ignore();
		cout << "======== Nhap lop thu " << i << " ================" << endl;
		student_class a;
		cin >> a;
		ls.list[ls.num++] = a;
	}
}
ostream& operator << (ostream& os, student_class a)
{
	os << "Ma so mon hoc: " << a.code << endl;
	os << "Ten mon hoc: " << a.name << endl;
	os << "So tin chi ly thuyet: " << a.y_begin << endl;
	return os;
}
void output_student_class_list(student_class_array_list ls)
{
	for (int i = 0; i < ls.num; i++)
	{
		cout << "======== Thong tin lop " << ls.list[i].name << " ===" << endl;
		cout << ls.list[i];
	}
}
//-------------- ds sinh viên --------------
student_node* create_new_student_node(student a)
{
	//---------- new node ----------
	student_node* p = new student_node;
	//------------ data -------------
	p->data.code = a.code;
	p->data.l_name = a.l_name;
	p->data.f_name = a.f_name;
	p->data.gender = a.gender;
	p->data.t_num = a.t_num;
	//---------- pnext ------------
	p->pnext = NULL;
	return p;
}
void add_node_last(student_link_list& st_ls, student a)
{
	//ds rỗng
	if (st_ls.phead == NULL && st_ls.ptail == NULL)
	{
		//chuyển data sang node
		student_node* p = create_new_student_node(a);
		//thêm 
		st_ls.phead = st_ls.ptail = p;
	}
	else
	{
		//ds có 1 p/tử
		if (st_ls.phead == st_ls.ptail)
		{
			//chuyển data sang node
			student_node* p = create_new_student_node(a);
			//thêm 
			st_ls.phead->pnext = p;
			st_ls.ptail = p;
		}
		//ds có n p/tử
		else
		{
			//chuyển data sang node
			student_node* p = create_new_student_node(a);
			//thêm
			st_ls.ptail->pnext = p;
			st_ls.ptail = p;
		}
	}
}
int check_class_code(student_class_array_list ls, string code)
{
	int index = -1;
	for (int i = 0; i < ls.num; i++)
	{
		if (_stricmp(ls.list[i].code.c_str(), code.c_str()) == 0)
		{
			index = i;
			break;
		}
	}
	return index;
}
istream& operator >> (istream& is, student& a)
{
	cout << "Nhap ma so sinh vien: "; getline(is, a.code);
	cout << "Nhap ho sinh vien: "; getline(is, a.l_name);
	cout << "Nhap ten sinh vien: "; getline(is, a.f_name);
	cout << "Nhap gioi tinh sinh vien: "; getline(is, a.gender);
	cout << "Nhap so dien thoai sinh vien: "; getline(is, a.t_num);
	return is;
}
void input_student_list_in_one_class(student_class_array_list& ls)
{
	string code;
	cout << "======== Nhap thong tin ds sinh vien 1 lop ====" << endl;
	cout << "Nhap ma lop: "; getline(cin, code);
	int i = check_class_code(ls, code);
	if (i == -1)
	{
		cout << "Loi nhap lop!" << endl; system("pause");
		return;
	}
	else
	{
		cout << "====== Da tim thay =======" << endl;
		int n;
		cout << "Nhap so luong sinh vien can nhap: "; cin >> n; 
		ls.list[i].st_num = n; cin.ignore();
		for (int j = 1; j <= n; j++)
		{
			student a;
			cout << "===== Nhap thong tin sv thu " << j << " ========" << endl;
			cin >> a;
			add_node_last(ls.list[i].st_ls, a);
		}
	}
}
ostream& operator << (ostream& os, student a)
{
	os << "Nhap ma so sinh vien: " << a.code << endl;
	os << "Nhap ho sinh vien: " << a.l_name << endl;
	os << "Nhap ten sinh vien: " << a.f_name << endl;
	os << "Nhap gioi tinh sinh vien: " << a.gender << endl;
	os << "Nhap so dien thoai sinh vien: " << a.t_num << endl;
	return os;
}
void output_student_list_in_one_class(student_class_array_list ls)
{
	string code;
	cout << "======== Thong tin ds sinh vien 1 lop =======" << endl;
	cout << "Nhap ma lop: "; getline(cin, code);
	int i = check_class_code(ls, code);
	if (i == -1)
	{
		cout << "Loi nhap lop!" << endl;
		return;
	}
	else
	{
		int count = 1;
		cout << "====== Da tim thay =======" << endl;
		cout << "=== Xuat ds sv cua lop " << ls.list[i].name << " ===" << endl;
		for (student_node* p = ls.list[i].st_ls.phead; p != NULL; p = p->pnext)
		{
			cout << "===== Sv thu " << count++ << " ======" << endl;
			cout << p->data;
		}
	}
}
void output_student_list_on_all_classes(student_class_array_list ls)
{
	for (int i = 0; i < ls.num; i++)
	{
		cout << "==== Xuat ds sv cua lop " << ls.list[i].name <<" ===" << endl;
		int count = 1;
		for (student_node* p = ls.list[i].st_ls.phead; p != NULL; p = p->pnext)
		{
			cout << "===== Sv thu " << count++ << " ======" << endl;
			cout << p->data;
		}
		cout << endl;
	}
}
void arrange_student_list_with_alphabet(student_class_array_list& ls)
{
	for (int i = 0; i < ls.num; i++)
	{
		for (student_node* p = ls.list[i].st_ls.phead; p->pnext != NULL; p = p->pnext)
		{
			for (student_node* k = p->pnext; k != NULL; k = k->pnext)
			{
				if (_stricmp(p->data.f_name.c_str(), k->data.f_name.c_str()) > 0)
				{
					swap(p->data, k->data);
				}
				else if (_stricmp(p->data.f_name.c_str(), k->data.f_name.c_str()) == 0)
				{
					if (_stricmp(p->data.l_name.c_str(), k->data.l_name.c_str()) > 0)
					{
						swap(p->data, k->data);
					}
				}
			}
		}
	}
	cout << "Da sap xep xong!" << endl;
}
void output_student_list_with_year_begin(student_class_array_list ls)
{
	int year;
	cout << "Nhap nam nhap hoc: "; cin >> year;
	for (int i = 0; i < ls.num; i++)
	{
		if (ls.list[i].y_begin == year)
		{
			cout << "========= Da tim thay lop " << ls.list[i].name   << " =========" << endl;
			int count = 1;
			for (student_node* p = ls.list[i].st_ls.phead; p != NULL; p = p->pnext)
			{
				cout << "===== Sv thu " << count++ << " ======" << endl;
				cout << p->data;
			}
		}
	}
}
//---------------- ds điểm ------------------
subject_point_node* create_subject_point_node(subject_point a)
{
	subject_point_node* p = new subject_point_node;
	//----- data -----
	p->data.code= a.code;
	p->data.t_num = a.t_num;
	p->data.point = a.point;
	//----- pointer ----
	p->pnext = NULL;
	return p;
}
void add_node_last(subject_point_link_list& ls, subject_point a)
{
	//ds rỗng
	if (ls.phead == NULL && ls.ptail == NULL)
	{
		subject_point_node* p = create_subject_point_node(a);
		ls.phead = ls.ptail = p;
	}
	else
	{
		//ds có 1 p/tử
		if (ls.phead == ls.ptail)
		{
			subject_point_node* p = create_subject_point_node(a);
			ls.phead->pnext = p;
			ls.ptail = p;
		}
		//ds có n p/tử
		else if (ls.phead != ls.ptail)
		{
			subject_point_node* p = create_subject_point_node(a);
			ls.ptail->pnext = p;
			ls.ptail = p;
		}
	}
	
}
int check_sub_code(subject_array_list ls, subject_point a)
{
	int check = 0;
	for (int i = 0; i < ls.num; i++)
	{
		if (a.code == ls.list[i].code)
		{
			return check = 1;
		}
	}
	return check = 0;
}
istream& operator >> (istream& is, subject_point& a)
{
	cout << "Nhap ma mon hoc: "; getline(is, a.code);
	cout << "Nhap lan thi: "; is >> a.t_num;
	cout << "Nhap diem: "; is >> a.point;
	return is;
}
void input_subject_point_list_in_one_class(student_class_array_list& ls, subject_array_list ls_1)
{
	for (int i = 0; i < ls.num; i++)
	{
		cout << "===== Nhap thong tin lop thu " << i + 1 << " =====" << endl;
		int c = 1;
		for (student_node* p = ls.list[i].st_ls.phead; p != NULL; p = p->pnext)
		{
			cout << "===== Nhap thong tin sv thu " << c++ << " =====" << endl;
			int n;
			cout << "Nhap so luong diem mon hoc can nhap: "; cin >> n;
			p->data.sub_p_num = n;
			for (int j = 1; j <= n; j++)
			{
				cout << "==== Nhap diem mon hoc thu " << j << "======" << endl;
				subject_point a;
				int check;
				do
				{
					cin.ignore();
					cin >> a; 
					check = check_sub_code(ls_1, a);
					if (check == 0)
					{
						cout << "Loi nhap lai!" << endl;
					}
				} while (check != 1);
				add_node_last(p->data.sub_p_list, a);
			}
		}
	}
}
ostream& operator << (ostream& os, subject_point& a)
{
	os << "Ma mon hoc: " << a.code << endl;
	os << "Lan thi: " << a.t_num << endl;
	os << "Diem: " << a.point << endl;
	return os;
}
void output_subject_point_list_in_one_class(student_class_array_list ls)
{
	string cl_code;
	cout << "Nhap ma lop: "; getline(cin, cl_code);
	int i = check_class_code(ls, cl_code);
	if (i == -1)
	{
		cout << "Loi nhap ma lop!" << endl;
		system("pause"); return;
	}
	else
	{
		cout << "===== Xuat thong tin lop " << i + 1 << " ===========" << endl;
		int c = 1;
		for (student_node* p = ls.list[i].st_ls.phead; p != NULL; p = p->pnext)
		{
			cout << "===== Xuat thong tin sv thu" << c++ << " =======" << endl;
			int index = 1;
 			for (subject_point_node* k = p->data.sub_p_list.phead; k != NULL; k = k->pnext)
			{
				cout << "==== Xuat diem mon hoc thu " << index++ <<   " ========" << endl;
				cout << k->data;
			}
		}
	}
}
void output_subject_point_list_in_all_class(student_class_array_list ls)
{
	for (int i = 0; i < ls.num; i++)
	{
		cout << "===== Xuat thong tin lop " << i + 1 << " ===========" << endl;
		int c = 1;
		for (student_node* p = ls.list[i].st_ls.phead; p != NULL; p = p->pnext)
		{
			cout << "===== Xuat thong tin sv thu " << c++ << " =======" << endl;
			int index = 1;
			for (subject_point_node* k = p->data.sub_p_list.phead; k != NULL; k = k->pnext)
			{
				cout << "==== Xuat diem mon hoc thu " << index++ << " ========" << endl;
				cout << k->data;
			}
		}
	}
}
void output_subject_point_list_in_1_student(student_class_array_list ls)
{
	string cl_code;
	cout << "Nhap ma lop: "; getline(cin, cl_code);
	int i = check_class_code(ls, cl_code);
	if (i == -1)
	{
		cout << "Loi nhap ma lop!" << endl;
		system("pause"); return;
	}
	else
	{
		cout << "======== Xuat thong tin 1 sinh vien =======" << endl;
		string st_code; 
		cout << "Nhap ma so sinh vien: "; getline(cin, st_code);
		for (student_node* p = ls.list[i].st_ls.phead; p != NULL; p = p->pnext)
		{
			if (_stricmp(p->data.code.c_str(), st_code.c_str()) == 0)
			{
				cout << "===== Da tim thay sv =====" << endl;
				int index = 1;
				for (subject_point_node* k = p->data.sub_p_list.phead; k != NULL; k = k->pnext)
				{
					cout << "==== Xuat diem mon hoc thu " << index++ << " ========" << endl;
					cout << k->data;
				}
			}
		}
	}
}
