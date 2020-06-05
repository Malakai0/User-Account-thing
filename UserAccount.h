#pragma once
#include <iostream>

#define REAL_NAME std::string
#define USERNAME std::string
#define PASSWORD std::string
#define AUTH_CODE int

#define UNDEFINED_STRING ""
#define UNDEFINED_INT 0

#define ERROR_C1 "ERROR: AUTH CODE INCORRECT."
#define ERROR_C2 "ERROR: INCORRECT DETAILS INPUTTED."

class UserAccount {
public:

    UserAccount(REAL_NAME passed_real_name, USERNAME passed_name,
                PASSWORD passed_pass, AUTH_CODE code);

    USERNAME GetUsername();
    PASSWORD GetPassword();
    REAL_NAME GetRealName();
    int ValidatePassword(AUTH_CODE code, PASSWORD pass);
    int ValidateUsername(USERNAME user_name);
private:
    REAL_NAME real_name = UNDEFINED_STRING;
    USERNAME name = UNDEFINED_STRING;
    PASSWORD password = UNDEFINED_STRING;
    AUTH_CODE user_code = UNDEFINED_INT;

};

class invalid_details_error : public std::exception {
public:
    explicit invalid_details_error(const std::string& br_message);
    const char* what() {
        return message.c_str();
    };
private:
    std::string message;
};
