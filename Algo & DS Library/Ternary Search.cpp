/// LOJ 1146 - Closest Distance

#include <bits/stdc++.h>
using namespace std;


double ax, ay, bx, by, cx, cy, dx, dy;

double calDistance(double x1, double y1, double x2, double y2){
    return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double ternary(){
    int t = 100;
    double ex, ey, fx, fy, gx, gy, hx, hy, dist_1, dist_2; /// e, f ab er upor 2 ti point
    while(t--){
        double ab_X = abs(bx-ax)/3.0; /// ab er x okkhe durotto/3
        double ab_Y = abs(by-ay)/3.0; /// ab er y okkhe durotto/3
        (bx > ax) ? (ex = ax + ab_X, fx = ax + 2*ab_X) : (ex = ax - ab_X, fx = ax - 2*ab_X);
        (by > ay) ? (ey = ay + ab_Y, fy = ay + 2*ab_Y) : (ey = ay - ab_Y, fy = ay - 2*ab_Y);

        double cd_X = abs(dx-cx)/3.0; /// cd er x okkhe durotto/3
        double cd_Y = abs(dy-cy)/3.0; /// cd er y okkhe durotto/3
        (dx > cx) ? (gx = cx + cd_X, hx = cx + 2*cd_X) : (gx = cx - cd_X, hx = cx - 2*cd_X);
        (dy > cy) ? (gy = cy + cd_Y, hy = cy + 2*cd_Y) : (gy = cy - cd_Y, hy = cy - 2*cd_Y);

        dist_1 = calDistance(ex, ey, gx, gy);
        dist_2 = calDistance(fx, fy, hx, hy);

        (dist_1 > dist_2) ? (ax = ex, ay = ey, cx = gx, cy = gy) : (bx = fx, by = fy, dx = hx, dy = hy);
    }
    return sqrt(dist_2);
}

int main(){
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
        cin>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
        double res = ternary();

        printf("Case %d: %.10lf\n", t, res);
    }
}
