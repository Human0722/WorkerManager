#include "../header/WorkerManager.h"
#include "../header/Employee.h"
#include "../header/Manager.h"
#include "../header/Boss.h"

WorkerManager::WorkerManager() {

    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    // 文件不存在
    if (!ifs.is_open()) {
        cout << "数据库不存在，将创建" << endl;
        this->m_FileIsEmpty = true;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        ifs.close();
        return ;
    }
    // 文件为空
    char ch;
    ifs >> ch;
    while(ifs.eof()) {
        cout << "文件为空" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = nullptr;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    // 文件不为空时
    int num = this->get_Num();
    this->m_EmpNum = num;
    cout << "职工个数为:" << num << endl;
    this->m_FileIsEmpty = false;

    this->m_EmpArray = new Worker * [this->m_EmpNum];
    this->init_Emp();
}


WorkerManager::~WorkerManager() {
    if (this->m_EmpArray != NULL) {
        delete[] this->m_EmpArray;
    }

}

void WorkerManager::showMenu() {

    cout << "********************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ **********" << endl;
    cout << "*************  0.退出管理程序  *************" << endl;
    cout << "*************  1.增加职工信息  *************" << endl;
    cout << "*************  2.显示职工信息  *************" << endl;
    cout << "*************  3.删除离职职工  *************" << endl;
    cout << "*************  4.修改职工信息  *************" << endl;
    cout << "*************  5.查找职工信息  *************" << endl;
    cout << "*************  6.按照编号排序  *************" << endl;
    cout << "*************  7.清空所有文档  *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem() {
    exit(0);
}

void WorkerManager::Add_Emp() {
    int addNum = 0;
    cout << "请输入新增员工数量:";
    cin >> addNum;
    if (addNum > 0) {
        // 计算增加后的空间
        int newSize = m_EmpNum + addNum;
        //开辟新数组
        Worker ** newSpace = new Worker*[newSize];
        // 扩容
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < m_EmpNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        //追加新数据
        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int deptId;

            cout << "Please input NO." << i+1 << " id:";
            cin >> id;
            cout << "Please input NO." << i+1 << " name:";
            cin >> name;
            cout << "Please input NO." << i+1 << " deptId:";
            cout << "Please input deptId:" << endl;
            cout << "1: Employee" << endl;
            cout << "2: Manager" << endl;
            cout << "3: Boss" << endl;
            cin >> deptId;

            Worker * worker = NULL;
            switch(deptId) {
                case 1:
                    worker = new Employee(id, name, deptId);
                    break;
                case 2:
                    worker = new Manager(id, name, deptId);
                    break;
                case 3:
                    worker = new Boss(id, name, deptId);
                    break;
                default:
                    break;
            }
            newSpace[m_EmpNum + i] = worker;
        }
        // 释放原有的空间
        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_EmpNum = newSize;
        this->m_FileIsEmpty = false;
        cout << "成功添加" << addNum << "名员工!" << endl;

        this->save();
    }else {
        cout << "输入有误" << endl;
    }
//    system("pause");
//    system("cls");
}

// 保存文件
void WorkerManager::save() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_EmpNum; i++) {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}

// 从数据库中读读取条目数
int WorkerManager::get_Num() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int deptId;

    int count = 0;

    while(ifs >> id && ifs >> name && ifs >> deptId) {
       count++;
    }
    ifs.close();
    return count;
}

//从数据库中读取数据到内存
void WorkerManager::init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int deptId;

    int index = 0;

    while(ifs >> id && ifs >> name && ifs >> deptId) {
        Worker * worker = NULL;
       if (deptId == 1) {
          worker = new Employee(id, name, deptId);
       }else if (deptId == 2) {
           worker = new Manager(id, name, deptId);
       }else if (deptId == 3) {
           worker = new Boss(id, name, deptId);
       }else {
           cout << "Delete Error Data:" << endl
                << "id: " << id << endl
                << "name: " << name << endl
                << "deptId: " << deptId << endl;
           continue;
       }
       this->m_EmpArray[index] = worker;
       index++;
    }
}

// 显示员工
void WorkerManager::show_Emp() {
    if (m_FileIsEmpty) {
        cout << "文件不存在" << endl;
    }else {
        for (int i = 0; i < m_EmpNum; i++) {
            this->m_EmpArray[i]->showInfo();
        }
    }
}

// 删除员工
void WorkerManager::del_Emp() {
    cout << "所有员工信息:" << endl;
    this->show_Emp();
    cout << "请输入要删除的编号" << endl;
    int id = -1;
    cin >> id;

    int flag = -100;

    for (int i = 0; i < this->m_EmpNum; i++) {
        if (this->m_EmpArray[i]->m_Id == id) {
            flag = i;
        }
    }
    if (flag == -100) {
        cout << "找不到id=" << id << "的用户";
    } else {
        delete this->m_EmpArray[flag];
        for (int j = flag; j < this->m_EmpNum - 1; j++) {
            this->m_EmpArray[j] = this->m_EmpArray[j+1];
        }
        --this->m_EmpNum;
        this->save();
    }
}

// 更新信息
void WorkerManager::update_Emp() {
    cout << "员工信息表：" << endl;
    this->show_Emp();
    cout << "请输入要修改的id:";
    int id = 0;
    cin >> id;

    string name;
    int deptId;

    bool flag = false;


    for (int i = 0 ; i < m_EmpNum; i++) {
        if(this->m_EmpArray[i]->m_Id == id) {
            cout << "原姓名[" << this->m_EmpArray[i]->m_Name << "], 请输入新姓名:";
            cin >> name;
            cout << "原部门[" << this->m_EmpArray[i]->m_DeptId << "], 请输入新部门:";
            cin >> deptId;
            this->m_EmpArray[i]->m_Name = name;
            this->m_EmpArray[i]->m_Id = deptId;
            this->save();
            flag = true;
        }
    }
    if (!flag) {
        cout << "数据未找到" << endl;
    }
}
// 查找
void WorkerManager::find_Emp() {
    cout << "数据表" << endl;
    this->show_Emp();
    int id = 0;
    cout << "请输入id进行查找: ";
    cin >> id;
    for (int i = 0 ; i < m_EmpNum; i++) {
        if(id == m_EmpArray[i]->m_Id) {
            this->m_EmpArray[i]->showInfo();
        }
    }
}

// 清空
void WorkerManager::trunc_Emp() {
    ofstream ofs;
    ofs.open(FILENAME, ios::trunc);
    ofs.close();
    delete[] this->m_EmpArray;
    this->m_EmpArray = NULL;
    this->m_EmpNum = 0;
}

//
void WorkerManager::sort_Emp() {
    for (int i = 0; i < m_EmpNum; i++) {
        for (int j = 0; j < m_EmpNum - i - 1; j++) {
            if (m_EmpArray[j]->m_Id > m_EmpArray[j+1]->m_Id) {
                Worker * temp = NULL;
                temp = m_EmpArray[j];
                m_EmpArray[j] = m_EmpArray[j+1];
                m_EmpArray[j+1] = temp;
            }
        }
    }
    this->save();
    this->show_Emp();
}