//
// Created by pavel on 26.03.19.
//

#include "TeamLeader.h"
#include "Tester.h"
#include "SeniorManager.h"
#include "Driver.h"
#include "Cleaner.h"

#include <fstream>
#include <vector>
#include <iostream>
#include "StreamTable.h"


using namespace std;

void make_a_information_table(vector <Employee* > employees, vector <string> positions)
{
    ofstream file("../data/out.txt");
    StreamTable st(file);
    st.AddCol(5);
    st.AddCol(25);
    st.AddCol(25);
    st.AddCol(8);

    st.MakeBorderExt(true);
    st.SetDelimRow(true, '-');
    st.SetDelimCol(true, '|');

    st << "ID" << "Name and Surname" << "Position" << "Salary";
    for (auto i(0); i < employees.size(); i++)
        st << employees[i]->getId() << employees[i]->getName() << positions[i] << employees[i]->getPayment();
}

int main()
{
    ifstream file("../data/employees.txt");
    vector<Employee*> employees;
    vector<string> positions;
    unsigned id, subord_num;
    int worktime;
    string name, surname, position;
    PROJECT project;
    double base, involvement;

    while(file >> id) {
        file >> name >> surname >> position;
        positions.push_back(position);
        if (position == "Tester")
        {
            file >> worktime >> base;
            file >> project.project_name >> project.budget >> involvement;
            employees.push_back(new Tester(id,name+" "+surname,worktime,base,project,involvement));
            employees[employees.size() - 1]->setPayment();
        }
        if(position=="Manager")
        {
            file >> project.project_name >> project.budget >> involvement;
            employees.push_back(new Manager(id, name + " " + surname, project,involvement));
            employees[employees.size() - 1]->setPayment();

        }
        if(position=="Programmer")
        {

            file >> worktime >> base >> project.project_name >> project.budget >> involvement;
            employees.push_back(new Tester(id,name+" "+surname,worktime,base, project ,involvement));
            employees[employees.size() - 1]->setPayment();

        }
        if(position=="Cleaner")
        {

            file >> worktime >> base;
            employees.push_back(new Cleaner(id,name+" "+surname,worktime,base));
            employees[employees.size() - 1]->setPayment();
        }
        if(position=="Driver")
        {

            file >> worktime >> base;
            employees.push_back(new Driver(id,name+" "+surname,worktime,base));
            employees[employees.size() - 1]->setPayment();
        }
        if(position=="SeniorManager")
        {

            file >> project.project_name >> project.budget >> involvement >> subord_num;
            employees.push_back(new SeniorManager(id, name+" "+ surname, project ,involvement,subord_num));
            employees[employees.size() - 1]->setPayment();
        }
        if(position=="ProjectManager")
        {

            file >> project.project_name >> project.budget >> involvement >> subord_num;
            employees.push_back(new ProjectManager(id,name + " " + surname, project,involvement, subord_num));
            employees[employees.size() - 1]->setPayment();

        }
        if(position=="TeamLeader")
        {


            file >> worktime >> base >> project.project_name >> project.budget >> involvement >> subord_num;
            employees.push_back(new TeamLeader(id,name+" "+surname,worktime,base, project, involvement, subord_num));
            employees[employees.size() - 1]->setPayment();

        }
    }
    make_a_information_table(employees, positions);

    return 0;
}
