create table Exam (
    ExamId number,
    CourseId number, 
    ExamDate Date,
    ExamType varchar2(40)
);
create table Exam_Result(
    ResultID number, 
    StudentID number,
    ExamID number,
    Score number
);

alter table student add constraint pk primarykey (StudentID);
CREATE TABLE STUDENT (
    StudentID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    BirthDate DATE,
    Address VARCHAR(100),
    Email VARCHAR(100),
    Year INT
);

CREATE TABLE COURSE (
    CourseID INT PRIMARY KEY,
    CourseName VARCHAR(100),
    CourseCoef INT,
    CourseCredits INT
);

CREATE TABLE TEACHER (
    TeacherID INT PRIMARY KEY,
    CIV VARCHAR(10),
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Salary REAL,
    Email VARCHAR(100),
    Grade VARCHAR(20)
);

CREATE TABLE ENROLLMENT (
    StudentID INT,
    CourseID INT,
    EnrollmentDate DATE,
    FinalMark REAL,
    PRIMARY KEY (StudentID, CourseID),
    FOREIGN KEY (StudentID) REFERENCES STUDENT(StudentID),
    FOREIGN KEY (CourseID) REFERENCES COURSE(CourseID)
);

CREATE TABLE COURSE_ASSIGNMENT (
    CourseID INT,
    TeacherID INT,
    StartDate DATE,
    EndDate DATE,
    PRIMARY KEY (CourseID, TeacherID),
    FOREIGN KEY (CourseID) REFERENCES COURSE(CourseID),
    FOREIGN KEY (TeacherID) REFERENCES TEACHER(TeacherID)
);



CREATE TABLE EXAM_RESULT (
    ResultID INT PRIMARY KEY,
    StudentID INT,
    ExamID INT,
    Score REAL,
    FOREIGN KEY (StudentID) REFERENCES STUDENT(StudentID),
    FOREIGN KEY (ExamID) REFERENCES EXAM(ExamID)
);














//lab 2
ALTER TABLE TEACHER ADD HireDate DATE;
ALTER TABLE TEACHER MODIFY Grade VARCHAR(20) NOT NULL;
ALTER TABLE TEACHER MODIFY Salary number NOT NULL;
ALTER TABLE TEACHER MODIFY FirstName VARCHAR(100);
ALTER TABLE TEACHER MODIFY FirstName VARCHAR(30);
ALTER TABLE TEACHER DROP COLUMN HireDate;
desc Teacher;
ALTER TABLE STUDENT RENAME COLUMN Address TO StudentAddress;
ALTER TABLE COURSE_ASSIGNMENT ADD CONSTRAINT check_dates CHECK (StartDate < EndDate);
//week 2 part 2



