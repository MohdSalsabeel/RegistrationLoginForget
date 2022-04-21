//#include<iostream>
#include<string>
//using namespace std;
#include "classes_file.h"


std::string encrypt(std::string input)
{
    std::string result = "";
    int offset=9;
    for (int i = 0; i < input.length(); ++i)
    {
        // For capital letters
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            result += (char) (input[i] - 'A' + offset) % ('Z' - 'A') + 'A';
            continue;
        }

        // For non-capital
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            result += (char) (input[i] - 'a' + offset) % ('z' - 'a') + 'a';
            continue;
        }

        if (input[i] >= '0' && input[i] <= '9')
        {
            char ch = (input[i] - 2 + offset) -20;
            //result += (input[i] - 2 + offset) % 9;
            result += ch;
            continue;
        }

        // For others
        result += input[i];
    }

    return result;
}


std::string LoginPage::login(User *lobj){
        std::string login_user_id;
        std::string login_password;
        int current_time;
        
        std::cout<<"Enter login user id: "<<std::endl;
        std::cin>>login_user_id;
        std::cout<<"Enter login password: "<<std::endl;
        std::cin>>login_password;
        std::cout<<"Enter the current time: "<<std::endl;
        std::cin>>current_time;
        
        for(int i=0;i<5;i++){
            if(login_user_id==lobj[i].user_id && encrypt(login_password)==lobj[i].password ){
                lobj[i].time=current_time;
                return "Successful";
                //break;
                
            }
            
        }
}        


void ForgetPassword::forget(User *fobj){
        std::string pins;
        int times;
        std::cout<<"Enter the pin "<<std::endl;
        std::cin>>pins;
        std::cout<<"Enter the last time "<<std::endl;
        std::cin>>times;

        for(int i=0;i<5;i++){
            if(encrypt(pins)==fobj[i].pin && times==fobj[i].time){
                std::string new_pin;
                std::cout<<"Enter new pin"<<std::endl;
                std::cin>>new_pin;
                fobj[i].pin=new_pin;
                std::cout<<"Successfully reset password "<<std::endl;
                break;
            }
        }
};


std::string TwoStepVerification::correct_pin(User *pobj){
        std::string pin_number;
        std::cout<<"Enter pin number in two minutes: "<<std::endl;
        std::cin>>pin_number;

        for(int i=0;i<5;i++){
            if(encrypt(pin_number)==pobj[i].pin){
                return "Successful";
                //break;
                
            }
            
        }
        
}




void ThirdStepVerification::correct_third_step(User *thirdverifyobj){
        std::string verify_imei_number;
        //int verify_current_location;
        int verify_current_location;
        int verify_previous_location;
        int verify_mobile_no;
        std::cout<<"Enter imei number for verification: "<<std::endl;
        //std::cin>>verify_imei_number;
        std::cin>>verify_imei_number;

        std::cout<<"Enter current location: "<<std::endl;
        std::cin>>verify_current_location;

        std::cout<<"Enter previous location where you have login last time"<<std::endl;
        std::cin>>verify_previous_location;

        std::cout<<"Enter mobile number: "<<std::endl;
        std::cin>>verify_mobile_no;

        for(int i=0;i<5;i++){
            if(encrypt(verify_imei_number)==thirdverifyobj[i].imei_no && verify_previous_location==thirdverifyobj[i].location && verify_mobile_no==thirdverifyobj[i].mobile_no){
                thirdverifyobj[i].location=verify_current_location;

                char current_location_character=(char)verify_current_location;
                char previous_location_character=(char)verify_previous_location;
                char mobile_number_character=(char)verify_mobile_no;

                //std::string token;
                std::string token=verify_imei_number+current_location_character+previous_location_character+mobile_number_character;
                std::cout<<"Token is generated "<<std::endl;
                std::cout<<token<<std::endl;
                std::cout<<std::endl;
                std::cout<<"Write same token character: "<<std::endl;
                //cout<<"Enter token input: "<<endl;
                std::string token_character;
                std::cin>>token_character;
                if(token==token_character){
                    std::cout<<"Successful third step"<<std::endl;
                    break;
                }else{
                    std::cout<<"Wrong token number"<<std::endl;
                    break;
                }

            }
            
        }
        
}


