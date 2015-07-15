#include "courseinfo.h"

StudentInfo::StudentInfo(string fn, 
    string ln, 
    string maj, 
    int id, 
    string letterGrade)
{
    firstName = fn;
    lastName = ln;
    major = maj;
    studentId = id;
    this->letterGrade = letterGrade;
}

string StudentInfo::getFirstName()
{
    return firstName;
}
void StudentInfo::setFirstName(string fn)
{
    firstName = fn;
}

string StudentInfo::getLastName()
{
    return lastName;
}

void StudentInfo::setLastName(string ln)
{
    lastName = ln;
}

string StudentInfo::getMajor()
{
    return major;
}

void StudentInfo::setMajor(string maj)
{
    major = maj;    
}

int StudentInfo::getStudentId()
{
    return studentId;
}

void StudentInfo::setStudentId(int id)
{
    studentId = id;
}

string StudentInfo::getLetterGrade()
{
    return letterGrade;
}

void StudentInfo::setLetterGrade(string lg)
{
    letterGrade = lg;
}

string StudentInfo::toString()
{
    return lastName + ", " + firstName;
}


string CourseInfo::getDepartment()
{
    return department;
}

void CourseInfo::setDepartment(string dept)
{
    department = dept;
}

string CourseInfo::getCourseName()
{
    return courseName;
}

void CourseInfo::setCourseName(string courseNm)
{
    courseName = courseNm;
}

int CourseInfo::getCatalogNum()
{
    return catalogNum;
}

void CourseInfo::setCatalogNum(int cNum)
{
    catalogNum = cNum;
}

void CourseInfo::addStudent(StudentInfo studentInfo)
{
    if(numberOfStudents < MAX_STUDENTS)
        students[numberOfStudents++] = studentInfo;
    else
    {
        // throw an exception
        throw CourseInfoException("Max number of students reached");
    }
}

StudentInfo CourseInfo::getStudent(unsigned short student)
{
    if(student < numberOfStudents)
        return students[student];
    else
    {
        // throw exception
        throw CourseInfoException("Invalid student requested");
    }
}