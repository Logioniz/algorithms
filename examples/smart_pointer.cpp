#include <stdio.h>
#include "vector.h"
#include "smart_pointer.h"
#include <string>

class Person {
public:
    std::string name;
    std::string surname;
    int age;
    Person(std::string n, std::string sn, int a) : name(n), surname(sn), age(a) {};

    ~Person() {
        printf("Удаляют %s\n", this->name.c_str());
    }
};

int main() {

    smart_pointer<Person> vasya(new Person("vasya", "pupkin", 10));
    smart_pointer<Person> kolya(new Person("kolya", "pupkin", 20));
    {
        smart_pointer<Person> tolya(new Person("tolya", "pupkin", 31));
        tolya->name = "tolyanishe";
        printf("%s\n", kolya->name.c_str());
        kolya = vasya;
        printf("%s\n", kolya->name.c_str());

        (*tolya).name = "tolya polya";
        printf("%s\n", (*tolya).name.c_str());
    }

    smart_pointer<vector<int> > arr(new vector<int>());
    arr->push_back(12);
    printf("%d\n", (*arr)[0]);

    // test on memory leak
    {
        for (int attempt = 0; attempt < 10; ++attempt) {
            smart_pointer<vector<smart_pointer<int> > > v(new vector<smart_pointer<int> >());
            for (int i = 0; i < 5000000; ++i) {
                v->push_back(smart_pointer<int>(new int(5)));
            }
            printf("Number of elements %d\n", v->len());
            printf("Check memory and press enter");
            getchar();
        }
    }

    return 0;
}
