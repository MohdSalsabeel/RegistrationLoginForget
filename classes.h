#include<string>
class User
{
   public:
    std::string user_id;
    std::string password;
    std::string pin;
    std::string imei_no;
    int location;
    int mobile_no;
    int time;

};


class LoginPage : public User
{
    public:
    std::string login(User *lobj);
};

class ForgetPassword : public User
{
    public:
    void forget(User *fobj);
};


class TwoStepVerification : public User
{
    std::string pin_number;
public:
    std::string correct_pin(User *pobj);
};


class ThirdStepVerification:public User
{
    public:
    std::string verify_imei_number;
    int verify_current_location;
    int verify_previous_location;
    int verify_mobile_no;
    ThirdStepVerification(){}
public:
    void correct_third_step(User *thirdverifyobj);
};
