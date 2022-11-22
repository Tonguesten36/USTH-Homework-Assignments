CREATE DATABASE Company;
USE Company;


CREATE TABLE Employee(
	fname VARCHAR(50),
    lname VARCHAR(50),
    ssn INTEGER,
    super_ssn INTEGER,
    PRIMARY KEY (ssn),
    FOREIGN KEY (super_ssn) REFERENCES Employee(ssn),
    bdate DATE,
    address VARCHAR(50),
    salary INTEGER,
    sex CHAR(1),
    Dno INTEGER,
    FOREIGN KEY(Dno) REFERENCES Department(Dnumber)
);
CREATE TABLE Department(
	Dname VARCHAR(50),
    Dnumber INTEGER,
    Mgr_ssn INTEGER,
    Mgr_start_date DATE,
    FOREIGN KEY(Mgr_ssn) REFERENCES Employee(ssn),
    PRIMARY KEY(Dnumber)
);
CREATE TABLE Dept_location (
    Dnumber INTEGER,
    Dlocation VARCHAR(50),
    PRIMARY KEY (Dlocation),
    UNIQUE(Dnumber),
    FOREIGN KEY(Dnumber) REFERENCES Department(Dnumber)
);
CREATE TABLE Project(
	Pname VARCHAR(50),
    Pnumber VARCHAR(50),
    Plocation VARCHAR(50),
    Dnum INTEGER,
    FOREIGN KEY(Dnum) REFERENCES Department(Dnumber),
    PRIMARY KEY(Pnumber)
);
CREATE TABLE Works_On(
	Essn INTEGER,
    Pno INTEGER,
    Hours INTEGER,
    PRIMARY KEY(Pno),
    UNIQUE(Essn),
    FOREIGN KEY(Essn) REFERENCES Employee(ssn),
    FOREIGN KEY(Pno) REFERENCES Project(Pnumber)
);
CREATE TABLE Dependent(
	Essn INTEGER,
    Department_name VARCHAR(50),
    Sex CHAR(1),
    Bdate DATE,
    Relationship VARCHAR(20),
    UNIQUE(Department_name),
    PRIMARY KEY(Essn),
    FOREIGN KEY(Essn) REFERENCES Employee(ssn)
);


-- Add a new column Partner_ssn into the Employee table
ALTER TABLE Employee
ADD Partner_ssn INTEGER, ADD CONSTRAINT FOREIGN KEY(Partner_ssn) REFERENCES Dependent(Essn);


-- Add some new columns to the tables
ALTER TABLE Department
ADD Personnel INTEGER;

ALTER TABLE Project
ADD Progress INTEGER;


-- Delete all created tables
DROP TABLE Employee, Dependent, Dept_location, Project, Department, Works_on;