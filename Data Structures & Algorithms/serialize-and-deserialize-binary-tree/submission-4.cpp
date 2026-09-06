// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Codec {
// public:

//     string str = "";

//     string serialize(TreeNode* root) {

//         if (root == nullptr) {
//             str += "null,";
//         }
//         else {
//             str += to_string(root->val);
//             str += ",";

//             serialize(root->left);
//             serialize(root->right);
//         }

//         return str;
//     }

//     int index = 0;

//     TreeNode* deserialize(string data) {

//         string current = "";

//         for (int i = index; i < data.size(); i++) {

//             if (data[i] == ',') {

//                 current = data.substr(index, i - index);

//                 index = i + 1;   // ⭐ IMPORTANT

//                 break;
//             }
//         }

//         if (current == "null")
//             return nullptr;

//         int value = stoi(current);

//         TreeNode* root = new TreeNode(value);

//         root->left = deserialize(data);
//         root->right = deserialize(data);

//         return root;
//     }
// };


class Codec {
public:

    string serialize(TreeNode* root) {
        if (!root)
            return "null,";

        return to_string(root->val) + "," +
               serialize(root->left) +
               serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }

private:

    TreeNode* build(stringstream& ss) {
        string value;

        getline(ss, value, ',');

        if (value == "null")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(value));

        root->left = build(ss);
        root->right = build(ss);

        return root;
    }
};