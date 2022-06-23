class Solution
{
public:
    //Function to merge two nodes a and b.
    int find(int node, int par[]) {
        if (par[node] == node) return node;
        return par[node] = find(par[node], par);
    }

    void union_( int a, int b, int par[], int rank[])
    {
        //code here
        int parenta = find(a, par);
        int parentb = find(b, par);

        if (parenta != parentb) {
            // Merge
            if (rank[parenta] < rank[parentb]) {
                // Attack parent a to parentb
                par[parenta] = parentb;
                rank[parentb] += rank[parenta];
            } else {
                par[parentb] = parenta;
                rank[parenta] += rank[parentb];
            }
        }
    }

    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x, int y, int par[], int rank1[])
    {
        //code here
        return find(x, par) == find(y, par) ? true : false;
    }
};