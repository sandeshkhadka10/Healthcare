#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <unistd.h>
using namespace std;
class doctor
{
    protected:
	char doc_name[50];
	int license_no;
	char spec[30];
	char status[30];
	int temp_license_no;
	public:
	void show(doctor &obj);
	void check_found(int &found);
	void AddDoctor();
	void DisplayAllDoctors();
	void DeleteDoctor();
	void DeleteAllDoctor();
	void EditDoctorsDetails();
	void SearchDoctor();
	void anesthesiology();
	void gynocology();
	void neurology();
	void radiology();
	void cardiology();
	void hysterology();
	void physiology();
	void ent();
};
	void  doctor::show(doctor &obj)
	{
		cout << "\n\t\tName: " << obj.doc_name << endl;
		cout << "\t\tSpeciality: " << obj.spec << endl;
		cout << "\t\tLicense no: " << obj.license_no << endl;
		cout << "\t\t______________________________" << endl;
	}
	void doctor::check_found(int &found)
	{
		if(found==0)
		{
			cout<<"\n\t\tNo doctor found!!!!!"<<endl;
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
	ofstream fout;
	fout.open("doctordata", ios::binary | ios::app);
	fout.write((char *)&obj, sizeof(obj));
	cout<<"\n\t\tDetails added successfully"<<endl;
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
	cout << "\t\t<<------Delete Doctor Details------>> "<< endl;
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
    check_found(found);
}
void doctor::anesthesiology()
{
	system("cls");
	cout << "\t\t<<------Anesthesiology------>>" << endl;
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
    check_found(found);
	fin.close();
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
		if (strcmp(obj.spec, "physiology") == 0)
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
		if (strcmp(obj.spec, "gynocology") == 0)
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
		if (strcmp(obj.spec, "neurology") == 0)
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
		if (strcmp(obj.spec, "radiology") == 0)
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

		if (strcmp(obj.spec, "cardiology") == 0)
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
		if (strcmp(obj.spec, "hysterology") == 0)
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
		if (strcmp(obj.spec, "ent") == 0)
		{
			found = 1;
			show(obj);
		}
	}
    check_found(found);
	fin.close();
}

class credentials {
	private:
		char username[50];
		char password[50];
		char pin[5];
		char p[5];
		char temp_un[50];
		char temp_pass[50];
		
		public:
			void signup();
			void pi_n();
			int login();
			void forgot_pass();
			

};

void credentials ::signup() {
				credentials obj;
				cout<<"\n\t\tEnter new username: ";
				cin>>obj.username;
				int i=0;
				cout<< "\t\tEnter new password: ";
				while(true) {
					char  ch = _getch();
					if(ch==13)
						break;
					obj.password[i] = ch;
					cout<< '*';
					i++;
				}
				obj.password[i] = '\0';
				ofstream fout;
				fout.open("p_confidentials", ios::trunc|ios::binary);
				fout.write((char*)&obj,sizeof(obj));
				fout.close();
}
void credentials :: pi_n() {
	credentials obj;
	int j = 0;
	cout<<"\n\t\tEnter pin(used while doing forget password/4 character): ";
		while (true) {
			char c = _getch();
			if(c==13) {
				break;
			}
			obj.pin[j] = c;
			cout<<"*";
			j++;
		}
		
		obj.pin[j] = '\0';
		ofstream fout1;
		fout1.open("pin", ios::binary);
		fout1.write((char*)&obj, sizeof(obj));
		fout1.close();
	
}

int credentials :: login()
    {
    	credentials obj;
        system("cls");
        cout << "\t\t<<------Log In------>>" << endl;
        cout << "\n\t\tUsername: ";
        cin >> temp_un;
        int i = 0;
        cout << "\t\tPassword: ";
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
        fin.open("p_confidentials",ios::binary);
        fin.seekg(0, ios::beg);
		fin.read((char*)&obj,sizeof(obj));
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

    void credentials :: forgot_pass()
    {
    	credentials obj;
        system("cls");
        int j = 0;
        cout << "\n\t\tEnter the pin:";
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
        fin.open("pin", ios :: binary);
    	fin.read((char*)&obj,sizeof(obj));
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
		cout << "\n\t\ta. Add Doctor"<<endl;
		cout << "\t\tb. Display All Doctors"<<endl;
		cout << "\t\tc. Search Doctor"<<endl;
		cout << "\t\td. Edit Doctor Details"<<endl;
		cout << "\t\te. Delete Doctor"<<endl;
		cout << "\t\tf. Delete All Doctors"<<endl;
		cout << "\t\tg. Back"<<endl;
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
			cout << "\t\tInvalid Choice...."<<endl;
			cout << "\t\tPlease Enter from a to g"<<endl;
			break;
		}
		cout << "\n\t\t\tPress any key to go to menu"<<endl;
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
		cout << "\n\t\ta.Anesthesiology" << endl;
		cout << "\t\tb.Gynocology" << endl;
		cout << "\t\tc.Neurology" << endl;
		cout << "\t\td.Radiology" << endl;
		cout << "\t\te.Cardiology" << endl;
		cout << "\t\tf.Hysterology" << endl;
		cout << "\t\tg.ENT" << endl;
		cout << "\t\th.Physiology" << endl;
		cout << "\t\ti.Back" << endl;
		cout << "\n\t\tEnter the choice (a-i): ";
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
			cout << "\t\tInvalid Choice" << endl;
			cout << "\t\tPlease Press from a to i" << endl;
			break;
		}
		cout << "\n\t\tPress any key to go back" << endl;
		getch();
	}
}
void appoint_doc()//global function
{
	menu_appoint_check();
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
            cout<< "\n\t\tPress any key to go to back" << endl;
            getch();
            break;
        }
        }
    }
	while (1)
	{
		system("cls");
		cout << "\t\t<<------MAIN MENU------>>" << endl;
		cout << "\n\t\ta.Appointment check" << endl
			 << "\t\tb.Appoint the doctor" << endl
			 << "\t\tc.Doctor Information" << endl
			 << "\t\td.Exit" << endl;
		char choice;
		cout << "\n\t\tEnter the choice (a-d):";
		cin >> choice;
		switch (choice)
		{
		case 'a':
			menu_appoint_check();
			break;
		case 'b':
			appoint_doc();
			break;
		case 'c':
			menu_doc_info();
			break;
		case 'd':
			system("cls");
			exit(0);
		default:
			system("cls");
			cout << "\t\tInvalid Choice...."<<endl;
			cout << "\t\tPlease Enter from a to d"<<endl;
			cout<<"\n\t\tPress any key to go to menu....."<<endl;
			getch();
			break;
		}
	}
	return 0;
}
