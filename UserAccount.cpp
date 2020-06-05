#include "UserAccount.h"
#include <iostream>

#define REAL_NAME std::string
#define USERNAME std::string
#define PASSWORD std::string
#define AUTH_CODE int

#define TRUE 1
#define FALSE 0

#define UNDEFINED_STRING ""
#define UNDEFINED_INT 0

#define ERROR_C1 "ERROR: AUTH CODE INCORRECT."
#define ERROR_C2 "ERROR: INCORRECT DETAILS INPUTTED."

UserAccount::UserAccount(REAL_NAME passed_real_name, USERNAME passed_name, PASSWORD passed_pass,
                        AUTH_CODE code) {
    name = passed_name;
    password = passed_pass;
    real_name = passed_real_name;
    user_code = code;
}

USERNAME UserAccount::GetUsername() {
    return name;
}

PASSWORD UserAccount::GetPassword() {
    return password;
}

REAL_NAME UserAccount::GetRealName() {
    return real_name;
}

int UserAccount::ValidatePassword(AUTH_CODE code, PASSWORD pass) {
    if(pass == password && code == user_code)
        return TRUE;
    return FALSE;
}

int UserAccount::ValidateUsername(USERNAME user_name) {
    if (name == user_name)
        return TRUE;
    return FALSE;
}

invalid_details_error::invalid_details_error(const std::string& br_message) {
    message = br_message;
}
