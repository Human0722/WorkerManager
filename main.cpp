#include <iostream>
#include "header/WorkerManager.h"

using namespace std;

int main() {
    WorkerManager wm;
    int choice = 0;

    while(true) {
        wm.showMenu();
        cout << "请输入您的选择 :";
        cin >> choice;

        switch (choice) {
            case 0: // 退出管理程序
                wm.exitSystem();
                break;
            case 1: //增加职工信息
                wm.Add_Emp();
                break;
            case 2: // 显示职工信息
                wm.show_Emp();
                break;
            case 3: // 删除职工信息
                wm.del_Emp();
                break;
            case 4: // 修改职工信息
                wm.update_Emp();
                break;
            case 5: // 查找职工信息
                wm.find_Emp();
                break;
            case 6: // 按照编号排序
                wm.sort_Emp();
                break;
            case 7: // 清空所有文档
                wm.trunc_Emp();
                break;
            default:
                system("cls");
                break;
        }
    }
}
