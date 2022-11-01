#pragma once
#include <iostream>
#include <fstream>
#include "Worker.h"

#define FILENAME "empFile.txt"

using namespace std;

class WorkerManager {
public:
    // 构造函数
    WorkerManager();

    // 展示菜单
    void showMenu();

    // 退出系统
    void exitSystem();

    // 增加员工信息
    void Add_Emp();

    // 析构函数
    ~WorkerManager();

    // 保存文件
    void save();

    // 从文件中读取数据条目数
    int get_Num();

    // 从数据库中读取到内存中
    void init_Emp();

    // 显示员工
    void show_Emp();

    // 删除员工
    void del_Emp();

    // 修改职工
    void update_Emp();

    // 查找
    void find_Emp();

    // 清空
    void trunc_Emp();

    // 排序
    void sort_Emp();
public:
    int m_EmpNum;
    Worker ** m_EmpArray;
    bool m_FileIsEmpty;
};