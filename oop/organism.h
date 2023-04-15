#include <string>

using std::string;

class organism {
public:
    virtual string get_description() const {
        return "some organism";
    };
};
