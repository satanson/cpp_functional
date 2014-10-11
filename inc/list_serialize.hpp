#include<cppstdlib.hpp>
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};

// Definition for an interval.
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
	friend ostream& operator<<(ostream& out,const Interval& interval){
		out<<"["<<interval.start<<","<<interval.end<<"]";
		return out;
	}
	friend istream& operator>>(istream& in,Interval& interval){
		char c=0;
		while(in.get(c)){
			if(c=='['){
				in>>interval.start;
				continue;
			}else if (c==','){
				in>>interval.end;
			}else if (c==']'){
				break;
			}
		}
		return in;
	}
};

ListNode* string2list(const string& s){
	stringstream ss(s);
	int val;
	ListNode *head=NULL,*tail=NULL;
	while(ss>>val){
		ListNode *t=new ListNode(val);
		if (!tail) head=tail=t;	
		else{
			tail->next=t;
			tail=t;
		}
	}
	return head;
}

string list2string(const ListNode* L){
	stringstream ss;
	while(L){
		ss<<L->val<<" ";
		L=L->next;
	}
	return ss.str();
}

template <typename T>
vector<T> string2vector(const string& s){
	stringstream ss(s);
	T val;
	vector<T> v;
	while(ss>>val)v.push_back(val);
	return v;
}

template <typename T>
string vector2string(const vector<T>& v,string sep=" "){
	stringstream ss;
	for(int i=0;i<v.size();i++)ss<<v[i]<<(i==v.size()-1?"":sep);
	return ss.str();
}
