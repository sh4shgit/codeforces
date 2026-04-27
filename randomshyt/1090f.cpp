#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    // A tree with x even subtree sizes and y odd subtree sizes 
    // is only possible if x is even.
    if (x % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

    int total_nodes = x + y;
    
    /* Construction:
       1. Connect nodes 2 to y to node 1 (Star graph).
          Node 1 will have size y. Nodes 2...y are leaves (size 1).
       2. Use the remaining x nodes to create x/2 chains of length 2
          attached to node 1.
          Each chain 1 -> u -> v adds:
          - Node v: size 1 (Odd)
          - Node u: size 2 (Even)
          Wait, this adds x/2 even nodes. We need x.
       
       Revised Construction:
       Make a single path of x nodes: 1-2-3-...-x, then attach y leaves to node x.
       Actually, the most robust way:
       Every even node must have an odd number of odd children.
    */

    // Simple construction for even x:
    // Create x nodes in a path 2-3-4...-(x+1) and connect 2 to 1.
    // Then connect the rest as leaves to 1.
    
    // Let's use the property: 
    // Node u is even if it has an odd number of odd subtrees below it.
    // We can simply build x/2 blocks of 2 nodes each.
    
    int current_node = 2;
    // We need x even nodes. Each pair (u, v) where u is parent of v 
    // gives one even node (u) and one odd node (v).
    for (int i = 0; i < x; ++i) {
        if (i % 2 == 0) {
            // Start of a pair, connect to root
            cout << 1 << " " << current_node << "\n";
        } else {
            // End of a pair, connect to previous node
            cout << current_node - 1 << " " << current_node << "\n";
        }
        current_node++;
    }

    // The remaining nodes (y - 1 if root is odd, or y - some other amount)
    // must be connected to the root to remain odd.
    while (current_node <= total_nodes) {
        cout << 1 << " " << current_node << "\n";
        current_node++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}