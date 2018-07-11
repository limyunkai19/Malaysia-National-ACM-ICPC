/*Team Name: KitKat*/
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

struct point{
    int x,y;
    point(){
        x = y = 0;
    }

    point(int _x, int _y) : x(_x), y(_y) {}

    bool operator == (point other) const{
        return ( (x==other.x)&&(y==other.y) );
    }
};

struct vec{
    int x, y;
    vec(int x, int y):x(x), y(y){}
};

vec toVec(point a, point b){
    return vec(b.x-a.x, b.y-a.y);
}

int cross(vec a, vec b){
    return a.x*b.y - a.y*b.x;
}

bool collinear(point p, point q, point r){
    return cross(toVec(p,q), toVec(p,r)) == 0;
}

vector<point> p;
set<ii> s;

int main(){
    int t, n, maxshoot, shoot;
    double a, b;
    int c, d;
    cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cin >> n;
        p.clear();
        s.clear();
        while(n--){
            cin >> a >> b;
            c = (100*(a+0.005));
            d = (100*(b+0.005));
            if(s.count(ii(c, d)) == 0){
                s.insert(ii(c, d));
                p.push_back(point(c, d));
            }
        }
        maxshoot = 0;
        for(int i = 0; i < p.size(); i++){
            for(int j = i+1; j < p.size(); j++){
                shoot = 0;
                for(int k = 0; k < p.size(); k++){
                    if(p[k] == p[i] || p[k] == p[j]){
                        continue;
                    }
                    else{
                        if(collinear(p[i], p[k], p[j])){
                            shoot++;
                        }
                    }
                }
                maxshoot = max(maxshoot, shoot);
            }
        }
        if(p.size() == 1){
            maxshoot = -1;
        }
        cout << "Case #" << tc << ": " << p.size() << ' ' << maxshoot+2 << endl;
    }
}
