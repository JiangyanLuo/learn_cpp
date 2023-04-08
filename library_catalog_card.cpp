#include <iostream>
#include <cstdint>
#include <cstring>

using std::cout;
using small_int = uint16_t; // for year

struct Card{
    const char* title;
    const char* author;
    const char* publisher;
    const char* subject;
    const char* ISBN;
    short int yearPublished {};
    short int yearAcquired {};
    unsigned int stock {};
};

int main() {
    //aggregate initialization, only works if there's no constructor, and must be in proper order, all fields should apply
    Card myBook{
        .title = "Gone With Wind",
        .author = "popo",
        .publisher = "la maison",
        .subject = "romantic",
        .ISBN = "ABC123",
        .yearPublished = 2022,
        .yearAcquired = 2023,
        .stock = 2,
    };

    cout << "The name of my book is: " << myBook.title << "\n";
    return 0;
}