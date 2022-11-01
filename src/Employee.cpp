#include "../header/Employee.h"

Employee::Employee(int id, string name, int deptId) {
    m_Id = id;
    m_Name = name;
    m_DeptId = deptId;
}

void Employee::showInfo() {
    cout << "Worker ID: " << this->m_Id
         << " \tWorker Name: " << this->m_Name
         << " \tJob:" << this->getDeptName()
         << " \tResponsibility: Finish task from Manager" << endl;
}

string Employee::getDeptName() {
    return string("Employee");
}