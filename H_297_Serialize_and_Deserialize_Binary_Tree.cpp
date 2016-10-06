#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {

public:
	void dfs(TreeNode* root){
		if(!root) return;
		cout << root->val << " ";
		dfs(root->left);
		dfs(root->right);
	}


	vector<string> parse(string s){

		std::vector<string> v;
		size_t pos = s.find_first_of(',');
		while(pos != string::npos){
			v.push_back(s.substr(0,pos));
			s.erase(0,pos+1);
			pos = s.find_first_of(',');
		}
		return v;

	}


    // Encodes a tree to a single string.
    void serializeParse(TreeNode* root, string & s) {
    	if(!root){ s += "#,"; return; }

    	s+= to_string(root->val);
    	s+= ",";
    	serializeParse(root->left,s);
    	serializeParse(root->right,s);

    }

   	string serialize(TreeNode* root) {
   		string result;
   		serializeParse(root,result);
   		return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    	vector<string> parseResult = parse(data);
        return decode(parseResult);
    }

    TreeNode* decode(vector<string>& vec){
    	string t = vec.front();
    	vec.erase(vec.begin());
    	if(t == "#")
    		return nullptr;
    	TreeNode* root = new TreeNode(stoi(t));
    	root -> left = decode(vec);
    	root -> right = decode(vec);
    	return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));



int main(int argc, char const *argv[])
{
	/* code */
	TreeNode* n1 = new TreeNode(5);
	TreeNode* n2 = new TreeNode(4);
	TreeNode* n3 = new TreeNode(2);
	n1 -> left = n2;
	n1 -> right = n3;
	TreeNode* n4 = new TreeNode(11);
	n2 ->right = n4;
	TreeNode* n5 = new TreeNode(7);
	TreeNode* n6 = new TreeNode(8);
	n3 -> left = n5;
	n3 -> right = n6;

	Codec c;
	string test = "5,4,#,11,#,#,2,7,#,#,8,#,#,";

	//c.dfs(n1);


	cout << "---------" << endl;
	c.dfs(c.deserialize(test));
	cout  << endl;

	cout << c.serialize(n1)<<endl;
	cout << test<<endl;
	c.dfs(c.deserialize(c.serialize(n1)));

	return 0;
}