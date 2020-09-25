class Student {
private:
	char studentSurname[30];
	char studentName[30];
	char studentPatronymic[30];
	char studentBirthday[15];
	char studentAdress[50];
	char studentPhone[30];
	char studentFac[30];
	int studentCourse;
public:
	Student();
	~Student();
	void showStudent();
	char* getStudentSurname();
	char* getStudentName();
	char* getStudentPatronymic();
	char* getStudentBirthday();
	char* getStudentAdress();
	char* getStudentPhone();
	char* getStudentFac();
	int getStudentCourse();
	void facultyList(Student list[], int n);
	void studentFacList(Student list[], int n);
	void studentCourseList(Student list[], int n);
	void studentBirthYear(Student list[], int n);
};
