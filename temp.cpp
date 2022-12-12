#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;
class Person//人为基类
{
   private:
      char Type;// 1bytes,1为教师，2为实验员，3为行政，4为教师兼行政
      char Num[8];
      char Name[8];
      char Gender;//boys is 1
      int Age;
   public:
      Person(char type='0',char num[8] = "123456", char name[8] = "aaaa", char gen = '1', int age = 233)
      { 
         Type = type;
         strcpy(Num, num);
         strcpy(Name, name);
         Gender = gen;
         Age=age;
      }
      char getType() { return Type; }
      string getNum() { return Num; }
      string getName() { return Name; }
      char getGender(){return Gender;}
      int getAge() { return Age; }
      int Count(int Ty,vector<Person> &p);//统计人数,ty为统计类型,若ty=0则统计所有人数,若ty=1则统计男员工人数,若ty=2则统计女员工人数
};
int Person::Count(int Ty,vector<Person> &p)
{
   int count = 0;
   if (Ty == 0)
   {
      count = p.size();
   }
   else if (Ty == 1)
   {
      for (int i = 0; i < p.size(); i++)
      {
         if (p[i].getGender() == '1')
         {
            count++;
         }
      }
   }
   else if (Ty == 2)
   {
      for (int i = 0; i < p.size(); i++)
      {
         if (p[i].getGender() == '0')
         {
            count++;
         }
      }
   }
   return count;
}
class Teacher : public Person//教师为派生类
{
   private:
      char Faculty[8];//系部
      char Speciality[8];//专业
      char JobTitle[8];//职称
   public:
      Teacher(char type = '1', char num[8] = "123456", char name[8] = "aaaa", char gen = '1', int age = 233, char fac[8] = "", char spe[8] = "", char job[8] = "") : Person(type, num, name, gen, age)
      {
         strcpy(Faculty, fac);
         strcpy(Speciality, spe);
         strcpy(JobTitle, job);
      }
      string getFaculty() { return Faculty; }
      string getSpeciality() { return Speciality; }
      string getJobTitle() { return JobTitle; }
};
class Experimenter : public Person//实验员为派生类
{
   private:
      char Laboratory[8];//xx实验室
      char Job[8];//职务
   public:
      Experimenter(char type = '2', char num[8] = "123456", char name[8] = "aaaa", char gen = '1', int age = 233, char lab[8] = "", char job[8] = "") : Person(type, num, name, gen, age)
      {
         strcpy(Laboratory, lab);
         strcpy(Job, job);
      }
      string getLaboratory() { return Laboratory; }
      string getJob() { return Job; }
};
class Admin : public Person//行政为派生类
{
   private:
      char Job[8];//职务
      char Officelocation[8];//办公地点
   public:
      Admin(char type = '3', char num[8]="123456", char name[8]="aaaa", char gen='1', int age=233, char job[8]="", char off[8]="") : Person(type, num, name, gen, age)
      {
         strcpy(Job, job);
         strcpy(Officelocation, off);
      }
      string getJob() { return Job; }
      string getOfficelocation() { return Officelocation; }
};
class TeacherAdmin : public Person//教师兼行政为派生类
{
   private:
      char Faculty[8];//系部
      char Speciality[8];//专业
      char JobTitle[8];//职称
      char Job[8];//职务
      char Officelocation[8];//办公地点
   public:
      TeacherAdmin(char type = '4', char num[8] = "123456", char name[8] = "aaaa", char gen = '1', int age = 233, char fac[8] = "", char spe[8] = "", char job[8] = "", char job1[8] = "", char off[8] = "") : Person(type, num, name, gen, age)
      {
         strcpy(Faculty, fac);
         strcpy(Speciality, spe);
         strcpy(JobTitle, job);
         strcpy(Job, job1);
         strcpy(Officelocation, off);
      }
      string getFaculty() { return Faculty; }
      string getSpeciality() { return Speciality; }
      string getJobTitle() { return JobTitle; }
      string getJob() { return Job; }
      string getOfficelocation() { return Officelocation; }
};

template <typename T>
int count (int Ty, vector<T> &p)
{
   int Sum = 0;
   if (Ty == 0)
   {
      Sum = p.size();
   }
   else if (Ty == 1)
   {
      for (int i = 0; i < p.size(); i++)
      {
         if (p[i].getGender() == '1')
         {
            Sum++;
         }
      }
   }
   else if (Ty == 2)
   {
      for (int i = 0; i < p.size(); i++)
      {
         if (p[i].getGender() == '0')
         {
            Sum++;
         }
      }
   }
   return Sum;
}



int main(){
vector<Teacher*> t;
vector<Experimenter*> e;
vector<Admin*> a;
vector<TeacherAdmin*> ta;
t.push_back(new Teacher('1', "123456", "aaaa", '1', 233, "计算机", "软件工程", "教授"));
t.push_back(new Teacher('1', "123456", "bbbb", '1', 233, "计算机", "软件工程", "副教授"));
   //统计教师人数
   // cout << "教师人数为：" << count(0, t) << endl;
   t[0]->Count(1, t);//统计男教师人数
   system("pause");
   return 0;
}