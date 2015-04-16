Date::Date(int newYear, int newMonth, int newDay){
    this->year = newYear;
    this->month = newMonth;
    this->day = newDay;
}

int Date::getYear(){
    return this->year;
}

int Date::getMonth(){
    return this->month;
}

int Date::getDay(){
    return this->day;
}

void Date::setYear(int newYear){
    this->year = newYear;
}

void Date::setMonth(int newMonth){
    this->month = newMonth;
}

void Date::setDay(int newDay){
    this->day = newDay;
}

Person::Person(int id, int year, int month, int day){
    Date* obj = new Date(year, month, day);
    this->id = id;
    birthDate = obj;
    numberOfObjects++;
}

Person::~Person(){
    if(birthDate != NULL){
        delete(birthDate);
        birthDate = NULL;
    }
    numberOfObjects--;
}

int Person::getId(){
    return this->id;
}

Date* Person::getBirthDate(){
    return this->birthDate;
}

int Person::getNumberOfObjects(){
    return Person::numberOfObjects;
}                                 
