#ifndef LAB4_STUDENT_H
#define LAB4_STUDENT_H

#include <string>
#include <ostream>

#include "../enums/Evaluation.h"

using namespace std;

struct Student {
private:
    string name;
    Evaluation learningDesirement;
    int cheatedWorksAmount;

public:
    Student();

    Student(const string &name, Evaluation learningDesirement, int cheatedWorksAmount);

    const string &getName() const;

    void setName(const string &name);

    Evaluation getLearningDesirement() const;

    void setLearningDesirement(Evaluation learningDesirement);

    int getCheatedWorksAmount() const;

    void setCheatedWorksAmount(int cheatedWorksAmount);

    bool operator==(const Student &rhs) const;

    bool operator!=(const Student &rhs) const;

    bool operator<(const Student &rhs) const;

    bool operator>(const Student &rhs) const;

    bool operator<=(const Student &rhs) const;

    bool operator>=(const Student &rhs) const;

    friend ostream &operator<<(ostream &os, const Student &student);
};


#endif //LAB4_STUDENT_H
