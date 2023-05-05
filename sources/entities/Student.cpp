#include "entities/Student.h"

Student::Student(const string &name, Evaluation learningDesirement, int cheatedWorksAmount) : name(name),
                                                                                              learningDesirement(
                                                                                                      learningDesirement),
                                                                                              cheatedWorksAmount(
                                                                                                      cheatedWorksAmount) {}

Student::Student() {
    string allNames[] = {"Richard", "Erlich", "Jared",
                         "Dinesh", "Gilfoyle", "Monica",
                         "Gavin", "Mia", "Russ"};

    this->name = allNames[rand() % 9];
    this->learningDesirement = Evaluation(1 + rand() % 5);
    this->cheatedWorksAmount = rand() % 1'000'000;
}

const string &Student::getName() const {
    return name;
}

void Student::setName(const string &name) {
    Student::name = name;
}

Evaluation Student::getLearningDesirement() const {
    return learningDesirement;
}

void Student::setLearningDesirement(Evaluation learningDesirement) {
    Student::learningDesirement = learningDesirement;
}

int Student::getCheatedWorksAmount() const {
    return cheatedWorksAmount;
}

void Student::setCheatedWorksAmount(int cheatedWorksAmount) {
    Student::cheatedWorksAmount = cheatedWorksAmount;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << "name: " << student.name << " learningDesirement: " << student.learningDesirement << " cheatedWorksAmount: "
       << student.cheatedWorksAmount;
    return os;
}

bool Student::operator==(const Student &rhs) const {
    return cheatedWorksAmount == rhs.cheatedWorksAmount;
}

bool Student::operator!=(const Student &rhs) const {
    return !(rhs == *this);
}

bool Student::operator<(const Student &rhs) const {
    return cheatedWorksAmount < rhs.cheatedWorksAmount;
}

bool Student::operator>(const Student &rhs) const {
    return rhs < *this;
}

bool Student::operator<=(const Student &rhs) const {
    return !(rhs < *this);
}

bool Student::operator>=(const Student &rhs) const {
    return !(*this < rhs);
}
