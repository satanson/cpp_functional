#include<cppfunctional.hpp>

template <
			typename It,
			typename T,
			typename BinOp
		 >
T foldr(const It &begin,const It &end,T init,BinOp f)
{
	for (It a=begin;a!=end;++a){
		init=f(init,*a);
	}
	return init;
}

int add(int a,int b){return a+b;}
int main(){
	string line;
	while(getline(cin,line)){
		stringstream sin(line);
		vector<int> a;
		int t;
		while(sin>>t)a.push_back(t);
		//functor
		cout<<vector2string<int>(a,"+")
			<<"="<<foldr(a.begin(),a.end(),0,plus<int>())
			<<endl;
		//function reference
		cout<<vector2string<int>(a,"+")
			<<"="<<foldr(a.begin(),a.end(),0,add)
			<<endl;
		//function pointer
		cout<<vector2string<int>(a,"+")
			<<"="<<foldr(a.begin(),a.end(),0,&add)
			<<endl;
		//lambda expression
		cout<<vector2string<int>(a,"+")
			<<"="<<foldr(a.begin(),a.end(),0,[](int a,int b)->int{return a+b;})
			<<endl;

	}
}
