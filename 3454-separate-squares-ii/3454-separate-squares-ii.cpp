class Solution {
public:

struct Event {
        double y;
        int type;
        int x1, x2;
    };

    double separateSquares(vector<vector<int>>& squares) {
        vector<Event> events;
        set<int> xs;

        for (auto &sq : squares) {
            int x = sq[0], y = sq[1], s = sq[2];
            events.push_back({(double)y, 1, x, x + s});
            events.push_back({(double)y + s, -1, x, x + s});
            xs.insert(x);
            xs.insert(x + s);
        }

        vector<int> x(xs.begin(), xs.end());
        int n = x.size();

        sort(events.begin(), events.end(),
             [](const Event &a, const Event &b) { return a.y < b.y; });

        vector<int> cover(4 * n, 0);
        vector<double> coveredLen(4 * n, 0.0);

        double totalArea = 0.0;
        double prevY = events[0].y;
        vector<array<double, 3>> parts;

        int i = 0;
        while (i < events.size()) {
            double currY = events[i].y;

            if (currY > prevY) {
                double h = currY - prevY;
                double w = coveredLen[1];
                totalArea += w * h;
                parts.push_back({prevY, currY, w});
                prevY = currY;
            }

            while (i < events.size() && events[i].y == currY) {
                int l = lower_bound(x.begin(), x.end(), events[i].x1) - x.begin();
                int r = lower_bound(x.begin(), x.end(), events[i].x2) - x.begin();
                update(1, 0, n, l, r, events[i].type, x, cover, coveredLen);
                i++;
            }
        }

        double half = totalArea / 2.0;
        double acc = 0.0;

        for (auto &p : parts) {
            double y1 = p[0], y2 = p[1], w = p[2];
            double area = w * (y2 - y1);
            if (acc + area >= half) {
                return y1 + (half - acc) / w;
            }
            acc += area;
        }

        return prevY;
    }

    void update(int node, int l, int r, int ql, int qr, int val,
                vector<int>& x, vector<int>& cover, vector<double>& coveredLen) {
        if (qr <= l || r <= ql) return;

        if (ql <= l && r <= qr) {
            cover[node] += val;
        } else {
            int mid = (l + r) / 2;
            update(node * 2, l, mid, ql, qr, val, x, cover, coveredLen);
            update(node * 2 + 1, mid, r, ql, qr, val, x, cover, coveredLen);
        }

        if (cover[node] > 0) {
            coveredLen[node] = x[r] - x[l];
        } else {
            if (r - l == 1) coveredLen[node] = 0;
            else coveredLen[node] = coveredLen[node * 2] + coveredLen[node * 2 + 1];
        }
    }
};