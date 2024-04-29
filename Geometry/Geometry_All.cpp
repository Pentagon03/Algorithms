/*
Geometry Namespace
reference: https://codeforces.com/contest/1936/submission/249350779 (which referenced https://victorlecomte.com/cp-geo.pdf)
*/
namespace Geometry{
    // double or ll
    using C = double;
    const C INF = 1e100;
    const C EPS = 1e-9;
    const C PI = acos((C)-1);
    int sign(C x){return (x>EPS) - (x<-EPS);}

    // Point
    struct Point{
        C x, y;
        Point(C x=0,C y=0):x(x),y(y){}
        Point operator-(Point p) const {return Point(x - p.x, y - p.y);}
        Point operator-=(Point p){return *this = (*this - p);}
        Point operator+(Point p) const {return Point(x + p.x, y + p.y);}
        Point operator+=(Point p){return *this = (*this + p);}
        Point operator*(C c) const {return Point(x * c, y * c);}
        Point operator*=(C c){return *this = ((*this) * c);}
        friend Point operator*(const C& c, Point p){return p*c;}
        Point operator/(C c) const {return Point(x / c, y / c);}
        Point operator/=(C c) {return *this = (*this / c);}
        bool operator==(Point p) const {return !sign(p.x-x) && !sign(p.y-y);}
        bool operator!=(Point p) const {return !(*this == p);}
        bool operator<(Point p) const {return !sign(p.x-x) ? y < p.y : x < p.x;}
        bool operator<=(Point p) const {return *this == p || *this < p;}
        bool operator>(Point p) const {return !sign(p.x-x) ? y > p.y : x > p.x;}
        bool operator>=(Point p) const {return *this == p || *this > p;}
        double norm() const {return std::hypot(x, y);}
        C norm2() const{return x*x + y*y;}
        double arg() const{ return atan2(y, x);}
        Point perpendicular() const{ return Point(-y, x);}
        // returns a vector with norm r and having same direction
        Point unit() const{
            double k = norm();
            if(!sign(k)) return *this;
            return (*this) / k;
        }
    };
    const Point O = Point(0,0), FAIL = Point(INF, INF);
    istream &operator>>(istream &in, Point &p) { return in >> p.x >> p.y; }
    ostream &operator<<(ostream &out, Point &p) { return out << "(" << p.x << "," << p.y << ")"; }
    C dot(Point a, Point b){return a.x*b.x + a.y*b.y;}
    double dist(Point a, Point b){return (b-a).norm();}
    C dist2(Point a, Point b){return (b-a).norm2();}
    C cross(Point a, Point b){return a.x*b.y - a.y*b.x;}
    C cross(Point a, Point b, Point c){return cross(b-a, c-a);}
    int ccw(Point a, Point b, Point c){return sign(cross(a,b,c));}
    // y축 음의 방향으로부터 시계 반대방향으로 정렬하는 비교함수.
    inline bool cmp_angle(Point a, Point b){
        if((a>O)^(b>O)) return a > b;
        if(sign(cross(a,b))) return sign(cross(a,b))>0;
        return a.norm2() < b.norm2();
    }
    double area_signed(Point a, Point b, Point c){
        if(dist(b,c)<EPS) return 0; 
        return cross(a,b,c) / 2;
    } 
    double area(Point a, Point b, Point c){return abs(area_signed(a,b,c));}

    struct Line{
        Point s,e;
        Line(Point s=O,Point e=O):s(s),e(e){}
        friend istream& operator>> (istream& is, Line& l){Point a, b; cin>>a>>b; l = Line(a,b); return is;}
        double length() const{return dist(s,e);}
        C length2() const{return dist2(s,e);}
        bool is_on_line(Point x) const{return !ccw(s,e,x) && min(s,e)<=x && x<=max(s,e);}
        friend bool chk_inter(Line p, Line q){
            auto[a,b] = p; auto[c,d] = q;
            int t1 = ccw(a,c,d); int t2 =  ccw(b,c,d);
            int t3 = ccw(c,a,b); int t4 =  ccw(d,a,b);
            if(!t1 && !t2){
                if(a>b) swap(a,b);
                if(c>d) swap(c,d);
                return a <= d && c <= b;
            }
            return t1*t2 <= 0 && t3*t4 <= 0;
        }
        friend Point parrallel_inter(Line a,Line b){
            if(a.s > a.e) swap(a.s, a.e);
            if(b.s > b.e) swap(b.s, b.e);
            if(a.e==b.s) return a.e;
            if(a.s==b.e) return a.s;
            return FAIL;
        }
        // only works when T = C
        friend Point inter(Line p,Line q){
            Point a=p.s, b=p.e, c=q.s, d=q.e;
            int t1 = ccw(a,c,d) , t2 = ccw(b,c,d);
            if(t1 == 0 && t2 == 0)
                return parrallel_inter(p,q);
            b-=a; d-=c;
            double t = cross(c-a,d) / cross(b,d);
            return a + b*t;
        }
        friend inline double dist_signed(Line a,Point x){ return cross(a.s, a.e, x)/a.length();}
        friend inline double dist(Line a,Point x){ return abs(dist_signed(a,x));}
    };
    //compute intersection of line through points a and b with
    //circle centered at c with radius r > 0
    vector<Point> circle_line_intersection(Point c, C r, Line l) {
        vector<Point> ret;
        auto [a,b] = l;
        b -= a; a -= c; // b is vector of a, a is relative to c
        // |(u+kv - O)| = r
        // ||u+kv-O|^2 = r^2
        // solve quadratic equation regard of k.
        C A = dot(b, b), B = dot(a, b);
        C C = dot(a, a) - r * r, D = B * B - A * C;
        if (D < -EPS) return ret;
        ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
        // D != 0
        if (D > EPS) ret.push_back(c + a + b * (-B - sqrt(D)) / A); 
        return ret;
    }

    double sector_signed(Point c, C r, Point a, Point b){
        if(ccw(c, a, b) == 0) return 0;
        a -= c; b -= c;
        return r * r * atan2(cross(a,b), dot(a,b)) / 2;
    }
    double sector(Point c, C r, Point a, Point b){
        return abs(sector_signed(c, r, a, b));
    }

    using Polygon = vector<Point>;
    Polygon getCH(Polygon pg){ //Monotone Chain of polygon
        if(size(pg)<=3) return pg;
        sort(all(pg));
        Polygon up(size(pg)),dn(size(pg)); 
        int u=0,d=0;
        for(auto&p:pg){
            // change the inequity for colinear cases
            while(u>1 && ccw(up[u-2],up[u-1],p)>=0) --u;
            while(d>1 && ccw(dn[d-2],dn[d-1],p)<=0) --d;
            up[u++] = dn[d++] = p;
        }
        up.resize(u); dn.resize(d);
        dn.insert(dn.end(),++up.rbegin(),--up.rend());
        return dn;
    }

    pair<Point,Point> find_farthest(const Polygon&v){
        vector<Point> ch = getCH(v);
        int n = ch.size();
        C ans = 0; Point ans1,ans2;
        int id = 1;
        auto upd = [&](int a,int b){
            auto val = dist(ch[a], ch[b]);
            if(ans< val){
                ans1 = ch[a];
                ans2 = ch[b];
                ans = val;
            }
        };
        for(int i=0;i<n;i++){
            while(ccw(O,ch[i+1]-ch[i],ch[(id+1)%n]-ch[id])>0){
                upd(i,id);
                id++; if(id==n) id = 0;
            }
            upd(i,id);
        }
        return {ans1, ans2};
    }

    bool point_in_polygon_naive(const Polygon& h,const Point& p){
        // strictly inner
        int s = ccw(h[0],h[1],p);
        for(int i=1;i<size(h);i++){
            if(s * ccw(h[i], h[(i+1) % size(h)], p) <= 0) return false;
        }
        return true;
    }
    // -1 if strictly inside, 0 if on the polygon, 1 if strictly outside
    // polygon is counter clock wised sorted
    // it must be strictly convex, otherwise make it strictly convex first
    int is_point_in_convex(Polygon &p, const Point &x) { // O(log n)
        int n = p.size();
        assert(n >= 3);
        int a = ccw(p[0], p[1], x), b = ccw(p[0], p[n - 1], x);
        if (a < 0 || b > 0) return 1;
        int l = 1, r = n - 1;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            if (ccw(p[0], p[mid], x) >= 0) l = mid;
            else r = mid;
        }
        int k = ccw(p[l], p[r], x);
        if (k <= 0) return -k;
        if (l == 1 && a == 0) return 0;
        if (r == n - 1 && b == 0) return 0;
        return -1;
    }
 
    bool is_point_on_polygon(const Polygon& p, const Point &z) {
        int n = p.size();
        for (int i = 0; i < n; i++) 
            if (Line(p[i], p[(i + 1) % n]).is_on_line(z)) 
                return 1;
        return 0;
    }
 
    // returns 1e9 if the point is on the polygon
    int winding_number(Polygon &p, const Point &z) { // O(n)
        if (is_point_on_polygon(p, z)) return 1e9;
        int n = p.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            bool below = p[i].y < z.y;
            if (below != (p[j].y < z.y)) {
                auto orient = ccw(z, p[j], p[i]);
                if (orient == 0) return 0;
                if (below == (orient > 0)) ans += below ? 1 : -1;
            }
        }
        return ans;
    }
 
    // -1 if strictly inside, 0 if on the polygon, 1 if strictly outside
    int is_point_in_polygon(Polygon &p, const Point &z) { // O(n)
        int k = winding_number(p, z);
        return k == 1e9 ? 0 : (k == 0 ? 1 : -1);
    }
}
using namespace Geometry;
