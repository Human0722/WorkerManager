#include "../header/Worker.h"
#include "../header/Employee.h"
#include "../header/Manager.h"
#include "../header/Boss.h"
#include <iostream>

void test() {
    Worker * worker = NULL;

    worker = new Employee(1,"randy", 12);
    worker->showInfo();
    worker->getDeptName();

    worker = new Manager(2, "lisi", 2);
    worker->showInfo();
    delete worker;

    worker = new Boss(3, "wang", 3);
    worker->showInfo();
    delete worker;
}

int main() {
    test();
    return 0;
}
