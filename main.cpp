#include <iostream>
#include <string>
#include <utility>

using namespace std;

class BigNumber {
    string number;
public:
    explicit BigNumber(string number) : number(std::move(number)) {}

    [[nodiscard]] const string &getNumber() const {
        return number;
    }

    void setNumber(const string &num) {
        BigNumber::number = num;
    }

    bool operator==(const BigNumber &rhs) const {
        return number == rhs.number;
    }

    bool operator!=(const BigNumber &rhs) const {
        return !(rhs == *this);
    }

    bool operator<(const BigNumber &rhs) const {
        const string &num1 = number;
        const string &num2 = rhs.number;
        if (num1 == num2) {
            return false;
        }
        if (num1.size() < num2.size()) {
            return true;
        }
        else if (num1.size() > num2.size()) {
            return false;
        }
        else {
            for (int i = 0; i != num1.size(); ++i) {
                int n = num1[i] - num2[i];
                if (n < 0) {
                    return true;
                }
                else if (n > 0) {
                    return false;
                }
            }
        }

        return false;
    }

    bool operator>(const BigNumber &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const BigNumber &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const BigNumber &rhs) const {
        return !(*this < rhs);
    }

    friend ostream &operator<<(ostream &os, const BigNumber &num) {
        os << "num: " << num.number;
        return os;
    }
};

int main() {
    BigNumber num1("200");
    BigNumber num2("347");
    cout << (num1 < num2);
    return 0;
}
