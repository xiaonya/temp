#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "jsoncpp.cpp"
#include <iostream>
#include <fstream>
using namespace std;
class Person//��Ϊ����
{
   private:
      int Type;// 1bytes,1Ϊ��ʦ��2Ϊʵ��Ա��3Ϊ������4Ϊ��ʦ������
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
class Teacher : public Person//��ʦΪ������
{
   private:
      string Faculty;//ϵ��
      string Speciality;//רҵ
      string JobTitle;//ְ��
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
      int count(int Ty, vector<Teacher> p){//��T=1���������������Ty=2�������Ա����������Ty=3�����ŮԱ������
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
         cout << "Type:" << "1.��ʦ" << endl;
         cout << "Num:" << getNum() << endl;
         cout << "Name:" << getName() << endl;
         cout << "Gender:"<<((getGender())?("��Ա��"):("ŮԱ��"))<< endl;
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
class Experimenter : public Person//ʵ��ԱΪ������
{
   private:
      string Laboratory;//xxʵ����
      string Job;//ְ��
   public:
      Experimenter(string num = "123456", string name = "aaaa", int gen = 1, int age = 233, string lab = "", string job = "") : Person(2, num, name, gen, age)
      {
         Laboratory = lab;
         Job = job;
      }
      string getLaboratory() { return Laboratory; }
      string getJob() { return Job; }
      int count(int Ty, vector<Experimenter> &p){//��T=1���������������Ty=2�������Ա����������Ty=3�����ŮԱ������
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
         cout << "Type:" << "2.ʵ��Ա" << endl;
         cout << "Num:" << getNum() << endl;
         cout << "Name:" << getName() << endl;
         cout << "Gender:"<<((getGender())?("��Ա��"):("ŮԱ��"))<< endl;
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
class Admin : public Person//����Ϊ������
{
   private:
      string Job;//ְ��
      string Officelocation;//�칫�ص�
   public:
      Admin(string num="123456", string name = "aaaa", int gen = 1, int age=233, string job="", string off="") : Person(3, num, name, gen, age)
      {
         Job = job;
         Officelocation = off;
      }
      string getJob() { return Job; }
      string getOfficelocation() { return Officelocation; }
      int count(int Ty, vector<Admin> &p){//��T=1���������������Ty=2�������Ա����������Ty=3�����ŮԱ������
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
         cout << "Type:" << "3.����" << endl;
         cout << "Num:" << getNum() << endl;
         cout << "Name:" << getName() << endl;
         cout << "Gender:"<<((getGender())?("��Ա��"):("ŮԱ��"))<< endl;
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
class TeacherAdmin : public Person//��ʦ������Ϊ������
{
   private:
      string Faculty;//ϵ��
      string Speciality;//רҵ
      string JobTitle;//ְ��
      string Job;//ְ��
      string Officelocation;//�칫�ص�
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
      int count(int Ty, vector<TeacherAdmin> &p){//��Ty=1���������������Ty=2�������Ա����������Ty=3�����ŮԱ������
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
         cout << "Type:" << "4.��ʦ������" << endl;
         cout << "Num:" << getNum() << endl;
         cout << "Name:" << getName() << endl;
         cout << "Gender:"<<((getGender())?("��Ա��"):("ŮԱ��"))<< endl;
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

int CheckName(string Name, vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){//�ڲ�����Ԫ��ʱ�ж������Ƿ���ڣ��������򷵻�0�����򷵻�1
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

int CheckNum(string Num, vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){//�ڲ�����Ԫ��ʱ������Ψһ��,���ظ��򷵻�0�����򷵻�1
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
void InsertNew(vector<Teacher> &t, vector<Experimenter> &e, vector<Admin> &a, vector<TeacherAdmin> &ta){//��������
   int i;
   cout<<"������Ա����ݶ�Ӧ�����֣�1.��ʦ 2.ʵ��Ա 3.���� 4.��ʦ������"<<endl;
   cin>>i;
   while (cin.fail()){//�ж������Ƿ�Ϊ����
      cin.clear();//�������״̬���Ա���������
      cin.sync();//����������е�����
      cout<<"�����������������"<<endl;
      cin>>i;
   }
   int age,gen;//gen�Ա� 1�� 0Ů
   string num, name,fac,spe,job,lab,job1,off;//facϵ�� speרҵ jobְ�� labʵ���� job1ְ�� off�칫�ص�
   switch (i)
   {
   case 1:{
      cout<<"�������ʦ�Ĺ��š��������Ա�[1�� 0Ů]�����䡢ϵ����רҵ��ְ��"<<endl;
      cin>>num>>name>>gen>>age>>fac>>spe>>job;
      if (CheckNum(num, t, e, a, ta))
      {
         Teacher Teacher_temp(num, name, gen, age, fac, spe, job);
         t.push_back(Teacher_temp);
         cout << "����������ɹ�" << endl;
      }
      else
         cout << "�ù����Ѵ���,�����������������������" << endl;
      break;}

   case 2:{
      cout<<"������ʵ��Ա�Ĺ��š��������Ա�[1�� 0Ů]�����䡢ʵ���ҡ�ְ��"<<endl;
      cin>>num>>name>>gen>>age>>lab>>job1;
      if (CheckNum(num, t, e, a, ta))
      {
         Experimenter Experimenter_temp(num, name, gen, age, lab, job1);
         e.push_back(Experimenter_temp);
         cout << "����������ɹ�" << endl;
      }
      else
         cout << "�ù����Ѵ���,�����������������������" << endl;
      break;}

   case 3:{
      cout<<"�����������Ĺ��š��������Ա�[1�� 0Ů]�����䡢ְ�񡢰칫�ص�"<<endl;
      cin>>num>>name>>gen>>age>>job1>>off;
      if (CheckNum(num, t, e, a, ta))
      {
         Admin Admin_temp(num, name, gen, age, job1, off);
         a.push_back(Admin_temp);
         cout << "����������ɹ�" << endl;
      }
      else
         cout << "�ù����Ѵ���,�����������������������" << endl;
      break;}

   case 4:{
      cout<<"�������ʦ�������Ĺ��š��������Ա�[1�� 0Ů]�����䡢ϵ����רҵ��(��ʦ)ְ�ơ���������ְ�񡢰칫��"<<endl;
      cin>>num>>name>>gen>>age>>fac>>spe>>job>>off>>job1;
      if (CheckNum(num, t, e, a, ta))
      {
         TeacherAdmin TeacherAdmin_temp(num, name, gen, age, fac, spe, job, job1, off);
         ta.push_back(TeacherAdmin_temp);
         cout << "����������ɹ�" << endl;
      }
      else
         cout << "�ù����Ѵ���,�����������������������" << endl;
      break;}
   default:
      cout<<"���������󣬻ص�������"<<endl;
      break;
   }
}

void CountSum(vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){//ͳ������
      cout<<"��ʦ������Ϊ��"<<t[0].count(1,t)<<endl;
      cout<<"ʵ��Ա������Ϊ��"<<e[0].count(1,e)<<endl;
      cout<<"����������Ϊ��"<<a[0].count(1,a)<<endl;
      cout<<"��ʦ������Ա��������Ϊ��"<<ta[0].count(1,ta)<<endl;
      cout<<"������Ϊ��"<<t[0].count(1,t)+e[0].count(1,e)+a[0].count(1,a)+ta[0].count(1,ta)<<endl;
      cout<<"��Ա��������Ϊ��"<<t[0].count(2,t)+e[0].count(2,e)+a[0].count(2,a)+ta[0].count(2,ta)<<endl;
      cout<<"ŮԱ��������Ϊ��"<<t[0].count(3,t)+e[0].count(3,e)+a[0].count(3,a)+ta[0].count(3,ta)<<endl;
}

//���ڲ��ҹ��ܵĺ���������һ���������飬�����д�ŵ��ǲ��ҵ���Ԫ�ص��±꣬δ��ģ��ƥ�䣬����Ҫģ��ƥ�书����Ҫ����������ʽ�Ŀ�
int NameSearchCore(string Name,int (&Res)[100], vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){//���Ʋ��Һ����ĺ��ĺ�����NumΪ��Ų��ҽ��������,NameΪ���ҵ�����
   int n=0,x,y,i;//��Ų��ҽ�����±�,xΪ����ı�־��yΪ����������±�,nΪ���ҵ��ĸ���
   for(i=0;i<t.size();i++){//�ڽ�ʦ�в���
      if(Name==t[i].getName()){
         x=2*n;
         y=2*n+1;
         Res[x]=1;
         Res[y]=i;
         n++;
      }
   }
   for(i=0;i<e.size();i++){//��ʵ��Ա�в���
      if(Name==e[i].getName()){
         x=2*n;
         y=2*n+1;
         Res[x]=2;
         Res[y]=i;
         n++;
      }
   }
   for(i=0;i<a.size();i++){//��������Ա�в���
      if(Name==a[i].getName()){
         x=2*n;
         y=2*n+1;
         Res[x]=3;
         Res[y]=i;
         n++;
      }
   }
   for(i=0;i<ta.size();i++){//�ڽ�ʦ��������Ա�в���
      if(Name==ta[i].getName()){
         x=2*n;
         y=2*n+1;
         Res[x]=4;
         Res[y]=i;
         n++;
      }
   }
   return n;//���ز��ҽ���ĸ���
}
int NumSearchCore(string Num,int (&Res)[100], vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){//��Ų��Һ����ĺ��ĺ�����NumΪ��Ų��ҽ��������,NumΪ���ҵı��
   int n=0,x,y,i;//��Ų��ҽ�����±�,xΪ����ı�־��yΪ����������±�,nΪ���ҵ��ĸ���
   for(i=0;i<t.size();i++){//�ڽ�ʦ�в���
      if(Num==t[i].getNum()){
         x=2*n;
         y=2*n+1;
         Res[x]=1;
         Res[y]=i;
         n++;
      }
   }
   for(i=0;i<e.size();i++){//��ʵ��Ա�в���
      if(Num==e[i].getNum()){
         x=2*n;
         y=2*n+1;
         Res[x]=2;
         Res[y]=i;
         n++;
      }
   }
   for(i=0;i<a.size();i++){//��������Ա�в���
      if(Num==a[i].getNum()){
         x=2*n;
         y=2*n+1;
         Res[x]=3;
         Res[y]=i;
         n++;
      }
   }
   for(i=0;i<ta.size();i++){//�ڽ�ʦ��������Ա�в���
      if(Num==ta[i].getNum()){
         x=2*n;
         y=2*n+1;
         Res[x]=4;
         Res[y]=i;
         n++;
      }
   }
   return n;//���ز��ҽ���ĸ���
}
void Search(vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){
   int flag;//��Ų��ҷ�ʽ�ı�־
   cout<<"�����ձ�Ų���������1����������������������2"<<endl;
   cin>>flag;
   while (cin.fail()){//�ж������Ƿ�Ϊ����
      cin.clear();//�������״̬���Ա���������
      cin.sync();//����������е�����
      cout<<"�����������������"<<endl;
      cin>>flag;
   }
   switch (flag)
   {
      case 1:{//���ձ�Ų���
         int Res[100];//��Ų��ҽ��������
         int count;//��Ų��ҽ���ĸ���
         string Num;
         cout<<"������Ҫ���ҵı��"<<endl;
         cin>>Num;
         count=NumSearchCore(Num,Res,t,e,a,ta);
         if(count==0){//û�в��ҵ����
            cout<<"û�в��ҵ����"<<endl;
            break;
         }
         for (int i=0;i<count;i++){//������ҽ��
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
      case 2:{//������������
         int Res[100];//��Ų��ҽ��������
         int count;//��Ų��ҽ���ĸ���
         string Name;
         cout<<"������Ҫ���ҵ�����"<<endl;
         cin>>Name;
         count=NameSearchCore(Name,Res,t,e,a,ta);
         if (count==0)//û�в��ҵ����
         {
            cout<<"û�в��ҵ����"<<endl;
            break;
         }
         for (int i=0;i<count;i++){//������ҽ��
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
         cout<<"������󣬻ص����˵�"<<endl;
         break;
   }



}
//����ɾ���ĺ���
void Delete(vector<Teacher> &t, vector<Experimenter> &e, vector<Admin> &a, vector<TeacherAdmin> &ta){//ɾ������,����ɾ����һ�����������ԣ�ɾ��ֻ��ͨ��Ψһ�ı�������в���
   cout<<"������Ҫɾ������Ա�ı��"<<endl;
   string Num;
   cin>>Num;
   if (CheckNum(Num,t,e,a,ta))
   {
      cout<<"��Ų����ڣ�ɾ��ʧ��"<<endl;
      return;
   }
   else{//��ʼִ��ɾ������
      for (int i=0;i<t.size();i++){//�ڽ�ʦ�в���
         if (Num==t[i].getNum())
         {
            t.erase(t.begin()+i);
            cout<<"ɾ���ɹ�"<<endl;
            return;
         }
      }
      for (int i=0;i<e.size();i++){//��ʵ��Ա�в���
         if (Num==e[i].getNum())
         {
            e.erase(e.begin()+i);
            cout<<"ɾ���ɹ�"<<endl;
            return;
         }
      }
      for (int i=0;i<a.size();i++){//�������в���
         if (Num==a[i].getNum())
         {
            a.erase(a.begin()+i);
            cout<<"ɾ���ɹ�"<<endl;
            return;
         }
      }
      for (int i=0;i<ta.size();i++){//�ڽ�ʦ�������в���
         if (Num==ta[i].getNum())
         {
            ta.erase(ta.begin()+i);
            cout<<"ɾ���ɹ�"<<endl;
            return;
         }
      }
   }
}

//�����޸ĵĺ������޸�ǰ�ȼ����Ψһ�ԣ��޸ĺ��ټ����Ψһ��
void ModifyAccordingNum(vector<Teacher> &t, vector<Experimenter> &e, vector<Admin> &a, vector<TeacherAdmin> &ta){
   cout<<"������Ҫ�޸ĵ���Ա�ı��"<<endl;
   int age,gen;//gen�Ա� 1�� 0Ů
   string num, name,fac,spe,job,lab,job1,off,PastNum;
   cin>>num;
   PastNum=num;
   if (CheckNum(num,t,e,a,ta))
   {
      cout<<"��Ų����ڣ��Ҳ��������޸�ʧ��"<<endl;
      return;
   }
   else{//��ʼִ���޸Ĳ���
      for (int i=0;i<t.size();i++){//�ڽ�ʦ�в���
         if (num==t[i].getNum()){
            cout<<"�������޸ĺ��ʦ�Ĺ��š��������Ա�[1�� 0Ů]�����䡢ϵ����רҵ��ְ��"<<endl;
            cin>>num>>name>>gen>>age>>fac>>spe>>job;
               if (CheckNum(num,t,e,a,ta)||num==PastNum)
               {  
                  t[i].modify(num,name,gen,age,fac,spe,job);
                  cout<<"�޸ĳɹ�"<<endl;
                  return;
               }
               else{
                  cout<<"�޸�ʧ�ܣ������ظ�"<<endl;
                  return;
               }
            }
      }
      for (int i=0;i<e.size();i++){//��ʵ��Ա�в���
         if (num==e[i].getNum())
         {
            cout<<"�������޸ĺ�ʵ��Ա�Ĺ��š��������Ա�[1�� 0Ů]�����䡢ʵ���ҡ�ְ��"<<endl;
            cin>>num>>name>>gen>>age>>lab>>job1;
               if (CheckNum(num,t,e,a,ta)||num==PastNum)
               {  
                  e[i].modify(num,name,gen,age,lab,job1);
                  cout<<"�޸ĳɹ�"<<endl;
                  return;
               }
               else{
                  cout<<"�޸�ʧ�ܣ������ظ�"<<endl;
                  return;
               }
         }
      }
      for (int i=0;i<a.size();i++){//�������в���
         if (num==a[i].getNum())
         {
            cout<<"�������޸ĺ������Ĺ��š��������Ա�[1�� 0Ů]�����䡢ְ�񡢰칫��"<<endl;
            cin>>num>>name>>gen>>age>>job>>off;
               if (CheckNum(num,t,e,a,ta)||num==PastNum)
               {  
                  a[i].modify(num,name,gen,age,job,off);
                  cout<<"�޸ĳɹ�"<<endl;
                  return;
               }
               else{
                  cout<<"�޸�ʧ�ܣ������ظ�"<<endl;
                  return;
               }
         }
      }
      for (int i=0;i<ta.size();i++){//�ڽ�ʦ�������в���
         if (num==ta[i].getNum())
         {
            cout<<"�������޸ĺ��ʦ�������Ĺ��š��������Ա�[1�� 0Ů]�����䡢ϵ����רҵ��ְ�ơ�ְ�񡢰칫��"<<endl;
            cin>>num>>name>>gen>>age>>fac>>spe>>job>>job1>>off;
               if (CheckNum(num,t,e,a,ta)||num==PastNum)
               {  
                  ta[i].modify(num,name,gen,age,fac,spe,job,job1,off);
                  cout<<"�޸ĳɹ�"<<endl;
                  return;
               }
               else{
                  cout<<"�޸�ʧ�ܣ������ظ�"<<endl;
                  return;
               }
            }
         }
      }
}
void ModifyAccordingName(vector<Teacher> &t, vector<Experimenter> &e, vector<Admin> &a, vector<TeacherAdmin> &ta){
   cout<<"������Ҫ�޸ĵ���Ա������"<<endl;
   int age,gen;//gen�Ա� 1�� 0Ů
   string num, name,fac,spe,job,lab,job1,off,PastName;
   cin>>name;
   PastName=name;
   if (CheckName(name,t,e,a,ta))
   {
      cout<<"���������ڣ��Ҳ��������޸�ʧ��"<<endl;
      return;
   }
   else{//��ʼִ���޸Ĳ���
      for (int i=0;i<t.size();i++){//�ڽ�ʦ�в���
         if (name==t[i].getName()){
            cout<<"�������޸ĺ��ʦ�Ĺ��š��������Ա�[1�� 0Ů]�����䡢ϵ����רҵ��ְ��"<<endl;
            cin>>num>>name>>gen>>age>>fac>>spe>>job;
               if (CheckNum(num,t,e,a,ta)||num==t[i].getNum())
               {  
                  t[i].modify(num,name,gen,age,fac,spe,job);
                  cout<<"�޸ĳɹ�"<<endl;
                  return;
               }
               else{
                  cout<<"�޸�ʧ�ܣ������ظ�"<<endl;
                  return;
               }
            }
      }
      for (int i=0;i<e.size();i++){//��ʵ��Ա�в���
         if (name==e[i].getName())
         {
            cout<<"�������޸ĺ�ʵ��Ա�Ĺ��š��������Ա�[1�� 0Ů]�����䡢ʵ���ҡ�ְ��"<<endl;
            cin>>num>>name>>gen>>age>>lab>>job1;
               if (CheckNum(num,t,e,a,ta)||num==e[i].getNum())
               {  
                  e[i].modify(num,name,gen,age,lab,job1);
                  cout<<"�޸ĳɹ�"<<endl;
                  return;
               }
               else{
                  cout<<"�޸�ʧ�ܣ������ظ�"<<endl;
                  return;
               }
         }
      }
      for (int i=0;i<a.size();i++){//�������в���
         if (name==a[i].getName())
         {
            cout<<"�������޸ĺ������Ĺ��š��������Ա�[1�� 0Ů]�����䡢ְ�񡢰칫��"<<endl;
            cin>>num>>name>>gen>>age>>job>>off;
               if (CheckNum(num,t,e,a,ta)||num==a[i].getNum())
               {  
                  a[i].modify(num,name,gen,age,job,off);
                  cout<<"�޸ĳɹ�"<<endl;
                  return;
               }
               else{
                  cout<<"�޸�ʧ�ܣ������ظ�"<<endl;
                  return;
               }
         }
      }
      for (int i=0;i<ta.size();i++){//�ڽ�ʦ�����в���
         if (name==ta[i].getName())
         {
            cout<<"�������޸ĺ��ʦ�������Ĺ��š��������Ա�[1�� 0Ů]�����䡢ϵ����רҵ��ְ�ơ�ְ�񡢰칫��"<<endl;
            cin>>num>>name>>gen>>age>>fac>>spe>>job>>job1>>off;
               if (CheckNum(num,t,e,a,ta)||num==ta[i].getNum())
               {  
                  ta[i].modify(num,name,gen,age,fac,spe,job,job1,off);
                  cout<<"�޸ĳɹ�"<<endl;
                  return;
               }
               else{
                  cout<<"�޸�ʧ�ܣ������ظ�"<<endl;
                  return;
               }
            }
         }
      }
}
void Modify(vector<Teacher> &t, vector<Experimenter> &e, vector<Admin> &a, vector<TeacherAdmin> &ta){//�޸���Ա��Ϣ
//ѡ���޸ĵķ�ʽ�����ò�ͬ���޸ĺ���
   int choice;
   cout<<"��ѡ���޸ķ�ʽ��1.�������޸� 2.�������޸�"<<endl;
   cin>>choice;
   while (cin.fail()){//�ж������Ƿ�Ϊ����
      cin.clear();//�������״̬���Ա���������
      cin.sync();//����������е�����
      cout<<"�����������������"<<endl;
      cin>>choice;
   }
   switch (choice){
      case 1:ModifyAccordingNum(t,e,a,ta);break;
      case 2:ModifyAccordingName(t,e,a,ta);break;
      default:cout<<"�������"<<endl;
   }
}
//�������ÿ���˵�����
//�������ÿ���˵�����
void PrintAll(vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){
   if (t.size()==0)
      cout<<"�޽�ʦ��Ϣ"<<endl;
   else{
      cout<<"��ʦ��Ϣ���£�"<<endl;
      for (int i=0;i<t.size();i++){
         t[i].show();
      }
   }
   if (e.size()==0)
      cout<<"��ʵ��Ա��Ϣ"<<endl;
   else{
      cout<<"ʵ��Ա��Ϣ���£�"<<endl;
      for (int i=0;i<e.size();i++){
         e[i].show();
      }
   }
   if (a.size()==0)
      cout<<"��������Ϣ"<<endl;
   else{
      cout<<"������Ϣ���£�"<<endl;
      for (int i=0;i<a.size();i++){
         a[i].show();
      }
   }
   if (ta.size()==0)
      cout<<"�޽�ʦ��������Ϣ"<<endl;
   else{
      cout<<"��ʦ��������Ϣ���£�"<<endl;
      for (int i=0;i<ta.size();i++){
         ta[i].show();
      }
   }
}
//��ÿ���˵�����ʹ��jsoncpp��д���ļ���
void WriteToFile(vector<Teacher> t, vector<Experimenter> e, vector<Admin> a, vector<TeacherAdmin> ta){
   Json::Value root;//�������������ڵ�
   Json::Value teacher;//����teacher�����������ͬ��
   Json::Value experimenter;
   Json::Value admin;
   Json::Value teacheradmin;
   Json::StyledWriter writer;//����д����
   //��json���ݱ����ʽ����Ϊgbk2312
   ofstream out;
   out.open("data.json");//Ĭ�ϴ洢�ڵ�ǰĿ¼��data.json�ļ���
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
   cout<<"����ɹ�"<<endl;
   /*��ע���г�json�Ĵ���ļ��ṹ
   {
   "teacher":[
      {
         "num":"001",
         "name":"����",
         "gen":"��",
         "age":"30",
         "fac":"�����ѧԺ",
         "spe":"�������ѧ�뼼��",
         "job":"����"
      }
   ],
   "experimenter":[
      {
         "num":"003",
         "name":"����",
         "gen":"��",
         "age":"30",
         "lab":"�����ʵ����",
         "job":"ʵ��Ա"
      }
   ],
   "admin":[
      {
         "num":"005",
         "name":"����",
         "gen":"��",
         "age":"30",
         "job":"����",
         "off":"����¥"
      }
   ],
   "teacheradmin":[
      {
         "num":"007",
         "name":"���",
         "gen":"��",
         "age":"30",
         "fac":"�����ѧԺ",
         "spe":"�������ѧ�뼼��",
         "job":"����",
         "job1":"����",
         "off":"����¥"
      }
   ]
   }
   */
}
//��json�ļ��е����ݶ�ȡ����,�����ݲ�ͬ��ְλ�ֱ���벻ͬ��vector��
void ReadFromFile(vector<Teacher> &t, vector<Experimenter> &e, vector<Admin> &a, vector<TeacherAdmin> &ta){
   t.clear();
   e.clear();
   a.clear();
   ta.clear();
   Json::Reader reader;
   Json::Value root;
   ifstream in;
   in.open("data.json");
   cout<<"��ʼ��ȡ�ļ�"<<endl;
   if (!in.is_open()){
      cout<<"�ļ���ʧ��"<<endl;
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
   cout<<"��ȡ�ɹ�"<<endl;
}

int main(){
system("chcp 936");//���ÿ���̨���Ϊ����
int choice;
vector<Teacher> t;
vector<Experimenter> e;
vector<Admin> a;
vector<TeacherAdmin> ta;
while (1){
   system ("cls");
   cout <<"-----------------��У��Ա����ϵͳ-----------------"<< endl;
   cout<<"��ӭʹ�ø�У��Ա����ϵͳ"<<endl;
   cout<<"1.�����Ա��"<<endl;
   cout<<"2.ɾ��Ա��"<<endl;
   cout<<"3.�޸�Ա����Ϣ"<<endl;
   cout<<"4.��ѯԱ����Ϣ"<<endl;
   cout<<"5.ͳ��Ա������"<<endl;
   cout<<"6.�����������Ա����Ϣ"<<endl;
   cout<<"7.����Ա����Ϣ����ǰĿ¼��data.json�ļ���"<<endl;
   cout<<"8.�ӵ�ǰĿ¼�µ�data.json�ļ��ж�ȡԱ����Ϣ"<<endl;
   cout<<"9.�˳�"<<endl;
   cout<<"----------------------------------------------"<<endl;
   cout<<"����������ѡ��"<<endl;
   cin>>choice;
   //������Ĳ�������ʱ���������ѭ��
   while (cin.fail()){//�ж������Ƿ�Ϊ����
      cin.clear();//�������״̬���Ա���������
      cin.sync();//����������е�����
      cout<<"�����������������"<<endl;
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
      default:{cout<<"�����������������"<<endl;}
   }
   system("pause");
}
return 0;
}