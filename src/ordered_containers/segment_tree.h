#include <vector>

struct SegTreeSum
{
    std::vector<int> seg;
    int MAX;

    SegTreeSum(const int mx)
    {
        MAX = mx;
        seg.assign(4 * MAX + 10, 0);
    }

    void add_val(int pos, int add, int cur, int st, int en);
    void add_val(int pos, int add);
    void insert(int pos);
    void erase(int pos);
    bool contain(int pos);
    int query(int l, int r, int cur, int st, int en);
    int query(int l, int r);
    int kth(int l, int r, int k, int cur, int st, int en);
    int kth(int l, int r, int k);
};