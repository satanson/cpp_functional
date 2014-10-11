#include<cppstdlib.hpp>

template <typename T,typename K>
int call_f(T *f,K*v){
	f(v);
}
int main(){
	call_f(printf,"ranpanf");
}
