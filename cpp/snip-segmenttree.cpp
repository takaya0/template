template<class T> class SegmentTree {
    int n;
    vector<T> seg_tree;
    T unit;
    function<T(T, T)> operation;
    function<T(T, T)> update;
    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l)
            return unit;
        if (a <= l && r <= b) {
            return seg_tree[k];
        } else {
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
            return operation(c1, c2);
        }
    }

  public:
    SegmentTree(size_t _n, T _unit, function<T(T, T)> _operation,
                function<T(T, T)> _update)
        : unit(_unit), operation(_operation), update(_update) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        seg_tree = vector<T>(2 * n - 1, unit);
    }

    void change(int index, T changed) {
        index += n - 1;
        seg_tree[index] = update(seg_tree[index], changed);
        while (index > 0) {
            index = (index - 1) / 2;
            seg_tree[index] =
                operation(seg_tree[index * 2 + 1], seg_tree[index * 2 + 2]);
        }
    }
    T query(int a, int b) { return _query(a, b, 0, 0, n); }
    T operator[](int index) { return seg_tree[index + n - 1]; }
};