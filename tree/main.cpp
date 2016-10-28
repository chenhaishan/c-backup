/***这是一个简易的文件路径添加+打印程序
 * 使用的是多叉树的方法，值得优化的地方还有
 * 1.添加查询，删除方法
 * 2.将文件夹和普通文件分开聚集存储（在兄弟节点中前半部分是文件夹后半部分是普通文件）***/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct FileType{
	string name;//名称
	char type;//d表示目录，f表示普通文件
	FileType(){}
	FileType(string n, char t): name(n), type(t){}
	
};

//template <typename Object>
struct TreeNode{
	//Object element;
	FileType element;
	TreeNode *firstChild;
	TreeNode *nextSibling;
	TreeNode(const FileType &obj,  TreeNode *fc = nullptr, TreeNode *ns = nullptr)
	:element(obj), firstChild(fc), nextSibling(ns){}
};

void removeslash(string &path){
	for(string::iterator itr = path.begin(); itr != path.end(); ++itr){
		if(*itr == '/'){
			*itr = ' ';
		}
	}
}

/***将depth+1~vfoo.size()-1设置为sibling，并返回firstchild***/
void Sibling(const vector<string> &vfoo, int depth, int s, TreeNode *si, TreeNode *fc){
	TreeNode *newtreenode = new TreeNode(FileType(vfoo[s], 'd'), nullptr, si);
	if(s >= depth){
		Sibling(vfoo, depth, s-1, newtreenode, fc);
	}
	else{
		fc->firstChild = newtreenode;
	}

}

/***将depth+1~vfoo.size()-1设置为firstchild，并返回第一个firstchild***/
void FirstChild(const vector<string> &vfoo, int depth, int s, TreeNode *fc, TreeNode *ffc){
	TreeNode *newtreenode = new TreeNode(FileType(vfoo[s--], 'd'), fc, nullptr);
	if(s >= depth){
		FirstChild(vfoo, depth, s, newtreenode, ffc);
	}
	else{
		ffc->firstChild = newtreenode;
	}

}

/***按层检索,检索成功下一层的firstChild***/
TreeNode* siblingsearch(const vector<string> &vfoo, int &depth, TreeNode *root){
	if((root->element).name == vfoo[depth]){
		return root->firstChild;
	}
	else{
		while(root->nextSibling != nullptr){
			root = root->nextSibling;
			if((root->element).name == vfoo[depth])
				return root->firstChild;
		}
		/****表明新增的位置在sibling以及其子节点****/
		root->nextSibling = new TreeNode(FileType(vfoo[depth], 'd'));
		if(depth != vfoo.size()-1){
			FirstChild(vfoo, depth+1, vfoo.size()-1, nullptr, root->nextSibling);
			/***将depth设置为最大从而退出调用函数中的while循环***/
			depth = vfoo.size();
		}
		return root->nextSibling;
	}
	
}


void addfoo(const vector<string> &vfoo, TreeNode *root){
	int depth = 0;
	int s = vfoo.size();
	TreeNode *prelocate = root;
	TreeNode *nextlocate = prelocate;
	while(depth < s){
		nextlocate = prelocate;
		prelocate = siblingsearch(vfoo, depth, prelocate);
		if(prelocate == nullptr){
			/***表明新增的位置在firstchild***/
			FirstChild(vfoo, ++depth, s-1, nullptr, nextlocate);
			break;
		}
		++depth;
	}
	
}

void tables(int depth=0){
	while(depth-->0){
		cout<<' ';
	}
}

void PrintTree(const TreeNode *root, int depth = 0){
	if(root->firstChild != nullptr){
		tables(depth);
		cout<<(root->element).name<<endl;
		PrintTree(root->firstChild, depth+1);
	}
	if(root->nextSibling != nullptr){
		if(root->firstChild == nullptr){
			tables(depth);
			cout<<(root->element).name<<endl;
			
		}
		PrintTree(root->nextSibling, depth);
	}
	if(root->firstChild == nullptr && root->nextSibling == nullptr){
		tables(depth);
		cout<<(root->element).name<<endl;
	}
	
}

int main(){
	TreeNode *root = new TreeNode(FileType("/",'d'));
	cout<<"Hep:"<<endl;
	cout<<"add /usr/foo/foo.txt"<<endl;
	cout<<"remove /usr/foo"<<endl;
	cout<<"print /usr/foo"<<endl;
	
	string cmd_path;
	while(getline(cin, cmd_path)){
		string cmd, path, foo;
		vector<string> vfoo;
		istringstream is(cmd_path);
		is>>cmd;
		is>>path;
		removeslash(path);
		istringstream ipath(path);
		while(ipath>>foo){
			cout<<foo<<endl;
			vfoo.push_back(foo);
		}
		
		if(cmd == "add"){
			addfoo(vfoo, root);
		}
		else if(cmd == "print"){
			PrintTree(root);
		}
		
	}
	
	return 0;
	
}