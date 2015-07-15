/** 
 * File: courseinfo.h
 * Author: Nathan Tenney
 * This file contains the class definitions for StudentInfo, as well as CourseInfo.
 * It also contains the definition for the CourseInfoException class, which is used
 * to signal an issue has ocurred in the use of the CourseInfo class. CourseInfo is a
 * class that describes objects that may be used to manage a university course. It 
 * consists of information about the course, as well as a roster of students. 
 * StudentInfo is a class that describes an object that may be used to hold the
 * information for a single student in a university course.
 */
#ifndef _COURSEINF_H_
#define _COURSEINF_H_

#include <string>
#include <iostream>

using namespace std;

const int MAX_STUDENTS = 30;

/**
 * CourseInfoException is an exception handling class. It takes as a string a reson
 * for the excpetion that may be used when later handling the exception.
 */
class CourseInfoException{
private:
    string reason;
public:
    /**
     * CourseInfoException constructor.
     *
     * @param reason - the reason for the exception
     */
    CourseInfoException(string reason)
    {
        this->reason = reason;
    }

    /**
     * Accessor function for the reason member
     *
     * @return the reason string.
     */
    string getReason(){
        return reason;
    }
};

/**
 * Class to describe objects that contain information needed to identify a student
 * who is taking a university course.
 */
class StudentInfo
{
private:
    string firstName;
    string lastName;
    int studentId;
    string major;
    string letterGrade;

public:
    /**
     * Default constructor for a StudentInfo object. Creates a blank object
     */ 
    StudentInfo()
    {
        firstName = "";
        lastName = "";
        major = "";
        studentId = 0;
        letterGrade = "";
    }

    /**
     * Constructor for a StudentInfo object. Creates an object filled in with
     * with the given paramaters.
     *
     * @param fn - the first name of the student
     * @param ln - the last name of the student
     * @param maj - the major of the student
     * @param id - the student ID of the student
     * @param letterGrade - the letter grade given to the student
     */ 
    StudentInfo(string fn, string ln, string maj, int id, string letterGrade);

    /**
     * @return the first name of the student
     */
    string getFirstName();

    /**
     * @param fn - The first name to use for this student
     */
    void setFirstName(string fn);

    /**
     * @return the last name of the student
     */
    string getLastName();

    /**
     * @param - The last name to use for this student
     */
    void setLastName(string);

    /**
     * @return the major of the student
     */
    string getMajor();

    /**
     * @param - The major to use for this student
     */
    void setMajor(string);

    /**
     * @return the student ID of the student
     */
    int getStudentId();

    /**
     * @param - The student ID to use for this student
     */
    void setStudentId(int);

    /**
     * @return the letter grade of the student
     */
    string getLetterGrade();

    /**
     * @param - The letter grade to use for this student
     */
    void setLetterGrade(string);

    /**
     * @return a string represntation of the student object
     */
    string toString();
};

class CourseInfo
{
private:
    string department;
    string courseName;
    int catalogNum;

    StudentInfo *students;
    int numberOfStudents;

public:
    CourseInfo()
    {
        cout << "CourseInfo default constructor" << endl;   
        department = "";
        courseName = "";
        catalogNum = 0;

        students  = new StudentInfo[MAX_STUDENTS];
        numberOfStudents = 0;
    }

    CourseInfo(string dept, string courseNm, int cNum)
    {
        department = dept;
        courseName = courseNm;
        catalogNum = cNum;

        students  = new StudentInfo[MAX_STUDENTS];
        numberOfStudents = 0;
    }

    ~CourseInfo()
    {
        cout << "Destructor called" << endl;
        delete[] students;
    }

    string getDepartment();
    void setDepartment(string dept);

    string getCourseName();
    void setCourseName(string courseNm);

    int getCatalogNum();
    void setCatalogNum(int cNum);

    void addStudent(StudentInfo);
    StudentInfo getStudent(unsigned short);


};

#endif