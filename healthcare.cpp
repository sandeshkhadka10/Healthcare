#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <unistd.h>
using namespace std;
class doctor
{
public:
	int appointed_pat_no;
	char doc_name[50];
	int license_no;
	int temp_license_no;
	char spec[30];
	int limit = 2;

public:
	void show(doctor &obj);
	void check_found(int &found);
	void AddDoctor();
	void DisplayAllDoctors();
	void DeleteDoctor();
	void DeleteAllDoctor();
	void EditDoctorsDetails();
	void SearchDoctor();
	void gynocology();
	void neurology();
	void radiology();
	void cardiology();
	void hysterology();
	void physiology();
	void ent();
};
void doctor::show(doctor &obj)
{
	cout << "\n\t\tName: " << obj.doc_name << endl;
	cout << "\t\tSpeciality: " << obj.spec << endl;
	cout << "\t\tLicense no: " << obj.license_no << endl;
	cout << "\t\t______________________________" << endl;
}
void doctor::check_found(int &found)
{
	if (found == 0)
	{
		cout << "\n\t\tDoctor Unavailable!!!!!" << endl;
	}
}
void doctor::AddDoctor()
{
	doctor obj;
	system("cls");
	cin.ignore();
	cout << "\t\t<<------Add Doctor Details------>>" << endl;
	cout << "\n\t\tEnter the name of the doctor:";
	cin.getline(obj.doc_name, 50);
	cout << "\t\tEnter license number:";
	cin >> obj.license_no;
	cout << "\t\tEnter the speciality:";
	cin >> obj.spec;
	obj.appointed_pat_no = 0;
	ofstream fout;
	fout.open("doctordata", ios::binary | ios::app);
	fout.write((char *)&obj, sizeof(obj));
	cout << "\n\t\tDetails added successfully" << endl;
	fout.close();
}

void doctor::DisplayAllDoctors()
{
	int found = 0;
	doctor obj;
	system("cls");
	cout << "\t\t<<------Display All Doctor Details------>>" << endl;
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
		cout << "\n\t\tNo data found!!!!!" << endl;
	}
}
void doctor::DeleteDoctor()
{
	int found = 0;
	doctor obj;
	system("cls");
	cout << "\t\t<<------Delete Doctor Details------>> " << endl;
	cout << "\n\t\tEnter license number : ";
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
		cout << "\n\t\tDetails deleted successfully....." << endl;
	}
	else
	{
		cout << "\n\t\tInvalid license number!!!!!" << endl;
	}
}
void doctor::DeleteAllDoctor()
{
	system("cls");
	cout << "\t\t<<------Delete ALL Doctor Details------>>" << endl;
	ofstream fout;
	fout.open("doctordata", ios::trunc);
	fout.close();
	cout << "\n\t\tAll data deleted successfully....." << endl;
}
void doctor::EditDoctorsDetails()
{
	int found = 0;
	doctor obj;
	system("cls");
	cout << "\t\t<<------Edit Doctor Details------>>" << endl;
	cout << "\n\t\tEnter the license number:";
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
			show(obj);
			cout << "\n\t\tEnter the name of the doctor:";
			cin.getline(obj.doc_name, 50);
			cout << "\t\tEnter license number:";
			cin >> obj.license_no;
			cout << "\t\tEnter the speciality:";
			cin >> obj.spec;
			int pos = finout.tellg();
			finout.seekp(pos - sizeof(obj), ios::beg);
			finout.write((char *)&obj, sizeof(obj));
			break;
		}
	}
	if (found == 0)
	{
		cout << "\n\t\tDetails not found!!!!!" << endl;
	}
	else
	{
		cout << "\n\t\tDetails edited successfully....." << endl;
	}
	finout.close();
}
void doctor::SearchDoctor()
{
	int found = 0;
	doctor obj;
	system("cls");
	cout << "\t\t<<------Search Doctor------>>" << endl;
	cout << "\n\t\tEnter the license number:";
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
		cout << "\n\t\tDoctor not found!!!!!" << endl;
	}
}

void doctor::physiology()
{
	system("cls");
	cout << "\t\t<<------Physiology------>>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (strcmp(obj.spec, "physiology") == 0 && (obj.appointed_pat_no < obj.limit))
		{
			found = 1;
			show(obj);
		}
	}
	check_found(found);
	fin.close();
}
void doctor::gynocology()
{
	system("cls");
	cout << "\t\t<<------Gynocology------>>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (strcmp(obj.spec, "gynocology") == 0 && (obj.appointed_pat_no < obj.limit))
		{
			found = 1;
			show(obj);
		}
	}
	check_found(found);
	fin.close();
}
void doctor::neurology()
{
	system("cls");
	cout << "\t\t<<------Neurology------>>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (strcmp(obj.spec, "neurology") == 0 && (obj.appointed_pat_no < obj.limit))
		{
			found = 1;
			show(obj);
		}
	}
	check_found(found);
	fin.close();
}
void doctor::radiology()
{
	system("cls");
	cout << "\t\t<<------Radiology----->>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (strcmp(obj.spec, "radiology") == 0 && (obj.appointed_pat_no < obj.limit))
		{
			found = 1;
			show(obj);
		}
	}
	check_found(found);
	fin.close();
}
void doctor::cardiology()
{
	system("cls");
	cout << "\t\t<<------Cardiology------>>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{

		if (strcmp(obj.spec, "cardiology") == 0 && (obj.appointed_pat_no < obj.limit))
		{
			found = 1;
			show(obj);
		}
	}
	check_found(found);
	fin.close();
}
void doctor::hysterology()
{
	system("cls");
	cout << "\t\t<<------Hysterology------>>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (strcmp(obj.spec, "hysterology") == 0 && (obj.appointed_pat_no < obj.limit))
		{
			found = 1;
			show(obj);
		}
	}
	check_found(found);
	fin.close();
}
void doctor::ent()
{
	system("cls");
	cout << "\t\t<<------ENT------>>" << endl;
	doctor obj;
	int found = 0;
	ifstream fin;
	fin.open("doctordata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		if (strcmp(obj.spec, "ent") == 0 && (obj.appointed_pat_no < obj.limit))
		{
			found = 1;
			show(obj);
		}
	}
	check_found(found);
	fin.close();
}
class patient : public doctor
{
protected:
	int appointed_doc;
	char patient_name[50];
	char gender[10];
	int age;

public:
	void book_doc();
	void show_patient();
};
void patient ::book_doc()
{
	system("cls");
	cout << "\t\t<<------Appoint Doctor------>>" << endl;
	int appoint = 0;
	int busy = 0;
	int found = 0;
	doctor obj;
	cout << "\n\t\tEnter the license no of doctor to appoint: ";
	cin >> temp_license_no;
	fstream finout;
	finout.open("doctordata", ios::in | ios::out | ios::binary);
	finout.seekg(0, ios::beg);
	while (finout.read((char *)&obj, sizeof(obj)))
	{
		if (obj.license_no == temp_license_no)
		{
			found = 1;
			if (obj.appointed_pat_no < obj.limit)
			{
				busy = 0;
				appoint = 1;

				patient obj1;
				cin.ignore();
				cout << "\n\t\tEnter patient name : ";
				cin.getline(obj1.patient_name, 50);
				cout << "\t\tEnter patient age : ";
				cin >> obj1.age;
				cout << "\t\tEnter patient gender(male/female) : ";
				cin >> obj1.gender;
				obj1.appointed_doc = temp_license_no;
				ofstream fout;
				fout.open("patientdata", ios::binary | ios::app);
				fout.write((char *)&obj1, sizeof(obj1));
				cout << "\n\t\tDoctor appointed successfully....." << endl;
				fout.close();
			}
			else
			{
				busy = 1;
				appoint = 0;
			}
			if (appoint == 1)
			{
				int pos = finout.tellg();
				finout.seekp(pos - sizeof(obj), ios::beg);
				obj.appointed_pat_no++;
				finout.write((char *)&obj, sizeof(obj));
			}
			if (busy == 1)
			{
				cout << "\n\t\tDoctor is unavailable!!!!!" << endl;
			}
			break;
		}
		else
		{
			found = 0;
		}
	}
	check_found(found);
	finout.close();
}
void patient::show_patient()
{
	int found = 0;
	patient obj;
	system("cls");
	cout << "\t\t<<------Show Patient------>>" << endl;
	ifstream fin;
	fin.open("patientdata", ios::binary);
	fin.seekg(0, ios::beg);
	while (fin.read((char *)&obj, sizeof(obj)))
	{
		found = 1;
		cout << "\n\t\tPatient name : " << obj.patient_name << endl;
		cout << "\t\tPatient age : " << obj.age << endl;
		cout << "\t\tPatient gender(male/female) : " << obj.gender << endl;
		cout << "\t\tLicense number of appointed doctor :" << obj.appointed_doc << endl;
		cout << "\t\t____________________________________________" << endl;
	}
	fin.close();
	if (found == 0)
	{
		cout << "\n\t\tPatient not found!!!!!" << endl;
	}
	cout << "\n\t\tPress any key to go back....." << endl;
	getch();
}
class credentials
{
private:
	char username[50];
	char password[11];
	char pin[5];
	char p[5];
	char temp_un[50];
	char temp_pass[11];

public:
	void signup();
	void pi_n();
	int login();
	void forgot_pass();
};

void credentials ::signup()
{
	credentials obj;
	cout << "\n\t\tEnter new username: ";
	cin >> obj.username;
	int i = 0;
	cout << "\t\tEnter new password(10 characters): ";
	while (true)
	{
		char ch = _getch();
		if (ch == 13)
			break;
		obj.password[i] = ch;
		cout << '*';
		i++;
	}
	obj.password[i] = '\0';
	ofstream fout;
	fout.open("p_confidentials", ios::trunc | ios::binary);
	fout.write((char *)&obj, sizeof(obj));
	fout.close();
}
void credentials ::pi_n()
{
	credentials obj;
	int j = 0;
	cout << "\n\t\tEnter pin(used while doing forget password/4 character): ";
	while (true)
	{
		char c = _getch();
		if (c == 13)
		{
			break;
		}
		obj.pin[j] = c;
		cout << "*";
		j++;
	}

	obj.pin[j] = '\0';
	ofstream fout1;
	fout1.open("pin", ios::binary);
	fout1.write((char *)&obj, sizeof(obj));
	fout1.close();
}
int credentials ::login()
{
	credentials obj;
	system("cls");
	cout << "\t\t<<------Log In------>>" << endl;
	cout << "\n\t\tUsername: ";
	cin >> temp_un;
	int i = 0;
	cout << "\t\tPassword(10 characters): ";
	while (true)
	{
		char ch = _getch();
		if (ch == 13)
			break;
		temp_pass[i] = ch;
		cout << '*';
		i++;
	}
	temp_pass[i] = '\0';
	ifstream fin;
	fin.open("p_confidentials", ios::binary);
	fin.seekg(0, ios::beg);
	fin.read((char *)&obj, sizeof(obj));
	if (strcmp(obj.username, temp_un) == 0 && strcmp(obj.password, temp_pass) == 0)
	{
		cout << endl
			 << "\n\t\tLogin successful" << endl;
		cout << "\t\tLogging in . . . ." << endl;
		sleep(3);
		return 1;
	}
	else
	{
		cout << endl
			 << "\n\t\tLogin failed! Invalid username or password." << endl;
		cout << "\t\tPress any key to go back" << endl;
		getch();
		return 0;
	}
	fin.close();
}

void credentials ::forgot_pass()
{
	credentials obj;
	system("cls");
	int j = 0;
	cout << "\n\t\tEnter the pin(4 characters):";
	while (true)
	{
		char c = _getch();
		if (c == 13)
			break;
		p[j] = c;
		cout << '*';
		j++;
	}
	p[j] = '\0';
	ifstream fin;
	fin.open("pin", ios ::binary);
	fin.read((char *)&obj, sizeof(obj));
	if (strcmp(p, obj.pin) == 0)
	{
		cout << endl;
		signup();
	}
	else
	{
		cout << endl
			 << "\t\tWrong pin!!!!!" << endl;
	}
	cout << endl
		 << "\n\t\tPress any key to go back" << endl;
	getch();
	fin.close();
}
void menu_doc_info() // global function
{
	doctor obj;
	while (1)
	{
		system("cls");
		cout << "\t\t<<------- DOCTORS INFORMATION------->>" << endl;
		cout << "\n\t\ta. Add Doctor" << endl;
		cout << "\t\tb. Display All Doctors" << endl;
		cout << "\t\tc. Search Doctor" << endl;
		cout << "\t\td. Edit Doctor Details" << endl;
		cout << "\t\te. Delete Doctor" << endl;
		cout << "\t\tf. Delete All Doctors" << endl;
		cout << "\t\tg. Back" << endl;
		char choice;
		cout << "\n\t\tEnter your choice (a-g): ";
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
			cout << "\t\tInvalid Choice...." << endl;
			cout << "\t\tPlease Enter from a to g" << endl;
			break;
		}
		cout << "\n\t\t\tPress any key to go to menu" << endl;
		getch();
	}
}
void menu_appoint_check() // global function
{
	doctor obj;
	while (1)
	{
		system("cls");
		char choice;
		cout << "\t\t<<------MENU OF APPOINTMENT SERVICE------>>" << endl;
		cout << "\n\t\ta.Gynocology" << endl;
		cout << "\t\tb.Neurology" << endl;
		cout << "\t\tc.Radiology" << endl;
		cout << "\t\td.Cardiology" << endl;
		cout << "\t\te.Hysterology" << endl;
		cout << "\t\tf.ENT" << endl;
		cout << "\t\tg.Physiology" << endl;
		cout << "\t\th.Back" << endl;
		cout << "\n\t\tEnter the choice (a-h): ";
		cin >> choice;
		switch (choice)
		{
		case 'a':
			obj.gynocology();
			break;
		case 'b':
			obj.neurology();
			break;
		case 'c':
			obj.radiology();
			break;
		case 'd':
			obj.cardiology();
			break;
		case 'e':
			obj.hysterology();
			break;
		case 'f':
			obj.ent();
			break;
		case 'g':
			obj.physiology();
			break;
		case 'h':
			system("cls");
			return;
		default:
			system("cls");
			cout << "\t\tInvalid Choice" << endl;
			cout << "\t\tPlease Press from a to h" << endl;
			break;
		}
		cout << "\n\t\tPress any key to go back" << endl;
		getch();
	}
}
int main()
{

	credentials obj;
	ifstream fin;
	fin.open("p_confidentials", ios::binary);
	if (!fin.is_open())
	{
		system("cls");
		cout << "\t\t<<------Sign up------>>" << endl;
		obj.signup();
		obj.pi_n();
	}
	fin.close();
flag:
	int loggedin = 0;
	char ch;
	while (loggedin == 0)
	{
		system("cls");
		cout << "\n\t\ta.Login" << endl
			 << "\t\tb.Forgot password" << endl
			 << "\t\tc.Exit" << endl;
		cout << "\n\t\tEnter your choice(a-c):";
		cin >> ch;
		switch (ch)
		{
		case 'a':
		{
			loggedin = obj.login();
			break;
		case 'b':
			obj.forgot_pass();
			break;
		case 'c':
			exit(0);
		default:
			system("cls");
			cout << "\t\tInvalid choice!!!!!" << endl;
			cout << "\n\t\tPress any key to go to back" << endl;
			getch();
			break;
		}
		}
	}
	while (1)
	{
		patient obj1;
		system("cls");
		cout << "\t\t<<------MAIN MENU------>>" << endl;
		cout << "\n\t\ta.Appointment check" << endl
			 << "\t\tb.Appoint the doctor" << endl
			 << "\t\tc.Doctor Information" << endl
			 << "\t\td.Patient information" << endl
			 << "\t\te.Log out" << endl;
		char choice;
		cout << "\n\t\tEnter the choice (a-e):";
		cin >> choice;
		switch (choice)
		{
		case 'a':
			menu_appoint_check();
			break;
		case 'b':
			obj1.book_doc();
			cout << "\n\t\tPress any key to go back" << endl;
			getch();
			break;
		case 'c':
			menu_doc_info();
			break;
		case 'd':
			obj1.show_patient();
			break;
		case 'e':
			system("cls");
			exit(0);
		default:
			system("cls");
			cout << "\t\tInvalid Choice...." << endl;
			cout << "\t\tPlease Enter from a to d" << endl;
			cout << "\n\t\tPress any key to go to menu....." << endl;
			getch();
			break;
		}
	}
	return 0;
}
