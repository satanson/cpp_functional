#include<cppstdlib.hpp>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

uint32_t parse_int(const char* s){
	assert(s!=NULL&&s[0]!='\0');
	char *endptr;
	uint32_t value=strtoul(s,&endptr,0);
	assert(endptr[0]=='\0');
	return value;
}
template <typename T>
string to_string(T const& a){
	return ((stringstream&)(stringstream()<<a)).str();
}
TreeNode* list2tree(list<string> &L){
	if (L.size()==0)return NULL;
	list<TreeNode*> q;
	string val=L.front();
	assert(val!="#");
	TreeNode *root=new TreeNode(parse_int(val.c_str()));
	q.push_back(root);
	L.pop_front();
	while(!q.empty() && !L.empty()){
		TreeNode *branch=q.front();
		q.pop_front();

		if (!L.empty()){
			string left_val=L.front();L.pop_front();
			if (left_val!="#"){
				branch->left=new TreeNode(parse_int(left_val.c_str()));
				q.push_back(branch->left);
			}
		}
		if (!L.empty()){
			string right_val=L.front();L.pop_front();
			if (right_val!="#"){
				branch->right=new TreeNode(parse_int(right_val.c_str()));
				q.push_back(branch->right);
			}
		}
	}
	return root;
}
list<string> tree2list(TreeNode*root){
	if (!root)return list<string>();
	list<string> L;
	list<TreeNode*> q;
	q.push_back(root);
	while(!q.empty()){
		TreeNode *branch=q.front();
		q.pop_front();
		if (!branch)L.push_back("#");
		else{
			L.push_back(to_string(branch->val));
			if (!branch->left)q.push_back(NULL);
			else q.push_back(branch->left);
			if (!branch->right)q.push_back(NULL);
			else q.push_back(branch->right);
		}
	}
	while(L.back()=="#")L.pop_back();
	return L;
}
TreeNode* string2tree(const string& s){
	stringstream ss(s);
	string val;
	list<string> L;
	while(ss>>val)L.push_back(val);
	return list2tree(L);
}

string tree2string(TreeNode* root){
	list<string> L=tree2list(root);
	string s;
	while(!L.empty()){
		s+=L.front()+" ";
		L.pop_front();
	}
	return s;
}
