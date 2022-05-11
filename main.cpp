#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol987;

/*
Input: root = [3,9,20,null,null,15,7]
Output: [[9],[3,15],[20],[7]]
Explanation:
Column -1: Only node 9 is in this column.
Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
Column 1: Only node 20 is in this column.
Column 2: Only node 7 is in this column.
*/

tuple<Node *, vector<vector<int>>>
testFixture1()
{
  auto root = new Node(3);
  root->left = new Node(9);
  root->right = new Node(20);
  root->right->left = new Node(15);
  root->right->right = new Node(7);

  auto output = vector<vector<int>>{{9}, {3, 15}, {20}, {7}};

  return make_tuple(root, output);
}

/*
Input: root = [1,2,3,4,5,6,7]
Output: [[4],[2],[1,5,6],[3],[7]]
Explanation:
Column -2: Only node 4 is in this column.
Column -1: Only node 2 is in this column.
Column 0: Nodes 1, 5, and 6 are in this column.
          1 is at the top, so it comes first.
          5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
Column 1: Only node 3 is in this column.
Column 2: Only node 7 is in this column.

*/

tuple<Node *, vector<vector<int>>>
testFixture2()
{
  auto root = new Node(1);
  root->left = new Node(2);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right = new Node(3);
  root->right->left = new Node(6);
  root->right->right = new Node(7);

  auto output = vector<vector<int>>{{4}, {2}, {1, 5, 6}, {3}, {7}};

  return make_tuple(root, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.traverse(get<0>(f))) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << Util::toString(get<1>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.traverse(get<0>(f))) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}