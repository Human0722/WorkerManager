#include "../header/Manager.h"

Manager::Manager(int id, string name, int deptId) {
    m_Id = id;
    m_Name = name;
    m_DeptId = deptId;
}

void Manager::showInfo() {
    cout << "Worker ID: " << this->m_Id
         << " \tWorker Name: " << this->m_Name
         << " \tJob:" << this->getDeptName()
         << " \tResponsibility: Finish task from Boss, and spare to Employee" << endl;
};

string Manager::getDeptName() {
    return string("Manager");
}