#include "courseinfo.h"
#include "courseinfo.h"

int main()
{
    CourseInfo cinfo;

    cout << "Course Name: " + cinfo.getCourseName() << endl;

    StudentInfo student("John", "Doe", "CptS", 12345, "A");

    try{
		cinfo.addStudent(student);

        StudentInfo newStudent = cinfo.getStudent(0);

        cout << "Put in " << student.toString() << endl;
        cout << "Got out " << newStudent.toString() << endl;

        StudentInfo student2 = cinfo.getStudent(10);
    }
    catch(CourseInfoException ex){
        cout << ex.getReason() << endl;
        return -1;
    }

    cout << "After the catch block" << endl;

    return 0;
}