#include <iostream>
#include <string>
#include <fstream>

using i64 = long long;

int main () {

    std::string me;
    std::ifstream me_out ("dict4.out");
    me_out >> me;
    me_out.close ();

    std::string ans;
    std::ifstream ans_out ("dict4.ans");
    ans_out >> ans;
    ans_out.close ();

    if (me == ans) { std::cout << "AC!" << "\n"; }
    else { std::cout << "呜呜呜" << "\n"; }

    return 0;
}