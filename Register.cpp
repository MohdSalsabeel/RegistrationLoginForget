#include "Register.h"
#include<iostream>
#include<regex>
#include<fstream>
#include <windows.h>
#include "encrypted.h"

using namespace std;

bool specialCharacter(string str){
    for(int i=0;i<str.length();i++)
    {
        if ((str[i]>=48 && str[i]<=57)||
            (str[i]>=65 && str[i]<=90)||
            (str[i]>=97 && str[i]<=122))
            {
            continue;
            }
        else
        {

        return true;

        }
    }
    return false;
}

bool Email_check(string email)
{
     const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email,pattern);
}

bool containsOnlyLetters(string const &str) {
    return regex_match(str, regex("^[A-Za-z]+$"));
}



bool isValid(string s)
{
    const regex pattern("(0|91)?[7-9][0-9]{9}");
    if(regex_match(s, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Register::RegisterPage(){

    User obj;

    loop:

            fstream database_file;
            database_file.open("databaseRecordtest.txt",ios::out | ios::app | ios::in);

            if(database_file.is_open())
            {

            //top_user_name:

            cout<<"Enter the user name:"<<endl;
            //cin.ignore();
            /*
            getline(cin,obj.user_name);
            cout<<endl;
            for(int i=0;i<obj.user_name.size();i++){
                if(obj.user_name[i]==' '){
                    goto loop;
                }
            }
            */
            cin>>obj.user_name;

            cin.ignore(numeric_limits<streamsize>::max(),'\n');



            //string s_user=obj.user_name;
            /*
            for(int i=0;i<s_user.size();++i){
                if(s_user[i]==' '){
                    break;
                }
            }
            */

            if(containsOnlyLetters(obj.user_name)){
                goto user_name_bottom_loop;
            }
            else{
                cout<<"Enter valid user name"<<endl;
                goto loop;
            }

            cout<<obj.user_name<<endl;

            user_name_bottom_loop:

            // Here we are extracting three word from user name
            string three_user_word;
            for(int i=0;i<3;i++){
                three_user_word+=obj.user_name[i];
            }


            mobile_loop:
            string str;
            cout<<"Enter the mobile number"<<endl;

            cin>>obj.mobile_no_int;

            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            //bottom_mobile:

            // string str;
            str=to_string(obj.mobile_no_int);



            //string s=to_string(number);
            char YesNo;
            bool value=false;
            if(isValid(str))
            {
                goto bottom_mobile_loop;
            }
            else
            {
                cout<<"Please write correct mobile number"<<endl;
                goto mobile_loop;
            }


            bottom_mobile_loop:

            database_file.close();
            database_file.open("databaseRecordtest.txt",ios::in);
            while(database_file>>user_name1>>mobile_no1>>user_id1>>email_id1>>password1>>pin1>>imei_no1>>location1>>time1){
                if(encrypt(str)==mobile_no1){
                    cout<<"Mobile number must be different"<<endl;
                    goto mobile_loop;  // It will goto sign up page
                    break;
                }
            }


            // Here we are extracting three word from mobile number
            string three_mobile_word;
            for(int i=0;i<3;i++){
                three_mobile_word+=str[i];
            }

            // We are generating unique user id
            string unique_user_id=three_user_word+three_mobile_word;
            database_file.close();
            database_file.open("databaseRecordtest.txt",ios::in);
            while(database_file>>user_name1>>mobile_no1>>user_id1>>email_id1>>password1>>pin1>>imei_no1>>location1>>time1){
                if(encrypt(unique_user_id)==user_id1){
                    cout<<"user id must be different"<<endl;
                    goto loop;  // It will goto sign up page
                    break;
                }
            }

            cout<<"User id is generated: "<<endl;
            cout<<unique_user_id<<endl;

            email_id_loop:

            cout<<"Enter the email id:"<<endl;
            cin>>obj.email_id;

            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            if(Email_check(obj.email_id)){
                goto email_id_bottom_loop;
            }
            else{
                cout<<"Enter valid email id"<<endl;
                goto email_id_loop;
            }

            email_id_bottom_loop:

            database_file.close();
            database_file.open("databaseRecordtest.txt",ios::in);
            while(database_file>>user_name1>>mobile_no1>>user_id1>>email_id1>>password1>>pin1>>imei_no1>>location1>>time1){
                if(encrypt(obj.email_id)==email_id1){
                    cout<<"Email id must be different"<<endl;
                    goto email_id_loop;  // It will goto sign up page
                    break;
                }
            }

            specialLoop:

            cout<<"Enter the password:"<<endl;
            cin>>obj.password;

            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            // Password must be greater than 8 digit
            if(obj.password.size()>=8 ){
                goto specialCharaterBottom;
            }
            else{
                cout<<"Password must be greater than 8 character"<<endl;
                goto specialLoop;
            }

            specialCharaterBottom:

            if(specialCharacter(obj.password)){
                goto bottom1;
            }
            else{
                cout<<"Please write strong password"<<endl;
                goto specialLoop;
            }



            bottom1:

            cout<<"Enter the pin:"<<endl;
            cin>>obj.pin;

            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            // Pin must be four digit

            if(obj.pin.size()==4){
                goto bottom2;
            }
            else{
                cout<<"Pin must be in 4 digit"<<endl;
                goto bottom1;
            }


            bottom2:

            cout<<"Enter the imei number"<<endl;
            cin>>obj.imei_no;

            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            if(obj.imei_no.size()<15){
                cout<<"Imei number must be greater than or equal to 15 character"<<endl;
                goto bottom2;
            }

            database_file.close();
            database_file.open("databaseRecordtest.txt",ios::in);
            while(database_file>>user_name1>>mobile_no1>>user_id1>>email_id1>>password1>>pin1>>imei_no1>>location1>>time1){
                if(encrypt(obj.imei_no)==imei_no1){
                    cout<<"Imei number must be different"<<endl;
                    goto bottom2;  // It will goto sign up page
                    break;
                }
            }



            cout<<"Enter the location"<<endl;
            cin>>obj.location;

            cin.ignore(numeric_limits<streamsize>::max(),'\n');

            cout<<"Enter the time"<<endl;
            cin>>obj.time;

            cin.ignore(numeric_limits<streamsize>::max(),'\n');


            database_file.close();

            //Here we are checking unique user id and mobile number and email id
            //If user wrote same id , mobile number and email id then go to registration form again , user must used different id,mobile number and email

            database_file.open("databaseRecordtest.txt",ios::in);
            while(database_file>>user_name1>>mobile_no1>>user_id1>>email_id1>>password1>>pin1>>imei_no1>>location1>>time1){
                // if user id present in database then it will goto sign up page
                if(encrypt(unique_user_id)==user_id1){
                    cout<<"Please write different name and mobile no"<<endl;
                    goto loop;  // It will goto sign up page
                    break;
                }
                // if same mobile present in database then it will goto sign up page , print message
                if(encrypt(str)==mobile_no1){
                    cout<<"Mobile number must be different"<<endl;
                    goto loop;  // It will goto sign up page
                    break;
                }
                if(encrypt(obj.email_id)==email_id1){
                    cout<<"Email id must be different"<<endl;
                    goto loop;   // It will goto sign up page
                    break;
                }
                if(encrypt(obj.imei_no)==imei_no1){
                    cout<<"imei must be different"<<endl;
                    goto loop;   // It will goto sign up page
                    break;
                }

            }
            database_file.close();

            // We put all input into database in encrypted form

            database_file.open("databaseRecordtest.txt",ios::out | ios::app);
            database_file<<encrypt(obj.user_name)<<" ";
            database_file<<encrypt(str)<<" ";
            database_file<<encrypt(three_user_word+three_mobile_word)<<" ";


            database_file<<encrypt(obj.email_id)<<" ";
            database_file<<encrypt(obj.password)<<" ";
            database_file<<encrypt(obj.pin)<<" ";
            database_file<<encrypt(obj.imei_no)<<" ";
            database_file<<encrypt(obj.location)<<" ";
            database_file<<encrypt(obj.time)<<" ";
            database_file<<endl;

            // cout<<"Successfully Register"<<endl;

            database_file.close();

            return "Successful";
            }


        return "False";
            //}

}
