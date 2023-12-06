#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
class doctor
{
public:
	char doc_name[50];
	int license_no;
	char spec[30];
	char status[30];
	int temp_license_no;
	void AddDoctor();
	void DisplayAllDoctors();
	void DeleteDoctor();
	void DeleteAllDoctor();
	void EditDoctorsDetails();
	void SearchDoctor();
	void show(doctor &obj)
	{
		cout << "Name: " << obj.doc_name << endl;
		cout << "Speciality: " << obj.spec << endl;
		cout << "License no: " << obj.license_no << endl;
		cout << "______________________________" << endl;
	}
	void anesthesiology();
	void gynocology();
	void neurology();
	void radiology();
	void cardiology();
	void hysterology();
	void physiology();
	void ent();
};
void doctor::AddDoctor()
{
	doctor obj;
	system("cls");
	cin.ignore();
	cout << "*****Add Doctor Details*****" << endl;
	cout << "Enter the name of the doctor:";
	cin.getline(obj.doc_name, 50);
	cout << "Enter license number:";
	cin >> obj.license_no;
	cout << "Enter the speciality:";
	cin >> obj.spec;
	ofstream fout;
	fout.open("doctordata", ios::binary | ios::app);
	fout.write((char *)&obj, sizeof(obj));
	fout.close();
}
void doctor::DisplayAllDoctors()
{
	int found = 0;
	doctor obj;
	system("cls");
	cout << "*****Display All Doctor Details*****" << endl;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		found = 1;
		show(obj);
	}
	fin.close();
	if (found == 0)
	{
		cout << "No data found!!!!!" << endl;
	}
}
void doctor::DeleteDoctor()
{
	int found = 0;
	doctor obj;
	system("cls");
	cout << "*****Delete Doctor Details*****" << endl;
	cout << "Enter license number : ";
	cin >> temp_license_no;
	ifstream fin;
	ofstream fout;
	fin.open("doctordata", ios::binary);
	fout.open("tempdoctordata", ios::binary | ios::app);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (obj.license_no == temp_license_no)
		{
			found = 1;
			continue;
		}
		else
		{
			fout.write((char *)&obj, sizeof(obj));
		}
	}
	fin.close();
	fout.close();
	remove("doctordata");
	rename("tempdoctordata", "doctordata");
	if (found == 1)
	{
		cout << "Data deleted successfully....." << endl;
	}
	else
	{
		cout << "Invalid license number!!!!!" << endl;
	}
}
void doctor::DeleteAllDoctor()
{
	system("cls");
	cout << "*****Delete ALL Doctor Details*****" << endl;
	ofstream fout;
	fout.open("doctordata", ios::trunc);
	fout.close();
	cout << "All data deleted successfully....." << endl;
}
void doctor::EditDoctorsDetails()
{
	int found = 0;
	doctor obj;
	system("cls");
	cout << "*****Edit Doctor Details*****" << endl;
	cout << "Enter the license number:";
	cin >> temp_license_no;
	fstream finout;
	finout.open("doctordata", ios::in | ios::out | ios::binary);

	finout.seekg(0, ios::beg);
	while (finout.read((char *)&obj, sizeof(obj)))
	{
		if (obj.license_no == temp_license_no)
		{
			found = 1;
			cin.ignore();
			cout << "enter the name of the doctor:";
			cin.getline(obj.doc_name, 50);
			cout << "Enter license number:";
			cin >> obj.license_no;
			cout << "Enter the speciality:";
			cin >> obj.spec;
			int pos = finout.tellg();
			finout.seekp(pos - sizeof(obj), ios::beg);
			finout.write((char *)&obj, sizeof(obj));
			break;
		}
	}
	if (found == 0)
	{
		cout << "Details not found!!!!!" << endl;
	}
	else
	{
		cout << "Details edited successfully....." << endl;
	}
	finout.close();
}
void doctor::SearchDoctor()
{
	int found = 0;
	doctor obj;
	system("cls");
	cout << "*****Search Doctor*****" << endl;
	cout << "Enter the license number:";
	cin >> temp_license_no;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (obj.license_no == temp_license_no)
		{
			found = 1;
			show(obj);
		}
	}
	fin.close();
	if (found == 0)
	{
		cout << "No doctor found!!!!!" << endl;
	}
}
void doctor::anesthesiology()
{
	system("cls");
	cout << "<<------Anesthesiology------>>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (strcmp(obj.spec, "anesthesiology") == 0)
		{
			found = 1;
			show(obj);
		}
	}
	if (found == 0)
	{
		cout << "Doctor not available!!!!!" << endl;
	}
	fin.close();
}
void doctor::physiology()
{
	system("cls");
	cout << "<<------Physiology------>>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (strcmp(obj.spec, "Physicology") == 0)
		{
			found = 1;
			show(obj);
		}
	}
	if (found == 0)
	{
		cout << "Doctor not available!!!!!" << endl;
	}
	fin.close();
}
void doctor::gynocology()
{
	system("cls");
	cout << "<<------Gynocology------>>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (strcmp(obj.spec, "gynocology") == 0)
		{
			found = 1;
			show(obj);
		}
	}
	if (found == 0)
	{
		cout << "Doctor not available!!!!!" << endl;
	}
	fin.close();
}
void doctor::neurology()
{
	system("cls");
	cout << "<<------Neurology------>>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (strcmp(obj.spec, "neurology") == 0)
		{
			found = 1;
			show(obj);
		}
	}
	if (found == 0)
	{
		cout << "Doctor not available!!!!!" << endl;
	}
	fin.close();
}
void doctor::radiology()
{
	system("cls");
	cout << "<<------Radiology----->>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (strcmp(obj.spec, "radiology") == 0)
		{
			found = 1;
			show(obj);
		}
	}
	if (found == 0)
	{
		cout << "Doctor not available!!!!!" << endl;
	}
	fin.close();
}
void doctor::cardiology()
{
	system("cls");
	cout << "<<------Cardiology------>>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{

		if (strcmp(obj.spec, "cardiology") == 0)
		{
			found = 1;
			show(obj);
		}
	}
	if (found == 0)
	{
		cout << "Doctor not available!!!!!" << endl;
	}
	fin.close();
}
void doctor::hysterology()
{
	system("cls");
	cout << "<<------Hysterology------>>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (strcmp(obj.spec, "hysterology") == 0)
		{
			found = 1;
			show(obj);
		}
	}
	if (found == 0)
	{
		cout << "Doctor not available!!!!!" << endl;
	}
	fin.close();
}
void doctor::ent()
{
	system("cls");
	cout << "<<------ENT------>>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (strcmp(obj.spec, "ent") == 0)
		{
			found = 1;
			show(obj);
		}
	}
	if (found == 0)
	{
		cout << "Doctor not available!!!!!" << endl;
	}
	fin.close();
}
void menu_doc_info() // global function
{
	doctor obj;
	while (1)
	{
	flag:
		system("cls");
		cout << "<<------- DOCTORS INFORMATION------->>" << endl;
		cout << "\t\ta. Add Doctor\n";
		cout << "\t\tb. Display All Doctors\n";
		cout << "\t\tc. Search Doctor\n";
		cout << "\t\td. Edit Doctor Details\n";
		cout << "\t\te. Delete Doctor\n";
		cout << "\t\tf. Delete All Doctors\n";
		cout << "\t\tg. Back\n";
		char choice;
		cout << "\n\t\tEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 'a':
			obj.AddDoctor();
			break;

		case 'b':
			obj.DisplayAllDoctors();
			break;

		case 'c':
			obj.SearchDoctor();
			break;

		case 'd':
			obj.EditDoctorsDetails();
			break;

		case 'e':
			obj.DeleteDoctor();
			break;

		case 'f':
			obj.DeleteAllDoctor();
			break;

		case 'g':
			system("cls");
			return;

		default:
			system("cls");
			cout << "\n\t\tInvalid Choice....\n";
			cout << "\t\tPlease Enter from a to g\n";
			break;
		}
		cout << "\n\t\t\t\t\tPress any key to go to menu";
		getch();
	}
}
void menu_appoint_check() // global function
{
	doctor obj;
	while (1)
	{
	flag:
		system("cls");
		char choice;
		cout << "<<------MENU OF APPOINTMENT SERVICE------>>" << endl;
		cout << "a.Anesthesiology" << endl;
		cout << "b.Gynocology" << endl;
		cout << "c.Neurology" << endl;
		cout << "d.Radiology" << endl;
		cout << "e.Cardiology" << endl;
		cout << "f.Hysterology" << endl;
		cout << "g.ENT" << endl;
		cout << "h.Physiology" << endl;
		cout << "i.Back" << endl;
		cout << "Enter the choice: ";
		cin >> choice;
		switch (choice)
		{
		case 'a':
			obj.anesthesiology();
			break;
		case 'b':
			obj.gynocology();
			break;
		case 'c':
			obj.neurology();
			break;
		case 'd':
			obj.radiology();
			break;
		case 'e':
			obj.cardiology();
			break;
		case 'f':
			obj.hysterology();
			break;
		case 'g':
			obj.ent();
			break;
		case 'h':
			obj.physiology();
			break;
		case 'i':
			system("cls");
			return;
		default:
			system("cls");
			cout << "Invalid Choice" << endl;
			cout << "Please Press from a to i" << endl;
			break;
		}
		cout << "Press any key to go to menu" << endl;
		getch();
	}
}
int main()
{
	while (1)
	{
		system("cls");
		cout << "<<------MAIN MENU------>>" << endl;
		cout << "a.Appointment check" << endl
			 << "b.Appoint the doctor" << endl
			 << "c.Doctor Information" << endl
			 << "d.exit" << endl;
		char choice;
		cout << "Enter the choice:";
		cin >> choice;
		switch (choice)
		{
		case 'a':
			menu_appoint_check();
			break;
		case 'b':
			// baaki xa
			break;
		case 'c':
			menu_doc_info();
			break;
		case 'd':
			system("cls");
			exit(0);
		default:
			system("cls");
			cout << "\n\t\tInvalid Choice....\n";
			cout << "\t\tPlease Enter from a to d\n";
			break;
		}
	}
	return 0;
}
