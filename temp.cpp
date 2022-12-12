#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
//#include "jsoncpp.cpp"
#include <iostream>
#include <fstream>
using namespace std;
class Person//人为基类
{
   private:
      int Type;// 1bytes,1为教师，2为实验员，3为行政，4为教师兼行政
      string Num;
      string Name;
      char Gender;//boys is 1
      int Age;
   public:
      Person(int type=0,string num = "123456", string name = "aaaa", char gen = '1', int age = 233)
      { 
         Type = type;
         Num=num;
         Name=name;
         Gender = gen;
         Age=age;
      }
      char getType() { return Type; }
      string getNum() { return Num; }
      string getName() { return Name; }
      char getGender(){return Gender;}
      int getAge() { return Age; }
};
class Teacher : public Person//教师为派生类
{
   private:
      string Faculty;//系部
      string Speciality;//专业
      string JobTitle;//职称
   public:
      Teacher(string num = "123456", string name = "aaaa", char gen = '1', int age = 233, string fac = "", string spe = "", string job = "") : Person(1, num, name, gen, age)
      {
         Faculty = fac;
         Speciality = spe;
         JobTitle = job;
      }
      string getFaculty() { return Faculty; }
      string getSpeciality() { return Speciality; }
      string getJobTitle() { return JobTitle; }
      int count(int Ty, vector<Teacher> p){//若T=1则计算总人数，若Ty=2则计算男员工人数，若Ty=3则计算女员工人数
         int i, count = 0;
         if (Ty == 1)
         {
            for (i = 0; i < p.size(); i++)
            {
               count++;
            }
         }
         else if (Ty == 2)
         {
            for (i = 0; i < p.size(); i++)
            {
               if (p[i].getGender() == '1')
                  count++;
            }
         }
         else if (Ty == 3)
         {
            for (i = 0; i < p.size(); i++)
            {
               if (p[i].getGender() == '0')
                  count++;
            }
         }
         return count;
      }
};
class Experimenter : public Person//实验员为派生类
{
   private:
      string Laboratory;//xx实验室
      string Job;//职务
   public:
      Experimenter(string num = "123456", string name = "aaaa", char gen = '1', int age = 233, string lab = "", string job = "") : Person(2, num, name, gen, age)
      {
         Laboratory = lab;
         Job = job;
      }
      string getLaboratory() { return Laboratory; }
      string getJob() { return Job; }
      int count(int Ty, vector<Experimenter> &p){//若T=1则计算总人数，若Ty=2则计算男员工人数，若Ty=3则计算女员工人数
         int i, count = 0;
         if (Ty == 1)
         {
            for (i = 0; i < p.size(); i++)
            {
               count++;
            }
         }
         else if (Ty == 2)
         {
            for (i = 0; i < p.size(); i++)
            {
               if (p[i].getGender() == '1')
                  count++;
            }
         }
         else if (Ty == 3)
         {
            for (i = 0; i < p.size(); i++)
            {
               if (p[i].getGender() == '0')
                  count++;
            }
         }
         return count;
      }
};
class Admin : public Person//行政为派生类
{
   private:
      string Job;//职务
      string Officelocation;//办公地点
   public:
      Admin(string num="123456", string name = "aaaa", char gen='1', int age=233, string job="", string off="") : Person(3, num, name, gen, age)
      {
         Job = job;
         Officelocation = off;
      }
      string getJob() { return Job; }
      string getOfficelocation() { return Officelocation; }
      int count(int Ty, vector<Admin> &p){//若T=1则计算总人数，若Ty=2则计算男员工人数，若Ty=3则计算女员工人数
         int i, count = 0;
         if (Ty == 1)
         {
            for (i = 0; i < p.size(); i++)
            {
               count++;
            }
         }
         else if (Ty == 2)
         {
            for (i = 0; i < p.size(); i++)
            {
               if (p[i].getGender() == '1')
                  count++;
            }
         }
         else if (Ty == 3)
         {
            for (i = 0; i < p.size(); i++)
            {
               if (p[i].getGender() == '0')
                  count++;
            }
         }
         return count;
      }
};
class TeacherAdmin : public Person//教师兼行政为派生类
{
   private:
      string Faculty;//系部
      string Speciality;//专业
      string JobTitle;//职称
      string Job;//职务
      string Officelocation;//办公地点
   public:
      TeacherAdmin(string num = "123456", string name = "aaaa", char gen = '1', int age = 233, string fac = "", string spe = "", string job = "", string job1 = "", string off = "") : Person(4, num, name, gen, age)
      {
         Faculty = fac;
         Speciality = spe;
         JobTitle = job;
         Job = job1;
         Officelocation = off;
      }
      string getFaculty() { return Faculty; }
      string getSpeciality() { return Speciality; }
      string getJobTitle() { return JobTitle; }
      string getJob() { return Job; }
      string getOfficelocation() { return Officelocation; }
      int count(int Ty, vector<TeacherAdmin> &p){//若Ty=1则计算总人数，若Ty=2则计算男员工人数，若Ty=3则计算女员工人数
         int i, count = 0;
         if (Ty == 1)
         {
            for (i = 0; i < p.size(); i++)
            {
               count++;
            }
         }
         else if (Ty == 2)
         {
            for (i = 0; i < p.size(); i++)
            {
               if (p[i].getGender() == '1')
                  count++;
            }
         }
         else if (Ty == 3)
         {
            for (i = 0; i < p.size(); i++)
            {
               if (p[i].getGender() == '0')
                  count++;
            }
         }
         return count;
      }
};

int main(){
system("chcp 65001");//设置控制台输出为UTF-8编码
vector<Teacher> t;
vector<Experimenter*> e;
vector<Admin*> a;
vector<TeacherAdmin*> ta;
Teacher Teacher_temp("123456","aaaa",'1',233,"计算机系","计算机科学与技术","教授");
Experimenter Experimenter_temp("12","aaaa",'1',233,"计算机系","计算机科学与技术","教授");
t.push_back(Teacher_temp);
   //统计教师人数
   cout << "教师总人数为：" << t[0].count(1,t) << endl;
   //统计男教师人数
   cout << "男教师人数为：" << t[0].count(2,t) << endl;
   //统计女教师人数
   cout << "女教师人数为：" << t[0].count(3,t) << endl;
   return 0;
}