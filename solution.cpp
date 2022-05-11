#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol987;
using namespace std;

/*takeaways
  - choose the right data structure to record the coordinates
    - use map to maintain the order
  - visit the tree to assign each node a coordinate
    - multiple nodes can be mapped to the same coordinates
*/

vector<vector<int>> Solution::traverse(Node *root)
{
  auto result = vector<vector<int>>();
  /*
    (x,y) is recorded as m[x][y]
    - m[x][y] is a vector
    - multiple nodes might be mapped to
      the same coordinate so we need
      a vector to record all the nodes
    - map will maintain a ascending order
      - we need the children to have
        a bigger y so that they can be listed
        after their ancestors if they
        are in the same col (x)
  */
  auto m = map<int, map<int, vector<int>>>();
  auto q = queue<pair<Node *, pair<int, int>>>();

  /* root has the coordinate of (0,0)
     - (x,y): don't forget x is the col
       and y is the row
  */
  q.push({root, {0, 0}});
  while (!q.empty())
  {
    auto &[node, coords] = q.front();
    q.pop();
    auto &[x, y] = coords;
    /* record the node value and its coordinate */
    m[x][y].push_back(node->val);

    /* make sure children has a larger y as we want
       to list the nodes from top to bottom if they
       are in the same column
    */
    if (node->left != nullptr)
      q.push({node->left, {x - 1, y + 1}});
    if (node->right != nullptr)
      q.push({node->right, {x + 1, y + 1}});
  }

  for (auto &x : m)
  {
    auto col = vector<int>();
    /* all the y's that have the same x */
    for (auto &y : x.second)
    {
      auto &values = y.second;
      /* If two nodes have the same position,
         then the value of the node that is
         reported first is the value that is smaller. */
      sort(values.begin(), values.end());
      col.insert(col.end(), values.begin(), values.end());
    }

    result.push_back(col);
  }

  return result;
}
