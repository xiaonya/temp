#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "jsoncpp.cpp"
#include <iostream>
#include <fstream>
using namespace std;
class Person//人为基类
{
   private:
      int Type;// 1bytes,1为教师，2为实验员，3为行政，4为教师兼行政
      string Num;
      string Name;
      int Gender;//boys is 1
      int Age;
   public:
      Person(int type=0,string num = "123456", string name = "aaaa", int gen = 1, int age = 233)
      { 
         Type = type;
         Num=num;
         Name=name;
         Gender = gen;
         Age=age;
      }
      int getType() { return Type; }
      string getNum() { return Num; }
      string getName() { return Name; }
      int getGender(){return Gender;}
      int getAge() { return Age; }
      void Change0(int type, string num, string name, int gen, int age)
      {
         Type = type;
         Num = num;
         Name = name;
         Gender = gen;
         Age = age;
      }
};
class Teacher : public Person//教师为派生类
{
   private:
      string Faculty;//系部
      string Speciality;//专业
      string JobTitle;//职称
   public:
      Teacher(string num = "123456", string name = "aaaa", int gen = 1, int age = 233, string fac = "", string spe = "", string job = "") : Person(1, num, name, gen, age)
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
               if (p[i].getGender() == 1)
                  count++;
            }
         }
         else if (Ty == 3)
         {
            for (i = 0; i < p.size(); i++)
            {
               if (p[i].getGender() == 0)
                  count++;
            }
         }
         return count;
      }
      void show(){
         cout << "--------------------------------" << endl;
         cout << "Type:" << "1.教师" << endl;
         cout << "Num:" << getNum() << endl;
         cout << "Name:" << getName() << endl;
         cout << "Gender:"<<((getGender())?("男员工"):("女员工"))<< endl;
         cout << "Age:" << getAge() << endl;
         cout << "Faculty:" << getFaculty() << endl;
         cout << "Speciality:" << getSpeciality() << endl;
         cout << "JobTitle:" << getJobTitle() << endl;
         cout << "--------------------------------" << endl;
      }
      void modify(string num, string name, int gen, int age, string fac, string spe, string job)
      {  
         Change0(1, num, name, gen, age);
         Faculty = fac;
         Speciality = spe;
         JobTitle = job;
      }  
};
class Experimenter : public Person//实验员为派生类
{
   private:
      string Laboratory;//xx实验室
      string Job;//职务
   public:
      Experimenter(string num = "123456", string name = "aaaa", int gen = 1, int age = 233, string lab = "", string job = "") : Person(2, num, name, gen, age)
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
               if (p[i].getGender() == 1)
                  count++;
            }
         }
         else if (Ty == 3)
         {
            for (i = 0; i < p.size(); i++)
            {
               if (p[i].getGender() == 0)
                  count++;
            }
         }
         return count;
      }
      void show(){
         cout << "--------------------------------" << endl;
         cout << "Type:" << "2.实验员" << endl;
         cout << "Num:" << getNum() << endl;
         cout << "Name:" << getName() << endl;
         cout << "Gender:"<<((getGender())?("男员工"):("女员工"))<< endl;
         cout << "Age:" << getAge() << endl;
         cout << "Laboratory:" << getLaboratory() << endl;
         cout << "Job:" << getJob() << endl;
         cout << "--------------------------------" << endl;
      }
      void modify(string num, string name, int gen, int age, string lab, string job)
      {
         Change0(2, num, name, gen, age);
         Laboratory = lab;
         Job = job;
      }
};
class Admin : public Person//行政为派生类
{
   private:
      string Job;//职务
      string Officelocation;//办公地点
   public:
      Admin(string num="123456", string name = "aaaa", int gen = 1, int age=233, string job="", string off="") : Person(3, num, name, gen, age)
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
               if (p[i].getGender() == 1)
                  count++;
            }
         }
         else if (Ty == 3)
         {
            for (i = 0; i < p.size(); i++)
            {
               if (p[i].getGender() == 0)
                  count++;
            }
         }
         return count;
      }
      void show(){
         cout << "--------------------------------" << endl;
         cout << "Type:" << "3.行政" << endl;
         cout << "Num:" << getNum() << endl;
         cout << "Name:" << getName() << endl;
         cout << "Gender:"<<((getGender())?("男员工"):("女员工"))<< endl;
         cout << "Age:" << getAge() << endl;
         cout << "Job:" << getJob() << endl;
         cout << "Officelocation:" << getOfficelocation() << endl;
         cout << "--------------------------------" << endl;
      }
      void modify(string num, string name, int gen, int age, string job, string off)
      {
         Change0(3, num, name, gen, age);
         Job = job;
         Officelocation = off;
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
      TeacherAdmin(string num = "123456", string name = "aaaa", int gen = 1, int age = 233, string fac = "", string spe = "", string job = "", string job1 = "", string off = "") : Person(4, num, name, gen, age)
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
               if (p[i].getGender() == 1)
                  count++;
            }
         }
         else if (Ty == 3)
         {
            for (i = 0; i < p.size(); i++)
            {
               if (p[i].getGender() == 0)
                  count++;
            }
         }
         return count;
      }
      void show(){
         cout << "--------------------------------" << endl;
         cout << "Type:" << "4.教师兼行政" << endl;
         cout << "Num:" << getNum() << endl;
         cout << "Name:" << getName() << endl;
         cout << "Gender:"<<((getGender())?("男员工"):("女员工"))<< endl;
         cout << "Age:" << getAge() << endl;
         cout << "Faculty:" << getFaculty() << endl;
         cout << "Speciality:" << getSpeciality() << endl;
         cout << "JobTitle:" << getJobTitle() << endl;
         cout << "Job:" << getJob() << endl;
         cout << "Officelocation:" << getOfficelocation() << endl;
         cout << "--------------------------------" << endl;
      }
      void modify(string num, string name, int gen, int age, string fac, string spe, string job, string job1, string off)
      {
         Change0(4, num, name, gen, age);
         Faculty = fac;
         Speciality = spe;
         JobTitle = job;
         Job = job1;
         Officelocation = off;
      }
};

int CheckName(string Name, vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){//在插入新元素时判断名字是否存在，若存在则返回0，否则返回1
   int i;
   for(i=0;i<t.size();i++){
      if(Name==t[i].getName())
         return 0;
   }
   for(i=0;i<e.size();i++){
      if(Name==e[i].getName())
         return 0;
   }
   for(i=0;i<a.size();i++){
      if(Name==a[i].getName())
         return 0;
   }
   for(i=0;i<ta.size();i++){
      if(Name==ta[i].getName())
         return 0;
   }
   return 1;
}

int CheckNum(string Num, vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){//在插入新元素时检验编号唯一性,若重复则返回0，否则返回1
   int i;
   for(i=0;i<t.size();i++){
      if(Num==t[i].getNum())
         return 0;
   }
   for(i=0;i<e.size();i++){
      if(Num==e[i].getNum())
         return 0;
   }
   for(i=0;i<a.size();i++){
      if(Num==a[i].getNum())
         return 0;
   }
   for(i=0;i<ta.size();i++){
      if(Num==ta[i].getNum())
         return 0;
   }
   return 1;
}
void InsertNew(vector<Teacher> &t, vector<Experimenter> &e, vector<Admin> &a, vector<TeacherAdmin> &ta){//插入数据
   int i;
   cout<<"请输入员工身份对应的数字：1.教师 2.实验员 3.行政 4.教师兼行政"<<endl;
   cin>>i;
   while (cin.fail()){//判断输入是否为整数
      cin.clear();//清除错误状态，以便重新输入
      cin.sync();//清空输入流中的内容
      cout<<"输入错误，请重新输入"<<endl;
      cin>>i;
   }
   int age,gen;//gen性别 1男 0女
   string num, name,fac,spe,job,lab,job1,off;//fac系部 spe专业 job职称 lab实验室 job1职务 off办公地点
   switch (i)
   {
   case 1:{
      cout<<"请输入教师的工号、姓名、性别[1男 0女]、年龄、系部、专业、职称"<<endl;
      cin>>num>>name>>gen>>age>>fac>>spe>>job;
      if (CheckNum(num, t, e, a, ta))
      {
         Teacher Teacher_temp(num, name, gen, age, fac, spe, job);
         t.push_back(Teacher_temp);
         cout << "数据项增添成功" << endl;
      }
      else
         cout << "该工号已存在,请检查无误后重新增添数据项" << endl;
      break;}

   case 2:{
      cout<<"请输入实验员的工号、姓名、性别[1男 0女]、年龄、实验室、职务"<<endl;
      cin>>num>>name>>gen>>age>>lab>>job1;
      if (CheckNum(num, t, e, a, ta))
      {
         Experimenter Experimenter_temp(num, name, gen, age, lab, job1);
         e.push_back(Experimenter_temp);
         cout << "数据项增添成功" << endl;
      }
      else
         cout << "该工号已存在,请检查无误后重新增添数据项" << endl;
      break;}

   case 3:{
      cout<<"请输入行政的工号、姓名、性别[1男 0女]、年龄、职务、办公地点"<<endl;
      cin>>num>>name>>gen>>age>>job1>>off;
      if (CheckNum(num, t, e, a, ta))
      {
         Admin Admin_temp(num, name, gen, age, job1, off);
         a.push_back(Admin_temp);
         cout << "数据项增添成功" << endl;
      }
      else
         cout << "该工号已存在,请检查无误后重新增添数据项" << endl;
      break;}

   case 4:{
      cout<<"请输入教师兼行政的工号、姓名、性别[1男 0女]、年龄、系部、专业、(教师)职称、（行政）职务、办公室"<<endl;
      cin>>num>>name>>gen>>age>>fac>>spe>>job>>off>>job1;
      if (CheckNum(num, t, e, a, ta))
      {
         TeacherAdmin TeacherAdmin_temp(num, name, gen, age, fac, spe, job, job1, off);
         ta.push_back(TeacherAdmin_temp);
         cout << "数据项增添成功" << endl;
      }
      else
         cout << "该工号已存在,请检查无误后重新增添数据项" << endl;
      break;}
   default:
      cout<<"身份输入错误，回到主界面"<<endl;
      break;
   }
}

void CountSum(vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){//统计人数
      cout<<"教师总人数为："<<t[0].count(1,t)<<endl;
      cout<<"实验员总人数为："<<e[0].count(1,e)<<endl;
      cout<<"行政总人数为："<<a[0].count(1,a)<<endl;
      cout<<"教师兼行政员工总人数为："<<ta[0].count(1,ta)<<endl;
      cout<<"总人数为："<<t[0].count(1,t)+e[0].count(1,e)+a[0].count(1,a)+ta[0].count(1,ta)<<endl;
      cout<<"男员工总人数为："<<t[0].count(2,t)+e[0].count(2,e)+a[0].count(2,a)+ta[0].count(2,ta)<<endl;
      cout<<"女员工总人数为："<<t[0].count(3,t)+e[0].count(3,e)+a[0].count(3,a)+ta[0].count(3,ta)<<endl;
}

//用于查找功能的函数，返回一个整型数组，数组中存放的是查找到的元素的下标，未做模糊匹配，若需要模糊匹配功能需要增加正则表达式的库
int NameSearchCore(string Name,int (&Res)[100], vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){//名称查找函数的核心函数，Num为存放查找结果的数组,Name为查找的姓名
   int n=0,x,y,i;//存放查找结果的下标,x为种类的标志，y为具体种类的下标,n为查找到的个数
   for(i=0;i<t.size();i++){//在教师中查找
      if(Name==t[i].getName()){
         x=2*n;
         y=2*n+1;
         Res[x]=1;
         Res[y]=i;
         n++;
      }
   }
   for(i=0;i<e.size();i++){//在实验员中查找
      if(Name==e[i].getName()){
         x=2*n;
         y=2*n+1;
         Res[x]=2;
         Res[y]=i;
         n++;
      }
   }
   for(i=0;i<a.size();i++){//在行政人员中查找
      if(Name==a[i].getName()){
         x=2*n;
         y=2*n+1;
         Res[x]=3;
         Res[y]=i;
         n++;
      }
   }
   for(i=0;i<ta.size();i++){//在教师兼行政人员中查找
      if(Name==ta[i].getName()){
         x=2*n;
         y=2*n+1;
         Res[x]=4;
         Res[y]=i;
         n++;
      }
   }
   return n;//返回查找结果的个数
}
int NumSearchCore(string Num,int (&Res)[100], vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){//编号查找函数的核心函数，Num为存放查找结果的数组,Num为查找的编号
   int n=0,x,y,i;//存放查找结果的下标,x为种类的标志，y为具体种类的下标,n为查找到的个数
   for(i=0;i<t.size();i++){//在教师中查找
      if(Num==t[i].getNum()){
         x=2*n;
         y=2*n+1;
         Res[x]=1;
         Res[y]=i;
         n++;
      }
   }
   for(i=0;i<e.size();i++){//在实验员中查找
      if(Num==e[i].getNum()){
         x=2*n;
         y=2*n+1;
         Res[x]=2;
         Res[y]=i;
         n++;
      }
   }
   for(i=0;i<a.size();i++){//在行政人员中查找
      if(Num==a[i].getNum()){
         x=2*n;
         y=2*n+1;
         Res[x]=3;
         Res[y]=i;
         n++;
      }
   }
   for(i=0;i<ta.size();i++){//在教师兼行政人员中查找
      if(Num==ta[i].getNum()){
         x=2*n;
         y=2*n+1;
         Res[x]=4;
         Res[y]=i;
         n++;
      }
   }
   return n;//返回查找结果的个数
}
void Search(vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){
   int flag;//存放查找方式的标志
   cout<<"若按照编号查找则输入1，若按照姓名查找则输入2"<<endl;
   cin>>flag;
   while (cin.fail()){//判断输入是否为整数
      cin.clear();//清除错误状态，以便重新输入
      cin.sync();//清空输入流中的内容
      cout<<"输入错误，请重新输入"<<endl;
      cin>>flag;
   }
   switch (flag)
   {
      case 1:{//按照编号查找
         int Res[100];//存放查找结果的数组
         int count;//存放查找结果的个数
         string Num;
         cout<<"请输入要查找的编号"<<endl;
         cin>>Num;
         count=NumSearchCore(Num,Res,t,e,a,ta);
         if(count==0){//没有查找到结果
            cout<<"没有查找到结果"<<endl;
            break;
         }
         for (int i=0;i<count;i++){//输出查找结果
            int x=2*i;
            int y=2*i+1;
            switch (Res[x])
            {
            case 1:
               t[Res[y]].show();
               break;
            case 2:
               e[Res[y]].show();
               break;
            case 3:
               a[Res[y]].show();
               break;
            case 4:
               ta[Res[y]].show();
               break;
            default:
               break;
            }
         }
         break;}
      case 2:{//按照姓名查找
         int Res[100];//存放查找结果的数组
         int count;//存放查找结果的个数
         string Name;
         cout<<"请输入要查找的姓名"<<endl;
         cin>>Name;
         count=NameSearchCore(Name,Res,t,e,a,ta);
         if (count==0)//没有查找到结果
         {
            cout<<"没有查找到结果"<<endl;
            break;
         }
         for (int i=0;i<count;i++){//输出查找结果
            int x=2*i;
            int y=2*i+1;
            switch (Res[x])
            {
            case 1:
               t[Res[y]].show();
               break;
            case 2:
               e[Res[y]].show();
               break;
            case 3:
               a[Res[y]].show();
               break;
            case 4:
               ta[Res[y]].show();
               break;
            default:
               break;
            }
         }
         break;}
      default:
         cout<<"输入错误，回到主菜单"<<endl;
         break;
   }



}
//用于删除的函数
void Delete(vector<Teacher> &t, vector<Experimenter> &e, vector<Admin> &a, vector<TeacherAdmin> &ta){//删除函数,由于删除这一操作的特殊性，删除只能通过唯一的编号来进行操作
   cout<<"请输入要删除的人员的编号"<<endl;
   string Num;
   cin>>Num;
   if (CheckNum(Num,t,e,a,ta))
   {
      cout<<"编号不存在，删除失败"<<endl;
      return;
   }
   else{//开始执行删除操作
      for (int i=0;i<t.size();i++){//在教师中查找
         if (Num==t[i].getNum())
         {
            t.erase(t.begin()+i);
            cout<<"删除成功"<<endl;
            return;
         }
      }
      for (int i=0;i<e.size();i++){//在实验员中查找
         if (Num==e[i].getNum())
         {
            e.erase(e.begin()+i);
            cout<<"删除成功"<<endl;
            return;
         }
      }
      for (int i=0;i<a.size();i++){//在行政中查找
         if (Num==a[i].getNum())
         {
            a.erase(a.begin()+i);
            cout<<"删除成功"<<endl;
            return;
         }
      }
      for (int i=0;i<ta.size();i++){//在教师兼行政中查找
         if (Num==ta[i].getNum())
         {
            ta.erase(ta.begin()+i);
            cout<<"删除成功"<<endl;
            return;
         }
      }
   }
}

//用于修改的函数，修改前先检查编号唯一性，修改后再检查编号唯一性
void ModifyAccordingNum(vector<Teacher> &t, vector<Experimenter> &e, vector<Admin> &a, vector<TeacherAdmin> &ta){
   cout<<"请输入要修改的人员的编号"<<endl;
   int age,gen;//gen性别 1男 0女
   string num, name,fac,spe,job,lab,job1,off,PastNum;
   cin>>num;
   PastNum=num;
   if (CheckNum(num,t,e,a,ta))
   {
      cout<<"编号不存在，找不到对象，修改失败"<<endl;
      return;
   }
   else{//开始执行修改操作
      for (int i=0;i<t.size();i++){//在教师中查找
         if (num==t[i].getNum()){
            cout<<"请输入修改后教师的工号、姓名、性别[1男 0女]、年龄、系部、专业、职称"<<endl;
            cin>>num>>name>>gen>>age>>fac>>spe>>job;
               if (CheckNum(num,t,e,a,ta)||num==PastNum)
               {  
                  t[i].modify(num,name,gen,age,fac,spe,job);
                  cout<<"修改成功"<<endl;
                  return;
               }
               else{
                  cout<<"修改失败，工号重复"<<endl;
                  return;
               }
            }
      }
      for (int i=0;i<e.size();i++){//在实验员中查找
         if (num==e[i].getNum())
         {
            cout<<"请输入修改后实验员的工号、姓名、性别[1男 0女]、年龄、实验室、职务"<<endl;
            cin>>num>>name>>gen>>age>>lab>>job1;
               if (CheckNum(num,t,e,a,ta)||num==PastNum)
               {  
                  e[i].modify(num,name,gen,age,lab,job1);
                  cout<<"修改成功"<<endl;
                  return;
               }
               else{
                  cout<<"修改失败，工号重复"<<endl;
                  return;
               }
         }
      }
      for (int i=0;i<a.size();i++){//在行政中查找
         if (num==a[i].getNum())
         {
            cout<<"请输入修改后行政的工号、姓名、性别[1男 0女]、年龄、职务、办公室"<<endl;
            cin>>num>>name>>gen>>age>>job>>off;
               if (CheckNum(num,t,e,a,ta)||num==PastNum)
               {  
                  a[i].modify(num,name,gen,age,job,off);
                  cout<<"修改成功"<<endl;
                  return;
               }
               else{
                  cout<<"修改失败，工号重复"<<endl;
                  return;
               }
         }
      }
      for (int i=0;i<ta.size();i++){//在教师兼行政中查找
         if (num==ta[i].getNum())
         {
            cout<<"请输入修改后教师兼行政的工号、姓名、性别[1男 0女]、年龄、系部、专业、职称、职务、办公室"<<endl;
            cin>>num>>name>>gen>>age>>fac>>spe>>job>>job1>>off;
               if (CheckNum(num,t,e,a,ta)||num==PastNum)
               {  
                  ta[i].modify(num,name,gen,age,fac,spe,job,job1,off);
                  cout<<"修改成功"<<endl;
                  return;
               }
               else{
                  cout<<"修改失败，工号重复"<<endl;
                  return;
               }
            }
         }
      }
}
void ModifyAccordingName(vector<Teacher> &t, vector<Experimenter> &e, vector<Admin> &a, vector<TeacherAdmin> &ta){
   cout<<"请输入要修改的人员的姓名"<<endl;
   int age,gen;//gen性别 1男 0女
   string num, name,fac,spe,job,lab,job1,off,PastName;
   cin>>name;
   PastName=name;
   if (CheckName(name,t,e,a,ta))
   {
      cout<<"姓名不存在，找不到对象，修改失败"<<endl;
      return;
   }
   else{//开始执行修改操作
      for (int i=0;i<t.size();i++){//在教师中查找
         if (name==t[i].getName()){
            cout<<"请输入修改后教师的工号、姓名、性别[1男 0女]、年龄、系部、专业、职称"<<endl;
            cin>>num>>name>>gen>>age>>fac>>spe>>job;
               if (CheckNum(num,t,e,a,ta)||num==t[i].getNum())
               {  
                  t[i].modify(num,name,gen,age,fac,spe,job);
                  cout<<"修改成功"<<endl;
                  return;
               }
               else{
                  cout<<"修改失败，工号重复"<<endl;
                  return;
               }
            }
      }
      for (int i=0;i<e.size();i++){//在实验员中查找
         if (name==e[i].getName())
         {
            cout<<"请输入修改后实验员的工号、姓名、性别[1男 0女]、年龄、实验室、职务"<<endl;
            cin>>num>>name>>gen>>age>>lab>>job1;
               if (CheckNum(num,t,e,a,ta)||num==e[i].getNum())
               {  
                  e[i].modify(num,name,gen,age,lab,job1);
                  cout<<"修改成功"<<endl;
                  return;
               }
               else{
                  cout<<"修改失败，工号重复"<<endl;
                  return;
               }
         }
      }
      for (int i=0;i<a.size();i++){//在行政中查找
         if (name==a[i].getName())
         {
            cout<<"请输入修改后行政的工号、姓名、性别[1男 0女]、年龄、职务、办公室"<<endl;
            cin>>num>>name>>gen>>age>>job>>off;
               if (CheckNum(num,t,e,a,ta)||num==a[i].getNum())
               {  
                  a[i].modify(num,name,gen,age,job,off);
                  cout<<"修改成功"<<endl;
                  return;
               }
               else{
                  cout<<"修改失败，工号重复"<<endl;
                  return;
               }
         }
      }
      for (int i=0;i<ta.size();i++){//在教师行政中查找
         if (name==ta[i].getName())
         {
            cout<<"请输入修改后教师兼行政的工号、姓名、性别[1男 0女]、年龄、系部、专业、职称、职务、办公室"<<endl;
            cin>>num>>name>>gen>>age>>fac>>spe>>job>>job1>>off;
               if (CheckNum(num,t,e,a,ta)||num==ta[i].getNum())
               {  
                  ta[i].modify(num,name,gen,age,fac,spe,job,job1,off);
                  cout<<"修改成功"<<endl;
                  return;
               }
               else{
                  cout<<"修改失败，工号重复"<<endl;
                  return;
               }
            }
         }
      }
}
void Modify(vector<Teacher> &t, vector<Experimenter> &e, vector<Admin> &a, vector<TeacherAdmin> &ta){//修改人员信息
//选择修改的方式来调用不同的修改函数
   int choice;
   cout<<"请选择修改方式：1.按工号修改 2.按姓名修改"<<endl;
   cin>>choice;
   while (cin.fail()){//判断输入是否为整数
      cin.clear();//清除错误状态，以便重新输入
      cin.sync();//清空输入流中的内容
      cout<<"输入错误，请重新输入"<<endl;
      cin>>choice;
   }
   switch (choice){
      case 1:ModifyAccordingNum(t,e,a,ta);break;
      case 2:ModifyAccordingName(t,e,a,ta);break;
      default:cout<<"输入错误"<<endl;
   }
}
//遍历输出每个人的数据
//遍历输出每个人的数据
void PrintAll(vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){
   if (t.size()==0)
      cout<<"无教师信息"<<endl;
   else{
      cout<<"教师信息如下："<<endl;
      for (int i=0;i<t.size();i++){
         t[i].show();
      }
   }
   if (e.size()==0)
      cout<<"无实验员信息"<<endl;
   else{
      cout<<"实验员信息如下："<<endl;
      for (int i=0;i<e.size();i++){
         e[i].show();
      }
   }
   if (a.size()==0)
      cout<<"无行政信息"<<endl;
   else{
      cout<<"行政信息如下："<<endl;
      for (int i=0;i<a.size();i++){
         a[i].show();
      }
   }
   if (ta.size()==0)
      cout<<"无教师兼行政信息"<<endl;
   else{
      cout<<"教师兼行政信息如下："<<endl;
      for (int i=0;i<ta.size();i++){
         ta[i].show();
      }
   }
}
//将每个人的数据使用jsoncpp库写入文件中
void WriteToFile(vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){
   Json::Value root;//定义数组对象根节点
   Json::Value teacher;//定义teacher数组对象，以下同理
   Json::Value experimenter;
   Json::Value admin;
   Json::Value teacheradmin;
   Json::StyledWriter writer;//定义写入器
   //将json数据编码格式设置为gbk2312
   ofstream out;
   out.open("data.json");//默认存储在当前目录下data.json文件中
   for (int i=0;i<t.size();i++){
      teacher[i]["num"]=t[i].getNum();
      teacher[i]["name"]=t[i].getName();
      teacher[i]["gen"]=t[i].getGender();
      teacher[i]["age"]=t[i].getAge();
      teacher[i]["fac"]=t[i].getFaculty();
      teacher[i]["spe"]=t[i].getSpeciality();
      teacher[i]["job"]=t[i].getJobTitle();
   }
   for (int i=0;i<e.size();i++){
      experimenter[i]["num"]=e[i].getNum();
      experimenter[i]["name"]=e[i].getName();
      experimenter[i]["gen"]=e[i].getGender();
      experimenter[i]["age"]=e[i].getAge();
      experimenter[i]["lab"]=e[i].getLaboratory();
      experimenter[i]["job"]=e[i].getJob();
   }
   for (int i=0;i<a.size();i++){
      admin[i]["num"]=a[i].getNum();
      admin[i]["name"]=a[i].getName();
      admin[i]["gen"]=a[i].getGender();
      admin[i]["age"]=a[i].getAge();
      admin[i]["job"]=a[i].getJob();
      admin[i]["off"]=a[i].getOfficelocation();
   }
   for (int i=0;i<ta.size();i++){
      teacheradmin[i]["num"]=ta[i].getNum();
      teacheradmin[i]["name"]=ta[i].getName();
      teacheradmin[i]["gen"]=ta[i].getGender();
      teacheradmin[i]["age"]=ta[i].getAge();
      teacheradmin[i]["fac"]=ta[i].getFaculty();
      teacheradmin[i]["spe"]=ta[i].getSpeciality();
      teacheradmin[i]["job"]=ta[i].getJob();
      teacheradmin[i]["job1"]=ta[i].getJobTitle();
      teacheradmin[i]["off"]=ta[i].getOfficelocation();
   }
   root["teacher"]=teacher;
   root["experimenter"]=experimenter;
   root["admin"]=admin;
   root["teacheradmin"]=teacheradmin;
   out<<writer.write(root);
   out.close();
   cout<<"保存成功"<<endl;
   /*用注释列出json的大概文件结构
   {
   "teacher":[
      {
         "num":"001",
         "name":"张三",
         "gen":"男",
         "age":"30",
         "fac":"计算机学院",
         "spe":"计算机科学与技术",
         "job":"教授"
      }
   ],
   "experimenter":[
      {
         "num":"003",
         "name":"王五",
         "gen":"男",
         "age":"30",
         "lab":"计算机实验室",
         "job":"实验员"
      }
   ],
   "admin":[
      {
         "num":"005",
         "name":"孙七",
         "gen":"男",
         "age":"30",
         "job":"行政",
         "off":"行政楼"
      }
   ],
   "teacheradmin":[
      {
         "num":"007",
         "name":"吴九",
         "gen":"男",
         "age":"30",
         "fac":"计算机学院",
         "spe":"计算机科学与技术",
         "job":"行政",
         "job1":"教授",
         "off":"行政楼"
      }
   ]
   }
   */
}
//将json文件中的数据读取出来,并根据不同的职位分别存入不同的vector中
void ReadFromFile(vector<Teacher> &t, vector<Experimenter> &e, vector<Admin> &a, vector<TeacherAdmin> &ta){
   t.clear();
   e.clear();
   a.clear();
   ta.clear();
   Json::Reader reader;
   Json::Value root;
   ifstream in;
   in.open("data.json");
   cout<<"开始读取文件"<<endl;
   if (!in.is_open()){
      cout<<"文件打开失败"<<endl;
      return;
   }
   if (reader.parse(in,root)){
      for (int i=0;i<root["teacher"].size();i++){
         Teacher teacher;
         teacher.modify(root["teacher"][i]["num"].asString(),root["teacher"][i]["name"].asString(),root["teacher"][i]["gen"].asInt(),root["teacher"][i]["age"].asInt(),root["teacher"][i]["fac"].asString(),root["teacher"][i]["spe"].asString(),root["teacher"][i]["job"].asString());
         t.push_back(teacher);
      }
      }
      for (int i=0;i<root["experimenter"].size();i++){
         Experimenter experimenter;
         experimenter.modify(root["experimenter"][i]["num"].asString(),root["experimenter"][i]["name"].asString(),root["experimenter"][i]["gen"].asInt(),root["experimenter"][i]["age"].asInt(),root["experimenter"][i]["lab"].asString(),root["experimenter"][i]["job"].asString());
         e.push_back(experimenter);
      }
      for (int i=0;i<root["admin"].size();i++){
         Admin admin;
         admin.modify(root["admin"][i]["num"].asString(),root["admin"][i]["name"].asString(),root["admin"][i]["gen"].asInt(),root["admin"][i]["age"].asInt(),root["admin"][i]["job"].asString(),root["admin"][i]["off"].asString());
         a.push_back(admin);
      }
      for (int i=0;i<root["teacheradmin"].size();i++){
         TeacherAdmin teacheradmin;
         teacheradmin.modify(root["teacheradmin"][i]["num"].asString(),root["teacheradmin"][i]["name"].asString(),root["teacheradmin"][i]["gen"].asInt(),root["teacheradmin"][i]["age"].asInt(),root["teacheradmin"][i]["fac"].asString(),root["teacheradmin"][i]["spe"].asString(),root["teacheradmin"][i]["job"].asString(),root["teacheradmin"][i]["job1"].asString(),root["teacheradmin"][i]["off"].asString());
         ta.push_back(teacheradmin);
      }
   in.close();
   cout<<"读取成功"<<endl;
}

int main(){
system("chcp 936");//设置控制台输出为中文
int choice;
vector<Teacher> t;
vector<Experimenter> e;
vector<Admin> a;
vector<TeacherAdmin> ta;
while (1){
   system ("cls");
   cout <<"-----------------高校人员管理系统-----------------"<< endl;
   cout<<"欢迎使用高校人员管理系统"<<endl;
   cout<<"1.添加新员工"<<endl;
   cout<<"2.删除员工"<<endl;
   cout<<"3.修改员工信息"<<endl;
   cout<<"4.查询员工信息"<<endl;
   cout<<"5.统计员工人数"<<endl;
   cout<<"6.遍历输出所有员工信息"<<endl;
   cout<<"7.保存员工信息到当前目录下data.json文件中"<<endl;
   cout<<"8.从当前目录下的data.json文件中读取员工信息"<<endl;
   cout<<"9.退出"<<endl;
   cout<<"----------------------------------------------"<<endl;
   cout<<"请输入您的选择："<<endl;
   cin>>choice;
   //当输入的不是整数时，会出现死循环
   while (cin.fail()){//判断输入是否为整数
      cin.clear();//清除错误状态，以便重新输入
      cin.sync();//清空输入流中的内容
      cout<<"输入错误，请重新输入"<<endl;
      cin>>choice;
   }
   switch (choice){
      case 1:InsertNew(t,e,a,ta);break;
      case 2:Delete(t,e,a,ta);break;
      case 3:Modify(t,e,a,ta);break;
      case 4:Search(t,e,a,ta);break;
      case 5:CountSum(t,e,a,ta);break;
      case 6:PrintAll(t,e,a,ta);break;
      case 7:WriteToFile(t,e,a,ta);break;
      case 8:ReadFromFile(t,e,a,ta);break; 
      case 9:system ("cls");exit(0);
      default:{cout<<"输入错误，请重新输入"<<endl;}
   }
   system("pause");
}
return 0;
}