// 690. Employee Importance

/*
    Input: employees = [[1,5,[2,3]],[2,3,[]],[3,3,[]]], id = 1
    Output: 11
    Explanation: Employee 1 has an importance value of 5 and has two direct subordinates: employee 2 and employee 3.
    They both have an importance value of 3.
    Thus, the total importance value of employee 1 is 5 + 3 + 3 = 11.
*/

#include<bits/stdc++.h>
using namespace std;


// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;

    Employee(int id_,int importance_,vector<int> subordinates_){
        id = id_;
        importance = importance_;
        for(auto x:subordinates_) subordinates.push_back(x);  
    }
};



    int dfsSum(Employee* emp,unordered_map<int,Employee*>& map){
        int ans = emp->importance;
        
        for(auto x:emp->subordinates) ans += dfsSum(map[x],map);
        
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> map;
        for(auto x:employees) map[x->id] = x;  
        
        int ans = dfsSum(map[id],map);
        return ans;
    }

int main(){

    vector<int> subordinates_1 = {2,3};
    Employee *emp1 = new Employee(1,5,subordinates_1);

    vector<int> subordinates_2 = {};
    Employee *emp2 = new Employee(2,3,subordinates_2);

    vector<int> subordinates_3 = {};
    Employee *emp3 = new Employee(3,3,subordinates_3);

    vector<Employee*> employees;
    employees.push_back(emp1);
    employees.push_back(emp2);
    employees.push_back(emp3);

    cout<<getImportance(employees,1);

    return 0;
}