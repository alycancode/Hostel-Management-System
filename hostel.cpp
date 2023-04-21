#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <regex>
using namespace std;

class User
{
 public:
 string first_name;
 //Comment
 string last_name;
 long int cnic;
 string address;
 string gender;
 string email;
 long long int contact_no;


};

class Student : public User
{
 public:
 string student_id;
 string date_of_birth;
 string father_name;
 long long int father_contact;
 string blood_group;

};

class MessManager 
{
 public:
 string mess_manager_id;
};

class Administrator : public Student, public MessManager
{
 public:
 string admin_id;
  void add_user()
  {
      int choice;
      cout << "Press\n 1 if adding administrator \n 2 if adding student \n 3 if adding mess Manager" << endl;
      cin >> choice;
      cin.ignore();
      cout<< "Enter first name: ";
      getline(cin,User::first_name);
      cout<< "Enter last name: ";
      getline(cin,User::last_name);
      cout << "Enter Cnic: ";
      cin >> User::cnic;
      cin.ignore();
      cout << "Enter Adress: ";
      getline(cin,User::address);
       //cout<< "Enter gender(Male / Female): ";
       //cin>> User::gender;
      do
      {
        cout << "Enter Gender(Male / Female): ";
        cin >> gender;
        if(gender != "Male" && gender != "male" && gender != "female" && gender != "Female")
        {
          cout << "Enter valid gender(Male / Female)";
        }
      }
      while(gender != "Male" && gender != "male" && gender != "female" && gender != "Female");
     bool isValidEmail = false;
     while (!isValidEmail) {
     cout << "Enter email (xyz23@gmail.com): ";
     cin.ignore();
     getline(cin,User::email);
     //cin >> User :: email;
     // check email format
     int atIndex = email.find('@');
     size_t dotIndex = email.find(".com");
     if (atIndex == string::npos || dotIndex == string::npos ||
        atIndex >= dotIndex || atIndex == 0 || dotIndex == email.length() - 1) 
     {
        isValidEmail = false;
        cout << "Invalid email format. Please enter a valid email." << endl;
     }
     else 
     {
        string name = email.substr(0, atIndex);
        string domain = email.substr(atIndex + 1, dotIndex - atIndex - 1);
        if (name.length() < 1 || domain != "gmail")
        {
            isValidEmail = false;
            cout << "Invalid email format. Please enter a valid email." << endl;
        } 
        else 
        {
            string number = name.substr(name.length() - 2);
            if (number[0] < '0' || number[0] > '9' || number[1] < '0' || number[1] > '9') 
            {
                isValidEmail = false;
                cout << "Invalid email format. Please enter a valid email." << endl;
            } else {
                isValidEmail = true;
            }
        }
     }
} 
      cout << "Enter contact number: ";
      cin >> User::contact_no;    
      

      ofstream outfile;
      outfile.open("user.txt",ios_base::app); //this line of code is creating an output file stream object
       regex admin_id_regex("A[0-9]{2}[K]-[0-9]{4}");
       regex student_id_regex("S[0-9]{2}[K]-[0-9]{4}");
       regex mess_manager_id_regex("M[0-9]{2}[K]-[0-9]{4}");

      switch (choice)
      {
      case 1:
        //cout << "Enter administrator id: ";
        //cin >> admin_id;
        do {
            cin.ignore();
            cout << "Enter ID in format A00K-0000: ";
            getline(cin,admin_id);
           }
   while (!regex_match(admin_id, admin_id_regex));
   cout << "Valid ID entered: " << admin_id << endl;

        outfile << first_name+' '+last_name+' '+to_string(cnic)+' '+address+' '+gender+' '+email+' '+to_string(contact_no)+' '+admin_id+'\n';
        break;

      case 2:
        //cout << "Enter student id: ";
      
   do {
    cin.ignore();
    cout << "Enter ID in format S00K-0000: ";
    getline(cin,Student::student_id);
      }
   while (!regex_match(Student::student_id, student_id_regex));

   cout << "Valid ID entered: " << Student::student_id << endl;

        //cin >> Student::student_id;
        // format 22K-4227
        cout << "Enter Date of birth (date/month/year): ";
        getline(cin,Student::date_of_birth);
        cout << "Enter father name: ";
        getline(cin,Student::father_name);
        cout << "Enter father's contact number: ";
        cin >> Student :: father_contact;
        cin.ignore();
        do
        {
          cout << "Enter blood group (A+ ,A- ,B+ ,B- ,AB+ ,AB- ,O+ ,O-): ";
          getline(cin,Student::blood_group);
          if(blood_group != "A+" &&  blood_group != "A-" && blood_group != "B+" && blood_group != "B-" && blood_group != "AB+" && blood_group != "AB-" && blood_group != "O+" && blood_group != "O-")
          cout << "Enter valid blood group\n";
        } 
        while (blood_group != "A+" &&  blood_group != "A-" && blood_group != "B+" && blood_group != "B-" && blood_group != "AB+" && blood_group != "AB-" && blood_group != "O+" && blood_group != "O-");
        
        outfile << first_name+' '+last_name+' '+to_string(cnic)+' '+address+' '+gender+' '+email+' '+to_string(contact_no)+' '+student_id+' '+date_of_birth+' '+father_name+' '+to_string(father_contact)+' '+blood_group+'\n'; // used for appending data 
        break;

      case 3:
        //cout << "Enter Mess Manager id: ";

        // cin >> mess_manager_id;
          do {
            cin.ignore();
            cout << "Enter ID in format M00K-0000: ";
            getline(cin, MessManager :: mess_manager_id);
           }
          while (!regex_match(mess_manager_id, mess_manager_id_regex));
          cout << "Valid ID entered: " << mess_manager_id << endl;

        outfile << first_name+' '+last_name+' '+to_string(cnic)+' '+address+' '+gender+' '+email+' '+to_string(contact_no)+' '+mess_manager_id+'\n';
        break;
          
      default:
        cin.ignore();
        cout << "Press valid number !";
        break;
      }
  }

  void update_user()
  {
   ifstream myfile("user.txt"); // open the file directly in the constructor
   string mystring;

   while(getline(myfile, mystring))
 {
  cout << mystring << endl; // output each line of the file
 }

  myfile.close(); // 

  }

};

int main()
{
    cout << "***************************************************" << endl;
    cout << "***                                             ***" << endl;
    cout << "***         Welcome to our Hostel !             ***"  << endl;
    cout << "***                                             ***" << endl;
    cout << "***************************************************" << endl;

  Administrator a;
  a.add_user();
  cout << "---Displaying---" << endl;
 // a.update_user();

  return 0;
}
