#include<iostream>
#include<math.h>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<bits/stdc++.h>
#include "function_files.cpp"
using std::ios;
using std::cerr;
using namespace std;


int main(){
    User obj[5];

    cout<<"1. Registration"<<endl;
    cout<<"2. Login"<<endl;
    cout<<"3. Forget Password"<<endl;

    int choice;
    cout<<"Enter the choice: "<<endl;
    cin>>choice;

    switch(choice){
        
        case 1:{
            
            obj[0].user_id="xy10";
            obj[0].password=encrypt("khan345");
            obj[0].pin=encrypt("6789");
            obj[0].imei_no=encrypt("rtyu78");
            obj[0].location=23;
            obj[0].mobile_no=89341;
            obj[0].time=10;

            obj[1].user_id="abc12";
            obj[1].password=encrypt("khan123");
            obj[1].pin=encrypt("1234");
            obj[1].imei_no=encrypt("edf78");
            obj[1].location=29;
            obj[1].mobile_no=34513;
            obj[1].time=12;

            obj[2].user_id="fgh12";
            obj[2].password=encrypt("jad456");
            obj[2].pin=encrypt("8910");
            obj[2].imei_no=encrypt("klm99");
            obj[2].location=35;
            obj[2].mobile_no=10000;
            obj[2].time=54;

            obj[3].user_id="pqrs1";
            obj[3].password=encrypt("khan345");
            obj[3].pin=encrypt("0988");
            obj[3].imei_no=encrypt("yuzx89");
            obj[3].location=89;
            obj[3].mobile_no=45678;
            obj[3].time=67;

            obj[4].user_id="klmn89";
            obj[4].password=encrypt("sal456");
            obj[4].pin=encrypt("5613");
            obj[4].imei_no=encrypt("7845");
            obj[4].location=90;
            obj[4].mobile_no=87654;
            obj[4].time=95;
            
            LoginPage login_page_obj;
        }
        case 2:{

            obj[0].user_id="xy10";
            obj[0].password=encrypt("khan345");
            obj[0].pin=encrypt("6789");
            obj[0].imei_no=encrypt("rtyu78");
            obj[0].location=23;
            obj[0].mobile_no=89341;
            obj[0].time=10;

            obj[1].user_id="abc12";
            obj[1].password=encrypt("khan123");
            obj[1].pin=encrypt("1234");
            obj[1].imei_no=encrypt("edf78");
            obj[1].location=29;
            obj[1].mobile_no=34513;
            obj[1].time=12;

            obj[2].user_id="fgh12";
            obj[2].password=encrypt("jad456");
            obj[2].pin=encrypt("8910");
            obj[2].imei_no=encrypt("klm99");
            obj[2].location=35;
            obj[2].mobile_no=10000;
            obj[2].time=54;

            obj[3].user_id="pqrs1";
            obj[3].password=encrypt("khan345");
            obj[3].pin=encrypt("0988");
            obj[3].imei_no=encrypt("yuzx89");
            obj[3].location=89;
            obj[3].mobile_no=45678;
            obj[3].time=67;

            obj[4].user_id="klmn89";
            obj[4].password=encrypt("sal456");
            obj[4].pin=encrypt("5613");
            obj[4].imei_no=encrypt("7845");
            obj[4].location=90;
            obj[4].mobile_no=87654;
            obj[4].time=95;
            
            LoginPage login_page_obj;
            //cout<<login_page_obj.login(obj)<<endl;
            if(login_page_obj.login(obj)=="Successful"){
                cout<<endl;
                cout<<"Gone to Second Step Verification"<<endl;
                TwoStepVerification pin_obj;
                //pin_obj.correct_pin(obj);

                if(pin_obj.correct_pin(obj)=="Successful"){
                    cout<<endl;
                    cout<<"Go to Third Step Verification"<<endl;
                    ThirdStepVerification third_step_verification_obj;
                    third_step_verification_obj.correct_third_step(obj);
                }else{
                    cout<<"Wrong pin number"<<endl;

                }
            }
            else{
                cout<<"UnSuccessful"<<endl;
            }
            break;
        }

        case 3:{

            User obj[5];

            obj[0].user_id="xy10";
            obj[0].password=encrypt("khan345");
            obj[0].pin=encrypt("6789");
            obj[0].imei_no=encrypt("rtyu78");
            obj[0].location=23;
            obj[0].mobile_no=89341;
            obj[0].time=10;

            obj[1].user_id="abc12";
            obj[1].password=encrypt("khan123");
            obj[1].pin=encrypt("1234");
            obj[1].imei_no=encrypt("edf78");
            obj[1].location=29;
            obj[1].mobile_no=34513;
            obj[1].time=12;

            obj[2].user_id="fgh12";
            obj[2].password=encrypt("jad456");
            obj[2].pin=encrypt("8910");
            obj[2].imei_no=encrypt("klm99");
            obj[2].location=35;
            obj[2].mobile_no=10000;
            obj[2].time=54;

            obj[3].user_id="pqrs1";
            obj[3].password=encrypt("khan345");
            obj[3].pin=encrypt("0988");
            obj[3].imei_no=encrypt("yuzx89");
            obj[3].location=89;
            obj[3].mobile_no=45678;
            obj[3].time=67;

            obj[4].user_id="klmn89";
            obj[4].password=encrypt("sal456");
            obj[4].pin=encrypt("5613");
            obj[4].imei_no=encrypt("7845");
            obj[4].location=90;
            obj[4].mobile_no=87654;
            obj[4].time=95;

            ForgetPassword forget_password_obj;
            forget_password_obj.forget(obj);
            //cout<<obj[0].pin<<endl;
            break;
        }
        default:
            cout<<"Enter the correct choice"<<endl;



    }


    cout<<endl;
    //cout<<obj[0].user_id<<endl;

    ofstream databaseFile("databaseRecord.txt",ios::out | ios::app);

    databaseFile<<obj[0].user_id<<" "<<obj[0].password<<" "<<obj[0].pin<<" "<<obj[0].imei_no<<" "<<obj[0].location<<" "<<obj[0].mobile_no<<" "<<obj[0].time<<endl;
    databaseFile<<obj[1].user_id<<" "<<obj[1].password<<" "<<obj[1].pin<<" "<<obj[1].imei_no<<" "<<obj[1].location<<" "<<obj[1].mobile_no<<" "<<obj[1].time<<endl;
    databaseFile<<obj[2].user_id<<" "<<obj[2].password<<" "<<obj[2].pin<<" "<<obj[2].imei_no<<" "<<obj[2].location<<" "<<obj[2].mobile_no<<" "<<obj[2].time<<endl;
    databaseFile<<obj[3].user_id<<" "<<obj[3].password<<" "<<obj[3].pin<<" "<<obj[3].imei_no<<" "<<obj[3].location<<" "<<obj[3].mobile_no<<" "<<obj[3].time<<endl;
    databaseFile<<obj[4].user_id<<" "<<obj[4].password<<" "<<obj[4].pin<<" "<<obj[4].imei_no<<" "<<obj[4].location<<" "<<obj[4].mobile_no<<" "<<obj[4].time<<endl;

    databaseFile.close();

    

    return 0;
}
