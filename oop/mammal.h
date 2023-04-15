#include "animal.h"

class mammal: public animal {
    std::string fur_color;
public:
    mammal(std::string fur_color_, std::string gender_, unsigned int age_)
    : animal(gender_,age_), fur_color{fur_color_} {}

    std::string get_fur_color() const {
        return fur_color;
    }
};