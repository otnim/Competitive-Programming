///LOJ 1112 - Curious Robin Hood (Accepted)
/// Used Square Root Decomposition

#include <bits/stdc++.h>
using namespace std;
#define  nl    '\n'
#define  LL    long long int
#define  pb    push_back
#define  LIM   100000
#define  MAXX  320

int row, col, n, m, q, segment, element;
int ara[LIM+5];
vector<int> seg[MAXX+5];


void update(int pos, int val){
    int segment_no_of_pos = ceil(pos/(segment*1.0));
    int pos_in_segment = pos%segment;
    if(pos_in_segment == 0) pos_in_segment = segment;
    pos_in_segment--;

    ara[pos] += val;
    int st = pos - pos_in_segment;
    for(int i = 0, j = st; i < segment; i++, j++) seg[segment_no_of_pos][i] = ara[j];
    for(int i = 1; i < segment; i++) seg[segment_no_of_pos][i] += seg[segment_no_of_pos][i-1];
}

int query(int lft, int rht){
    int lft_segment = ceil(lft/(segment*1.0));
    int rht_segment = ceil(rht/(segment*1.0));
    int sum = 0;
    for(int i = lft_segment+1; i < rht_segment; i++){ /// fully cover kore (left, right baad diye) emon segment gulo
        sum += seg[i][segment-1];
    }
    int pos_in_lft_segment = lft%segment; /// 1index theke shuru hocche but ami 0 index korechi
    int pos_in_rht_segment = rht%segment;
    if(pos_in_lft_segment == 0) pos_in_lft_segment = segment;
    if(pos_in_rht_segment == 0) pos_in_rht_segment = segment;

    pos_in_lft_segment--; /// 0 indexed, ejonno 1 komaichi
    pos_in_rht_segment--;

    if(lft_segment == rht_segment){
        if(pos_in_lft_segment == 0) sum = seg[rht_segment][pos_in_rht_segment];
        else sum = seg[rht_segment][pos_in_rht_segment] - seg[lft_segment][pos_in_lft_segment-1];
    }
    else{
        if(pos_in_lft_segment == 0) sum += seg[lft_segment][segment-1];
        else sum += seg[lft_segment][segment-1] - seg[lft_segment][pos_in_lft_segment-1];
        sum += seg[rht_segment][pos_in_rht_segment];
    }
    return sum;
}

int main(){
    //freopen("ip.txt", "r", stdin);
    int T;
    cin>>T;
    for(int tc = 1; tc <= T; tc++){
        memset(ara, 0, sizeof ara);
        for(int i = 0; i <= MAXX+2; i++) seg[i].clear();
        cin>>n>>q;
        segment = sqrt(n);
        element = segment;

        if(segment*segment < n) segment++;
        //cout<<element*segment<<nl;

        for(int i = 1; i <= n; i++) cin>>ara[i];

        for(int i = 1, pos = 1; i <= n; i += segment, pos++){
            for(int j = i; j < i+segment; j++){
                seg[pos].pb(ara[j]);
            }
        }

        for(int i = 1; i <= segment; i++){
            for(int j = 1; j < seg[i].size(); j++) seg[i][j] += seg[i][j-1]; /// segment er last index e er total sum ache
        }
        printf("Case %d:\n", tc);
        for(int i = 1; i <= q; i++){
            int cmd, lft, rht, val; cin>>cmd;
            if(cmd == 1){  /// element k '0' kore dao
                cin>>lft;
                ++lft;
                cout<<ara[lft]<<nl;

                update(lft, -ara[lft]);
            }
            else if(cmd == 2){
                cin>>lft>>val;
                ++lft;
                update(lft, val);
                //cout<<nl;
            }
            else{
                cin>>lft>>rht;
                ++lft, ++rht;
                int res = query(lft, rht);
                cout<<res<<nl;
            }
        }
    }
}


