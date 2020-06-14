#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define base10_4 10000      //1e4
#define base10_5 100000     //1e5
#define base10_6 1000000    //1e6
#define base10_7 10000000   //1e7
#define base10_8 100000000  //1e8
#define base10_9 1000000000 //1e9

#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll A;
ll B;
ll C;
ll N;
ll X;
ll Y;

#define base 220      //1e4
#define base2 440      //1e4
ll block[base2][base2]={};
ll d[base2][base2]={};

#include <queue>  
typedef pair<ll,ll> P;  

/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/
map<string,ll> map_XYtoID;
map<string,ll> map_IDtoX;
map<string,ll> map_IDtoY;

#include <queue>    
struct edge{ll next_index, cost;};    
typedef pair<ll,ll> P;    
struct graph{    
    ll graph_size;    
    vector<vector <edge> > G;    
    vector<ll> node_costs;    
    graph(ll n){    
        init(n);    
    }    
    void init(ll n){    
        graph_size = n;    
        G.resize(graph_size);    
        node_costs.resize(graph_size);    
        rep(i,graph_size){    
            node_costs[i] = INF;    
        }    
    }    
    void add_edge(ll start_index, ll next_index, ll cost){    
        edge e;    
        e.next_index = next_index;    
        e.cost = cost;    
        G[start_index].push_back(e);    
    }    
    void dijkstra(ll base_id){    
        ll x1 = map_IDtoX[to_string(base_id)];
        ll y1 = map_IDtoY[to_string(base_id)];
        d[x1][y1] = 0;
        priority_queue<P,vector<P>, greater<P> > que;    
        que.push(P(d[x1][y1],base_id));    

        while(!que.empty()){    
            P p = que.top();    
            que.pop();    
            ll id = p.second;    
            ll xi = map_IDtoX[to_string(id)];
            ll yi = map_IDtoY[to_string(id)];
            ll updated_cost = p.first;


            //if(d[xi][yi] < updated_cost) continue;    


            //cout << "x " << xi << " y " << yi << endl;

            ll _x = xi;
            ll _y = yi-1;
            if(_y>0){
                if(d[_x][_y] > d[xi][yi]+1 && block[_x][_y]==0){
                    d[_x][_y] = d[xi][yi]+1;
                    string _key = to_string(_x) + "_" + to_string(_y);   
                    que.push(P(d[_x][_y], map_XYtoID[_key]  ));    
                }  
            }

            for(int _x_ = -1 ; _x_ <=1 ; _x_++ ){
                for(int _y_ = 0 ; _y_ <=1 ; _y_++ ){
                    _x = xi + _x_;
                    _y = yi + _y_;
                    if(_x > 0 && _x < base2 && _y < base2){

                        if(d[_x][_y] > d[xi][yi]+1 && block[_x][_y]==0){
                            d[_x][_y] = d[xi][yi]+1;
                            string _key = to_string(_x) + "_" + to_string(_y);   
                            que.push(P(d[_x][_y], map_XYtoID[_key]  ));    
                        }  

                    }
                    
                }
            }
        }    
    }    
};


int main(){

    
    cin >> N;
    cin >> X;
    cin >> Y;


    X = X + base;
    Y = Y + base;
    rep(ni,N){
        int xi,yi;
        cin >> xi;
        cin >> yi;
        block[xi+base][yi+base]=1;
    }
    /*
    int flag = 0;
    for( int xi = -1 ; xi <=1 ; xi++ ){
        for( int yi = -1 ; yi <=1 ; yi++ ){
            flag+=block[X+xi][Y+yi];
        }
    }

    int flag2 = 0;
    for( int xi = -1 ; xi <=1 ; xi++ ){
        for( int yi = -1 ; yi <=1 ; yi++ ){
            flag2+=block[base+xi][base+yi];
        }
    }
    if(flag==8){
        cout << -1 << endl;
    elseif(flag2==8){
        cout << -1 << endl;
    }else{
    */

    ll id=0;
    for( int xi = 0 ; xi <base2 ; xi++ ){
        for( int yi = 0 ; yi <base2 ; yi++ ){
            string key1 = to_string(xi) + "_" + to_string(yi);
            string key2 = to_string(id);
            map_XYtoID[key1]=id;
            map_IDtoX[key2]=xi;
            map_IDtoY[key2]=yi;
            d[xi][yi]=1000000;
            id++;
        }
    }

    //cout << "setup" << endl;
    graph G(id);
    string key0 = to_string(base)+"_" + to_string(base);
    ll start = map_XYtoID[key0];
    
    
    //cout << "start" << endl;
    G.dijkstra(start);
    //cout << d[X][Y] << endl;

    if(d[X][Y]==1000000){
        cout << -1 << endl;
    }else{
        cout << d[X][Y] << endl;
    }


    //}

}