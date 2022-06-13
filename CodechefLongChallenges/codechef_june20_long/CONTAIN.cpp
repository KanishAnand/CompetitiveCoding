#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define llu unsigned long long int
#define fr(va, beg, end) for (lli va = beg; va < end; va++)
#define pb push_back
#define rt return 0
#define endln "\n"
#define all(x) x.begin(), x.end()
#define sz(x) (lli)(x.size())

typedef lli coord_t;   // coordinate type
typedef lli coord2_t;  // must be big enough to hold 2*max(|coordinate|)^2

struct Point {
    coord_t x, y;

    bool operator<(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r) {
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) &&
        q.y >= min(p.y, r.y))
        return true;
    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
lli orientation(Point p, Point q, Point r) {
    lli val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;              // colinear
    return (val > 0) ? 1 : 2;  // clock or counterclock wise
}

// The function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2) {
    // Find the four orientations needed for general and
    // special cases
    lli o1 = orientation(p1, q1, p2);
    lli o2 = orientation(p1, q1, q2);
    lli o3 = orientation(p2, q2, p1);
    lli o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false;  // Doesn't fall in any of the above cases
}

// Returns true if the point p lies inside the polygon[] with n vertices
lli isInside(vector<Point> polygon, Point p) {
    lli n = polygon.size();
    // There must be at least 3 vertices in polygon[]
    if (n < 3) {
        return 0;
    }

    // Create a point for line segment from p to infinite
    lli INF = 1e10;
    Point extreme = {INF, p.y};

    // Count intersections of the above line with sides of polygon
    lli count = 0, i = 0;
    do {
        lli next = (i + 1) % n;

        // Check if the line segment from 'p' to 'extreme' intersects
        // with the line segment from 'polygon[i]' to 'polygon[next]'
        if (doIntersect(polygon[i], polygon[next], p, extreme)) {
            // If the point 'p' is colinear with line segment 'i-next',
            // then check if it lies on segment. If it lies, return true,
            // otherwise false
            if (orientation(polygon[i], p, polygon[next]) == 0) {
                return 0;
            }
            // cout << polygon[i].x << " " << polygon[i].y << endl;
            count++;
        }
        i = next;
    } while (i != 0);

    // cout << count << endl;
    // Return true if count is odd, false otherwise
    if (count == 1) {
        return 1;
    } else {
        if (count == 2) {
            // Create a point for line segment from p to infinite
            INF = -1e10;
            Point extreme = {INF, p.y};

            // Count intersections of the above line with sides of polygon
            lli count2 = 0;
            i = 0;
            do {
                lli next = (i + 1) % n;
                if (doIntersect(polygon[i], polygon[next], p, extreme)) {
                    if (orientation(polygon[i], p, polygon[next]) == 0) {
                        return 0;
                    }
                    count2++;
                }
                i = next;
            } while (i != 0);
            if (count2 == 1) {
                return 1;
            } else {
                if (count2 == 2) {
                    return 1;
                } else {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    }
}

// 3D cross product of OA and OB vectors, (i.e z-component of their "2D" cross
// product, but remember that it is not defined in "2D"). Returns a positive
// value, if OAB makes a counter-clockwise turn, negative for clockwise turn,
// and zero if the points are collinear.
coord2_t cross(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<Point> convex_hull(vector<Point> P) {
    size_t n = P.size(), k = 0;
    if (n < 3)
        return P;
    vector<Point> H(2 * n);

    // Sort points lexicographically
    sort(P.begin(), P.end());

    // Build lower hull
    for (size_t i = 0; i < n; ++i) {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0)
            k--;
        H[k++] = P[i];
    }

    // Build upper hull
    for (size_t i = n - 1, t = k + 1; i > 0; --i) {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i - 1]) < 0)
            k--;
        H[k++] = P[i - 1];
    }

    H.resize(k - 1);
    return H;
}

void solve() {
    lli n, q;
    cin >> n >> q;

    vector<Point> points;

    for (lli i = 0; i < n; i++) {
        Point inp;
        cin >> inp.x >> inp.y;
        points.pb(inp);
    }

    vector<Point> tmp;
    tmp = points;
    vector<vector<Point>> polys;

    unordered_map<lli, unordered_map<lli, lli>> mp;
    // for mapping negative cood
    lli constant = 1e9 + 2;
    // case when candle point is present in the input
    while (1) {
        vector<Point> res = convex_hull(tmp);

        // cout << res.size() << endl;
        if (res.size() <= 2) {
            break;
        }
        polys.pb(res);
        // cout << res.size() << endl;
        // for (lli i = 0; i < res.size(); i++) {
        //     cout << res[i].x << " " << res[i].y << endl;
        // }

        for (lli i = 0; i < res.size(); i++) {
            mp[res[i].x + constant][res[i].y + constant] = 1;
        }

        vector<Point> new_tmp;

        for (lli i = 0; i < points.size(); i++) {
            if (mp[points[i].x + constant][points[i].y + constant] == 0) {
                new_tmp.pb(points[i]);
            }
        }

        if (new_tmp.size() <= 2) {
            break;
        }
        tmp = new_tmp;
    }

    while (q--) {
        Point query;
        cin >> query.x >> query.y;
        lli ans = 0;
        for (lli i = 0; i < polys.size(); i++) {
            lli ret = isInside(polys[i], query);
            // cout << ret << endl;
            // cout << endl;
            if (ret == 0) {
                // ans++;
                break;
            }
            ans++;
        }
        cout << ans << endl;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli t;
    cin >> t;
    while (t--)
        solve();
    rt;
}