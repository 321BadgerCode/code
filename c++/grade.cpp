//badger
#include <iostream>

using namespace std;

class grade{
private:
	float get_percent(const float a1){
		float b1=a1;

		if(a1>1){b1/=100;}

		return b1;
	}
public:
	float q1=0;
	float q2=0;
	float grade_goal=0;
	float q_percent=0;
	float grade_percent=0;
	float min_pass_grade=0;
	float sem_grade=0;
	grade(const float q11,const float q21,const float grade_goal1=70,const float q_percent1=40,const float grade_percent1=20){
		q1=q11;
		q2=q21;
		grade_goal=grade_goal1;
		q_percent=q_percent1;
		grade_percent=grade_percent1;
	}
	float get_min_pass_grade(){//.4(q1)+.4(q2)+.2(g)>=grade_goal
		float b1=0;
		float sem=(get_percent(q_percent)*q1)+(get_percent(q_percent)*q2);

		b1=grade_goal-sem;
		b1/=get_percent(grade_percent);

		min_pass_grade=b1;

		return b1;
	}
	float get_sem_grade(){float b1=(q1+q2)/2;sem_grade=b1;return b1;}
	float get_new_sem_grade(){float b1=0;b1=((get_percent(q_percent)*q1)+(get_percent(q_percent)*q2)+(get_percent(grade_percent)*min_pass_grade));return b1;}
};

string get_line(){return "-------------------------";}

int main(){
	string q1="";
	cout<<"grade in 1st quarter: ";
	cin>>q1;

	string q2="";
	cout<<"grade in 2nd quarter: ";
	cin>>q2;

	grade* g1=new grade(stof(q1),stof(q2));

	cout<<"quarter percent: "<<g1->q_percent<<endl;
	cout<<"grade percent: "<<g1->grade_percent<<endl;

	cout<<get_line()<<endl;

	cout<<"current sem. grade: "<<g1->get_sem_grade()<<endl;

	cout<<get_line()<<endl;

	cout<<"grade goal: grade needed on midterm to get grade goal"<<endl;

	cout<<get_line()<<endl;

	for(int a=0;a<=100;a+=10){
		g1->grade_goal=a;
		cout<<a<<"%: "<<g1->get_min_pass_grade()<<"%"<<endl;
	}

	system("pause");

	return 0;
}
//get slope of semester grade vs min pass grade(ex. 70,86.7)