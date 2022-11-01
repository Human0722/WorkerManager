#include "../header/Boss.h"

Boss::Boss(int id, string name, int deptId) {
    m_Id = id;
    m_Name = name;
    m_DeptId = deptId;
}

void Boss::showInfo() {
    cout << "Worker ID: " << this->m_Id
         << " \tWorker Name: " << this->m_Name
         << " \tJob:" << this->getDeptName()
         << " \tResponsibility : Manage all stuff" << endl;
}

string Boss::getDeptName() {
    return string("BOSS");
}