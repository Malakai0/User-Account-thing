#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include "UserAccount.h"

#pragma warning(disable : 4996)

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

std::string FormatString(std::string orig, std::vector<std::string> args);
void OutputAccountInformation(UserAccount acc);
UserAccount RequestLogin();

std::vector<UserAccount> Database = {
    UserAccount("John", "JohnHackerman123", "iamcoolxd123", 6353)
};

int main()
{

    try {
        UserAccount Account = RequestLogin();
        std::string WelcomeString = FormatString(
            "Logged in successfully! Welcome %s!", { Account.GetRealName() });
        std::cout << WelcomeString << std::endl;
        OutputAccountInformation(Account);
    }
    catch (invalid_details_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

std::string FormatString(std::string orig, std::vector<std::string> args) {
    boost::format a = boost::format(orig);
    for (const auto& arg : args) {
        a = a % arg;
    }
    return a.str();
}

void OutputAccountInformation(UserAccount Account) {
    std::map<std::string, std::string> AccountInfo = {
        { "REAL_NAME", Account.GetRealName() },
        { "USERNAME", Account.GetUsername() },
        { "PASSWORD", Account.GetPassword() }
    };

    std::string format_base = "%s | USERNAME: %s, PASSWORD: %s";
    std::string formatted = FormatString(format_base,
        { AccountInfo["REAL_NAME"], AccountInfo["USERNAME"], AccountInfo["PASSWORD"] });

    std::cout << formatted << std::endl;
}

UserAccount RequestLogin() {

    AUTH_CODE input_code;
    USERNAME input_username;
    PASSWORD input_password;
    std::string input_code_string;

    std::cout << "Please input your user account code: ";
    std::cin >> input_code_string;

    try {
        input_code = boost::lexical_cast<int>(input_code_string);
    }
    catch (boost::bad_lexical_cast) {
        std::cout << "Invalid input code inputted!" << std::endl;
        throw invalid_details_error(ERROR_C2);
    }
    
    std::cout << "Please input your username: ";
    std::cin >> input_username;

    std::cout << "Please input your password: ";
    std::cin >> input_password;

    for (UserAccount user : Database) {
        int usernameMatch = user.ValidateUsername(input_username);
        int passwordMatch = user.ValidatePassword(input_code,
                             input_password);
        if (usernameMatch == TRUE && passwordMatch == TRUE) {
            return user;
        }
    }

    throw invalid_details_error(ERROR_C2);
}
